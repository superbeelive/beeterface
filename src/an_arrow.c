#include <stdio.h>
#include <stdlib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE///////////////////////
/* Struct: arrow_t
Arrow annotation is an arrow whose direction is given by the value of an angle. 

Fields:
    tag[TAILLE] - tag list 
    tag_size - tag number 

    author - Author of the annotation. See the struct author_t.
    color - Color used on the annotation. See the struct color_t.
    time_start - Timecode where annotation begin.
    time_end - Timecode where annotation finish.
    description - Description about the annotation made by the user
    
    x - Value of x where the arrow is located. 
    y - Value of y where the arrow is located.
    angle - Value of the angle in degrees 
*/


/*Function : arrow_new 
Create an arrow annotation and returns it with default values
*/
arrow_t* arrow_new(){
    arrow_t* ar;

    ar = malloc ( sizeof (arrow_t) ) ; 
    ar->author = malloc ( TAILLE ) ; 
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
    ar->author = author_new() ;

    return ar;
}

/*Function : arrow_del 
Delete properly an arrow annotation. 
 
Parameters : 
    ar - The arrow to be delete
*/

void arrow_del ( arrow_t* ar) {
    
    color_del ( ar->color ) ;
    author_del (ar->author ) ;
    free ( ar->time_start ) ;
    free ( ar->time_end ) ;
    free ( ar->author ) ;
    free ( ar->description ) ;
    free ( ar ) ;

}

/*Function : arrow_show
*/
void arrow_show ( arrow_t* ar) {
    printf("Début : %s \nFin : %s \nDescription : %s \nx départ : %d \ny départ : %d \n", 
                                  ar->time_start,
                                  ar->time_end, 
                                  ar->description,
                                  ar->x,
                                  ar->y ) ; 

    color_show ( ar->color ) ;
    author_show ( ar->author ) ;
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
