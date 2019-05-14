#include <stdio.h>

#include <stldib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE///////////////////////


arrow_t* arrow_new(){
    arrow_t* ar;

    ar = malloc ( sizeof (arrow_t) ) ; 
    ar->auteur = malloc ( sizeof (TAILLE) ) ; 
    ar->description = malloc ( sizeof (TAILLE) ) ;

    sprintf(ar->auteur, "OSP");
    sprintf(ar->color, "RGB");
    sprintf(ar->time_start "0:45");
    sprintf(ar->time_end "2:00");
    sprintf(ar->description "Ceci est une description");
    sprintf(ar->x_start "3");
    sprintf(ar->y_start "5");
    sprintf(ar->x_end "8");
    sprintf(ar->y_end "15");   

    return ar;
}

void arrow_del ( arrow_t* ar) {
    free ( ar->auteur ) ;
    free ( ar->description ) ;
    free ( ar ) ;

}


//Pas de visualisation des tags ici
void arrow_show ( arrow_t* ar) {
    printf("%s %s %s %s %s %s\n", ar->auteur,
                                  ar->color,
                                  ar->time_start,
                                  ar->time_end,
                                  ar->description,
                                  ar->x_start,
                                  ar->y_start, 
                                  ar->x_end, 
                                  ar->y_end);

}

/////////////////////////TAGS/////////////////////////////

void arrow_add_tag (arrow_t* ar, int tag ) { //TODO
} 

void arrow_remove_tag ( arrow_t* ar, int tag ) { //TODO
} 

void arrow_show_tag ( arrow_t* ar, int taf ) { //TODO
}


//////////////////////COLORS/////////////////////////////


void arrow_set_color ( arrow_t* ar, color_t* col ) { 
    sprintf(ar->color,"%s",col);
}

color_t arrow_get_color ( arrow_t* ar ) { 
    return ar->color ;
}

////////////////////////TIME//////////////////////////////

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

////////////////////////DESCRIPTION///////////////////////

void arrow_set_description ( arrow_t* ar, char* desar ) {
    sprintf ( ar->description, "%s", desar ) ; 
}

char* arrow_get_description ( arrow_t* ar ) {
    return ar->description ; 
}

//////////////////////// POINTS //////////////////////////

void arrow_set_x ( arrow_t* ar, int x ) {
    sprintf ( ar->x, "%s", x ) ;
}

int arrow_get_x ( arrow_t* ar, int x ) {
    return ar->x ;
}


void arrow_set_y ( arrow_t* ar, int y ) {
    sprintf ( ar->y, "%s", y ) ;
}

int arrow_get_y ( arrow_t* ar, int y ) {
    return ar->y ;
}

//////////////////// ANGLE /////////////////////

void arrow_set_angle ( arrow_t* ar, int ang ) {
    sprintf ( ar->angle, "%s", ang ) ;
}

int arrow_get_angle ( arrow_t* ar ) {
    return ar->angle ; 
}
