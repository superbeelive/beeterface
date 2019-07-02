#ifndef MAIN_WIN_H
#define MAIN_WIN_H

#include <gtk/gtk.h>

typedef struct {

    GtkWidget *window ; 
   
    //BOX
    GtkWidget* box_principal ;  
    GtkWidget* box_up ;
    GtkWidget* box_down ; 

    GtkWidget* box_left ;
    GtkWidget* box_right ;

    GtkWidget* box_video ; 
    GtkWidget* box_time ;
    GtkWidget* box_btn ;

    GtkWidget* box_info ;
    GtkWidget* box_meta ;
    
    //GRID
    GtkWidget* grid_info ; 
    GtkWidget* grid_meta ;  

    GtkWidget *frame_info ; 
    //Label
    GtkWidget *txt_trier_par;
    GtkWidget *txt_visualiser;
    GtkWidget *label_title ;
   
    GtkWidget *label_info_temp_ruche ;
    GtkWidget *label_info_temp_ext ;
    GtkWidget *label_info_date ; 
    GtkWidget *label_info_heure ; 
   
    GtkWidget *label_temp_ruche ;
    GtkWidget *label_temp_ext ; 
    GtkWidget *label_date ;
    GtkWidget *label_heure ; 

    GtkWidget* label_name_ruche ;
    GtkWidget* label_description ;
    GtkWidget* label_auteur ;
    GtkWidget* label_camera ;
    GtkWidget* label_nruche ;
    GtkWidget* label_ncadre ;

    GtkWidget* label_info_name_ruche ;
    GtkWidget* label_info_description ;
    GtkWidget* label_info_auteur ;
    GtkWidget* label_info_camera ;
    GtkWidget* label_info_nruche ;
    GtkWidget* label_info_ncadre ;

    //Boutons
    GtkWidget *btn_enregistrer;
    GtkWidget *img_btn_enregistrer;
    
    GtkWidget *btn_info;
    GtkWidget *img_btn_info;
    

    
    //Images
    GtkWidget *img_exemple; //Image pour repérer où sera la vidéo
    GtkWidget *img_live;
   
    //Combo Box
    GtkWidget *choix_camera;
    GtkWidget *choix_tri;

    //Autre
    GtkWidget *sep; //Separateur vertical  entre image et selecteur fichier
    GtkWidget *search; //Barre de recherche tag
    GtkWidget *sep_haut; //Ligne de séparation
    GtkWidget *sep_part ;
        
    GtkWidget* scale_time ;   
    GtkAdjustment* adjust_scale_time ; 
} main_win_t ;

main_win_t* main_win_new() ;
void main_win_del( main_win_t* ) ;
void main_win_show( main_win_t* ) ;

#endif
