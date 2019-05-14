#include <stdio.h>

#include <stldib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE///////////////////////


cross_t* cross_new(){
    cross_t* cr;

    cr = malloc ( sizeof (cross_t) ) ; 
    cr->auteur = malloc ( sizeof (TAILLE) ) ; 
    cr->description = malloc ( sizeof (TAILLE) ) ;

    sprintf(cr->auteur, "OSP");
    sprintf(cr->color, "RGB");
    sprintf(cr->time_start "0:45");
    sprintf(cr->time_end "2:00");
    sprintf(cr->description "Ceci est une description");
    sprintf(cr->x_start "3");
    sprintf(cr->y_start "5");
    sprintf(cr->x_end "8");
    sprintf(cr->y_end "15");   

    return cr;
}

void cross_del ( cross_t* cr) {
    free ( cr->auteur ) ;
    free ( cr->description ) ;
    free ( cr ) ;

}


//Pas de visualisation des tags ici
void cross_show ( cross_t* cr) {
    printf("%s %s %s %s %s %s\n", cr->auteur,
                                  cr->color,
                                  cr->time_start,
                                  cr->time_end,
                                  cr->description,
                                  cr->x_start,
                                  cr->y_start, 
                                  cr->x_end, 
                                  cr->y_end);

}

/////////////////////////TAGS/////////////////////////////

void cross_add_tag (cross_t* cr, int tag ) { //TODO
} 

void cross_remove_tag ( cross_t* cr, int tag ) { //TODO
} 

void cross_show_tag ( cross_t* cr, int taf ) { //TODO
}


//////////////////////COLORS/////////////////////////////


void cross_set_color ( cross_t* cr, color_t* col ) { 
    sprintf(cr->color,"%s",col);
}

color_t cross_get_color ( cross_t* cr ) { 
    return cr->color ;
}

////////////////////////TIME//////////////////////////////

void cross_set_time_start ( cross_t* cr, timecode_t time_s ) {
    sprintf ( cr->time_start, "%s", time_s ) ;
}

timecode_t cross_get_time_start ( cross_t* cr ) {
    return cr->time_start ;
}

void cross_set_time_end ( cross_t* cr, timecode_t time_e ) {
    sprintf ( cr->time_end,"%s",time_e ) ; 

timecode_t cross_get_time_end ( cross_t* cr ) {
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
    sprintf ( cr->x, "%s", x ) ;
}

int cross_get_x ( cross_t* cr, int x ) {
    return cr->x ;
}


void cross_set_y ( cross_t* cr, int y ) {
    sprintf ( cr->y, "%s", y ) ;
}

int cross_get_y ( cross_t* cr, int y ) {
    return cr->y ;
}

