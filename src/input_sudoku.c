/**
 * @file input_sudoku.c
 *
 * Purpose  : This function askes the user for the difficulty level and number of 
 *            sudokus that the user wants to generate.
 *
 * Language : C
 *
 * Author   : Rishith Rao - rishithrao@cmail.carleton.ca
 *
 * Date     : 4 June, 2020.
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * This function removes surplus characters or symbols from the input buffer.       
 */
static inline void clear_input_buffer(){
    char c = 0; 
    while ((c = getchar()) != '\n' && c != EOF); /*Loop over input buffer and consume chars until buffer is empty*/
}
/**
 * This functions asks the difficulty level and number of sudokus from the user and checks whether 
 * they meet the pre-defined conditions and range. It also tracks the incorrect attempts made
 * by the user and exits the program if the maximum allowed attempts are reached. 
 */
void input_sudoku(int *diff_level,int *no_sudoku){ 
    printf("....................Welcome to Sudoku Generator......................\n\n");     
    int x;
    int y;
    float a;
    float b;
    int i=5;
    int j=5;
    while(i!=0) {/*Asks the user for difficulty level.*/
        printf("Enter difficulty level as(0,1,2 or 3):\nEasy:      0\nMedium:    1\nHard:      2\nVery Hard: 3\n->");
	scanf("%f",&a);
        x=a;
        if(x<=3&&x>=0&&x==a) {/* Checks whether the difficulty level is in the specified range*/
            *diff_level=x;
            printf("..............................................................................\n");
            break;
        }else {/*If difficulty level is not in the specified range*/
             clear_input_buffer();/*Clear the elements in the input buffer.*/  
             printf("....................Invalid input. %d attempts remaining........................\n",i-1);
         }
        i--; 
    }
    if (i==0) { /* If the user exceeds the inputs limit, this loop will execute to terminate the program*/
         printf("\n....................YOU HAVE REACHED MAXIMUM ATTEMPTS...............\n");               
         exit(0);
    }
    while(j!=0) {/*Asks the user for number of sudokus.*/
        printf("Enter the number of sudokus you would like to print between 1 to 40:\n->");
        scanf("%f",&b);
        y=b;
        if(y<=40&&y>=1&&y==b) {/* Checks whether the number of sudokus are in the specified range*/
            *no_sudoku=y;
            break;
        }else {/*If number of sudokus are not in the specified range*/
              clear_input_buffer();/*Clear the elements in the input buffer.*/ 
              printf("................Invalid input. %d attempts remaining...............\n",j-1);
         }
        j--;
    }
    if (j==0) {/* If the user exceeds the inputs limit, this loop will execute to terminate the program*/
       printf("\n....................YOU HAVE REACHED MAXIMUM ATTEMPTS...............\n");
       exit(0);
    }
    printf("Difficulty level: %d\n",x);
    printf("Number of sudokus: %d\n",y);	
}
