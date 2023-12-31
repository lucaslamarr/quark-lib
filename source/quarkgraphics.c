#include "quarkgraphics.h"

/* NOTE: Modify these functions to meet the needs of your project */

/*-------------------------
 ------WINDOW CREATION------
 -------------------------*/

/* Checking for the active operating system in order to determine how certain functions should be implemented */
#ifdef _WIN32

HWND window_handle;

/* NOTE: Naming conventions match Microsoft's documentation and differs from the rest of the library */
LRESULT CALLBACK window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	
	/* Checks for specific message types that should be handled, such as closing the window.*/
	switch(msg)
	{
		case WM_CLOSE:
		{
			/* NOTE: Add your own boolean that tracks if the program is running and set it to false here */
			DestroyWindow(window_handle); 
			window_handle = NULL;
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0); /* Terminates the message loop. */
			break;
		}
		default:
		{
			/* All non specified messages will be handled with the default window procedure. */
			result = DefWindowProcA(window, msg, wParam, lParam);
		}
	}
	
	return result;
}

bool create_window(Window window)
{
	HINSTANCE instance = GetModuleHandleA(0); /* Reference the current process that is asking for this handle. */
	
	/* Set a bunch of information about the window that we are using. Details listed below. */
	WNDCLASSA window_class;
	
	window_class.style         = CS_HREDRAW | CS_VREDRAW;          /* Tells the window to redraw when the size changes. */
	window_class.lpfnWndProc   = window_callback;                  /* The callback function that handles messages to the window. */
	window_class.cbClsExtra    = 0;                                /* Extra bytes stored in case of extra class data being added. */
	window_class.cbWndExtra    = 0;
	window_class.hInstance     = instance;                         /* Application instance that contains the window. */
	window_class.hIcon         = LoadIconA(NULL, IDI_APPLICATION); /* Set the icon for the window to something standard. */
	window_class.hCursor       = LoadCursorA(NULL, IDC_ARROW);     /* Set the mouse cursor to something standard. */
	window_class.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);       /* Set the background color of the window. */
	window_class.lpszMenuName  = NULL;                             /* No class menu. */
	window_class.lpszClassName = window.window_title;              /* Name of the window class that can be used later. */
	
	/* Ensure that the class can be registered correctly. If not, stop creating the window and return. */
	if (!RegisterClassA(&window_class))
		return false;
	
	window_handle = CreateWindowExA(0,                    /* No additional or extended window styling. */
									window.window_title,  /* The window class name. It was made to be the same as the window title */
									window.window_title,  /* The title of the window that can be seen at the top. */
									WS_OVERLAPPEDWINDOW,  /* Window with 3 buttons, and a bar at the top. */
									100,                  /* Window X position */
									100,                  /* Window Y position. */
									window.window_width,  /* Window width. */
									window.window_height, /* Window height. */
									NULL,                 /* No parent window. */ 
									NULL,                 /* No menu handle. */
									instance,             /* Instance of the application that is using the window. */
									NULL);                /* Assigne to our window handle and not a different pointer. */
	
	/* If the window handle fails and is null, cancel the window creation process and return. */
	if (!window_handle)
		return false;
	
	ShowWindow(window_handle, SW_SHOWNORMAL); /* Show the window that was just created in it's regular size. */
	UpdateWindow(window_handle); /* Handle any pending messages before finishing the creation process. */
	
	return true;
}

void window_update()
{
	MSG msg;
	
	/* Handle messages sent to the window. No min or max message value is set. */
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); /* Perform translations from virtual key codes to windows readable messages. */
		DispatchMessageA(&msg); /* Send the message to the window now that it has been translated. */
	}
}

#endif

/* TODO: #ifdef APPLE and LINUX implementations */
