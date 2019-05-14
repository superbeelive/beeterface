#include <stdio.h>

#include <stldib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE///////////////////////
//TODO

moving_cross_t* moving_cross_new(){
    moving_cross_t* cr;

    cr = malloc ( sizeof (moving_cross_t) ) ; 
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

void moving_cross_del ( moving_cross_t* cr) {
    free ( cr->auteur ) ;
    free ( cr->description ) ;
    free ( cr ) ;

}


//Pas de visualisation des tags ici
void moving_cross_show ( moving_cross_t* cr) {
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

void moving_cross_add_tag (moving_cross_t* cr, int tag ) { //TODO
} 

void moving_cross_remove_tag ( moving_cross_t* cr, int tag ) { //TODO
} 

void moving_cross_show_tag ( moving_cross_t* cr, int taf ) { //TODO
}


//////////////////////COLORS/////////////////////////////


void moving_cross_set_color ( moving_cross_t* cr, color_t* col ) { 
    sprintf(cr->color,"%s",col);
}

color_t moving_cross_get_color ( moving_cross_t* cr ) { 
    return cr->color ;
}

////////////////////////TIME//////////////////////////////

void moving_cross_set_time_start ( moving_cross_t* cr, timecode_t time_s ) {
    sprintf ( cr->time_start, "%s", time_s ) ;
}

timecode_t moving_cross_get_time_start ( moving_cross_t* cr ) {
    return cr->time_start ;
}

void moving_cross_set_time_end ( moving_cross_t* cr, timecode_t time_e ) {
    sprintf ( cr->time_end,"%s",time_e ) ; 

timecode_t moving_cross_get_time_end ( moving_cross_t* cr ) {
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

void moving_cross_set_x ( moving_cross_t* cr, int x ) {
    sprintf ( cr->x, "%s", x ) ;
}

int moving_cross_get_x ( moving_cross_t* cr, int x ) {
    return cr->x ;
}


void moving_cross_set_y ( moving_cross_t* cr, int y ) {
    sprintf ( cr->y, "%s", y ) ;
}

int moving_cross_get_y ( moving_cross_t* cr, int y ) {
    return cr->y ;
}

