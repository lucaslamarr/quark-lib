/* DO NOT INCLUDE! THIS IS JUST FOR TESTING AND NOT PART OF THE QUARK LIBRARY! */

#include "quark.h"
#include <stdio.h> 

/* MacOS and Linux Screen Clearing */

#ifdef _WIN32
    #include <stdlib.h>
#endif

void run_core_demo()
{
	printf("-----------------------------------------\n");
	printf("Booleans\n");
	printf("-----------------------------------------\n\n");
	
	{
		bool bool_test = false;
		
		printf("Boolean Initialized To False: %c\n", bool_test);
		
		bool_test = true;
		printf("Boolean Changed To True: %c\n\n", bool_test);
	}
	
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
		printf("DEBUGGING\n");
		printf("-----------------------------------------\n\n");
		
		{
			debug_log(MESSAGE,   "Test Log - Message"  );
			debug_log(WARNING,   "Test Log - Warning"  );
			debug_log(ERR,       "Test Log - Error"    );
			
			debug_alert(MESSAGE, "3 more alerts will appear demonstrating the alert box logging feature.");
			
			debug_alert(MESSAGE, "Test Alert - Message");
			debug_alert(WARNING, "Test Alert - Warning");
			debug_alert(ERR,     "Test Alert - Error");
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
	int i;
	
	{
		int bubble_array_int[5] = {2, 6, 4, 7, 9};
		float bubble_array_float[5] = {2.0f, 6.0f, 4.0f, 7.0f, 9.0f};
		
		printf("\n---INT BUBBLE SORT BEFORE---\n\n");
		
		for (i = 0; i < (int)sizeof(bubble_array_int) / (int)sizeof(bubble_array_int[0]); i++)
			printf("Element: %d = %d\n", i, bubble_array_int[i]);
		i = 0;
		
		printf("\n---INT BUBBLE SORT AFTER---\n\n");
		
		bubble_sort_int(bubble_array_int, 5);
		
		for (i = 0; i < (int)sizeof(bubble_array_int) / (int)sizeof(bubble_array_int[0]); i++)
			printf("Element: %d = %d\n", i, bubble_array_int[i]);
		i = 0;
		
		printf("\n---FLOAT BUBBLE SORT BEFORE---\n\n");
		
		for (i = 0; i < (int)sizeof(bubble_array_float) / (int)sizeof(bubble_array_float[0]); i++)
			printf("Element: %d = %f\n", i, bubble_array_float[i]);
		i = 0;
		
		printf("\n---FLOAT BUBBLE SORT AFTER---\n\n");
		
		bubble_sort_float(bubble_array_float, 5);
		
		for (i = 0; i < (int)sizeof(bubble_array_float) / (int)sizeof(bubble_array_float[0]); i++)
			printf("Element: %d = %f\n", i, bubble_array_float[i]);
		i = 0;
	}
	
	{
		int selection_array_int[5] = {34, 2, 62, 27, 91};
		float selection_array_float[5] = {23.0f, 66.0f, 41.0f, 17.0f, 39.0f};
		
		printf("\n\n\n\n---INT SELECTION SORT BEFORE---\n\n");
		
		for (i = 0; i < (int)sizeof(selection_array_int) / (int)sizeof(selection_array_int[0]); i++)
			printf("Element: %d = %d\n", i, selection_array_int[i]);
		i = 0;
		
		printf("\n---INT SELECTION SORT AFTER---\n\n");
		
		selection_sort_int(selection_array_int, 5);
		
		for (i = 0; i < (int)sizeof(selection_array_int) / (int)sizeof(selection_array_int[0]); i++)
			printf("Element: %d = %d\n", i, selection_array_int[i]);
		i = 0;
		
		printf("\n---FLOAT SELECTION SORT BEFORE---\n\n");
		
		for (i = 0; i < (int)sizeof(selection_array_float) / (int)sizeof(selection_array_float[0]); i++)
			printf("Element: %d = %f\n", i, selection_array_float[i]);
		i = 0;
		
		printf("\n---FLOAT SELECTION SORT AFTER---\n\n");
		
		selection_sort_float(selection_array_float, 5);
		
		for (i = 0; i < (int)sizeof(selection_array_float) / (int)sizeof(selection_array_float[0]); i++)
			printf("Element: %d = %f\n", i, selection_array_float[i]);
		i = 0;
	}
	
	{
		int insertion_array_int[5] = {92, 16, 34, 57, 59};
		float insertion_array_float[5] = {2.0f, 96.0f, 54.0f, 47.0f, 99.0f};
		
		printf("\n\n\n\n---INT INSERTION SORT BEFORE---\n\n");
		
		for (i = 0; i < (int)sizeof(insertion_array_int) / (int)sizeof(insertion_array_int[0]); i++)
			printf("Element: %d = %d\n", i, insertion_array_int[i]);
		i = 0;
		
		printf("\n---INT INSERTION SORT AFTER---\n\n");
		
		insertion_sort_int(insertion_array_int, 5);
		
		for (i = 0; i < (int)sizeof(insertion_array_int) / (int)sizeof(insertion_array_int[0]); i++)
			printf("Element: %d = %d\n", i, insertion_array_int[i]);
		i = 0;
		
		printf("\n---FLOAT INSERTION SORT BEFORE---\n\n");
		
		for (i = 0; i < (int)sizeof(insertion_array_float) / (int)sizeof(insertion_array_float[0]); i++)
			printf("Element: %d = %f\n", i, insertion_array_float[i]);
		i = 0;
		
		printf("\n---FLOAT INSERTION SORT AFTER---\n\n");
		
		insertion_sort_float(insertion_array_float, 5);
		
		for (i = 0; i < (int)sizeof(insertion_array_float) / (int)sizeof(insertion_array_float[0]); i++)
			printf("Element: %d = %f\n", i, insertion_array_float[i]);
		i = 0;
	}
	
	{
		int index;
		
		int linear_search_array_int[5] = {2, 6, 4, 3, 9};
		float linear_search_array_float[5] = {2.0f, 6.0f, 4.0f, 3.0f, 9.0f};
		
		printf("\n\n\n\n---INT LINEAR SEARCH ARRAY---\n\n");
		
		for (i = 0; i < (int)sizeof(linear_search_array_int) / (int)sizeof(linear_search_array_int[0]); i++)
			printf("Element: %d = %d\n", i, linear_search_array_int[i]);
		i = 0;
		
		printf("\n---INT LINEAR SEARCH RESULT---\n\n");
		
		index = linear_search_int(linear_search_array_int, 5, 3);
		
		printf("Found at index %d\n", index);
		
		printf("\n---FLOAT LINEAR SEARCH ARRAY---\n\n");
		
		for (i = 0; i < (int)sizeof(linear_search_array_float) / (int)sizeof(linear_search_array_float[0]); i++)
			printf("Element: %d = %f\n", i, linear_search_array_float[i]);
		i = 0;
		
		printf("\n---FLOAT LINEAR SEARCH RESULT---\n\n");
		
		index = linear_search_float(linear_search_array_float, 5, 3.0f);
		
		printf("Found at index %d", index);
	}
	
	{
		int index;
		
		int binary_search_array_int[5] = {22, 3, 34, 13, 9};
		float binary_search_array_float[5] = {32.0f, 3.0f, 84.0f, 13.0f, 9.0f};
		
		printf("\n\n\n\n---INT BINARY SEARCH ARRAY---\n\n");
		
		for (i = 0; i < (int)sizeof(binary_search_array_int) / (int)sizeof(binary_search_array_int[0]); i++)
			printf("Element: %d = %d\n", i, binary_search_array_int[i]);
		i = 0;
		
		printf("\n---INT BINARY SEARCH RESULT---\n\n");
		
		index = binary_search_int(binary_search_array_int, 5, 3);
		
		printf("Found at index %d\n", index);
		
		printf("\n---FLOAT BINARY SEARCH ARRAY---\n\n");
		
		for (i = 0; i < (int)sizeof(binary_search_array_float) / (int)sizeof(binary_search_array_float[0]); i++)
			printf("Element: %d = %f\n", i, binary_search_array_float[i]);
		i = 0;
		
		printf("\n---FLOAT BINARY SEARCH RESULT---\n\n");
		
		index = binary_search_float(binary_search_array_float, 5, 3.0f);
		
		printf("Found at index %d\n", index);
	}
}

void run_graphics_demo()
{
	Window window;
	window.window_title = "Quark Lib Demo";
	window.window_width = 1280;
	window.window_height = 720;
	
	if (!create_window(window))
		return;
	
	/* You use your own boolean to check if the program is running here. This acts as a placeholder for the demo program. In the "LRESULT CALLBACK window_callback" you can set your boolean to false right before DestroyWindow() is called and destroys the "HWND window_handle" variable. */
	
	while (window_handle)
	{
		window_update();
	}
	
	printf("Window destroyed!\n");
}

int main()
{
	bool running = true;
	int choice;
	
	while (running)
	{
		printf("Welcome to the Quark Library Demo Program\n\n");
		
		printf("1. Core\n");
		printf("2. Math\n");
		printf("3. Algorithms\n");
		printf("4. Data Structures\n");
		printf("5. Graphics\n\n");
		
		while (1)
		{
			printf("Choice: ");
			fflush(stdin);
			choice = getchar();
			
			switch (choice)
			{			
				case '1':
				{
					system("cls");
					run_core_demo();
					break;
				}
				case '2':
				{
					system("cls");
					run_math_demo();
					break;
				}
				case '3':
				{
					system("cls");
					run_algo_demo();
					break;
				}
				case '4':
				{
					system("cls");
					run_ds_demo();
					break;
				}
				case '5':
				{
					system("cls");
					run_graphics_demo();
					break;
				}
				default:
				{
					printf("\nINVALID RESPONSE\n\n");
					continue;
				}
				
				break;
			} 
			
			break;
		}
		
		printf("\n-----------------------------------------\n");
		printf("-----------------------------------------\n\n");
		printf("Run another demo?\n\n");
		
		printf("1: Yes\n");
		printf("2: No\n\n");
		
		while (1)
		{
			printf("Choice: ");
			fflush(stdin);
			choice = getchar();
			
			switch(choice)
			{			
				case '1':
				{
					system("cls");
					break;
				}
				case '2':
				{
					system("cls");
					running = false;
					return 0;
				}
				default:
				{
					printf("\nINVALID RESPONSE\n\n");
					continue;
				}
				
				break;
			}
			
			break;
		}
		
		system("cls");
	} 
		
	return 0;
}

