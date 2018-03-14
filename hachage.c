#include "hachage.h"

#define TAILLE 10

struct annuaire *creer() {
    struct annuaire *annuaire = malloc(sizeof(struct annuaire));
    if (annuaire == NULL) {
        exit(EXIT_FAILURE);
    }
    annuaire->taille = TAILLE;
    annuaire->listes = malloc(annuaire->taille * sizeof(struct liste));
    if (annuaire->listes == NULL) {
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < annuaire->taille; i++) {
        annuaire->listes[i].taille = 0;
    }
    return annuaire;
}


void libererListe(struct liste *liste) {
    if (liste->taille == 0) {
        return;
    }
    struct cellule *parc = liste->tete;
    struct cellule *asup;
    while (parc != NULL) {
        asup = parc;
        parc = parc->suiv;
        free(asup);
    }
}

void liberer(struct annuaire *an) {
    for (size_t i = 0; i < an->taille; i++) {
        libererListe(&(an->listes[i]));
    }
    free(an->listes);
    free(an);
}


unsigned int hachage(const char *nom) {
    unsigned int hash = 5381;
    int i = 0;
    char c = nom[i];
    while (c != '\0') {
        hash = hash * 33 + c;
        i++;
        c = nom[i];
    }
    return hash;
}

struct cellule *creerCellule(const char *nom, const char *numero) {
    struct cellule *cellule = malloc(sizeof(struct cellule));
    if (cellule == NULL) {
        exit(EXIT_FAILURE);
    }
    cellule->nom = nom;
    cellule->numero = numero;
    cellule->suiv = NULL;
    return cellule;
}

const char *insererDansListe(struct liste *liste, struct cellule *cellule) {
    struct cellule *parc = liste->tete;
    const char *aRetourner = NULL;
    while (parc->suiv != NULL) {
        if (!strcmp(parc->nom, cellule->nom)) {
            aRetourner = parc->numero;
            parc->numero = cellule->numero;
            free(cellule);
            return aRetourner;
        }
        parc = parc->suiv;
    }
    cellule->suiv = liste->tete;
    liste->tete = cellule;
    liste->taille++;
    return aRetourner;
}


struct cellule *elementsAnnuaire(struct annuaire *an, int nbElement) {
    struct cellule *elements = malloc(nbElement * sizeof(struct cellule));
    int enCours = 0;
    for (size_t i = 0; i < an->taille; i++) {
        if (an->listes[i].taille == 0) {
            continue;
        }
        struct cellule *parc = an->listes[i].tete;
        for(size_t j=0; j<an->listes[i].taille;j++) {
            elements[enCours] = *parc;
            enCours++;
            parc = parc->suiv;
        }
    }
    return elements;
}

void redimensionner(struct annuaire *an, int agrandir, int nbElements) {
    if (agrandir == 0 && an->taille <= 10){
        return;
    }
    size_t nouvelleTaille = agrandir ? an->taille * 2 : an->taille / 2;
    struct liste *nouv = malloc(nouvelleTaille * sizeof(struct liste));
    if (nouv == NULL) {
        exit(EXIT_FAILURE);
    }
    struct cellule *elements = elementsAnnuaire(an, nbElements);
    for (size_t i = 0; i < an->taille; i++) {
        libererListe(&(an->listes[i]));
    }
    free(an->listes);
    an->listes = nouv;
    for (size_t i = 0; i < an->taille; i++) {
        an->listes[i].taille = 0;
    }
    an->taille = nouvelleTaille;
    for (int i = 0; i < nbElements; i++) {
        inserer(an, elements[i].nom, elements[i].numero);
    }
    free(elements);
}

const char *inserer(struct annuaire *an, const char *nom, const char *numero) {
    unsigned int hash = hachage(nom);
    size_t index = hash % (an->taille);
    const char *res;
    struct cellule *nouv = creerCellule(nom, numero);
    if (an->listes[index].taille == 0) {
        an->listes[index].tete = nouv;
        an->listes[index].taille++;
        return NULL;
    }
    res = insererDansListe(&(an->listes[index]), nouv);
    int nbElements = nombreElements(an);
    float nb = (float) nbElements;
    if (nb / an->taille * 100 > 75) {
        printf("Redimensionnage, %s\n", nom);
        afficher(an);
        redimensionner(an, 1, nbElements);
        afficher(an);
    }
    return res;

}

const char *rechercher_numero(struct annuaire *an, const char *nom) {
    size_t index = hachage(nom) % an->taille;
    struct cellule *parc = an->listes[index].tete;
    while (parc != NULL) {
        if (!strcmp(parc->nom, nom)) {
            return parc->numero;
        }
        parc = parc->suiv;
    }
    return NULL;
}

void supprimerDeListe(struct liste *liste, const char *nom) {
    if (liste->taille == 0) {
        return;
    }
    struct cellule *asup;
    if (!strcmp(liste->tete->nom, nom)) {
        asup = liste->tete;
        liste->tete = liste->tete->suiv;
        free(asup);
        liste->taille--;
        return;
    }
    struct cellule *parc = liste->tete;
    while (parc->suiv != NULL) {
        if (!strcmp(parc->suiv->nom, nom)) {
            asup = parc->suiv;
            parc->suiv = parc->suiv->suiv;
            free(asup);
            liste->taille--;
            break;
        }
        parc = parc->suiv;
    }

}

void supprimer(struct annuaire *an, const char *nom) {
    size_t index = hachage(nom) % an->taille;
    supprimerDeListe(&(an->listes[index]), nom);
    int nbElements = nombreElements(an);
    printf("LL:%d\n", nbElements);
    if (nbElements / an->taille * 100 < 15) {
        printf("Redimensionnage, %s\n", nom);
        redimensionner(an, 0, nbElements);
        afficher(an);
    }
}

void afficherCellule(struct cellule *cellule) {
    printf("%s | %s -->", cellule->nom, cellule->numero);
}

void afficherListe(struct liste liste, int i) {
    struct cellule *parc = liste.tete;
    for (size_t j = 0; j < liste.taille; j++) {
        printf("%d : ", i);
        afficherCellule(parc);
        parc = parc->suiv;
    }
    printf("   %lo", liste.taille);
    printf("\n");
}

void afficher(struct annuaire *an) {
    for (size_t i = 0; i < an->taille; i++) {
        afficherListe(an->listes[i], i);
    }
    printf("\n");
}

int nombreElements(struct annuaire *an) {
    int nb = 0;
    for (size_t i = 0; i < an->taille; i++) {
        nb += an->listes[i].taille;
    }
    return nb;
}