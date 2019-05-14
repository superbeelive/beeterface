#include <stdio.h>

#include <stldib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE///////////////////////


measure_t* measure_new(){
    measure_t* mea;

    mea = malloc ( sizeof (measure_t) ) ; 
    mea->auteur = malloc ( sizeof (TAILLE) ) ; 
    mea->description = malloc ( sizeof (TAILLE) ) ;

    sprintf(mea->auteur, "OSP");
    sprintf(mea->color, "RGB");
    sprintf(mea->time_start "0:45");
    sprintf(mea->time_end "2:00");
    sprintf(mea->description "Ceci est une description");
    sprintf(mea->x_start "3");
    sprintf(mea->y_start "5");
    sprintf(mea->x_end "8");
    sprintf(mea->y_end "15");   

    return mea;
}

void measure_del ( measure_t* mea) {
    free ( mea->auteur ) ;
    free ( mea->description ) ;
    free ( mea ) ;

}


//Pas de visualisation des tags ici
void measure_show ( measure_t* mea) {
    printf("%s %s %s %s %s %s\n", mea->auteur,
                                  mea->color,
                                  mea->time_start,
                                  mea->time_end,
                                  mea->description,
                                  mea->x_start,
                                  mea->y_start, 
                                  mea->x_end, 
                                  mea->y_end);

}

/////////////////////////TAGS/////////////////////////////

void measure_add_tag (measure_t* mea, int tag ) { //TODO
} 

void measure_remove_tag ( measure_t* mea, int tag ) { //TODO
} 

void measure_show_tag ( measure_t* mea, int taf ) { //TODO
}


//////////////////////COLORS/////////////////////////////


void measure_set_color ( measure_t* mea, color_t* col ) { 
    sprintf(mea->color,"%s",col);
}

color_t measure_get_color ( measure_t* mea ) { 
    return mea->color ;
}

////////////////////////TIME//////////////////////////////

void measure_set_time_start ( measure_t* mea, timecode_t time_s ) {
    sprintf ( mea->time_start, "%s", time_s ) ;
}

timecode_t measure_get_time_start ( measure_t* mea ) {
    return mea->time_start ;
}

void measure_set_time_end ( measure_t* mea, timecode_t time_e ) {
    sprintf ( mea->time_end,"%s",time_e ) ; 

timecode_t measure_get_time_end ( measure_t* mea ) {
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
    sprintf ( mea->value, "%s", val ) ;
}

double measure_get_value ( measure_t* mea ) {
    return mea->value ;
}



