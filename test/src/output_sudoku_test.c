/*
* TITLE      : output_sudoku_test.c 
*
* Purpose   : Test the output_sudoku.c file functions
*
* Language  : C
*
* Author    : Mathieu Falardeau 101173923, 
* GitHub ID : Mathieufalardeau3 
* Date      : 30 May 2020
*
**/

#include "..\\..\\include\\sudoku.h"

#include <stdio.h>


int main(void){
    
    int difficulty = 3; 
    
    //Sudokus for testing
    int sudoku_puzzle[9][9] = {{1,0,3,4,5,6,7,8,9},
                                {2,3,0,5,6,7,8,9,1},
                                {3,4,5,6,0,8,9,1,2},
                                {4,5,6,7,8,9,1,0,3},
                                {5,0,7,0,9,1,2,3,4},
                                {6,7,8,9,1,0,3,0,5},
                                {7,8,0,1,2,3,4,5,6},
                                {8,0,1,2,0,4,5,6,7},
                                {9,1,0,3,0,5,0,7,8}};

    int sudoku_solution[9][9] = {{1,2,3,4,5,6,7,8,9},
                                {2,3,4,5,6,7,8,9,1},
                                {3,4,5,6,7,8,9,1,2},
                                {4,5,6,7,8,9,1,2,3},
                                {5,6,7,8,9,1,2,3,4},
                                {6,7,8,9,1,2,3,4,5},
                                {7,8,9,1,2,3,4,5,6},
                                {8,9,1,2,3,4,5,6,7},
                                {9,1,2,3,4,5,6,7,8}};
    
    scanf("%d",&difficulty); //Inputs the sudoku difficulty level

    //Generate multiple sudokus to test for future releases
    output_sudoku(sudoku_solution,sudoku_puzzle,difficulty);
    output_sudoku(sudoku_solution,sudoku_puzzle,difficulty);
    output_sudoku(sudoku_solution,sudoku_puzzle,difficulty);
    output_sudoku(sudoku_solution,sudoku_puzzle,difficulty);

    //End of the program
    printf("This is the end of the test. Press 0 to end the program.");
    scanf("%d",&difficulty);
    return 0;
}