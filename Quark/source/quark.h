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

float get_absolute_value_float(float); //Returns the absolute value of a positive or negative number.
void flip_sign_float(float*); //Makes a positive number negative, and a negative number positive.

#endif //QUARK_H
