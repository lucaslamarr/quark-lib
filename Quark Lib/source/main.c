/* DO NOT INCLUDE! THIS IS JUST FOR TESTING AND NOT PART OF THE QUARK LIBRARY! */

#include "quark.h"
#include <stdio.h> 

void run_core_demo()
{
    printf("-----------------------------------------\n");
    printf("Min and Max Values\n");
    printf("-----------------------------------------\n\n");
    {
        printf("Max Char Value %d\n", get_max_char_value());
        printf("Min Char Value %d\n", get_min_char_value());
        printf("Max Unsigned Char Value %u\n\n", get_max_unsigned_char_value());
        
        printf("Max Short Value %d\n", get_max_short_value());
        printf("Min Short Value %d\n", get_min_short_value());
        printf("Max Unsigned Short Value %u\n\n", get_max_unsigned_short_value());
        
        printf("Max Int Value %d\n", get_max_int_value());
        printf("Min Int Value %d\n", get_min_int_value());
        printf("Max Unsigned Int Value %u\n\n", get_max_unsigned_int_value());
        
        printf("Max Long Value %ld\n", get_max_long_value());
        printf("Min Long Value %ld\n", get_min_long_value());
        printf("Max Unsigned Long Value %lu\n\n", get_max_unsigned_long_value());
    }
    
    printf("-----------------------------------------\n");
    printf("Vectors\n");
    printf("-----------------------------------------\n\n");
    {
        Vector2 vec2_test_a = {1, 2};
        Vector2 vec2_test_b = {8, 9};
        Vector3 vec3_test_a = {1, 2, 3};
        Vector3 vec3_test_b = {7, 8, 9};
        
        printf("Vector2 A Initialized To %f, %f\n", vec2_test_a.x, vec2_test_a.y);
        printf("Vector2 B Initialized To %f, %f\n\n", vec2_test_b.x, vec2_test_b.y);
        
        printf("Vector2 Meeting Point X: %f\n", vector2_get_meeting_point_x(vec2_test_a, vec2_test_b)); 
        printf("Vector2 Meeting Point Y: %f\n", vector2_get_meeting_point_y(vec2_test_a, vec2_test_b));
        printf("Vector2 Meeting Point All: %f, %f\n\n", vector2_get_meeting_point_all(vec2_test_a, vec2_test_b).x, vector2_get_meeting_point_all(vec2_test_a, vec2_test_b).y);
        
        printf("Vector3 A Initialized To %f, %f, %f\n", vec3_test_a.x, vec3_test_a.y, vec3_test_a.z);
        printf("Vector3 B Initialized To %f, %f, %f\n\n", vec3_test_b.x, vec3_test_b.y, vec3_test_b.z);
        
        printf("Vector3 Meeting Point X: %f\n", vector3_get_meeting_point_x(&vec3_test_a, &vec3_test_b)); 
        printf("Vector3 Meeting Point Y: %f\n", vector3_get_meeting_point_y(&vec3_test_a, &vec3_test_b));
        printf("Vector3 Meeting Point Z: %f\n", vector3_get_meeting_point_z(&vec3_test_a, &vec3_test_b));
        printf("Vector3 Meeting Point All: %f, %f, %f\n\n", vector3_get_meeting_point_all(&vec3_test_a, &vec3_test_b).x, 
               vector3_get_meeting_point_all(&vec3_test_a, &vec3_test_b).y, 
               vector3_get_meeting_point_all(&vec3_test_a, &vec3_test_b).z);
		
		printf("-----------------------------------------\n");
		printf("Booleans\n");
		printf("-----------------------------------------\n\n");
		{
			bool bool_test = false;
			
			printf("Boolean Initialized To False: %c\n", bool_test);
			
			bool_test = true;
			printf("Boolean Changed To True: %c\n\n", bool_test);
		}
    }
}

void run_math_demo()
{
	printf("-----------------------------------------\n");
    printf("Absolute Value\n");
    printf("-----------------------------------------\n\n");
    {
        float sign_test_float;
        int sign_test_int;
        
        printf("Absolute Value Of -15.2: %f\n", get_absolute_value_float(-15.2f));
        printf("Absolute Value Of 15: %d\n\n", get_absolute_value_int(-15));
        
        printf("-----------------------------------------\n");
        printf("Raised To Power of N\n");
        printf("-----------------------------------------\n\n");
        
        printf("4.2 Raised To 3rd Power: %f\n", get_raised_power_value_float(4.2f, 3));
        printf("5 Raised To 6th Power: %d\n\n", get_raised_power_value_int(5, 6));
        
        printf("-----------------------------------------\n");
        printf("Sign Flipping\n");
        printf("-----------------------------------------\n\n");
        
        printf("-5.2 Flipped: %f\n", get_flipped_sign_float(-5.2f));
        printf("5 Flipped: %d\n\n", get_flipped_sign_int(5));
        
        sign_test_float = 10.2f;
        sign_test_int = -3;
        
        printf("Float Initialized To %f\n", sign_test_float);
        printf("Int Initialized To %d\n\n", sign_test_int);
        
        flip_sign_float(&sign_test_float);
        flip_sign_int(&sign_test_int);
        
        printf("Float Sign Flipped: %f\n", sign_test_float);
        printf("Int Sign Flipped: %d\n\n", sign_test_int);
    }
    
    printf("-----------------------------------------\n");
    printf("Rounding and Floating Point Modulus\n");
    printf("-----------------------------------------\n\n");
    {
        float round_test_float;
        
        round_test_float = 10.5f;
        
        printf("Float Initialized To %f\n", round_test_float);
        round_float(&round_test_float); 
        printf("Float Auto Rounded To %f\n\n", round_test_float);
        
        round_test_float = 10.2f;
        printf("Float Initialized To %f\n", round_test_float);
        round_float_up(&round_test_float); 
        printf("Float Rounded Up To %f\n\n", round_test_float);
        
        round_test_float = 10.8f;
        printf("Float Initialized To %f\n", round_test_float);
        round_float_down(&round_test_float); 
        printf("Float Rounded Down To %f\n\n", round_test_float);
        
        printf("Floating Point Modulus 82.6 %% 12 = %f\n", get_mod_value_float(82.6, 12));
    }
}

void run_ds_demo()
{
	
}

void run_algo_demo()
{
	
}

void run_graphics_demo()
{
	Window window;
	window.window_title = "Quark Lib Demo";
	window.window_width = 1280;
	window.window_height = 720;
	
	if (!create_window(window))
		return;
	
	while (is_running)
	{
		window_update();
	}
}

int main()
{
	/*
	run_ds_demo();
run_algo_demo();
*/
	
	run_core_demo(); 
	run_math_demo();
	run_graphics_demo();
	
	while (getchar() != '\n');
	
	return 0;
}

