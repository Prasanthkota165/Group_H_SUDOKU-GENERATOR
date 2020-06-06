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
#include <string.h>
#include <errno.h>

#define max_digits 4

/**
 * This function removes surplus characters or symbols from the input buffer.       
 */
static inline void clear_input_buffer(){

	char c = 0; 
	while ((c = getchar()) != '\n' && c != EOF); /*Loop over input buffer and consume chars until buffer is empty*/
}

/**
 * This function initially clears the input buffer and checks for restricted 
 * input values and returns only if the entered value is integer. 
 */
void get_integer_from_stdin(int *input_integer){

	char *input_buffer = malloc(sizeof(char) * max_digits);
	memset(input_buffer, 0, max_digits); /*Clears the input buffer initially.*/
	char *input = NULL;
	while (input == NULL){/*Here fgets returns inputBuffer on success.This becomes important when freeing - free either `input` or`inputBuffer` to avoid an attempted double-free error.*/
                input = fgets(input_buffer, max_digits, stdin); 
		if (input_buffer[strlen(input_buffer) - 1] != '\n') { /* prevents the program to generate seperate error messages for a string of characters. */
			printf("..............Invalid input.Please try again.......................\n");
			clear_input_buffer();
			input = NULL;
			continue;
		}
        errno = 0; /*Check that the input can be intepreted as an integer*/
        char *endptr = NULL;
        *input_integer = strtol(input, &endptr, 10); /*Convert to integer using `strtol()`*/
                if (input == endptr) { /* If an integer was not found, endptr remains set to input*/
			input[strcspn(input, "\n")] = 0; /*strcspn - this function gets the length of a prefix substring.*/
			printf("..............Invalid input.Please try again.......................\n");
			input = NULL;
		}
		if (errno != 0) {
			printf("..............Invalid input.Please try again........................\n");
			input = NULL;
		}
             
                
	}
	free(input_buffer);
}

 
/**
 * This functions asks the difficulty level and number of sudokus checks whether 
 * the meet the pre-defined conditions.
 */
void input_sudoku(int *diff_level,int *no_sudoku){ 

   printf("....................Welcome to Sudoku Generator......................\n\n");     
   int x;
   int y;
   puts("Enter difficulty level as(0,1,2 or 3):\nEasy:      0\nMedium:    1\nHard:      2\nVery Hard: 3");
	
   while(1){/*Checks for valid difficulty level and number of sudokus.*/
	get_integer_from_stdin(&x);
	if(x<=3&&x>=0) {/* Checks whether the difficulty level in in the specified range*/
                *diff_level=x;
                puts("..............................................................................\n");
                puts("Enter the number of sudokus you would like to print between 1 to 40:");
                get_integer_from_stdin(&y);
                if(y<=40&&y>=1){/* Checks whether the number of sudokus are in the specified range*/
                            *no_sudoku=y;
                            break;
                }
                else{
                            puts("................Invalid number of sudokus.Please try again...............");
                            puts("Enter the number of sudokus you would like to print between 1 to 40:");
                            continue;
                }
        }
        else {
                puts("....................Invalid input...........................\n");
                puts("Enter difficulty level as(0,1,2 or 3):\nEasy:      0\nMedium:    1\nHard:      2\nVery Hard: 3");
                 continue;
        }

   }
        printf("Difficulty level: %d\n",x);
        printf("Number of sudokus: %d\n",y);	
}




