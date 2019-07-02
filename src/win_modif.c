#include <stdlib.h>

#include "win_modif.h"

const gchar* images_boutons[] = {"/usr/share/beeterface/images/ciseaux.png", 
                                    "/usr/share/beeterface/images/next.png", 
                                    "/usr/share/beeterface/images/next.png", 
                                    "/usr/share/beeterface/images/save.png" };


modif_win_t* modif_win_new() {
    
    modif_win_t* tmp ;
    tmp = malloc ( sizeof(modif_win_t) ) ;

//DECLARATION VAR
    gint i;

//CREATION
    
    //WINDOW
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    //BOX
    tmp->box_principale = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_left = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_right = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);


    tmp->box_video = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_time = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0); 
    tmp->box_label_time = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0); 
    tmp->box_tool_video = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    
    tmp->box_tool_an = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_an = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0); 
    tmp->box_tag = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);       
    tmp->box_btn_tag = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);     

    

    //GRID
    tmp->grid_tool_video = gtk_grid_new() ;
    tmp->grid_tool_an = gtk_grid_new() ; 


    //OTHER BOX 
    tmp->scroll_an = gtk_scrolled_window_new (NULL, NULL) ; 
    tmp->scroll_tag = gtk_scrolled_window_new (NULL, NULL) ; 
    tmp->frame_tool_an = gtk_frame_new ("Boîte à Outils") ;  

    //IMAGE 
    tmp->img_video = gtk_image_new_from_file ("/usr/share/beeterface/images/video_bee.jpg");
    
    //LABEL
    tmp->label_title_video = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(tmp->label_title_video), "<span foreground=\"black\" font=\"16\">Nom de la vidéo</span>");

    tmp->label_title_an = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(tmp->label_title_an), "<span foreground=\"black\" font=\"10\"> Annotations </span>");

    tmp->label_title_tag = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_title_tag), "<span foreground=\"black\" font=\"10\"> Tags </span>");

    tmp->label_time_deb = gtk_label_new("0:00");
    tmp->label_time_fin = gtk_label_new("2:30");
    tmp->label_test = gtk_label_new ("Je suis un test de texte bonjour.\ntest \ntest \ntest \ntest") ; 
    tmp->label_test2 = gtk_label_new ("Je suis un test de texte bonjour.\ntest \ntest \ntest \ntest") ; 

    //BUTTONS 

    tmp->button_add_tag = gtk_button_new_with_label ("Ajouter") ;
    tmp->button_remove_tag = gtk_button_new_with_label ("Retirer") ;

    tmp->btn_erase = gtk_button_new ();
        tmp->img_btn_erase =  gtk_image_new_from_file ("/usr/share/beeterface/images/gomme.png");
        gtk_button_set_image (GTK_BUTTON (tmp->btn_erase), tmp->img_btn_erase);
    
    tmp->btn_an_cross = gtk_button_new ();
        tmp->img_btn_an_cross =  gtk_image_new_from_file ("/usr/share/beeterface/images/croix.png");
        gtk_button_set_image (GTK_BUTTON (tmp->btn_an_cross), tmp->img_btn_an_cross);

    tmp->btn_an_circle = gtk_button_new ();
        tmp->img_btn_an_circle =  gtk_image_new_from_file ("/usr/share/beeterface/images/cercle.png");
        gtk_button_set_image (GTK_BUTTON (tmp->btn_an_circle), tmp->img_btn_an_circle);

    tmp->btn_an_oblong = gtk_button_new ();
        tmp->img_btn_an_oblong =  gtk_image_new_from_file ("/usr/share/beeterface/images/rectangle.png");
        gtk_button_set_image (GTK_BUTTON (tmp->btn_an_oblong), tmp->img_btn_an_oblong);

    tmp->btn_an_arrow = gtk_button_new ();
        tmp->img_btn_an_arrow =  gtk_image_new_from_file ("/usr/share/beeterface/images/fleche.png");
        gtk_button_set_image (GTK_BUTTON (tmp->btn_an_arrow), tmp->img_btn_an_arrow);

    tmp->btn_an_moving_cross = gtk_button_new ();
        tmp->img_btn_an_moving_cross =  gtk_image_new_from_file ("/usr/share/beeterface/images/croix.png");
        gtk_button_set_image (GTK_BUTTON (tmp->btn_an_moving_cross), tmp->img_btn_an_moving_cross);

    tmp->btn_an_measure = gtk_button_new_with_label ("Mesure");
    tmp->btn_an_text = gtk_button_new_with_label ("Texte");
    tmp->btn_color = gtk_button_new_with_label ("Couleur");

    
        //Boutons du bas édition vidéo
    
    for  (i = 0; i < 4; i++) {
        tmp->button_list[i] = gtk_button_new ();
        tmp->image_button_list[i] =  gtk_image_new_from_file (images_boutons[i]);
        gtk_button_set_image (GTK_BUTTON (tmp->button_list[i]), tmp->image_button_list[i]);

        gtk_grid_attach(GTK_GRID (tmp->grid_tool_video),tmp->button_list[i], i, 1, 1, 1) ;  

        gtk_widget_set_margin_top (GTK_WIDGET (tmp->button_list[i]), 5 ) ;
        gtk_widget_set_margin_end (GTK_WIDGET (tmp->button_list[i]), 10 ) ;

    } 

    //SEPARATOR 
    tmp->sep = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL) ; 
    tmp->sep2 = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL) ; 

    //OTHER WIDGET 
    tmp->adjustement_barre_temps = gtk_adjustment_new (10,0,500,1,1,2);
    tmp->barre_temps = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL,tmp->adjustement_barre_temps);
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->label_title_video), 5) ; 
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->label_title_tag), 5) ; 
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->label_title_an), 5) ; 



//RANGEMENT
//Fenetre
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principale);

        //box_principale
        gtk_box_pack_start(GTK_BOX(tmp->box_principale), tmp->box_left,  FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_principale), tmp->sep, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_principale), tmp->box_right, FALSE, FALSE, 0);
       
            //box_left       
            gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_video, FALSE, FALSE, 0);
                //box_video
                gtk_box_pack_start(GTK_BOX(tmp->box_video), tmp->label_title_video, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_video), tmp->img_video, FALSE, FALSE, 0);


            gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_time, FALSE, FALSE, 0);
                //box_time
                gtk_box_pack_start(GTK_BOX(tmp->box_time), tmp->barre_temps, TRUE, TRUE, 0);
                        
            gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_label_time, FALSE, FALSE, 0);
                //box_label_time
                gtk_box_pack_start(GTK_BOX(tmp->box_label_time), tmp->label_time_deb, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_label_time), tmp->label_time_fin, FALSE, FALSE, 0);


            gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_tool_video, FALSE, FALSE, 0);
                //box_tool_video
                gtk_box_pack_start(GTK_BOX(tmp->box_tool_video), tmp->grid_tool_video, FALSE, FALSE, 0);


            //box_right
            gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_tool_an, FALSE, FALSE, 0);
                //box_tool_an
                gtk_box_pack_start(GTK_BOX(tmp->box_tool_an), tmp->frame_tool_an, FALSE, FALSE, 0);
                    gtk_container_add (GTK_CONTAINER (tmp->frame_tool_an), tmp->grid_tool_an);
                        //Colonne 1
                     gtk_grid_attach(GTK_GRID (tmp->grid_tool_an), tmp->btn_an_cross, 1,1,1,1 ) ;
                     gtk_grid_attach(GTK_GRID (tmp->grid_tool_an), tmp->btn_an_circle, 1,2,1,1 ) ;
                     gtk_grid_attach(GTK_GRID (tmp->grid_tool_an), tmp->btn_an_oblong, 1,3,1,1 ) ;
                        //Colonne 2
                     gtk_grid_attach(GTK_GRID (tmp->grid_tool_an), tmp->btn_an_arrow, 2,1,1,1 ) ;
                     gtk_grid_attach(GTK_GRID (tmp->grid_tool_an), tmp->btn_an_moving_cross, 2,2,1,1 ) ;

                     gtk_grid_attach(GTK_GRID (tmp->grid_tool_an), tmp->btn_an_measure, 3,1,1,1 ) ;
                     gtk_grid_attach(GTK_GRID (tmp->grid_tool_an), tmp->btn_an_text, 3,2,1,1 ) ;

                     gtk_grid_attach(GTK_GRID (tmp->grid_tool_an), tmp->btn_erase, 4,1,1,1 ) ;
                     gtk_grid_attach(GTK_GRID (tmp->grid_tool_an), tmp->btn_color, 4,2,1,1 ) ;

            gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_an, FALSE, FALSE, 0);
                //box_an
                gtk_box_pack_start(GTK_BOX(tmp->box_an), tmp->label_title_an, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_an), tmp->scroll_an, FALSE, FALSE, 0);
                    gtk_container_add (GTK_CONTAINER (tmp->scroll_an), tmp->label_test);
                
            gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_tag, FALSE, FALSE, 0);
                //box_tag 
                gtk_box_pack_start(GTK_BOX(tmp->box_tag), tmp->label_title_tag, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_tag), tmp->scroll_tag, FALSE, FALSE, 0);
                    gtk_container_add (GTK_CONTAINER (tmp->scroll_tag), tmp->label_test2);
                gtk_box_pack_start(GTK_BOX(tmp->box_tag), tmp->box_btn_tag, FALSE, FALSE, 0);
                    gtk_box_pack_start(GTK_BOX(tmp->box_btn_tag), tmp->button_add_tag, FALSE, FALSE, 0);
                    gtk_box_pack_start(GTK_BOX(tmp->box_btn_tag), tmp->button_remove_tag, FALSE, FALSE, 0);
                    

//PLACEMENT 
    //Window
    gtk_window_set_title (GTK_WINDOW (tmp->window), "Modifier la vidéo"); //Nomme la fenêtre 
    gtk_window_set_default_size ( GTK_WINDOW (tmp->window), 30, 30 ) ; 
    gtk_window_unmaximize (GTK_WINDOW (tmp->window));
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );

    //Video
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_time_deb), 800) ; 
    
    //Sep
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->sep), 10) ; 
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->sep), 5) ; 

    //Titre video
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->label_title_video), 10) ; 
    //gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->label_title_tag), 5) ; 
    //gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->label_title_an), 5) ; 

    gtk_widget_set_margin_top (GTK_WIDGET (tmp->label_title_video), 10) ; 
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->label_title_tag), 30) ; 
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->label_title_an), 10) ; 
    
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->frame_tool_an), 35) ; 
    
  /*  gtk_widget_set_margin_top (GTK_WIDGET (tmp->label_test), 10);
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->label_test), 10);
    
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->label_test2), 10);
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->label_test2), 10);
    */
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->grid_tool_an), 5);
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->grid_tool_an), 5);
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->grid_tool_an), 5);
    
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->scroll_tag), 5);
    
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->box_tool_video), 325);

    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_title_video), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_title_tag), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_title_an), GTK_ALIGN_START ) ;


    /*
    gtk_widget_set_size_request (GTK_WIDGET (tmp->scroll_an), 20, 20) ;
    gtk_widget_set_size_request (GTK_WIDGET (tmp->label_test), 20, 20) ;
    */
    return tmp ;

}

void modif_win_show( modif_win_t* tmp ) {

    gtk_widget_show (tmp->window);
    gtk_widget_show_all (tmp->box_principale);

}


void modif_win_del ( modif_win_t* w ) {
    free ( w ) ;
}

