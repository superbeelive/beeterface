#include <stdlib.h>
#include "win_cross.h" 

cross_win_t* cross_win_new() {
    cross_win_t* tmp ;
    tmp = malloc ( sizeof(cross_win_t) ) ;
   
    //CREATION
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //box
    tmp->box_principal = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    
    tmp->box_left = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    tmp->box_right = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    
    tmp->box_name = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_description = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_video = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_time = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_label_time = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_btn_video = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_def_time_deb = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_def_time_fin = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    
    tmp->box_tag = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_txt_tag = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_scroll_tag = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_tag = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_meta = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_text_meta = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    tmp->box_btn_quit = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    
    //frame
    tmp->frame_tag =  gtk_frame_new ("Tags") ;  
    tmp->frame_meta =  gtk_frame_new ("Informations") ;  

    //scroll 
    tmp->scroll_tag = gtk_scrolled_window_new (NULL, NULL) ; 

    //grid
    tmp->grid_meta = gtk_grid_new() ; 

    //label
    tmp->label_name = gtk_label_new("Nom :") ; 
    tmp->label_desc = gtk_label_new("Description :") ; 
    tmp->label_time_deb = gtk_label_new("0:00") ; 
    tmp->label_time_fin = gtk_label_new("2:30") ; 
    
    tmp->label_test = gtk_label_new("test \n test \n test \n test \n") ; 


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

    tmp->label_enr_timed = gtk_label_new("Début de l'annotation :") ; 
    tmp->label_enr_timef = gtk_label_new("Fin de l'annotation :") ; 

    tmp->label_timed = gtk_label_new("1:45") ; 
    tmp->label_timef = gtk_label_new("4:50") ; 
    //img
    tmp->img_ex_video = gtk_image_new_from_file ("/usr/share/beeterface/images/video_bee.jpg");

    //entry
    tmp->entry_name = gtk_entry_new() ; 

    //btn
    tmp->btn_name = gtk_button_new ();
        tmp->img_btn_ok_name =  gtk_image_new_from_file ("/usr/share/beeterface/images/modif.png");
        tmp->img_btn_mod_name =  gtk_image_new_from_file ("/usr/share/beeterface/images/ok.png");
        gtk_button_set_image (GTK_BUTTON (tmp->btn_name), tmp->img_btn_ok_name);
   
    tmp->btn_cut = gtk_button_new_with_label ("Couper") ;  
    tmp->btn_play = gtk_button_new_with_label ("Play") ;  
    tmp->btn_av = gtk_button_new_with_label ("Avancer") ;  
    tmp->btn_rec = gtk_button_new_with_label ("Reculer") ;  

    tmp->btn_enr = gtk_button_new_with_label ("Enregistrer") ;  
    tmp->btn_ann = gtk_button_new_with_label ("Annuler") ;  

    tmp->btn_enr_timed = gtk_button_new_with_label ("Deb") ;  
    tmp->btn_enr_timef = gtk_button_new_with_label ("Fin") ;  

    //other
    tmp->text_description = gtk_text_view_new() ; 
    tmp->buffer_description = gtk_text_view_get_buffer(GTK_TEXT_VIEW (tmp->text_description)) ;
    gtk_text_buffer_set_text (tmp->buffer_description, "Croix : croix à placer à un endroit sur la vidéo \n x et y définissent sa position. \n Cliquer sur la vidéo pour la placer.", -1) ; 
    g_object_set(tmp->text_description,"editable", FALSE, NULL) ;

    tmp->adj_time = gtk_adjustment_new (10,0,500,1,1,2);
    tmp->scale_time = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL,tmp->adj_time);



    //RANGEMENT 
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal);

    gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_left, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_right, FALSE, FALSE, 0);

        //box_left
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_name, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_video, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_time, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_label_time, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_btn_video, FALSE, FALSE, 0);
   
            //box_name
            gtk_box_pack_start(GTK_BOX(tmp->box_name), tmp->label_name, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_name), tmp->entry_name, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_name), tmp->btn_name, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_name), tmp->box_description, FALSE, FALSE, 0);
       
            //box_description
            gtk_box_pack_start(GTK_BOX(tmp->box_description), tmp->label_desc, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_description), tmp->text_description, FALSE, FALSE, 0);
           
            //box_video
            gtk_box_pack_start(GTK_BOX(tmp->box_video), tmp->img_ex_video, FALSE, FALSE, 0);
            
            //box_time
            gtk_box_pack_start(GTK_BOX(tmp->box_time), tmp->scale_time, TRUE, TRUE, 0);

            //box_label_time
            gtk_box_pack_start(GTK_BOX(tmp->box_label_time), tmp->label_time_deb, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_label_time), tmp->label_time_fin, FALSE, FALSE, 0);

            //box_btn_video
            gtk_box_pack_start(GTK_BOX(tmp->box_btn_video), tmp->btn_cut, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_btn_video), tmp->btn_play, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_btn_video), tmp->btn_av, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_btn_video), tmp->btn_rec, FALSE, FALSE, 0);

            
        //box_right
        gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_tag, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_meta, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_def_time_deb, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_def_time_fin, FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_btn_quit, FALSE, FALSE, 0);

            //box_tag 
            gtk_box_pack_start(GTK_BOX(tmp->box_tag), tmp->frame_tag, TRUE, TRUE, 0) ;
              gtk_container_add (GTK_CONTAINER (tmp->frame_tag), tmp->box_scroll_tag) ;
            gtk_box_pack_start(GTK_BOX(tmp->box_scroll_tag), tmp->scroll_tag, TRUE, TRUE, 0) ;
               gtk_container_add (GTK_CONTAINER (tmp->scroll_tag), tmp->box_txt_tag) ;
            gtk_box_pack_start(GTK_BOX(tmp->box_txt_tag), tmp->label_test, TRUE, TRUE, 0);

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

            //box_def_time_deb
            gtk_box_pack_start(GTK_BOX(tmp->box_def_time_deb), tmp->btn_enr_timed, FALSE, FALSE, 0) ;
            gtk_box_pack_start(GTK_BOX(tmp->box_def_time_deb), tmp->label_enr_timed, FALSE, FALSE, 0) ;
            gtk_box_pack_start(GTK_BOX(tmp->box_def_time_deb), tmp->label_timed, FALSE, FALSE, 0) ;
            
            //box_def_time_fin
            gtk_box_pack_start(GTK_BOX(tmp->box_def_time_fin), tmp->btn_enr_timef, FALSE, FALSE, 0) ;
            gtk_box_pack_start(GTK_BOX(tmp->box_def_time_fin), tmp->label_enr_timef, FALSE, FALSE, 0) ;
            gtk_box_pack_start(GTK_BOX(tmp->box_def_time_fin), tmp->label_timef, FALSE, FALSE, 0) ;

            //box_btn_quit
            gtk_box_pack_start(GTK_BOX(tmp->box_btn_quit), tmp->btn_enr, FALSE, FALSE, 0) ;
            gtk_box_pack_start(GTK_BOX(tmp->box_btn_quit), tmp->btn_ann, FALSE, FALSE, 0) ;
            

    //PLACEMENT 
    gtk_window_set_title (GTK_WINDOW (tmp->window), "Annotation : croix") ; 
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );



    //label_time
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_time_deb), 750) ;

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

void cross_win_show ( cross_win_t* tmp ) {
    gtk_widget_show ( tmp->window ) ;
    gtk_widget_show_all ( tmp->box_principal ) ; 
}

void cross_win_del ( cross_win_t* tmp ) { 
    free ( tmp ) ; 
}
