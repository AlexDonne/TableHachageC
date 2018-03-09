#include "hashage.h"
#include <string.h>

struct annuaire *creer()
{
    struct annuaire* annuaire = malloc(sizeof(struct annuaire));
    annuaire->taillephysique = 0;
    annuaire->taillelogique = 0;
    return annuaire;
}


void liberer(struct annuaire *an) {

}

unsigned int hachage (const char *nom){
    unsigned int hash = 5381;
    int i = 0;
    char c = nom[i];
    while (c != "\0"){
        hash = hash*33 + c;
        i++;
        c = nom[i];
    }
    return hash;
}

struct liste* creerListe(){
    struct liste* liste = malloc(sizeof(struct liste));
    return liste;
}

struct cellule* creerCellule(const char* nom,const char* numero){
    struct cellule* cellule = malloc(sizeof(struct cellule));
    cellule->nom = nom;
    cellule->numero = numero;
    cellule->suiv = NULL;
    return cellule;
}

char* insererDansListe(struct liste* liste, struct cellule *cellule){
    struct cellule parc = liste->tete;
    aRetourner = NULL;
    while (parc->suiv != NULL){
        if (strcmp(parc->nom,cellule->nom){
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
    unsigned int index = hash % (an->m + 1);
    char* res;
    struct cellule* nouv = creerCellule(nom, numero);
    if (an->listes[index] == NULL){
        listes[index] = creerListe();
        (listes[index])->tete = nouv;
    }
    else {
        res = insererDansListe(an->listes[index], nouv);
        return res;
    }

}


const char *rechercher_numero(struct annuaire *an, const char *nom)
{
}


void supprimer(struct annuaire *an, const char *nom)
{
}
