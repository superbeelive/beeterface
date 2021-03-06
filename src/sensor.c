#include <stdio.h>
#include <stdlib.h>

#include "sensor.h"
#include "utils.h"

const char* sensor_type_to_string( sensor_type_t T ) {
    switch (T) {
        case SENSOR_HYGUSB :
            return "SENSOR_HYGUSB" ;
        case SENSOR_TEMP_ARRAY_V01 :
            return "SENSOR_TEMPARRAY_V01" ;
        default:
            return "Unknown Camera";
    }
} 

sensor_t* sensor_new(){
    sensor_t* sensor;
    sensor = malloc (sizeof(sensor_t));
    if ( sensor == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    sensor->name = malloc (STRING_SIZE);
    if ( sensor->name == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    sensor->model = malloc (STRING_SIZE);
    if ( sensor->model == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    sensor->serial = malloc (STRING_SIZE);
    if ( sensor->serial == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    sensor->notes = malloc (STRING_SIZE);
    if ( sensor->notes == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    sensor->hw_handle = malloc (STRING_SIZE);
    if ( sensor->hw_handle == NULL ) {
       throw_error("malloc failed", 1 ) ;
       return NULL ;
    }
    sprintf(sensor->name, "Unnamed sensor");
    sprintf(sensor->model, "Unknown model");
    sprintf(sensor->serial, "00000");
    sensor->type = SENSOR_HYGUSB ;
    sprintf(sensor->notes, "N/A");
    sprintf(sensor->hw_handle, "-");

    return sensor;
}

void sensor_del ( sensor_t* sensor_a_del) {
    free (sensor_a_del->name);
    free (sensor_a_del->model);
    free (sensor_a_del->serial);
    free (sensor_a_del->notes);
    free (sensor_a_del);
}

void sensor_show ( int ind, sensor_t* sensor ) {
    indent (ind ) ;
    printf("Sensor:\n");
    indent(ind) ;
    printf("  Name: %s\n", sensor->name ) ;
    indent(ind) ;
    printf("  Model: %s\n", sensor->model ) ;
    indent(ind) ;
    printf("  Serial: %s\n", sensor->serial ) ;
    indent(ind) ;
    printf("  Type : %s\n", sensor_type_to_string(sensor->type) ) ;
    indent(ind) ;
    printf("  Hw_handle : %s\n", sensor->hw_handle ) ;
    indent(ind) ;
    printf("  Notes :\n");
    indent(ind) ;
    printf("  %s\n", sensor->notes ) ;
}


//Name 
void sensor_set_name (sensor_t* sensor_a_set, const char* name){
    sprintf(sensor_a_set->name,"%s",name);
}

char* sensor_get_name (sensor_t* sensor_a_get){
    return sensor_a_get->name;
}


//Model

void sensor_set_model (sensor_t* sensor_a_set, const char* model){
    sprintf(sensor_a_set->model,"%s",model);
}


char* sensor_get_model (sensor_t* sensor_a_get){
    return sensor_a_get->model;
}

//Nserie

void sensor_set_serial (sensor_t* sensor_a_set, const char* serial){
    sprintf(sensor_a_set->serial,"%s",serial);
}

char* sensor_get_serial (sensor_t* sensor_a_get){
    return sensor_a_get->serial;
}

//Type

void sensor_set_type (sensor_t* sensor_a_set, sensor_type_t type){
    sensor_a_set->type = type ;
}

sensor_type_t sensor_get_type (sensor_t* sensor_a_get){
    return sensor_a_get->type;
}

//Description

void sensor_set_notes (sensor_t* sensor_a_set, const char* notes){
    sprintf(sensor_a_set->notes,"%s",notes);
}

char* sensor_get_notes (sensor_t* sensor_a_get){
    return sensor_a_get->notes;
}


void sensor_set_hw_handle (sensor_t* sensor_a_set, const char* handle){
    sprintf(sensor_a_set->hw_handle,"%s",handle);
}

char* sensor_get_hw_handle (sensor_t* sensor_a_get){
    return sensor_a_get->hw_handle;
}
