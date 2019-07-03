#include <stdio.h> 
#include <stdlib.h>

#include "projet.h"
#include "utils.h"

#define TAB_SIZE 128


projet_t* projet_new() { 
    
    projet_t* ficus ;
    ficus = malloc ( sizeof(projet_t) ) ;
    ficus->camera = NULL ; 
    ficus->video = NULL ; 
    
    ficus->oblong = malloc ( TAB_SIZE* sizeof(oblong_t*) ) ;
    if ( ficus->oblong == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    ficus->oblong_size = TAB_SIZE ;
    ficus->oblong_n = 0 ;

    ficus->cross = malloc ( TAB_SIZE* sizeof(cross_t*) ) ;
    if ( ficus->cross == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    ficus->cross_size = TAB_SIZE ;
    ficus->cross_n = 0 ;
    
    ficus->arrow = malloc ( TAB_SIZE* sizeof(arrow_t*) ) ;
    if ( ficus->arrow == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    ficus->arrow_size = TAB_SIZE ;
    ficus->arrow_n = 0 ;

    ficus->text = malloc ( TAB_SIZE* sizeof(text_t*) ) ;
    if ( ficus->text == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    ficus->text_size = TAB_SIZE ;
    ficus->text_n = 0 ;

    ficus->measure = malloc ( TAB_SIZE* sizeof(measure_t*) ) ;
    if ( ficus->measure == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    ficus->measure_size = TAB_SIZE ;
    ficus->measure_n = 0 ;

    ficus->moving_cross = malloc ( TAB_SIZE* sizeof(moving_cross_t*) ) ;
    if ( ficus->moving_cross == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    ficus->moving_cross_size = TAB_SIZE ;
    ficus->moving_cross_n = 0 ;

    return ficus ; 
}

void projet_del (projet_t* ficus ) {
    projet_flush(ficus) ;
    free ( ficus->oblong ) ; 
    free ( ficus->cross ) ; 
    free ( ficus->arrow ) ; 
    free ( ficus->text ) ;
    free ( ficus->measure ) ; 
    free ( ficus->moving_cross ) ; 
    free ( ficus ) ; 
}

void projet_flush( projet_t* ficus) {
    int i ;
    
    if (ficus->camera != NULL ) 
        camera_del ( ficus->camera ) ;

    if (ficus->video != NULL ) 
        video_del  ( ficus->video ) ; 

    for (i=0; i<ficus->oblong_n; i++)
        free(ficus->oblong[i]) ;

    for (i=0; i<ficus->cross_n; i++)
        free(ficus->cross[i]) ;

    for (i=0; i<ficus->arrow_n; i++)
        free(ficus->arrow[i]) ;
    
    for (i=0; i<ficus->text_n; i++)
        free(ficus->text[i]) ;
    
    for (i=0; i<ficus->measure_n; i++)
        free(ficus->measure[i]) ;
    
    for (i=0; i<ficus->moving_cross_n; i++)
        free(ficus->moving_cross[i]) ;

    ficus->oblong_n = 0 ;
    ficus->cross_n = 0 ;
    ficus->arrow_n = 0 ;
    ficus->text_n = 0 ;
    ficus->measure_n = 0 ;
    ficus->moving_cross_n = 0 ;

    ficus->camera = NULL ;
    ficus->video = NULL ;

}

void projet_add_cross( projet_t* projet, cross_t* cross ) {
    if (projet->cross_n == projet->cross_size ) {
        projet->cross = reallocarray( projet->cross, projet->cross_size+TAB_SIZE, sizeof(cross_t*) ) ;
        projet->cross_size += TAB_SIZE ;
    }
    projet->cross[projet->cross_n] = cross ;
    projet->cross_n +=1 ;
}
