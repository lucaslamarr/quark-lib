#ifndef QUARKALGO_H
#define QUARKALGO_H

/*-------------------------
 ----------SORTING----------
 -------------------------*/

/* Implementation of a few common sorting algorithms for both int and float types. */

void bubble_sort_int(int*, int);
void bubble_sort_float(float*, int);

void insertion_sort_int(int*, int);
void insertion_sort_float(float*, int);

/*-------------------------
 ---------SEARCHING---------
 -------------------------*/

/* These searches return the index of where the target is located. */

int linear_search_int(int*, int, int);
int linear_search_float(float*, int, float);

int binary_search_int(int*, int, int);
int binary_search_float(float*, int, float);

#endif 



