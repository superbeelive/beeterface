#include <stdlib.h>
#include <stdio.h>

#include "annotations.h"

int main (int argc, char *argv[]) {


        text_t* ficus;
        ficus = text_new() ; 
        text_show ( ficus ) ;
        
        printf("\n-----------------------------------------------------\n") ;

        text_set_description ( ficus, "C'est un joli mot ça" ) ;
        char* test1 ;
        test1 = text_get_description ( ficus ) ;
        printf ( "descripion : %s\n", test1 ) ;
        

        text_set_comment ( ficus, "commentaire/20" ) ;
        char* test3 ;
        test3 = text_get_comment ( ficus ) ;
        printf ( "Commentaire : %s\n", test3 ) ;


        text_set_time_start ( ficus ) ;
        char* test6 ;
        test6 = text_get_time_start ( ficus ) ; 
        printf ( "Date de début : %s\n", test6 ) ; 

        text_del ( ficus ) ; 


        return 0;
}
