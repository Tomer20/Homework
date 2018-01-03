//
//  IsPalindrom.c
//  MivNet1
//
//  Created by Tomer Cohen on 11/08/2017.
//  Copyright © 2017 Tomer Cohen. All rights reserved.
//

#include <stdio.h>
#include "Stack_arr.h"

void is_palindrom (char str[]) {
    int i = 0, flag = 1;                    // flag is set to true
    char current;
    stack stk;
    create_stack(&stk);
    
    while (str[i] != '\0') {
        push(str[i], &stk);
        i++;
    }
    
    while (!stack_is_empty(&stk) && flag) {
        pop(&stk, &current);
        if (str[i-1] != current)            // Need to use [i-1] because index is starting on the end of string '\0'
            flag = 0;
        i--;                                // Check string from end to start
    }
    
    if (flag)
        printf("Oh fuck it's a palindrom\n");
    else
        printf("String is not palidrom, Jesus christ\n");
}
