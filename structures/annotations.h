#ifndef ANNOTATIONS_H
#define ANNOTATIONS_H

#define TAILLE 128

#include "auteur.h"

typedef int timecode_t; //TODO 
typedef int color_t; //TODO
//3 chars 

/* Tag = pile de tag, une fonction unique(passe partout) TODO*/


//////////////////////OBLONG
typedef struct {

    int tag[TAILLE];
    int tag_size;
    auteur_t* auteur;
    color_t color;
    timecode_t time_start;
    timecode_t time_end;
    char* description; 

    int x_start;
    int y_start;
    int x_end;
    int y_end;

} oblong_t;

oblong_t* oblong_new();
void oblong_del ( oblong_t* ) ;
void oblong_show ( oblong_t* ) ;


void oblong_add_tag ( oblong_t*, int tag ) ; 
void oblong_remove_tag ( oblong_t*, int tag ) ;
void oblong_show_tag ( oblong_t* ) ; 

void oblong_set_color ( oblong_t*, color_t* color) ;
color_t oblong_get_color ( oblong_t* ) ;

void oblong_set_time_start ( oblong_t*, timecode_t time_s ) ;
timecode_t oblong_get_time_start ( oblong_t* );

void oblong_set_time_end ( oblong_t*, timecode_t time_e ) ;
timecode_t oblong_get_time_end ( oblong_t* );

void oblong_set_description ( oblong_t*, char* descr ) ;
char* oblong_get_description ( oblong_t* ) ;


void oblong_set_x_start ( oblong_t*, int x_s ) ; 
int oblong_get_x_start ( oblong_t * ) ; 

void oblong_set_y_start ( oblong_t*, int y_s ) ; 
int oblong_get_y_start ( oblong_t * ) ; 

void oblong_set_x_end ( oblong_t*, int x_e ) ; 
int oblong_get_x_end ( oblong_t * ) ; 

void oblong_set_y_end ( oblong_t*, int y_e ) ; 
int oblong_get_y_end ( oblong_t * ) ; 



////////////////////CROSS
typedef struct {

    int tag[TAILLE];
    int tag_size;
    auteur_t* auteur;
    color_t color;
    timecode_t time_start;
    timecode_t time_end;
    char* description; 
    
    int x;
    int y;

} cross_t;


cross_t* cross_new();
void cross_del ( cross_t* ) ;
void cross_show ( cross_t* ) ;

void cross_add_tag ( cross_t*, int tag ) ; 
void cross_remove_tag ( cross_t*, int tag ) ;
void cross_show_tag ( cross_t* ) ; 

void cross_set_color ( cross_t*, color_t* color) ;
color_t cross_get_color ( cross_t* ) ;

void cross_set_time_start ( cross_t*, timecode_t time_s ) ;
timecode_t cross_get_time_start ( cross_t* );

void cross_set_time_end ( cross_t*, timecode_t time_e ) ;
timecode_t cross_get_time_end ( cross_t* );

void cross_set_description ( cross_t*, char* descr ) ;
char* cross_get_description ( cross_t* ) ;

void cross_set_x ( cross_t*, int x ) ;
int cross_get_x ( cross_t* ) ;

void cross_set_y ( cross_t*, int y ) ; 
int cross_get_y ( cross_t* ) ;


/////////////////////ARROW
typedef struct {

    int tag[TAILLE];
    int tag_size;
    auteur_t* auteur;
    color_t color;
    timecode_t time_start;
    timecode_t time_end;
    char* description; 
    
    int x;
    int y;
    int angle;

} arrow_t;

arrow_t* arrow_new();
void arrow_del ( arrow_t* ) ;
void arrow_show ( arrow_t* ) ;

void arrow_add_tag ( arrow_t*, int tag ) ; //TODO  
void arrow_remove_tag ( arrow_t*, int tag ) ; //TODO
void arrow_show_tag ( arrow_t* ) ; //TODO 

void arrow_set_color ( arrow_t*, color_t* color) ; //TODO
color_t arrow_get_color ( arrow_t* ) ; //TODO 

void arrow_set_time_start ( arrow_t*, timecode_t time_s ) ; //TODO
timecode_t arrow_get_time_start ( arrow_t* ); //TODO

void arrow_set_time_end ( arrow_t*, timecode_t time_e ) ; //TODO
timecode_t arrow_get_time_end ( arrow_t* ); //TODO 

void arrow_set_description ( arrow_t*, char* descr ) ;
char* arrow_get_description ( arrow_t* ) ;


void arrow_set_x ( arrow_t*, int x ) ;
int arrow_get_x ( arrow_t* ) ;

void arrow_set_y ( arrow_t*, int y ) ; 
int arrow_get_y ( arrow_t* ) ;

void arrow_set_angle ( arrow_t*, int ang ) ; 
int arrow_get_angle ( arrow_t* ) ;


////////////////////TEXT
typedef struct {
   
    int tag[TAILLE];
    int tag_size;
    auteur_t* auteur;
    color_t color;
    timecode_t time_start;
    timecode_t time_end;
    char* description; 

    char* comment;

} text_t;

text_t* text_new() ;
void text_del ( text_t* ) ;
void text_show ( text_t* ) ;

void text_add_tag ( text_t*, int tag ) ; 
void text_remove_tag ( text_t*, int tag ) ;
void text_show_tag ( text_t* ) ; 

void text_set_color ( text_t*, color_t* color) ;
color_t text_get_color ( text_t* ) ;

void text_set_time_start ( text_t*, timecode_t time_s ) ;
timecode_t text_get_time_start ( text_t* );

void text_set_time_end ( text_t*, timecode_t time_e ) ;
timecode_t text_get_time_end ( text_t* );

void text_set_description ( text_t*, char* descr ) ;
char* text_get_description ( text_t* ) ;

void text_set_comment ( text_t*, char* com ) ;
char* text_get_comment ( text_t* ) ; 


////////////////////MEASUREMENT
typedef struct {
    
    int tag[TAILLE];
    int tag_size;
    auteur_t* auteur;
    color_t color;
    timecode_t time_start;
    timecode_t time_end;
    char* description; //On y précisera l'unité
   
    double value; 
    
} measure_t;

measure_t* measure_new () ; 
void measure_del ( measure_t* ) ;
void measure_show ( measure_t* ) ;

void measure_add_tag ( measure_t*, int tag ) ; 
void measure_remove_tag ( measure_t*, int tag ) ;
void measure_show_tag ( measure_t* ) ; 

void measure_set_color ( measure_t*, color_t* color) ;
color_t measure_get_color ( measure_t* ) ;

void measure_set_time_start ( measure_t*, timecode_t time_s ) ;
timecode_t measure_get_time_start ( measure_t* );

void measure_set_time_end ( measure_t*, timecode_t time_e ) ;
timecode_t measure_get_time_end ( measure_t* );

void measure_set_description ( measure_t*, char* descr ) ;
char* measure_get_description ( measure_t* ) ;

void measure_set_value ( measure_t*, double val ) ;
double measure_get_value ( measure_t* ) ;



//////////////////////MOVING CROSS
typedef struct { //TODO

    int tag[TAILLE];
    int tag_size;
    auteur_t* auteur;
    char* color;
    char* time_start;
    char* time_end;

    char* description;

} moving_cross_t;

moving_cross_t* moving_cross_new() ; 
void moving_cross_del (  moving_cross_t* ) ;
void  moving_cross_show (  moving_cross_t* ) ;

void moving_cross_add_tag (  moving_cross_t*, int tag ) ; 
void moving_cross_remove_tag ( moving_cross_t*, int tag ) ;
void moving_cross_show_tag ( moving_cross_t* ) ; 

void moving_cross_set_color ( moving_cross_t*, color_t* color) ;
color_t moving_cross_get_color ( moving_cross_t* ) ;

void moving_cross_set_time_start ( moving_cross_t*, timecode_t time_s ) ;
timecode_t moving_cross_get_time_start ( moving_cross_t* );

void moving_cross_set_time_end ( moving_cross_t*, timecode_t time_e ) ;
timecode_t moving_cross_get_time_end ( moving_cross_t* );

void moving_cross_set_description ( moving_cross_t*, char* descr ) ;
char* moving_cross_get_description ( moving_cross_t* ) ;



#endif
