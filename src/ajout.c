#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"ajout.h"

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>



enum   
{       
        CIN,
        NOM,
	PRENOM,
	TELEPHONE,
	ABONNEMENT,
        MAIL,	
	DATEDEBUT,
	DATEFIN,
        COLUMNS
};






//fonction ajouter nouveaux compt
void ajouter(long cin2,char password1[] , int rolx ,char prenom[] ,char username1[],char mail1[] ,char abonnement1[] ,long telephone1,int ddj,int ddm,int dda,int dfj,int dfm,int dfa)
{
FILE *f;
f=fopen("/home/jasser/Desktop/MyGym/gym/src/info_users.txt","a");
if(f!=NULL)
{fprintf(f,"%ld %s %d %s %s %s %s %ld %d %d %d %d %d %d \n",cin2,password1,rolx,username1, prenom,mail1,abonnement1,telephone1,ddj,ddm,dda,dfj,dfm,dfa);
fclose(f);
}
}

//fonction afichage adherent 

void afficher_adherent(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
FILE *f;
long cin2;
char username1[30];
char prenom[30];
char telephone2[30];
char date[30];
char cin3[30];
char date1[30];
char password1[30];
char nom1[30];
char mail1[30];
char compt[30];
char abonnement1[30];
long telephone1;
int ddj,dda,ddm,dfa,dfm,dfj,rolx,i=0;
store=NULL;
 
	
	store=gtk_tree_view_get_model(liste);	
printf("TEST\n");
	if (store==NULL)
	{

        renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("  cin", renderer, "text",CIN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" nom", renderer, "text",NOM, NULL);	
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("  prenom", renderer, "text",PRENOM, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("  telephone", renderer, "text",TELEPHONE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("  abonnement", renderer, "text",ABONNEMENT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("  mail", renderer, "text",MAIL, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("  date_debut", renderer, "text",DATEDEBUT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("  date_debut", renderer, "text",DATEFIN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
printf("pos2\n");
               
	
	}

	printf("pos3\n");
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	
	printf("pos4\n");
	f = fopen("/home/jasser/Desktop/MyGym/gym/src/info_users.txt", "r");
	printf("pos5\n");
	if(f==NULL)
	{printf("pos6\n");

		return;
	}		
	else 

      
	{ 
	//f = fopen("/home/jasser/Desktop/MyGym/gym/src/info_users.txt", "a+");
	

	///	fichage recurcive 

	printf("pos9\n");

              while((fscanf(f,"%ld %s %d %s %s %s %s %ld %d %d %d %d %d %d ",&cin2,password1,&rolx,username1, prenom ,mail1,abonnement1,&telephone1,&ddj,&ddm,&dda,&dfj,&dfm,&dfa)!=EOF)&&(i<10))
		{
	printf("pos8\n");
	i=i+1;
	sprintf(date,"%d/%d/%d",ddj,ddm,dda);
	sprintf(date1,"%d/%d/%d",dfj,dfm,dfa);
	sprintf(telephone2,"%ld",telephone1);
	sprintf(cin3,"%ld",cin2);
	printf("pos10\n");
	gtk_list_store_append (store, &iter);
	printf("pos100000000 %d\n",i);

	gtk_list_store_set (store, &iter, CIN, cin3, NOM, username1, PRENOM, prenom ,TELEPHONE , telephone2,  ABONNEMENT ,abonnement1 , MAIL ,mail1 ,DATEDEBUT,date,DATEFIN,date1, -1); 
		
//printf("pos101111111199999999\n");
}







	printf("pos11\n");
		fclose(f);
	printf("pos12\n");
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
	printf("pos13\n");
    g_object_unref (store);
printf("pos14\n");	
}
}



//suprimer un compt
int supprimer(long cin){
FILE *f,*g;
long cin1;
//char cin2[30] ,cin3[30];
char username1[30];
char prenom[30];
char password1[30];
char nom1[30];
char mail1[30];
char compt[30];
char abonnement1[30];
long telephone1;
int ddj,dda,ddm,dfa,dfm,dfj,rolx,m=0;
f=fopen("/home/jasser/Desktop/MyGym/gym/src/info_users.txt","r");
g=fopen("/home/jasser/Desktop/MyGym/gym/src/aux.txt","a+");
if(f!=NULL){
printf("pos9999999999999999\n");
while(fscanf(f,"%ld %s %d %s %s %s %s %ld %d %d %d %d %d %d ",&cin1,password1,&rolx,username1,prenom,mail1,abonnement1,&telephone1,&ddj,&ddm,&dda,&dfj,&dfm,&dfa)!=EOF)
{
if(cin!=cin1)
{
fprintf(g,"%ld %s %d %s %s %s %s %ld %d %d %d %d %d %d \n ",cin1,password1,rolx,username1,prenom,mail1,abonnement1,telephone1,ddj,ddm,dda,dfj,dfm,dfa);
printf("pos77777777777777777777\n");
}
else m=1;
}
}
printf("pos000000000000000000000009\n");
fclose(f);
printf("pos9233333333333333333333\n");
fclose(g);
printf("pos922222222222222222222222222\n");
rename("/home/jasser/Desktop/MyGym/gym/src/info_users.txt","/home/jasser/Desktop/MyGym/gym/src/test1.txt");
rename("/home/jasser/Desktop/MyGym/gym/src/aux.txt","/home/jasser/Desktop/MyGym/gym/src/info_users.txt");
printf("pos911111111111111111111111111111\n");
return m;
}
//*********************************************************************************
//logs sauvegarde
void logs_set(char cin[],int role){
FILE *f;
f=fopen("/home/jasser/Desktop/MyGym/gym/src/logs.txt","a");
if(f!=NULL)
{fprintf(f,"%s %d\n",cin,role);
fclose(f);
}
}
//********************************************************************************
//logs get
int logs_get(char cin100[],int *role100){
FILE *f;
int m=0;
f=fopen("/home/jasser/Desktop/MyGym/gym/src/logs.txt","a");
if (f!=NULL)
{
while(fscanf(f,"%s %d",cin100,role100)!=EOF)
{
}
}
return *role100;
}
//********************************************************************************

//modifier compt
int modifier_adherent (long cin10,char password10[], int rol10 ,char username10[], char prenom10[],char mail10[] ,char abonnement10[] ,long telephone10,int ddj10,int ddm10,int dda10,int dfj10,int dfm10,int dfa10){
FILE *f;
FILE *g;
long cin5;
char username5[30];
char password5[30];
char prenom5[30];
char nom5[30];
char mail5[30];
char compt5[30];
char abonnement5[30];
long telephone5;
int ddj5,dda5,ddm5,dfa5,dfm5,dfj5,m=0,rolx5;
f=fopen("/home/jasser/Desktop/MyGym/gym/src/info_users.txt","r");
g=fopen("/home/jasser/Desktop/MyGym/gym/src/aux.txt","w");
if(f!=NULL){
while(fscanf(f,"%ld %s %d %s %s %s %s %ld %d %d %d %d %d %d ",&cin5, password5,&rolx5,username5,mail5, prenom5,abonnement5,&telephone5,&ddj5,&ddm5,&dda5,&dfj5,&dfm5,&dfa5)!=EOF)
{
if(cin10==cin5)
{
fprintf(g,"%ld %s %d %s %s %s %s %ld %d %d %d %d %d %d ",cin10,password10,rol10,username10,prenom10,mail10,abonnement10,telephone10,ddj10,ddm10,dda10,dfj10,dfm10,dfa10);
m=1;
}
else    {fprintf(g,"%ld %s %d %s %s %s %s %ld %d %d %d %d %d %d 	",cin5,password5,rolx5,username5,prenom5,mail5,abonnement5,telephone5,ddj5,ddm5,dda5,dfj5,dfm5,dfa5);
	}
}
}
fclose(f);
fclose(g);
remove("/home/jasser/Desktop/MyGym/gym/src/info_users.txt");
rename("/home/jasser/Desktop/MyGym/gym/src/aux.txt","info_users1.txt");
return m;
}
