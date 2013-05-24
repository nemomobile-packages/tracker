/* tracker-utils.c generated by valac 0.14.2, the Vala compiler
 * generated from tracker-utils.vala, do not modify */

/**/
/* Copyright 2010, Martyn Russell <martyn@lanedo.com>*/
/**/
/* This program is free software; you can redistribute it and/or*/
/* modify it under the terms of the GNU General Public License*/
/* as published by the Free Software Foundation; either version 2*/
/* of the License, or (at your option) any later version.*/
/**/
/* This program is distributed in the hope that it will be useful,*/
/* but WITHOUT ANY WARRANTY; without even the implied warranty of*/
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the*/
/* GNU General Public License for more details.*/
/**/
/* You should have received a copy of the GNU General Public License*/
/* along with this program; if not, write to the Free Software*/
/* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA*/
/* 02110-1301, USA.*/
/**/

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <time.h>
#include <glib/gi18n-lib.h>
#include <float.h>
#include <math.h>
#include <gdk-pixbuf/gdk-pixdata.h>

#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_string_free0(var) ((var == NULL) ? NULL : (var = (g_string_free (var, TRUE), NULL)))



#define secs_per_day ((60 * 60) * 24)
gchar* uri_get_selected (GtkTreeModel* model, GtkTreePath* path, gint col);
void uri_launch (const gchar* uri);
void tracker_model_launch_selected (GtkTreeModel* model, GtkTreePath* path, gint col);
void tracker_model_launch_selected_parent_dir (GtkTreeModel* model, GtkTreePath* path, gint col);
gchar* tracker_time_format_from_iso8601 (const gchar* s);
gchar* tracker_time_format_from_seconds (const gchar* seconds_str);
GdkPixbuf* tracker_pixbuf_new_from_file (GtkIconTheme* theme, const gchar* filename, gint size, gboolean is_image);
GdkPixbuf* tracker_pixbuf_new_from_name (GtkIconTheme* theme, const gchar* name, gint size);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


gchar* uri_get_selected (GtkTreeModel* model, GtkTreePath* path, gint col) {
	gchar* result = NULL;
	GtkTreeIter iter = {0};
	GtkTreeModel* _tmp0_;
	GtkTreePath* _tmp1_;
	GtkTreeIter _tmp2_ = {0};
	const gchar* uri = NULL;
	GtkTreeModel* _tmp3_;
	GtkTreeIter _tmp4_;
	gint _tmp5_;
	gchar* _tmp6_;
	g_return_val_if_fail (model != NULL, NULL);
	g_return_val_if_fail (path != NULL, NULL);
	_tmp0_ = model;
	_tmp1_ = path;
	gtk_tree_model_get_iter (_tmp0_, &_tmp2_, _tmp1_);
	iter = _tmp2_;
	_tmp3_ = model;
	_tmp4_ = iter;
	_tmp5_ = col;
	gtk_tree_model_get (_tmp3_, &_tmp4_, _tmp5_, &uri, -1);
	_tmp6_ = g_strdup (uri);
	result = _tmp6_;
	return result;
}


static gint string_index_of (const gchar* self, const gchar* needle, gint start_index) {
	gint result = 0;
	gint _tmp0_;
	const gchar* _tmp1_;
	gchar* _tmp2_ = NULL;
	gchar* _result_;
	gchar* _tmp3_;
	g_return_val_if_fail (self != NULL, 0);
	g_return_val_if_fail (needle != NULL, 0);
	_tmp0_ = start_index;
	_tmp1_ = needle;
	_tmp2_ = strstr (((gchar*) self) + _tmp0_, (gchar*) _tmp1_);
	_result_ = _tmp2_;
	_tmp3_ = _result_;
	if (_tmp3_ != NULL) {
		gchar* _tmp4_;
		_tmp4_ = _result_;
		result = (gint) (_tmp4_ - ((gchar*) self));
		return result;
	} else {
		result = -1;
		return result;
	}
}


void uri_launch (const gchar* uri) {
	const gchar* _tmp0_;
	gint _tmp1_ = 0;
	GError * _inner_error_ = NULL;
	g_return_if_fail (uri != NULL);
	_tmp0_ = uri;
	_tmp1_ = string_index_of (_tmp0_, "://", 0);
	if (_tmp1_ < 1) {
		const gchar* _tmp2_;
		gchar** _tmp3_;
		gchar** _tmp4_ = NULL;
		gchar** command;
		gint command_length1;
		gint _command_size_;
		gchar** _tmp5_;
		gint _tmp5__length1;
		const gchar* _tmp6_;
		GPid child_pid = 0;
		gchar** _tmp7_ = NULL;
		gchar** argv;
		gint argv_length1;
		gint _argv_size_;
		gchar** _tmp8_;
		gint _tmp8__length1;
		gchar** _tmp9_;
		gint _tmp9__length1;
		const gchar* _tmp10_;
		gchar* _tmp11_;
		gchar* _tmp12_;
		GPid _tmp22_;
		_tmp2_ = uri;
		_tmp4_ = _tmp3_ = g_strsplit (_tmp2_, " ", 0);
		command = _tmp4_;
		command_length1 = _vala_array_length (_tmp3_);
		_command_size_ = command_length1;
		_tmp5_ = command;
		_tmp5__length1 = command_length1;
		_tmp6_ = _tmp5_[0];
		g_debug ("tracker-utils.vala:39: Attempting to spawn_async() '%s'", _tmp6_);
		_tmp7_ = g_new0 (gchar*, 1 + 1);
		argv = _tmp7_;
		argv_length1 = 1;
		_argv_size_ = argv_length1;
		_tmp8_ = argv;
		_tmp8__length1 = argv_length1;
		_tmp9_ = command;
		_tmp9__length1 = command_length1;
		_tmp10_ = _tmp9_[0];
		_tmp11_ = g_strdup (_tmp10_);
		_g_free0 (_tmp8_[0]);
		_tmp8_[0] = _tmp11_;
		_tmp12_ = _tmp8_[0];
		{
			gchar** _tmp13_;
			gint _tmp13__length1;
			GPid _tmp14_ = 0;
			_tmp13_ = argv;
			_tmp13__length1 = argv_length1;
			g_spawn_async ("/usr/bin", _tmp13_, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, &_tmp14_, &_inner_error_);
			child_pid = _tmp14_;
			if (_inner_error_ != NULL) {
				goto __catch22_g_error;
			}
		}
		goto __finally22;
		__catch22_g_error:
		{
			GError* e = NULL;
			gchar** _tmp15_;
			gint _tmp15__length1;
			const gchar* _tmp16_;
			GError* _tmp17_;
			gint _tmp18_;
			GError* _tmp19_;
			gint _tmp20_;
			const gchar* _tmp21_ = NULL;
			e = _inner_error_;
			_inner_error_ = NULL;
			_tmp15_ = command;
			_tmp15__length1 = command_length1;
			_tmp16_ = _tmp15_[0];
			_tmp17_ = e;
			_tmp18_ = _tmp17_->code;
			_tmp19_ = e;
			_tmp20_ = _tmp19_->code;
			_tmp21_ = g_strerror (_tmp20_);
			g_warning ("tracker-utils.vala:53: Could not launch '%s', %d->%s", _tmp16_, _tmp18_, _tmp21_);
			_g_error_free0 (e);
			argv = (_vala_array_free (argv, argv_length1, (GDestroyNotify) g_free), NULL);
			command = (_vala_array_free (command, command_length1, (GDestroyNotify) g_free), NULL);
			return;
		}
		__finally22:
		if (_inner_error_ != NULL) {
			argv = (_vala_array_free (argv, argv_length1, (GDestroyNotify) g_free), NULL);
			command = (_vala_array_free (command, command_length1, (GDestroyNotify) g_free), NULL);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return;
		}
		_tmp22_ = child_pid;
		g_debug ("tracker-utils.vala:57: Launched application with PID:%d", (gint) _tmp22_);
		argv = (_vala_array_free (argv, argv_length1, (GDestroyNotify) g_free), NULL);
		command = (_vala_array_free (command, command_length1, (GDestroyNotify) g_free), NULL);
		return;
	}
	{
		const gchar* _tmp23_;
		const gchar* _tmp24_;
		_tmp23_ = uri;
		g_debug ("tracker-utils.vala:62: Attempting to launch application for uri:'%s'", _tmp23_);
		_tmp24_ = uri;
		g_app_info_launch_default_for_uri (_tmp24_, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch23_g_error;
		}
	}
	goto __finally23;
	__catch23_g_error:
	{
		GError* e = NULL;
		GError* _tmp25_;
		const gchar* _tmp26_;
		gchar* _tmp27_;
		gchar* _tmp28_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp25_ = e;
		_tmp26_ = _tmp25_->message;
		_tmp27_ = g_strconcat ("Could not launch application: ", _tmp26_, NULL);
		_tmp28_ = _tmp27_;
		g_warning ("tracker-utils.vala:65: %s", _tmp28_);
		_g_free0 (_tmp28_);
		_g_error_free0 (e);
	}
	__finally23:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


void tracker_model_launch_selected (GtkTreeModel* model, GtkTreePath* path, gint col) {
	GtkTreeModel* _tmp0_;
	GtkTreePath* _tmp1_;
	gint _tmp2_;
	gchar* _tmp3_ = NULL;
	gchar* uri;
	g_return_if_fail (model != NULL);
	g_return_if_fail (path != NULL);
	_tmp0_ = model;
	_tmp1_ = path;
	_tmp2_ = col;
	_tmp3_ = uri_get_selected (_tmp0_, _tmp1_, _tmp2_);
	uri = _tmp3_;
	g_debug ("tracker-utils.vala:71: Selected uri:'%s'", uri);
	uri_launch (uri);
	_g_free0 (uri);
}


void tracker_model_launch_selected_parent_dir (GtkTreeModel* model, GtkTreePath* path, gint col) {
	GtkTreeModel* _tmp0_;
	GtkTreePath* _tmp1_;
	gint _tmp2_;
	gchar* _tmp3_ = NULL;
	gchar* uri;
	GFile* _tmp4_ = NULL;
	GFile* f;
	GFile* _tmp5_ = NULL;
	GFile* p;
	gchar* _tmp6_ = NULL;
	gchar* parent_uri;
	g_return_if_fail (model != NULL);
	g_return_if_fail (path != NULL);
	_tmp0_ = model;
	_tmp1_ = path;
	_tmp2_ = col;
	_tmp3_ = uri_get_selected (_tmp0_, _tmp1_, _tmp2_);
	uri = _tmp3_;
	g_debug ("tracker-utils.vala:78: Selected uri:'%s'", uri);
	_tmp4_ = g_file_new_for_uri (uri);
	f = _tmp4_;
	_tmp5_ = g_file_get_parent (f);
	p = _tmp5_;
	_tmp6_ = g_file_get_uri (p);
	parent_uri = _tmp6_;
	g_debug ("tracker-utils.vala:84: Parent uri:'%s'", parent_uri);
	uri_launch (parent_uri);
	_g_free0 (parent_uri);
	_g_object_unref0 (p);
	_g_object_unref0 (f);
	_g_free0 (uri);
}


static gchar* g_time_format (struct tm *self, const gchar* format) {
	gchar* result = NULL;
	gchar* _tmp0_ = NULL;
	gchar* buffer;
	gint buffer_length1;
	gint _buffer_size_;
	gchar* _tmp1_;
	gint _tmp1__length1;
	const gchar* _tmp2_;
	gchar* _tmp3_;
	gint _tmp3__length1;
	gchar* _tmp4_;
	g_return_val_if_fail (format != NULL, NULL);
	_tmp0_ = g_new0 (gchar, 64);
	buffer = _tmp0_;
	buffer_length1 = 64;
	_buffer_size_ = buffer_length1;
	_tmp1_ = buffer;
	_tmp1__length1 = buffer_length1;
	_tmp2_ = format;
	strftime (_tmp1_, _tmp1__length1, _tmp2_, &(*self));
	_tmp3_ = buffer;
	_tmp3__length1 = buffer_length1;
	_tmp4_ = g_strdup ((const gchar*) _tmp3_);
	result = _tmp4_;
	buffer = (g_free (buffer), NULL);
	return result;
}


gchar* tracker_time_format_from_iso8601 (const gchar* s) {
	gchar* result = NULL;
	struct tm t = {0};
	const gchar* _tmp0_;
	GTimeVal tv_now = {0};
	GTimeVal tv_then = {0};
	const gchar* _tmp1_;
	GTimeVal _tmp2_;
	glong _tmp3_;
	GTimeVal _tmp4_;
	glong _tmp5_;
	glong diff_sec;
	glong _tmp6_;
	glong diff_days;
	glong _tmp7_;
	glong _tmp8_ = 0L;
	glong diff_days_abs;
	glong _tmp9_;
	glong _tmp12_;
	g_return_val_if_fail (s != NULL, NULL);
	memset (&t, 0, sizeof (struct tm));
	_tmp0_ = s;
	strptime (_tmp0_, "%FT%T", &t);
	g_get_current_time (&tv_now);
	g_get_current_time (&tv_now);
	g_get_current_time (&tv_then);
	_tmp1_ = s;
	g_time_val_from_iso8601 (_tmp1_, &tv_then);
	_tmp2_ = tv_now;
	_tmp3_ = _tmp2_.tv_sec;
	_tmp4_ = tv_then;
	_tmp5_ = _tmp4_.tv_sec;
	diff_sec = _tmp3_ - _tmp5_;
	_tmp6_ = diff_sec;
	diff_days = _tmp6_ / secs_per_day;
	_tmp7_ = diff_days;
	_tmp8_ = labs (_tmp7_);
	diff_days_abs = _tmp8_;
	_tmp9_ = diff_days_abs;
	if (_tmp9_ > ((glong) 7)) {
		const gchar* _tmp10_ = NULL;
		gchar* _tmp11_ = NULL;
		_tmp10_ = _ ("%x");
		_tmp11_ = g_time_format (&t, _tmp10_);
		result = _tmp11_;
		return result;
	}
	_tmp12_ = diff_days_abs;
	if (_tmp12_ == ((glong) 0)) {
		const gchar* _tmp13_ = NULL;
		gchar* _tmp14_;
		_tmp13_ = _ ("Today");
		_tmp14_ = g_strdup (_tmp13_);
		result = _tmp14_;
		return result;
	} else {
		gboolean future;
		glong _tmp15_;
		glong _tmp16_;
		future = FALSE;
		_tmp15_ = diff_days;
		if (_tmp15_ < ((glong) 0)) {
			future = TRUE;
		}
		_tmp16_ = diff_days;
		if (_tmp16_ <= ((glong) 1)) {
			gboolean _tmp17_;
			_tmp17_ = future;
			if (_tmp17_) {
				const gchar* _tmp18_ = NULL;
				gchar* _tmp19_;
				_tmp18_ = _ ("Tomorrow");
				_tmp19_ = g_strdup (_tmp18_);
				result = _tmp19_;
				return result;
			} else {
				const gchar* _tmp20_ = NULL;
				gchar* _tmp21_;
				_tmp20_ = _ ("Yesterday");
				_tmp21_ = g_strdup (_tmp20_);
				result = _tmp21_;
				return result;
			}
		} else {
			gboolean _tmp22_;
			_tmp22_ = future;
			if (_tmp22_) {
				glong _tmp23_;
				const gchar* _tmp24_ = NULL;
				glong _tmp25_;
				gchar* _tmp26_ = NULL;
				_tmp23_ = diff_days_abs;
				_tmp24_ = ngettext ("%ld day from now", "%ld days from now", (gulong) _tmp23_);
				_tmp25_ = diff_days_abs;
				_tmp26_ = g_strdup_printf (_tmp24_, _tmp25_);
				result = _tmp26_;
				return result;
			} else {
				glong _tmp27_;
				const gchar* _tmp28_ = NULL;
				glong _tmp29_;
				gchar* _tmp30_ = NULL;
				_tmp27_ = diff_days_abs;
				_tmp28_ = ngettext ("%ld day ago", "%ld days ago", (gulong) _tmp27_);
				_tmp29_ = diff_days_abs;
				_tmp30_ = g_strdup_printf (_tmp28_, _tmp29_);
				result = _tmp30_;
				return result;
			}
		}
	}
}


gchar* tracker_time_format_from_seconds (const gchar* seconds_str) {
	gchar* result = NULL;
	const gchar* _tmp0_;
	gint _tmp1_ = 0;
	gdouble seconds;
	gdouble total = 0.0;
	gint d = 0;
	gint h = 0;
	gint m = 0;
	gint s = 0;
	gdouble _tmp2_;
	gdouble _tmp5_;
	gdouble _tmp6_;
	gdouble _tmp7_;
	gdouble _tmp8_;
	gdouble _tmp9_;
	gdouble _tmp10_;
	gdouble _tmp11_;
	GString* _tmp12_;
	GString* output;
	gint _tmp13_;
	gint _tmp18_;
	gint _tmp23_;
	const gchar* _tmp31_ = NULL;
	gint _tmp32_;
	GString* _tmp33_;
	const gchar* _tmp34_;
	gint _tmp35_;
	gchar* _tmp36_ = NULL;
	gchar* _tmp37_;
	GString* _tmp38_;
	gssize _tmp39_;
	GString* _tmp42_;
	const gchar* _tmp43_;
	gchar* _tmp44_;
	gchar* str;
	const gchar* _tmp45_;
	const gchar* _tmp46_ = NULL;
	gchar* _tmp47_;
	g_return_val_if_fail (seconds_str != NULL, NULL);
	_tmp0_ = seconds_str;
	_tmp1_ = atoi (_tmp0_);
	seconds = (gdouble) _tmp1_;
	_tmp2_ = seconds;
	if (_tmp2_ == 0.0) {
		const gchar* _tmp3_ = NULL;
		gchar* _tmp4_;
		_tmp3_ = _ ("Less than one second");
		_tmp4_ = g_strdup (_tmp3_);
		result = _tmp4_;
		return result;
	}
	_tmp5_ = seconds;
	total = _tmp5_;
	_tmp6_ = total;
	s = ((gint) _tmp6_) % 60;
	_tmp7_ = total;
	total = _tmp7_ / 60;
	_tmp8_ = total;
	m = ((gint) _tmp8_) % 60;
	_tmp9_ = total;
	total = _tmp9_ / 60;
	_tmp10_ = total;
	h = ((gint) _tmp10_) % 24;
	_tmp11_ = total;
	d = ((gint) _tmp11_) / 24;
	_tmp12_ = g_string_new ("");
	output = _tmp12_;
	_tmp13_ = d;
	if (_tmp13_ > 0) {
		GString* _tmp14_;
		gint _tmp15_;
		gchar* _tmp16_ = NULL;
		gchar* _tmp17_;
		_tmp14_ = output;
		_tmp15_ = d;
		_tmp16_ = g_strdup_printf (" %dd", _tmp15_);
		_tmp17_ = _tmp16_;
		g_string_append (_tmp14_, _tmp17_);
		_g_free0 (_tmp17_);
	}
	_tmp18_ = h;
	if (_tmp18_ > 0) {
		GString* _tmp19_;
		gint _tmp20_;
		gchar* _tmp21_ = NULL;
		gchar* _tmp22_;
		_tmp19_ = output;
		_tmp20_ = h;
		_tmp21_ = g_strdup_printf (" %.2d", _tmp20_);
		_tmp22_ = _tmp21_;
		g_string_append (_tmp19_, _tmp22_);
		_g_free0 (_tmp22_);
	}
	_tmp23_ = m;
	if (_tmp23_ > 0) {
		const gchar* _tmp24_ = NULL;
		gint _tmp25_;
		GString* _tmp26_;
		const gchar* _tmp27_;
		gint _tmp28_;
		gchar* _tmp29_ = NULL;
		gchar* _tmp30_;
		_tmp25_ = h;
		if (_tmp25_ > 0) {
			_tmp24_ = ":";
		} else {
			_tmp24_ = "";
		}
		_tmp26_ = output;
		_tmp27_ = _tmp24_;
		_tmp28_ = m;
		_tmp29_ = g_strdup_printf ("%s%.2d", _tmp27_, _tmp28_);
		_tmp30_ = _tmp29_;
		g_string_append (_tmp26_, _tmp30_);
		_g_free0 (_tmp30_);
	}
	_tmp32_ = m;
	if (_tmp32_ > 0) {
		_tmp31_ = ":";
	} else {
		_tmp31_ = "0:";
	}
	_tmp33_ = output;
	_tmp34_ = _tmp31_;
	_tmp35_ = s;
	_tmp36_ = g_strdup_printf ("%s%.2d", _tmp34_, _tmp35_);
	_tmp37_ = _tmp36_;
	g_string_append (_tmp33_, _tmp37_);
	_g_free0 (_tmp37_);
	_tmp38_ = output;
	_tmp39_ = _tmp38_->len;
	if (_tmp39_ < ((gssize) 1)) {
		const gchar* _tmp40_ = NULL;
		gchar* _tmp41_;
		_tmp40_ = _ ("Less than one second");
		_tmp41_ = g_strdup (_tmp40_);
		result = _tmp41_;
		_g_string_free0 (output);
		return result;
	}
	_tmp42_ = output;
	_tmp43_ = _tmp42_->str;
	_tmp44_ = g_strdup (_tmp43_);
	str = _tmp44_;
	_tmp45_ = str;
	_tmp46_ = g_strchug (_tmp45_);
	_tmp47_ = g_strdup (_tmp46_);
	result = _tmp47_;
	_g_free0 (str);
	_g_string_free0 (output);
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


GdkPixbuf* tracker_pixbuf_new_from_file (GtkIconTheme* theme, const gchar* filename, gint size, gboolean is_image) {
	GdkPixbuf* result = NULL;
	const gchar* _tmp0_;
	GFile* _tmp1_ = NULL;
	GFile* file;
	GdkPixbuf* _tmp2_;
	GdkPixbuf* pixbuf;
	gboolean _tmp3_;
	GFile* _tmp17_;
	gboolean _tmp18_ = FALSE;
	GdkPixbuf* _tmp50_;
	GtkIconTheme* _tmp51_;
	gint _tmp52_;
	GdkPixbuf* _tmp53_ = NULL;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (theme != NULL, NULL);
	g_return_val_if_fail (filename != NULL, NULL);
	_tmp0_ = filename;
	_tmp1_ = g_file_new_for_uri (_tmp0_);
	file = _tmp1_;
	_tmp2_ = _g_object_ref0 (GDK_IS_PIXBUF (NULL) ? ((GdkPixbuf*) NULL) : NULL);
	pixbuf = _tmp2_;
	_tmp3_ = is_image;
	if (_tmp3_) {
		GdkPixbuf* _tmp16_;
		{
			GFile* _tmp4_;
			gchar* _tmp5_ = NULL;
			gchar* _tmp6_;
			gint _tmp7_;
			gint _tmp8_;
			GdkPixbuf* _tmp9_;
			GdkPixbuf* _tmp10_;
			GdkPixbuf* _tmp11_;
			_tmp4_ = file;
			_tmp5_ = g_file_get_path (_tmp4_);
			_tmp6_ = _tmp5_;
			_tmp7_ = size;
			_tmp8_ = size;
			_tmp9_ = gdk_pixbuf_new_from_file_at_size (_tmp6_, _tmp7_, _tmp8_, &_inner_error_);
			_tmp10_ = _tmp9_;
			_g_free0 (_tmp6_);
			_tmp11_ = _tmp10_;
			if (_inner_error_ != NULL) {
				goto __catch24_g_error;
			}
			_g_object_unref0 (pixbuf);
			pixbuf = _tmp11_;
		}
		goto __finally24;
		__catch24_g_error:
		{
			GError* e = NULL;
			GError* _tmp12_;
			const gchar* _tmp13_;
			gchar* _tmp14_;
			gchar* _tmp15_;
			e = _inner_error_;
			_inner_error_ = NULL;
			_tmp12_ = e;
			_tmp13_ = _tmp12_->message;
			_tmp14_ = g_strconcat ("Error loading icon pixbuf: ", _tmp13_, NULL);
			_tmp15_ = _tmp14_;
			g_warning ("tracker-utils.vala:188: %s", _tmp15_);
			_g_free0 (_tmp15_);
			_g_error_free0 (e);
		}
		__finally24:
		if (_inner_error_ != NULL) {
			_g_object_unref0 (pixbuf);
			_g_object_unref0 (file);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
		_tmp16_ = pixbuf;
		if (_tmp16_ != NULL) {
			result = pixbuf;
			_g_object_unref0 (file);
			return result;
		}
	}
	_tmp17_ = file;
	_tmp18_ = g_file_query_exists (_tmp17_, NULL);
	if (_tmp18_) {
		{
			GFile* _tmp19_;
			GFileInfo* _tmp20_ = NULL;
			GFileInfo* file_info;
			GFileInfo* _tmp21_;
			_tmp19_ = file;
			_tmp20_ = g_file_query_info (_tmp19_, "standard::icon", G_FILE_QUERY_INFO_NONE, NULL, &_inner_error_);
			file_info = _tmp20_;
			if (_inner_error_ != NULL) {
				goto __catch25_g_error;
			}
			_tmp21_ = file_info;
			if (_tmp21_ != NULL) {
				GFileInfo* _tmp22_;
				GIcon* _tmp23_ = NULL;
				GIcon* _tmp24_;
				GIcon* icon;
				_tmp22_ = file_info;
				_tmp23_ = g_file_info_get_icon (_tmp22_);
				_tmp24_ = _g_object_ref0 (_tmp23_);
				icon = _tmp24_;
				{
					GIcon* _tmp25_;
					_tmp25_ = icon;
					if (G_IS_FILE_ICON (_tmp25_)) {
						GIcon* _tmp26_;
						GFile* _tmp27_ = NULL;
						gchar* _tmp28_ = NULL;
						gchar* _tmp29_;
						GdkPixbuf* _tmp30_;
						GdkPixbuf* _tmp31_;
						GdkPixbuf* _tmp32_;
						_tmp26_ = icon;
						_tmp27_ = g_file_icon_get_file (G_FILE_ICON (_tmp26_));
						_tmp28_ = g_file_get_path (_tmp27_);
						_tmp29_ = _tmp28_;
						_tmp30_ = gdk_pixbuf_new_from_file (_tmp29_, &_inner_error_);
						_tmp31_ = _tmp30_;
						_g_free0 (_tmp29_);
						_tmp32_ = _tmp31_;
						if (_inner_error_ != NULL) {
							goto __catch26_g_error;
						}
						_g_object_unref0 (pixbuf);
						pixbuf = _tmp32_;
					} else {
						GIcon* _tmp33_;
						_tmp33_ = icon;
						if (G_IS_THEMED_ICON (_tmp33_)) {
							GtkIconTheme* _tmp34_;
							GIcon* _tmp35_;
							gchar** _tmp36_;
							gchar** _tmp37_ = NULL;
							const gchar* _tmp38_;
							gint _tmp39_;
							GdkPixbuf* _tmp40_ = NULL;
							GdkPixbuf* _tmp41_;
							_tmp34_ = theme;
							_tmp35_ = icon;
							_tmp37_ = _tmp36_ = g_themed_icon_get_names (G_THEMED_ICON (_tmp35_));
							_tmp38_ = _tmp37_[0];
							_tmp39_ = size;
							_tmp40_ = gtk_icon_theme_load_icon (_tmp34_, _tmp38_, _tmp39_, GTK_ICON_LOOKUP_USE_BUILTIN, &_inner_error_);
							_tmp41_ = _tmp40_;
							if (_inner_error_ != NULL) {
								goto __catch26_g_error;
							}
							_g_object_unref0 (pixbuf);
							pixbuf = _tmp41_;
						}
					}
				}
				goto __finally26;
				__catch26_g_error:
				{
					GError* e = NULL;
					GError* _tmp42_;
					const gchar* _tmp43_;
					gchar* _tmp44_;
					gchar* _tmp45_;
					e = _inner_error_;
					_inner_error_ = NULL;
					_tmp42_ = e;
					_tmp43_ = _tmp42_->message;
					_tmp44_ = g_strconcat ("Error loading icon pixbuf: ", _tmp43_, NULL);
					_tmp45_ = _tmp44_;
					g_warning ("tracker-utils.vala:212: %s", _tmp45_);
					_g_free0 (_tmp45_);
					_g_error_free0 (e);
				}
				__finally26:
				if (_inner_error_ != NULL) {
					_g_object_unref0 (icon);
					_g_object_unref0 (file_info);
					goto __catch25_g_error;
				}
				_g_object_unref0 (icon);
			}
			_g_object_unref0 (file_info);
		}
		goto __finally25;
		__catch25_g_error:
		{
			GError* e = NULL;
			GError* _tmp46_;
			const gchar* _tmp47_;
			gchar* _tmp48_;
			gchar* _tmp49_;
			e = _inner_error_;
			_inner_error_ = NULL;
			_tmp46_ = e;
			_tmp47_ = _tmp46_->message;
			_tmp48_ = g_strconcat ("Error looking up file for pixbuf: ", _tmp47_, NULL);
			_tmp49_ = _tmp48_;
			g_warning ("tracker-utils.vala:216: %s", _tmp49_);
			_g_free0 (_tmp49_);
			_g_error_free0 (e);
		}
		__finally25:
		if (_inner_error_ != NULL) {
			_g_object_unref0 (pixbuf);
			_g_object_unref0 (file);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
			g_clear_error (&_inner_error_);
			return NULL;
		}
	}
	_tmp50_ = pixbuf;
	if (_tmp50_ != NULL) {
		result = pixbuf;
		_g_object_unref0 (file);
		return result;
	}
	_tmp51_ = theme;
	_tmp52_ = size;
	_tmp53_ = tracker_pixbuf_new_from_name (_tmp51_, "text-x-generic", _tmp52_);
	result = _tmp53_;
	_g_object_unref0 (pixbuf);
	_g_object_unref0 (file);
	return result;
}


GdkPixbuf* tracker_pixbuf_new_from_name (GtkIconTheme* theme, const gchar* name, gint size) {
	GdkPixbuf* result = NULL;
	GdkPixbuf* _tmp0_;
	GdkPixbuf* pixbuf;
	GError * _inner_error_ = NULL;
	g_return_val_if_fail (theme != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	_tmp0_ = _g_object_ref0 (GDK_IS_PIXBUF (NULL) ? ((GdkPixbuf*) NULL) : NULL);
	pixbuf = _tmp0_;
	{
		GtkIconTheme* _tmp1_;
		const gchar* _tmp2_;
		gint _tmp3_;
		GdkPixbuf* _tmp4_ = NULL;
		GdkPixbuf* _tmp5_;
		_tmp1_ = theme;
		_tmp2_ = name;
		_tmp3_ = size;
		_tmp4_ = gtk_icon_theme_load_icon (_tmp1_, _tmp2_, _tmp3_, GTK_ICON_LOOKUP_USE_BUILTIN, &_inner_error_);
		_tmp5_ = _tmp4_;
		if (_inner_error_ != NULL) {
			goto __catch27_g_error;
		}
		_g_object_unref0 (pixbuf);
		pixbuf = _tmp5_;
	}
	goto __finally27;
	__catch27_g_error:
	{
		GError* e = NULL;
		const gchar* _tmp6_;
		GError* _tmp7_;
		const gchar* _tmp8_;
		e = _inner_error_;
		_inner_error_ = NULL;
		_tmp6_ = name;
		_tmp7_ = e;
		_tmp8_ = _tmp7_->message;
		g_warning ("tracker-utils.vala:234: Could not load default icon pixbuf from theme " \
"for '%s': %s", _tmp6_, _tmp8_);
		_g_error_free0 (e);
	}
	__finally27:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (pixbuf);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	result = pixbuf;
	return result;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}



