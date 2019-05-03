#ifndef MODIF_WIN_H
#define MODIF_WIN_H

#include <gtk/gtk.h>

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
    GtkWidget *button_ex_1;
    GtkWidget *button_ex_2;
    GtkWidget *button_ex_3;
    GtkWidget *button_ex_4;
    GtkWidget *button_ex_5;
    GtkWidget *barre_temps;
    GtkWidget *button_ex2_1;
    GtkWidget *button_ex2_2;
    GtkWidget *button_ex2_3;
    GtkWidget *button_ex2_4;
    GtkWidget *tags;
    GtkWidget *outils;
    GtkAdjustment *adjustement_barre_temps;
    GtkWidget *time_deb;
    GtkWidget *time_fin;
    GtkWidget *box_menus;
    GtkWidget *box_up;
    GtkWidget *box_time;

} modif_win_t ;

modif_win_t* modif_win_new() ;
void modif_win_show( modif_win_t* ) ;

#endif
