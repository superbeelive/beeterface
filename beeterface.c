#include <gtk/gtk.h>

void destroy (GtkWidget *widget, gpointer data)
{
     gtk_main_quit ();
}        

void window2 (GtkWidget *widget, gpointer data)
{
//DECLARATIONS

    GtkWidget *window2; //Fenetre changements
    GtkWidget *box_principal2;    
    GtkWidget *box_gauche;    
    GtkWidget *box_milieu;
    GtkWidget *box_droit;
    GtkWidget *box_video;
    GtkWidget *box_outil_video;
    GtkWidget *image_video;
    GtkWidget *titre_video;
    GtkWidget *button_ex_1;
    GtkWidget *button_ex_2;
    GtkWidget *button_ex_3;
    GtkWidget *button_ex_4;
    GtkWidget *button_ex_5;
    GtkWidget *barre_temps;
    GtkWidget *button_ex2_1;
    GtkWidget *button_ex2_2;
    GtkWidget *button_ex2_3;
    GtkWidget *button_ex2_4;
    GtkWidget *tags;
    GtkWidget *outils;
    GtkAdjustment *adjustement_barre_temps;
//CREATION
    //Fenetre
    window2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //Boites
    box_principal2 = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    box_gauche = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_milieu = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_droit = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_video = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_outil_video = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    //Image
    image_video = gtk_image_new_from_file ("images/bee2.jpg");
    //Texte
    titre_video = gtk_label_new("Nom de la vidéo");
    //Button
    button_ex_1 = gtk_button_new_with_label ("ex1");
    button_ex_2 = gtk_button_new_with_label ("ex2");
    button_ex_3 = gtk_button_new_with_label ("ex3");
    button_ex_4 = gtk_button_new_with_label ("ex4");
    button_ex_5 = gtk_button_new_with_label ("ex5");
        //Pour le menu de la video (bas)
    button_ex2_1 = gtk_button_new_with_label ("Test1");
    button_ex2_2 = gtk_button_new_with_label ("Test2");
    button_ex2_3 = gtk_button_new_with_label ("Test3");
    button_ex2_4 = gtk_button_new_with_label ("Test4");

    //Autre
    adjustement_barre_temps = gtk_adjustment_new (10,0,20,1,1,2);
    barre_temps = gtk_scrollbar_new(GTK_ORIENTATION_HORIZONTAL,adjustement_barre_temps);
    tags = gtk_places_sidebar_new ();
    outils = gtk_tool_palette_new ();
   // gtk_tool_palette_set_style ((GtkToolPalette) outils, GTK_TOOLBAR_ICONS);


//RANGEMENT
//Fenetre
    gtk_container_add (GTK_CONTAINER (window2), box_principal2);
       //Dans box_principal2
        gtk_box_pack_start(GTK_BOX(box_principal2), box_gauche, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box_principal2), box_milieu, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box_principal2), box_droit, TRUE, TRUE, 0);
            //Dans box_gauche
            gtk_box_pack_start(GTK_BOX(box_gauche), box_video, TRUE, TRUE, 0);
            gtk_box_pack_start(GTK_BOX(box_gauche), box_outil_video, TRUE, TRUE, 0);
                //Dans box_video
                gtk_box_pack_start(GTK_BOX(box_video), image_video, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(box_video), titre_video, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(box_video), barre_temps, TRUE, TRUE, 0);
                //Dans box_outil_video
                gtk_box_pack_start(GTK_BOX(box_outil_video), button_ex2_1, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(box_outil_video), button_ex2_2, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(box_outil_video), button_ex2_3, TRUE, TRUE, 0);
                gtk_box_pack_start(GTK_BOX(box_outil_video), button_ex2_4, TRUE, TRUE, 0);
                

             //Dans box_milieu
             gtk_box_pack_start(GTK_BOX(box_milieu), button_ex_1, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(box_milieu), button_ex_2, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(box_milieu), button_ex_3, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(box_milieu), button_ex_4, FALSE, FALSE, 0);
             gtk_box_pack_start(GTK_BOX(box_milieu), button_ex_5, FALSE, FALSE, 0);
             // gtk_box_pack_start(GTK_BOX(box_milieu), outils, FALSE, FALSE, 0);

             //Dans box_droit
             gtk_box_pack_start(GTK_BOX(box_droit), tags, FALSE, FALSE, 0);


//FONCTIONS
    gtk_window_set_title (GTK_WINDOW (window2), "Modifier la vidéo"); //Nomme la fenêtre 
//AFFICHAGE
    gtk_widget_show (window2);
    gtk_widget_show_all (box_principal2);

}


int main (int argc, char *argv[])
{

//DECLARATIONS

    GtkWidget *window; //Fenêtre d'acceuil 
    GtkWidget *box_principal; //Boite principale contenant les autres boites 
    GtkWidget *button_quit; //Bouton quitter 
    GtkWidget *image_button_quit;
    GtkWidget *box_up; //Boite la plus haute pour le bouton quitter (provisoire ?) 
    GtkWidget *box_all; //Reste de la zone 
    GtkWidget *box_info_video;
    GtkWidget *image_exemple; //Image pour repérer où sera la vidéo
    GtkWidget *box_menu_droit; //Boite pour la droite de la vidéo
    GtkWidget *box_gauche; //Boite contenant vidéo & menus
    GtkWidget *box_video; //boite avec la vidéo + nom de la vidéo
    GtkWidget *box_menu_video; //Menu sous la vidéo
    GtkWidget *box_quit;
    GtkWidget *box_search_1;
    GtkWidget *box_search_2;
    GtkWidget *sep; //Separateur vertical  entre image et selecteur fichier
    GtkWidget *fichiers; 
    GtkWidget *search;
    GtkWidget *nom_video;
    GtkWidget *choix_camera;
    GtkWidget *button_enregistrer;
    GtkWidget *image_button_enregistrer;
    GtkWidget *button_stop;
    GtkWidget *image_button_stop;
    GtkWidget *button_photo;
    GtkWidget *image_button_photo;
    GtkWidget *logo_type_video;
    GtkWidget *choix_tri;
    GtkWidget *txt_trier_par;
    GtkWidget *txt_visualiser;

    gtk_init (&argc, &argv);

//CREATION    
    //Fenêtre principale 
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    //BOITES 
    box_principal = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_up = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_all = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    box_menu_droit = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_gauche = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_video = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_menu_video = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    box_info_video = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    box_quit = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    box_search_1 = gtk_box_new( GTK_ORIENTATION_HORIZONTAL, 0);
    box_search_2 = gtk_box_new( GTK_ORIENTATION_VERTICAL, 0);
    

    //BOUTONS
    button_quit = gtk_button_new (); //Definition sur deux lignes  
    //gtk_button_set_label ((GtkButton*)button_quit,"Quitter");
    image_button_quit = gtk_image_new_from_file ("images/quit3.png");
    gtk_button_set_image (GTK_BUTTON (button_quit), image_button_quit);

    button_enregistrer = gtk_button_new ();
    image_button_enregistrer = gtk_image_new_from_file ("images/enregistrer.png");
    gtk_button_set_image (GTK_BUTTON (button_enregistrer), image_button_enregistrer);


    button_stop = gtk_button_new ();
    image_button_stop =  gtk_image_new_from_file ("images/carre_noir.png");
    gtk_button_set_image (GTK_BUTTON (button_stop), image_button_stop);

    button_photo = gtk_button_new ();
    image_button_photo = gtk_image_new_from_file ("images/icone_photo3.png");
    gtk_button_set_image (GTK_BUTTON (button_photo), image_button_photo);

    //IMAGES  
    image_exemple = gtk_image_new_from_file ("images/bee2.jpg");
    logo_type_video = gtk_image_new_from_file ("images/cassette2.png");
    //TEXTE 
    nom_video = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(nom_video), "<span foreground=\"black\" font=\"16\">Nom de la vidéo</span>");
    
    txt_trier_par = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(txt_trier_par), "<span foreground=\"black\" font=\"10\">Trier par :</span>");

    txt_visualiser = gtk_label_new("");
    gtk_label_set_markup(GTK_LABEL(txt_visualiser), "<span foreground=\"black\" font=\"10\">Visualiser :</span>");



    //AUTRES 
    fichiers = gtk_places_sidebar_new ();
    sep = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
    search = gtk_search_entry_new ();
    
    choix_camera = gtk_combo_box_text_new();
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) choix_camera, 1,"Caméra n°1");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) choix_camera, 2,"Caméra n°2");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) choix_camera, 3,"Caméra n°3");

    choix_tri =  gtk_combo_box_text_new();
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) choix_tri, 3,"Date");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) choix_tri, 3,"Nom");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) choix_tri, 3,"Tag");
    gtk_combo_box_text_insert_text ((GtkComboBoxText*) choix_tri, 3,"Caméra");


//Rangement des boxs & Widgets 
    
    //Boite PRINCIPALE 
    gtk_container_add (GTK_CONTAINER (window), box_principal);
        //Dans la boite principale :
        gtk_box_pack_start(GTK_BOX(box_principal), box_up, TRUE, TRUE, 0);
        gtk_box_pack_start(GTK_BOX(box_principal), box_all, TRUE, TRUE, 0);

            //Dans box_up
            gtk_box_pack_start(GTK_BOX(box_up), box_quit, TRUE, TRUE, 0); 
            gtk_box_pack_start(GTK_BOX(box_up), box_info_video, TRUE, TRUE, 0); 
                 //Dans box_info_video   
                 gtk_box_pack_start(GTK_BOX(box_info_video), logo_type_video, FALSE, FALSE, 20);
                 gtk_box_pack_start(GTK_BOX(box_info_video), nom_video, FALSE, FALSE, 0);

                 //Dans box_quit
                 gtk_box_pack_start(GTK_BOX(box_quit), button_quit, FALSE, FALSE, 0);
            //Dans box_all
            gtk_box_pack_start(GTK_BOX(box_all), box_gauche, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(box_all), sep, FALSE, FALSE, 0);
            gtk_box_pack_start(GTK_BOX(box_all), box_menu_droit, TRUE, TRUE, 0);

                //Dans box_menu_droit
                 gtk_box_pack_start(GTK_BOX(box_menu_droit), box_search_1, FALSE, FALSE, 0);
                 gtk_box_pack_start(GTK_BOX(box_menu_droit), box_search_2, FALSE, FALSE, 0);
                    //Dans box_search_1
                    gtk_box_pack_start(GTK_BOX(box_search_1), search, FALSE, FALSE, 5);
                    gtk_box_pack_start(GTK_BOX(box_search_1), txt_trier_par, FALSE, FALSE, 0);

                    gtk_box_pack_start(GTK_BOX(box_search_1), choix_tri, FALSE, FALSE, 5);

                    //Dans box_search_2
                    gtk_box_pack_start(GTK_BOX(box_search_2), fichiers, FALSE, FALSE, 0);

                //Dans box_gauche
                     gtk_box_pack_start(GTK_BOX(box_gauche), box_video, FALSE, FALSE, 0);
                     gtk_box_pack_start(GTK_BOX(box_gauche), box_menu_video, FALSE, FALSE, 0);

                        //Dans box_video
                             gtk_box_pack_start(GTK_BOX(box_video), image_exemple, FALSE, FALSE, 0);

                        //Dans box_menu_video
                             gtk_box_pack_start(GTK_BOX(box_menu_video), txt_visualiser, FALSE, FALSE, 10);
                             gtk_box_pack_start(GTK_BOX(box_menu_video), choix_camera, FALSE, FALSE, 0);
                             gtk_box_pack_start(GTK_BOX(box_menu_video), button_enregistrer, FALSE, FALSE, 0);
                             gtk_box_pack_start(GTK_BOX(box_menu_video), button_stop, FALSE, FALSE, 0);
                             gtk_box_pack_start(GTK_BOX(box_menu_video), button_photo, FALSE, FALSE, 0);



//FONCTIONS 
    g_signal_connect (button_quit, "clicked", G_CALLBACK(destroy),NULL);
    g_signal_connect (button_enregistrer, "clicked", G_CALLBACK(window2),NULL);

//AUTRE 
    gtk_window_set_title (GTK_WINDOW (window), "BEETERFACE"); //Nomme la fenêtre 



//AFFICHAGE 
  
    //BOX
    gtk_widget_show_all (box_principal);
    gtk_widget_show_all (box_up);
    gtk_widget_show (box_all);
    gtk_widget_show (box_menu_droit);
    gtk_widget_show (box_gauche);
    gtk_widget_show (box_video);
    gtk_widget_show (box_menu_video);

    //BUTTONS
    gtk_widget_show (button_quit); 
    gtk_widget_show (button_enregistrer);
    gtk_widget_show (button_stop); 
    gtk_widget_show (button_photo);
    
    
    //IMAGE
    gtk_widget_show (image_exemple);

    //TEXTE
    gtk_widget_show (nom_video);

    //AUTRE
    gtk_widget_show (sep);
    gtk_widget_show (fichiers);
    gtk_widget_show (choix_camera);

    //FENETRE
    gtk_widget_show (window);


  gtk_main ();
    return 0;

}
