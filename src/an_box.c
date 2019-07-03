#include <stdio.h>
#include <stdlib.h>

#include "annotations.h" 

#define TAILLE 128

/////////////////////FONCTIONS DE BASE////////////////////////

box_t* box_new(){
    box_t* ob;

    ob = malloc ( sizeof (box_t) ) ; 
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

void box_del ( box_t* ob) {

    color_del ( ob->color ) ;
    auteur_del ( ob->auteur ) ;
    free ( ob->time_start ) ;  
    free ( ob->time_end ) ;  
    free ( ob->auteur ) ;
    free ( ob->description ) ;
    free ( ob ) ;
    
}


void box_show ( box_t* ob) {
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

void box_add_tag (box_t* ob, int tag ) { //TODO
} 

void box_remove_tag ( box_t* ob, int tag ) { //TODO
} 

void box_show_tag ( box_t* ob, int taf ) { //TODO
}

IL NAGE MON BEBOU

*/
////////////////////////TIME//////////////////////////////

// TIME START 
void box_set_time_start ( box_t* ob ) { 

    time_t temps;
    time(&temps);

    char* time_s;
    time_s = ctime(&temps) ;

    sprintf ( ob->time_start, "%s", time_s ) ;
}

char* box_get_time_start ( box_t* ob ) {
    return ob->time_start ;
}

//TIME END 

void box_set_time_end ( box_t* ob ) { 
    sprintf ( ob->time_end, "%s", ob->time_start ) ;
}

char* box_get_time_end ( box_t* ob ) {
    return ob->time_end ; 
}


////////////////////////DESCRIPTION///////////////////////

void box_set_description ( box_t* ob, char* descr ) {
    sprintf ( ob->description, "%s", descr ) ; 
}

char* box_get_description ( box_t* ob ) {
    return ob->description ; 
}

//////////////////////// POINTS //////////////////////////

void box_set_x_start ( box_t* ob, int x_s ) {
     ob->x_start = x_s ;
}

int box_get_x_start ( box_t* ob ) {
    return ob->x_start ;
}


void box_set_y_start ( box_t* ob, int y_s ) {
     ob->y_start = y_s ;
}

int box_get_y_start ( box_t* ob ) {
    return ob->y_start ;
}


void box_set_x_end ( box_t* ob, int x_e ) {
     ob->x_end = x_e ;
}

int box_get_x_end ( box_t* ob ) {
    return ob->x_end ;
}


void box_set_y_end ( box_t* ob, int y_e ) {
     ob->y_end = y_e ;
}

int box_get_y_end ( box_t* ob ) {
    return ob->y_end ;
}



