//
//  Assigned by:
//  Group number
//
//  File Name:        stack_arr.h
//  Files in project: main.c, main.h, double_list.c, double_list.h
//                    stack_arr.h, stack_arr.c, polynomial.c, polynomial.h
//

#define MaxStack 100

typedef char stack_type;

typedef struct {											// Struct for stack
	int top;												// Top - upper value in stack
	stack_type items [MaxStack];
} stack;

// Stack functions
void create_stack (stack *);
int push (stack_type, stack *);
int pop (stack *, stack_type *);
int stack_top (stack *, stack_type *);
int stack_is_empty (stack *);
int stack_is_full (stack *);
