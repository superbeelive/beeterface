#include <stdlib.h>

#include "win_main.h"

main_win_t* main_win_new() {

    main_win_t* tmp ;
    tmp = malloc ( sizeof(main_win_t) ) ;

//CREATION    
    //Fenêtre principale 
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //BOITES 

    tmp->box_principal = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_up = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_down = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_left = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_right = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);

    tmp->box_video = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_btn_l = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);

    tmp->box_info = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_meta = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_btn_cam = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_btn_video = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_time = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_info_time = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_folder = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    

    //GRID
    tmp->grid_info = gtk_grid_new() ; 
    tmp->grid_meta = gtk_grid_new() ; 
   
    //OTHER BOX
    tmp->frame_info = gtk_frame_new("Information Capteurs") ; 
    tmp->frame_meta = gtk_frame_new("Information Vidéo") ; 

    //BOUTONS

    tmp->btn_enregistrer = gtk_button_new_with_label ("Enregistrer");

    tmp->btn_info = gtk_button_new_with_label ("Informations");

    tmp->btn_camera_more = gtk_button_new ();
    tmp->img_btn_camera_more = gtk_image_new_from_file ("/usr/share/beeterface/images/inter.png");
    gtk_button_set_image (GTK_BUTTON (tmp->btn_camera_more), tmp->img_btn_camera_more);

    tmp->btn_folder = gtk_button_new_with_label ("Ouvrir") ;

    //IMAGES  
    tmp->img_exemple = gtk_image_new_from_file ("/usr/share/beeterface/images/video_bee.jpg") ;
    tmp->img_live = gtk_image_new_from_file ("/usr/share/beeterface/images/enregistrer.png") ;

    //TEXTE 
    tmp->label_title = gtk_label_new("") ;
    gtk_label_set_markup(GTK_LABEL(tmp->label_title), "<span foreground=\"black\" font=\"16\">En live</span>");
    
    tmp->txt_trier_par = gtk_label_new("") ;
    gtk_label_set_markup(GTK_LABEL(tmp->txt_trier_par), "<span foreground=\"black\" font=\"10\">Trier par :</span>");

    tmp->txt_visualiser = gtk_label_new("") ;
    gtk_label_set_markup(GTK_LABEL(tmp->txt_visualiser), "<span foreground=\"black\" font=\"10\">Visualiser :</span>");

    tmp->label_time_beg = gtk_label_new("0:00") ;
    tmp->label_time_end = gtk_label_new("2:30") ;
    tmp->label_info = gtk_label_new("Status") ; 

    tmp->label_info_date = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_date), "<span foreground=\"black\" font=\"10\"><b>Date   </b></span>");
    tmp->label_info_heure = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_heure), "<span foreground=\"black\" font=\"10\"><b>Heure    </b></span>");
    tmp->label_info_temp_ruche = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_temp_ruche), "<span foreground=\"black\" font=\"10\"><b>Temp Ruche    </b></span>");
    tmp->label_info_temp_ext = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_temp_ext), "<span foreground=\"black\" font=\"10\"><b>Temp Ext   </b> </span>");
   

    tmp->label_date = gtk_label_new("ex_date") ; 
    tmp->label_heure = gtk_label_new("ex_heure") ; 
    tmp->label_temp_ruche = gtk_label_new("42°") ; 
    tmp->label_temp_ext = gtk_label_new("51°") ; 
  

    tmp->label_info_name_ruche = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_name_ruche), "<span foreground=\"black\" font=\"10\"><b>Nom Ruche   </b> </span>");
    tmp->label_info_description = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_description), "<span foreground=\"black\" font=\"10\"><b>Description   </b></span>");
    tmp->label_info_date = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_date), "<span foreground=\"black\" font=\"10\"><b>Date   </b></span>");
    tmp->label_info_auteur = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_auteur), "<span foreground=\"black\" font=\"10\"><b>Auteur   </b></span>");
    tmp->label_info_camera = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_camera), "<span foreground=\"black\" font=\"10\"><b>Camera   </b></span>");
    tmp->label_info_nruche = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_nruche), "<span foreground=\"black\" font=\"10\"><b>Num de Ruche   </b></span>");
    tmp->label_info_ncadre = gtk_label_new("") ; 
    gtk_label_set_markup(GTK_LABEL(tmp->label_info_ncadre), "<span foreground=\"black\" font=\"10\"><b>Num de Cadre   </b></span>");

    tmp->label_name_ruche = gtk_label_new("Zbeub  ") ; 
    tmp->label_description = gtk_label_new("Ficus des neiges  ") ; 
    tmp->label_auteur = gtk_label_new("Moi  ") ; 
    tmp->label_camera = gtk_label_new("Big Brother  ") ; 
    tmp->label_nruche = gtk_label_new("Maya  ") ; 
    tmp->label_ncadre = gtk_label_new("L'abeille  ") ; 

    //AUTRES 
    tmp->sep_part = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
    tmp->sep_haut = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
    tmp->sep_vid = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
    tmp->sep_fold = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);
    
    tmp->choix_camera = gtk_combo_box_text_new();
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_camera, 1,"Caméra n°1");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_camera, 2,"Caméra n°2");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_camera, 3,"Caméra n°3");

    tmp->choix_tri =  gtk_combo_box_text_new();
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_tri, 3,"Date");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_tri, 3,"Nom");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_tri, 3,"Tag");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) tmp->choix_tri, 3,"Caméra");
     
    
    tmp->level_bar_time = gtk_level_bar_new_for_interval ( 0, 100 ) ;    
    gtk_level_bar_add_offset_value (GTK_LEVEL_BAR(tmp->level_bar_time), "Milieu", 50 ) ; 
    gtk_level_bar_set_value (GTK_LEVEL_BAR(tmp->level_bar_time),50) ; 

//RANGEMENT
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal);
        //box principale 
        gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_up, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->sep_haut, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_down, FALSE, FALSE, 0);
       
            //box_up
            gtk_box_pack_start(GTK_BOX(tmp->box_up), tmp->img_live, FALSE, FALSE, 20);
            gtk_box_pack_start(GTK_BOX(tmp->box_up), tmp->label_title, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_up), tmp->btn_info, FALSE, FALSE, 0);
            
            //box_down
            gtk_box_pack_start(GTK_BOX(tmp->box_down), tmp->box_left, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_down), tmp->sep_part, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_down), tmp->box_right, FALSE, FALSE, 0);
        
                //box_left
                gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_video, FALSE, FALSE, 0);
                    //box_video
                    gtk_box_pack_start(GTK_BOX(tmp->box_video), tmp->img_exemple, FALSE, FALSE, 0);
  
                //box_right
                gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_info, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_meta, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_btn_cam, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->sep_vid, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_btn_video, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_time, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_info_time, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->sep_fold, FALSE, FALSE, 0);
                gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_folder, FALSE, FALSE, 0);


                  //Dans box_info
                  gtk_box_pack_start(GTK_BOX(tmp->box_info), tmp->frame_info, FALSE, FALSE, 0);
                  gtk_container_add (GTK_CONTAINER (tmp->frame_info), tmp->grid_info);

                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_info_date, 1, 1, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_info_heure, 1, 2, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_info_temp_ext, 1, 3, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_info_temp_ruche, 1, 4, 1, 1) ;  
                   
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_date, 2, 1, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_heure, 2, 2, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_temp_ext, 2, 3, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_info),tmp->label_temp_ruche, 2, 4, 1, 1) ;                  
                  
                  //box_meta
                  gtk_box_pack_start(GTK_BOX(tmp->box_meta), tmp->frame_meta, FALSE, FALSE, 0);
                  gtk_container_add (GTK_CONTAINER (tmp->frame_meta), tmp->grid_meta);
                  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_info_name_ruche, 1, 1, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_info_description, 1, 2, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_info_auteur, 1, 3, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_info_camera, 1, 4, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_info_nruche, 1, 5, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_info_ncadre, 1, 6, 1, 1) ;  
                 
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_name_ruche, 2, 1, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_description, 2, 2, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_auteur, 2, 3, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_camera, 2, 4, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_nruche, 2, 5, 1, 1) ;  
                  gtk_grid_attach(GTK_GRID (tmp->grid_meta),tmp->label_ncadre, 2, 6, 1, 1) ;  

                  //box_btn_cam
                  gtk_box_pack_start(GTK_BOX(tmp->box_btn_cam), tmp->txt_visualiser, FALSE, FALSE, 0);
                  gtk_box_pack_start(GTK_BOX(tmp->box_btn_cam), tmp->choix_camera, FALSE, FALSE, 0);
                  gtk_box_pack_start(GTK_BOX(tmp->box_btn_cam), tmp->btn_camera_more, FALSE, FALSE, 0);
                  
                  //box_btn_video
                  gtk_box_pack_start(GTK_BOX(tmp->box_btn_video), tmp->btn_enregistrer, FALSE, FALSE, 0);
                  gtk_box_pack_start(GTK_BOX(tmp->box_btn_video), tmp->label_info, FALSE, FALSE, 0);


                  //box_time
                  gtk_box_pack_start(GTK_BOX(tmp->box_time), tmp->level_bar_time, FALSE, FALSE, 0);
                  
                  //box_info_time
                  gtk_box_pack_start(GTK_BOX(tmp->box_info_time), tmp->label_time_beg, FALSE, FALSE, 0);
                  gtk_box_pack_start(GTK_BOX(tmp->box_info_time), tmp->label_time_end, FALSE, FALSE, 0);
                    
                  //box_folder
                  gtk_box_pack_start(GTK_BOX(tmp->box_folder), tmp->btn_folder, FALSE, FALSE, 0);



                  
 //PLACEMENT
    //Window
    gtk_window_set_title (GTK_WINDOW (tmp->window), "BEETERFACE"); //Nomme la fenêtre 
    gtk_window_set_default_size ( GTK_WINDOW (tmp->window), 30, 30 ) ; 
    gtk_window_unmaximize (GTK_WINDOW (tmp->window));
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );
   
    //box left
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->box_btn_cam), 5 ) ;
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->box_btn_cam), 5 ) ;
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->box_info), 20 ) ;
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->box_info), 5 ) ;
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->box_meta), 5 ) ;
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->box_meta), 5 ) ;
    
    //btn
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->btn_info), 800 ) ;


    //img_exemple
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->img_exemple), 5 ) ;
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->img_exemple), 5 ) ;
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->img_exemple), 5 ) ;
    
    //sep
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->sep_haut), 5 ) ;
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->sep_haut), 5 ) ;
    
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->sep_part), 5 ) ;
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->sep_part), 10 ) ;
    
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->sep_vid), 5 ) ;
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->sep_vid), 5 ) ;

    gtk_widget_set_margin_top (GTK_WIDGET (tmp->sep_fold), 5 ) ;
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->sep_fold), 5 ) ;
    
    //box_btn_cam
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->txt_visualiser), 5 ) ;
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->choix_camera), 5 ) ;
    

    //Grid info
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

    //Grid meta
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_name_ruche), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_description), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_auteur), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_camera), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_nruche), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_info_ncadre), GTK_ALIGN_START ) ;

    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_name_ruche), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_description), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_auteur), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_camera), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_nruche), GTK_ALIGN_START ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_ncadre), GTK_ALIGN_START ) ;
    
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->grid_meta), 5 ) ;
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->grid_meta), 5 ) ;
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->grid_meta), 5 ) ;
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->grid_meta), 5 ) ;

    //time
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_time_beg), 175 ) ;
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->level_bar_time), 5 ) ;
    gtk_widget_set_margin_top (GTK_WIDGET (tmp->level_bar_time), 5 ) ;
    gtk_widget_set_margin_start (GTK_WIDGET (tmp->label_info), 5 ) ;
    
    
    return tmp ;
}


void main_win_show ( main_win_t* tmp ) {  
 
    gtk_widget_show (tmp->window);
    gtk_widget_show_all (tmp->box_principal);

}

void main_win_del( main_win_t* W ) {
    free(W) ;
}
