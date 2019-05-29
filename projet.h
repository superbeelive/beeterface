#ifndef PROJET_H
#define PROJET_H

#include "structures/annotations.h"
#include "structures/camera.h"
//#include "structures/tag.h"
#include "structures/video.h"
#include "structures/auteur.h"

typedef struct {
    
    auteur_t* auteur ; 
    camera_t* camera ; 
    video_t* video ;
    oblong_t* oblong ; 
    cross_t* cross ; 
    arrow_t* arrow ; 
    text_t* text ; 
    measure_t* measure ; 
    moving_cross_t* moving_cross ; 
    

} projet_t ; 

projet_t* projet_new() ; 
void projet_del (projet_t*) ; 

#endif 
