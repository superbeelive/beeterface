#ifndef VIDEO_H
#define VIDEO_H

#include <time.h>

#include "camera.h"
#include "annotations.h"
#include "auteur.h"

// Comment déclarer les annotations ici ? on les met toutes au cas où ?

typedef struct {

    char* name_ruche;
    int nruche;
    int ncadre;
    char* description;
    auteur_t* auteur;
    camera_t* camera;
    //Annotation ? TODO
    time_t* date;

} video_t ;


////FONCTIONS DE BASE////

video_t* video_new() ;
void video_del ( video_t* ) ;
void video_show ( video_t* ) ;

void video_set_name_ruche ( video_t*, char* ) ;
char* video_get_name_ruche ( video_t* ) ; 

void video_set_nruche ( video_t*, int ) ;
int video_get_nruch ( video_t* ) ;

void video_set_ncadre ( video_t*, int ) ;
int video_get_ncadre ( video_t* ) ;

void video_set_description ( video_t*, char* ) ;
char* video_get_description ( video_t* ) ;


//comment implémenter auteur et video dans leur création ? 
void video_set_auteur ( video_t*, auteur_t* ) ; //TODO 
auteur_t* video_get_auteur ( video_t* ) ;

void video_set_camera ( video_t*, camera_t* ) ; //TODO 
camera_t* video_get_camera ( video_t* ) ;

void video_set_date ( video_t*, time_t* ) ; //TODO 
time_t* vide_get_date ( video_t* ) ;

//proposition 
void video_set_date_auto ( video_t*, time_t* ) ;
