//
//  Assigned by:
//  Group number
//
//  File Name:        polynomial.h
//  Files in project: main.c, main.h, double_list.c, double_list.h
//                    stack_arr.h, stack_arr.c, polynomial.c, polynomial.h
//

#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct {										    // Polynom struct
    double coef;
    unsigned int exp;
} Polynomial;

typedef Polynomial NodeType;

typedef struct Node {										// Node struct
    NodeType data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {											// Linked list struct
    struct Node *head;
    struct Node *tail;
    int size;
} DoubleList;

// List functions
void create_list(DoubleList *list);														// create list
void insert_node_first(DoubleList *list, NodeType x);									// insert node at begining of the list
void insert_node_last(DoubleList *list, NodeType x);									// insert node at end of the list
void insert_node_middle(DoubleList *list, Node *prev, Node *next, NodeType x);			// insert node at middle of the list according to a specific value
void insert_node_by_order(DoubleList *list, NodeType x);								// arrange the polynom size and insert a Node
void print_list_forward(DoubleList *list);												// print the list from the begining
void print_list_backward(DoubleList *list);												// print the list from the ending
void delete_from_list(DoubleList *list, Node *t);										// delete the a Node from the list

// Exercise 2 functions
void init_polynom(DoubleList *list);													// initialyze the list
void create_pol_type(Polynomial *pol, double coef, unsigned int exp);					// create polynom type with coefficient and exponent
void insert_polynom(Polynomial *pol, double coef, unsigned int exp, DoubleList *list);  // insert struct of polynom into list
void polynom_sum(DoubleList *pol1, DoubleList *pol2, DoubleList *sum_pol);				// calculate the sum of the polynom's
void polynom_subtract(DoubleList *pol1, DoubleList *pol2, DoubleList *sum_pol);			// subtract polynom 2 from polynom 1
void polynom_multiply(DoubleList *pol, double c, DoubleList *new_pol);					// multiply a polynom with constant value chosen by user
int polynom_size(DoubleList *list);														// determine the max size of exponent
void polynom_reset(DoubleList *list);													// reset the polynom
void print_polynom(Polynomial *pol);													// print the polynom
