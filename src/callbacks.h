#include <gtk/gtk.h>


void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button9_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
void
on_button10_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
on_medecin_activate_default            (GtkWindow       *window,
                                        gpointer         user_data);

void
on_button13_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button14adh_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button15adh_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_admin_set_focus                     (GtkWindow       *window,
                                        GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_supprimer_as_admin_clicked          (GtkWidget         *objet_graphique,
                                        gpointer         user_data);

void
on_modifier_as_admin_clicked           (GtkWidget         *objet_graphique,
                                        gpointer         user_data);


gboolean
on_notebook1_select_page               (GtkNotebook     *notebook,
                                        gboolean         move_focus,
                                        gpointer         user_data);


void
on_affichetree_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_ajouter_admin_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_adherent_set_focus                  (GtkWindow       *window,
                                        GtkWidget       *widget,
                                        gpointer         user_data);

void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button19_leave                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button20_clicked                    (GtkButton       *button,
                                        gpointer         user_data);
