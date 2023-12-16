#include "quarkds.h"
#include <stdlib.h>
#include <stddef.h>

/*-------------------------
 -----STACK DEFINITIONS-----
 -------------------------*/

/*
[-] TODO: initialize:            Set initial size and apply default values to entries
[-] TODO: verify initialize:     Verify that the stack is not null and was initialized.
[-] TODO: push:                  Add an element to the top of a stack
[-] TODO: pop:                   Remove an element from the top of a stack
[-] TODO: clear:                 Clear all elements from the stack
[-] TODO: is_empty:              Check if the stack is empty
[-] TODO: is_full:               Check if the stack is full
[-] TODO: get_top:               Get the value of the top element without removing itself
[-] TODO: get_max_size:          Get the max size of the stack
[-] TODO: get_current_size:      Get the current size of the stack
[ ] TODO: comments
*/

struct Stack
{
	unsigned int size;
	unsigned int top;
	unsigned int entries[];
};


void stack_initialize(Stack* stack, unsigned int size)
{
	unsigned int i;
	
	stack->top = 0;
	stack->size = size;
	stack->entries = (unsigned int*)malloc(size * sizeof(unsigned int));
	
	for (i = 0; i < stack->size; i++)
	{
		stack->entries[i] = NULL;
	}
}

bool stack_was_initialized(Stack* stack)
{
	return (stack != NULL) ? true : false;
}

void stack_push(Stack* stack, unsigned int entry)
{
	if (!stack_was_initialized(stack))
		return;
	
	if (stack_is_full(stack))
		return;
	
	stack->entries[stack->top] = entry;
	++stack->top;
}

void stack_pop(Stack* stack)
{
	unsigned int i;
	unsigned int[] temp = stack->entries;
	
	if (!stack_was_initialized(stack))
		return;
	
	if (stack->top < 0) /* TODO: This is a bug because top is an unsigned int. */
		return;
	
	stack_clear(stack);
	
	for (i = 0; i < stack->size - 1; i++)
	{
		stack->entries[i] = temp[i+1];
	}
	
	--stack->top;
}

void stack_clear(Stack* stack)
{
	unsigned int i;
	for (i = 0; i < stack->size; i++)
	{
		stack->entries[i] = NULL;
	}
}

bool stack_is_empty(Stack* stack)
{
	unsigned int i;
	for (i = 0; i < stack->size; i++)
	{
		if (!stack->entries[i] == NULL)
			return false;
	}
	
	return true;
}

bool stack_is_full(Stack* stack)
{
	if (sizeof(stack->entries/sizeof(stack->entries[0])) >= stack->top)
		return true;
	
	return false;
}

unsigned int stack_get_top(Stack* stack)
{
	return stack->entries[stack->top];
}

unsigned int stack_get_size_max(Stack* stack)
{
	return stack->size;
}

unsigned int stack_get_size_current(Stack* stack)
{
	return stack->top;
}




