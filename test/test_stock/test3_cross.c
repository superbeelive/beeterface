#include <stdlib.h>
#include <stdio.h>

#include "annotations.h"

int main (int argc, char *argv[]) {
              
    
        cross_t* ficus;
        ficus = cross_new() ; 
        cross_show ( ficus ) ;
        
        printf("\n-----------------------------------------------------\n") ;

        cross_set_description ( ficus, "C'est un joli mot ça" ) ;
        char* test1 ;
        test1 = cross_get_description ( ficus ) ;
        printf ( "descripion : %s\n", test1 ) ;
        

        cross_set_x ( ficus, 0 ) ;
        int test2 ;
        test2 = cross_get_x( ficus ) ;
        printf ( "x départ : %d\n", test2 ) ;


        cross_set_y ( ficus, 1 ) ;
        int test3 ;
        test3 = cross_get_y ( ficus ) ;
        printf ( "y départ : %d\n", test3 ) ;


        cross_set_time_start ( ficus ) ;
        char* test6 ;
        test6 = cross_get_time_start ( ficus ) ; 
        printf ( "Date de début : %s\n", test6 ) ; 

        cross_del ( ficus ) ; 

    
    return 0;
}
