/**
* @file solver_sudoku.c 
*
* Purpose   : Contains the functions to to determine if a Sudoku puzzle 
*               is solvable.
*
* Language  : C
*
* Author    : Mathieu Falardeau 101173923,  
* GitHub ID : Mathieufalardeau3 
* Date      : 06 June 2020
*
*/
#if defined(_WIN32)||defined (WIN32) //<Define if Microsoft OS                           
#include "..\\include\\sudoku.h"
#else //Define if Linux OS*/ 
#include "../include/sudoku.h"
#endif

#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0 /*A constant for empty spaces in a Sudoku puzzle*/
#define TRUE 1 /*A constant for _Bool*/
#define FALSE 0 /*A constant for _Bool*/
#define N 9 /*A constant for the basic size of a Sudoku*/

/**
 * Determines if the sudoku puzzle is solvable. 
 * 
 * @param[in] sudoku_puzzle[N][N] The Sudoku puzzle to be verified.
 * @param[out] temp_sudoku[N][N] The Sudoku puzzle to be verified.
 * 
 * @return TRUE if it is solvable, FASLE if it is not.  
 */
_Bool solver_sudoku(int sudoku_puzzle [N][N], int temp_sudoku[N][N]){

    /*Variables*/ 
    int col, row; 
    
    /*Copies the data from the sudoku_puzzle parameter into the temporary 
    sudoku.*/
    for (row=0; row<N; row++){
        for(col=0; col<N; col++){
            temp_sudoku[row][col] = sudoku_puzzle[row][col];
        }
    }
    /*Determines if the sudoku puzzle is solvable.*/
    if (!apply_solver(temp_sudoku)){ 
        printf("No solution exists for this puzzle."); 
        return FALSE;
    } 
    return TRUE;
}

/**
 * Recursive function that applies the main mechanic to solve the Sudoku 
 * puzzle. 
 * 
 * @param[in] sudoku_puzzle[N][N] A partially solved Sudoku puzzle.
 * 
 * @return TRUE if the Sudoku Puzzle has been solved, FALSE if it 
 */

_Bool apply_solver(int sudoku_puzzle [N][N]){ 
    
    /*Variables*/
    int row, col; 
    int slot[2];
    
    /* If there is no EMPTY slots left, then the sudoku puzzle has been 
    solved*/
    if (!find_next_empty(sudoku_puzzle,slot)){ 
        return TRUE; 
    }
    
    /*Assigns the location of the EMPTY slot to the variables*/
	row = slot[0];
	col = slot[1];
	
    /* Verifies numbers 1 to 9 at the EMPTY slot*/
    for (int num = 1; num <= 9; num++) { 
        /*Checks if their is a conflict with the number at the EMPTY slot.*/
        if (no_conflict(sudoku_puzzle, row, col, num)) { 
            /*Assigns the number to the EMPTY slot temporarily.*/
            sudoku_puzzle[row][col] = num; 
  
            /*Continues to solve the Sudoku Puzzle, but with the EMPTY slot 
            filled with the assigned number.*/ 
            if (apply_solver(sudoku_puzzle)){ 
                return TRUE; /*If an apply_solver() instance returns TRUE, then 
                                a chain reaction will begin with all parent 
                                apply_solver() returning also TRUE */
            }
            /*If the above apply_solver() instance returns FALSE, then the 
            number is incorect and the slot is restored as EMPTY.*/
            sudoku_puzzle[row][col] = EMPTY; 
        } 
    } 
    /* Backtracks the process if all numbers attempts in the EMPTY slot causes 
    a conflict.*/ 
    return FALSE; 
} 
  
/** 
 * A part of the main function to finds the next empty slot in a Sudoku Puzzle.
 * 
 * @param[in] sudoku_puzzle[N][N] The Sudoku Puzzle to check for EMPTY slots.
 * @param[out] slot[2] An array to store the location of the EMPTY slot.
 * 
 * @return TRUE if an EMPTY slot is found, FALSE if not.
 * 
 */
_Bool find_next_empty(int sudoku_puzzle[N][N], int slot[2]){ 
    /*Searches the Sudoku Puzzle for en EMPTY slot*/
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            if (sudoku_puzzle[row][col] == EMPTY){ 
                /*Assigns the location of the EMPTY slot*/
                slot[0] = row;
                slot[1] = col;
                return TRUE; 
            }
        }
    }
    return FALSE; 
} 
/**
 * Checks if there is a confict in either the row, column or box at a slots 
 * location (row, col).
 * 
 * @param[in] sudoku_puzzle[9][9] The Sudoku Puzzle to check for a conflict.
 * @param[in] row The row of the location to check for conflict.
 * @param[in] col The column of the location to check for conflict.
 * @param[in] num The number that needs to be verified for conflict.
 * 
 * @return Returns TRUE if the location is free to place the number, FALSE if 
 *          it will create a conflict.
 */
_Bool no_conflict(int sudoku_puzzle[N][N], int row, int col, int num){ 
    /*Checks if the number is already placed in the row of the location*/
    _Bool free_row = !used_in_row(sudoku_puzzle, row, num);
    /*Checks if the number is already placed in the column of the location*/
    _Bool free_col = !used_in_col(sudoku_puzzle, col, num);
    /*Checks if the number is already placed in the box of the location*/
    _Bool free_box = !used_in_box(sudoku_puzzle, row, col , num);
    
    /*Returns the availability of the location in accordance with the nummber*/
    return free_row && free_col && free_box && (sudoku_puzzle[row][col] == EMPTY);
} 
  
/**
 * Checks if the row already has the requested number.
 * 
 * @param[in] sudoku_puzzle[9][9] The Sudoku Puzzle to check in.
 * @param[in] row The row to verify if the number is already there.
 * @param[in] num The number that needs to be verified.
 * 
 * @return Returns TRUE if the row has the number already there, FALSE if 
 *          not.
 */
_Bool used_in_row( int sudoku_puzzle[N][N], int row, int num){ 
    /*Checks each column in the row*/
    for (int col = 0; col < N; col++){ 
        if (sudoku_puzzle[row][col] == num){ 
            return TRUE; 
        }
    }
    return FALSE; 
} 
  
/**
 * Checks if the column already has the requested number.
 * 
 * @param[in] sudoku_puzzle[9][9] The Sudoku Puzzle to check in.
 * @param[in] col The column to verify if the number is already there.
 * @param[in] num The number that needs to be verified.
 * 
 * @return Returns TRUE if the column has the number already there, FALSE if 
 *          not.
 */
_Bool used_in_col(int sudoku_puzzle[N][N], int col, int num){ 
    /*Checks each row in the column*/
    for (int row = 0; row < N; row++){
        if (sudoku_puzzle[row][col] == num){
            return TRUE; 
        }
    }
    return FALSE; 
} 
  
/**
 * Checks if the 3x3 box of the current location already contains the requested 
 * number.
 * 
 * @param[in] sudoku_puzzle[9][9] The Sudoku Puzzle to check in.
 * @param[in] row The row of the current location.
 * @param[in] col The column of the current location.
 * @param[in] num The number that needs to be verified.
 * 
 * @return Returns TRUE if the box has the number already there, FALSE if 
 *          not.
 */
_Bool used_in_box(int sudoku_puzzle[N][N], int row, int col, int num){ 
    
    /*Variables*/
    int start_row = (row/3)*3;/*Determines which row the box begins at*/ 
    int start_col = (col/3)*3;/*Determines which row the box begins at*/
    
    /*Check every slot in the box*/
    for (int i = 0; i < 3; i++){ 
        for (int j = 0; j < 3; j++){ 
            if (sudoku_puzzle[i + start_row][j + start_col] == num){ 
                return TRUE;
            }
        }
    } 
    return FALSE; 
} 
  

  
