#include "quarkmath.h"

/*-------------------------
 ---------GENERAL-----------
 -------------------------*/

/*Gets the value without sign information. This is done by multiplying by -1 and if the original 
value is a positive number then it is already considered to be the absolute value.*/

float get_absolute_value_float(float original_value) 
{
    return (original_value < 0.0f) ? original_value * -1.0f : original_value; 
}

int get_absolute_value_int(int original_value) 
{
    return (original_value < 0.0f) ? original_value * -1.0f : original_value; 
}

/* Takes the original value and multiplies by the number of times determined by the exponent. */

float get_raised_power_value_float(float original_value, int exponent)
{
    float returned_value = original_value; /* Can't start from zero because this number gets multiplied. */
    
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

/* Multiplies the original value by -1 which causes the sign information to flip. */

float get_flipped_sign_float(float original_value)
{
    if (original_value != 0.0f)
        return original_value *= -1.0f; 
    else
        return original_value;
}

int get_flipped_sign_int(int original_value)
{
    if (original_value != 0)
        return original_value *= -1;
    else
        return original_value;
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
	float full_value = (original_value / divisor); /* This number perfectly divides into the original value. */ 
    float quotient_value = (int)full_value; /* Truncates the full value down to a whole number. */               
    float remainder_value = full_value - quotient_value; /* Gets the individual remainder from each divide. */
    
	return remainder_value * divisor; /* This returns the actual remainder after all divides have been made. */
}

/*Rounds the number up or down based on how large it is. Anything that is 0.5 or above for the decimal place 
will be rounded up and anything that is below 0.5 will be rounded down. This works by truncating the decimal 
place on a value, and then also increasing the value by 1 if rounding up.*/

void round_float(float *original_value)
{
    float temp = *original_value;
    round_float_down(&temp); /* Storing temp value to be rounded down and used below. */
    
    /* If the remainder is greater than or equal to 0.5, round up, otherwise round down. */
    
    if (*original_value - temp >= 0.5f) 
        round_float_up(original_value);
	else
        round_float_down(original_value);
}

void round_float_up(float *original_value)
{
	int rounded_number = (int)*original_value + 1; /* Truncate the number and add 1 to get the rounded up whole number. */
    *original_value = (float)rounded_number; /* Convert back to float. */
}

void round_float_down(float *original_value)
{
	int rounded_number = (int)*original_value; /* Truncate the number to get the rounded down whole number. */
    *original_value = (float)rounded_number; 
}

/* If number a is smaller than b, return it and vice versa. */

float get_smaller_number_float(float a, float b)
{
    return (a > b) ? a : b; 
}

int get_smaller_number_int(int a, int b)
{
    return (a > b) ? a : b; 
}

/* If number a is larger than b, return it and vice versa. */

float get_larger_number_float(float a, float b)
{
    return (a > b) ? a : b; 
}

int get_larger_number_int(int a, int b)
{
    return (a > b) ? a : b; 
}

/* If number a is larger than number b, subtract b from a to get the difference and vice versa. */

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