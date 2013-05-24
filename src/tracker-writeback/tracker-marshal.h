
#ifndef __tracker_marshal_MARSHAL_H__
#define __tracker_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:BOXED (tracker-marshal.list:1) */
#define tracker_marshal_VOID__BOXED	g_cclosure_marshal_VOID__BOXED

/* VOID:INT,BOXED (tracker-marshal.list:2) */
extern void tracker_marshal_VOID__INT_BOXED (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);

G_END_DECLS

#endif /* __tracker_marshal_MARSHAL_H__ */

