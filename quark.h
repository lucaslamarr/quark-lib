#ifndef QUARK_H
#define QUARK_H

/*-------------------------------------
 ---------BOOLEAN DECLARATIONS---------
 --------------------------------------*/

/* Custom implementation of the boolean type that is absent from C89. */
/* If stdbool.h is already included, skip this step. */

#ifndef _STDBOOL_H         
    #ifndef bool            /* Won't override pre-existing bool made by the user. */
        typedef char bool;  /* Using 1-byte char instead of a full integer value. */
        #define true  '1'   /* true and false values will expand to the '1' and '0' characters. */
        #define false '0'
    #endif
#endif

/*-------------------------------------
 -------TYPE LIMITS DECLARATIONS-------
 --------------------------------------*/

/* This section returns the maximum and minimum values of the specified data types. */
/* Char returns the ASCII symbol but can be cast to return an integer value. */

/* All values checked alongside the C99 Limits.h macros.*/

char get_max_char_value();
char get_min_char_value();
unsigned char get_max_unsigned_char_value();

short get_max_short_value();
short get_min_short_value();
unsigned short get_max_unsigned_short_value();

/* Actual min value sometimes throws an error. Applying -1 seems to be a workaround. */

int get_max_int_value();
int get_min_int_value();
unsigned int get_max_unsigned_int_value();

/* limits.h on the GCC compiler reports long values to be the same as an int */

long get_max_long_value();
long get_min_long_value();
unsigned long get_max_unsigned_long_value();

float get_max_float_value();
float get_min_float_value();

/* Doubles are not being reported consistently with GCC and have been excluded for now. */

/*-------------------------------------
 ---------VECTOR 2 DECLARATIONS--------
 --------------------------------------*/

/* Holds positional data relative to an X and Y coordinate system. */
/* Uses floats by default but can be cast to an integer. */

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

/* Finds the center point between individual axes or all positions on two Vectors. */
/* No pointer parameters for Vector2's because there is no benefit while the structs are also 8 bytes in size. */

float vector2_get_meeting_point_x(Vector2, Vector2); 
float vector2_get_meeting_point_y(Vector2, Vector2);
Vector2 vector2_get_meeting_point_all(Vector2, Vector2);

/* Using pointer parameters for Vector3's because the struct exceeds the size of a 64-bit pointer. */

float vector3_get_meeting_point_x(Vector3*, Vector3*); 
float vector3_get_meeting_point_y(Vector3*, Vector3*);
float vector3_get_meeting_point_z(Vector3*, Vector3*);
Vector3 vector3_get_meeting_point_all(Vector3*, Vector3*);

/*--------------------------------------
 -----------MATH DECLARATIONS-----------
 ---------------------------------------*/

/* Many of these return a value rather than directly modifying what is being passed.
The user can simply assign a new value by calling these functions and passing itself as an argument. 
While slightly long-winded, this allows the functions to be used both for assignment and getting values.*/

/* Returns the absolute value of a positive or negative number. */

float get_absolute_value_float(float); 
int get_absolute_value_int(int); 

/* Raises the provided value to the nth power. */

float get_raised_power_value_float(float, int); 
int get_raised_power_value_int(int, int); 

/* Float alternative to the modulus operator that only worked on integers. */

float get_mod_value_float(float, float); 

/* Returns the argument value with the opposite sign. */

float get_flipped_sign_float(float); 
int get_flipped_sign_int(int); 

/* Float rounding. */

void round_float(float*);      /* Anything 0.5 and above will be rounded to the next whole number, anything lower is truncated. */
void round_float_up(float*);   /* Increases the value to the next whole number. */
void round_float_down(float*); /* Truncates the decimal place. */

/*-------------------------------------
 -------TYPE LIMITS DEFINITIONS--------
 --------------------------------------*/

 /* All values checked alongside the C99 Limits.h macros.*/

static char get_max_char_value()                     { return 127;    }
static char get_min_char_value()                     { return -128;   }
static unsigned char get_max_unsigned_char_value()   { return 255;    }

static short get_max_short_value()                   { return 32767;  }
static short get_min_short_value()                   { return -32768; }
static unsigned short get_max_unsigned_short_value() { return 65535;  }

/* Actual min value sometimes throws an error. */ 
/* Applying -1 seems to be a workaround. */

static int get_max_int_value()                       { return 2147483647;      }
static int get_min_int_value()                       { return -2147483647 - 1; }
static unsigned int get_max_unsigned_int_value()     { return 4294967295U;     }

static long get_max_long_value()                     { return 2147483647;      }
static long get_min_long_value()                     { return -2147483647 - 1; }
static unsigned long get_max_unsigned_long_value()   { return 4294967295UL;    }

/* limits.h on the GCC compiler reports long values to be the same as an int */

static float get_max_float_value()                   { return 340282346638528859811704183484516925440.000000f; }
static float get_min_float_value()                   { return 0.000000f;                                       }

/*-------------------------------------
 ---------VECTOR 2 DEFINITIONS---------
 --------------------------------------*/

static float vector2_get_meeting_point_x(Vector2 vector_a, Vector2 vector_b)
{
    /* Subtract vector_b from vector_a and store a positive or negative sign based on the results.
    Determine the absolute distance between the two x values and cut it in half.
    Both the low and high numbers will be able to add or subtract this value to reach the same center point.
    Use the previously stored sign to determine whether to add or subtract. */

    char sign = (vector_a.x >= vector_b.x) ? '+' : '-';
    float offset_amount = get_absolute_value_float((vector_a.x - vector_b.x) / 2.0f);
    return (sign == '+') ? vector_a.x - offset_amount : vector_a.x + offset_amount;

    /* Always uses vector_a as the baseline. */
}

static float vector2_get_meeting_point_y(Vector2 vector_a, Vector2 vector_b)
{
    /* Identical to the implementation for the x position, just calculating for y instead. */

    char sign = (vector_a.y >= vector_b.y) ? '+' : '-';
    float offset_amount = get_absolute_value_float((vector_a.y - vector_b.y) / 2.0f);
    return (sign == '+') ? vector_a.y - offset_amount : vector_a.y + offset_amount;
}

static Vector2 vector2_get_meeting_point_all(Vector2 vector_a, Vector2 vector_b)
{
    /* Uses both implementations for the x and y values to create a full Vector2 that can be returned. */

    Vector2 returned_vector2;

    returned_vector2.x = vector2_get_meeting_point_x(vector_a, vector_b);
    returned_vector2.y = vector2_get_meeting_point_y(vector_a, vector_b);

    return returned_vector2;
}

/* All of these work the same as the Vector2 functions. */

static float vector3_get_meeting_point_x(Vector3* vector_a, Vector3* vector_b)
{
    char sign = (vector_a->x >= vector_b->x) ? '+' : '-';
    float offset_amount = get_absolute_value_float((vector_a->x - vector_b->x) / 2.0f);
    return (sign == '+') ? vector_a->x - offset_amount : vector_a->x + offset_amount;
}

static float vector3_get_meeting_point_y(Vector3* vector_a, Vector3* vector_b)
{
    char sign = (vector_a->y >= vector_b->y) ? '+' : '-';
    float offset_amount = get_absolute_value_float((vector_a->y - vector_b->y) / 2.0f);
    return (sign == '+') ? vector_a->y - offset_amount : vector_a->y + offset_amount;
}

static float vector3_get_meeting_point_z(Vector3* vector_a, Vector3* vector_b)
{
    char sign = (vector_a->z >= vector_b->z) ? '+' : '-';
    float offset_amount = get_absolute_value_float((vector_a->z - vector_b->z) / 2.0f);
    return (sign == '+') ? vector_a->z - offset_amount : vector_a->z + offset_amount;
}

static Vector3 vector3_get_meeting_point_all(Vector3* vector_a, Vector3* vector_b)
{
    Vector3 returned_vector3;

    returned_vector3.x = vector3_get_meeting_point_x(vector_a, vector_b);
    returned_vector3.y = vector3_get_meeting_point_y(vector_a, vector_b);
    returned_vector3.z = vector3_get_meeting_point_z(vector_a, vector_b);

    return returned_vector3;
}

/*--------------------------------------
 -----------MATH DEFINITIONS------------
 ---------------------------------------*/

 /* Gets the value without sign information. This is done by multiplying by -1 and if the original
 value is a positive number then it is already considered to be the absolute value. */

static float get_absolute_value_float(float original_value)
{
    return (original_value < 0.0f) ? original_value * -1.0f : original_value;
}

static int get_absolute_value_int(int original_value)
{
    return (original_value < 0.0f) ? original_value * -1.0f : original_value;
}

/* Takes the original value and multiplies it by the number of times determined by the exponent. */

static float get_raised_power_value_float(float original_value, int exponent)
{
    float returned_value = original_value; /* Can't start from zero because this number gets multiplied. */

    int i;
    for (i = 1; i < exponent; i++)
    {
        returned_value *= original_value;
    }

    return returned_value;
}

static int get_raised_power_value_int(int original_value, int exponent)
{
    int returned_value = original_value;

    int i;
    for (i = 1; i < exponent; i++)
    {
        returned_value *= original_value;
    }

    return returned_value;
}

/* Multiplies the original value by -1 which causes the sign information to flip. */

static float get_flipped_sign_float(float original_value)
{
    if (original_value != 0.0f)
        return original_value *= -1.0f;
    else
        return original_value;
}

static int get_flipped_sign_int(int original_value)
{
    if (original_value != 0)
        return original_value *= -1;
    else
        return original_value;
}

/* Initially returns a number that perfectly divides into the original value and then uses that
number to store the quotient and remainder. The remainder can be found by subtracting the quotient
from the number that perfectly divides into the original value and then multiplying it by the
divisor to get the actual mod results. */

static float get_mod_value_float(float original_value, float divisor)
{
    float full_value = (original_value / divisor);       /* This number perfectly divides into the original value. */
    float quotient_value = (int)full_value;              /* Truncates the full value down to a whole number. */
    float remainder_value = full_value - quotient_value; /* Gets the individual remainder from each divide. */

    return remainder_value * divisor;                    /* Returns the actual remainder after all divides have been made. */
}

/* Rounds the number up or down based on how large it is. Anything that is 0.5 or above for the decimal place
will be rounded up and anything that is below 0.5 will be rounded down. This works by truncating the decimal
place on a value, and then also increasing the value by 1 if rounding up. */

static void round_float(float* original_value)
{
    float temp = *original_value;
    round_float_down(&temp); /* Storing temp value to be rounded down and used below. */

    /* If the remainder is greater than or equal to 0.5, round up, otherwise round down. */

    if (*original_value - temp >= 0.5f)
        round_float_up(original_value);
    else
        round_float_down(original_value);
}

static void round_float_up(float* original_value)
{
    int rounded_number = (int)*original_value + 1; /* Truncate the number and add 1 to get the rounded up whole number. */
    *original_value = (float)rounded_number;       /* Convert back to float. */
}

static void round_float_down(float* original_value)
{
    int rounded_number = (int)*original_value; /* Truncate the number to get the rounded down whole number. */
    *original_value = (float)rounded_number;
}

#endif
