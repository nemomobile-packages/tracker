
#ifndef __tracker_marshal_MARSHAL_H__
#define __tracker_marshal_MARSHAL_H__

#include	<glib-object.h>

G_BEGIN_DECLS

/* VOID:OBJECT,BOOLEAN (tracker-marshal.list:1) */
extern void tracker_marshal_VOID__OBJECT_BOOLEAN (GClosure     *closure,
                                                  GValue       *return_value,
                                                  guint         n_param_values,
                                                  const GValue *param_values,
                                                  gpointer      invocation_hint,
                                                  gpointer      marshal_data);

/* VOID:OBJECT,OBJECT (tracker-marshal.list:2) */
extern void tracker_marshal_VOID__OBJECT_OBJECT (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

/* VOID:OBJECT,OBJECT,BOOLEAN,BOOLEAN (tracker-marshal.list:3) */
extern void tracker_marshal_VOID__OBJECT_OBJECT_BOOLEAN_BOOLEAN (GClosure     *closure,
                                                                 GValue       *return_value,
                                                                 guint         n_param_values,
                                                                 const GValue *param_values,
                                                                 gpointer      invocation_hint,
                                                                 gpointer      marshal_data);

/* VOID:OBJECT,POINTER,UINT,UINT,UINT,UINT (tracker-marshal.list:4) */
extern void tracker_marshal_VOID__OBJECT_POINTER_UINT_UINT_UINT_UINT (GClosure     *closure,
                                                                      GValue       *return_value,
                                                                      guint         n_param_values,
                                                                      const GValue *param_values,
                                                                      gpointer      invocation_hint,
                                                                      gpointer      marshal_data);

/* VOID:OBJECT,UINT,UINT,UINT,UINT (tracker-marshal.list:5) */
extern void tracker_marshal_VOID__OBJECT_UINT_UINT_UINT_UINT (GClosure     *closure,
                                                              GValue       *return_value,
                                                              guint         n_param_values,
                                                              const GValue *param_values,
                                                              gpointer      invocation_hint,
                                                              gpointer      marshal_data);

/* VOID:DOUBLE,UINT,UINT,UINT,UINT (tracker-marshal.list:6) */
extern void tracker_marshal_VOID__DOUBLE_UINT_UINT_UINT_UINT (GClosure     *closure,
                                                              GValue       *return_value,
                                                              guint         n_param_values,
                                                              const GValue *param_values,
                                                              gpointer      invocation_hint,
                                                              gpointer      marshal_data);

/* VOID:STRING,DOUBLE,INT (tracker-marshal.list:7) */
extern void tracker_marshal_VOID__STRING_DOUBLE_INT (GClosure     *closure,
                                                     GValue       *return_value,
                                                     guint         n_param_values,
                                                     const GValue *param_values,
                                                     gpointer      invocation_hint,
                                                     gpointer      marshal_data);

/* VOID:STRING,STRING (tracker-marshal.list:8) */
extern void tracker_marshal_VOID__STRING_STRING (GClosure     *closure,
                                                 GValue       *return_value,
                                                 guint         n_param_values,
                                                 const GValue *param_values,
                                                 gpointer      invocation_hint,
                                                 gpointer      marshal_data);

/* VOID:STRING,STRING,DOUBLE,INT (tracker-marshal.list:9) */
extern void tracker_marshal_VOID__STRING_STRING_DOUBLE_INT (GClosure     *closure,
                                                            GValue       *return_value,
                                                            guint         n_param_values,
                                                            const GValue *param_values,
                                                            gpointer      invocation_hint,
                                                            gpointer      marshal_data);

/* VOID:STRING,STRING,BOOLEAN,BOOLEAN (tracker-marshal.list:10) */
extern void tracker_marshal_VOID__STRING_STRING_BOOLEAN_BOOLEAN (GClosure     *closure,
                                                                 GValue       *return_value,
                                                                 guint         n_param_values,
                                                                 const GValue *param_values,
                                                                 gpointer      invocation_hint,
                                                                 gpointer      marshal_data);

/* VOID:STRING,STRING,STRING,BOOLEAN,BOOLEAN (tracker-marshal.list:11) */
extern void tracker_marshal_VOID__STRING_STRING_STRING_BOOLEAN_BOOLEAN (GClosure     *closure,
                                                                        GValue       *return_value,
                                                                        guint         n_param_values,
                                                                        const GValue *param_values,
                                                                        gpointer      invocation_hint,
                                                                        gpointer      marshal_data);

/* BOOL:OBJECT,OBJECT,OBJECT (tracker-marshal.list:12) */
extern void tracker_marshal_BOOLEAN__OBJECT_OBJECT_OBJECT (GClosure     *closure,
                                                           GValue       *return_value,
                                                           guint         n_param_values,
                                                           const GValue *param_values,
                                                           gpointer      invocation_hint,
                                                           gpointer      marshal_data);
#define tracker_marshal_BOOL__OBJECT_OBJECT_OBJECT	tracker_marshal_BOOLEAN__OBJECT_OBJECT_OBJECT

/* BOOL:OBJECT,OBJECT (tracker-marshal.list:13) */
extern void tracker_marshal_BOOLEAN__OBJECT_OBJECT (GClosure     *closure,
                                                    GValue       *return_value,
                                                    guint         n_param_values,
                                                    const GValue *param_values,
                                                    gpointer      invocation_hint,
                                                    gpointer      marshal_data);
#define tracker_marshal_BOOL__OBJECT_OBJECT	tracker_marshal_BOOLEAN__OBJECT_OBJECT

/* BOOL:OBJECT,POINTER (tracker-marshal.list:14) */
extern void tracker_marshal_BOOLEAN__OBJECT_POINTER (GClosure     *closure,
                                                     GValue       *return_value,
                                                     guint         n_param_values,
                                                     const GValue *param_values,
                                                     gpointer      invocation_hint,
                                                     gpointer      marshal_data);
#define tracker_marshal_BOOL__OBJECT_POINTER	tracker_marshal_BOOLEAN__OBJECT_POINTER

/* BOOL:OBJECT (tracker-marshal.list:15) */
extern void tracker_marshal_BOOLEAN__OBJECT (GClosure     *closure,
                                             GValue       *return_value,
                                             guint         n_param_values,
                                             const GValue *param_values,
                                             gpointer      invocation_hint,
                                             gpointer      marshal_data);
#define tracker_marshal_BOOL__OBJECT	tracker_marshal_BOOLEAN__OBJECT

/* BOOL:OBJECT,BOXED,BOXED,OBJECT (tracker-marshal.list:16) */
extern void tracker_marshal_BOOLEAN__OBJECT_BOXED_BOXED_OBJECT (GClosure     *closure,
                                                                GValue       *return_value,
                                                                guint         n_param_values,
                                                                const GValue *param_values,
                                                                gpointer      invocation_hint,
                                                                gpointer      marshal_data);
#define tracker_marshal_BOOL__OBJECT_BOXED_BOXED_OBJECT	tracker_marshal_BOOLEAN__OBJECT_BOXED_BOXED_OBJECT

G_END_DECLS

#endif /* __tracker_marshal_MARSHAL_H__ */

