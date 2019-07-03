#ifndef CAMERA_H
#define CAMERA_H

typedef enum {
    CAM_USB_UVC,
    CAM_ETH
} camera_type_t ;


typedef struct {
    char* name;                 // Displayed name
    char* model;                // Model
    char* serial;               // Serial number
    camera_type_t type;         // camera type (type enum)
    char* description;          // Comments and description
} camera_t ; 


const char* camera_type_to_string( camera_type_t ) ;


camera_t* camera_new() ;
void camera_del (camera_t*);
void camera_show (camera_t*);

// Name
void camera_set_name (camera_t*, const char* name);
char* camera_get_name (camera_t*);

// Model
void camera_set_model (camera_t*, const char* model);
char* camera_get_model (camera_t*);

// Nserie
void camera_set_serial (camera_t*, const char* serial);
char* camera_get_serial (camera_t*);

// Type
void camera_set_type (camera_t*, camera_type_t type);
camera_type_t camera_get_type (camera_t*);

// Description
void camera_set_description (camera_t*, const char* description);
char* camera_get_description (camera_t*);

#endif
