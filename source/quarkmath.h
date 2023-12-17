#ifndef QUARKMATH_H
#define QUARKMATH_H

/*-------------------------
 ---------GENERAL-----------
 -------------------------*/

/*NOTE: Many of these return a value rather than directly modifying what is being passed in.
The user can simply assign a new value by calling these functions and passing itself as an argument. While slightly long-winded, this allows the functions to be used in different ways.*/

float get_absolute_value_float(float); /* Returns the absolute value of a positive or negative number. */
int get_absolute_value_int(int); 

float get_raised_power_value_float(float, int); /* Raises the provided value to the power of N. */
int get_raised_power_value_int(int, int); 

float get_mod_value_float(float, float); /* Float counterpart to the modulus symbol that only works on integers. */

float get_flipped_sign_float(float); /* Returns the argument value with the opposite sign. */
int get_flipped_sign_int(int); 

/* NOTE: These next few functions allow you to directly modify the value and are a little bit more convenient. */

void flip_sign_float(float*); /* Makes a positive number negative, and a negative number positive. */
void flip_sign_int(int*); 

void round_float(float*); /* Anything .5 and above will be rounded to the next whole number, anything lower is truncated. */
void round_float_up(float*); /* Increases the value to the next whole number. */
void round_float_down(float*); /* Truncates the decimal place. */

#endif
