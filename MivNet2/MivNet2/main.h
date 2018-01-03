//
//  Assigned by:
//
//  File Name:        main.h
//  Files in project: main.c, main.h, double_list.c, double_list.h
//                    stack_arr.h, stack_arr.c, polynomial.c, polynomial.h
//

#pragma once
#include "stack_arr.h"
#include "polynomial.h"

void exercise_1();
void exercise_2();
void print_stack(stack *S1, stack *S2, char *str);				// Determine which action to insert to the table first
void print_row(stack *S1, stack *S2, char result);				// Pop and print row at the table
void polynom_input(DoubleList *list);							// Input into polynom
