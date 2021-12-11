#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"afichage_fenetre.h"

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif




#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>




//qffichqge compts ********************

void affichage_fenetre(char cin,char date[] ,char prenom[] ,char username[],char mail[] ,char abonnement[] ,char telephone[]){
FILE *f;
long cin1;
//char cin2[30] ,cin3[30];
char username1[30];
char cin2[30];
char prenom1[30];
char password1[30];
char date1[30];
char date2[30];
char mail1[30];
char compt1[30];
char abonnement1[30];
char telephone2[30];
long telephone1;
int ddj,dda,ddm,dfa,dfm,dfj,rolx,m=0;
f=fopen("/home/jasser/Desktop/MyGym/gym/src/info_users.txt","r");
if(f!=NULL){
printf("pos9999999999999999\n");
while(fscanf(f,"%ld %s %d %s %s %s %s %ld %d %d %d %d %d %d ",&cin1,password1,&rolx,username1,prenom1,mail1,abonnement1,&telephone1,&ddj,&ddm,&dda,&dfj,&dfm,&dfa)!=EOF)
{
	
	sprintf(cin2,"%ld",cin1);
if(strcmp(cin,cin2)==0)
{
sprintf(date1,"%d/%d/%d",ddj,ddm,dda);
	sprintf(date2,"%d/%d/%d",dfj,dfm,dfa);
	sprintf(telephone2,"%ld",telephone1);

strcpy(username,username1);
strcpy(prenom,prenom1);
strcpy(mail,mail1);
strcpy(abonnement,abonnement1);
strcpy(telephone,telephone2);
strcpy(date,date1);
}
}
}
	


printf("pos000000000000000000000009\n");
fclose(f);
printf("pos911111111111111111111111111111\n");

}


/////////////////////////////////////////////////////
