#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
#include <ctype.h>


typedef struct
{
    int jour;
    int mois;
    int annee;

}dates;
typedef struct
{
    int recid;
    dates date; 
    char tel[9] ;
    char idpark[5];
    char avis [2];
    char desc[300];
}rec;


int ajouter(char *,rec ,int choix[],char ch[]);
int modifier( char *, char*,int, rec,char cha[] ,char ch[],int choix2[]);
int supprimer(char *, char* ,int,char ch[]);
rec chercher(char *, char*,int,char ch[]);



#endif // POINT_H_INCLUDED
