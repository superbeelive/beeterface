#ifndef PROJET_H
#define PROJET_H

#include "annotations.h"
#include "camera.h"
//#include "tag.h"
#include "video.h"
#include "author.h"

typedef struct {
   
    camera_t* camera ; 
    video_t* video ;
    
    box_t** box ; 	    // tableau
    int box_n ;              // Nombre d'objects stockés
    int box_size ;           // Taille du tableau

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

void projet_add_box( projet_t*, box_t*); 
void projet_add_cross( projet_t*, cross_t*); 
void projet_add_arrow( projet_t*, arrow_t*);
void projet_add_text( projet_t*, text_t*);
void projet_add_measure( projet_t*, measure_t*);
void projet_add_moving_cross( projet_t*, moving_cross_t*);

void project_del_box( projet_t*, int ); 
void project_del_cross( projet_t* , int );
void project_del_arrow( projet_t* , int );
void project_del_text( projet_t* , int );
void project_del_measure( projet_t* , int );
void project_del_moving_cross( projet_t* , int );

#endif 
