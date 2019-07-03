#include <stdio.h> 
#include <stdlib.h>

#include "projet.h"
#include "utils.h"

#define TAB_SIZE 128


projet_t* projet_new() { 
    
    projet_t* ficus ;
    ficus = malloc ( sizeof(projet_t) ) ;
    ficus->camera = NULL ; 
    ficus->video = NULL ; 
    
    ficus->box = malloc ( TAB_SIZE* sizeof(box_t*) ) ;
    if ( ficus->box == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    ficus->box_size = TAB_SIZE ;
    ficus->box_n = 0 ;

    ficus->cross = malloc ( TAB_SIZE* sizeof(cross_t*) ) ;
    if ( ficus->cross == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    ficus->cross_size = TAB_SIZE ;
    ficus->cross_n = 0 ;
    
    ficus->arrow = malloc ( TAB_SIZE* sizeof(arrow_t*) ) ;
    if ( ficus->arrow == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    ficus->arrow_size = TAB_SIZE ;
    ficus->arrow_n = 0 ;

    ficus->text = malloc ( TAB_SIZE* sizeof(text_t*) ) ;
    if ( ficus->text == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    ficus->text_size = TAB_SIZE ;
    ficus->text_n = 0 ;

    ficus->measure = malloc ( TAB_SIZE* sizeof(measure_t*) ) ;
    if ( ficus->measure == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    ficus->measure_size = TAB_SIZE ;
    ficus->measure_n = 0 ;

    ficus->moving_cross = malloc ( TAB_SIZE* sizeof(moving_cross_t*) ) ;
    if ( ficus->moving_cross == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    ficus->moving_cross_size = TAB_SIZE ;
    ficus->moving_cross_n = 0 ;

    return ficus ; 
}

void projet_del (projet_t* ficus ) {
    projet_flush(ficus) ;
    free ( ficus->box ) ; 
    free ( ficus->cross ) ; 
    free ( ficus->arrow ) ; 
    free ( ficus->text ) ;
    free ( ficus->measure ) ; 
    free ( ficus->moving_cross ) ; 
    free ( ficus ) ; 
}

void projet_flush( projet_t* ficus) {
    int i ;
    
    if (ficus->camera != NULL ) 
        camera_del ( ficus->camera ) ;

    if (ficus->video != NULL ) 
        video_del  ( ficus->video ) ; 

    for (i=0; i<ficus->box_n; i++)
        free(ficus->box[i]) ;

    for (i=0; i<ficus->cross_n; i++)
        free(ficus->cross[i]) ;

    for (i=0; i<ficus->arrow_n; i++)
        free(ficus->arrow[i]) ;
    
    for (i=0; i<ficus->text_n; i++)
        free(ficus->text[i]) ;
    
    for (i=0; i<ficus->measure_n; i++)
        free(ficus->measure[i]) ;
    
    for (i=0; i<ficus->moving_cross_n; i++)
        free(ficus->moving_cross[i]) ;

    ficus->box_n = 0 ;
    ficus->cross_n = 0 ;
    ficus->arrow_n = 0 ;
    ficus->text_n = 0 ;
    ficus->measure_n = 0 ;
    ficus->moving_cross_n = 0 ;

    ficus->camera = NULL ;
    ficus->video = NULL ;

}

void projet_add_box( projet_t* projet, box_t* box ) {
    if (projet->box_n == projet->box_size ) {
        projet->box = reallocarray( projet->box, projet->box_size+TAB_SIZE, sizeof(box_t*) ) ;
        projet->box_size += TAB_SIZE ;
    }
    projet->box[projet->box_n] = box ;
    projet->box_n +=1 ;
}

void projet_add_cross( projet_t* projet, cross_t* cross ) {
    if (projet->cross_n == projet->cross_size ) {
        projet->cross = reallocarray( projet->cross, projet->cross_size+TAB_SIZE, sizeof(cross_t*) ) ;
        projet->cross_size += TAB_SIZE ;
    }
    projet->cross[projet->cross_n] = cross ;
    projet->cross_n +=1 ;
}

void projet_add_arrow( projet_t* projet, arrow_t* arrow ) {
    if (projet->arrow_n == projet->arrow_size ) {
        projet->arrow = reallocarray( projet->arrow, projet->arrow_size+TAB_SIZE, sizeof(arrow_t*) ) ;
        projet->arrow_size += TAB_SIZE ;
    }
    projet->arrow[projet->arrow_n] = arrow ;
    projet->arrow_n +=1 ;
}

void projet_add_text( projet_t* projet, text_t* text ) {
    if (projet->text_n == projet->text_size ) {
        projet->text = reallocarray( projet->text, projet->text_size+TAB_SIZE, sizeof(text_t*) ) ;
        projet->text_size += TAB_SIZE ;
    }
    projet->text[projet->text_n] = text ;
    projet->text_n +=1 ;
}

void projet_add_measure( projet_t* projet, measure_t* measure ) {
    if (projet->measure_n == projet->measure_size ) {
        projet->measure = reallocarray( projet->measure, projet->measure_size+TAB_SIZE, sizeof(measure_t*) ) ;
        projet->measure_size += TAB_SIZE ;
    }
    projet->measure[projet->measure_n] = measure ;
    projet->measure_n +=1 ;
}

void projet_add_moving_cross( projet_t* projet, moving_cross_t* moving_cross ) {
    if (projet->moving_cross_n == projet->moving_cross_size ) {
        projet->moving_cross = reallocarray( projet->moving_cross, projet->moving_cross_size+TAB_SIZE, sizeof(moving_cross_t*) ) ;
        projet->moving_cross_size += TAB_SIZE ;
    }
    projet->moving_cross[projet->moving_cross_n] = moving_cross ;
    projet->moving_cross_n +=1 ;
}

void project_del_box( projet_t* projet, int n ) {
    int i ;
    if ((n<0) || (n >= projet->box_n)) {
        throw_error("invalid index",0);
    }
   box_del(projet->box[n]) ;
   for(i=n+1;i<projet->box_n;i++) {
    projet->box[i-1]=projet->box[i] ;
   }
}

void project_del_cross( projet_t* projet, int n ) {
    int i ;
    if ((n<0) || (n >= projet->cross_n)) {
        throw_error("invalid index",0);
    }
   cross_del(projet->cross[n]) ;
   for(i=n+1;i<projet->cross_n;i++) {
    projet->cross[i-1]=projet->cross[i] ;
   }
}

void project_del_arrow( projet_t* projet, int n ) {
    int i ;
    if ((n<0) || (n >= projet->arrow_n)) {
        throw_error("invalid index",0);
    }
   arrow_del(projet->arrow[n]) ;
   for(i=n+1;i<projet->arrow_n;i++) {
    projet->arrow[i-1]=projet->arrow[i] ;
   }
}

void project_del_text( projet_t* projet, int n ) {
    int i ;
    if ((n<0) || (n >= projet->text_n)) {
        throw_error("invalid index",0);
    }
   text_del(projet->text[n]) ;
   for(i=n+1;i<projet->text_n;i++) {
    projet->text[i-1]=projet->text[i] ;
   }
}

void project_del_measure( projet_t* projet, int n ) {
    int i ;
    if ((n<0) || (n >= projet->measure_n)) {
        throw_error("invalid index",0);
    }
   measure_del(projet->measure[n]) ;
   for(i=n+1;i<projet->measure_n;i++) {
    projet->measure[i-1]=projet->measure[i] ;
   }
}

void project_del_moving_cross( projet_t* projet, int n ) {
    int i ;
    if ((n<0) || (n >= projet->moving_cross_n)) {
        throw_error("invalid index",0);
    }
   moving_cross_del(projet->moving_cross[n]) ;
   for(i=n+1;i<projet->moving_cross_n;i++) {
    projet->moving_cross[i-1]=projet->moving_cross[i] ;
   }
}
