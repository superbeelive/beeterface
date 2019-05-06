#ifndef MAIN_WIN_H
#define MAIN_WIN_H

#include <gtk/gtk.h>

typedef struct {

    GtkWidget *window; //Fenêtre d'acceuil 
    GtkWidget *box_principal; //Boite principale contenant les autres boites 
    GtkWidget *button_quit; //Bouton quitter 
    GtkWidget *image_button_quit;
    GtkWidget *box_up; //Boite la plus haute pour le bouton quitter (provisoire ?) 
    GtkWidget *box_all; //Reste de la zone 
    GtkWidget *box_info_video;
    GtkWidget *image_exemple; //Image pour repérer où sera la vidéo
    GtkWidget *box_menu_droit; //Boite pour la droite de la vidéo
    GtkWidget *box_gauche; //Boite contenant vidéo & menus
    GtkWidget *box_video; //boite avec la vidéo + nom de la vidéo
    GtkWidget *box_menu_video; //Menu sous la vidéo
    GtkWidget *box_quit;
    GtkWidget *box_search_1;
    GtkWidget *box_search_2;
    GtkWidget *sep; //Separateur vertical  entre image et selecteur fichier
    GtkWidget *fichiers; 
    GtkWidget *search;
    GtkWidget *nom_video;
    GtkWidget *choix_camera;
    GtkWidget *button_enregistrer;
    GtkWidget *image_button_enregistrer;
    GtkWidget *button_stop;
    GtkWidget *image_button_stop;
    GtkWidget *button_photo;
    GtkWidget *image_button_photo;
    GtkWidget *logo_type_video;
    GtkWidget *choix_tri;
    GtkWidget *txt_trier_par;
    GtkWidget *txt_visualiser;
    GtkWidget *button_info;
    GtkWidget *image_button_info;

} main_win_t ;

main_win_t* main_win_new() ;
void main_win_del( main_win_t* ) ;
void main_win_show( main_win_t* ) ;

#endif
