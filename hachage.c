#include "hachage.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct annuaire *creer()
{
    struct annuaire* annuaire = malloc(sizeof(struct annuaire));
    annuaire->taille = 10;
    annuaire->listes = malloc(annuaire->taille * sizeof(struct liste));
    return annuaire;
}


void libererListe(struct liste liste){
    if (liste.tete == NULL){
        return;
    }
    struct cellule* parc= liste.tete;
    struct cellule* asup;
    while (parc->suiv != NULL){
        asup = parc;
        parc = parc->suiv;
        free(asup);
    }
}

void liberer(struct annuaire *an) {
    for (int i=0; i < an->taille; i++){
        libererListe(an->listes[i]);
    }
    free(an->listes);
    free(an);
}


unsigned int hachage (const char *nom){
    unsigned int hash = 5381;
    int i = 0;
    char c = nom[i];
    while (c != '\0'){
        hash = hash*33 + c;
        i++;
        c = nom[i];
    }
    return hash;
}

struct cellule* creerCellule(const char* nom,const char* numero){
    struct cellule* cellule = malloc(sizeof(struct cellule));
    cellule->nom = nom;
    cellule->numero = numero;
    cellule->suiv = NULL;
    return cellule;
}

const char* insererDansListe(struct liste* liste, struct cellule *cellule){
    if (liste->tete == NULL){
        liste->tete = cellule;
        return NULL;
    }
    struct cellule* parc = liste->tete;
    const char* aRetourner = NULL;
    while (parc->suiv != NULL){
        if (strcmp(parc->nom,cellule->nom)){
            aRetourner = parc->numero;
            parc->numero = cellule->numero;
        }
        parc = parc->suiv;
    }
    parc->suiv = cellule;
    return aRetourner;
}

const char *inserer(struct annuaire *an, const char *nom, const char *numero)
{
    unsigned int hash = hachage(nom);
    unsigned int index = hash % (an->taille);
    const char* res;
    struct cellule* nouv = creerCellule(nom, numero);
    res = insererDansListe(&(an->listes[index]), nouv);
    return res;

}


// const char *rechercher_numero(struct annuaire *an, const char *nom)
// {
// }


// void supprimer(struct annuaire *an, const char *nom)
// {
// }

void afficherCellule(struct cellule* cellule){
    printf("%s | %s -->",cellule->nom, cellule->numero);
}

void afficherListe(struct liste liste,int i){
    struct cellule* parc = liste.tete;
    while (parc != NULL){
        printf("%d : ",i);
        afficherCellule(parc);
        parc = parc->suiv;
    }
    printf("\n");
}

void afficher(struct annuaire *an){
    for (int i=0 ; i<an->taille; i++){
        afficherListe(an->listes[i],i);
    }
}

int main (void){
    struct annuaire* an = creer();
    inserer(an, "Pierre", "0634");
    inserer(an, "Rac", "0634");
    inserer(an, "Napo", "0634");
    inserer(an, "Napol", "0634");
    afficher(an);
    liberer(an);
}
