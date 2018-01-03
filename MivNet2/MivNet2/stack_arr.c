//
//  Assigned by:
//
//  File Name:        stack_arr.c
//  Files in project: main.c, main.h, double_list.c, double_list.h
//                    stack_arr.h, stack_arr.c, polynomial.c, polynomial.h
//

#include "stack_arr.h"

void create_stack (stack *ps)
{
	ps->top = -1;											// No top for empty stack
}

int push (stack_type x, stack *ps)							// Enter value to stack
{
	if (ps->top < MaxStack-1)
	{
		ps->top++;
        ps->items[ps->top] = x;
        return 1;
	}
	return 0;
}

int pop (stack *ps, stack_type *px)							// Pull out value from stack
{
	if (ps->top >= 0)
	{
		*px = ps->items[ps->top];
        ps->top--;
        return 1;
	}
	return 0;
}

int stack_top (stack *ps, stack_type *px)					// Get stack top
{
	if (ps->top >= 0)
	{
		*px = ps->items[ps->top];
        return 1;
	}
	return 0;
}

int stack_is_empty (stack *ps)								// Check if stack is empty
{
	return ps->top == -1;
}

int stack_is_full (stack *ps)								// Check if stack is full
{
	return ps->top == MaxStack-1;
}


