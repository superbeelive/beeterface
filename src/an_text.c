#include <stdio.h>
#include <stdlib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE///////////////////////


text_t* text_new(){
    text_t* txt;

    txt = malloc ( sizeof (text_t) ) ; 
    txt->author = malloc ( TAILLE ) ; 
    txt->description = malloc ( TAILLE ) ;
    txt->comment = malloc ( TAILLE ) ; 
    txt->time_start = malloc ( TAILLE ) ; 
    txt->time_end = malloc ( TAILLE ) ;

    sprintf ( txt->time_end, "2:45" ) ;  
    sprintf ( txt->time_start, "0:45" );
    sprintf ( txt->description, "Ceci est une description" ) ;
    sprintf ( txt->comment, "Ceci est un commentaire" ) ;

    txt->color = color_new() ; 
    txt->author = author_new() ; 

    return txt;
}
void text_del ( text_t* txt) {
    
    color_del ( txt->color ) ;
    author_del ( txt->author ) ;
    free ( txt->time_start ) ;
    free ( txt->author ) ;
    free ( txt->description ) ;
    free ( txt->comment ) ;
    free ( txt ) ;
}

void text_show ( text_t* txt) {
    printf("Début : %s \nFin : %s \nDescription : %s\nCommentaire : %s", 
                                  txt->time_start,
                                  txt->time_end, 
                                  txt->description,
                                  txt->comment ) ; 

    color_show ( txt->color ) ;
    author_show ( txt->author ) ;

}

/////////////////////////TAGS/////////////////////////////
/*
void text_add_tag (text_t* txt, int tag ) { //TODO
} 

void text_remove_tag ( text_t* txt, int tag ) { //TODO
} 

void text_show_tag ( text_t* txt, int taf ) { //TODO
}


////////////////////////TIME//////////////////////////////
*/
void text_set_time_start ( text_t* txt ) { 

    time_t temps;
    time(&temps);

    char* time_s;
    time_s = ctime(&temps) ;

    sprintf ( txt->time_start, "%s", time_s ) ;
}

char* text_get_time_start ( text_t* txt ) {
    return txt->time_start ;
}

//TIME END 

void text_set_time_end ( text_t* txt ) { 
    sprintf ( txt->time_end, "%s", txt->time_start ) ;
}

char* text_get_time_end ( text_t* txt ) {
    return txt->time_end ; 
}

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



