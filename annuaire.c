#include "hachage.h"

void testRechercherNumero(struct annuaire *an) {
    const char *res = rechercher_numero(an, "Pierre");
    if (res == NULL) {
        printf("Erreur recherche numéro\n");
    }
    else if (!strcmp("0634",res)){
        printf("Recherche numéro test 1 ok\n");
    }
    res = rechercher_numero(an, "ExistePas");
    if (res != NULL) {
        printf("Erreur recherche numéro\n");
    } else {
        printf("Recherche numéro 2 test ok\n");
    }
}

void testSupprimer(struct annuaire *an) {
    supprimer(an, "Napo");
    if (nombreElements(an) != 22) {
        printf("Erreur suppression\n");
    } else {
        printf("Suppression ok\n");
    }
}

void testInsertionetRedimension(struct annuaire *an) {
    inserer(an, "Pierre", "0634");
    inserer(an, "Rac", "0634");
    inserer(an, "Napo", "0634");
    inserer(an, "Bulbi", "0635");
    inserer(an, "Annibal", "0635");
    inserer(an, "Cesar", "0635");
    inserer(an, "Temudjin", "0635");
    inserer(an, "Ogodei", "0634");
    inserer(an, "Kubilai", "0634");
    inserer(an, "Auguste", "0634");
    inserer(an, "Scipion", "0634");
    inserer(an, "Napoleon", "0635");
    inserer(an, "Alexandre", "0635");
    inserer(an, "Frederic", "0635");
    inserer(an, "Djebe", "0635");
    inserer(an, "Subotei", "0634");
    inserer(an, "Desaix", "0634");
    inserer(an, "Lannes", "0634");
    inserer(an, "Davout", "0634");
    inserer(an, "Murat", "0635");
    inserer(an, "Berthier", "0635");
    inserer(an, "Grouchy", "0635");
    inserer(an, "Kleber", "0635");
    nombreElements(an) == 23 ? printf("Insertion ok\n") : printf("Insertion erreur\n");
    an->taille == 40 ? printf("Redimension ok\n") : printf("Redimension erreur\n");
}

int main() {
    struct annuaire *an = creer();
    testInsertionetRedimension(an);
    testRechercherNumero(an);
    testSupprimer(an);
    liberer(an);
}

