#ifndef MAIN_WIN_H
#define MAIN_WIN_H

#include <gtk/gtk.h>

typedef struct {

    GtkWidget *window; //Fenêtre d'acceuil 
   
    //Container
    GtkWidget *box_principal; //Boite principale contenant les autres boites 
    GtkWidget *box_up; //Boite la plus haute pour le bouton quitter (provisoire ?) 
    GtkWidget *box_all; //Reste de la zone 
    GtkWidget *box_info_video;
    GtkWidget *box_menu_droit; //Boite pour la droite de la vidéo
    GtkWidget *box_gauche; //Boite contenant vidéo & menus
    GtkWidget *box_video; //boite avec la vidéo + nom de la vidéo
    GtkWidget *box_menu_video; //Menu sous la vidéo
    GtkWidget *box_quit;
    GtkWidget *box_search_1;
    GtkWidget *box_search_2;
    GtkWidget *box_info_sup;
    
    GtkWidget *grid_info ; 

    //Label
    GtkWidget *txt_trier_par;
    GtkWidget *txt_visualiser;
    GtkWidget *nom_video;
   
    GtkWidget *label_title_info ;
    GtkWidget *label_info_temp_ruche ;
    GtkWidget *label_info_temp_ext ;
    GtkWidget *label_info_date ; 
    GtkWidget *label_info_heure ; 
   
    GtkWidget *label_temp_ruche ;
    GtkWidget *label_temp_ext ; 
    GtkWidget *label_date ;
    GtkWidget *label_heure ; 


    //Boutons
    GtkWidget *button_quit; //Bouton quitter 
    GtkWidget *image_button_quit;
        
    GtkWidget *button_enregistrer;
    GtkWidget *image_button_enregistrer;
    
    GtkWidget *button_info;
    GtkWidget *image_button_info;
    
    GtkWidget *button_stop;
    GtkWidget *image_button_stop;
    
    GtkWidget *button_photo;
    GtkWidget *image_button_photo;
    
    
    GtkWidget *button_auteur ; 
    GtkWidget *button_video ;
    GtkWidget *button_camera ; 
    GtkWidget *button_tag ;  
    
    //Images
    GtkWidget *image_exemple; //Image pour repérer où sera la vidéo
    GtkWidget *logo_type_video;
   
    //Combo Box
    GtkWidget *choix_camera;
    GtkWidget *choix_tri;

    //Autre
    GtkWidget *sep; //Separateur vertical  entre image et selecteur fichier
    GtkWidget *fichiers; //Gestionnaire de fichiers pour simuler le futur TAG
    GtkWidget *search; //Barre de recherche tag
    GtkWidget *sep_haut; //Ligne de séparation
    
    
} main_win_t ;

main_win_t* main_win_new() ;
void main_win_del( main_win_t* ) ;
void main_win_show( main_win_t* ) ;

#endif
