#include "quark.h"

/*-------------------------
 -TYPE LIMITS DECLARATIONS--
 -------------------------*/

short get_max_char_value() { return 127; }
short get_min_char_value() { return -128; }
short get_max_unsigned_char_value() { return 255; }

short get_max_short_value() { return 32767; }
short get_min_short_value() { return -32768; }
unsigned short get_max_unsigned_short_value() { return 65535; }

int get_max_int_value() { return 2147483647; }
int get_min_int_value() { return -2147483648; }
unsigned int get_max_unsigned_int_value() { return 4294967295; }

long get_max_long_value() { return 2147483647; }
long get_min_long_value() { return -2147483648; }
unsigned long get_max_unsigned_long_value() { return 4294967295; }

long long get_max_long_long_value() { return 9223372036854775807; }

//NOTE: Actual limit is +1 but gcc does not match the limits.h macro for the min value.
long long get_min_long_long_value() { return -9223372036854775807; } 

unsigned long long get_max_unsigned_long_long_value() { return 18446744073709551615ULL; }

/*-------------------------
 ---VECTOR 2 DEFINITIONS----
 -------------------------*/

float vector2_get_meeting_point_x(Vector2 vector_a, Vector2 vector_b)
{
    //Subtract vector_b from vector_a, assign a positive or negative sign based on the results.
    //Determine the absolute distance in between the two x values and cut it in half.
    //Both the low and high number will be able to add or subtract this value to reach the same center point.
    //Use the previously stored sign to determine whether to add or subtract.
    
    char sign = (vector_a.x >= vector_b.x) ? '+' : '=';
    float offset_amount = get_absolute_value_float((vector_a.x - vector_b.x) / 2.0f);
    return (sign == '+') ? vector_a.x - offset_amount : vector_a.x + offset_amount; //Always uses vector_a as the baseline
}

float vector2_get_meeting_point_y(Vector2 vector_a, Vector2 vector_b)
{
    //Identical to the implementation for the x position, just calculating for y instead.
    char sign = (vector_a.y >= vector_b.y) ? '+' : '=';
    float offset_amount = get_absolute_value_float((vector_a.y - vector_b.y) / 2.0f);
    return (sign == '+') ? vector_a.y - offset_amount : vector_a.y + offset_amount;
}

Vector2 vector2_get_meeting_point_all(Vector2 vector_a, Vector2 vector_b)
{
    //Uses both implementations for the x and y values to create a full Vector2 that can be returned.
    Vector2 returned_vector2;
    
    returned_vector2.x = vector2_get_meeting_point_x(vector_a, vector_b);
    returned_vector2.y = vector2_get_meeting_point_y(vector_a, vector_b);
    
    return returned_vector2;
}

float vector3_get_meeting_point_x(Vector3 vector_a, Vector3 vector_b)
{
    //Subtract vector_b from vector_a, assign a positive or negative sign based on the results.
    //Determine the absolute distance in between the two x values and cut it in half.
    //Both the low and high number will be able to add or subtract this value to reach the same center point.
    //Use the previously stored sign to determine whether to add or subtract.
    
    char sign = (vector_a.x >= vector_b.x) ? '+' : '=';
    float offset_amount = get_absolute_value_float((vector_a.x - vector_b.x) / 2.0f);
    return (sign == '+') ? vector_a.x - offset_amount : vector_a.x + offset_amount; //Always uses vector_a as the baseline
}

float vector3_get_meeting_point_y(Vector3 vector_a, Vector3 vector_b)
{
    //Identical to the implementation for the x position, just calculating for y instead.
    char sign = (vector_a.y >= vector_b.y) ? '+' : '=';
    float offset_amount = get_absolute_value_float((vector_a.y - vector_b.y) / 2.0f);
    return (sign == '+') ? vector_a.y - offset_amount : vector_a.y + offset_amount;
}

float vector3_get_meeting_point_z(Vector3 vector_a, Vector3 vector_b)
{
    //Identical to the implementation for the x and y positions, just calculating for Z instead.
    char sign = (vector_a.z >= vector_b.z) ? '+' : '=';
    float offset_amount = get_absolute_value_float((vector_a.z - vector_b.z) / 2.0f);
    return (sign == '+') ? vector_a.z - offset_amount : vector_a.z + offset_amount;
}

Vector3 vector3_get_meeting_point_all(Vector3 vector_a, Vector3 vector_b)
{
    //Uses both implementations for the x and y values to create a full Vector2 that can be returned.
    Vector3 returned_vector3;
    
    returned_vector3.x = vector3_get_meeting_point_x(vector_a, vector_b);
    returned_vector3.y = vector3_get_meeting_point_y(vector_a, vector_b);
    returned_vector3.z = vector3_get_meeting_point_z(vector_a, vector_b);
    
    return returned_vector3;
}

/*-------------------------
 -----MATH DEFINITIONS------
 -------------------------*/

float get_absolute_value_float(float original_value) 
{
    return (original_value < 0.0f) ? original_value * -1.0f : original_value; //Gets the value without sign information.
}

float get_raised_power_value_float(float original_value, int exponent)
{
	//Takes the original value and multiplies itself a number of times determined by the exponent
	float returned_value = original_value; //Can't start from zero because this number gets multiplied
	
	for(int i = 1; i < exponent; i++)
	{
		returned_value *= original_value;
	}
	
	return returned_value;
}

void flip_sign_float(float *original_value)
{
    if (*original_value != 0.0f)
        *original_value *= -1.0f; //Multiplies the original value by -1 which causes the sign information to flip.
}


//TODO: This needs more work in order to continue writing the rounding functions. Can't divide by 1...
float get_modulus_value_float(float *original_value, float divisor)
{
	float modulus_value = (*original_value / divisor);
	modulus_value = *original_value - modulus_value;
	
	return modulus_value;
}

void round_float(float *original_value)
{
	float value_to_remove = get_modulus_value_float(original_value, 1.0);
	
	if (value_to_remove >= 0.5f)
		round_up_float(original_value);
	else
		round_down_float(original_value);
}

void round_up_float(float *original_value)
{
	float value_to_remove = get_modulus_value_float(original_value, 1.0);
	*original_value -= value_to_remove + 1.0f;
}

void round_down_float(float *original_value)
{
	float value_to_remove = get_modulus_value_float(original_value, 1.0);
	*original_value -= value_to_remove;
}



