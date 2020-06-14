/**
* @file sudoku_base.c 
*
* Purpose   : This is the main function to generate the sudoku puzzle and solution.
*
* Language  : C
*
* GitHub link : https://github.com/Prasanthkota165/Group_H_SUDOKU-GENERATOR
*
* Author    : Group H, Prasanth Kota 
*		       Mathieu Falardeau
*		       Rishith Rao
*		       Gabriel Seyoum
*		       
* Date      : 5 June 2020
*
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../include/sudoku.h"

int main(void){
    int no_sudoku, diff_level;
    int sudoku_template[ROWS][COLS];
    int rearranged_sudoku[ROWS][COLS];
    _Bool tester;
    int masked_sudoku[ROWS][COLS];
    int sudoku_solution [ROWS][COLS];

    /* Input the difficulty level and number of sudoku needed */
    input_sudoku(&diff_level,&no_sudoku);
    
    for (int i = 0; i < no_sudoku; i++){
        /* This function will generate the sudoku template */
        generate_sudoku_template(sudoku_template);

        /* Rearranging the sudoku template to generate different combinations 
        of sudoku */ 
        rearrange_cols_rows(sudoku_template, rearranged_sudoku);
        
        /*Tests the rearranged sudoku for sudoku rules*/
        tester=test_sudoku_rules(rearranged_sudoku);
     
        /* Masking the numbers on the rearranged sudoku template according 
        to the difficulty level provided */  
        apply_mask(rearranged_sudoku, diff_level, masked_sudoku);

        /* Finally, create the two .csv files (puzzle and solution) into the 
        output folder */
        output_sudoku(rearranged_sudoku, masked_sudoku, diff_level);
    }
    
    /*Final message of the program*/
    printf("Sudoku generator has finished creating all %d sudokus.\n", no_sudoku);
    return 0;
}

