#ifndef QUARK_H
#define QUARK_H

/*-------------------------
 ---VECTOR 2 DECLARATIONS---
 -------------------------*/

typedef struct //Holds positional data relative to an X and Y grid coordinate system. 
{
    //Uses floats by default but can be casted to an integer.
    float x;
    float y;
} Vector2; 

//Finds the center point between the x, y, or both positions on two Vector2's.
float vector2_get_meeting_point_x(Vector2, Vector2); 
float vector2_get_meeting_point_y(Vector2, Vector2);
Vector2 vector2_get_meeting_point_all(Vector2, Vector2);

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

//Square root

#endif //QUARK_H
