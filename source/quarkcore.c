#include "quarkcore.h"
#include "quarkmath.h"
#include <stdio.h>
#include <Windows.h>

/*-------------------------
 --------TYPE LIMITS--------
 -------------------------*/

/* NOTE: Using a short for chars so that I return a small number and not a symbol. */
/* NOTE: MSVC will sometimes throw an error for writing the actual min value, applying -1 seems to be a workaround. */

char get_max_char_value()                             { return 127;             }
char get_min_char_value()                             { return -128;            } 
unsigned char get_max_unsigned_char_value()           { return 255;             }

short get_max_short_value()                           { return 32767;           }
short get_min_short_value()                           { return -32768;          } 
unsigned short get_max_unsigned_short_value()         { return 65535;           }

int get_max_int_value()                               { return 2147483647;      }
int get_min_int_value()                               { return -2147483647 - 1; } 
unsigned int get_max_unsigned_int_value()             { return 4294967295U;     }

/* limits.h on the GCC compiler reports these values to be the same as an int */
long get_max_long_value()                             { return 2147483647;      }
long get_min_long_value()                             { return -2147483647 - 1; } 
unsigned long get_max_unsigned_long_value()           { return 4294967295UL;    }

float get_max_float_value()                           { return 340282346638528859811704183484516925440.000000f; }
float get_min_float_value()                           { return 0.000000f;                                       }

/* 
The value reported using limits.h exceeds the level of precision that of the GCC compiler that I am using. Use at your own risk.
double get_max_double_value()                         { return 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000f;            }
*/

double get_min_double_value()                         { return 0.000000f; }

/* NOTE: All values checked alongside the C99 Limits.h macros.*/

/*-------------------------
 ----------VECTOR 2---------
 -------------------------*/

float vector2_get_meeting_point_x(Vector2 vector_a, Vector2 vector_b)
{
    /*Subtract vector_b from vector_a, store a positive or negative sign based on the results.
    Determine the absolute distance in between the two x values and cut it in half.
    Both the low and high number will be able to add or subtract this value to reach the same center point.
    Use the previously stored sign to determine whether to add or subtract.*/
    
    char sign = (vector_a.x >= vector_b.x) ? '+' : '=';
    float offset_amount = get_absolute_value_float((vector_a.x - vector_b.x) / 2.0f);
    return (sign == '+') ? vector_a.x - offset_amount : vector_a.x + offset_amount; 
	/* Always uses vector_a as the baseline. */
}

float vector2_get_meeting_point_y(Vector2 vector_a, Vector2 vector_b)
{
    /* Identical to the implementation for the x position, just calculating for y instead. */
    
    char sign = (vector_a.y >= vector_b.y) ? '+' : '=';
    float offset_amount = get_absolute_value_float((vector_a.y - vector_b.y) / 2.0f);
    return (sign == '+') ? vector_a.y - offset_amount : vector_a.y + offset_amount;
}

Vector2 vector2_get_meeting_point_all(Vector2 vector_a, Vector2 vector_b)
{ 
    /* Uses both implementations for the x and y values to create a full Vector2 that can be returned. */
    
    Vector2 returned_vector2;
    
    returned_vector2.x = vector2_get_meeting_point_x(vector_a, vector_b);
    returned_vector2.y = vector2_get_meeting_point_y(vector_a, vector_b);
    
    return returned_vector2;
}

/* All of these work exactly the same as the Vector2 functions, except these also check the z position. */

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
 ---------DEBUGGING---------
 -------------------------*/

/* For library development only and not exposed to the user. Returns the text displayed for the message type. */
const char* get_debug_message_type(DebugMessageType message_type)
{
	switch(message_type)
	{
		case MESSAGE:
		{
			return "Message";
			break;
		}
		case WARNING:
		{
			return "Warning";
			break;
		}
		case ERR:
		{
			return "Error";
			break;
		}
		default:
		{
			return "Message";
		}
	}
}

/* Displays a message in the console with a message type, followed by the message itself. */
void debug_log(DebugMessageType message_type, const char* message)
{
	printf("%s: %s\n", get_debug_message_type(message_type), message);
}

/* Displays a graphical popup showing the message type, followed by the message. Native implementation for each OS. */
void debug_alert(DebugMessageType message_type, const char* message)
{
#ifdef _WIN32
	UINT icon_type; /* The icon that will show in the alert box */
	
	if (message_type == MESSAGE)
		icon_type = MB_ICONINFORMATION;
	else if (message_type == WARNING)
		icon_type = MB_ICONWARNING;
	else
		icon_type = MB_ICONERROR;
	
	MessageBox(NULL, message, get_debug_message_type(message_type), icon_type | MB_OK);
#endif
	
	/* TODO: MacOS and Linux */
}

