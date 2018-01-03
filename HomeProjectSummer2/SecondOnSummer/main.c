//
//  Assigned by:
//  Group number      61108-61
//
//  File Name:        main.c
//  Files in project: main.c, main.h
//

#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

void exercise_1 () {
    char letter;
    char *user_str = (char *) malloc(MAX_STR_SIZE * sizeof(char));					    // allocate string for user input
    char **string_add = NULL;															// array of string will be allocated in the function
    int arr_size = 0, col_free = 0, i = 0;
    printf("\n===== Exercise Number 1 =====\n");
    printf("Please insert a string of words separated by ' ': \n");
    gets(user_str);
    flushall();
    printf("Enter character to search in the string: \n");
    scanf(" %c", &letter);
    string_add = find_letter_string(letter, &user_str[0], &arr_size, &col_free);		// activate the function to find the matching letter from string
    free(user_str);
    for (i = 0; i < col_free; i++) {	// free array of string - first we free each raw, size of rows sent by Ref since it detarmined after we dynamiclly create the array
        free(string_add[i]);
    }
    free(string_add);																	// free array of string - head pointer
}

char **find_letter_string(char letter, char *str, int *arr_size, int *col_size) {
    int i = 0, str_length = 0, k = 0, j = 0, arr_i = 0, arr_j = 0;
    char **string_arr = (char **) malloc(MAX_STR_SIZE * sizeof(char*));
    
    while (str[i] != '\0') {
        if (((str[i] == letter) || (str[i] == letter + 32) || (str[i] == letter - 32)) &&		// verify entering of small or capital letter.
            ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            j = i;
            while ((str[j] != ' ') && (str[j] != '\0')) {								// counting size of each string in order to allocate row at rhe matrix
                str_length++;
                j++;
            }
            string_arr[arr_i] = (char *)malloc(str_length + 1);							// allocate row in the array of string --> +1 for NUL
            for (k = 0; k < str_length; k++) {
                string_arr[arr_i][arr_j] = str[i];										// insert from user string to the array of string
                printf("%c", string_arr[arr_i][arr_j]);
                i++;																	// forwarding user string
                arr_j++;
            }
            printf("\n");
            *arr_size += str_length;													// arr size by Ref
            ++*col_size;																// counting the col by Ref to return and free at the main
            arr_i++;																	// down in array of string to new line
            arr_j = 0;																	// return col index to begining of line
            str_length = 0;
            i++;
        }
        else {
            i++;
        }
    }
    string_arr = (char **) realloc(string_arr, (*arr_size)* sizeof(*string_arr));		// reallocate the array of string to match the data
    return string_arr;
}

void exercise_2() {
    char str[MAX_STR_SIZE];
    char *cut_str = NULL;
    printf("\n===== Exercise Number 2 =====\n");
    printf("Enter a string:\n");
    flushall();
    fgets(str, MAX_STR_SIZE, stdin);                        // Get string from user input
    cut_str = remove_chars(&str[0]);                        // Save the pointer returned from the function
    printf("New string:\n%s", cut_str);                     // print the new string without spaces and numbers
}

char *remove_chars(char *str) {                             // Remove spaces and numbers from a given string
    char *new_str = (char *) malloc(MAX_STR_SIZE * sizeof(char));
    int i = 0, j = 0;
    while (str[i] != '\0') {                                // Read string
        if ((str[i] != ' ') && !((str[i] > '0') && (str[i] < '9'))) {   // If it is not space or number -> copy char to new string
            new_str[j] = str[i];
            j++;
        }
        i++;
    }
    new_str[j] = 0;                                         // Close string
    new_str = (char *) realloc(new_str, (j + 1) * sizeof(char *));      // Realloc new string's size.
    return new_str;
}

void exercise_3() {
    char common_char;
    char filename[] = "input.txt";
    printf("\n===== Exercise Number 3 =====\n");
    if (!write_file(&filename[0])) {                        // Try to write to file, if fialed -> stop the function
        return;
    }
    common_char = commonestLetter(&filename[0]);            // Save the returned char
    if (common_char)	{                                   // Print char if there's any
        printf("The commonest letter is %c\n", common_char);
    }
    else {
        printf("No letters in the file\n");
    }
}

int write_file(char *filename) {
    char line[MAX_STR_SIZE];
    FILE *file = NULL;
    if (!(file = fopen(filename, "w"))) {                   // Try open file for writing
        printf("ERROR: failed to open file.\n");
        return 0;
    }
    printf("Enter lines to file (stop input with empty line):\n");
    fgets(line, MAX_STR_SIZE, stdin);                       // Get user's input
    while (line[0] != '\n') {                               // Insert to file while it is not a new empty line
        fprintf(file, "%s", line);                          // Save user's input to the file
        fgets(line, MAX_STR_SIZE, stdin);
    }
    fclose(file);                                           // Close file
    return 1;
}

char commonestLetter(char *filename) {
    FILE *file = NULL;
    char letter;
    int count_arr[26] = {0};                                // Count array
    int i = 0, max_index = 0, sum = 0;
    if (!(file = fopen(filename, "r"))) {                   // Try open file for reading
        printf("ERROR: failed to open file.\n");
        return 0;
    }
    while ((letter = getc(file)) != EOF) {                  // Read file while it is not the end of file
        if (letter >= 'a' && letter <= 'z') {               // Increase count array by char's ASCII value
            count_arr[letter - 'a']++;
        }
        else if (letter >= 'A' && letter <= 'Z') {
            count_arr[letter - 'A']++;
        }
    }
    for (i = 0; i < 26; i++) {
        if (count_arr[i] >= count_arr[max_index]) {
            max_index = i;                                  // Save index of the biggest and commonest letter
        }
        sum += count_arr[i];                                // Count the array to check if there's no commonest letter
    }
    if (!sum) {
        return 0;
    }
    return 'A' + max_index;                                 // Return commonest letter by ASCII calcutation
}

void exercise_4() {
    char test_str[] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt";
    char str[MAX_STR_SIZE] = {'\0'};
    printf("\n===== Exercise Number 4 =====\n");
    printf("Enter encoded string:\n");
    fgets(str, MAX_STR_SIZE, stdin);                        // Save user's input
    str_decoder(&str[0]);                                   // Decode the string
    printf("The decoded string:\n%s", str);                 // Print the decoded string
    str_decoder(test_str);                                  // Decode the string given in the example
    printf("The decoded string given for example:\n%s\n", test_str);
}

void str_decoder(char *str) {
    int i = 0, word_index = 1;
    int length = strlen(str);
    while (i < length - 1) {
        if (str[i] != ' ') {
            str[i] = str[i] - word_index;                   // Calculate letter by ASCII value
            word_index++;
        }
        else {                                              // If it is a space
            word_index = 1;
        }
        i++;
    }
}

void exercise_5() {
    char declar[MAX_STR_SIZE];
    char file_name[] = "input.txt";
    printf("\n===== Exercise Number 5 =====\n");
    printf("Enter a decleration string:\n");
    fgets(declar, MAX_STR_SIZE, stdin);                     // Save user's input
    declaration_calculation(&declar[0], &file_name[0]);
    print_file(file_name);                                  // Print file to console after creating it
}

void declaration_calculation(char *declaration, char *filename) {
    char *var = NULL;
    char *type = NULL;
    FILE *file = NULL;
    int byte_size, base_size = 0, i = 0, arr_sum;
    if (!(file = fopen(filename, "w"))) {                   // Open file for writing
        printf("ERROR: failed to open file.\n");
        return;
    }
    type = strtok(declaration, " ");                        // Save pointer to start of string up to the next space
    // If block: check if the first word is one of the
    // allowed types and initialize it's regular size
    if (strcmp(type, "char") == 0) {
        base_size = 1;
    }
    else if (strcmp(type, "short") == 0) {
        base_size = 2;
    }
    else if (strcmp(type, "int") == 0) {
        base_size = 4;
    }
    else if (strcmp(type, "float") == 0) {
        base_size = 4;
    }
    else if (strcmp(type, "long") == 0) {
        base_size = 4;
        var = strtok(NULL, " ");                            // Save pointer to start of string up to the next space
        if (strcmp(var, "long") == 0) {                     // We need to check if it is `long long` type
            base_size *= 2;
            var = strtok(NULL, ",");
        }
    }
    else if (strcmp(type, "double") == 0) {
        base_size = 8;
    }
    byte_size = base_size;                                  // Initialize byte_size for print incase there won't be changes to its value
    if (!var) {
        var = strtok(NULL, ",");                            // Save pointer to start of string up to the next comma
    }
    while (var) {                                           // Continue reading as long as there is a word
        i = 0;
        while (var[i] != ';' && var[i] != '\0') {
            while (var[i] == ' ') {                         // Ignore spaces
                i++;
            }
            if (var[i] == ',') {                            // Continue to next var if the char is comma
                i++;
                continue;
            }
            else if (var[i] == '*') {                       // If it is '*' change byte_size to pionter size and continue loop
                byte_size = 4;
                i++;
                continue;
            }
            else if (var[i] == '[') {                       // It is an array, need to calculate chars' values
                i++;
                arr_sum = 0;
                while (var[i] != ']') {
                    arr_sum *= 10;                          // Multiply by 10 if there is another char in line
                    arr_sum += (var[i] - 48);               // Calculate char's value by its ASCII code
                    i++;
                }
                i++;
                byte_size = base_size * arr_sum;            // Multiply base_size with the size of the array
                continue;
            }
            fprintf(file, "%c", var[i]);                    // Write char to file
            i++;
        }
        fprintf(file, " requires %d bytes\n", byte_size);   // Write the ammount of bytes required
        byte_size = base_size;
        var = strtok(NULL, ",");                            // Save pointer to start of string up to the next comma
    }
    fclose(file);                                           // Close file
}

int print_file(char *filename) {
    char c;
    FILE *fptr;
    fptr = fopen(filename, "r");                            // Open file
    if (!fptr) {
        printf("ERROR: failed to open file.\n");
        return 0;
    }
    c = fgetc(fptr);                                        // Read contents from file
    while (c != EOF) {
        printf ("%c", c);
        c = fgetc(fptr);
    }
    fclose(fptr);
    return 1;
}

int main() {
    int func;
    printf("Please enter question number (1-5)\nOr press '6' to run all excersises one by one: \n");
    scanf("%d", &func);
    flushall();
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
            break;
        default:
            break;
    }
    return 0;
}
