//
//  Assigned by:
//
//  File Name:        polynomial.c
//  Files in project: main.c, main.h, double_list.c, double_list.h
//                    stack_arr.h, stack_arr.c, polynomial.c, polynomial.h
//

#include "polynomial.h"
#define _CRT_SECURE_NO_WARNINGS

void init_polynom(DoubleList *list) {					    // Initialize the polynom
    create_list(list);
}

void create_pol_type(Polynomial *pol, double coef, unsigned int exp) {		// Create polynom type with given coefficient and exponent
    pol->coef = coef;
    pol->exp = exp;
}

void insert_polynom(Polynomial *pol, double coef, unsigned int exp, DoubleList *list) {		// Insert struct of polynom into list
    create_pol_type(pol, coef, exp);
    insert_node_by_order(list, *pol);                       // Insert values by order
}

int polynom_size(DoubleList *list) {						// Return the max size of exponent in polynom
    return list->tail->data.exp;
}

void polynom_reset(DoubleList *list) {					    // Reset the polynom
    Node *head = list->head;
    Node *to_delete = NULL;
    while (head) {
        to_delete = head;
        head = head->next;
        free(to_delete);
    }
    init_polynom(list);                                     // Call createList to initialize list to point to NULL
}

void polynom_sum(DoubleList *pol1, DoubleList *pol2, DoubleList *sum_pol) {	// Calculate the sum of the polynom's
    Polynomial sum;
    Node *polynom1 = pol1->tail;
    Node *polynom2 = pol2->tail;
    while (polynom1 && polynom2) {                          // Stop comparison after smaller polynom is ended
        if (polynom1->data.exp == polynom2->data.exp) {     // If exponent is equal - sum the values
            insert_polynom(&sum, polynom1->data.coef + polynom2->data.coef, polynom1->data.exp, sum_pol);
            polynom1 = polynom1->prev;
            polynom2 = polynom2->prev;
        }
        else if (polynom1->data.exp > polynom2->data.exp) { // Insert the greater exponent only
            insert_polynom(&sum, polynom1->data.coef, polynom1->data.exp, sum_pol);
            polynom1 = polynom1->prev;
        }
        else {
            insert_polynom(&sum, polynom2->data.coef, polynom2->data.exp, sum_pol);
            polynom2 = polynom2->prev;
        }
    }
	while (polynom1) {                                      // Insert left values in first polynom
		insert_polynom(&sum, polynom1->data.coef, polynom1->data.exp, sum_pol);
		polynom1 = polynom1->prev;
	}
	while (polynom2) {                                      // Insert left values in second polynom
		insert_polynom(&sum, polynom2->data.coef, polynom2->data.exp, sum_pol);
		polynom2 = polynom2->prev;
	}
}

void polynom_subtract(DoubleList *pol1, DoubleList *pol2, DoubleList *sum_pol) {    // Calculate subtraction of polynoms
    Polynomial sum;
    Node *polynom1 = pol1->tail;
    Node *polynom2 = pol2->tail;
    while (polynom1 && polynom2) {                          // Stop comparison after smaller polynom is ended
        if (polynom1->data.exp == polynom2->data.exp) {     // If exponent is equal - subtract
            insert_polynom(&sum, polynom1->data.coef - polynom2->data.coef, polynom1->data.exp, sum_pol);
            polynom1 = polynom1->prev;
            polynom2 = polynom2->prev;
        }
        else if (polynom1->data.exp > polynom2->data.exp) { // Insert the greater exponent only
            insert_polynom(&sum, polynom1->data.coef, polynom1->data.exp, sum_pol);
            polynom1 = polynom1->prev;
        }
        else {
            insert_polynom(&sum, 0 - polynom2->data.coef, polynom2->data.exp, sum_pol);
            polynom2 = polynom2->prev;
        }
    }
	while (polynom1) {                                      // Insert left values in first polynom
		insert_polynom(&sum, polynom1->data.coef, polynom1->data.exp, sum_pol);
		polynom1 = polynom1->prev;
	}
	while (polynom2) {                                      // Insert left values in second polynom
		insert_polynom(&sum, 0- polynom2->data.coef, polynom2->data.exp, sum_pol);
		polynom2 = polynom2->prev;
	}
}

void polynom_multiply(DoubleList *pol, double c, DoubleList *new_pol) {    // Multiply a polynom with constant "c" value chosen by user
    Polynomial type_pol;
    Node *current = pol->head;
    while (current) {
        insert_polynom(&type_pol,c * current->data.coef, current->data.exp, new_pol);
        current = current->next;
    }
}
