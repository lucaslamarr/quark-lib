#ifndef QUARK_H
#define QUARK_H

/*-------------------------
 -----BOOL DECLARATIONS-----
 -------------------------*/

#define false 0
#define true 1

typedef struct 
{ 
    char state;
} Bool;

/*-------------------------
 -TYPE LIMITS DECLARATIONS--
 -------------------------*/

/*This section returns the maximum and minimum value of the specified data types.*/
/*NOTE: Returns the ASCII symbol but can be casted to return the integer type.*/

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

/*NOTE: This codebase was compiled using C89 standards, while long long is supported through
GCC extensions, I do not want to add code that will not run on the base GNU GCC compiler.

long long int get_max_long_long_value();
long long int get_min_long_long_value();
unsigned long long int get_max_unsigned_long_long_value();*/

/*-------------------------
 ---VECTOR 2 DECLARATIONS---
 -------------------------*/

typedef struct /*Holds positional data relative to an X and Y grid coordinate system.*/
{
    /*Uses floats by default but can be casted to an integer.*/
    float x;
    float y;
} Vector2; 

typedef struct /*Holds positional data relative to an X, Y, and Z grid coordinate system.*/
{
    float x;
    float y;
    float z;
} Vector3; 

/*Finds the center point between the x, y, z or all positions on two Vectors.*/
/*NOTE: No pointer parameters for Vector2's because there is no benefit while the structs are also 8 bytes in size.*/

float vector2_get_meeting_point_x(Vector2, Vector2); 
float vector2_get_meeting_point_y(Vector2, Vector2);
Vector2 vector2_get_meeting_point_all(Vector2, Vector2);

/*NOTE: Using pointer parameters for Vector3's because the struct size exeeds the size of 64 bit pointer.*/

float vector3_get_meeting_point_x(Vector3*, Vector3*); 
float vector3_get_meeting_point_y(Vector3*, Vector3*);
float vector3_get_meeting_point_z(Vector3*, Vector3*);
Vector3 vector3_get_meeting_point_all(Vector3*, Vector3*);

/*-------------------------
 -----MATH DECLARATIONS-----
 -------------------------*/

/*NOTE: Many of these return a value rather than directly modifying what is being passed in.
The user can simply assign a new value by calling these functions and passing itself as an argument.
While slightly long-winded, this allows the functions to be used in different ways.*/

float get_absolute_value_float(float); /*Returns the absolute value of a positive or negative number.*/
int get_absolute_value_int(int); 

float get_raised_power_value_float(float, int); /*Raises the provided value to the power of N.*/
int get_raised_power_value_int(int, int); 

float get_mod_value_float(float, float); /*Float counterpart to the modulus symbol that only works on integers.*/

float get_flipped_sign_float(float); /*Returns the argument value with the opposite sign.*/
int get_flipped_sign_int(int); 

/*NOTE: These next few functions allow you to directly modify the value and are a little bit more convenient.*/

void flip_sign_float(float*); /*Makes a positive number negative, and a negative number positive.*/
void flip_sign_int(int*); 

void round_float(float*); /*Anything .5 and above will be rounded to the next whole number, anything lower is truncated.*/
void round_float_up(float*); /*Increases the value to the next whole number.*/
void round_float_down(float*); /*Truncates the decimal place.*/

#endif
