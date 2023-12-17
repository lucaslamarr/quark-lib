#ifndef QUARKGRAPHICS_H
#define QUARKGRAPHICS_H

#include "quarkcore.h"

bool is_running;

/*-------------------------
 ------WINDOW CREATION------
 -------------------------*/

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

extern HWND window_handle;

#endif

bool create_window(Window window);
void window_update();

#endif