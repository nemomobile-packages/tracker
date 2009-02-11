/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2008, Nokia
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 */

#include "config.h"

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

#include <glib.h>
#include <glib/gprintf.h>
#include <glib/gstdio.h>

#include <gio/gio.h>

#ifdef HAVE_GDKPIXBUF
#include <gdk-pixbuf/gdk-pixbuf.h>
#endif

#include <libtracker-common/tracker-common.h>
#include <libtracker-common/tracker-thumbnailer.h>

#include "tracker-extract-albumart.h"



#ifdef HAVE_GDKPIXBUF

static gboolean
set_albumart (const unsigned char *buffer,
	      size_t               len,
	      const gchar         *artist, 
	      const gchar         *album,
	      const gchar         *uri)
{
	GdkPixbufLoader *loader;
	GdkPixbuf       *pixbuf = NULL;
	gchar           *filename;
	GError          *error = NULL;

	g_type_init ();

	if (!artist && !album) {
		g_warning ("No identification data for embedded image");
		return FALSE;
	}

	tracker_albumart_get_path (artist, album, "album", NULL, &filename, NULL);

	loader = gdk_pixbuf_loader_new ();

	if (!gdk_pixbuf_loader_write (loader, buffer, len, &error)) {
		g_warning ("%s\n", error->message);
		g_error_free (error);

		gdk_pixbuf_loader_close (loader, NULL);
		g_free (filename);
		return FALSE;
	}

	pixbuf = gdk_pixbuf_loader_get_pixbuf (loader);

	if (!gdk_pixbuf_save (pixbuf, filename, "jpeg", &error, NULL)) {
		g_warning ("%s\n", error->message);
		g_error_free (error);

		g_free (filename);
		g_object_unref (pixbuf);

		gdk_pixbuf_loader_close (loader, NULL);
		return FALSE;
	}


	g_object_unref (pixbuf);

	if (!gdk_pixbuf_loader_close (loader, &error)) {
		g_warning ("%s\n", error->message);
		g_error_free (error);
	}

	tracker_thumbnailer_get_file_thumbnail (filename, "image/jpeg");
	g_free (filename);

	return TRUE;
}

#endif /* HAVE_GDKPIXBUF */

gboolean
tracker_process_albumart (const unsigned char *buffer,
                          size_t               len,
                          const gchar         *artist,
                          const gchar         *album,
                          const gchar         *trackercnt_str,
                          const gchar         *filename)
{
	gchar *art_path;
	gboolean retval = TRUE;
	gchar *local_uri = NULL;
	gchar *filename_uri;
	gboolean lcopied = FALSE;

	if (strchr (filename, ':'))
		filename_uri = g_strdup (filename);
	else
		filename_uri = g_filename_to_uri (filename, NULL, NULL);

	tracker_albumart_get_path (artist, album, "album", filename_uri, 
				   &art_path, &local_uri);

	if (!g_file_test (art_path, G_FILE_TEST_EXISTS)) {

#ifdef HAVE_GDKPIXBUF

		/* If we have embedded album art */

		if (buffer && len) {
			retval = set_albumart (buffer, len,
					       artist,
					       album,
					       filename);

			lcopied = !retval;

		} else {
#endif /* HAVE_GDK_PIXBUF */

			/* If not, we perform a heuristic on the dir */

			if (!tracker_albumart_heuristic (artist, album, trackercnt_str, filename, local_uri, &lcopied)) {

				/* If the heuristic failed, we request the download 
				 * of the media-art to the media-art downloaders */

				lcopied = TRUE;
				tracker_albumart_request_download (artist,
								   album,
								   local_uri,
								   art_path);
			}
#ifdef HAVE_GDKPIXBUF

		}

#endif /* HAVE_GDKPIXBUF */

		/* If the heuristic didn't copy from the .mediaartlocal, then 
		 * we'll perhaps copy it to .mediaartlocal (perhaps because this
		 * only copies in case the media is located on a removable 
		 * device */

		if (g_file_test (art_path, G_FILE_TEST_EXISTS)) {
			gchar *asuri = g_filename_to_uri (art_path, NULL, NULL);
			tracker_thumbnailer_get_file_thumbnail (asuri, "image/jpeg");
			g_free (asuri);
		}

		if (!lcopied && g_file_test (art_path, G_FILE_TEST_EXISTS))
			tracker_albumart_copy_to_local (art_path, local_uri);
	}

	g_free (art_path);
	g_free (filename_uri);
	g_free (local_uri);

	return retval;
}
