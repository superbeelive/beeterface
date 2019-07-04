#include <stdlib.h>
#include "win_cut.h"

cut_win_t* cut_win_new() { 

    cut_win_t* tmp ; 
    tmp = malloc ( sizeof(cut_win_t) ) ; 
     
   //CREATION
   tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

   //box
   tmp->box_principal = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
   tmp->box_left = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
   tmp->box_right = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);

   tmp->box_video = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
   tmp->box_time = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
   tmp->box_label_time = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
   tmp->box_def_timed = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
   tmp->box_def_timef = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
   tmp->box_quit = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
   
   tmp->label_time_start = gtk_label_new("0:00") ; 
   tmp->label_time_end = gtk_label_new("4:30") ; 

   tmp->label_def_timed = gtk_label_new("Début") ; 
   tmp->label_def_timef = gtk_label_new("Fin") ;
   tmp->label_timed = gtk_label_new("0:05") ;
   tmp->label_timef = gtk_label_new("3:00") ;

   tmp->btn_timed = gtk_button_new_with_label("Deb") ; 
   tmp->btn_timef = gtk_button_new_with_label("Fin") ; 

   tmp->btn_enr = gtk_button_new_with_label("Enregistrer") ; 
   tmp->btn_ann = gtk_button_new_with_label("Quitter") ;

   tmp->adjustement_tmp = gtk_adjustment_new (10,0,500,1,1,2);
   tmp->scale_tmp = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL,tmp->adjustement_tmp);
    
   tmp->img_ex_video = gtk_image_new_from_file ("/usr/share/beeterface/images/video_bee.jpg");


   //RANGEMENT
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal);
    gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_left,  FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(tmp->box_principal), tmp->box_right,  FALSE, FALSE, 0);
    
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_video,  TRUE, TRUE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_video), tmp->img_ex_video,  TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_time,  FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_time), tmp->scale_tmp,  FALSE, FALSE, 0);
        gtk_box_pack_start(GTK_BOX(tmp->box_left), tmp->box_label_time,  FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_label_time), tmp->label_time_start,  FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_label_time), tmp->label_time_end,  FALSE, FALSE, 0);

        gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_def_timed,  FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_def_timed), tmp->btn_timed,  FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_def_timed), tmp->label_def_timed,  FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_def_timed), tmp->label_timed,  FALSE, FALSE, 0);
        
        gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_def_timef,  FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_def_timef), tmp->btn_timef,  FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_def_timef), tmp->label_def_timef,  FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_def_timef), tmp->label_timef,  FALSE, FALSE, 0);
        
        gtk_box_pack_start(GTK_BOX(tmp->box_right), tmp->box_quit,  FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_quit), tmp->btn_ann,  FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(tmp->box_quit), tmp->btn_enr,  FALSE, FALSE, 0);
            
   //PLACEMENT 
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );
    gtk_window_set_title (GTK_WINDOW (tmp->window), "Couper"); 


    return tmp ; 
}

void cut_win_show ( cut_win_t* tmp ) {

    gtk_widget_show ( tmp->window ) ; 
    gtk_widget_show_all ( tmp->box_principal ) ; 
}

void cut_win_del ( cut_win_t* tmp ) {
    free ( tmp ) ;
}
