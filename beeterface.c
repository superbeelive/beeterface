#include <stdlib.h>

#include "main_win.h"

void destroy (GtkWidget *widget, gpointer data)
{
     gtk_main_quit ();
}        

void window2 (GtkWidget *widget, gpointer data)
{
//DECLARATIONS

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
//CREATION
    //Fenetre
    window2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //Boites
    box_principal2 = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    box_gauche = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_milieu = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_droit = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_video = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_outil_video = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    box_menus = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_up = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    box_time = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 520); //TO DO : arranger écart temps pour qu'ils soient calé sur la barre de temps 
    //Image
    image_video = gtk_image_new_from_file ("images/bee2.jpg");
    //Texte
    titre_video = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(titre_video), "<span foreground=\"black\" font=\"16\">Nom de la vidéo</span>");


    time_deb = gtk_label_new("0:00");
    time_fin = gtk_label_new("2:30");

    //Button
    button_ex_1 = gtk_button_new_with_label ("ex1");
    button_ex_2 = gtk_button_new_with_label ("ex2");
    button_ex_3 = gtk_button_new_with_label ("ex3");
    button_ex_4 = gtk_button_new_with_label ("ex4");
    button_ex_5 = gtk_button_new_with_label ("ex5");
        //Pour le menu de la video (bas)
    button_ex2_1 = gtk_button_new_with_label ("Test1");
    button_ex2_2 = gtk_button_new_with_label ("Test2");
    button_ex2_3 = gtk_button_new_with_label ("Test3");
    button_ex2_4 = gtk_button_new_with_label ("Test4");

    //Autre
    adjustement_barre_temps = gtk_adjustment_new (10,0,500,1,1,2);
    barre_temps = gtk_scrollbar_new(GTK_ORIENTATION_HORIZONTAL,adjustement_barre_temps);
    tags = gtk_places_sidebar_new ();
    outils = gtk_tool_palette_new ();
   // gtk_tool_palette_set_style ((GtkToolPalette) outils, GTK_TOOLBAR_ICONS);


//RANGEMENT
//Fenetre
       gtk_container_add (GTK_CONTAINER (window2), box_menus);

        //Dans box_menus
        gtk_box_pack_start(GTK_BOX(box_menus), box_up, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box_menus), box_principal2, TRUE, TRUE, 0);
        //Dans box_up        
        gtk_box_pack_start(GTK_BOX(box_up), titre_video, TRUE, TRUE, 0);

        //Dans box_principal2
        gtk_box_pack_start(GTK_BOX(box_principal2), box_gauche, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box_principal2), box_milieu, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box_principal2), box_droit, TRUE, TRUE, 0);

            //Dans box_gauche
            gtk_box_pack_start(GTK_BOX(box_gauche), box_video, TRUE, TRUE, 0);
            gtk_box_pack_start(GTK_BOX(box_gauche), box_outil_video, TRUE, TRUE, 0);
                //Dans box_video
                gtk_box_pack_start(GTK_BOX(box_video), image_video, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(box_video), barre_temps, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(box_video), box_time, TRUE, TRUE, 0);
                    //Dans box_time
                   gtk_box_pack_start(GTK_BOX(box_time), time_deb, TRUE, TRUE, 0);
                   gtk_box_pack_start(GTK_BOX(box_time), time_fin, TRUE, TRUE, 0);

                //Dans box_outil_video
                gtk_box_pack_start(GTK_BOX(box_outil_video), button_ex2_1, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(box_outil_video), button_ex2_2, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(box_outil_video), button_ex2_3, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(box_outil_video), button_ex2_4, TRUE, TRUE, 0);
                

             //Dans box_milieu
             gtk_box_pack_start(GTK_BOX(box_milieu), button_ex_1, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(box_milieu), button_ex_2, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(box_milieu), button_ex_3, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(box_milieu), button_ex_4, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(box_milieu), button_ex_5, FALSE, FALSE, 0);
             // gtk_box_pack_start(GTK_BOX(box_milieu), outils, FALSE, FALSE, 0);

             //Dans box_droit
             gtk_box_pack_start(GTK_BOX(box_droit), tags, FALSE, FALSE, 0);


//FONCTIONS
    gtk_window_set_title (GTK_WINDOW (window2), "Modifier la vidéo"); //Nomme la fenêtre 
//AFFICHAGE
    gtk_widget_show (window2);
    gtk_widget_show_all (box_menus);

}


int main (int argc, char *argv[])
{

//DECLARATIONS

    main_win_t* fenetre ;
    
    gtk_init (&argc, &argv);
    fenetre = main_win_new() ;

    main_win_show( fenetre ) ;

//AFFICHAGE 
  gtk_main ();
    return 0;

}
