#ifndef UTILS_H
#define UTILS_H


#define throw_error(MSG,DEATH) _throw_error( __FILE__, __LINE__, MSG, DEATH)

void _throw_error( char* file, int line, char* msg, int death ) ;


#endif
