#ifndef QUARKCORE_H
#define QUARKCORE_H

/* TODO: Figure out what really belongs in Core. Or get rid of core all together. */

/*-------------------------
 ----BOOLEAN DECLARATIONS---
 -------------------------*/

#ifndef _STDBOOL_H /* If stdbool.h is already included, skip this step */
#ifndef bool /* Won't override pre existing bool solution made by the user. */
typedef char bool;
#define true  '1'
#define false '0'
#endif
#endif

/*-------------------------
 -TYPE LIMITS DECLARATIONS--
 -------------------------*/

/* This section returns the maximum and minimum value of the specified data types. */
/* NOTE: Returns the ASCII symbol but can be casted to return the integer type. */

char get_max_char_value();
char get_min_char_value();
unsigned char get_max_unsigned_char_value();

short get_max_short_value();
short get_min_short_value();
unsigned short get_max_unsigned_short_value();

int get_max_int_value();
int get_min_int_value();
unsigned int get_max_unsigned_int_value();

long int get_max_long_value();
long int get_min_long_value();
unsigned long int get_max_unsigned_long_value();

/*-------------------------
 ---VECTOR 2 DECLARATIONS---
 -------------------------*/

typedef struct /* Holds positional data relative to an X and Y grid coordinate system. */
{
    /* Uses floats by default but can be casted to an integer. */
    float x;
    float y;
} Vector2; 

typedef struct /* Holds positional data relative to an X, Y, and Z grid coordinate system. */
{
    float x;
    float y;
    float z;
} Vector3; 

/* Finds the center point between the x, y, z or all positions on two Vectors. */
/* NOTE: No pointer parameters for Vector2's because there is no benefit while the structs are also 8 bytes in size. */

float vector2_get_meeting_point_x(Vector2, Vector2); 
float vector2_get_meeting_point_y(Vector2, Vector2);
Vector2 vector2_get_meeting_point_all(Vector2, Vector2);

/* NOTE: Using pointer parameters for Vector3's because the struct size exeeds the size of a 64 bit pointer. */

float vector3_get_meeting_point_x(Vector3*, Vector3*); 
float vector3_get_meeting_point_y(Vector3*, Vector3*);
float vector3_get_meeting_point_z(Vector3*, Vector3*);
Vector3 vector3_get_meeting_point_all(Vector3*, Vector3*);

#endif
