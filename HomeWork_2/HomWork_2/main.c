/*
 Assigned by:
 Yoni Saida 
 Tomer Cohen 
 
 File Name: main.c
 Assignment #2
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

/* Declare functions for exercise 1 */
void exercise_1();
int * create_array(int);
void print_array(int *, int);
int	* create_new_array(int *,int);
/* Declare function for exercise 2 */
void exercise_2();
int distance_value(int, int);
/* Declare functions for exercise 3 */
void exercise_3();
int pascal_triangle(int);
void print_space(int, int);
void print_pascal_line(int);
/* Declare functions for exercise 4 */
void exercise_4();
int betrothed_numbers(int);
int devidors_sum(int);
/* Declare functions for exercise 5 */
void exercise_5();
double newton_raphson(double, double);

void main() {
    int func;
    printf("Please enter question number (1-5)\nOr press '6' to run all excersises one by one: \n");
    scanf("%d", &func);
    switch (func) {
        case 1:                                             // Run exercise 1.
            exercise_1();
            break;
        case 2:                                             // Run exercise 2.
            exercise_2();
            break;
        case 3:                                             // Run exercise 3.
			exercise_3();
            break;
        case 4:                                             // Run exercise 4.
			exercise_4();
            break;
        case 5:                                             // Run exercise 5.
			exercise_5();
            break;
        case 6:                                             // Run all exercises.
            exercise_1();
            exercise_2();
			exercise_3();
			exercise_4();
			exercise_5();
        default:
            break;
    }
}

void exercise_1() {                                         // Exercise 1 function.
    int arr_size, *array_ptr;
	printf("\n\n======= Exercise 1 =======\n");
    printf("Enter size of array:\n");
    scanf("%d", &arr_size);
    array_ptr = create_array(arr_size);                     // Call a function to create an array.
    printf("First array:\n");
    print_array(array_ptr, arr_size);
    array_ptr = create_new_array(array_ptr, arr_size);      // Call a function to change values inside the given array.
    printf("New array:\n");
    print_array(array_ptr, arr_size);
    free(array_ptr);
}

int * create_array(int arr_size) {                          // Function to create array, size of array is given as parameter.
    int i, *arr;
    arr = (int *) calloc(arr_size, sizeof(int));            // Initialize array size.
    assert(arr);                                            // Check array memory allocation.
    printf("Please enter values to the array:\n");
    for(i=0; i<arr_size; i++) {
        scanf("%d", &arr[i]);
    }
    return arr;
}

void print_array(int *arr, int size) {                      // Function to print all values in the array.
    int i;
    for(i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
	printf("\n");
}

int * create_new_array(int *arr, int arr_size) {            // This function recieves an array and its size.
    int i, j, sum=0;
    for (i=arr_size-1; i>=0; i--) {                         // Change array values from the end to start.
        for (j=i; j>=0; j--) {                              // Sum in a loop all values from curren index to start.
            sum += arr[j];
        }
        arr[i] = sum;                                       // Save sum into arr[i].
        sum=0;
    }
    return arr;                                             // Return the new array.
}

void exercise_2() {                                         // Exercise 2 main.
    int answer, a, b;
	printf("\n\n======= Exercise 2 =======\n");
    printf("Please enter numbers a and b:\n");
    scanf("%d %d", &a, &b);
	while (a>b) {											// If a is greater than b - ask for new input.
		printf("a (%d) should be smaller than b (%d). Please try again.\n", a, b);
		scanf("%d %d", &a, &b);
	}
    answer = distance_value(a, b);
	printf("The distance is: %d\n", answer);
}

int distance_value(int a, int b) {                          // Exercise 2 function.
    int response, number, first=0, second=0;
    printf("Please enter the first number of the series:\n");
    scanf("%d", &number);                                   // Recieve the first number of the series.
    while (number!=-1) {
        if (number > (a+b)/2 && number < b) {               // First condition.
            first+=number;
        }
        if (number > a && number < (a+b)/2) {               // Second condition.
            second+=number;
        }
        printf("Please enter another number:\n");
        scanf("%d", &number);
    }
    response = first - second;                              // Calculate the distance between 'first' and 'second'.
    return response;
}

void exercise_3() {                                         // Exercise 3 main.
	int a;
	printf("\n\n======= Exercise 3 =======\n");
	printf("Please enter number of rows for Pascal triangle:\n");
    scanf("%d", &a);
    pascal_triangle(a);
}

int pascal_triangle(int n) {                                // Exercise 3 function.
    int i;
    for (i=0; i<n; i++) {                                   // 'i' is the current line number.
        print_space(i, n);
        print_pascal_line(i);
    }
    return 1;
}

void print_space(int i, int n) {
    for (; i<n; i++) {                                      // Print spaces according to line number.
        printf(" ");
    }
}

void print_pascal_line(int i) {
    double k, pascal_multiplier=1;
    printf("1 ");                                           // Print '1' as the first index in the line.
    for (k=1; k<=i; k++){
        pascal_multiplier *= (i-k+1)/k;                     // Calculate the number should be in index (i,k).
        printf("%d ", (int) pascal_multiplier);
    }
    printf("\n");
}

void exercise_4() {											// Exercise 4 main.
	int a;
	printf("\n\n======= Exercise 4 =======\n");
    printf("Please enter number to find betrothed numbers:\n");
    scanf("%d", &a);
    betrothed_numbers(a);							
}
int betrothed_numbers(int n) {
    int i, sum_a, sum_b, counter=0;
    for (i=2; i<n; i++) {
        sum_a = devidors_sum(i);						    // Calculate the sum of devidors of i.
        sum_b = devidors_sum(sum_a-1);						// Calculate the sum of devidors of sum of i.
        if (sum_b-1 == i && sum_b<sum_a) {					// Check if the numbers are betrothed numbers and make sure to print each couple only once.
            printf("Betrothed numbers: %d,%d\n", sum_a-1,i);
            counter++;
        }
    }
    if (counter==0) {                                       // If no betrothed numbers were found - print a message.
        printf("No betrothed numbers were found for the given number (%d).\n", n);
    }
    return 1;
}

int devidors_sum(int n) {									// Function to some all 'n' devidors.
    int i, sum=1;
    for (i=2; i<n; i++) {
        if (n%i==0) {
            sum+=i;											// Count the number if it devides by n.
        }
    }
    return sum;
}


void exercise_5()											// Exercise 5 main.
{
	double n, x=1, y;
	printf("\n\n======= Exercise 5 =======\n");
	printf("Enter a number to calculate its square root:\n");
	scanf("%lf",&n);
	y = newton_raphson(x,n);
	printf("The most acurate answer is: %lf\n",y);
}
	
double newton_raphson(double x, double n)                   // Recursive function to find square root.
{
	double new_x;
	new_x = x-((x*x-n)/(2*x));								// Calculate newton-raphson square root.
	if (fabs(new_x-x) <= 0.00001) {							
		return new_x;										// Returns the most accurate square root.
	}
	return newton_raphson(new_x, n);						// Recursive call.
}
