//
//  Assigned by:
//
//  File Name:        double_list.c
//  Files in project: main.c, main.h, double_list.c, double_list.h
//                    stack_arr.h, stack_arr.c, polynomial.c, polynomial.h
//

#include "polynomial.h"
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

void create_list(DoubleList *list) {						// Create empty list
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}

void insert_node_first(DoubleList *list, NodeType x) {     // Insert node to list's head
	Node *new_node = (Node *) malloc(sizeof(Node));
	new_node->data = x;
	if (list->size == 0) {
        list->head = list->tail = new_node;                // Make head and tail pointing to the node
	}
	else {
		list->head->prev = new_node;                       // Make old last node point to created node
	}
	new_node->next = list->head;                           // Make old list->head as next node
	list->head = new_node;                                 // Point list->head to the created node
	new_node->prev = NULL;
	list->size++;
}

void insert_node_last(DoubleList *list, NodeType x) {      // Insert node to list's tail
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = x;
    if (list->size == 0) {
        list->head = list->tail = new_node;                // Make head and tail pointing to the node
    }
    else {
        list->tail->next = new_node;                       // Make old last node point to created node
    }
    new_node->prev = list->tail;                           // Make old list->tail as previous node
    list->tail = new_node;                                 // Point list->tail to the created node
    new_node->next = NULL;
    list->size++;
}

void insert_node_middle(DoubleList *list, Node *prev, Node *next, NodeType x) { // Insert node between two nodes
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->data = x;
    new_node->next = next;                                 // Make old list->head as next node
    new_node->prev = prev;                                 // Make old list->tail as previous node
    prev->next = new_node;
    next->prev = new_node;
    list->size++;
}

void insert_node_by_order(DoubleList *list, NodeType x) {  // Insert nnode by exponent size (from smallest to biggest exponent)
    Node *current = list->head;
    if (list->size == 0) {								   // Insert when list->size is 0
        insert_node_first(list, x);
		list->tail->next = NULL;
    }
    else if (list->size == 1) {							   // Insert when list->size is 1
        if (current->data.exp > x.exp) {				   // Check wich exponent is bigger
            insert_node_first(list, x);
        }
        else if (current->data.exp < x.exp) {
            insert_node_last(list, x);
        }
    }
    else {												   // Insert when more than one node
        while (current && (current->data.exp <= x.exp)) {
            if (current->data.exp == x.exp) {
                printf("Exponent is equal to an existing exponent, skipping insert to polynomial.\n");
                return;
            }
            current = current->next;
        }
        if (!current) {
            insert_node_last(list, x);
        }
        else if (!current->prev) {
            insert_node_first(list, x);
        }
        else {
            insert_node_middle(list, current->prev, current, x);
        }
    }
}

void print_list_backward(DoubleList *list) {						// Print the polynom from the end
	int index = 0;
	Node *tmp = list->tail;
    if (!tmp) {
        printf("Zero (Empty Polynomial)");							// When list is empty send massage as requested
    }
	while (tmp) {
        if (tmp->data.coef > 1) {
            printf("%.3f", tmp->data.coef);
        }
        else if (tmp->data.coef == -1) {
            printf(" - ");
        }
        else if (tmp->data.coef < -1) {
            printf(" - %.3f", fabs(tmp->data.coef));
        }
        if (tmp->data.exp > 1 && tmp->data.coef != 0) {
            printf("(X)^%d", tmp->data.exp);
        }
        else if (tmp->data.exp == 1 && tmp->data.coef != 0) {
            printf("(X)");
        }
        else if (tmp->data.coef == 0) { 							// In case mekadem IS 0 - polynom will be presented as 0
            printf("0");
        }
        tmp = tmp->prev;
        if (tmp && tmp->data.coef >= 0) {
            printf(" + ");
        }
		index++;
	}
    printf("\n");
}
