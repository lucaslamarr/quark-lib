# A small C89 (ANSI) library with no dependencies.
Everything is compiled with ```-Wall -Wextra -ansi -pedantic``` for strict adherence to the C89 standard and is contained in one single ```.h``` file.

# Overview

I started working on Quark to recreate some of the functions that I frequently use from the C standard library. Rather than including full header files just for a few functions, I decided to try and remake these functions on my own. As a result, Quark includes a few features that are found in the C89 standard library, along with some of my own features that I felt would be useful. 

This is by no means meant to be a replacement for any part of the standard library or a claim to being any faster or more efficient. I just wanted to remake these functions for myself and put them all into one single file that I can use in my projects. It is just a small hobby project that I hope to continue improving and expanding upon as I spend more time programming in C89.

# quark.h

Quark is built with C89, which was before the ```bool``` type had been added to the language. If you are using a later version and have already ```#include <stdbool.h>``` or have your own custom implementation of the ```bool``` type, this will be skipped over. This implementation uses a ```char``` as the smallest available data type to represent the ```bool``` and also uses the familiar ```true``` and ```false``` keywords, which expand to the 0 or 1 characters.

```
#ifndef _STDBOOL_H         
    #ifndef bool           
        typedef char bool; 
        #define true  '1'   
        #define false '0'
    #endif
#endif
```

There is also a reimplementation of the ```limits.h``` file that contains minimum and maximum values for different data types. Type limits for ```char```, ```short```, ```int```, ```long```, and ```float``` are included in Quark and are represented with functions for each of them. 

```
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

float get_max_float_value();
float get_min_float_value();
```

Structs for ```Vector2``` and ```Vector3``` are included and default to the ```float``` data type for the x, y, and z values. These can be cast down to an ```int``` value if desired. Commonly used in games to represent coordinates, or for things like color when trying to represent RGB values.

```
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
```

The ```Vector2``` and ```Vector3``` structs also have a few functions that allow you to get the meeting point of each axis.

```
float vector2_get_meeting_point_x(Vector2, Vector2); 
float vector2_get_meeting_point_y(Vector2, Vector2);
Vector2 vector2_get_meeting_point_all(Vector2, Vector2);

float vector3_get_meeting_point_x(Vector3*, Vector3*); 
float vector3_get_meeting_point_y(Vector3*, Vector3*);
float vector3_get_meeting_point_z(Vector3*, Vector3*);
Vector3 vector3_get_meeting_point_all(Vector3*, Vector3*);
```

A variety of mathematical functions are also included for ```float``` and ```int``` types.

- Get the absolute value of a number.
- Get the raised power value of a number.
- Get the remainder (mod) value of a ```float```.
- Get the flipped sign version of a number.
- Rounding for ```float``` values.

```
float get_absolute_value_float(float); 
int get_absolute_value_int(int); 

float get_raised_power_value_float(float, int); 
int get_raised_power_value_int(int, int); 

float get_mod_value_float(float, float); 

float get_flipped_sign_float(float); 
int get_flipped_sign_int(int); 

void round_float(float*);      
void round_float_up(float*);   
void round_float_down(float*); 
```



