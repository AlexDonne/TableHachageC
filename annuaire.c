#include "hachage.c"

void testInserer(struct annuaire *an){
    printf("Test Insertion \n");
    inserer(an, "Pierre", "0634");
    inserer(an, "Rac", "0634");
    inserer(an, "Napo", "0634");
    inserer(an, "Napol", "0634");
    inserer(an, "Napol", "0635");
    inserer(an, "Raul", "0635");
    inserer(an, "JP", "0635");
    inserer(an, "Alex", "0635");
    if (nombreElements(an) != 7){
        printf("Erreur insertion\n");
        exit(EXIT_FAILURE);
    }
    afficher(an);
}

void testRechercherNumero(struct annuaire *an){
    printf("Test Recherche Numéro \n");
    const char* res = rechercher_numero(an,"a");
    if (res != NULL){
        printf("Erreur recherche numéro\n");
        exit(EXIT_FAILURE);
    }
    res = rechercher_numero(an,"Napol");
    if (strcmp(res,"0635")){
        printf("Erreur recherche numéro\n");
        exit(EXIT_FAILURE);
    }
}

void testSupprimer(struct annuaire *an){
    printf("Test suppression de Napo");
    afficher(an);
    supprimer(an, "Napo");
    afficher(an);
    if (nombreElements(an) != 6){
        printf("Erreur suppression\n");
        exit(EXIT_FAILURE);
    }
}

void testRedimension(struct annuaire *an){
    inserer(an, "Pierre", "0634");
    inserer(an, "Rac", "0634");
    inserer(an, "Napo", "0634");
    inserer(an, "Napol", "0634");
    inserer(an, "Napol", "0635");
    inserer(an, "Raul", "0635");
    inserer(an, "JP", "0635");
    inserer(an, "Alex", "0635");
    inserer(an, "JJ", "0634");
    inserer(an, "Jean", "0634");
    inserer(an, "La", "0634");
    inserer(an, "Pika", "0634");
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
    inserer(an, "Klebr", "0635");

}

int main()
{
    struct annuaire* an = creer();
    testRedimension(an);
//    testInserer(an);
//    testRechercherNumero(an);
//    afficher(an);
//    testSupprimer(an);
//    liberer(an);
}

