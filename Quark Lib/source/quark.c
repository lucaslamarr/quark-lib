#include "quark.h"

/*-------------------------
 --TYPE LIMITS DEFINITIONS--
 -------------------------*/

/*NOTE: Using a short for chars so that I return a small number and not a symbol.*/
/*NOTE: MSVC will sometimes throw an error for writing the actual min value, applying -1 seems to be a workaround.*/

char get_max_char_value()                             { return 127;      }
char get_min_char_value()                             { return -127 - 1; } 
unsigned char get_max_unsigned_char_value()           { return 255;      }

short get_max_short_value()                           { return 32767;      }
short get_min_short_value()                           { return -32767 - 1; } 
unsigned short get_max_unsigned_short_value()         { return 65535;      }

int get_max_int_value()                               { return 2147483647;      }
int get_min_int_value()                               { return -2147483647 - 1; } 
unsigned int get_max_unsigned_int_value()             { return 4294967295U;      }

long get_max_long_value()                             { return 2147483647;      }
long get_min_long_value()                             { return -2147483647 - 1; } 
unsigned long get_max_unsigned_long_value()           { return 4294967295UL;      }

/*NOTE: This codebase was compiled using C89 standards, while long long is supported through
GCC, I do not want to add code in here that is dependent on extensions or specific compilers.

long long get_max_long_long_value()                   { return 9223372036854775807;     }
long long get_min_long_long_value()                   { return -9223372036854775807;    }
unsigned long long get_max_unsigned_long_long_value() { return 18446744073709551615ULL; }*/

/*NOTE: All values checked alongside the C99 Limits.h macros.*/
/*NOTE: Actual min limit of long long is +1 but gcc does not match the limits.h macro for the min value.*/

/*-------------------------
 ---VECTOR 2 DEFINITIONS----
 -------------------------*/

float vector2_get_meeting_point_x(Vector2 vector_a, Vector2 vector_b)
{
    /*Subtract vector_b from vector_a, store a positive or negative sign based on the results.
    Determine the absolute distance in between the two x values and cut it in half.
    Both the low and high number will be able to add or subtract this value to reach the same center point.
    Use the previously stored sign to determine whether to add or subtract.*/
    
    char sign = (vector_a.x >= vector_b.x) ? '+' : '=';
    float offset_amount = get_absolute_value_float((vector_a.x - vector_b.x) / 2.0f);
    return (sign == '+') ? vector_a.x - offset_amount : vector_a.x + offset_amount; /*Always uses vector_a as the baseline.*/
}

float vector2_get_meeting_point_y(Vector2 vector_a, Vector2 vector_b)
{
    /*Identical to the implementation for the x position, just calculating for y instead.*/
    
    char sign = (vector_a.y >= vector_b.y) ? '+' : '=';
    float offset_amount = get_absolute_value_float((vector_a.y - vector_b.y) / 2.0f);
    return (sign == '+') ? vector_a.y - offset_amount : vector_a.y + offset_amount;
}

Vector2 vector2_get_meeting_point_all(Vector2 vector_a, Vector2 vector_b)
{ 
    /*Uses both implementations for the x and y values to create a full Vector2 that can be returned.*/
    
    Vector2 returned_vector2;
    
    returned_vector2.x = vector2_get_meeting_point_x(vector_a, vector_b);
    returned_vector2.y = vector2_get_meeting_point_y(vector_a, vector_b);
    
    return returned_vector2;
}

/*All of these work exactly the same as the Vector2 functions, except these also check the z position.*/

float vector3_get_meeting_point_x(Vector3 *vector_a, Vector3 *vector_b)
{
    char sign = (vector_a->x >= vector_b->x) ? '+' : '=';
    float offset_amount = get_absolute_value_float((vector_a->x - vector_b->x) / 2.0f);
    return (sign == '+') ? vector_a->x - offset_amount : vector_a->x + offset_amount;
}

float vector3_get_meeting_point_y(Vector3 *vector_a, Vector3 *vector_b)
{
    char sign = (vector_a->y >= vector_b->y) ? '+' : '=';
    float offset_amount = get_absolute_value_float((vector_a->y - vector_b->y) / 2.0f);
    return (sign == '+') ? vector_a->y - offset_amount : vector_a->y + offset_amount;
}

float vector3_get_meeting_point_z(Vector3 *vector_a, Vector3 *vector_b)
{
    char sign = (vector_a->z >= vector_b->z) ? '+' : '=';
    float offset_amount = get_absolute_value_float((vector_a->z - vector_b->z) / 2.0f);
    return (sign == '+') ? vector_a->z - offset_amount : vector_a->z + offset_amount;
}

Vector3 vector3_get_meeting_point_all(Vector3 *vector_a, Vector3 *vector_b)
{
    Vector3 returned_vector3;
    
    returned_vector3.x = vector3_get_meeting_point_x(vector_a, vector_b);
    returned_vector3.y = vector3_get_meeting_point_y(vector_a, vector_b);
    returned_vector3.z = vector3_get_meeting_point_z(vector_a, vector_b);
    
    return returned_vector3;
}

/*-------------------------
 -----MATH DEFINITIONS------
 -------------------------*/

/*Gets the value without sign information. This is done by multiplying by -1 and if the original value is
 a positive number then it is already considered to be the absolute value.*/

float get_absolute_value_float(float original_value) 
{
    return (original_value < 0.0f) ? original_value * -1.0f : original_value; 
}

int get_absolute_value_int(int original_value) 
{
    return (original_value < 0.0f) ? original_value * -1.0f : original_value; 
}

/*Takes the original value and multiplies itself by the number of times determined by the exponent.*/

float get_raised_power_value_float(float original_value, int exponent)
{
    float returned_value = original_value; /*Can't start from zero because this number gets multiplied.*/
    
	int i;
	for(i = 1; i < exponent; i++)
	{
		returned_value *= original_value; 
	}
    
	return returned_value;
}

int get_raised_power_value_int(int original_value, int exponent)
{
    int returned_value = original_value; 
    
	int i;
	for(i = 1; i < exponent; i++)
	{
		returned_value *= original_value;
	}
	
	return returned_value;
}

/*Multiplies the original value by -1 which causes the sign information to flip.*/

float get_flipped_sign_float(float original_value)
{
    if (original_value != 0.0f)
        return original_value *= -1.0f; 
}

int get_flipped_sign_int(int original_value)
{
    if (original_value != 0)
        return original_value *= -1; 
}

/*Modifies the value directly by calling the float and int return versions with itself 
as an argument to prevent re-writing the same code again.*/

void flip_sign_float(float *original_value)
{
    *original_value = get_flipped_sign_float(*original_value);
}

void flip_sign_int(int *original_value)
{
    *original_value = get_flipped_sign_int(*original_value);
}

/*Initially returns a number that perfectly divides into the original value and then uses that 
number to store the quotient and remainder. The remainder can be found by subtracting the quotient 
from the number that perfectly divides into the original value, and then multiplying it by the 
divisor to get the actual mod results.*/

float get_mod_value_float(float original_value, float divisor)
{
	float full_value = (original_value / divisor); /*This number perfectly divides into the original value.*/    
    float quotient_value = (int)full_value; /*Truncates the full value down to a whole number.*/                
    float remainder_value = full_value - quotient_value; /*Gets the individual remainder from each divide.*/ 
    
	return remainder_value * divisor; /*This returns the actual remainder after all divides have been made*/
}

/*Rounds the number up or down based on how large it is. Anything that is 0.5 or above for the decimal place 
will be rounded up and anything that is below 0.5 will be rounded down. This works by truncating the decimal 
place on a value, and then also increasing the value by 1 if rounding up.*/

void round_float(float *original_value)
{
    float temp = *original_value;
    round_float_down(&temp); /*Storing temp value to be rounded down and used below.*/
    
    /*If the remainder is greater than or equal to 0.5, round up, otherwise round down.*/
    
    if (*original_value - temp >= 0.5f) 
        round_float_up(original_value);
	else
        round_float_down(original_value);
}

void round_float_up(float *original_value)
{
	int rounded_number = (int)*original_value + 1; /*Truncate the number and add 1 to get the rounded up whole number.*/
    *original_value = (float)rounded_number; /*Convert back to float.*/
}

void round_float_down(float *original_value)
{
	int rounded_number = (int)*original_value; /*Truncate the number to get the rounded down whole number.*/
    *original_value = (float)rounded_number; 
}

/*If number a is smaller than b, return it and vice versa.*/

float get_smaller_number_float(float a, float b)
{
    return (a > b) ? a : b; 
}

int get_smaller_number_int(int a, int b)
{
    return (a > b) ? a : b; 
}

/*If number a is larger than b, return it and vice versa.*/

float get_larger_number_float(float a, float b)
{
    return (a > b) ? a : b; 
}

int get_larger_number_int(int a, int b)
{
    return (a > b) ? a : b; 
}

/*If number a is larger than number b, subtract b from a to get the difference and vice versa.*/

float get_difference_float(float a, float b)
{
    if (a > b)
        return a - b;
    else if (b > a)
        return b - a;
    else
        return 0.0f;
}

int get_difference_int(int a, int b)
{
    if (a > b)
        return a - b;
    else if (b > a)
        return b - a;
    else
        return 0;
}
