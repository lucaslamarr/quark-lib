/* DO NOT INCLUDE! THIS IS JUST FOR TESTING AND NOT PART OF THE QUARK LIBRARY! */

#include <stdio.h>

#include "quark.h"

int main()
{
    bool bool_test = true;
    float float_test = 10.2f;
    int int_test = -20;

    Vector2 vec2_a;
    Vector2 vec2_b;

    Vector3 vec3_a;
    Vector3 vec3_b;
    
    vec2_a.x = 10;
    vec2_a.y = 20;

    vec2_b.x = 30;
    vec2_b.y = 40;

    vec3_a.x = 10;
    vec3_a.y = 20;
    vec3_a.z = 30;

    vec3_b.x = 40;
    vec3_b.y = 50;
    vec3_b.z = 60;

    printf("%c\n\n", bool_test);
    
    printf("%d\n", get_max_char_value());
    printf("%d\n", get_min_char_value());
    printf("%u\n\n", get_max_unsigned_char_value());

    printf("%hd\n",get_max_short_value());
    printf("%hd\n",get_min_short_value());
    printf("%hu\n\n",get_max_unsigned_short_value());

    printf("%d\n", get_max_int_value());
    printf("%d\n", get_min_int_value());
    printf("%u\n\n", get_max_unsigned_int_value());

    printf("%ld\n", get_max_long_value());
    printf("%ld\n", get_min_long_value());
    printf("%lu\n\n", get_max_unsigned_long_value());

    printf("%f\n", get_max_float_value());
    printf("%f\n\n", get_min_float_value());

    printf("%f\n", vector2_get_meeting_point_x(vec2_a, vec2_b));
    printf("%f\n", vector2_get_meeting_point_y(vec2_a, vec2_b));

    vec2_a.x = vector2_get_meeting_point_all(vec2_a, vec2_b).x;
    vec2_a.y = vector2_get_meeting_point_all(vec2_a, vec2_b).y;

    printf("%f, %f\n\n", vec2_a.x, vec2_a.y);

    printf("%f\n", vector3_get_meeting_point_x(&vec3_a, &vec3_b));
    printf("%f\n", vector3_get_meeting_point_y(&vec3_a, &vec3_b));
    printf("%f\n", vector3_get_meeting_point_z(&vec3_a, &vec3_b)); 

    vec3_a.x = vector3_get_meeting_point_all(&vec3_a, &vec3_b).x;
    vec3_a.y = vector3_get_meeting_point_all(&vec3_a, &vec3_b).y;
    vec3_a.z = vector3_get_meeting_point_all(&vec3_a, &vec3_b).z;

    printf("%f, %f, %f\n\n", vec3_a.x, vec3_a.y, vec3_a.z);

    printf("%f\n", get_absolute_value_float(float_test));
    printf("%d\n\n", get_absolute_value_int(int_test));

    printf("%f\n", get_raised_power_value_float(float_test, 3));
    printf("%d\n\n", get_raised_power_value_int(int_test, 3));

    printf("%f\n\n", get_mod_value_float(float_test, 12.0f));

    printf("%f\n", get_flipped_sign_float(float_test));
    printf("%d\n\n", get_flipped_sign_int(int_test));

    round_float(&float_test);     
    printf("%f\n", float_test);

    round_float_up(&float_test);
    printf("%f\n", float_test);

    round_float_down(&float_test); 
    printf("%f\n", float_test);

    return 0;
}

