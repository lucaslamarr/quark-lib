#include "quarkalgo.h"

/*-------------------------
 ----------SORTING----------
 -------------------------*/

/* Pass in the array to be sorted, as well as the length of the array itself since it will decay into a pointer. */
void bubble_sort_int(int *arr, int array_length) 
{
	int i;
	int j;
	
	/* Outer loop stops at the last unsorted element and waits for all of the remaining elements to be sorted before moving forwad. */
    for (i = 0; i < array_length - 1; i++) 
	{
		/* Takes all remaining unsorted elements and begins running through them. */
        for (j = 0; j < array_length - i - 1; j++) 
		{
			/* Check the next element in the array and compare it to the current element's value. If it is larger, swap places. */
            if (arr[j] > arr[j + 1]) 
			{
                int temp = arr[j]; /* Temporarily holds the larger value so that the smaller value can move to it's spot before reassigning to the smaller value's previous spot. */
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/* Identical to the integer implementation. C89 does not support return type overloading. */
void bubble_sort_float(float *arr, int array_length) 
{
	int i;
	int j;
	
    for (i = 0; i < array_length - 1; i++) 
	{
        for (j = 0; j < array_length - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
			{
				float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort_int(int *arr, int array_length) 
{
	int i;
	int j;
	int key;
	
    for (i = 1; i < array_length; i++) 
	{
        key = arr[i];
        j = i - 1;
		
        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void insertion_sort_float(float *arr, int array_length) 
{
	int i;
	int j;
	float key;
	
    for (i = 1; i < array_length; i++) 
	{
        key = arr[i];
        j = i - 1;
		
        while (j >= 0 && arr[j] > key) 
		{
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*-------------------------
 ---------SEARCHING---------
 -------------------------*/

int linear_search_int(int *arr, int size, int target)
{
	int i;
	for (i = 0; i < size; i++) 
	{
        if (arr[i] == target)
            return i; 
    }
	
    return -1; 
}

int linear_search_float(float *arr, int size, float target)
{
	int i;
	for (i = 0; i < size; i++) 
	{
        if (arr[i] == target)
            return i; 
    }
	
    return -1;
}

int binary_search_int(int *arr, int size, int target)
{
	int low = 0;
    int high = size;
	
    while (low < high) 
	{
		int mid = low + (high - low) / 2;
		
        if (arr[mid] == target) 
            return mid; 
		else if (arr[mid] < target) 
            low = mid + 1;
		else 
            high = mid;
    }
	
    return -1;
}

int binary_search_float(float *arr, int size, float target)
{
	int low = 0;
    int high = size;
	
    while (low < high) 
	{
		int mid = low + (high - low) / 2;
		
        if (arr[mid] == target) 
            return mid; 
		else if (arr[mid] < target) 
            low = mid + 1;
		else 
            high = mid;
    }
	
    return -1;
}

