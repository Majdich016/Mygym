#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "ajout.h"
#include "verifier.h"
#include "affichage.h"
#include"afichage_fenetre.h"



GtkWidget  *test;

GtkWidget *authentification,*home;
void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
home=lookup_widget(objet_graphique,"home");
authentification=create_authentification();
gtk_widget_show(authentification);

}


GtkWidget *signin,*home;

void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
home=lookup_widget(objet_graphique,"home");
signin=create_signin();
gtk_widget_show(signin);
}


GtkWidget *authentification,*textview1,*textview2,*home,*admin,*medecin,*error,*kine,*adherent,*coach,*dietecien,*label35,*label36;
void
on_button3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f;
int role;
char login[30];
char password[30];
long cin23;
char username20[30];
char cin20[30];
char prenom20[30];
char password20[30];
char date20[30];
char date21[30];
char mail20[30];
char compt20[30];
char abonnement20[30];
char telephone20[30];
long telephone21;
int ddj20,dda20,ddm20,dfa20,dfm20,dfj20,rolx20;
char date[30],prenom[30],mail[30],username[30],telephone[30],abonnement[30];

int c;
GtkWidget *output40;
GtkWidget *output41;
GtkWidget *output30;
GtkWidget *output31;

GtkWidget *input1,*input2;
GtkWidget *output410;
GtkWidget *output411;
GtkWidget *output412;
GtkWidget *output413;
GtkWidget *output414;
GtkWidget *output415;
GtkWidget *output416;

output410=lookup_widget(objet_graphique,"label588");
output411=lookup_widget(objet_graphique,"label596");
output412=lookup_widget(objet_graphique,"label589");

output413=lookup_widget(objet_graphique,"label590");
output414=lookup_widget(objet_graphique,"label591");
output415=lookup_widget(objet_graphique,"label592");

output416=lookup_widget(objet_graphique,"label593");


input1=lookup_widget(objet_graphique,"entry1");
input2=lookup_widget(objet_graphique,"entry2");
authentification=lookup_widget(objet_graphique,"authentification");
strcpy(login,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
c=verifier(login,password);
printf("heeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeedi login %s\n",login);
logs_set(login,c);
if (c==1)
{admin=create_admin();
gtk_widget_show(admin);
gtk_widget_hide(authentification);

}
else if (c==2)
{medecin=create_medecin();
gtk_widget_show(medecin);
gtk_widget_hide(authentification);
}
else if (c==3)
{dietecien=create_dietecien();
gtk_widget_show(dietecien);
gtk_widget_hide(authentification);}
else if (c==4)
{coach=create_coach();
gtk_widget_show(coach);
gtk_widget_hide(authentification);
}
else if (c==5)
{kine=create_kine();
gtk_widget_show(kine);
gtk_widget_hide(authentification);}
else if (c==6)
{adherent=create_adherent();
gtk_widget_show(adherent);
gtk_widget_hide(authentification);
//**********************************************************************************************
//adherent=lookup_widget(objet_graphique,"adherent");

f=fopen("/home/jasser/Desktop/MyGym/gym/src/info_users.txt","r");
if(f!=NULL){
printf("pos999999999999********************9999\n");
while(fscanf(f,"%ld %s %d %s %s %s %s %ld %d %d %d %d %d %d ",&cin23,password20,&rolx20,username20,prenom20,mail20,abonnement20,&telephone21,&ddj20,&ddm20,&dda20,&dfj20,&dfm20,&dfa20)!=EOF)
{
	
	sprintf(cin20,"%ld",cin23);
printf("heeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeedhi cin20 %s\n",cin20);
if(login==cin20)
{
printf("6666666666666666666666666666666666666*******///////////***666666666666666666666666");
	/*sprintf(date20,"%d/%d/%d",ddj20,ddm20,dda20);
	sprintf(date21,"%d/%d/%d",dfj20,dfm20,dfa20);
	sprintf(telephone20,"%ld",telephone21);

strcpy(username,username20);
strcpy(prenom,prenom20);
strcpy(mail,mail20);
strcpy(abonnement,abonnement20);
strcpy(telephone,telephone20);
strcpy(date,date20);
printf("6666666666666666666666666666666666666**********666666666666666666666666");


printf("6666666666666666666666666666666666666666666666666666666666666");
*/
}

}

}
gtk_label_set_text(GTK_LABEL(output410),"username");
gtk_label_set_text(GTK_LABEL(output411),prenom);
gtk_label_set_text(GTK_LABEL(output412),login);
gtk_label_set_text(GTK_LABEL(output413),mail);
gtk_label_set_text(GTK_LABEL(output414),telephone);
gtk_label_set_text(GTK_LABEL(output415),date);
gtk_label_set_text(GTK_LABEL(output416),abonnement);
fclose(f);
printf("6666666666666666666666666666666666666666666666666666666666666");
}

//**********************************************************************************************
else if (c==-1)
{error=create_error();
gtk_widget_show(error);
gtk_widget_hide(authentification);}
}

GtkWidget *signin;
void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{/*
GtkWidget *input3,*input4,*input5;
char login1[30],password1[30],rolec[10];
int role;

input3=lookup_widget(objet_graphique,"entry3");
input4=lookup_widget(objet_graphique,"entry4");
input5=lookup_widget(objet_graphique,"entry5");

signin=lookup_widget(objet_graphique,"signin");

strcpy(login1,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(password1,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(rolec,gtk_entry_get_text(GTK_ENTRY(input5)));
role=atoi(rolec);
ajouter(login1,password1,role);
gtk_widget_hide(signin);
*/
}



GtkWidget *signin,*error;
void
on_button9_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
error=lookup_widget(objet_graphique,"error");
signin=create_signin();
gtk_widget_show(signin);
gtk_widget_hide(error);

}


GtkWidget *authentification,*error;

void
on_button10_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
error=lookup_widget(objet_graphique,"error");
authentification=create_authentification();
gtk_widget_show(authentification);
gtk_widget_hide(error);
}


void
on_medecin_activate_default            (GtkWindow       *window,
                                        gpointer         user_data)
{

}

GtkWidget *admin;
void
on_button13_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *combobox4;
GtkWidget *combobox3;
GtkWidget *dda,*ddm,*ddj,*dfa,*dfm,*label90,*dfj,*input101,*input100,*tel1,*cin1,*prenom,*password2;

long cin2;
char username1[30];
char prenom1[30];
char password11[30];
char nom1[30];
char mail1[30];
char compt[30];
char abonnement1[30];
long telephone1;
int ddj1,dda1,ddm1,dfa1,dfm1,dfj1;

int rolx;
input100=lookup_widget(objet_graphique,"entry6");
prenom=lookup_widget(objet_graphique,"entry105");
password2=lookup_widget(objet_graphique,"entry106");
input101=lookup_widget(objet_graphique,"entry7");
label90=lookup_widget(objet_graphique,"label90");
cin1=lookup_widget(objet_graphique,"spinbutton15");


tel1=lookup_widget(objet_graphique,"spinbutton16");

ddj=lookup_widget(objet_graphique,"spinbutton9");
ddm=lookup_widget(objet_graphique,"spinbutton10");
dda=lookup_widget(objet_graphique,"spinbutton11");

dfj=lookup_widget(objet_graphique,"spinbutton12");
dfm=lookup_widget(objet_graphique,"spinbutton14");
dfa=lookup_widget(objet_graphique,"spinbutton13");

combobox3=lookup_widget(objet_graphique,"combobox3");
combobox4=lookup_widget(objet_graphique,"combobox4");


admin=lookup_widget(objet_graphique,"admin");

strcpy(username1,gtk_entry_get_text(GTK_ENTRY(input100)));
strcpy(prenom1,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(password11,gtk_entry_get_text(GTK_ENTRY(password2)));

strcpy(mail1,gtk_entry_get_text(GTK_ENTRY(input101)));
cin2=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(cin1));

telephone1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(tel1));


ddj1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ddj));
ddm1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ddm));
dda1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dda));

dfj1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dfj));
dfm1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dfm));
dfa1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(dfa));

strcpy(abonnement1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));
strcpy(compt,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));


if(strcmp(compt,"adherent")==0){
rolx=6;
}
else if(strcmp(compt,"admin")==0){
rolx=1;
}
else if(strcmp(compt,"coach")==0){
rolx=5;
}
else if(strcmp(compt,"dietecien")==0){
rolx=4;
}
else if(strcmp(compt,"kine")==0){
rolx=3;
}
else if(strcmp(compt,"medecin")==0){
rolx=2;
}

ajouter(cin2,password11,rolx,username1,prenom1,mail1,abonnement1,telephone1,ddj1,ddm1,dda1,dfj1,dfm1,dfa1);
gtk_label_set_text(GTK_LABEL(label90),"inscription réusite.");
}

GtkWidget *admin,*home;
void
on_admin_set_focus                     (GtkWindow       *window,
                                        GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview2,treeview3;
GtkWidget *admin;

admin=lookup_widget(window,"admin");
//gtk_widget_destroy(home);

treeview2=lookup_widget(admin,"treeview1");
//treeview3=lookup_widget(admin,"treeview3");


afficher_adherent(treeview2);
//afficher_staf_coach(treeview3);
	
}



void
on_button14adh_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button15adh_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}



GtkWidget *admin;
void
on_supprimer_as_admin_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *supprimeraz;
int cin;
admin=lookup_widget(objet_graphique,"admin");
supprimeraz=lookup_widget(objet_graphique,"spinbutton26");
cin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(supprimeraz));
supprimer(cin);
printf("pos7897987987987987987\n");
}


void
on_modifier_as_admin_clicked           (GtkWidget         *objet_graphique,
                                        gpointer         user_data)
{
/*
GtkWidget *supprimer;
int cin;
supprimer=lookup_widget(objet_graphique,"spinbutton26");
cin=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(supprimer));
modifier_adherent(cin);*/
}



gboolean
on_notebook1_select_page               (GtkNotebook     *notebook,
                                        gboolean         move_focus,
                                        gpointer         user_data)
{
/*
GtkWidget *treeview2;
GtkWidget *admin;
GtkNotebook     *notebook2;

notebook2=lookup_widget(notebook,"notebook1");
//gtk_widget_destroy(home);

treeview2=lookup_widget(notebook2,"treeview1");


afficher_adherent(treeview2);*/

/*
GtkWidget *treeview1;
GtkWidget *adherent1;

admin=lookup_widget(objet,"admin");

adherent1 = notebook.get_current_page();
gtk_widget_destroy(home);
      
treeview1=lookup_widget(adherent1,"treeview1");

afficher_adherent(treeview1);
  return FALSE;*/
}



void
on_affichetree_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview2;
GtkWidget *admin;

admin=lookup_widget(objet_graphique,"admin");
//gtk_widget_destroy(home);
//test=lookup_widget(objet_graphique,"test");
//test=create_test();
//gtk_widget_show(test);



treeview2=lookup_widget(admin,"treeview3");


afficher_staf_coach(treeview2);

}




void
on_ajouter_admin_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}

GtkWidget *adherent;
void
on_adherent_set_focus                  (GtkWindow       *objet_graphique,
                                        GtkWidget       *widget,
                                        gpointer         user_data)
{
GtkWidget *treeview2;
GtkWidget *adherent;
FILE *f;

//pointeur qdherent

//poiteur coqch
GtkWidget *output300;
GtkWidget *output310;
/*
char date[30],prenom[30],mail[30],username[30],telephone[30],login[30];
int m=0,l=0;


FILE *f;
int role;
char login[30];
char password[30];
long cin23;
char username20[30];
char cin20[30];
char prenom20[30];
char password20[30];
char date20[30];
char date21[30];
char mail20[30];
char compt20[30];
char abonnement20[30];
char telephone20[30];
long telephone21;
char login[30];

int ddj20,dda20,ddm20,dfa20,dfm20,dfj20,rolx20,ll;
char date[30],prenom[30],mail[30],username[30],telephone[30],abonnement[30];

int c;
GtkWidget *output40;
GtkWidget *output41;
GtkWidget *output30;
GtkWidget *output31;

GtkWidget *input1,*input2;
GtkWidget *output410;
GtkWidget *output411;
GtkWidget *output412;
GtkWidget *output413;
GtkWidget *output414;
GtkWidget *output415;




//affichage_fenetre(login,date,prenom ,username, mail ,abonnement, telephone);
adherent=lookup_widget(objet_graphique,"adherent");

output410=lookup_widget(objet_graphique,"label588");
output411=lookup_widget(objet_graphique,"label596");
output412=lookup_widget(objet_graphique,"label589");

output413=lookup_widget(objet_graphique,"label590");
output414=lookup_widget(objet_graphique,"label591");
output415=lookup_widget(objet_graphique,"label592");

output416=lookup_widget(objet_graphique,"label593");
l=logs_get(cin100,&m);
printf("pppppppp************************************** %s \n cccccccccccccccc %d wwwxxc \n%d",cin100,l,m);
//affichage_fenetre(login,date,prenom ,username, mail ,abonnement, telephone);


//printf("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");*/

/*
adherent=lookup_widget(objet_graphique,"adherent");
f=fopen("/home/jasser/Desktop/MyGym/gym/src/info_users.txt","r");
if(f!=NULL){
printf("pos999999999999********************9999\n");
while(fscanf(f,"%ld %s %d %s %s %s %s %ld %d %d %d %d %d %d ",&cin23,password20,&rolx20,username20,prenom20,mail20,abonnement20,&telephone21,&ddj20,&ddm20,&dda20,&dfj20,&dfm20,&dfa20)!=EOF)
{
	
	sprintf(cin20,"%ld",cin23);
if(strcmp(login,cin20)==0)
{
	sprintf(date20,"%d/%d/%d",ddj20,ddm20,dda20);
	sprintf(date21,"%d/%d/%d",dfj20,dfm20,dfa20);
	sprintf(telephone20,"%ld",telephone21);

strcpy(username,username20);
strcpy(prenom,prenom20);
strcpy(mail,mail20);
strcpy(abonnement,abonnement20);
strcpy(telephone,telephone20);
strcpy(date,date20);
gtk_label_set_text(GTK_LABEL(output410),username);
gtk_label_set_text(GTK_LABEL(output411),prenom);
gtk_label_set_text(GTK_LABEL(output412),login);
gtk_label_set_text(GTK_LABEL(output413),mail);
gtk_label_set_text(GTK_LABEL(output414),telephone);
gtk_label_set_text(GTK_LABEL(output415),date);
gtk_label_set_text(GTK_LABEL(output416),abonnement);
}

}

}
fclose(f);*/




//treeview2=lookup_widget(adherent,"treeview5");


//afficher_staf_coach(treeview2);
}


void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button19_leave                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button20_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}

