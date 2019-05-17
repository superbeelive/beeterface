#include <stdio.h>
#include <stdlib.h>
#include "color.h"

#define TAILLE 128

//General

color_t* color_new () {
    color_t* col ; 
    col = malloc(sizeof(color_t)) ;
    col->name = malloc(TAILLE) ;
   
    sprintf ( col->name, "Nom de la couleur" ) ;
    col->R = 1 ;
    col->G = 2 ; 
    col->B = 3 ; 

    return col ; 
}

void color_del ( color_t* col ) {
    free(col->name) ; 
    free(col) ;
}

void color_show ( color_t* col ) {
    printf("Couleur : %s R : %d G : %d B : %d \n ", col->name,
                                                    col->R,
                                                    col->G,
                                                    col->B ) ;
}

//Name 
void color_set_name (color_t* col, char* name ) {
    sprintf ( col->name, "%s", name ) ; 
}

char* color_get_name (color_t* col ) {
    return col->name ;
}

//R 
void color_set_R ( color_t* col, int R ) {
    col->R = R ; 
}

int color_get_R ( color_t* col ) {
    return col->R ;
}

//G
 
void color_set_G ( color_t* col, int G ) {
    col->G = G ; 
}

int color_get_G ( color_t* col ) {
    return col->G ;
}



//B 
void color_set_B ( color_t* col, int B ) {
    col->B = B ; 
}

int color_get_B ( color_t* col ) {
    return col->B ;
}

