#include <stdlib.h>
#include <stdio.h>

#include "annotations.h"

int main (int argc, char *argv[]) {

        text_t* cuic;
        cuic = text_new() ; 
        text_show ( cuic ) ;
        
        printf("\n") ;

        text_set_description ( cuic, "Cochon d'inde qui vole" ) ;
        char* test1 ;
        test1 = text_get_description ( cuic ) ;
        printf ( "descripion : %s\n", test1 ) ;

        text_set_comment ( cuic , "Encore un commentaire" ) ;
        char* test2 ;
        test2 = text_get_comment ( cuic ) ;
        printf ( "Commentaire : %s\n", test2) ;
        
        text_del (cuic) ; 

        return 0;
}
