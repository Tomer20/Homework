//
//  Queue_ex.c
//  MivNet1
//
//  Created by Tomer Cohen on 11/08/2017.
//  Copyright © 2017 Tomer Cohen. All rights reserved.
//

#include <stdio.h>
#include "Queue_arr.h"
#include "Queue_ex.h"

int even_queue (queue *qt) {
    queue tmp, tmp2;
    create_queue(&tmp);
    create_queue(&tmp2);
    queue_type popped;
    
    while (!queue_is_empty(qt)) {
        dequeue(qt, &popped);
        if (popped%2 == 0)
            enqueue(popped, &tmp2);
        else
            enqueue(popped, &tmp);
    }
    
    while (!queue_is_empty(&tmp)) {
        dequeue(&tmp, &popped);
        enqueue(popped, qt);
    }

    while (!queue_is_empty(&tmp2)) {
        dequeue(&tmp2, &popped);
        enqueue(popped, qt);
    }

    return 0;
}


int minimal_int (queue *qt1, queue *qt2) {
    queue_type popped1, popped2;
    while (!queue_is_empty(qt1) || !queue_is_empty(qt2)) {
        dequeue(qt1, &popped1);
        
    }
    return -1;
}
