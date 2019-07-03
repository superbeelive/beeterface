#ifndef PROJET_H
#define PROJET_H

#include "annotations.h"
#include "camera.h"
//#include "tag.h"
#include "video.h"
#include "auteur.h"

typedef struct {
   
    camera_t* camera ; 
    video_t* video ;
    
    oblong_t** oblong ; 	        // tableau
    int oblong_n ;              // Nombre d'objects stockés
    int oblong_size ;           // Tqille du tableau

    cross_t** cross ;
    int cross_n ;
    int cross_size ;


    arrow_t** arrow ;
    int arrow_n ;
    int arrow_size ;

    text_t** text ; 
    int text_n ;
    int text_size ;

    measure_t** measure ; 
    int measure_n ;
    int measure_size ;

    moving_cross_t** moving_cross ; 
    int moving_cross_n ;
    int moving_cross_size ;
    

} projet_t ; 

projet_t* projet_new() ; 
void projet_del (projet_t*) ; 
void projet_flush( projet_t*) ;

void projet_add_cross( projet_t*, cross_t*); 
#endif 
