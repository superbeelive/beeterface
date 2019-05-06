#include <stdlib.h>

#include "main_win.h"

main_win_t* main_win_new() {

    main_win_t* tmp ;
    tmp = malloc ( sizeof(main_win_t) ) ;

//CREATION    
    //Fenêtre principale 
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //BOITES 
    tmp->box_principal = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_up = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_all = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_menu_droit = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_gauche = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_video = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_menu_video = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_info_video = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_quit = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_search_1 = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_search_2 = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    

    //BOUTONS
    tmp->button_quit = gtk_button_new (); //Definition sur deux lignes  
    //gtk_button_set_label ((GtkButton*)tmp->button_quit,"Quitter");
    tmp->image_button_quit = gtk_image_new_from_file ("images/quit3.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_quit), tmp->image_button_quit);

    tmp->button_enregistrer = gtk_button_new ();
    tmp->image_button_enregistrer = gtk_image_new_from_file ("images/enregistrer.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_enregistrer), tmp->image_button_enregistrer);


    tmp->button_stop = gtk_button_new ();
    tmp->image_button_stop =  gtk_image_new_from_file ("images/carre_noir.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_stop), tmp->image_button_stop);

    tmp->button_photo = gtk_button_new ();
    tmp->image_button_photo = gtk_image_new_from_file ("images/icone_photo3.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_photo), tmp->image_button_photo);

    tmp->button_info = gtk_button_new ();
    tmp->image_button_info = gtk_image_new_from_file ("images/inter.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_info), tmp->image_button_info);
    
    //IMAGES  
    tmp->image_exemple = gtk_image_new_from_file ("images/bee2.jpg");
    tmp->logo_type_video = gtk_image_new_from_file ("images/cassette2.png");
    //TEXTE 
    tmp->nom_video = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(tmp->nom_video), "<span foreground=\"black\" font=\"16\">Nom de la vidéo</span>");
    
    tmp->txt_trier_par = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(tmp->txt_trier_par), "<span foreground=\"black\" font=\"10\">Trier par :</span>");

    tmp->txt_visualiser = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(tmp->txt_visualiser), "<span foreground=\"black\" font=\"10\">Visualiser :</span>");



    //AUTRES 
    tmp->fichiers = gtk_places_sidebar_new ();
    tmp->sep = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
    tmp->search = gtk_search_entry_new ();
    
    tmp->choix_camera = gtk_combo_box_text_new();
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_camera, 1,"Caméra n°1");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_camera, 2,"Caméra n°2");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_camera, 3,"Caméra n°3");

    tmp->choix_tri =  gtk_combo_box_text_new();
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_tri, 3,"Date");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_tri, 3,"Nom");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_tri, 3,"Tag");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_tri, 3,"Caméra");


//Rangement des boxs & Widgets 
    
    //Boite PRINCIPALE 
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal);
        //Dans la boite principale :
        gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_up, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_all, TRUE, TRUE, 0);

            //Dans tmp->box_up
            gtk_box_pack_start(GTK_BOX(tmp->box_up), tmp->box_quit, TRUE, TRUE, 0); 
            gtk_box_pack_start(GTK_BOX(tmp->box_up), tmp->box_info_video, TRUE, TRUE, 0); 
                 //Dans tmp->box_info_video   
                 gtk_box_pack_start(GTK_BOX(tmp->box_info_video), tmp->logo_type_video, FALSE, FALSE, 20);
                 gtk_box_pack_start(GTK_BOX(tmp->box_info_video), tmp->nom_video, FALSE, FALSE, 0);

                 //Dans tmp->box_quit
                 gtk_box_pack_start(GTK_BOX(tmp->box_quit), tmp->button_quit, FALSE, FALSE, 0);
                 gtk_box_pack_start(GTK_BOX(tmp->box_quit), tmp->button_info, FALSE, FALSE, 0);

            //Dans tmp->box_all
            gtk_box_pack_start(GTK_BOX(tmp->box_all), tmp->box_gauche, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_all), tmp->sep, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_all), tmp->box_menu_droit, TRUE, TRUE, 0);

                //Dans tmp->box_menu_droit
                 gtk_box_pack_start(GTK_BOX(tmp->box_menu_droit), tmp->box_search_1, FALSE, FALSE, 0);
                 gtk_box_pack_start(GTK_BOX(tmp->box_menu_droit), tmp->box_search_2, FALSE, FALSE, 0);
                    //Dans tmp->box_search_1
                    gtk_box_pack_start(GTK_BOX(tmp->box_search_1), tmp->search, FALSE, FALSE, 5);
                    gtk_box_pack_start(GTK_BOX(tmp->box_search_1), tmp->txt_trier_par, FALSE, FALSE, 0);

                    gtk_box_pack_start(GTK_BOX(tmp->box_search_1), tmp->choix_tri, FALSE, FALSE, 5);

                    //Dans tmp->box_search_2
                    gtk_box_pack_start(GTK_BOX(tmp->box_search_2), tmp->fichiers, FALSE, FALSE, 0);

                //Dans tmp->box_gauche
                     gtk_box_pack_start(GTK_BOX(tmp->box_gauche), tmp->box_video, FALSE, FALSE, 0);
                     gtk_box_pack_start(GTK_BOX(tmp->box_gauche), tmp->box_menu_video, FALSE, FALSE, 0);

                        //Dans tmp->box_video
                             gtk_box_pack_start(GTK_BOX(tmp->box_video), tmp->image_exemple, FALSE, FALSE, 0);

                        //Dans tmp->box_menu_video
                             gtk_box_pack_start(GTK_BOX(tmp->box_menu_video), tmp->txt_visualiser, FALSE, FALSE, 10);
                             gtk_box_pack_start(GTK_BOX(tmp->box_menu_video), tmp->choix_camera, FALSE, FALSE, 0);
                             gtk_box_pack_start(GTK_BOX(tmp->box_menu_video), tmp->button_enregistrer, FALSE, FALSE, 0);
                             gtk_box_pack_start(GTK_BOX(tmp->box_menu_video), tmp->button_stop, FALSE, FALSE, 0);
                             gtk_box_pack_start(GTK_BOX(tmp->box_menu_video), tmp->button_photo, FALSE, FALSE, 0);



//AUTRE 
    gtk_window_set_title (GTK_WINDOW (tmp->window), "BEETERFACE"); //Nomme la fenêtre 

    return tmp ;
}






void main_win_show ( main_win_t* tmp ) {

  
    //BOX

    gtk_widget_show (tmp->window);
    gtk_widget_show_all ( tmp->box_principal);
    gtk_widget_show_all (tmp->box_up);

}

void main_win_del( main_win_t* W ) {
    free(W) ;
}
