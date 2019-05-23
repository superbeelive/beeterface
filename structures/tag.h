#ifndef TAG_H
#define TAH_H

typedef struct {
    char** val ; //Wallah c'est un tableau de tableaux !!!!  
    int pos ; 
} tag_t ; 
tag_t* tag_new () ;  //Création du tableau de la pile 
void tag_del ( tag_t* ) ; //
void tag_add ( tag_t*, char* tnew) ; //Ajout d'un TAG dans la pile
void tag_show ( tag_t* ) ; //Affiche les TAGS ajoutés
int tag_count ( tag_t* ) ; //Compte le nombre de TAGS
void tag_del_last ( tag_t* ) ; //Efface le dernier élément ajouté        

#endif 
