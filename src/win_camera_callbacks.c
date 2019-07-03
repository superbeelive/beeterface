#include <stdlib.h>
#include "camera.h"
#include "win_camera.h"

/* Function : camera_win_fill
Fill in the fields with camera's informations. 

Parameters :
    win - type : "camera_win_t". Package containing the useful pointers to use the camera window.
    camera - type "camera_t*". Package containing informations about the camera.
*/

void camera_win_fill( camera_win_t* win, camera_t* camera ) {

    gtk_entry_set_text((GtkEntry*) win->entry_name, camera->name ) ; 
    gtk_entry_set_text((GtkEntry*) win->entry_model, camera->model ) ; 
    gtk_entry_set_text((GtkEntry*) win->entry_serial, camera->serial );
    gtk_entry_set_text((GtkEntry*) win->entry_type, camera_type_to_string(camera->type) );
    gtk_entry_set_text((GtkEntry*) win->entry_description, camera->description );

    g_object_set(win->entry_name,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_model,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_serial, "editable", FALSE, NULL) ; 
    g_object_set(win->entry_type,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_description,"editable", FALSE, NULL) ; 
}
////name
void camera_button_modify_name_modif( camera_win_t* win, camera_t* camera ) {
     
     win->cnt_modif_name = 1 ;
     
     gtk_entry_set_text((GtkEntry*) win->entry_name, camera->name ) ; 
     g_object_set(win->entry_name,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_name), win->img_btn_modify_name_ok) ; 

}

void camera_button_modify_name_ok ( camera_win_t* win, camera_t* camera ) {
         
     win->cnt_modif_name = 0 ;
     sprintf(camera->name,"%s", gtk_entry_get_text((GtkEntry*) win->entry_name ) ) ;
     g_object_set(win->entry_name,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_name), win->img_btn_modify_name_modif) ; 
}
////model
void camera_button_modify_model_modif( camera_win_t* win, camera_t* camera ) {
     
     win->cnt_modif_model = 1 ;
     
     gtk_entry_set_text((GtkEntry*) win->entry_model, camera->model ) ; 
     g_object_set(win->entry_model,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_model), win->img_btn_modify_model_ok) ; 

}

void camera_button_modify_model_ok ( camera_win_t* win, camera_t* camera ) {
         
     win->cnt_modif_model = 0 ;
     sprintf(camera->model,"%s", gtk_entry_get_text((GtkEntry*) win->entry_model ) ) ;
     g_object_set(win->entry_model,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_model), win->img_btn_modify_model_modif) ; 
}
////serial
void camera_button_modify_serial_modif( camera_win_t* win, camera_t* camera ) {
     
     win->cnt_modif_serial = 1 ;
     
     gtk_entry_set_text((GtkEntry*) win->entry_serial, camera->serial ) ; 
     g_object_set(win->entry_serial,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_serial), win->img_btn_modify_serial_ok) ; 

}

void camera_button_modify_serial_ok ( camera_win_t* win, camera_t* camera ) {
         
     win->cnt_modif_serial = 0 ;
     sprintf(camera->serial,"%s", gtk_entry_get_text((GtkEntry*) win->entry_serial ) ) ;
     g_object_set(win->entry_serial,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_serial), win->img_btn_modify_serial_modif) ; 
}
////type
void camera_button_modify_type_modif( camera_win_t* win, camera_t* camera ) {
     
     win->cnt_modif_type = 1 ;
     
     gtk_entry_set_text((GtkEntry*) win->entry_type, camera_type_to_string(camera->type) ) ; 
     g_object_set(win->entry_type,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_type), win->img_btn_modify_type_ok) ; 

}

void camera_button_modify_type_ok ( camera_win_t* win, camera_t* camera ) {
         
     win->cnt_modif_type = 0 ;
//     sprintf(camera->type,"%s", gtk_entry_get_text((GtkEntry*) win->entry_type ) ) ;   FIXME
     g_object_set(win->entry_type,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_type), win->img_btn_modify_type_modif) ; 
}

////description
void camera_button_modify_description_modif( camera_win_t* win, camera_t* camera ) {
     
     win->cnt_modif_description = 1 ;
     
     gtk_entry_set_text((GtkEntry*) win->entry_description, camera->description ) ; 
     g_object_set(win->entry_description,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_description), win->img_btn_modify_description_ok) ; 

}

void camera_button_modify_description_ok ( camera_win_t* win, camera_t* camera ) {
         
     win->cnt_modif_description = 0 ;
     sprintf(camera->description,"%s", gtk_entry_get_text((GtkEntry*) win->entry_description ) ) ;
     g_object_set(win->entry_description,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->btn_modify_description), win->img_btn_modify_description_modif) ; 
}

