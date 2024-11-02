#include "rec.h"
#include<string.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////

int ajouter(char *filename, rec d, int choix[], char ch[])
{
    strcpy(ch, "");
    if (choix[0] == 1)
        strcat(ch, "/Problème_de_paiement/");
    if (choix[1] == 1)
        strcat(ch, "/Problème_avec_le_service_client/");
    if (choix[2] == 1)
        strcat(ch, "/Dommages_au_véhicule/");
    if (choix[3] == 1)
        strcat(ch, "/Autre/");

    // Replace spaces in the description with underscores
    for (int i = 0; d.desc[i] != '\0'; i++) {
        if (d.desc[i] == ' ') {
            d.desc[i] = '_';
        }
    }

    FILE *f = fopen(filename, "a+");
    if (f != NULL)
    {
        int lastRecid = 0;
        rec temp;

        while (fscanf(f, "%d %d %d %d %s %s %s %s %s\n", &temp.recid, &temp.date.jour, &temp.date.mois, &temp.date.annee, temp.tel, temp.idpark, temp.avis, temp.desc, ch) != EOF)
        {
            if (temp.recid > lastRecid)
                lastRecid = temp.recid;
        }

        d.recid = lastRecid + 1; 
      
        fprintf(f, "%d %d %d %d %s %s %s %s %s\n", d.recid, d.date.jour, d.date.mois, d.date.annee, d.tel, d.idpark, d.avis, d.desc, ch);
        fclose(f);
        return 1;
    }
    else
        return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////

int modifier(char *filename, char tel[], int recid, rec nouv, char cha[], char ch[], int choix2[])
{
    strcpy(cha, "");
    if (choix2[0] == 1)
        strcat(cha, "/Problème_de_paiement/");
    if (choix2[1] == 1)
        strcat(cha, "/Problème_avec_le_service_client/");
    if (choix2[2] == 1)
        strcat(cha, "/Dommages_au_véhicule/");
    if (choix2[3] == 1)
        strcat(cha, "/Autre/");

    // Replace spaces in the new description with underscores
    for (int i = 0; nouv.desc[i] != '\0'; i++) {
        if (nouv.desc[i] == ' ') {
            nouv.desc[i] = '_';
        }
    }

    rec t;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%d %d %d %d %s %s %s %s %s\n",
                      &t.recid, &t.date.jour, &t.date.mois, &t.date.annee, 
                      t.tel, t.idpark, t.avis, t.desc, ch) != EOF)
        {
            if (recid == t.recid)
            {
                fprintf(f2, "%d %d %d %d %s %s %s %s %s\n", 
                        t.recid, nouv.date.jour, nouv.date.mois, 
                        nouv.date.annee, nouv.tel, nouv.idpark, 
                        nouv.avis, nouv.desc, cha);
                tr = 1; 
            }
            else
            {
                fprintf(f2, "%d %d %d %d %s %s %s %s %s\n", 
                        t.recid, t.date.jour, t.date.mois, 
                        t.date.annee, t.tel, t.idpark, 
                        t.avis, t.desc, ch);
            }
        }

        fclose(f);
        fclose(f2);
        remove(filename);
        rename("nouv.txt", filename);
        return tr;
    }
    else
    {
        
        if (f != NULL) fclose(f);
        if (f2 != NULL) fclose(f2);
        return -1; 
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////////

int supprimer(char * filename, char tel[], int recid,char ch[])
{
    int tr=0;
    rec d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %d %d %s %s %s %s %s\n",&d.recid, &d.date.jour, &d.date.mois, &d.date.annee, d.tel, d.idpark, d.avis , d.desc,ch)!=EOF)
        {
            if( recid==d.recid)
                tr=1;
            else
                fprintf(f2,"%d %d %d %d %s %s %s %s %s\n",d.recid,d.date.jour,d.date.mois,d.date.annee,d.tel ,d.idpark, d.avis , d.desc,ch);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////

rec chercher(char * filename, char tel[],int recid,char ch[])
{
    rec d;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {    
        while(tr==0&& fscanf(f,"%d %d %d %d %s %s %s %s %s\n",&d.recid, &d.date.jour, &d.date.mois, &d.date.annee, d.tel,d.idpark, d.avis , d.desc ,ch)!=EOF)
        {
            if(strcmp(d.tel,tel)==0 && recid == d.recid)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        strcpy(d.tel,"-1");
    return d;

}


