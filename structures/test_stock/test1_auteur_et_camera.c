#include <stdlib.h>
#include <stdio.h>

#include "camera.h"
#include "auteur.h"

int main (int argc, char *argv[]) {

    //////TESTS AUTEURS /////
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

    ///TESTS CAMERA///
    
    camera_t* chose;
    chose = camera_new();

    camera_show(chose);
    
    camera_set_name(chose, "Poulpe");
    char* test2_1;
    test2_1 = camera_get_name(chose);
    printf("name : %s\n",test2_1);

    camera_set_model(chose,"camera du futur");
    char* test2_2;
    test2_2 = camera_get_model(chose);
    printf("model : %s\n",test2_2);

    camera_set_nserie(chose, "1232132");
    char* test2_3;
    test2_3 = camera_get_nserie(chose);
    printf("nserie : %s\n",test2_3);

    camera_set_type(chose, "USB");
    char* test2_4;
    test2_4 = camera_get_type(chose);
    printf("type : %s\n",test2_4);

    camera_set_description(chose, "C'est la première caméra posée");
    char* test2_5;
    test2_5 = camera_get_description(chose);
    printf("description : %s\n",test2_5);

    camera_del(chose);

    return 0 ; 
}
