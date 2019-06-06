#include <stdlib.h>

#include "queen.h"


void callback_destroy(GtkWidget * widget, gpointer data)
{
    gtk_main_quit();
}

void callback_modif(GtkWidget * widget, gpointer data)
{
    queen_t* tmp ;
    tmp = data ;
    modif_win_show(tmp->interface->win_modif);
}
///////////////////////////////////////AUTEUR////////////////////////////////////////////
void callback_auteur(GtkWidget * widget, gpointer data)
{
    queen_t* tmp ;
    tmp = data ;
    // Remplissage de la fenêtre avec le contenu de auteur 
    auteur_win_fill(tmp->interface->win_auteur, tmp->projet->auteur ) ; 
    
    //Apparition de la fenêtre
    auteur_win_show(tmp->interface->win_auteur); 
}

void callback_auteur_modify_name(GtkWidget* widget, gpointer data) { 
        queen_t* tmp ; 
        tmp = data ;

        if ( tmp->interface->win_auteur->button_modif_1 == 0 )  
        auteur_button_modify_name(tmp->interface->win_auteur, tmp->projet->auteur ) ;     
        else 
        auteur_button_modify_ok_name(tmp->interface->win_auteur, tmp->projet->auteur ) ;
}

void callback_auteur_modify_first_name(GtkWidget* widget, gpointer data) {
        queen_t* tmp ; 
        tmp = data ;

        if ( tmp->interface->win_auteur->button_modif_2 == 0 )  
        auteur_button_modify_first_name(tmp->interface->win_auteur, tmp->projet->auteur ) ;     
        else 
        auteur_button_modify_ok_first_name(tmp->interface->win_auteur, tmp->projet->auteur ) ;
}
   

void callback_auteur_modify_email (GtkWidget* widget, gpointer data) {
        queen_t* tmp ; 
        tmp = data ;

        if ( tmp->interface->win_auteur->button_modif_3 == 0 )  
        auteur_button_modify_email(tmp->interface->win_auteur, tmp->projet->auteur ) ;     
        else 
        auteur_button_modify_ok_email(tmp->interface->win_auteur, tmp->projet->auteur ) ;
    }
//////VIDEO

void callback_video(GtkWidget * widget, gpointer data)
{
    queen_t* tmp ;
    tmp = data ;
    // Remplissage de la fenêtre avec le contenu de auteur 
    //auteur_win_fill(tmp->interface->win_auteur, tmp->projet->auteur ) ; 
    
    //Apparition de la fenêtre
    video_win_show(tmp->interface->win_video); 
}


//////CAMERA

void callback_camera(GtkWidget * widget, gpointer data)
{
    queen_t* tmp ;
    tmp = data ;
    // Remplissage de la fenêtre avec le contenu de auteur 
    //auteur_win_fill(tmp->interface->win_auteur, tmp->projet->auteur ) ; 
    
    //Apparition de la fenêtre
    camera_win_show(tmp->interface->win_camera); 
}


int main(int argc, char *argv[])
{


//Création de la grande structure
    queen_t * queen;

//Initialisation de GTK
    gtk_init(&argc, &argv);

//Définition de la grande structure
    queen = queen_new();

//Affichage de la fenêtre principale 
    main_win_show(queen->interface->win_main);

//////FONCTIONS///////
//Fenêtre MAIN     
    g_signal_connect(queen->interface->win_main->button_quit, 
    			"clicked", 
		    	G_CALLBACK(callback_destroy),
		     	NULL);
    
    g_signal_connect(queen->interface->win_main->button_enregistrer, 
    			"clicked", 
			    G_CALLBACK(callback_modif), 
			    queen);			//Affiche win modif quand appui sur bouton

    g_signal_connect(queen->interface->win_main->button_auteur, 
    		   	"clicked",
			    G_CALLBACK(callback_auteur), 
			    queen);

    g_signal_connect(queen->interface->win_main->button_video, 
    		   	"clicked",
			    G_CALLBACK(callback_video), 
			    queen);

    
    g_signal_connect(queen->interface->win_main->button_camera, 
    		   	"clicked",
			    G_CALLBACK(callback_camera), 
			    queen);



//Fenêtre AUTEUR 
    g_signal_connect(queen->interface->win_auteur->button_modify1,
            "clicked",
            G_CALLBACK(callback_auteur_modify_name),
            queen);


    g_signal_connect(queen->interface->win_auteur->button_modify2,
            "clicked",
            G_CALLBACK(callback_auteur_modify_first_name),
            queen);

    g_signal_connect(queen->interface->win_auteur->button_modify3,
            "clicked",
            G_CALLBACK(callback_auteur_modify_email),
            queen);

//Fonction attend event.     
    gtk_main();

//Suppr des éléments
    queen_del(queen) ; 

    return 0;

}
