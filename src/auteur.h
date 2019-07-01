#ifndef AUTEUR_H
#define AUTEUR_H

typedef struct {
    char* nom;
    char* prenom;
    char* email;
} auteur_t ;

auteur_t* auteur_new() ;
void auteur_del (auteur_t*);
void auteur_show (auteur_t*);


void auteur_set_nom( auteur_t* , char* nom ) ;
char* auteur_get_nom ( auteur_t* ) ;


void auteur_set_prenom( auteur_t* , char* prenom ) ;
char* auteur_get_prenom ( auteur_t* ) ;

void auteur_set_email( auteur_t* , char* email ) ;
char* auteur_get_email ( auteur_t* ) ;

#endif 
