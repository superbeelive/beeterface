#include <stdio.h> 
#include <stdlib.h> 

#include "auteur.h"

#define TAILLE 128


auteur_t* auteur_new() {
    
    auteur_t* toto ;
    toto = malloc ( sizeof(auteur_t) );
    toto->nom = malloc ( TAILLE ) ;
    toto->prenom = malloc ( TAILLE );
    toto->email = malloc ( TAILLE );
    sprintf(toto->nom, "Doe") ; 
    sprintf(toto->prenom, "John") ; 
    sprintf(toto->email, "lepape@vatican.org") ; 
    return toto;
}

void auteur_del ( auteur_t* auteur_a_dell ) {
    free (auteur_a_dell->nom) ; 
    free (auteur_a_dell->prenom) ; 
    free (auteur_a_dell->email) ; 
    free (auteur_a_dell) ; 
}

void auteur_show (auteur_t* auteur_affiche ) {

    printf("%s %s %s", auteur_affiche->nom, 
                       auteur_affiche->prenom,
                       auteur_affiche->email);
}

/////////////NOM///////////////
void auteur_set_nom ( auteur_t* auteur_a_set, char* nom) {
    sprintf(auteur_a_set->nom,"%s",nom); // Méthode pour éviter une fuite mémoire : je prend la chaine et la recopie dans le tableau déjà alloué
   // auteur_a_set->nom = nom; //Fuite mémoire : réécrase adresse mémoire donc Malloc du début perdu, pas grave mais à EVITER
}

char* auteur_get_nom (auteur_t* auteur_a_get) {
    return auteur_a_get->nom;
}

////////////PRENOM////////////////
void auteur_set_prenom (auteur_t* auteur_a_set, char* prenom) {
    sprintf(auteur_a_set->prenom,"%s",prenom);
}

char* auteur_get_prenom (auteur_t* auteur_a_get) {
    return auteur_a_get->prenom;
}

///////////EMAIL//////////////////
void auteur_set_email (auteur_t* auteur_a_set, char* email) {
    sprintf(auteur_a_set->email,"%s",email);
}

char* auteur_get_email (auteur_t* auteur_a_get) {
    return auteur_a_get->email;
}



