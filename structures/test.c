#include <stdlib.h>
#include <stdio.h>

#include "tag.h"

int main (int argc, char *argv[]) {

    tag_t* ficus ; 
    ficus = tag_new() ;
    tag_add ( ficus, "yoplait" ) ;
    tag_add ( ficus, "yup" ) ;
    tag_show ( ficus ) ; 
    tag_count ( ficus ) ; 
    tag_del ( ficus ) ;
        return 0;
}
