#include <stdio.h> 
#include <stdlib.h>

#include "projet.h"

projet_t* projet_new() { 
    
    projet_t* ficus ;
    ficus = malloc ( sizeof(projet_t) ) ;
    ficus->auteur = malloc ( sizeof(auteur_t) ) ; 
    ficus->camera = malloc ( sizeof(camera_t) ) ; 
    ficus->video = malloc ( sizeof(video_t) ) ; 
    ficus->oblong = malloc ( sizeof(oblong_t) ) ; 
    ficus->cross = malloc ( sizeof(cross_t) ) ; 
    ficus->arrow = malloc ( sizeof(arrow_t) ) ; 
    ficus->text = malloc ( sizeof(text_t) ) ; 
    ficus->measure = malloc ( sizeof(measure_t) ) ; 
    ficus->moving_cross = malloc (sizeof(moving_cross_t)) ; 
    
    return ficus ; 
}

void project_del (projet_t* ficus ) {
    free ( ficus->auteur ) ; 
    free ( ficus->camera ) ;
    free ( ficus->video ) ; 
    free ( ficus->oblong ) ; 
    free ( ficus->cross ) ; 
    free ( ficus->arrow ) ; 
    free ( ficus->text ) ;
    free ( ficus->measure ) ; 
    free ( ficus->moving_cross ) ; 
    free ( ficus ) ; 
}


