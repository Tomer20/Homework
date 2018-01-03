/*
 Assigned by:
 Yoni Saida 
 Tomer Cohen 
 
 File Name: main.c
 Assignment #3
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
/* Declare functions for exercise 1 */
void exercise_1();
int	* swap_even_odd(int *,int);
/* Declare function for exercise 2 */
void exercise_2();
int sum_sign_change(int);
int is_devide_by_eleven(int);
/* Declare functions for exercise 3 */
void exercise_3();
int * merge_array(int *, int *, int, int, int *);
/* Declare functions for exercise 4 */
void exercise_4();
int ex_4_a(int *, int *, int);
int ex_4_b(int *, int *, int);
int ex_4_c(int *, int *, int);
/* Declare functions for exercise 5 */
void exercise_5();
void remove_char(char *, char);
char * input_long(void);
/* Mutual functions */
int * create_array(int);
void print_array(int *, int);
void merge(int *, int, int, int);
void merge_sort(int *,int, int);

int main() {
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
    return 1;
}

void exercise_1() {                                         // Exercise 1 function.
    int arr_size, *array_ptr;
    printf("\n\n======= Exercise 1 =======\n");
    printf("Enter size of array:\n");
    scanf("%d", &arr_size);
    array_ptr = create_array(arr_size);                     // Call a function to create an array.
    printf("First array:\n");
    print_array(array_ptr, arr_size);
    array_ptr = swap_even_odd(array_ptr, arr_size);         // Call a function to change values inside the given array.
    printf("New array:\n");
    print_array(array_ptr, arr_size);
    free(array_ptr);
}

int	* swap_even_odd(int * arr,int n) {
    int left=0, right=n-1, temp;
    while (left<right) {                                    // Checks all numbers from both sides of the array.
        while (arr[left]%2==1 && left<right) {
            left++;
        }
        while (arr[right]%2==0 && left<right) {
            right--;
        }
        if (left < right) {                                 // Swap if i is even and j is odd.
            temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
    return arr;
}

void exercise_2() {                                         // Exercise 2 function.
    int num;
    printf("\n\n======= Exercise 2 =======\n");
    printf("Please enter a number to check if it diveds by 11\n");
    scanf("%d", &num);
    is_devide_by_eleven(num);
}

int sum_sign_change(int num) {
    if (num != 0) {
        return (num%10 + sum_sign_change(num/-10));         // -10 changes the sign from '+' to '-'.
    }
    else {
        return 0;
    }
}

int is_devide_by_eleven(int num) {                          // Function to check if a given number divides by 11.
    while (num>=10) {
        num = abs(sum_sign_change(num));
    }
    if (num==0) {
        printf("\nNumber devides by 11\n");
    }
    else {
        printf("\nNumber doesn't devide by 11\n");
    }
    return 1;
}

void exercise_3(){                                          // Exercise 3 function.
    int n, m, *arr_n, *arr_m, *new_arr;
    int k=0;
    printf("\n\n======= Exercise 3 =======\n");
    printf("Please enter the size of the first and second arrays:\n");
    scanf("%d %d", &n, &m);
    arr_n = create_array(n);
    arr_m = create_array(m);
    new_arr = merge_array(arr_n, arr_m, n, m, &k);
    printf("\nThe new array is:\n");
    print_array(new_arr, k);
    free(arr_n);
    free(arr_m);
    free(new_arr);
}

// Function that returns a new array with mutual values of arr_n and arr_m.
int * merge_array(int * arr_n, int * arr_m, int n, int m, int * k_ptr) {
    int i=0, j=0;
    int *new_arr;
    int k = *k_ptr;
    if (n < m) {                                            // Allocate the memory of new_arr according to the smaller array.
        new_arr = (int *) calloc(n, sizeof(int));
    }
    else {
        new_arr = (int *) calloc(m, sizeof(int));
    }
    assert(new_arr);
    merge_sort(arr_n, i, n-1);
    merge_sort(arr_m, i, m-1);
    while (i<n && j<m) {
        if (arr_n[i] == arr_m[j]) {
            new_arr[k] = arr_n[i];
            i++;
            j++;
            k++;
        }
        else if (arr_n[i] < arr_m[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    void * realloc(void *new_arr, size_t k);                // Reallocate the memory of new_arr according to the number of mutual values.
    *k_ptr = k;
    return new_arr;
}

void exercise_4() {                                         // Exercise 4 function.
    int arr_size, *array_a, *array_b, sol, ans=0;
    printf("\n\n======= Exercise 4 =======\n");
    printf("Enter size of arrays:\n");
    scanf("%d", &arr_size);
    array_a = create_array(arr_size);                       // Call a function to create an array.
    array_b = create_array(arr_size);                       // Call a function to create an array.
    printf("Exercise 4 has three solutions, which of them would you like to try [1-3]?\nOr press 4 to run all sub-solutions\n");
    scanf("%d", &sol);
    switch (sol) {
        case 1:                                             // Run solution 1.
            ans = ex_4_a(array_a, array_b, arr_size);
            break;
        case 2:                                             // Run solution 2.
            ans = ex_4_b(array_a, array_b, arr_size);
            break;
        case 3:                                             // Run solution 3.
            ans = ex_4_c(array_a, array_b, arr_size);
            break;
        case 4:
            if (ex_4_a(array_a, array_b, arr_size)) {
                printf("Solution 1: The arrays are exchangeable!\n");
            }
            else {
                printf("Solution 1: The arrays are not exchangeable.\n");
            }
            printf("\nSince the arrays change in the first answer, please provide new arrays.\n");
            array_a = create_array(arr_size);                // Call a function to create an array.
            array_b = create_array(arr_size);                // Call a function to create an array.
            if (ex_4_b(array_a, array_b, arr_size)) {
                printf("Solution 2: The arrays are exchangeable!\n");
            }
            else {
                printf("Solution 2: The arrays are not exchangeable.\n");
            }
            array_a = create_array(arr_size);                // Call a function to create an array.
            array_b = create_array(arr_size);                // Call a function to create an array.
            if (ex_4_c(array_a, array_b, arr_size)) {
                printf("Solution 3: The arrays are exchangeable!\n");
            }
            else {
                printf("Solution 3: The arrays are not exchangeable.\n");
            }
            break;
        default:
            break;
    }
    if (ans == 1 && sol != 4) {
        printf("Solution %d: The arrays are exchangeable!\n", sol);
    }
    else if (ans == 0 && sol != 4) {
        printf("Solution %d: The arrays are not exchangeable.\n", sol);
    }
    free(array_a);
    free(array_b);
}

int ex_4_a(int * arr_a, int * arr_b, int size) {             // Function 4 A - Not recursive O(nlogn).
    int i=0, bool_t = 1;
    merge_sort(arr_a, i, size-1);                            // Sort both arrays.
    merge_sort(arr_b, i, size-1);
    while (i<size && bool_t!=0) {
        if (arr_a[i] != arr_b[i]) {
            bool_t = 0;                                      // Stop the loop if an integer from 'arr_a' could not be found in 'arr_b'.
        }
        i++;
    }
    return bool_t;
}

int ex_4_b(int * arr_a, int * arr_b, int size) {             // Function 4 B - Recursive.
    int found=0, i, temp;                                    // 'found' indicates if arr_a[i] was found in arr_b.
    if (size==0) {                                           // Exit when size is minimal.
        if(arr_a[0]==arr_b[0]) {
            return 1;
        }
        else {
            return 0;
        }
    }
    for (i=size-1; i>=0 && found==0; i--) {
        if (arr_b[i] == arr_a[size-1]) {                     // Check existence of element in arr_a.
            temp = arr_b[i];
            arr_b[i] = arr_b[size-1];
            arr_b[size-1] = temp;
            found = 1;
        }
    }
    if (found == 1) {
        return ex_4_b(arr_a, arr_b, size-1);
    }
    else {
        return 0;
    }
}

int ex_4_c(int * arr_a, int * arr_b, int size) {             // Function 4 C - Not recursive O(n).
    int i, multiply_a=1, multiply_b=1, sum_a=0, sum_b=0;
    for (i=0; i<size; i++) {
        multiply_a *= arr_a[i];                              // Multiply all arr_a values.
        sum_a += arr_a[i];                                   // Sum all arr_a values.
        multiply_b *= arr_b[i];                              // Multiply all arr_b values.
        sum_b += arr_b[i];                                   // Sum all arr_b values.
    }
    // If sum and multiply of both arrays are equal than they have the same numbers.
    if (multiply_a == multiply_b && sum_a == sum_b) {
        return 1;
    }
    return 0;
}

void exercise_5() {                                          // Exercise 5 function.
    char ch;
    char *str = input_long();
    printf("\n\n======= Exercise 5 =======\n");
    printf("Enter a char to replace:\n");
    scanf(" %c", &ch);
    remove_char(str, ch);
    printf("New string is: %s\n", str);
    free(str);
}

void remove_char(char * str, char ch) {                     // Remove all occurrences of a character in a string.
    int i, j=0;                                             // 'j' will be the index of 'ch' in the string.
    long len=strlen(str);
    for (i=0; i<len; i++) {                                 // Check each charcter in the string.
        if (str[i]!=ch) {
            str[j]=str[i];
            j++;
        }
    }
    str[j]='\0';
}

char * input_long(void) {                                   // Function to receive a string.
    char tempstr[80], *str;
    printf("Enter a string:\n");
    scanf(" %[^\n]s", tempstr);
    str=(char*)malloc((strlen(tempstr)+1)*sizeof(char));
    strcpy(str, tempstr);
    return str;
}

/* Mutual Functions */

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

void merge(int *a,int p,int q,int r) {                      // Function to merge an array.
    int i=p,j=q+1,k=0;
    int* temp=(int*)calloc(r-p+1, sizeof(int));
    while ((i<=q)&& (j<=r))
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    while(j<=r)
        temp[k++]=a[j++];
    while(i<=q)
        temp[k++]=a[i++];
    for(i=p,k=0;i<=r;i++,k++)
        a[i]=temp[k];
    free(temp);
}

void merge_sort(int *a,int first, int last) {               // Function to merge and sort an array (depands on 'merge' function).
    int middle;
    if(first < last)
    {
        middle=(first+last)/2;
        merge_sort(a,first,middle);
        merge_sort(a,middle+1,last);
        merge(a,first,middle,last);
    }
}
