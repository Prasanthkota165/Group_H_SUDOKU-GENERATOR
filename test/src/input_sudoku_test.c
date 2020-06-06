#include <stdio.h>
#include "../../src/input_sudoku.c"

int main(){
int diff_level,no_sudoku;

input_sudoku(&diff_level, &no_sudoku);
printf("Difficulty Level: %d\nNo of Sudokus: %d\n",diff_level,no_sudoku);
}
