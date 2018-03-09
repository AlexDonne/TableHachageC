#ifndef _HACHAGE_
#define _HACHAGE_

#include <stdint.h>

struct cellule{
    char* nom;
    char* numero;
    struct cellule* suiv;
}

struct liste{
    struct cellule* tete;
}

struct annuaire{
    struct liste* listes;
    int taillelogique;
    int taillephysique;
}

// Cree un nouvel annuaire, initialement vide
struct annuaire *creer();

// Libere tous les couples <nom, numero> d'un annuaire, et l'annaire lui-meme
void liberer(struct annuaire *an);

/*
 * Associe un numero a un nom.
 * Si l'annuaire contenait deja une entree de cle nom, alors la valeur associee
 * est remplacee par le parametre numero, et l'ancienne valeur est retournee
 * (attention, chaine a liberer!)
 * Sinon le couple <nom, numero> est ajoute et la fonction retourne NULL;
 * Requiert: an adresse valide d'un annuaire deja existant
 *           nom et numero chaines non nulles
 */
const char *inserer(struct annuaire *an, const char *nom, const char *numero);

/*
 * Retourne le numero associe a la cle nom, dans le parametre res.
 * Si la cle nom est presente, alors le numero associe est place dans res,
 * sinon res contient la chaine "ABSENT"
 * Requiert: an adresse valide d'un annuaire deja existant
 *           nom chaine non nulle
 *           res espace memoire alloue de taille taille_max_res
 */
//void rechercher_numero(struct annuaire *an, char *nom, char *res, uint32_t taille_max_res);


/*
 * Retourne une copie du numero associe a la cle nom, ou NULL si
 * la cle est absente.
 * Attention, cette fonction doit allouer de la memoire pour la chaine
 * renvoyee.
 * Requiert: an adresse valide d'un annuaire deja existant
 *           nom chaine non nulle
 */
const char *rechercher_numero(struct annuaire *an, const char *nom);


/*
 * Supprime l'entree de cle nom si elle presente, sans effet sinon */
void supprimer(struct annuaire *an, const char *nom);



// debug
void afficher(struct annuaire *an);


#endif
