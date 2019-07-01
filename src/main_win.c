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
    tmp->box_info_sup = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);

    tmp->scroll_tag = gtk_scrolled_window_new (NULL, NULL) ; 
    //GRID
    tmp->grid_info = gtk_grid_new() ; 
    
    //Paned
    tmp->frame_info = gtk_frame_new ("Informations") ;

    
    //BOUTONS
    tmp->button_quit = gtk_button_new ();  
    tmp->image_button_quit = gtk_image_new_from_file ("/usr/share/beeterface/images/quit3.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_quit), tmp->image_button_quit);

    tmp->button_enregistrer = gtk_button_new ();
    tmp->image_button_enregistrer = gtk_image_new_from_file ("/usr/share/beeterface/images/enregistrer.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_enregistrer), tmp->image_button_enregistrer);


    tmp->button_stop = gtk_button_new ();
    tmp->image_button_stop =  gtk_image_new_from_file ("/usr/share/beeterface/images/carre_noir.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_stop), tmp->image_button_stop);

    tmp->button_photo = gtk_button_new ();
    tmp->image_button_photo = gtk_image_new_from_file ("/usr/share/beeterface/images/icone_photo3.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_photo), tmp->image_button_photo);

    tmp->button_info = gtk_button_new ();
    tmp->image_button_info = gtk_image_new_from_file ("/usr/share/beeterface/images/inter.png");
    gtk_button_set_image (GTK_BUTTON (tmp->button_info), tmp->image_button_info);
   
    tmp->button_auteur =  gtk_button_new_with_label ("Auteur");
    tmp->button_video =  gtk_button_new_with_label ("Video");
    tmp->button_camera =  gtk_button_new_with_label ("Camera");
    tmp->button_tag =  gtk_button_new_with_label ("Tag");


    //IMAGES  
    tmp->image_exemple = gtk_image_new_from_file ("/usr/share/beeterface/images/video_bee.jpg") ;
    tmp->logo_type_video = gtk_image_new_from_file ("/usr/share/beeterface/images/cassette2.png") ;

    //TEXTE 
    tmp->nom_video = gtk_label_new("") ;
    gtk_label_set_markup(GTK_LABEL(tmp->nom_video), "<span foreground=\"black\" font=\"16\">Nom de la vidéo</span>");
    
    tmp->txt_trier_par = gtk_label_new("") ;
    gtk_label_set_markup(GTK_LABEL(tmp->txt_trier_par), "<span foreground=\"black\" font=\"10\">Trier par :</span>");

    tmp->txt_visualiser = gtk_label_new("") ;
    gtk_label_set_markup(GTK_LABEL(tmp->txt_visualiser), "<span foreground=\"black\" font=\"10\">Visualiser :</span>");


    tmp->label_info_date = gtk_label_new("Date  ") ; 
    tmp->label_info_heure = gtk_label_new("Heure  ") ; 
    tmp->label_info_temp_ruche = gtk_label_new("Temp. Ruche  ") ; 
    tmp->label_info_temp_ext = gtk_label_new("Temp. Ext.  ") ; 
    
    tmp->label_date = gtk_label_new("ex_date") ; 
    tmp->label_heure = gtk_label_new("ex_heure") ; 
    tmp->label_temp_ruche = gtk_label_new("42°") ; 
    tmp->label_temp_ext = gtk_label_new("51°") ; 
   
    tmp->label_test = gtk_label_new ("Je suis un test de texte bonjour.\ntest \ntest \ntest \ntest") ; 

    //AUTRES 
    tmp->sep = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
    tmp->sep_tag = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
    tmp->sep_haut = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
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


//RANGEMENT
    
    //Boite PRINCIPALE 
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal);
        //Dans la boite principale :
        gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_up, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_all, FALSE, FALSE, 0);

            //Dans tmp->box_up
            gtk_box_pack_start(GTK_BOX(tmp->box_up), tmp->box_quit, FALSE, FALSE, 5); 
            gtk_box_pack_start(GTK_BOX(tmp->box_up), tmp->sep_haut, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_up), tmp->box_info_video, TRUE, TRUE, 0);
                 //Dans tmp->box_info_video   
                 gtk_box_pack_start(GTK_BOX(tmp->box_info_video), tmp->logo_type_video, FALSE, FALSE, 20);
                 gtk_box_pack_start(GTK_BOX(tmp->box_info_video), tmp->nom_video, FALSE, FALSE, 0);

                 //Dans tmp->box_quit
                 gtk_box_pack_start(GTK_BOX(tmp->box_quit), tmp->button_quit, FALSE, FALSE, 0);
                 gtk_box_pack_start(GTK_BOX(tmp->box_quit), tmp->button_info, FALSE, FALSE, 0);
                 gtk_box_pack_start(GTK_BOX(tmp->box_quit), tmp->button_video, FALSE, FALSE, 0);
                 gtk_box_pack_start(GTK_BOX(tmp->box_quit), tmp->button_auteur, FALSE, FALSE, 0);
                 gtk_box_pack_start(GTK_BOX(tmp->box_quit), tmp->button_camera, FALSE, FALSE, 0);
                 gtk_box_pack_start(GTK_BOX(tmp->box_quit), tmp->button_tag, FALSE, FALSE, 0);
            
            //Dans tmp->box_all
            gtk_box_pack_start(GTK_BOX(tmp->box_all), tmp->box_gauche, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_all), tmp->box_info_sup, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_all), tmp->sep, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_all), tmp->box_menu_droit, TRUE, TRUE, 0);
            


                //Dans tmp->box_menu_droit
                 gtk_box_pack_start(GTK_BOX(tmp->box_menu_droit), tmp->box_search_1, FALSE, FALSE, 0);
                 gtk_box_pack_start(GTK_BOX(tmp->box_menu_droit), tmp->box_search_2, TRUE, TRUE, 0);
            
                    //Dans tmp->box_search_1
                    gtk_box_pack_start(GTK_BOX(tmp->box_search_1), tmp->search, TRUE, TRUE, 5);
                    gtk_box_pack_start(GTK_BOX(tmp->box_search_1), tmp->txt_trier_par, TRUE, TRUE, 0);

                    gtk_box_pack_start(GTK_BOX(tmp->box_search_1), tmp->choix_tri, TRUE, TRUE, 5);

                    //Dans tmp->box_search_2
                    gtk_box_pack_start(GTK_BOX(tmp->box_search_2), tmp->scroll_tag, TRUE, TRUE, 0);
                        //Scroll_tag                       
                        gtk_container_add (GTK_CONTAINER (tmp->scroll_tag), tmp->label_test);

                 //Dans tmp->box_gauche
                 gtk_box_pack_start(GTK_BOX(tmp->box_gauche), tmp->box_video, FALSE, FALSE, 0);
                 gtk_box_pack_start(GTK_BOX(tmp->box_gauche), tmp->box_menu_video, FALSE, FALSE,0);

                            //Dans tmp->box_video
                             gtk_box_pack_start(GTK_BOX(tmp->box_video), tmp->image_exemple, FALSE, FALSE, 0);

                             //Dans tmp->box_menu_video
                             gtk_box_pack_start(GTK_BOX(tmp->box_menu_video), tmp->txt_visualiser, FALSE, FALSE, 10);
                             gtk_box_pack_start(GTK_BOX(tmp->box_menu_video), tmp->choix_camera, FALSE, FALSE, 0);
                             gtk_box_pack_start(GTK_BOX(tmp->box_menu_video), tmp->button_enregistrer, FALSE, FALSE, 0);
                             gtk_box_pack_start(GTK_BOX(tmp->box_menu_video), tmp->button_stop, FALSE, FALSE, 0);
                             gtk_box_pack_start(GTK_BOX(tmp->box_menu_video), tmp->button_photo, FALSE, FALSE, 0);

                  //Dans box_info_sup 
                  gtk_box_pack_start(GTK_BOX(tmp->box_info_sup), tmp->frame_info, FALSE, FALSE, 0);
                  gtk_container_add (GTK_CONTAINER (tmp->frame_info), tmp->grid_info);

                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_info_date, 1, 1, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_info_heure, 1, 2, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_info_temp_ext, 1, 3, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_info_temp_ruche, 1, 4, 1, 1) ;  
                   
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_date, 2, 1, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_heure, 2, 2, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_temp_ext, 2, 3, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_temp_ruche, 2, 4, 1, 1) ;  
                   
                  


//PLACEMENT
    //Window
    gtk_window_set_title (GTK_WINDOW (tmp->window), "BEETERFACE"); //Nomme la fenêtre 
    gtk_window_set_default_size ( GTK_WINDOW (tmp->window), 30, 30 ) ; 
    gtk_window_unmaximize (GTK_WINDOW (tmp->window));
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );
    
    //image_exemple
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->image_exemple), 5 ) ;
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->image_exemple), 5 ) ;
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->image_exemple), 5 ) ;
    
    //logo_type_video
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->logo_type_video), 5 ) ;
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->logo_type_video), 5 ) ;
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->logo_type_video), 10 ) ;

    
    //fichier
    
    //sep
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->sep), 10 ) ;

    //menu_video
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->txt_visualiser), 2 ) ;
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->choix_camera), 5 ) ;
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->button_enregistrer), 5 ) ;
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->button_stop), 5 ) ;
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->button_photo), 5 ) ;

    //Information sup
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->box_info_sup), 10 ) ; 
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->box_info_sup), 5 ) ;


    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_temp_ruche), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_temp_ext), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_date), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_heure), GTK_ALIGN_START ) ;

    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_temp_ruche), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_temp_ext), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_date), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_heure), GTK_ALIGN_START ) ;

    gtk_widget_set_margin_end (GTK_WIDGET (tmp->grid_info), 5 ) ;
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->grid_info), 5 ) ;
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->grid_info), 5 ) ;
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->grid_info), 5 ) ;

    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->scroll_tag), 45 ) ;

    return tmp ;
}


void main_win_show ( main_win_t* tmp ) {  
 
    gtk_widget_show (tmp->window);
    gtk_widget_show_all (tmp->box_principal);
    gtk_widget_show_all (tmp->box_up);

}

void main_win_del( main_win_t* W ) {
    free(W) ;
}
