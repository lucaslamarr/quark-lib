#ifndef QUARK_H
#define QUARK_H

/*-------------------------
 -----------BOOLEAN--------
 -------------------------*/

/* Custom implementation of the boolean type that is absent from C89. */
/* If stdbool.h is already included, skip this step. */

#ifndef _STDBOOL_H         
    #ifndef bool            /* Won't override pre-existing bool made by the user. */
        typedef char bool;  /* Using 1 byte char instead of a full integer value. */
        #define true  '1'   /* true and false values will expand to the '1' and '0' characters. */
        #define false '0'
    #endif
#endif

/*-------------------------
 --------TYPE LIMITS-------
 -------------------------*/

/* This section returns the maximum and minimum value of the specified data types. */
/* Char returns the ASCII symbol but can be casted to return an integer value. */

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

float get_max_float_value();
float get_min_float_value();

/* Doubles are not being reported consistently with GCC and have been excluded for now. */

/*-------------------------
 ----------VECTOR 2--------
 -------------------------*/

/* Holds positional data relative to an X and Y coordinate system. */
/* Uses floats by default but can be casted to an integer. */

typedef struct 
{
    float x;
    float y;
} Vector2; 

typedef struct
{
    float x;
    float y;
    float z;
} Vector3; 

/* Finds the center point between individual axis' or all positions on two Vectors. */
/* No pointer parameters for Vector2's because there is no benefit while the structs are also 8 bytes in size. */

float vector2_get_meeting_point_x(Vector2, Vector2); 
float vector2_get_meeting_point_y(Vector2, Vector2);
Vector2 vector2_get_meeting_point_all(Vector2, Vector2);

/* Using pointer parameters for Vector3's because the struct exceeds the size of a 64 bit pointer. */

float vector3_get_meeting_point_x(Vector3*, Vector3*); 
float vector3_get_meeting_point_y(Vector3*, Vector3*);
float vector3_get_meeting_point_z(Vector3*, Vector3*);
Vector3 vector3_get_meeting_point_all(Vector3*, Vector3*);

/*-------------------------
 -----------MATH-----------
 -------------------------*/

/* Many of these return a value rather than directly modifying what is being passed in.
The user can simply assign a new value by calling these functions and passing itself as an argument. 
While slightly long-winded, this allows the functions to be used both for assignment and getting values.*/

/* Returns the absolute value of a positive or negative number. */

float get_absolute_value_float(float); 
int get_absolute_value_int(int); 

/* Raises the provided value to the nth power. */

float get_raised_power_value_float(float, int); 
int get_raised_power_value_int(int, int); 

/* Float alternative to the modulus operaetor that only worked on integers. */

float get_mod_value_float(float, float); 

/* Returns the argument value with the opposite sign. */

float get_flipped_sign_float(float); 
int get_flipped_sign_int(int); 

/* Float rounding. */

void round_float(float*);      /* Anything 0.5 and above will be rounded to the next whole number, anything lower is truncated. */
void round_float_up(float*);   /* Increases the value to the next whole number. */
void round_float_down(float*); /* Truncates the decimal place. */

#endif
