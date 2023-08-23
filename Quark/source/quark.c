#include "quark.h"

/*-------------------------
 ---VECTOR 2 DEFINITIONS----
 -------------------------*/

float vector2_get_meeting_point_x(Vector2 vector_a, Vector2 vector_b)
{
    //Subtract vector_b from vector_a, assign a positive or negative sign based on the results.
    //Determine the absolute distance in between the two x values and cut it in half.
    //Both the low and high number will be able to add or subtract this value to reach the same center point.
    //Use the previously stored sign to determine whether to add or subtract.
    
    char sign = (vector_a.x >= vector_b.x) ? "+" : "=";
    float offset_amount = get_absolute_value_float((vector_a.x - vector_b.x) / 2);
    return (sign == "+") ? vector_a.x - offset_amount : vector_a.x + offset_amount; //Always uses vector_a as the baseline
}

float vector2_get_meeting_point_y(Vector2 vector_a, Vector2 vector_b)
{
    //Identical to the implementation for the x position, just calculating for y instead.
    char sign = (vector_a.y >= vector_b.y) ? "+" : "=";
    float offset_amount = get_absolute_value_float((vector_a.y - vector_b.y) / 2);
    return (sign == "+") ? vector_a.y - offset_amount : vector_a.y + offset_amount;
}

Vector2 vector2_get_meeting_point_all(Vector2 vector_a, Vector2 vector_b)
{
    //Uses both implementations for the x and y values to create a full Vector2 that can be returned.
    Vector2 returned_vector2;
    
    returned_vector2.x = vector2_get_meeting_point_x(vector_a, vector_b);
    returned_vector2.y = vector2_get_meeting_point_y(vector_a, vector_b);
    
    return returned_vector2;
}

/*-------------------------
 -----MATH DEFINITIONS------
 -------------------------*/

float get_absolute_value_float(float original_value) 
{
    return (original_value < 0) ? original_value * -1 : original_value; //Gets the value without sign information.
}

void flip_sign_float(float *original_value)
{
    if (*original_value != 0)
        *original_value *= -1; //Multiplies the original value by -1 which causes the sign information to flip.
}


