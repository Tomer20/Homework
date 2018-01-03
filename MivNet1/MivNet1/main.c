//
//  main.c
//  MivNet1
//
//  Created by Tomer Cohen on 04/08/2017.
//  Copyright © 2017 Tomer Cohen. All rights reserved.
//

#include <stdio.h>
#include "Stack_arr.h"
#include "Queue_arr.h"
#include "Queue_ex.h"


# define N 6

int main(int argc, const char * argv[]) {
    int i;
    queue_type out;
    queue qt;
    create_queue(&qt);
    
    for (i=1; i<=N; i++)
        enqueue(i, &qt);
    
    printf("Init:\n");
    for (i=1; i<=N; i++) {
        dequeue(&qt, &out);
        printf("%d ", out);
    }

    even_queue(&qt);
    
    printf("After:\n");
    for (i=1; i<=N; i++) {
        dequeue(&qt, &out);
        printf("%d ", out);
    }
    
    return 0;
}
