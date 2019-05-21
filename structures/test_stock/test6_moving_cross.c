#include <stdlib.h>
#include <stdio.h>

#include "annotations.h"

int main (int argc, char *argv[]) {

        moving_cross_t* ficus;
        ficus = moving_cross_new() ; 
        moving_cross_show ( ficus ) ;
        
        printf("\n-----------------------------------------------------\n") ;

        moving_cross_set_description ( ficus, "C'est un joli mot ça" ) ;
        char* test1 ;
        test1 = moving_cross_get_description ( ficus ) ;
        printf ( "descripion : %s\n", test1 ) ;
        
        moving_cross_set_time_start ( ficus ) ;
        char* test6 ;
        test6 = moving_cross_get_time_start ( ficus ) ; 
        printf ( "Date de début : %s\n", test6 ) ; 

        
        moving_cross_set_time_end ( ficus ) ;
        char* test7 ;
        test7 = moving_cross_get_time_end ( ficus ) ; 
        printf ( "Date de fin : %s\n", test7 ) ; 

        

        moving_cross_del ( ficus ) ; 


        return 0;
}
