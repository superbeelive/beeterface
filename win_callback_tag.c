#include <stdlib.h>
#include "tag_win.h"

//TODO Réintégrer la structure du TAG dans projet.c quand tag sera complet 

void tag_btn_edit_modif ( tag_win_t* win ) {
     
     win->cnt_edit = 1 ;
     
     //gtk_entry_set_text((GtkEntry*) win->entry_edit, tag->name_ruche ) ; 
     g_object_set(win->entry_edit,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->btn_edit), win->img_btn_edit_ok) ; 
}

void tag_btn_edit_ok ( tag_win_t* win ) {
         
     win->cnt_edit = 0 ;
     //sprintf(tag->name_ruche,"%s", gtk_entry_get_text((GtkEntry*) win->entry_edit ) ) ;
     g_object_set(win->entry_edit,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->btn_edit), win->img_btn_edit_modif) ; 
}

