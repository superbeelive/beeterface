#include <stdio.h>
#include <stdlib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE///////////////////////
//

oblong_t* oblong_new(){
    oblong_t* ob;

    ob = malloc ( sizeof (oblong_t) ) ; 
    ob->auteur = malloc ( sizeof (TAILLE) ) ; 
    ob->description = malloc ( sizeof (TAILLE) ) ;

   /* sprintf(ob->auteur, "OSP");
    sprintf(ob->color, "RGB");
    sprintf(ob->time_start "0:45");
    sprintf(ob->time_end "2:00"); */
    sprintf(ob->description, "Ceci est une description");
    ob->x_start = 3 ;
    ob->y_start = 5 ;
    ob->x_end = 8 ;
    ob->y_end =15 ;   

    return ob;
}

void oblong_del ( oblong_t* ob) {
    free ( ob->auteur ) ;
    free ( ob->description ) ;
    free ( ob ) ;

}


//Pas de visualisation des tags ici
void oblong_show ( oblong_t* ob) {
    printf("%s %d %d %d %d\n", /*ob->auteur,
                                  ob->color,
                                  ob->time_start,
                                  ob->time_end, */
                                  ob->description,
                                  ob->x_start,
                                  ob->y_start, 
                                  ob->x_end, 
                                  ob->y_end);

}
/*
/////////////////////////TAGS/////////////////////////////

void oblong_add_tag (oblong_t* ob, int tag ) { //TODO
} 

void oblong_remove_tag ( oblong_t* ob, int tag ) { //TODO
} 

void oblong_show_tag ( oblong_t* ob, int taf ) { //TODO
}


//////////////////////COLORS/////////////////////////////

//TODO
void oblong_set_color ( oblong_t* ob, color_t* col ) { 
    sprintf(ob->color,"%s",col);
}

color_t oblong_get_color ( oblong_t* ob ) { 
    return ob->color ;
}

////////////////////////TIME//////////////////////////////
//TODO
void oblong_set_time_start ( oblong_t* ob, timecode_t time_s ) {
    sprintf ( ob->time_start, "%s", time_s ) ;
}

timecode_t oblong_get_time_start ( oblong_t* ob ) {
    return ob->time_start ;
}

void oblong_set_time_end ( oblong_t* ob, timecode_t time_e ) {
    sprintf ( ob->time_end,"%s",time_e ) ; 

timecode_t oblong_get_time_end ( oblong_t* ob ) {
    return ob->time_end ; 
}
*/
////////////////////////DESCRIPTION///////////////////////

void oblong_set_description ( oblong_t* ob, char* descr ) {
    sprintf ( ob->description, "%s", descr ) ; 
}

char* oblong_get_description ( oblong_t* ob ) {
    return ob->description ; 
}

//////////////////////// POINTS //////////////////////////

void oblong_set_x_start ( oblong_t* ob, int x_s ) {
     ob->x_start = x_s ;
}

int oblong_get_x_start ( oblong_t* ob ) {
    return ob->x_start ;
}


void oblong_set_y_start ( oblong_t* ob, int y_s ) {
     ob->y_start = y_s ;
}

int oblong_get_y_start ( oblong_t* ob ) {
    return ob->y_start ;
}


void oblong_set_x_end ( oblong_t* ob, int x_e ) {
     ob->x_end = x_e ;
}

int oblong_get_x_end ( oblong_t* ob ) {
    return ob->x_end ;
}


void oblong_set_y_end ( oblong_t* ob, int y_e ) {
     ob->y_end = y_e ;
}

int oblong_get_y_end ( oblong_t* ob ) {
    return ob->y_end ;
}



