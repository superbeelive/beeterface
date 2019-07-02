#ifndef INTERFACE_H
#define INTERFACE_H

#include "win_main.h"
#include "win_modif.h"
#include "win_auteur.h"
#include "win_video.h"
#include "win_camera.h"
#include "win_tag.h"
#include "win_info.h"
#include "win_color.h"

typedef struct {

	main_win_t* win_main ;	
	modif_win_t* win_modif ;
	auteur_win_t* win_auteur ;
    video_win_t* win_video ; 
    camera_win_t* win_camera ;
    tag_win_t* win_tag ; 
    info_win_t* win_info ; 
    color_win_t* win_color ; 

} interface_t ;


interface_t* interface_new() ;
void interface_del ( interface_t*) ;

#endif