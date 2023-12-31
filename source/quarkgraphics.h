#ifndef QUARKGRAPHICS_H
#define QUARKGRAPHICS_H

#include "quarkcore.h"

bool is_running;

/*-------------------------
 ------WINDOW CREATION------
 -------------------------*/

/* This is the information that the user will get to specify when creating a window. */
typedef struct 
{
	const char* window_title;
	int window_width;
	int window_height;
} Window;

/* Import the appropriate files depending on the current platform */
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

/* TODO: MacOS */
/* TODO: Linux */

/* This window handle is what will be checked for to determine if the window is still active or not when updating. */
extern HWND window_handle;

#endif

/* Create the window first and provide the required information, then run the window_update inside of a game loop. */
bool create_window(Window window);
void window_update();

#endif