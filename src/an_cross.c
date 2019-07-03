#include <stdio.h>
#include <stdlib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE///////////////////////


cross_t* cross_new(){
    cross_t* cr;

    cr = malloc ( sizeof (cross_t) ) ; 
    cr->author = malloc ( TAILLE ) ; 
    cr->description = malloc ( TAILLE ) ;
    cr->time_start = malloc ( TAILLE ) ;
    cr->time_end = malloc ( TAILLE ) ;

    sprintf ( cr->time_start, "0:45" ) ;
    sprintf ( cr->time_end, "2:00" ) ;
    sprintf ( cr->description, "Ceci est une description" ) ;
    cr->x = 3 ;
    cr->y = 5 ;

    cr->color = color_new() ; 
    cr->author = author_new() ; 

    return cr;
}

void cross_del ( cross_t* cr) {

    color_del ( cr->color ) ; 
    author_del ( cr->author ) ; 
    free ( cr->time_start ) ;
    free ( cr->time_end ) ;
    free ( cr->author ) ;
    free ( cr->description ) ;
    free ( cr ) ;

}

//Pas de visualisation des tags ici
void cross_show ( cross_t* cr) {
    printf("Début : %s \nFin : %s \nDescription : %s \nx : %d \ny : %d\n", 
                                  cr->time_start,
                                  cr->time_end, 
                                  cr->description,
                                  cr->x,
                                  cr->y ) ; 
                                    
                                  
    color_show ( cr->color ) ;
    author_show ( cr->author ) ; 

}
/*
/////////////////////////TAGS/////////////////////////////

void cross_add_tag (cross_t* cr, int tag ) { //TODO
} 

void cross_remove_tag ( cross_t* cr, int tag ) { //TODO
} 

void cross_show_tag ( cross_t* cr, int taf ) { //TODO
}

*/
////////////////////////TIME//////////////////////////////

void cross_set_time_start ( cross_t* cr ) { 
    time_t temps;
    time(&temps);

    char* time_s;
    time_s = ctime(&temps) ;

    sprintf ( cr->time_start, "%s", time_s ) ;
}

char* cross_get_time_start ( cross_t* cr ) {
    return cr->time_start ;
}

//TIME END 

void cross_set_time_end ( cross_t* cr ) { 
    sprintf ( cr->time_end, "%s", cr->time_start ) ;
}

char* cross_get_time_end ( cross_t* cr ) {
    return cr->time_end ; 
}

////////////////////////DESCRIPTION///////////////////////

void cross_set_description ( cross_t* cr, char* descr ) {
    sprintf ( cr->description, "%s", descr ) ; 
}

char* cross_get_description ( cross_t* cr ) {
    return cr->description ; 
}

//////////////////////// POINTS //////////////////////////

void cross_set_x ( cross_t* cr, int x ) {
    cr->x = x ;
}

int cross_get_x ( cross_t* cr ) {
    return cr->x ;
}


void cross_set_y ( cross_t* cr, int y ) {
    cr->y = y ;
}

int cross_get_y ( cross_t* cr ) {
    return cr->y ;
}

