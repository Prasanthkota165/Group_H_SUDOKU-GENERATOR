/*
* TITLE      : input_sudoku_test.c 
*
* Purpose   : Tests the input_sudoku.c function
*
* Language  : C
*
* Author    : Rishith Rao, 
* GitHub ID : rishithrao57 
* Date      : 21 June 2020
*
**/

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<errno.h>
#include "../../include/sudoku.h"
_Bool input_sudoku_test(float a, float b,FILE *log);
int main(float a,float b){

FILE *log = fopen ("../log/input_sudoku_test.log", "w+");
    srand(time(0));
    fprintf(log,"................................Testing for input_sudoku.c.......................\n\n");
    fprintf(log,"...................Test function for integer values.................\n");     
    a=2;
    b=3;
    fprintf(log,"Input Parameters:\n  Difficulty level= 2, Number of sudokus= 3\n");
    fprintf(log, "Expected output: \n  Difficulty level= 2, Number of sudokus= 3\n");
    input_sudoku_test(a,b,log);
    
    fprintf(log,"...................Test function for float values.................\n");     
    a=2.5;
    b=3.5;
    fprintf(log,"Input Parameters:\n  Difficulty level= 2.5, Number of sudokus=3.5\n");
    fprintf(log, "Expected output: \n  Invalid difficulty level\n  Invalid number of sudokus\n");
    input_sudoku_test(a,b,log);

    fprintf(log,"...................Test function for characters.................\n");     
    char c='c';
    char d='d';
    fprintf(log,"Input Parameters:\n  Difficulty level= 'c', Number of sudokus= 'd'\n");
    fprintf(log, "Expected output: \n  Invalid difficulty level\n  Invalid number of sudokus\n");
    input_sudoku_test(c,d,log);

    fprintf(log,"...................Test function for symbols.................\n");     
    char e='$';
    char f=':';
    fprintf(log,"Input Parameters:\n  Difficulty level= '$', No of sudokus= '$'\n");
    fprintf(log, "Expected output: \n  Invalid difficulty level\n  Invalid number of sudokus\n");
    input_sudoku_test(e,f,log);

    
    fclose(log);
    return 0;
}

/**
 * This functions asks the difficulty level and number of sudokus from the user and checks whether 
 * they meet the pre-defined conditions and range. It also tracks the incorrect attempts made
 * by the user and exits the program if the maximum allowed attempts are reached. 
 */
_Bool input_sudoku_test(float a,float b,FILE *log){ 
    int x;
    int y;
    fprintf(log,"Actual Output:\n");
    while(1) {/*Asks the user for difficulty level.*/ 
        x=a;
        
        if(x<=3&&x>=0&&x==a) {/* Checks whether the difficulty level is in the specified range*/
            
            fprintf(log, "  Difficulty level= %d ",x);
            break;
        }else {/*If difficulty level is not in the specified range*/
             
             fputs("  Invalid difficulty level\n",log);
             break;
         }
   
    }
    
    
    while(1) {/*Asks the user for number of sudokus.*/
        
        y=b;
        if(y<=40&&y>=1&&y==b) {/* Checks whether the number of sudokus are in the specified range*/
            fprintf(log," Number of sudokus= %d \n\n",y);
            break;
            
        }else {/*If number of sudokus are not in the specified range*/
              fputs("  Invalid number of sudokus\n",log);
              break;
              
        }
    }   	
}
