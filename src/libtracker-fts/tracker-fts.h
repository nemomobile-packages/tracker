/*
** 2006 Oct 10
**
** The author disclaims copyright to this source code.	In place of
** a legal notice, here is a blessing:
**
**    May you do good and not evil.
**    May you find forgiveness for yourself and forgive others.
**    May you share freely, never taking more than you give.
**
******************************************************************************
**
** This header file is used by programs that want to link against the
** FTS3 library.
*/

#ifndef __TRACKER_FTS_H__
#define __TRACKER_FTS_H__

#include <sqlite3.h>
#include <glib.h>
#include <glib-object.h>

G_BEGIN_DECLS

typedef const gchar *(*TrackerFtsMapFunc) (gint id);

typedef struct fulltext_vtab TrackerFts;

TrackerFts *tracker_fts_new              (sqlite3           *db,
                                          int                create);
void        tracker_fts_free             (TrackerFts        *fts);
int         tracker_fts_update_init      (TrackerFts        *fts,
                                          int                id);
int         tracker_fts_update_text      (TrackerFts        *fts,
                                          int                id,
                                          int                column_id,
                                          const char        *text,
                                          gboolean           limit_word_length);
void        tracker_fts_update_commit    (TrackerFts        *fts);
void        tracker_fts_update_rollback  (TrackerFts        *fts);

G_END_DECLS

#endif /* __TRACKER_FTS_H__ */

