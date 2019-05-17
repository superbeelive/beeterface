#ifndef COLOR_H
#define COLOR_H

typedef struct {
        char* name ; 
        int R ; 
        int G ;
        int B ; 
} color_t ; 

//General 

color_t* color_new () ; 
void color_del ( color_t* ) ;
void color_show ( color_t* ) ;

//Name 
void color_set_name ( color_t*, char* name ) ;
char* color_get_name ( color_t* ) ;

//R

void color_set_R ( color_t*, int R ) ;
int color_get_R ( color_t* ) ;

//G

void color_set_G ( color_t*, int G ) ;
int color_get_G ( color_t* ) ;

//B

void color_set_B ( color_t*, int B ) ;
int color_get_G ( color_t* ) ;


#endif
