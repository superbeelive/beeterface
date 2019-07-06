#include <stdio.h>
#include <stdlib.h>

#include "hive.h"
#include "utils.h"


hive_t* hive_new() {
    hive_t* tmp ;
    tmp = (hive_t*) malloc(sizeof(hive_t)) ;
    if ( tmp==NULL ) {
        throw_error("malloc failed", 1 ) ;
        return NULL ;
    }
    tmp->notes=(char*) malloc( STRING_SIZE ) ;
    if ( tmp->notes == NULL ) {
        throw_error("malloc failed", 1 ) ;
        return NULL ;
    }
    tmp->modules = (module_t**) malloc ( BLOC_SIZE * sizeof(module_t*) ) ;
    if ( tmp->modules == NULL ) {
        throw_error("malloc failed", 1 ) ;
        return NULL ;
    }
    sprintf(tmp->name, "Unnamed hive") ;
    sprintf(tmp->notes,"N/A") ;
    tmp->nb_modules = 0 ;
    tmp->modules_size = BLOC_SIZE ;
    return tmp ;
}

void hive_del( hive_t* mod ) {
    int i ;
    free(mod->name) ;
    free(mod->notes) ;
    for (i=0;i<mod->nb_modules;i++) {
        module_del(mod->modules[i]) ;
    }
    free(mod->modules) ;
    free(mod) ;
}

void hive_show( int ind, hive_t* mod, int recur ) {
    int i ;
    indent(ind) ;
    printf("Module:\n") ;
    indent(ind) ;
    printf("  Name: %s\n", mod->name ) ;
    indent(ind) ;
    printf("  Notes:\n");
    indent(ind) ;
    printf("  %s\n", mod->notes ) ;
    if ( recur ) {
        for (i=0; i<mod->nb_modules; i++)
            module_show( ind+1, mod->modules[i], 1 ) ;
    }
}

void hive_set_name( hive_t* mod, const char* name) {
    sprintf(mod->name,"%s",name) ;
}

char* hive_get_name( hive_t* mod ) {
    return mod->name ;
}

void hive_set_notes( hive_t* mod, const char* notes) {
    sprintf(mod->notes,"%s",notes) ;
}

char* hive_get_notes( hive_t* mod ) {
    return mod->notes ;
}

void hive_del_module( hive_t* mod, int n ) {
    int i ;
    if ((n<0) || (n >= mod->nb_modules)) {
        throw_error("invalid index",0);
        return ;
    }
   module_del(mod->modules[n]) ;
   for(i=n+1;i<mod->nb_modules;i++) {
        mod->modules[i-1]=mod->modules[i] ;
   }
   mod->nb_modules -= 1 ;
}

void hive_add_module( hive_t* hive, module_t* module ) {
    if (hive->nb_modules == hive->modules_size ) {
        hive->modules = reallocarray( hive->modules, hive->modules_size+BLOC_SIZE, sizeof(module_t*) ) ;
        hive->modules_size += BLOC_SIZE ;
    }
    hive->modules[hive->nb_modules] = module ;
    hive->nb_modules +=1 ;
}

