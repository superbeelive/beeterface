#include <stdio.h>
#include <stdlib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE///////////////////////


measure_t* measure_new(){
    measure_t* mea;

    mea = malloc ( sizeof (measure_t) ) ; 
    mea->description = malloc ( TAILLE ) ;
    mea->time_start = malloc ( TAILLE ) ; 
    mea->time_end = malloc ( TAILLE ) ; 

    sprintf(mea->time_start, "0:45");
    sprintf(mea->time_end, "2:00");
    sprintf(mea->description, "Ceci est une description");
    mea->value = 1 ;
    
    mea->color = color_new() ;
    mea->author = author_new() ;

    return mea;
}

void measure_del ( measure_t* mea) {

    color_del ( mea->color ) ;
    author_del ( mea->author ) ;
    free ( mea->time_start ) ;
    free ( mea->description ) ;
    free ( mea ) ;

}

void measure_show ( measure_t* mea) {
    printf("%s %s %f\n", mea->description,
                         mea->time_start,
                         mea->value ) ; 
    color_show ( mea->color ) ; 
    author_show ( mea->author ) ; 
}

/////////////////////////TAGS/////////////////////////////
/*
void measure_add_tag (measure_t* mea, int tag ) { //TODO
} 

void measure_remove_tag ( measure_t* mea, int tag ) { //TODO
} 

void measure_show_tag ( measure_t* mea, int taf ) { //TODO
}

*/

////////////////////////TIME//////////////////////////////
// TIME START 
void measure_set_time_start ( measure_t* mea ) { 

    time_t temps;
    time(&temps);

    char* time_s;
    time_s = ctime(&temps) ;

    sprintf ( mea->time_start, "%s", time_s ) ;
}

char* measure_get_time_start ( measure_t* mea ) {
    return mea->time_start ;
}

// TIME END 

void measure_set_time_end ( measure_t* mea ) { 
    sprintf ( mea->time_end, "%s", mea->time_start ) ;
}

char* measure_get_time_end ( measure_t* mea ) {
    return mea->time_end ; 
}

////////////////////////DESCRIPTION///////////////////////

void measure_set_description ( measure_t* mea, char* descr ) {
    sprintf ( mea->description, "%s", descr ) ; 
}

char* measure_get_description ( measure_t* mea ) {
    return mea->description ; 
}

//////////////////////// COMMENT //////////////////////////

void measure_set_value ( measure_t* mea, double val ) {
    mea->value = val ;
}

double measure_get_value ( measure_t* mea ) {
    return mea->value ;
}



