#include <stdlib.h>
#include "win_camera.h" 

camera_win_t* camera_win_new() {
    
    camera_win_t* tmp ; 
    tmp = malloc ( sizeof(camera_win_t) ) ; 

    //DECLARATION VARIABLES 
    tmp->cnt_modif_name = 0 ; 
    tmp->cnt_modif_model = 0 ; 
    tmp->cnt_modif_serial = 0 ; 
    tmp->cnt_modif_type = 0 ; 
    tmp->cnt_modif_description = 0 ; 
    //CREATION WIDGET  
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL) ; 
    tmp->box_principal = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0 ) ; 
   
    tmp->box_up = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0) ;
    tmp->box_down = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0) ; 
    tmp->box_left = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0) ;
    tmp->box_middle = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0) ;
    tmp->box_right = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0) ;

    
    tmp->label_title = gtk_label_new ("Caméra") ;
    tmp->label_name = gtk_label_new ("Nom") ;
    tmp->label_model = gtk_label_new ("Modèle") ;
    tmp->label_serial = gtk_label_new ("N° Série") ;
    tmp->label_type = gtk_label_new ("Type") ;
    tmp->label_description = gtk_label_new ("Description") ;
   
    tmp->entry_name = gtk_entry_new() ; 
    tmp->entry_model = gtk_entry_new() ; 
    tmp->entry_serial = gtk_entry_new() ; 
    tmp->entry_type = gtk_entry_new() ; 
    tmp->entry_description = gtk_entry_new() ; 

    //Buttons 
    tmp->img_btn_modify_name_modif = gtk_image_new_from_file ("/usr/share/beeterface/images/modif.png") ; 
    tmp->img_btn_modify_name_ok = gtk_image_new_from_file ("/usr/share/beeterface/images/ok.png") ; 
    tmp->btn_modify_name = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->btn_modify_name), tmp->img_btn_modify_name_modif) ;

    g_object_ref (tmp->img_btn_modify_name_modif);
    g_object_ref (tmp->img_btn_modify_name_ok);
    

    tmp->img_btn_modify_model_modif = gtk_image_new_from_file ("/usr/share/beeterface/images/modif.png") ; 
    tmp->img_btn_modify_model_ok = gtk_image_new_from_file ("/usr/share/beeterface/images/ok.png") ; 
    tmp->btn_modify_model = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->btn_modify_model), tmp->img_btn_modify_model_modif) ; 


    g_object_ref (tmp->img_btn_modify_model_modif);
    g_object_ref (tmp->img_btn_modify_model_ok);
    
    tmp->img_btn_modify_serial_modif = gtk_image_new_from_file ("/usr/share/beeterface/images/modif.png") ; 
    tmp->img_btn_modify_serial_ok = gtk_image_new_from_file ("/usr/share/beeterface/images/ok.png") ; 
    tmp->btn_modify_serial = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->btn_modify_serial), tmp->img_btn_modify_serial_modif) ; 


    g_object_ref (tmp->img_btn_modify_serial_modif);
    g_object_ref (tmp->img_btn_modify_serial_ok);
    
    tmp->img_btn_modify_type_modif = gtk_image_new_from_file ("/usr/share/beeterface/images/modif.png") ; 
    tmp->img_btn_modify_type_ok = gtk_image_new_from_file ("/usr/share/beeterface/images/ok.png") ; 
    tmp->btn_modify_type = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->btn_modify_type), tmp->img_btn_modify_type_modif) ; 


    g_object_ref (tmp->img_btn_modify_type_modif);
    g_object_ref (tmp->img_btn_modify_type_ok);
    

    tmp->img_btn_modify_description_modif = gtk_image_new_from_file ("/usr/share/beeterface/images/modif.png") ; 
    tmp->img_btn_modify_description_ok = gtk_image_new_from_file ("/usr/share/beeterface/images/ok.png") ; 
    tmp->btn_modify_description = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->btn_modify_description), tmp->img_btn_modify_description_modif) ; 


    g_object_ref (tmp->img_btn_modify_description_modif);
    g_object_ref (tmp->img_btn_modify_description_ok);
    
    //RANGEMENT 
    //Window
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal) ; 
    
        //Box principale 
        gtk_box_pack_start (GTK_BOX(tmp->box_principal), tmp->box_up, TRUE, TRUE, 0);
        gtk_box_pack_start (GTK_BOX(tmp->box_principal), tmp->box_down, TRUE, TRUE, 0);
            
            //Box Up
            gtk_box_pack_start (GTK_BOX(tmp->box_up), tmp->label_title, TRUE, TRUE, 0) ;
            //Box Down 
            gtk_box_pack_start (GTK_BOX(tmp->box_down), tmp->box_left, TRUE, TRUE, 0) ;
            gtk_box_pack_start (GTK_BOX(tmp->box_down), tmp->box_middle, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_down), tmp->box_right, TRUE, TRUE, 0) ; 

                //Box Left 
                gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_name, TRUE, TRUE, 0) ; 
                gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_model, TRUE, TRUE, 0) ; 
                gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_serial, TRUE, TRUE, 0) ; 
                gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_type, TRUE, TRUE, 0) ; 
                gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_description, TRUE, TRUE, 0) ; 

            //Box Middle
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_name, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_model, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_serial, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_type, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_description, TRUE, TRUE, 0) ; 

            //Bow Right 
            gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->btn_modify_name, TRUE, TRUE, 0) ;
            gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->btn_modify_model, TRUE, TRUE, 0) ;
            gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->btn_modify_serial, TRUE, TRUE, 0) ;
            gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->btn_modify_type, TRUE, TRUE, 0) ;
            gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->btn_modify_description, TRUE, TRUE, 0) ;

    //AUTRE
    gtk_window_set_title ( GTK_WINDOW (tmp->window), "Camera") ;
    gtk_window_set_default_size ( GTK_WINDOW (tmp->window), 30, 30 ) ; 
    gtk_window_unmaximize (GTK_WINDOW (tmp->window));
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );

    gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_name), 10 ) ;
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_model), 10 ) ;
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_serial), 10 ) ;
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_type), 10 ) ;
    gtk_widget_set_margin_end (GTK_WIDGET (tmp->label_description), 10 ) ;
 
    gtk_widget_set_margin_bottom (GTK_WIDGET (tmp->label_title), 10) ; 

    gtk_widget_set_halign (GTK_WIDGET (tmp->label_name), GTK_ALIGN_START) ;
    gtk_widget_set_halign (GTK_WIDGET (tmp->label_model), GTK_ALIGN_START) ;
    gtk_widget_set_halign (GTK_WIDGET (tmp->label_serial), GTK_ALIGN_START) ;
    gtk_widget_set_halign (GTK_WIDGET (tmp->label_type), GTK_ALIGN_START) ;
    gtk_widget_set_halign (GTK_WIDGET (tmp->label_description), GTK_ALIGN_START) ;

    
    return tmp ; 
}

void camera_win_show ( camera_win_t* nemo ) {
    gtk_widget_show ( nemo->window ) ; 
    gtk_widget_show_all ( nemo->box_principal ) ; 
}

void camera_win_del ( camera_win_t* nemo ) {
    free ( nemo ) ;
    g_object_unref (nemo->img_btn_modify_name_modif);
    g_object_unref (nemo->img_btn_modify_name_ok);

    g_object_unref (nemo->img_btn_modify_model_modif);
    g_object_unref (nemo->img_btn_modify_model_ok);

    g_object_unref (nemo->img_btn_modify_serial_modif);
    g_object_unref (nemo->img_btn_modify_serial_ok);

    g_object_unref (nemo->img_btn_modify_type_modif);
    g_object_unref (nemo->img_btn_modify_type_ok);

    g_object_unref (nemo->img_btn_modify_description_modif);
    g_object_unref (nemo->img_btn_modify_description_ok);
}
