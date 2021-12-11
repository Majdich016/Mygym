#include <gtk/gtk.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"affichage.h"

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>

//fonction afichage staf et coachs 
enum   
{       
        CIN,
        NOM,
	PRENOM,
	TELEPHONE,
	ROLE,
        MAIL,	
        COLUMNS
};
void afficher_staf_coach(GtkWidget *liste)
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
char role[30];
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
	column = gtk_tree_view_column_new_with_attributes("  role", renderer, "text",ROLE, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("  mail", renderer, "text",MAIL, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	/*renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("  date_debut", renderer, "text",DATEDEBUT, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("  date_debut", renderer, "text",DATEFIN, NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
printf("pos2\n");*/
               
	
	}

	printf("pos3\n");
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING);
	
	printf("pos4\n");
	f = fopen("/home/jasser/Desktop/MyGym/gym/src/info_staff_coach", "r");
	printf("pos5\n");
	if(f==NULL)
	{printf("pos6\n");

		return;
	}		
	else 

      
	{ 
	//f = fopen("/home/jasser/Desktop/MyGym/gym/src/info_staff_coach", "a+");
	

	///	fichage recurcive 

	printf("pos9\n");

              while((fscanf(f,"%ld %s %s %s %s %s %ld ",&cin2,password1,username1, prenom ,mail1,role,&telephone1)!=EOF)&&(i<10))
		{
	printf("pos8\n");
	i=i+1;
	//sprintf(date,"%d/%d/%d",ddj,ddm,dda);
	//sprintf(date1,"%d/%d/%d",dfj,dfm,dfa);
	sprintf(telephone2,"%ld",telephone1);
	sprintf(cin3,"%ld",cin2);
	printf("pos10\n");
	gtk_list_store_append (store, &iter);
	printf("pos100000000 %d\n",i);

	gtk_list_store_set (store, &iter, CIN, cin3, NOM, username1, PRENOM, prenom , MAIL ,mail1 ,  ROLE ,role ,TELEPHONE , telephone2, -1); 
		
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
