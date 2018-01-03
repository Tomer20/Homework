//
//  Assigned by:
//  Group number      61108-61
//
//  File Name:        main.h
//  Files in project: main.c, main.h, linked_list.c,
//                    inked_list.h, trio.c, trio.h
//

#pragma once
#include "linked_list.h"
#include "trio.h"
#define _CRT_SECURE_NO_WARNINGS

#define ROWS_A 2        // Matrix A rows
#define COLS_A 2        // Matrix A columns
#define ROWS_B 2        // Matrix B rows
#define COLS_B 3        // Matrix B columns

void exercise_1();
unsigned int powerCalculator(int base, int exponent);
unsigned int* powerArray(int n);

void exercise_2();
int** matrixMultiplication(int mat_a[ROWS_A][COLS_A], int mat_b[ROWS_B][COLS_B]);
void fillStaticMatrix_A(int rows, int cols, int mat[ROWS_A][COLS_A]);
void fillStaticMatrix_B(int rows, int cols, int mat[ROWS_B][COLS_B]);
void printStaticMatrix_A(int rows, int cols, int mat[ROWS_A][COLS_A]);
void printStaticMatrix_B(int rows, int cols, int mat[ROWS_B][COLS_B]);

void exercise_3();
int isTrio (int** matrix, TrioType* trio_arr, LinkedTrioList* list, int row, int col);

void exercise_4();
void removeEven(LinkedList* list, LinkedList* new_list);

void exercise_5();
void switchEven(LinkedList* list, LinkedList* new_list);

// Mutual functions to exercises 2 and 3
int** createDynamicMatrix(int rows, int cols);
void fillDynamicMatrix(int** mat, int rows, int cols);
void printDynamicMatrix(int** mat, int rows, int cols);
void freeMatrix(int** mat, int n);
