#include <stdlib.h>

#include "win_modif.h"



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
    tmp->box_meta = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);       
    
    tmp->box_scroll_an = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);       
    tmp->box_scroll_tag = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);       
    
    tmp->box_text_an = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);       
    tmp->box_text_tag = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);       
    tmp->box_text_meta = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);       
    
    //FRAME
    tmp->frame_tool_an = gtk_frame_new ("Boîte à Outils") ;  
    tmp->frame_an = gtk_frame_new ("Annotations") ;  
    tmp->frame_tag = gtk_frame_new ("Tags") ;  
    tmp->frame_meta = gtk_frame_new ("Informations Vidéo") ;  
    
    //SCROLL
    tmp->scroll_an = gtk_scrolled_window_new (NULL, NULL) ; 
    tmp->scroll_tag = gtk_scrolled_window_new (NULL, NULL) ; 
    tmp->scroll_meta = gtk_scrolled_window_new (NULL, NULL) ; 


    //GRID
    tmp->grid_tool_video = gtk_grid_new() ;
    tmp->grid_tool_an = gtk_grid_new() ; 
    tmp->grid_meta = gtk_grid_new() ; 

    //IMAGE 
    tmp->img_video = gtk_image_new_from_file ("/usr/share/beeterface/images/video_bee.jpg");
    
    //LABEL
    tmp->label_title_video = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(tmp->label_title_video), "<span foreground=\"black\" font=\"16\">Nom de la vidéo</span>");


    tmp->label_time_deb = gtk_label_new("0:00");
    tmp->label_time_fin = gtk_label_new("2:30");
    tmp->label_test = gtk_label_new ("Je suis un test de texte bonjour.\ntest \ntest \ntest \ntest") ; 
    tmp->label_test2 = gtk_label_new ("Je suis un test de texte bonjour.\ntest \ntest \ntest \ntest") ; 


        //meta
    tmp->label_info_name_ruche = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_name_ruche), "<span foreground=\"black\" font=\"10\"><b>Nom Ruche   </b> </span>");
    tmp->label_info_description = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_description), "<span foreground=\"black\" font=\"10\"><b>Description   </b></span>");
    tmp->label_info_camera = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_camera), "<span foreground=\"black\" font=\"10\"><b>Camera   </b></span>");
    tmp->label_info_nruche = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_nruche), "<span foreground=\"black\" font=\"10\"><b>Num de Ruche   </b></span>");
    tmp->label_info_ncadre = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_ncadre), "<span foreground=\"black\" font=\"10\"><b>Num de Cadre   </b></span>");

    tmp->label_name_ruche = gtk_label_new("Zbeub  ") ; 
    tmp->label_description = gtk_label_new("Ficus des neiges  ") ; 
    tmp->label_camera = gtk_label_new("Big Brother  ") ; 
    tmp->label_nruche = gtk_label_new("Maya  ") ; 
    tmp->label_ncadre = gtk_label_new("L'abeille  ") ; 


    //BUTTONS 

    tmp->button_add_tag = gtk_button_new_with_label ("Ajouter") ;
    tmp->button_remove_tag = gtk_button_new_with_label ("Retirer") ;


    tmp->btn_an_cross = gtk_button_new_with_label ("Croix");
    tmp->btn_an_circle = gtk_button_new_with_label ("Cercle");
    tmp->btn_an_oblong = gtk_button_new_with_label ("Rectangle");
    tmp->btn_an_arrow = gtk_button_new_with_label ("Flèche");
    tmp->btn_an_moving_cross = gtk_button_new_with_label ("Croix Mouv.");
    
    tmp->btn_an_measure = gtk_button_new_with_label ("Mesure");
    tmp->btn_an_text = gtk_button_new_with_label ("Texte");
    //Version des bouton an avec images
    /*tmp->btn_an_cross = gtk_button_new ();
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
    */

    
        //Boutons du bas édition vidéo
    tmp->btn_cut = gtk_button_new_with_label ("Couper") ;  
    tmp->btn_play = gtk_button_new_with_label ("Play") ;  
    tmp->btn_av = gtk_button_new_with_label ("Avancer") ;  
    tmp->btn_rec = gtk_button_new_with_label ("Reculer") ;  

    tmp->btn_enr = gtk_button_new_with_label ("Enregistrer") ;  
    tmp->btn_ann = gtk_button_new_with_label ("Annuler") ;  

    //SEPARATOR 
    tmp->sep = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL) ; 
    tmp->sep2 = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL) ; 

    //OTHER WIDGET 
    tmp->adjustement_barre_temps = gtk_adjustment_new (10,0,500,1,1,2);
    tmp->barre_temps = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL,tmp->adjustement_barre_temps);



//RANGEMENT
//Fenetre
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principale);

        //box_principale
        gtk_box_pack_start(GTK_BOX(tmp->box_principale), tmp->box_left,  FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_principale), tmp->sep, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_principale), tmp->box_right, FALSE, FALSE, 0);
       
            //box_left       
            gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_video, TRUE, TRUE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_time, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_label_time, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_tool_video, FALSE, FALSE, 0);
              
                //box_video
                gtk_box_pack_start(GTK_BOX(tmp->box_video), tmp->label_title_video, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_video), tmp->img_video, TRUE, TRUE, 0);

                //box_time
                gtk_box_pack_start(GTK_BOX(tmp->box_time), tmp->barre_temps, TRUE, TRUE, 0);
                        
                //box_label_time
                gtk_box_pack_start(GTK_BOX(tmp->box_label_time), tmp->label_time_deb, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_label_time), tmp->label_time_fin, FALSE, FALSE, 0);

                //box_tool_video
                gtk_box_pack_start(GTK_BOX(tmp->box_tool_video), tmp->btn_cut, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_tool_video), tmp->btn_play, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_tool_video), tmp->btn_av, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_tool_video), tmp->btn_rec, FALSE, FALSE, 0);


            //box_right
            gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_tool_an, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_an, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_tag, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_meta, FALSE, FALSE, 0);
              
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

                //box_an
                gtk_box_pack_start(GTK_BOX(tmp->box_an), tmp->frame_an, FALSE, FALSE, 0);
                    gtk_container_add (GTK_CONTAINER (tmp->frame_an), tmp->box_scroll_an);
                gtk_box_pack_start(GTK_BOX(tmp->box_scroll_an), tmp->scroll_an, FALSE, FALSE, 0);
                    gtk_container_add (GTK_CONTAINER (tmp->scroll_an), tmp->box_text_an);
                gtk_box_pack_start(GTK_BOX(tmp->box_text_an), tmp->label_test, FALSE, FALSE, 0);

                
                //box_tag 
                gtk_box_pack_start(GTK_BOX(tmp->box_tag), tmp->frame_tag, FALSE, FALSE, 0) ;
                    gtk_container_add (GTK_CONTAINER (tmp->frame_tag), tmp->box_scroll_tag) ;
                gtk_box_pack_start(GTK_BOX(tmp->box_scroll_tag), tmp->scroll_tag, FALSE, FALSE, 0) ;
                    gtk_container_add (GTK_CONTAINER (tmp->scroll_tag), tmp->box_text_tag) ;
                gtk_box_pack_start(GTK_BOX(tmp->box_text_tag), tmp->label_test2, FALSE, FALSE, 0);

                //box_meta 
                gtk_box_pack_start(GTK_BOX(tmp->box_meta), tmp->frame_meta, FALSE, FALSE, 0) ;
                    gtk_container_add (GTK_CONTAINER (tmp->frame_meta), tmp->grid_meta) ;
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_info_name_ruche, 1, 1, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_info_description, 1, 2, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_info_camera, 1, 3, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_info_nruche, 1, 4, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_info_ncadre, 1, 5, 1, 1) ;  
                 
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_name_ruche, 2, 1, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_description, 2, 2, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_camera, 2, 3, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_nruche, 2, 4, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_ncadre, 2, 5, 1, 1) ;  


//PLACEMENT 
    //Window
    gtk_window_set_title (GTK_WINDOW (tmp->window), "Modifier la vidéo"); //Nomme la fenêtre 
    gtk_window_set_default_size ( GTK_WINDOW (tmp->window), 30, 30 ) ; 
    gtk_window_unmaximize (GTK_WINDOW (tmp->window));
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );

    //Sep
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->sep), 10) ; 
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->sep), 5) ; 
    
    //Video time
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_time_deb), 800) ; 
    
    //Titre video
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->label_title_video), 10) ; 
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->label_title_video), 10) ; 
   
    //Tool video
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->btn_cut), 250) ; 


    //Tool an
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->box_tool_an), 40) ; 

    gtk_widget_set_margin_start (GTK_WIDGET (tmp->grid_tool_an), 2);
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->grid_tool_an), 2);
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->grid_tool_an), 2);
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->grid_tool_an), 2);
    
    //Tag
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->scroll_tag), 2);
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->scroll_tag), 2);
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->scroll_tag), 2);
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->scroll_tag), 2);
    
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->box_tag), 5);

    //An
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->box_an), 5);

    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->scroll_an), 2);
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->scroll_an), 2);
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->scroll_an), 2);
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->scroll_an), 2);

    //Grid Meta
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->box_meta), 5);

    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_name_ruche), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_description), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_camera), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_nruche), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_ncadre), GTK_ALIGN_START ) ;

    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_name_ruche), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_description), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_camera), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_nruche), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_ncadre), GTK_ALIGN_START ) ;
    
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->grid_meta), 5 ) ;
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->grid_meta), 5 ) ;
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->grid_meta), 5 ) ;
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->grid_meta), 5 ) ; 
    
    return tmp ;

}

void modif_win_show( modif_win_t* tmp ) {

    gtk_widget_show (tmp->window);
    gtk_widget_show_all (tmp->box_principale);

}


void modif_win_del ( modif_win_t* w ) {
    free ( w ) ;
}

