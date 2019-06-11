#include <stdlib.h>
#include <stdio.h>

#include "video_win.h"

    void video_win_fill( video_win_t* win, video_t* video ) {

    //Transforme int en char
    char buffer[10] ; 
    int value = video->nruche ; 
    sprintf ( buffer, "%d", value ) ;

    char buffer2[10] ; 
    int value2 = video->ncadre ; 
    sprintf ( buffer2, "%d", value2 ) ; 

    gtk_entry_set_text((GtkEntry*) win->entry_name_ruche, video->name_ruche ) ; 
    gtk_entry_set_text((GtkEntry*) win->entry_n_ruche, buffer ) ; 
    gtk_entry_set_text((GtkEntry*) win->entry_n_cadre, buffer2 ) ; 
    gtk_entry_set_text((GtkEntry*) win->entry_description, video->description ) ;
    //Intégrer nom complet / description cam 
    gtk_entry_set_text((GtkEntry*) win->entry_date, video->date ) ; 
    gtk_entry_set_text((GtkEntry*) win->entry_auteur, video->auteur->nom ) ; 
    gtk_entry_set_text((GtkEntry*) win->entry_camera, video->camera->name ) ; 
    
    
    g_object_set(win->entry_name_ruche,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_n_ruche,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_n_cadre,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_description,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_date,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_auteur,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_camera,"editable", FALSE, NULL) ; 
}
//name ruche
void video_button_modify_name_ruche_modif( video_win_t* win, video_t* video ) {
     
     win->cnt_modif_name_ruche = 1 ;
     
     gtk_entry_set_text((GtkEntry*) win->entry_name_ruche, video->name_ruche ) ; 
     g_object_set(win->entry_name_ruche,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_name_ruche), win->img_btn_modify_name_ruche_ok) ; 
}

void video_button_modify_name_ruche_ok ( video_win_t* win, video_t* video ) {
         
     win->cnt_modif_name_ruche = 0 ;
     sprintf(video->name_ruche,"%s", gtk_entry_get_text((GtkEntry*) win->entry_name_ruche ) ) ;
     g_object_set(win->entry_name_ruche,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_name_ruche), win->img_btn_modify_name_ruche_modif) ; 
}

//n_ruche
void video_button_modify_n_ruche_modif( video_win_t* win, video_t* video ) {
    
    char buffer[10] ; 
    int value = video->nruche ; 
    sprintf ( buffer, "%d", value ) ;
    
     win->cnt_modif_n_ruche = 1 ;
     
     gtk_entry_set_text((GtkEntry*) win->entry_n_ruche, buffer ) ; 
     g_object_set(win->entry_n_ruche,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_n_ruche), win->img_btn_modify_n_ruche_ok) ; 
}

void video_button_modify_n_ruche_ok ( video_win_t* win, video_t* video ) {
      
    char buffer[10] ; 
    int value = video->nruche ; 
    sprintf ( buffer, "%d", value ) ;    


     win->cnt_modif_n_ruche = 0 ;
     sprintf(buffer,"%s", gtk_entry_get_text((GtkEntry*) win->entry_n_ruche ) ) ;
     g_object_set(win->entry_n_ruche,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_n_ruche), win->img_btn_modify_n_ruche_modif) ; 
}

//n_cadre
void video_button_modify_n_cadre_modif( video_win_t* win, video_t* video ) {
    
    char buffer[10] ; 
    int value = video->ncadre ; 
    sprintf ( buffer, "%d", value ) ;
    
     win->cnt_modif_n_cadre = 1 ;
     
     gtk_entry_set_text((GtkEntry*) win->entry_n_cadre, buffer ) ; 
     g_object_set(win->entry_n_cadre,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_n_cadre), win->img_btn_modify_n_cadre_ok) ; 
}

void video_button_modify_n_cadre_ok ( video_win_t* win, video_t* video ) {
   
    //ATTENTION !!! Erreur de valeur 
    char buffer[10] ; 
    int value = video->ncadre ; 
    sprintf ( buffer, "%d", value ) ;
    
    win->cnt_modif_n_cadre = 0 ;
     sprintf(buffer,"%s", gtk_entry_get_text((GtkEntry*) win->entry_n_cadre ) ) ;
     g_object_set(win->entry_n_cadre,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_n_cadre), win->img_btn_modify_n_cadre_modif) ; 
}

//description
void video_button_modify_description_modif( video_win_t* win, video_t* video ) {
     
     win->cnt_modif_description = 1 ;
     
     gtk_entry_set_text((GtkEntry*) win->entry_description, video->description ) ; 
     g_object_set(win->entry_description,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_description), win->img_btn_modify_description_ok) ; 
}

void video_button_modify_description_ok ( video_win_t* win, video_t* video ) {
         
     win->cnt_modif_description = 0 ;
     sprintf(video->description,"%s", gtk_entry_get_text((GtkEntry*) win->entry_description ) ) ;
     g_object_set(win->entry_description,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_description), win->img_btn_modify_description_modif) ; 
}
