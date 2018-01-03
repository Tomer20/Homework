/*
Assigned by:
Yoni Saida 
Tomer Cohen 

File Name: main.c
The program is initiating telemarketing customer menu.
*/

#include <stdio.h>

void main()
{
    // Variables
	int menu_range, position_count=0, finish_flag=0;
	char ans_case_3;
	
    // Main loop
	while (finish_flag==0){
		printf("Please enter number in the range 1-5\n");
		scanf("%d", &menu_range);
        position_count++;               // main menu repetition counter
        switch(menu_range){
            case 1:                     // return to customer menu
                printf("Disconnecting...\n");
                break;
            case 2:                     // return to customer menu
                break;
            case 3:                     // return to customer menu - if answer is not Y/y
                flushall();
                printf("Are you sure you would like to cancel your order???\nPlease enter one char:\n");
                scanf(" %c",&ans_case_3);
                if (ans_case_3 == 'y' || ans_case_3 == 'Y'){
                    printf("Canceled\n");
                    finish_flag=1;      // exit the program
                }
                break;
            case 4:                     // return to customer menu
                printf("Your position in queue is %d\n", position_count);
                break;
            case 5:                     // exit the program
                finish_flag=1;
                break;
            default:                    // return to customer menu
                printf("Wrong input.\n");
                break;
        }
    }
}
