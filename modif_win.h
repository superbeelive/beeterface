#ifndef MODIF_WIN_H
#define MODIF_WIN_H

#include <gtk/gtk.h>

//const gchar* names[] = {"test1", "test2", "test3", "test4" };


typedef struct {

    GtkWidget *window; //Fenetre changements
    GtkWidget *box_principal2;    
    GtkWidget *box_gauche;    
    GtkWidget *box_milieu;
    GtkWidget *box_droit;
    GtkWidget *box_droit_bas ; 
    GtkWidget *box_video;
    GtkWidget *box_outil_video;
    GtkWidget *box_menus;
    GtkWidget *box_up;
    GtkWidget *box_time;
    GtkWidget *frame_tag_add ; 

    GtkWidget *grid_outil_video ;
    GtkWidget *grid_outil_tag ; 

    GtkWidget *image_video;
    
    GtkWidget *titre_video;
    GtkWidget *text_boite_outils;
    GtkWidget *time_deb;
    GtkWidget *time_fin;
    GtkWidget *txt_titre_tag ; 
    GtkWidget *label_test ; 
    GtkWidget *label_test2 ; 

    GtkWidget* btn_list_outils_dessin[5];
    GtkWidget* img_btn_list_outils_dessin[5];
    
    GtkWidget* button_list[4];
    GtkWidget* image_button_list[4];
    
    GtkWidget *barre_temps;
    GtkAdjustment *adjustement_barre_temps;
    
    GtkWidget* separateur ;
    GtkWidget* separateur2 ; 
    GtkWidget* scroll ;  

    
} modif_win_t ; //typedef + struct sur la même ligne

//pré déclaration des fonctions 
modif_win_t* modif_win_new() ; 
void modif_win_show( modif_win_t* ) ;
void modif_win_del( modif_win_t* ) ;

#endif
