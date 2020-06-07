#include <stdio.h>
#include "../../src/input_sudoku.c"

/*
* TITLE      : input_sudoku_test.c 
*
* Purpose   : Generates a pre-defined sudoku templete
*
* Language  : C
*
* Author    : Rishith Rao, 
* GitHub ID : rishithrao57 
* Date      : 7 June 2020
*
**/

int main(){
int diff_level,no_sudoku;

input_sudoku(&diff_level, &no_sudoku);
printf("Difficulty Level: %d\nNo of Sudokus: %d\n",diff_level,no_sudoku);
}
