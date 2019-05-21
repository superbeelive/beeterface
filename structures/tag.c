#include <stdio.h>
#include <stdlib.h>

#include "tag.h" 

#define TAILLE 128

tag_t* tag_new () {
    tag_t* tag ; 
    tag = malloc (sizeof(tag_t)) ;
    tag->val = malloc (TAILLE) ;

    return tag ;
}

void tag_del ( tag_t* tag ) {
    free ( tag->val ) ;
    free ( tag ) ;
}

void tag_add ( tag_t* tag, char* tnew ) {
    tag->val[tag->pos] = tnew ; 
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


