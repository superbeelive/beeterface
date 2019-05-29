#include <stdio.h> 
#include <stdlib.h>

#include "projet.h"

#define TAB_TAILLE 128


projet_t* projet_new() { 
    
    projet_t* ficus ;
    ficus = malloc ( sizeof(projet_t) ) ;
    ficus->auteur = auteur_new() ; 
    ficus->camera = camera_new() ; 
    ficus->video = video_new() ; 
    ficus->oblong = malloc ( TAB_TAILLE* sizeof(oblong_t) ) ; 
    ficus->cross = malloc ( TAB_TAILLE * sizeof(cross_t) ) ; 
    ficus->arrow = malloc ( TAB_TAILLE * sizeof(arrow_t) ) ; 
    ficus->text = malloc ( TAB_TAILLE * sizeof(text_t) ) ; 
    ficus->measure = malloc ( TAB_TAILLE * sizeof(measure_t) ) ; 
    ficus->moving_cross = malloc ( TAB_TAILLE* sizeof(moving_cross_t)) ; 
    
    return ficus ; 
}

void projet_del (projet_t* ficus ) {
    auteur_del ( ficus->auteur ) ; 
    camera_del ( ficus->camera ) ;
    video_del  ( ficus->video ) ; 
    free ( ficus->oblong ) ; 
    free ( ficus->cross ) ; 
    free ( ficus->arrow ) ; 
    free ( ficus->text ) ;
    free ( ficus->measure ) ; 
    free ( ficus->moving_cross ) ; 
    free ( ficus ) ; 
}


