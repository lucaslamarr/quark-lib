#ifndef QUARKDS_H
#define QUARKDS_H

#include "quarkcore.h"

typedef struct Stack Stack;

/* 
[ ] TODO: Linked List   
[ ] TODO: Key Value Map 
[ ] TODO: Dynamic Array 
[-] TODO: Stack         
[ ] TODO: Queue         
*/

/*-------------------------
 ----STACK DECLARATIONS-----
 -------------------------*/

void stack_initialize(Stack*, unsigned int);
void stack_push(Stack*, unsigned int);
void stack_pop(Stack*);

void stack_clear(Stack*);
bool stack_is_empty(Stack*);
bool stack_is_full(Stack*);
bool stack_was_initialized(Stack*);

unsigned int stack_get_top(Stack*);
unsigned int stack_get_size_max(Stack*);
unsigned int stack_get_size_current(Stack*); 

#endif 

