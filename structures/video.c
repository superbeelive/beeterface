#include "video.h" 

#define TAILLE 128

video_t* video_new() {

    video_t* vid ; 
    vid = malloc ( sizeof( video_t ) ) ;
    vid->name_ruche = malloc ( TAILLE ) ;
    vid->description = malloc ( TAILLE ) ; 
    vid->date = malloc ( time_t ) ; //FIXME : doute sur cette déclaration : je dois faire comme en dessous ou au dessus ? 
    auteur_new(); 
    camera_new();

    sprintf ( vid->name_ruche, "Nom_de_la_ruche" ) ;
    sprintf ( vid->nruche, "0" ) ;
    sprintf ( vid->ncadre, "0" ) ;
    sprintf ( vid->description, "Description_de_la_video" ) ;

    //Et pour la date ? 

    return vid ;
}

void video_del ( video_t* vid ) {
    
    free ( vid->name_ruche ) ;
    free ( vid->description ) ;
    free ( vid->date ) ;
    auteur_del(vid) ;
    camera_del(vid) ;

    free( vid ) ;
}

void video_show ( video_t* vid ) {
    //utilisation de %s, %d ..? 
    printf("%s %d %d %s", vid->name_ruche,
                        vid->nruche,
                        vid->ncadre,
                        vid->description);

    auteur_show(vid);
    camera_show(vid);
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
    sprintf ( vid->nruche, "%d", num);
}

int video_get_nruche ( video_t* vid ) {
    return vid->nruchev ;
}


/////// Numéro cadre ///////

void video_set_ncadre ( video_t* vid, int num ) {
    sprintf ( vid->ncadre, "%d", num );
}

int video_get_ncadre ( video_t* vid ) { 
    return vid->ncadre ;
}

/////// Description //////

void video_set_description ( video_t* vid, char* desc ) {
    sprintf ( vid->description, "%s", num ) ;
}

char* video_get_description ( video_t* vid ) {
    return vid->description ;
}

   /// AUTEUR ET VIDEO ????



