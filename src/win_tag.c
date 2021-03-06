#include <stdlib.h>
#include "win_tag.h"


tag_win_t* tag_win_new() {
    
    tag_win_t* tmp ; 
    tmp = malloc ( sizeof(tag_win_t) ) ; 
    
    //DECLARATION DES VARIABLES 
    tmp->cnt_edit = 0 ;

    //CREATION WIDGET / CONTAINER 
    //Window Definition
    tmp->window = gtk_window_new (GTK_WINDOW_TOPLEVEL) ; 
   
    gtk_window_set_title ( GTK_WINDOW (tmp->window), "Tag") ;
    gtk_window_set_default_size ( GTK_WINDOW (tmp->window), 50, 70 ) ; 
    gtk_window_unmaximize (GTK_WINDOW (tmp->window));
    gtk_container_set_border_width (GTK_CONTAINER (tmp->window), 10 );
    
    tmp->box_principal = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0 ) ; 
    tmp->box_up = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0 ) ; 
    tmp->box_down = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0 ) ; 
    tmp->box_btn = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0 ) ; 
    tmp->box_tag = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0 ) ; 
    tmp->box_text_tag = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0 ) ; 
    tmp->box_scroll_tag = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0 ) ; 
    tmp->box_left = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0 ) ; 
    tmp->box_right = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0 ) ; 
    tmp->box_tag_dispo = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0 ) ; 
  
    tmp->frame_tag = gtk_frame_new ("Bibliothèque de Tags") ;  
 
    tmp->scroll = gtk_scrolled_window_new (NULL, NULL) ; 
    //search
    tmp->search = gtk_search_entry_new() ; 
    
    tmp->label_test = gtk_label_new ("Je suis un test de texte bonjour.\ntest \ntest \ntest \ntest") ; 
    tmp->label_test3 = gtk_label_new ("Je suis un test de texte bonjour.\ntest \ntest \ntest \ntest") ; 
    tmp->label_tag_dispo = gtk_label_new ("Tag(s) ajouté(s) : ") ; 
    tmp->label_search = gtk_label_new ("Chercher un Tag : ") ; 

    
    //btn 
    tmp->btn_tag = gtk_button_new_with_label ("Chercher") ; 
    tmp->btn_create_tag = gtk_button_new_with_label ("Créer") ; 
    tmp->btn_ann = gtk_button_new_with_label ("Annuler") ; 
    tmp->btn_enr = gtk_button_new_with_label ("Enregistrer") ; 

    tmp->sep = gtk_separator_new(GTK_ORIENTATION_VERTICAL) ; 

    tmp->text_tag_list = gtk_text_view_new() ; 
    tmp->buffer_tag_list = gtk_text_view_get_buffer(GTK_TEXT_VIEW (tmp->text_tag_list)) ;
    gtk_text_buffer_set_text (tmp->buffer_tag_list, "Elem1, elem2, ele3, elem4 ..." ,-1) ; 
    g_object_set(tmp->text_tag_list,"editable", FALSE, NULL) ;

    //RANGEMENT
    gtk_container_add (GTK_CONTAINER (tmp->window), tmp->box_principal) ; 
        //Box Principale
        gtk_box_pack_start (GTK_BOX(tmp->box_principal), tmp->box_up, FALSE, FALSE, 0);
        gtk_box_pack_start (GTK_BOX(tmp->box_principal), tmp->box_down, TRUE, TRUE, 0);
        gtk_box_pack_start (GTK_BOX(tmp->box_principal), tmp->box_btn, FALSE, FALSE, 0);
        
            //Box_up 
            gtk_box_pack_start (GTK_BOX(tmp->box_up), tmp->label_search, FALSE, FALSE, 0);
            gtk_box_pack_start (GTK_BOX(tmp->box_up), tmp->search, FALSE, FALSE, 0);
            gtk_box_pack_start (GTK_BOX(tmp->box_up), tmp->btn_tag, FALSE, FALSE, 0);
            gtk_box_pack_start (GTK_BOX(tmp->box_up), tmp->btn_create_tag, FALSE, FALSE, 0);
        
            //Box_Down
            gtk_box_pack_start (GTK_BOX(tmp->box_down), tmp->box_tag, TRUE, TRUE, 0);
            gtk_box_pack_start (GTK_BOX(tmp->box_down), tmp->box_tag_dispo, FALSE, FALSE, 0);
                
                 //Box_tag
                 gtk_box_pack_start(GTK_BOX(tmp->box_tag), tmp->frame_tag, TRUE, TRUE, 0);
                        gtk_container_add (GTK_CONTAINER (tmp->frame_tag), tmp->box_scroll_tag);
                 gtk_box_pack_start(GTK_BOX(tmp->box_scroll_tag), tmp->scroll, TRUE, TRUE, 0);
                        gtk_container_add (GTK_CONTAINER (tmp->scroll), tmp->box_text_tag);
                 gtk_box_pack_start(GTK_BOX(tmp->box_text_tag), tmp->box_left, TRUE, TRUE, 0);
                 gtk_box_pack_start(GTK_BOX(tmp->box_text_tag), tmp->sep, FALSE, FALSE, 0);
                 gtk_box_pack_start(GTK_BOX(tmp->box_text_tag), tmp->box_right, TRUE, TRUE, 0);
            
                     //box_left 
                     gtk_box_pack_start (GTK_BOX(tmp->box_left), tmp->label_test, FALSE, FALSE, 0);
                     //box_right    
                     gtk_box_pack_start (GTK_BOX(tmp->box_right), tmp->label_test3, FALSE, FALSE, 0);

                //Box_tag_dispo
                 gtk_box_pack_start(GTK_BOX(tmp->box_tag_dispo), tmp->label_tag_dispo, FALSE, FALSE, 0);
                 gtk_box_pack_start(GTK_BOX(tmp->box_tag_dispo), tmp->text_tag_list, FALSE, FALSE, 0);


            //box_btn 
            gtk_box_pack_start (GTK_BOX(tmp->box_btn), tmp->btn_ann, FALSE, FALSE, 0);
            gtk_box_pack_start (GTK_BOX(tmp->box_btn), tmp->btn_enr, FALSE, FALSE, 0);



    //PLACEMENT 
    gtk_widget_set_margin_end ( GTK_WIDGET (tmp->search), 5 ) ;
    gtk_widget_set_halign ( GTK_WIDGET (tmp->label_test), GTK_ALIGN_START ) ;
    gtk_widget_set_margin_top ( GTK_WIDGET (tmp->scroll), 10 ) ;
    gtk_widget_set_margin_bottom ( GTK_WIDGET (tmp->scroll), 5 ) ;

    gtk_widget_set_margin_end ( GTK_WIDGET (tmp->box_left), 10 ) ;
    

    gtk_widget_set_margin_top ( GTK_WIDGET (tmp->box_tag_dispo), 5) ;
    gtk_widget_set_margin_bottom ( GTK_WIDGET (tmp->box_tag_dispo), 5 ) ;

    gtk_widget_set_margin_start ( GTK_WIDGET (tmp->sep), 2 ) ;
    gtk_widget_set_margin_end ( GTK_WIDGET (tmp->sep), 2 ) ;

    gtk_widget_set_halign ( GTK_WIDGET (tmp->box_btn), GTK_ALIGN_END ) ;
        return tmp ; 
}

void tag_win_show ( tag_win_t* nemo ) {
    gtk_widget_show ( nemo->window ) ; 
    gtk_widget_show_all ( nemo->box_principal ) ; 
}


void tag_win_del ( tag_win_t* nemo ) {
    free ( nemo ) ;

}

