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

   // sprintf(ar->auteur, "OSP"); TODO : ajouter auteur 
   //  sprintf(ar->color, "RGB"); TODO : ajouter couleur 
   // sprintf(ar->time_start "0:45"); TODO
   //  sprintf(ar->time_end "2:00"); TODO
    sprintf ( ar->description, "Ceci est une description" ) ;
    ar->x = 3 ;
    ar->y = 5 ;
    ar->angle = 45 ; 
    return ar;
}

void arrow_del ( arrow_t* ar) {
    free ( ar->auteur ) ;
    free ( ar->description ) ;
    free ( ar ) ;

}


//Pas de visualisation des tags ici
void arrow_show ( arrow_t* ar) {
    printf("%s %d %d %d \n", //ar->auteur,
                                  //ar->color,
                                  //ar->time_start,
                                  //ar->time_end,
                                  ar->description,
                                  ar->x,
                                  ar->y, 
                                  ar->angle);

}

/////////////////////////TAGS/////////////////////////////
/*
void arrow_add_tag (arrow_t* ar, int tag ) { //TODO
} 

void arrow_remove_tag ( arrow_t* ar, int tag ) { //TODO
} 

void arrow_show_tag ( arrow_t* ar, int taf ) { //TODO
}


//////////////////////COLORS/////////////////////////////

//TODO 

void arrow_set_color ( arrow_t* ar, color_t* col ) { 
    sprintf(ar->color,"%s",col);
}

color_t arrow_get_color ( arrow_t* ar ) { 
    return ar->color ;
}

////////////////////////TIME//////////////////////////////
//TODO
void arrow_set_time_start ( arrow_t* ar, timecode_t time_s ) {
    sprintf ( ar->time_start, "%s", time_s ) ;
}

timecode_t arrow_get_time_start ( arrow_t* ar ) {
    return ar->time_start ;
}

void arrow_set_time_end ( arrow_t* ar, timecode_t time_e ) {
    sprintf ( ar->time_end,"%s",time_e ) ; 

timecode_t arrow_get_time_end ( arrow_t* ar ) {
    return ar->time_end ; 
}
*/
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
