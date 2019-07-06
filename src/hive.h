#ifndef HIVE_H
#define HIVE_H

#include "module.h"

typedef struct {
    char* name ;            // nom du hive
    char* notes ;           // notes ou description
    
    module_t** modules ;    // Liste de modules
    int nb_modules ;
    int modules_size ;

} hive_t ;


hive_t* hive_new() ;
void hive_del( hive_t*) ;
void hive_show( int, hive_t*, int ) ;

void hive_set_name( hive_t*, const char* ) ;
char* hive_get_name(hive_t*) ;

void hive_set_notes( hive_t*, const char* ) ;
char* hive_get_notes( hive_t*) ;

void hive_del_module( hive_t*, int ) ;
void hive_add_module( hive_t*, module_t*) ;

#endif
