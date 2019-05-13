#include <stdlib.h>
#include <stdio.h>

#include "auteur.h"

int main (int argc, char *argv[]) {
    auteur_t* bidule ;
    bidule = auteur_new() ;

    auteur_show(bidule) ;
    
    printf("\n");

    auteur_set_nom (bidule, "Coucou");
    auteur_set_prenom(bidule, "Test");
    auteur_set_email(bidule, "mail@mail.com");

    printf("\n");

    auteur_show (bidule);

    printf("\n");
    char* test1;
    test1 = auteur_get_nom(bidule);
    printf("nom : %s\n", test1);

    char* test2;
    test2 = auteur_get_prenom(bidule);
    printf("prenom : %s\n", test2);

    char* test3;
    test3 = auteur_get_email(bidule);
    printf("email : %s\n", test3);

    auteur_del(bidule) ;
    return 0 ; 
}
