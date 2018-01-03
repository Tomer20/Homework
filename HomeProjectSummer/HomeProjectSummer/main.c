//
//  Assigned by:
//  Group number      61108-61
//
//  File Name:        main.c
//  Files in project: main.c, main.h, linked_list.c,
//                    inked_list.h, trio.c, trio.h
//

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "linked_list.h"
#include "trio.h"
#define _CRT_SECURE_NO_WARNINGS

void exercise_1() {
    int arr_size, i;
    unsigned int* power_arr = NULL;
    printf("\n===== Exercise Number 1 =====\n");
    printf("Please enter array size: ");
    scanf("%d", &arr_size);
    power_arr = powerArray(arr_size);
    printf("The calculated array:\n");
    for (i = 0; i<arr_size; i++)
        printf("%d ", power_arr[i]);
    printf("\n");
    free(power_arr);
}

unsigned int powerCalculator(int base, int exponent) {
    unsigned int power = 1;
    while (exponent != 0) {
        power *= base;
        --exponent;
    }
    return power;
}

unsigned int* powerArray(int n) {
    unsigned int* arr = (unsigned int*)calloc(n, sizeof(int));
    if (arr) {
        int i, base = 2, multip = 32;
        for (i = 0; i < n; i++) {
            arr[i] = powerCalculator(base, i % multip);
        }
    }
    else {
        printf("Failed to allocate memory for the array.");
        arr = 0;
    }
    return arr;
}

void exercise_2() {
    int arr_A[ROWS_A][COLS_A];
    int arr_B[ROWS_B][COLS_B];
    int** arr_C = NULL;
    printf("\n===== Exercise Number 2 =====\n");
    if (COLS_A != ROWS_B) {
        printf("Columns of matrix a should be equal to matrix b rows.\n");
        free(arr_C);
    }
    else {
        printf("Matrix A size: %d X %d\n", ROWS_A, COLS_A);
        fillStaticMatrix_A(ROWS_A, COLS_A, arr_A);
        printStaticMatrix_A(ROWS_A, COLS_A, arr_A);
        printf("Matrix B size: %d X %d\n", ROWS_B, COLS_B);
        fillStaticMatrix_B(ROWS_B, COLS_B, arr_B);
        printStaticMatrix_B(ROWS_B, COLS_B, arr_B);
        arr_C = matrixMultiplication(arr_A, arr_B);
        printf("\nThe multiplication of the matrices is:\n");
        printDynamicMatrix(arr_C, ROWS_A, COLS_B);
        freeMatrix(arr_C, ROWS_A);
    }
}

int** matrixMultiplication(int mat_a[ROWS_A][COLS_A], int mat_b[ROWS_B][COLS_B]) {
    int** arr = NULL;
    int i, j, k, sum = 0;
    arr = createDynamicMatrix(ROWS_A, COLS_B);
    
    for (i = 0; i < ROWS_A; i++) {
        for (j = 0; j < COLS_B; j++) {
            for (k = 0; k < ROWS_B; k++) {
                sum += mat_a[i][k] * mat_b[k][j];
            }
            arr[i][j] = sum;
            sum = 0;
        }
    }
    return arr;
}

void fillStaticMatrix_A(int rows, int cols, int mat[ROWS_A][COLS_A]){
    int i, j, val;
    printf("Enter numbers to fill the matrix\n");
    for (i = 0; i<rows; i++)
        for (j = 0; j<cols; j++) {
            printf("Number for index [%d][%d]: ", i, j);
            scanf("%d", &val);
            mat[i][j] = val;
        }
}

void fillStaticMatrix_B(int rows, int cols, int mat[ROWS_B][COLS_B]){
    int i, j, val;
    printf("Enter numbers to fill the matrix\n");
    for (i = 0; i<rows; i++)
        for (j = 0; j<cols; j++) {
            printf("Number for index [%d][%d]: ", i, j);
            scanf("%d", &val);
            mat[i][j] = val;
        }
}

void printStaticMatrix_A(int rows, int cols, int mat[ROWS_A][COLS_A]){
    int i, j;
    printf("\n");
    for (i = 0; i<rows; i++) {
        for (j = 0; j<cols; j++)
            printf("%8d", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

void printStaticMatrix_B(int rows, int cols, int mat[ROWS_B][COLS_B]) {
    int i, j;
    printf("\n");
    for (i = 0; i<rows; i++) {
        for (j = 0; j<cols; j++)
            printf("%8d", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

void exercise_3() {
    int** matrix = NULL;
    int array_size, row, col, i;
    TrioType* trio_arr = NULL;
    LinkedTrioList* list = (LinkedTrioList *) malloc(sizeof(LinkedTrioList));
    printf("\n===== Exercise Number 3 =====\n");
    createTrioList(list);
    printf("Please enter number of rows for the matrix: ");
    scanf("%d", &row);
    printf("Enter number of columns for the matrix: ");
    scanf("%d", &col);
    trio_arr = (TrioType *) malloc((row * col) * sizeof(TrioType));
    matrix = createDynamicMatrix(row, col);
    fillDynamicMatrix(matrix, row, col);
    printf("Your matrix is:\n");
    printDynamicMatrix(matrix, row, col);
    array_size = isTrio(matrix, trio_arr, list, row, col);
    printf("The array size is %d\nArray values:\n", array_size);
    for (i = 0; i < array_size; i++) {
        printf("matrix[%d][%d] = %d\n", (trio_arr + i)->index_row, (trio_arr + i)->index_col, (trio_arr + i)->sum);
    }
    printf("The calculated list:\n");
    printTrioList(list);
    freeMatrix(matrix, row);
    freeTrioList(list);
    free(trio_arr);
}

int isTrio (int** matrix, TrioType* trio_arr, LinkedTrioList* list, int row, int col) {
    int i, j, arr_index = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (matrix[i][j] == i + j) {
                trio_arr[arr_index].index_row = i;
                trio_arr[arr_index].index_col = j;
                trio_arr[arr_index].sum = i + j;
                insertLastTrioNode(trio_arr[arr_index], list);
                arr_index++;
            }
        }
    }
    trio_arr = (TrioType *) realloc(trio_arr, arr_index * sizeof(TrioType));
    return arr_index;
}

void exercise_4() {
    LinkedList num_list, odds_list;
    printf("\n===== Exercise Number 4 =====\n");
    createList(&num_list);
    createList(&odds_list);
    fillList(&num_list);
    printf("The given list:\n");
    printList(&num_list);
    removeEven(&num_list,&odds_list);
    printf("The odds list:\n");
    printList(&odds_list);
    printf("The given list after deleting items:\n");
    printList(&num_list);
    freeList(&num_list);
    freeList(&odds_list);
}

void removeEven(LinkedList* list, LinkedList* new_list) {
    ListNode* current = list->head;
    while (current) {
        if (current->data % 2 != 0) {
            insertLastNode(current->data, new_list);
            current = deleteLink(current, list);
        }
        else {
            current = current->next;
        }
    }
}

void exercise_5() {
    LinkedList num_list, odds_list;
    printf("\n===== Exercise Number 5 =====\n");
    createList(&num_list);
    createList(&odds_list);
    fillList(&num_list);
    printf("The given list:\n");
    printList(&num_list);
    switchEven(&num_list, &odds_list);
    printf("The odds list:\n");
    printList(&odds_list);
    printf("The given list after deleting items:\n");
    printList(&num_list);
    freeList(&num_list);
    freeList(&odds_list);
}

void switchEven(LinkedList* list, LinkedList* new_list) {
    ListNode* current_a = list->head;
    ListNode* current_b = NULL;
    ListNode* next_node = current_a->next;
    while (next_node) {
        if (current_a->data % 2 != 0) {
            if (!current_a->prev) {     // first node
                list->head = current_a->next;
            }
            else {
                current_a->prev->next = current_a->next;
            }
            if (!current_a->next) {     // last node
                list->tail = current_a->prev;
            }
            else {
                current_a->next->prev = current_a->prev;
            }
            next_node = current_a->next;
            current_b = current_a;
            current_a = current_a->next;
            current_b->next = NULL;
            if (isListEmpty(new_list)) {
                //make head & tail pointing to link
                new_list->head = new_list->tail = current_b;
            }
            else {
                //make link a new last link
                new_list->tail->next = current_b;
                //mark old last node as prev of new link
                current_b->prev = new_list->tail;
                //point last to new last node
                new_list->tail = current_b;
            }
            
        }
        else {
            next_node = current_a = current_a->next;
        }
    }
}

int** createDynamicMatrix(int rows, int cols) {
    int i;
    int** mat;
    mat = (int **)malloc(rows * cols * sizeof(int));
    for (i = 0; i<rows; i++) {
        mat[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}

void fillDynamicMatrix(int** mat, int rows, int cols) {
    int i, j, val;
    printf("Enter numbers to fill the matrix\n");
    for (i = 0; i<rows; i++)
        for (j = 0; j<cols; j++) {
            printf("Number for index [%d][%d]: ", i, j);
            scanf("%d", &val);
            mat[i][j] = val;
        }
}

void printDynamicMatrix(int** mat, int rows, int cols) {
    int i, j;
    printf("\n");
    for (i = 0; i<rows; i++) {
        for (j = 0; j<cols; j++)
            printf("%8d", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

void freeMatrix(int** mat, int n) {
    int i;
    for (i = 0; i<n; i++) {
        free(mat[i]);
    }
}

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
    return 0;
}
