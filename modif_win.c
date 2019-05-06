#include <stdlib.h>

#include "modif_win.h"

modif_win_t* modif_win_new() {

    modif_win_t* tmp ;
    tmp = malloc ( sizeof(modif_win_t) ) ;

//CREATION
    //Fenetre
    tmp->window2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //Boites
    tmp->box_principal2 = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_gauche = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_milieu = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_droit = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_video = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_outil_video = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_menus = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_up = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_time = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 520); //TO DO : arranger écart temps pour qu'ils soient calé sur la barre de temps 
    //Image
    tmp->image_video = gtk_image_new_from_file ("images/bee2.jpg");
    //Texte
    tmp->titre_video = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(tmp->titre_video), "<span foreground=\"black\" font=\"16\">Nom de la vidéo</span>");


    tmp->text_boite_outils = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(tmp->text_boite_outils), "<span foreground=\"black\" font=\"10\"> <b> Boîte à outils </b> </span>");


    tmp->time_deb = gtk_label_new("0:00");
    tmp->time_fin = gtk_label_new("2:30");

    //Button

    tmp->button_croix = gtk_button_new ();
    tmp->image_button_croix = gtk_image_new_from_file ("images/croix.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_croix), tmp->image_button_croix);
    

    tmp->button_cercle = gtk_button_new ();
    tmp->image_button_cercle = gtk_image_new_from_file ("images/cercle.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_cercle), tmp->image_button_cercle);

    tmp->button_rectangle = gtk_button_new ();
    tmp->image_button_rectangle = gtk_image_new_from_file ("images/rectangle.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_rectangle), tmp->image_button_rectangle);

    tmp->button_fleche = gtk_button_new ();
    tmp->image_button_fleche = gtk_image_new_from_file ("images/fleche.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_fleche), tmp->image_button_fleche);

    tmp->button_gomme = gtk_button_new ();
    tmp->image_button_gomme = gtk_image_new_from_file ("images/gomme.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_gomme), tmp->image_button_gomme);


        //Pour le menu de la video (bas)
    tmp->button_ex2_1 = gtk_button_new_with_label ("Test1");
    tmp->button_ex2_2 = gtk_button_new_with_label ("Test2");
    tmp->button_ex2_3 = gtk_button_new_with_label ("Test3");
    tmp->button_ex2_4 = gtk_button_new_with_label ("Test4");

    //Autre
    tmp->adjustement_barre_temps = gtk_adjustment_new (10,0,500,1,1,2);
    tmp->barre_temps = gtk_scrollbar_new(GTK_ORIENTATION_HORIZONTAL,tmp->adjustement_barre_temps);
    tmp->tags = gtk_places_sidebar_new ();
    tmp->outils = gtk_tool_palette_new ();
   // gtk_tool_palette_set_style ((GtkToolPalette) outils, GTK_TOOLBAR_ICONS);


//RANGEMENT
//Fenetre
       gtk_container_add (GTK_CONTAINER (tmp->window2), tmp->box_menus);

        //Dans box_menus
        gtk_box_pack_start(GTK_BOX(tmp->box_menus), tmp->box_up, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_menus), tmp->box_principal2, TRUE, TRUE, 0);
        //Dans box_up        
        gtk_box_pack_start(GTK_BOX(tmp->box_up), tmp->titre_video, TRUE, TRUE, 0);

        //Dans box_principal2
        gtk_box_pack_start(GTK_BOX(tmp->box_principal2), tmp->box_gauche, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_principal2), tmp->box_milieu, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_principal2), tmp->box_droit, TRUE, TRUE, 0);

            //Dans box_gauche
            gtk_box_pack_start(GTK_BOX(tmp->box_gauche), tmp->box_video, TRUE, TRUE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_gauche), tmp->box_outil_video, TRUE, TRUE, 0);
                //Dans box_video
                gtk_box_pack_start(GTK_BOX(tmp->box_video), tmp->image_video, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_video), tmp->barre_temps, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_video), tmp->box_time, TRUE, TRUE, 0);
                    //Dans box_time
                   gtk_box_pack_start(GTK_BOX(tmp->box_time), tmp->time_deb, TRUE, TRUE, 0);
                   gtk_box_pack_start(GTK_BOX(tmp->box_time), tmp->time_fin, TRUE, TRUE, 0);

                //Dans box_outil_video
                gtk_box_pack_start(GTK_BOX(tmp->box_outil_video), tmp->button_ex2_1, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_outil_video), tmp->button_ex2_2, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_outil_video), tmp->button_ex2_3, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_outil_video), tmp->button_ex2_4, TRUE, TRUE, 0);
                

             //Dans box_milieu (boite à outils)
             gtk_box_pack_start(GTK_BOX(tmp->box_milieu), tmp->text_boite_outils, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(tmp->box_milieu), tmp->button_croix, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(tmp->box_milieu), tmp->button_cercle, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(tmp->box_milieu), tmp->button_rectangle, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(tmp->box_milieu), tmp->button_fleche, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(tmp->box_milieu), tmp->button_gomme, FALSE, FALSE, 0);
             // gtk_box_pack_start(GTK_BOX(tmp->box_milieu), tmp->outils, FALSE, FALSE, 0);

             //Dans box_droit
             gtk_box_pack_start(GTK_BOX(tmp->box_droit), tmp->tags, FALSE, FALSE, 0);

//FONCTIONS
    gtk_window_set_title (GTK_WINDOW (tmp->window2), "Modifier la vidéo"); //Nomme la fenêtre 

    return tmp ;

}

void modif_win_show( modif_win_t* tmp ) {

    gtk_widget_show (tmp->window2);
    gtk_widget_show_all (tmp->box_menus);

}

