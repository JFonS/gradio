/* ReleaseNotesWindow.c generated by valac 0.34.0, the Vala compiler
 * generated from ReleaseNotesWindow.vala, do not modify */

/* This file is part of Gradio.
 *
 * Gradio is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Gradio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Gradio.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <webkit2/webkit2.h>
#include <stdlib.h>
#include <string.h>


#define GRADIO_TYPE_RELEASE_NOTES_WINDOW (gradio_release_notes_window_get_type ())
#define GRADIO_RELEASE_NOTES_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GRADIO_TYPE_RELEASE_NOTES_WINDOW, GradioReleaseNotesWindow))
#define GRADIO_RELEASE_NOTES_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), GRADIO_TYPE_RELEASE_NOTES_WINDOW, GradioReleaseNotesWindowClass))
#define GRADIO_IS_RELEASE_NOTES_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GRADIO_TYPE_RELEASE_NOTES_WINDOW))
#define GRADIO_IS_RELEASE_NOTES_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GRADIO_TYPE_RELEASE_NOTES_WINDOW))
#define GRADIO_RELEASE_NOTES_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), GRADIO_TYPE_RELEASE_NOTES_WINDOW, GradioReleaseNotesWindowClass))

typedef struct _GradioReleaseNotesWindow GradioReleaseNotesWindow;
typedef struct _GradioReleaseNotesWindowClass GradioReleaseNotesWindowClass;
typedef struct _GradioReleaseNotesWindowPrivate GradioReleaseNotesWindowPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _GradioReleaseNotesWindow {
	GtkWindow parent_instance;
	GradioReleaseNotesWindowPrivate * priv;
};

struct _GradioReleaseNotesWindowClass {
	GtkWindowClass parent_class;
};

struct _GradioReleaseNotesWindowPrivate {
	GtkBox* Placeholder;
	WebKitWebView* notes;
};


static gpointer gradio_release_notes_window_parent_class = NULL;

GType gradio_release_notes_window_get_type (void) G_GNUC_CONST;
#define GRADIO_RELEASE_NOTES_WINDOW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), GRADIO_TYPE_RELEASE_NOTES_WINDOW, GradioReleaseNotesWindowPrivate))
enum  {
	GRADIO_RELEASE_NOTES_WINDOW_DUMMY_PROPERTY
};
GradioReleaseNotesWindow* gradio_release_notes_window_new (void);
GradioReleaseNotesWindow* gradio_release_notes_window_construct (GType object_type);
static void gradio_release_notes_window_CloseButton_clicked (GradioReleaseNotesWindow* self, GtkButton* button);
static void _gradio_release_notes_window_CloseButton_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self);
static void gradio_release_notes_window_OpenHomepageButton_clicked (GradioReleaseNotesWindow* self, GtkButton* button);
void util_open_website (const gchar* address);
static void _gradio_release_notes_window_OpenHomepageButton_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self);
static void gradio_release_notes_window_finalize (GObject* obj);


GradioReleaseNotesWindow* gradio_release_notes_window_construct (GType object_type) {
	GradioReleaseNotesWindow * self = NULL;
	WebKitWebView* _tmp0_ = NULL;
	GtkBox* _tmp1_ = NULL;
	WebKitWebView* _tmp2_ = NULL;
	WebKitWebView* _tmp3_ = NULL;
	WebKitWebView* _tmp4_ = NULL;
	WebKitWebView* _tmp5_ = NULL;
	self = (GradioReleaseNotesWindow*) g_object_new (object_type, NULL);
	gtk_window_set_keep_above ((GtkWindow*) self, TRUE);
	_tmp0_ = (WebKitWebView*) webkit_web_view_new ();
	g_object_ref_sink (_tmp0_);
	_g_object_unref0 (self->priv->notes);
	self->priv->notes = _tmp0_;
	_tmp1_ = self->priv->Placeholder;
	_tmp2_ = self->priv->notes;
	gtk_container_add ((GtkContainer*) _tmp1_, (GtkWidget*) _tmp2_);
	_tmp3_ = self->priv->notes;
	gtk_widget_show ((GtkWidget*) _tmp3_);
	_tmp4_ = self->priv->notes;
	gtk_widget_set_vexpand ((GtkWidget*) _tmp4_, TRUE);
	_tmp5_ = self->priv->notes;
	webkit_web_view_load_uri (_tmp5_, "https://gradio.haecker-felix.de/release_notes/" VERSION ".html");
	return self;
}


GradioReleaseNotesWindow* gradio_release_notes_window_new (void) {
	return gradio_release_notes_window_construct (GRADIO_TYPE_RELEASE_NOTES_WINDOW);
}


static void gradio_release_notes_window_CloseButton_clicked (GradioReleaseNotesWindow* self, GtkButton* button) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (button != NULL);
	gtk_window_close ((GtkWindow*) self);
}


static void _gradio_release_notes_window_CloseButton_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self) {
	gradio_release_notes_window_CloseButton_clicked ((GradioReleaseNotesWindow*) self, _sender);
}


static void gradio_release_notes_window_OpenHomepageButton_clicked (GradioReleaseNotesWindow* self, GtkButton* button) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (button != NULL);
	util_open_website ("https://github.com/haecker-felix/gradio/");
}


static void _gradio_release_notes_window_OpenHomepageButton_clicked_gtk_button_clicked (GtkButton* _sender, gpointer self) {
	gradio_release_notes_window_OpenHomepageButton_clicked ((GradioReleaseNotesWindow*) self, _sender);
}


static void gradio_release_notes_window_class_init (GradioReleaseNotesWindowClass * klass) {
	gint GradioReleaseNotesWindow_private_offset;
	gradio_release_notes_window_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (GradioReleaseNotesWindowPrivate));
	G_OBJECT_CLASS (klass)->finalize = gradio_release_notes_window_finalize;
	GradioReleaseNotesWindow_private_offset = g_type_class_get_instance_private_offset (klass);
	gtk_widget_class_set_template_from_resource (GTK_WIDGET_CLASS (klass), "/de/haecker-felix/gradio/ui/release-notes.ui");
	gtk_widget_class_bind_template_child_full (GTK_WIDGET_CLASS (klass), "Placeholder", FALSE, GradioReleaseNotesWindow_private_offset + G_STRUCT_OFFSET (GradioReleaseNotesWindowPrivate, Placeholder));
	gtk_widget_class_bind_template_callback_full (GTK_WIDGET_CLASS (klass), "CloseButton_clicked", G_CALLBACK(_gradio_release_notes_window_CloseButton_clicked_gtk_button_clicked));
	gtk_widget_class_bind_template_callback_full (GTK_WIDGET_CLASS (klass), "OpenHomepageButton_clicked", G_CALLBACK(_gradio_release_notes_window_OpenHomepageButton_clicked_gtk_button_clicked));
}


static void gradio_release_notes_window_instance_init (GradioReleaseNotesWindow * self) {
	self->priv = GRADIO_RELEASE_NOTES_WINDOW_GET_PRIVATE (self);
	gtk_widget_init_template (GTK_WIDGET (self));
}


static void gradio_release_notes_window_finalize (GObject* obj) {
	GradioReleaseNotesWindow * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, GRADIO_TYPE_RELEASE_NOTES_WINDOW, GradioReleaseNotesWindow);
	_g_object_unref0 (self->priv->Placeholder);
	_g_object_unref0 (self->priv->notes);
	G_OBJECT_CLASS (gradio_release_notes_window_parent_class)->finalize (obj);
}


GType gradio_release_notes_window_get_type (void) {
	static volatile gsize gradio_release_notes_window_type_id__volatile = 0;
	if (g_once_init_enter (&gradio_release_notes_window_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (GradioReleaseNotesWindowClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) gradio_release_notes_window_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (GradioReleaseNotesWindow), 0, (GInstanceInitFunc) gradio_release_notes_window_instance_init, NULL };
		GType gradio_release_notes_window_type_id;
		gradio_release_notes_window_type_id = g_type_register_static (gtk_window_get_type (), "GradioReleaseNotesWindow", &g_define_type_info, 0);
		g_once_init_leave (&gradio_release_notes_window_type_id__volatile, gradio_release_notes_window_type_id);
	}
	return gradio_release_notes_window_type_id__volatile;
}


