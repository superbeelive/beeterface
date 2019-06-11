#include <stdlib.h>
#include "video_win.h" 

video_win_t* video_win_new() {
    
    video_win_t* tmp ; 
    tmp = malloc ( sizeof(video_win_t) ) ; 

    //DECLARATION VARIABLES 
    tmp->cnt_modif_name_ruche = 0 ; 
    
    //CREATION WIDGET  
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL) ; 
    tmp->box_principal = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0 ) ; 
    
    tmp->box_up = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0) ;
    tmp->box_down = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0) ; 
    tmp->box_left = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0) ;
    tmp->box_middle = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0) ;
    tmp->box_right = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0) ;

    tmp->label_name_video = gtk_label_new ("Nom_de_la_video") ; 

    tmp->label_name_ruche = gtk_label_new ("Nom Ruche") ; 
    tmp->label_n_ruche = gtk_label_new ("Numéro de Ruche") ; 
    tmp->label_n_cadre = gtk_label_new ("Numéro de Cadre") ; 
    tmp->label_description = gtk_label_new ("Description") ; 
    tmp->label_date = gtk_label_new ("Date") ; 
    tmp->label_auteur = gtk_label_new ("Auteur") ; 
    tmp->label_camera = gtk_label_new ("Camera") ; 

    tmp->entry_name_ruche = gtk_entry_new() ;  
    tmp->entry_n_ruche = gtk_entry_new() ;  
    tmp->entry_n_cadre = gtk_entry_new() ;  
    tmp->entry_description = gtk_entry_new() ;  
    tmp->entry_date = gtk_entry_new() ;  
    tmp->entry_auteur = gtk_entry_new() ;  
    tmp->entry_camera = gtk_entry_new() ;  
    
    //Buttons
    tmp->img_btn_modify_name_ruche_modif = gtk_image_new_from_file ("images/modif.png") ; 
    tmp->img_btn_modify_name_ruche_ok = gtk_image_new_from_file ("images/ok.png") ; 
    tmp->btn_modify_name_ruche = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->btn_modify_name_ruche), tmp->img_btn_modify_name_ruche_modif) ;
   
    g_object_ref (tmp->img_btn_modify_name_ruche_modif);
    g_object_ref (tmp->img_btn_modify_name_ruche_ok);
    
    tmp->img_btn_modify_n_ruche_modif = gtk_image_new_from_file ("images/modif.png") ; 
    tmp->img_btn_modify_n_ruche_ok = gtk_image_new_from_file ("images/ok.png") ; 
    tmp->btn_modify_n_ruche = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->btn_modify_n_ruche), tmp->img_btn_modify_n_ruche_modif) ;

    g_object_ref (tmp->img_btn_modify_n_ruche_modif);
    g_object_ref (tmp->img_btn_modify_n_ruche_ok);
    
    tmp->img_btn_modify_n_cadre_modif = gtk_image_new_from_file ("images/modif.png") ; 
    tmp->img_btn_modify_n_cadre_ok = gtk_image_new_from_file ("images/ok.png") ; 
    tmp->btn_modify_n_cadre = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->btn_modify_n_cadre), tmp->img_btn_modify_n_cadre_modif) ;

    g_object_ref (tmp->img_btn_modify_n_cadre_modif);
    g_object_ref (tmp->img_btn_modify_n_cadre_ok);
    
    tmp->img_btn_modify_description_modif = gtk_image_new_from_file ("images/modif.png") ; 
    tmp->img_btn_modify_description_ok = gtk_image_new_from_file ("images/ok.png") ; 
    tmp->btn_modify_description = gtk_button_new() ; 
    gtk_button_set_image (GTK_BUTTON (tmp->btn_modify_description), tmp->img_btn_modify_description_modif) ;

    g_object_ref (tmp->img_btn_modify_description_modif);
    g_object_ref (tmp->img_btn_modify_description_ok);
    
    
    //RANGEMENT 
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal) ; 

    //Box principale
    gtk_box_pack_start (GTK_BOX(tmp->box_principal), tmp->box_up, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX(tmp->box_principal), tmp->box_down, TRUE, TRUE, 0);
        //Box Up
        gtk_box_pack_start (GTK_BOX(tmp->box_up), tmp->label_name_video, TRUE, TRUE, 0) ;
        //Box Down
        gtk_box_pack_start (GTK_BOX(tmp->box_down), tmp->box_left, TRUE, TRUE, 0) ;
        gtk_box_pack_start (GTK_BOX(tmp->box_down), tmp->box_middle, TRUE, TRUE, 0) ; 
        gtk_box_pack_start (GTK_BOX(tmp->box_down), tmp->box_right, TRUE, TRUE, 0) ; 

            //Box Left
            gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_name_ruche, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_n_ruche, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_n_cadre, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_description, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_date, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_auteur, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_camera, TRUE, TRUE, 0) ; 

            //Box Middle

            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_name_ruche, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_n_ruche, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_n_cadre, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_description, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_date, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_auteur, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_middle), tmp->entry_camera, TRUE, TRUE, 0) ; 

            //Box Right

            gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->btn_modify_name_ruche, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->btn_modify_n_ruche, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->btn_modify_n_cadre, TRUE, TRUE, 0) ; 
            gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->btn_modify_description, TRUE, TRUE, 0) ; 
    //AUTRE
    gtk_window_set_title ( GTK_WINDOW (tmp->window), "Vidéo") ;

    return tmp ; 
}

void video_win_show ( video_win_t* nemo ) {
    gtk_widget_show ( nemo->window ) ; 
    gtk_widget_show_all ( nemo->box_principal ) ; 
}

void video_win_del ( video_win_t* nemo ) {
    free ( nemo ) ;
    g_object_unref (nemo->img_btn_modify_name_ruche_modif);
    g_object_unref (nemo->img_btn_modify_name_ruche_ok);

    g_object_unref (nemo->img_btn_modify_n_ruche_modif);
    g_object_unref (nemo->img_btn_modify_n_ruche_ok);

    g_object_unref (nemo->img_btn_modify_n_cadre_modif);
    g_object_unref (nemo->img_btn_modify_n_cadre_ok);

    g_object_unref (nemo->img_btn_modify_description_modif);
    g_object_unref (nemo->img_btn_modify_description_ok);

}
