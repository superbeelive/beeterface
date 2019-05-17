#include <stdio.h>

#include <stdlib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE///////////////////////


text_t* text_new(){
    text_t* txt;

    txt = malloc ( sizeof (text_t) ) ; 
    txt->auteur = malloc ( TAILLE ) ; 
    txt->description = malloc ( TAILLE ) ;
    txt->comment = malloc ( TAILLE ) ; 

   /* sprintf(txt->auteur, "OSP");
    sprintf(txt->color, "RGB");
    sprintf(txt->time_start "0:45");
    sprintf(txt->time_end "2:00"); TODO */
    sprintf ( txt->description, "Ceci est une description" ) ;
    sprintf (txt->comment, "Ceci est un commentaire" ) ;

    return txt;
}

void text_del ( text_t* txt) {
    free ( txt->auteur ) ;
    free ( txt->description ) ;
    free ( txt->comment ) ;
    free ( txt ) ;
}


//Pas de visualisation des tags ici
void text_show ( text_t* txt) {
    printf("%s %s\n", /*txt->auteur,
                                  txt->color,
                                  txt->time_start,
                                  txt->time_end, */
                                  txt->description, 
                                  txt->comment);

}

/////////////////////////TAGS/////////////////////////////
/*
void text_add_tag (text_t* txt, int tag ) { //TODO
} 

void text_remove_tag ( text_t* txt, int tag ) { //TODO
} 

void text_show_tag ( text_t* txt, int taf ) { //TODO
}


//////////////////////COLORS/////////////////////////////
//TODO

void text_set_color ( text_t* txt, color_t* col ) { 
    sprintf(txt->color,"%s",col);
}

color_t text_get_color ( text_t* txt ) { 
    return txt->color ;
}

////////////////////////TIME//////////////////////////////
//TODO
void text_set_time_start ( text_t* txt, timecode_t time_s ) {
    sprintf ( txt->time_start, "%s", time_s ) ;
}

timecode_t text_get_time_start ( text_t* txt ) {
    return txt->time_start ;
}

void text_set_time_end ( text_t* txt, timecode_t time_e ) {
    sprintf ( txt->time_end,"%s",time_e ) ; 

timecode_t text_get_time_end ( text_t* txt ) {
    return txt->time_end ; 
}
*/
////////////////////////DESCRIPTION///////////////////////

void text_set_description ( text_t* txt, char* descr ) {
    sprintf ( txt->description, "%s", descr ) ; 
}

char* text_get_description ( text_t* txt ) {
    return txt->description ; 
}

//////////////////////// COMMENT //////////////////////////

void text_set_comment ( text_t* txt, char* com ) {
    sprintf ( txt->comment, "%s", com ) ;
}

char* text_get_comment ( text_t* txt ) {
    return txt->comment ;
}



