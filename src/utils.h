#ifndef UTILS_H
#define UTILS_H


#define STRING_SIZE 128
#define BLOC_SIZE 50


void indent( int ) ;

#define throw_error(MSG,DEATH) _throw_error( __FILE__, __LINE__, MSG, DEATH)
void _throw_error( char* file, int line, char* msg, int death ) ;

#endif
