#ifndef AUTEUR_H
#define AUTEUR_H

typedef struct {
    char* lastname;
    char* firstname;
    char* email;
} author_t ;

author_t* author_new() ;
void author_del (author_t*);
void author_show (author_t*);


void author_set_lastname( author_t* , char* lastname ) ;
char* author_get_lastname ( author_t* ) ;


void author_set_firstname( author_t* , char* firstname ) ;
char* author_get_firstname ( author_t* ) ;

void author_set_email( author_t* , char* email ) ;
char* author_get_email ( author_t* ) ;

#endif 
