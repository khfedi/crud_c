#include <stdio.h>
#include "rec.h"
#include <string.h>
#include <stdlib.h>



int main() {
    char filename[] = "records.txt";
    rec d;
    int choix[4] = {1, 0, 0, 0};  // Example for "Problème de paiement" selected
    char ch[300];
    int success;

    // Initialize an example record
    d.date.jour = 5;
    d.date.mois = 11;
    d.date.annee = 2024;
    strcpy(d.tel, "12345678");
    strcpy(d.idpark, "P123");
    strcpy(d.avis, "A");
    strcpy(d.desc, "Example zfu oejeih zjfoiej eopfjeopfj ojfeofj ejoief");

    // Test the ajouter function
    success = ajouter(filename, d, choix, ch);
    if (success) {
        printf("Record added successfully \n.");
    } else {
        printf("Error adding record.\n");
    }

    // Modify the record with recid=1 (or whatever was just added)
    rec new_rec;
    new_rec.date.jour = 6;
    new_rec.date.mois = 11;
    new_rec.date.annee = 2024;
    strcpy(new_rec.tel, "87654321");
    strcpy(new_rec.idpark, "P321");
    strcpy(new_rec.avis, "B");
    strcpy(new_rec.desc, "Updated pojfoz eopjfej eofjf");

    int choix2[4] = {0, 1, 0, 0};  // Example for "Problème avec le service client"
    char cha[300];
    success = modifier(filename, d.tel, 2 , new_rec, cha, ch, choix2);
    if (success) {
        printf("Record modified successfully \n");
    } else {
        printf("Error modifying record.\n");
    }

    // Search for the modified record
    rec found_rec = chercher(filename, new_rec.tel, 2 , ch);
    if (strcmp(found_rec.tel, "-1") != 0) {
        printf("Record found\n");
    } else {
        printf("Record not found.\n");
    }

    // Test the supprimer function
    success = supprimer(filename, new_rec.tel, 7 , ch);
    if (success) {
        printf("Record deleted successfully.\n");
    } else {
        printf("Error deleting record.\n");
    }

    return 0;
}

