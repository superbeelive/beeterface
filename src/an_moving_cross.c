#include <stdio.h>
#include <stdlib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE///////////////////////
//TODO

moving_cross_t* moving_cross_new(){
    moving_cross_t* cr;

    cr = malloc ( sizeof (moving_cross_t) ) ; 
    cr->description = malloc ( TAILLE ) ;
    cr->time_start = malloc ( TAILLE ) ; 
    cr->time_end = malloc ( TAILLE ) ;

    
    sprintf(cr->time_start, "0:45");
    sprintf(cr->time_end, "2:00"); 
    sprintf(cr->description, "Ceci est une description");

    cr->color = color_new() ; 
    cr->author = author_new() ; 

    return cr;
}

void moving_cross_del ( moving_cross_t* cr) {
    
    color_del ( cr->color ) ;
    author_del ( cr->author ) ; 
    free ( cr->time_start ) ;
    free ( cr->time_end ) ; 
    free ( cr->author ) ;
    free ( cr->description ) ;
    free ( cr ) ;

}


void moving_cross_show ( moving_cross_t* cr) {
    printf("%s %s %s\n",cr->time_end,
                        cr->time_start,
                        cr->description ) ;
    
    color_show ( cr->color ) ; 
    author_show ( cr->author ) ;
}
/*
/////////////////////////TAGS/////////////////////////////

void moving_cross_add_tag (moving_cross_t* cr, int tag ) { //TODO
} 

void moving_cross_remove_tag ( moving_cross_t* cr, int tag ) { //TODO
} 

void moving_cross_show_tag ( moving_cross_t* cr, int taf ) { //TODO
}

////////////////////////TIME//////////////////////////////
*/

void moving_cross_set_time_start ( moving_cross_t* cr ) { 

    time_t temps;
    time(&temps);

    char* time_s;
    time_s = ctime(&temps) ;

    sprintf ( cr->time_start, "%s", time_s ) ;
}

char* moving_cross_get_time_start ( moving_cross_t* cr ) {
    return cr->time_start ;
}

//TIME END 

void moving_cross_set_time_end ( moving_cross_t* cr ) { 
    sprintf ( cr->time_end, "%s", cr->time_start ) ;
}

char* moving_cross_get_time_end ( moving_cross_t* cr ) {
    return cr->time_end ; 
}

////////////////////////DESCRIPTION///////////////////////

void moving_cross_set_description ( moving_cross_t* cr, char* descr ) {
    sprintf ( cr->description, "%s", descr ) ; 
}

char* moving_cross_get_description ( moving_cross_t* cr ) {
    return cr->description ; 
}

//////////////////////// POINTS //////////////////////////
