#ifndef MODIF_WIN_H
#define MODIF_WIN_H

#include <gtk/gtk.h>

//const gchar* names[] = {"test1", "test2", "test3", "test4" };


typedef struct {

    GtkWidget *window2; //Fenetre changements
    GtkWidget *box_principal2;    
    GtkWidget *box_gauche;    
    GtkWidget *box_milieu;
    GtkWidget *box_droit;
    GtkWidget *box_video;
    GtkWidget *box_outil_video;
    GtkWidget *image_video;
    GtkWidget *titre_video;
    GtkWidget *text_boite_outils;

    GtkWidget *button_croix;
    GtkWidget *image_button_croix;

    GtkWidget *button_cercle;
    GtkWidget *image_button_cercle;

    GtkWidget *button_rectangle;
    GtkWidget *image_button_rectangle;

    GtkWidget *button_fleche;
    GtkWidget *image_button_fleche;

    GtkWidget *button_gomme;
    GtkWidget *image_button_gomme;


    GtkWidget *barre_temps;

    
 /*   GtkWidget *button_ex2_1;
    GtkWidget *button_ex2_2;
    GtkWidget *button_ex2_3;
    GtkWidget *button_ex2_4; */
    GtkWidget *tags;
    GtkWidget *outils;
    GtkAdjustment *adjustement_barre_temps;
    GtkWidget *time_deb;
    GtkWidget *time_fin;
    GtkWidget *box_menus;
    GtkWidget *box_up;
    GtkWidget *box_time; 

    GtkWidget* button_list[4];
    GtkWidget* image_button_list[4];

    
} modif_win_t ; //typedef + struct sur la même ligne

//pré déclaration des fonctions 
modif_win_t* modif_win_new() ; 
void modif_win_show( modif_win_t* ) ;

#endif
