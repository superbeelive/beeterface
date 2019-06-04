#include <stdlib.h>
#include "auteur_win.h"

/* Function : auteur_win_fill
Fill in the fields with author's informations. 

Parameters :
    win - type : "auteur_win_t". Package containing the useful poiters to use the author window.
    auteur - type "auteur_t*". Package containing informations about the author. 
*/
void auteur_win_fill( auteur_win_t* win, auteur_t* auteur ) {

    gtk_entry_set_text((GtkEntry*) win->entry_email, auteur->email ) ; 
    gtk_entry_set_text((GtkEntry*) win->entry_first_name, auteur->prenom ) ; 
    gtk_entry_set_text((GtkEntry*) win->entry_name, auteur->nom );

    g_object_set(win->entry_name,"editable", FALSE) ; 
    g_object_set(win->entry_first_name,"editable", FALSE) ; 
    g_object_set(win->entry_email,"editable", FALSE) ; 
}

/*Function : auteur_bitton_modify_name 


*/
void auteur_button_modify_name( auteur_win_t* win, auteur_t* auteur ) {
     
     win->modif = 1 ;
     auteur->nom = gtk_entry_get_text((GtkEntry*) win->entry_name ) ;
     g_object_set(win->entry_name,"editable", TRUE) ;    
     
    // win->img_modify1 = gtk_image_new_from_file ("images/ok.png") ; 
    // win->button_modify1 = gtk_button_new() ; 
    
     gtk_button_set_image (GTK_BUTTON (win->button_modify1), win->img_modify_ok1) ; 

  // auteur->prenom = gtk_entry_get_text((GtkEntry*) win->entry_first_name ) ; 
  //  auteur->email = gtk_entry_get_text((GtkEntry*) win->entry_email ) ; 
}

void auteur_button_modify_ok_name ( auteur_win_t* win, auteur_t* auteur ) {
    
     win->modif = 0 ;
     auteur->nom = gtk_entry_get_text((GtkEntry*) win->entry_name ) ;
     g_object_set(win->entry_name,"editable", FALSE) ;     

     gtk_button_set_image (GTK_BUTTON (win->button_modify1), win->img_modify1) ; 


}

