//
//  Assigned by:
//  Group number      61108-61
//
//  File Name:        main.h
//  Files in project: main.c, main.h
//

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_SIZE 100

void exercise_1();											// Main exercise 1
char **find_letter_string(char letter, char *str, int *arr_size, int *col_size);	// Returns pointer to array of strings

void exercise_2();											// Main exercise 2
char *remove_chars(char *str);

void exercise_3();											// Main exercise 3
int write_file(char *filename);								// Function for writing to file
char commonestLetter(char *filename);						// Finds and returns the commonest char in a string

void exercise_4();											// Main exercise 4
void str_decoder(char *str);								// Decodes string, changes the original string

void exercise_5();											// Main exercise 5
void declaration_calculation(char *declaration, char *filename);	// Write to file required bytes according to declaration line
int print_file(char *filename);								// Print file to console
