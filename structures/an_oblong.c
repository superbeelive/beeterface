#include <stdio.h>
#include <stdlib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE////////////////////////

oblong_t* oblong_new(){
    oblong_t* ob;

    ob = malloc ( sizeof (oblong_t) ) ; 
    ob->description = malloc ( TAILLE ) ;
    ob->time_start = malloc ( TAILLE ) ;
    ob->time_end = malloc ( TAILLE ) ;
   
    sprintf ( ob->time_start, "0:45" ) ;
    sprintf ( ob->time_end, "1:25" ) ; 
    sprintf(ob->description, "Ceci est une description");
    ob->x_start = 3 ;
    ob->y_start = 5 ;
    ob->x_end = 8 ;
    ob->y_end =15 ;   
    
    ob->color = color_new() ;
    ob->auteur = auteur_new() ;

    return ob;
}

void oblong_del ( oblong_t* ob) {

    color_del ( ob->color ) ;
    auteur_del ( ob->auteur ) ;
    free ( ob->time_start ) ;  
    free ( ob->time_end ) ;  
    free ( ob->auteur ) ;
    free ( ob->description ) ;
    free ( ob ) ;
    
}


void oblong_show ( oblong_t* ob) {
    printf("Début : %s \nFin : %s \nDescription : %s \nx départ : %d \ny départ : %d \nx fin %d \ny fin %d \n", 
                                  ob->time_start,
                                  ob->time_end, 
                                  ob->description,
                                  ob->x_start,
                                  ob->y_start, 
                                  ob->x_end, 
                                  ob->y_end);

    color_show ( ob->color ) ;
    auteur_show ( ob->auteur ) ;
}

/*
/////////////////////////TAGS/////////////////////////////

void oblong_add_tag (oblong_t* ob, int tag ) { //TODO
} 

void oblong_remove_tag ( oblong_t* ob, int tag ) { //TODO
} 

void oblong_show_tag ( oblong_t* ob, int taf ) { //TODO
}

IL NAGE MON BEBOU

*/
////////////////////////TIME//////////////////////////////

// TIME START 
void oblong_set_time_start ( oblong_t* ob ) { 

    time_t temps;
    time(&temps);

    char* time_s;
    time_s = ctime(&temps) ;

    sprintf ( ob->time_start, "%s", time_s ) ;
}

char* oblong_get_time_start ( oblong_t* ob ) {
    return ob->time_start ;
}

//TIME END 

void oblong_set_time_end ( oblong_t* ob ) { 
    sprintf ( ob->time_end, "%s", ob->time_start ) ;
}

char* oblong_get_time_end ( oblong_t* ob ) {
    return ob->time_end ; 
}


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



