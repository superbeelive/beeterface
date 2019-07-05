#ifndef CAMERA_H
#define CAMERA_H

typedef enum {
    CAM_USB_UVC,
    CAM_ETH
} camera_type_t ;

const char* camera_type_to_string( camera_type_t ) ;

typedef struct {
    char* serial;               // Serial number
    char* name;                 // Displayed name
    char* model;                // Model
    camera_type_t type;         // camera type (type enum)
    char* notes;                // Comments and notes
    char* hw_handle ;           // handle used to access hardware. Can be of any type depending on type
} camera_t ; 


camera_t* camera_new() ;
void camera_del (camera_t*);
void camera_show (camera_t*);

void camera_set_name (camera_t*, const char*);
char* camera_get_name (camera_t*);

void camera_set_model (camera_t*, const char*);
char* camera_get_model (camera_t*);

void camera_set_serial (camera_t*, const char*);
char* camera_get_serial (camera_t*);

void camera_set_type (camera_t*, camera_type_t type);
camera_type_t camera_get_type (camera_t*);

void camera_set_notes (camera_t*, const char*);
char* camera_get_notes (camera_t*);

void camera_set_hw_handle  (camera_t*, const char*);
char* camera_get_hw_handle (camera_t*);

#endif
