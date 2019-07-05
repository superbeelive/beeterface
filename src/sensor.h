#ifndef SENSOR_H
#define SENSOR_H

typedef enum {
    SENSOR_HYGUSB,
    SENSOR_TEMP_ARRAY_V01
} sensor_type_t ;

const char* sensor_type_to_string( sensor_type_t ) ;

typedef struct {
    char* serial;               // Serial number
    char* name;                 // Displayed name
    char* model;                // Model
    sensor_type_t type;         // sensor type (type enum)
    char* notes;                // Comments and notes
    char* hw_handle ;           // handle used to access hardware. Can be of any type depending on type
} sensor_t ; 


sensor_t* sensor_new() ;
void sensor_del (sensor_t*);
void sensor_show (int, sensor_t*);

void sensor_set_name (sensor_t*, const char*);
char* sensor_get_name (sensor_t*);

void sensor_set_model (sensor_t*, const char*);
char* sensor_get_model (sensor_t*);

void sensor_set_serial (sensor_t*, const char*);
char* sensor_get_serial (sensor_t*);

void sensor_set_type (sensor_t*, sensor_type_t type);
sensor_type_t sensor_get_type (sensor_t*);

void sensor_set_notes (sensor_t*, const char*);
char* sensor_get_notes (sensor_t*);

void sensor_set_hw_handle  (sensor_t*, const char*);
char* sensor_get_hw_handle (sensor_t*);

#endif
