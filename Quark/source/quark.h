#ifndef QUARK_H
#define QUARK_H

//TODO: All implementations need to work for other appropriate and similar data types (chars, ints, shorts, longs, long long, floats, doubles, long doubles)

//TODO: String manipulations
//TODO: Custom boolean implementation
//TODO: Introduce generic drawing module called Quark2D.h (seprate, optional for game devs)
//TODO: Limits for floating point types

//TODO: New common struct ideas
//TODO: Make functions polymorphic with overrides (nothing clever, just simple functions)

//TODO: Absolute value for ints
//TODO: Return remainder and quotient functions
//TODO: Function that returns smaller / larger value of 2 choices
//TODO: Get value difference between two numbers (larger - smaller = difference)

/*-------------------------
 -TYPE LIMITS DECLARATIONS--
 -------------------------*/

//NOTE: Returns shorts instead of chars because I do not want to show a symbol.
short get_max_char_value();
short get_min_char_value();
short get_max_unsigned_char_value();

short get_max_short_value();
short get_min_short_value();
unsigned short get_max_unsigned_short_value();

int get_max_int_value();
int get_min_int_value();
unsigned int get_max_unsigned_int_value();

long int get_max_long_value();
long int get_min_long_value();
unsigned long int get_max_unsigned_long_value();

long long int get_max_long_long_value();
long long int get_min_long_long_value();
unsigned long long int get_max_unsigned_long_long_value();

/*-------------------------
 ---VECTOR 2 DECLARATIONS---
 -------------------------*/

typedef struct //Holds positional data relative to an X and Y grid coordinate system. 
{
    //Uses floats by default but can be casted to an integer.
    float x;
    float y;
} Vector2; 

typedef struct //Holds positional data relative to an X, Y, and Z grid coordinate system. 
{
    //Uses floats by default but can be casted to an integer.
    float x;
    float y;
    float z;
} Vector3; 


//Finds the center point between the x, y, or both positions on two Vector2's.
float vector2_get_meeting_point_x(Vector2, Vector2); 
float vector2_get_meeting_point_y(Vector2, Vector2);
Vector2 vector2_get_meeting_point_all(Vector2, Vector2);

float vector3_get_meeting_point_x(Vector3, Vector3); 
float vector3_get_meeting_point_y(Vector3, Vector3);
float vector3_get_meeting_point_Z(Vector3, Vector3);
Vector3 vector3_get_meeting_point_all(Vector3, Vector3);

//NOTE: No pointer parameters because there is no benefit while the structs are also 8 bytes in size.

/*-------------------------
 -----MATH DECLARATIONS-----
 -------------------------*/

//NOTE: Many of these return a value rather than directly modifying what is being passed in.
//      The user can simply assign a new value by calling these functions and passing itself.
//      While slightly long-winded, this allows the functions to be used in different ways.

float get_absolute_value_float(float); //Returns the absolute value of a positive or negative number.
float get_raised_power_value_float(float, int); //Raises the provided value to the n power.
float get_modulus_value_float(float*, float); //The modulus only works on integers by default.

void flip_sign_float(float*); //Makes a positive number negative, and a negative number positive.

void round_float(float*); //Anything .5 and above will be rounded to the next whole number, anything has the decimal removed.
void round_up_float(float*); //Removes everything after the decimal place and increases by 1 whole number.
void round_down_float(float*); //Removes everything after the decimal place no matter what the value is.

//TODO: Square root

#endif //QUARK_H
