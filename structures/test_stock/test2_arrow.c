#include <stdlib.h>
#include <stdio.h>

#include "annotations.h"

int main (int argc, char *argv[]) {

//TESTS ARROW 

        arrow_t* poulpe;
        poulpe = arrow_new() ; 
        arrow_show ( poulpe ) ;
        
        printf("\n") ;

        arrow_set_description ( poulpe, "Licorne des mers" ) ;
        char* test1 ;
        test1 = arrow_get_description ( poulpe ) ;
        printf ( "descripion : %s\n", test1 ) ;

        arrow_set_x ( poulpe , 123 ) ;
        int test2 ;
        test2 = arrow_get_x ( poulpe ) ;
        printf ( "x : %d\n", test2) ;

        arrow_set_y ( poulpe , 456 ) ; 
        int test3 ;
        test3 = arrow_get_y ( poulpe ) ; 
        printf ( "y : %d\n", test3) ; 

        arrow_set_angle ( poulpe, 70 ) ;
        int test4 ; 
        test4 = arrow_get_angle ( poulpe ) ;
        printf ( "angle : %d\n", test4 ) ;
        
        arrow_del(poulpe); 

         return 0;
}    
