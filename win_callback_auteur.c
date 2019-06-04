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

    g_object_set(win->entry_name,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_first_name,"editable", FALSE, NULL) ; 
    g_object_set(win->entry_email,"editable", FALSE, NULL) ; 
}

/*Function : auteur_button_modify_name 


*/
///////////////////////////BOUTON NOM
void auteur_button_modify_name( auteur_win_t* win, auteur_t* auteur ) {
     
     win->button_modif_1 = 1 ;
     
     gtk_entry_set_text((GtkEntry*) win->entry_name, auteur->nom ) ; 
     g_object_set(win->entry_name,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->button_modify1), win->img_modify_ok1) ; 

}

void auteur_button_modify_ok_name ( auteur_win_t* win, auteur_t* auteur ) {
         
    win->button_modif_1 = 0 ;
     sprintf(auteur->nom,"%s", gtk_entry_get_text((GtkEntry*) win->entry_name ) ) ;
     g_object_set(win->entry_name,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->button_modify1), win->img_modify1) ; 
}

////////////////////////BOUTON PRENOM
void auteur_button_modify_first_name( auteur_win_t* win, auteur_t* auteur ) {
     
     win->button_modif_2 = 1 ;
     
     gtk_entry_set_text((GtkEntry*) win->entry_first_name, auteur->prenom ) ; 
     g_object_set(win->entry_first_name,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->button_modify2), win->img_modify_ok2) ; 
}

void auteur_button_modify_ok_first_name ( auteur_win_t* win, auteur_t* auteur ) {
         
     win->button_modif_2 = 0 ;
     sprintf(auteur->prenom,"%s", gtk_entry_get_text((GtkEntry*) win->entry_first_name ) ) ;
     g_object_set(win->entry_first_name,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->button_modify2), win->img_modify2) ; 
}


////////////////////////////BOUTON EMAIL
void auteur_button_modify_email( auteur_win_t* win, auteur_t* auteur ) {
     
     win->button_modif_3 = 1 ;
     
     gtk_entry_set_text((GtkEntry*) win->entry_email, auteur->email ) ; 
     g_object_set(win->entry_email,"editable", TRUE, NULL) ;    
     gtk_button_set_image (GTK_BUTTON (win->button_modify3), win->img_modify_ok3) ; 
}

void auteur_button_modify_ok_email ( auteur_win_t* win, auteur_t* auteur ) {
         
     win->button_modif_3 = 0 ;
     sprintf(auteur->email,"%s", gtk_entry_get_text((GtkEntry*) win->entry_email ) ) ;
     //auteur->email = gtk_entry_get_text((GtkEntry*) win->entry_email ) ;
     g_object_set(win->entry_email,"editable", FALSE, NULL) ;     
     gtk_button_set_image (GTK_BUTTON (win->button_modify3), win->img_modify3) ; 
}

