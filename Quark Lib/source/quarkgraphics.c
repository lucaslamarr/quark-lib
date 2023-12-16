#include "quarkgraphics.h"

/* NOTE: Modify these functions to meet the needs of your project */

bool is_running = true;

/*-------------------------
 ------WINDOW CREATION------
 -------------------------*/

#ifdef _WIN32

/* NOTE: Naming conventions match Microsoft's documentation and differs from the rest of the library */
LRESULT CALLBACK window_callback(HWND window, UINT msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = 0;
	
	switch(msg)
	{
		case WM_CLOSE:
		{
			is_running = false;
			DestroyWindow(window_handle);
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		default:
		{
			result = DefWindowProcA(window, msg, wParam, lParam);
		}
	}
	
	return result;
}

bool create_window(Window window)
{
	HINSTANCE instance = GetModuleHandleA(0);
	
	WNDCLASSA window_class;
	
	window_class.style         = CS_HREDRAW | CS_VREDRAW;
	window_class.lpfnWndProc   = window_callback;
	window_class.cbClsExtra    = 0;
	window_class.cbWndExtra    = 0;
	window_class.hInstance     = instance;
	window_class.hIcon         = LoadIconA(NULL, IDI_APPLICATION);
	window_class.hCursor       = LoadCursorA(NULL, IDC_ARROW);
	window_class.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	window_class.lpszMenuName  = NULL;
	window_class.lpszClassName = window.window_title;
	
	if (!RegisterClassA(&window_class))
		return false;
	
	window_handle = CreateWindowExA(0, 
									window.window_title,
									window.window_title,
									WS_OVERLAPPEDWINDOW, 
									100, 
									100, 
									window.window_width,
									window.window_height,
									NULL, 
									NULL, 
									instance,
									NULL);
	
	if (!window_handle)
		return false;
	
	ShowWindow(window_handle, SW_SHOWNORMAL);
	UpdateWindow(window_handle);
	
	return true;
}

void window_update()
{
	MSG msg;
	
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
}

#endif

/* #ifdef APPLE and LINUX */
