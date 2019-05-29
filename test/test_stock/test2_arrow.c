#include <stdlib.h>
#include <stdio.h>

#include "annotations.h"

int main (int argc, char *argv[]) {


     arrow_t* ficus;
        ficus = arrow_new() ; 
        arrow_show ( ficus ) ;
        
        printf("\n-----------------------------------------------------\n") ;

        arrow_set_description ( ficus, "C'est un joli mot ça" ) ;
        char* test1 ;
        test1 = arrow_get_description ( ficus ) ;
        printf ( "descripion : %s\n", test1 ) ;
        

        arrow_set_x ( ficus, 0 ) ;
        int test2 ;
        test2 = arrow_get_x ( ficus ) ;
        printf ( "x départ : %d\n", test2 ) ;


        arrow_set_y ( ficus, 1 ) ;
        int test3 ;
        test3 = arrow_get_y ( ficus ) ;
        printf ( "y départ : %d\n", test3 ) ;


        arrow_set_angle ( ficus, 2 ) ;
        int test4 ;
        test4 = arrow_get_angle( ficus ) ;
        printf ( "x fin : %d\n", test4 ) ;

        arrow_set_time_start ( ficus ) ;
        char* test6 ;
        test6 = arrow_get_time_start ( ficus ) ; 
        printf ( "Date de début : %s\n", test6 ) ; 

        arrow_del ( ficus ) ; 


         return 0;
}    
