#include <stdlib.h>
#include "camera_win.h"

/* Function : camera_win_fill
Fill in the fields with camera's informations. 

Parameters :
    win - type : "camera_win_t". Package containing the useful poiters to use the camera window.
    camera - type "camera_t*". Package containing informations about the camera.
*/

void camera_win_fill( camera_win_t* win, camera_t* camera ) {

    gtk_entry_set_text((GtkEntry*) win->entry_name, camera->name ) ; 
    gtk_entry_set_text((GtkEntry*) win->entry_model, camera->model ) ; 
    gtk_entry_set_text((GtkEntry*) win->entry_nserie, camera->nserie );
    gtk_entry_set_text((GtkEntry*) win->entry_type, camera->type );
    gtk_entry_set_text((GtkEntry*) win->entry_description, camera->description );

    g_object_set(win->entry_name,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_model,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_nserie, "editable", FALSE, NULL) ; 
    g_object_set(win->entry_type,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_description,"editable", FALSE, NULL) ; 
}


