#include "quark.h"
#include <stdio.h>

#define DEMO_MODE //Simply #undef this macro to disable the demonstration from playing

void demo_program(); //Runs a small demonstration showing off some of the library features.
void package_library(); //Packages into a dll file.

int main()
{
#ifdef DEMO_MODE
	demo_program();
#else
	package_library();
#endif
	
	return 0;
}

void demo_program()
{
	float test = 5.5f;
	
	round_float(&test);
	printf("%f\n", test);
	
	scanf(".");
}

void package_library()
{
	printf("Packaging Library");
}