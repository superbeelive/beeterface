#include <stdio.h>
#include <stdlib.h>

#include "tag.h" 

#define TAILLE 128

tag_t* tag_new () {
    int i ;
    tag_t* tag ; 
    tag = malloc (sizeof(tag_t)) ;
    tag->val = malloc (TAILLE*sizeof(char*)) ;
    for (i=0; i<TAILLE; i++)
    	tag->val[i]=malloc(TAILLE) ;
    return tag ;
}

void tag_del ( tag_t* tag ) {
    int i ;
    for (i=0; i<TAILLE; i++ )
    	free( tag->val[i] ) ;
    free ( tag->val ) ;
    free ( tag ) ;
}

void tag_add ( tag_t* tag, char* tnew ) {
    sprintf( tag->val[tag->pos], "%s",  tnew ) ; 
    tag->pos++ ; 
}



void tag_show (tag_t * tag ) {
    int i;
    for (i = tag->pos; i > -1; i--){
        printf("|%s|\n", tag->val[i]);
    }
}

int tag_count ( tag_t* tag ) {
    return tag->pos ; 
}

void tag_del_last ( tag_t* tag ) {
    tag->pos-- ;
}


