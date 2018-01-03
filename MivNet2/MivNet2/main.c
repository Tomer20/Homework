//
//  Assigned by:
//
//  File Name:        main.c
//  Files in project: main.c, main.h, double_list.c, double_list.h
//                    stack_arr.h, stack_arr.c, polynomial.c, polynomial.h
//

#include <stdio.h>
#include "main.h"
#define _CRT_SECURE_NO_WARNINGS

#define STR_LEN 20

void exercise_1() {											// Arithmetic stack main
    stack S1, S2;
    char str[STR_LEN];
    create_stack(&S1);
    create_stack(&S2);
    printf("Please enter an arithmetic expression (allowed characters: '0-9', 'A-H', '+ - * / ^')\n");
    gets(str);
    print_stack(&S1, &S2, &str[0]);							// Send stack S1,S2,arithmetic expression
}

void print_stack(stack *S1, stack *S2, char *str) {         // Print stack and table
    /* Function includes bonus (support A^B^C from right to left) */
    char temp_operand, temp_operation , result = 'Z', topped;
    int i;
    push(str[0], S1);				                        // Push first value to S1 (operand)
    push(str[1], S2);				                        // Push second value to S2 (operation)
    push(str[2], S1);				                        // Push third value to S1 (operand)
    i = 3;							                        // Starting to check the string from the 4th place
    printf("The table is: \n");
    printf("Operation\tOperand1\tOperand2\tResult\n");
    printf("---------\t--------\t--------\t------\n");
    while (str[i] != '\0') {
        stack_top(S2, &topped);			                    // Saving the topped operator to check priority
        temp_operation = str[i];
        temp_operand = str[i + 1];
        switch (temp_operation) {
            case '^':						                // In case of '^': fpush the next operand and operation, then print row
                push(temp_operand, S1);
                push(temp_operation, S2);
                print_row(S1, S2, result);
                result--;
                i += 2;
                continue;
            case '*': case '/':				                // In case of '*' or '/': check for priority of '^'
                if (topped == '^') {
                    print_row(S1, S2, result);
                    result--;
                }
                push(temp_operand, S1);
                push(temp_operation, S2);
                i += 2;
                continue;
            case '+': case '-':				                // incase of '+' or '-': check for other priority waiting in S2
                if ((topped == '^') || (topped == '*') || (topped == '/')) {
                    print_row(S1, S2, result);
                    result--;
                }
                push(temp_operand, S1);
                push(temp_operation, S2);
                i += 2;
                continue;
        }
    }
    while (!stack_is_empty(S2)) {		                    // Print the remaining items left in stack
        print_row(S1, S2, result);
        result--;
    }
}

void print_row(stack *S1, stack *S2, char result) {		    // Print the calculation action and push it to S1
    char temp, temp2, temp3;
    pop(S2, &temp2);                                        // Pop from S2, S1, S1 and print
    printf("  %c\t\t", temp2);
    pop(S1, &temp);
    pop(S1, &temp3);
    printf("  %c\t\t", temp3);
    printf("  %c\t\t", temp);
    printf("  %c\t\t", result);
    push(result, S1);
    printf("\n");
}

void polynom_input(DoubleList *list) {						// Receive user input for polynom
	int exp;
	double coef;
	Polynomial pol;
	printf("\nEnter numbers to the polynom (until negative exponent)\n");
	printf("Enter coefficient: ");
	scanf(" %lf", &coef);
	printf("\nEnter exponent: ");
	scanf(" %d", &exp);
	while (exp >= 0) {                                      // Stop getting input when exponent is less than 0
		insert_polynom(&pol, coef, exp, list);
		printf("\nEnter coefficient: ");
		scanf(" %lf", &coef);
		printf("\nEnter exponent: ");
		scanf(" %d", &exp);
	}
}

void exercise_2() {										    // Polynomial main
    DoubleList list, list2, list3, list4, list5;
	double multiplier;
    init_polynom(&list);
    init_polynom(&list2);
    init_polynom(&list3);
	init_polynom(&list4);
    init_polynom(&list5);
	polynom_input(&list);
	polynom_input(&list2);
    printf("\nThe first polynom is:\n");					// Print the first polynom after user input
    print_list_backward(&list);
    printf("\nThe second polynom is:\n");                   // Print the second polynom after user input
    print_list_backward(&list2);
    printf("\nFirst polynom size is: %d\n", polynom_size(&list));		// Print first & second polynom size
	printf("\nSecond polynom size is: %d\n", polynom_size(&list2));
	printf("\nThe sum of the two given polynoms is:\n");
    polynom_sum(&list, &list2, &list3);						// Calculate two polynom's sum
	print_list_backward(&list3);
	printf("\nPolynom1 subtract Polynom2 is:\n");
	polynom_subtract(&list, &list2, &list4);				// Calculate first polynom subtract the second
	print_list_backward(&list4);
	printf("\nEnter a number to multiply the first polynom with: ");
	scanf(" %lf", &multiplier);
    polynom_multiply(&list, multiplier, &list5);			// Calculate multiplication of first polynom with value user entered
	printf("\nPolynom multiplied with %lf is:\n", multiplier);
    print_list_backward(&list5);
	polynom_reset(&list);									// Reset polynom
	polynom_reset(&list2);
    printf("\nThe first polynom after reset:\n");
    print_list_backward(&list);
    printf("\nThe second polynom after reset:\n");
    print_list_backward(&list2);
}

int main() {
    int func;
    printf("Please enter question number (1 or 2)\nOr press '3' to run all excersises one by one: \n");
    scanf("%d", &func);
	flushall();
    switch (func) {
        case 1:                                             // Run exercise 1.
            exercise_1();
            break;
        case 2:                                             // Run exercise 2.
            exercise_2();
            break;
        case 3:                                             // Run all exercises.
            exercise_1();
            exercise_2();
         default:
            break;
    }
    return 0;
}
