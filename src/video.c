#include <stdio.h> 
#include <stdlib.h> 

#include "video.h" 

#define TAILLE 128

video_t* video_new() {

    video_t* vid ; 
    vid = malloc ( sizeof( video_t ) ) ;
    vid->name_ruche = malloc ( TAILLE ) ;
    vid->description = malloc ( TAILLE ) ;
    vid->date = malloc ( TAILLE ) ; 
    vid->auteur = author_new(); 
    vid->camera = camera_new();


    sprintf ( vid->name_ruche, "Nom_de_la_ruche" ) ;
    vid->nruche = 0 ;
    vid->ncadre = 0 ;
    sprintf ( vid->description, "Description_de_la_video" ) ;
    sprintf ( vid->date, "Ceci est une date tout à fait pas bugguée" ) ; 
    
    return vid ;
}

void video_del ( video_t* vid ) {
    
    free ( vid->name_ruche ) ;
    free ( vid->description ) ;
    author_del(vid->auteur) ;
    camera_del(vid->camera) ;

    free( vid ) ;
}

void video_show ( video_t* vid ) {
    printf("%s %d %d %s", vid->name_ruche,
                        vid->nruche,
                        vid->ncadre,
                        vid->description);

    author_show(vid->auteur);
    camera_show(vid->camera);
}

/////// Name ruche //////

void video_set_name_ruche ( video_t* vid, char* nr) {
    sprintf ( vid->name_ruche, "%s", nr) ; 
}

char* video_get_name_ruche ( video_t* vid ) {
    return vid->name_ruche ;
}

/////// Numéro ruche //////

void video_set_nruche ( video_t* vid, int num ) {
    vid->nruche = num ;
}

int video_get_nruche ( video_t* vid ) {
    return vid->nruche ;
}


/////// Numéro cadre ///////

void video_set_ncadre ( video_t* vid, int num ) {
    vid->ncadre = num ;
}

int video_get_ncadre ( video_t* vid ) { 
    return vid->ncadre ;
}

/////// Description //////

void video_set_description ( video_t* vid, char* desc ) {
    sprintf ( vid->description, "%s", desc ) ;
}

char* video_get_description ( video_t* vid ) {
    return vid->description ;
}

///////// Time /////

void video_set_date ( video_t* vid ) { 
    time_t temps ;
    time (&temps) ; 
    
    char* time_s ; 
    time_s = ctime (&temps) ; 

    sprintf (vid->date, "%s", time_s ) ; 
}

////// Nom de la video /////

void video_set_name ( video_t* vid, author_t* aut, camera_t* cam ) {
    
    char* tmp_aut ;
    char* tmp_cam ; 
    tmp_aut = author_get_lastname ( aut ) ; 
    tmp_cam = camera_get_name ( cam ) ;

    sprintf ( vid->name, "%s_%d_%d_%s_%s_%s", vid->name_ruche, vid->nruche, vid->ncadre, tmp_aut, tmp_cam, vid->date ) ; 

}

char* video_get_name ( video_t* vid ) {
    return vid->name ; 
}

///// Date //// 


