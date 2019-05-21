#include <stdio.h>
#include <stdlib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE///////////////////////

arrow_t* arrow_new(){
    arrow_t* ar;

    ar = malloc ( sizeof (arrow_t) ) ; 
    ar->auteur = malloc ( TAILLE ) ; 
    ar->description = malloc ( TAILLE ) ;
    ar->time_start = malloc ( TAILLE ) ; 
    ar->time_end = malloc ( TAILLE ) ; 
    
    sprintf(ar->time_start, "0:45"); 
    sprintf(ar->time_end, "2:25"); 
    sprintf ( ar->description, "Ceci est une description" ) ;
    ar->x = 3 ;
    ar->y = 5 ;
    ar->angle = 45 ; 

    ar->color = color_new() ; 
    ar->auteur = auteur_new() ;

    return ar;
}

void arrow_del ( arrow_t* ar) {
    
    color_del ( ar->color ) ;
    auteur_del (ar->auteur ) ;
    free ( ar->time_start ) ;
    free ( ar->time_end ) ;
    free ( ar->auteur ) ;
    free ( ar->description ) ;
    free ( ar ) ;

}

void arrow_show ( arrow_t* ar) {
    printf("Début : %s \nFin : %s \nDescription : %s \nx départ : %d \ny départ : %d \n", 
                                  ar->time_start,
                                  ar->time_end, 
                                  ar->description,
                                  ar->x,
                                  ar->y ) ; 

    color_show ( ar->color ) ;
    auteur_show ( ar->auteur ) ;
}

/////////////////////////TAGS/////////////////////////////
/*
void arrow_add_tag (arrow_t* ar, int tag ) { //TODO
} 

void arrow_remove_tag ( arrow_t* ar, int tag ) { //TODO
} 

void arrow_show_tag ( arrow_t* ar, int taf ) { //TODO
}

////////////////////////TIME//////////////////////////////
*/
void arrow_set_time_start ( arrow_t* ar ) { 

    time_t temps;
    time(&temps);

    char* time_s;
    time_s = ctime(&temps) ;

    sprintf ( ar->time_start, "%s", time_s ) ;
}

char* arrow_get_time_start ( arrow_t* ar ) {
    return ar->time_start ;
}

///TIME END 

void arrow_set_time_end ( arrow_t* ar ) { 
    sprintf ( ar->time_end, "%s", ar->time_start ) ;
}

char* arrow_get_time_end ( arrow_t* ar ) {
    return ar->time_end ; 
}

////////////////////////DESCRIPTION///////////////////////

void arrow_set_description ( arrow_t* ar, char* desar ) {
    sprintf ( ar->description, "%s", desar ) ; 
}

char* arrow_get_description ( arrow_t* ar ) {
    return ar->description ; 
}

//////////////////////// POINTS //////////////////////////

void arrow_set_x ( arrow_t* ar, int x ) {
   ar->x = x ;
}

int arrow_get_x ( arrow_t* ar ) {
    return ar->x ;
}


void arrow_set_y ( arrow_t* ar, int y ) {
    ar->y = y ;
}

int arrow_get_y ( arrow_t* ar ) {
    return ar->y ;
}

//////////////////// ANGLE /////////////////////

void arrow_set_angle ( arrow_t* ar, int ang ) {
    ar->angle = ang ;
}

int arrow_get_angle ( arrow_t* ar ) {
    return ar->angle ; 
}
