#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#ifndef __MY_HEADER__
#define __MY_HEADER__
    #include "../../include/sudoku.h"
#endif

#define ROWS 9
#define COLS 9

/**
* @file apply_mask_test.c
*
* apply_mask_test
* ---------------
* This program tests the apply_mask.c function
* Language C
* Author Gabriel Seyoum, Group H member
* Date May 31, 2020
*/


int main(){
   FILE *fp;
   int masked_sudoku [9][9], diff_level [4] = {0, 1, 2, 3};
   int cells_tobe_masked, numbers_tobe_shown;
   int array_size = sizeof diff_level / sizeof *diff_level;
   srand(time(0));
   int rearranged_sudoku1 [9][9] = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
                                    {4, 5, 6, 7, 8, 9, 1, 2, 3},
                                    {7, 8, 9, 1, 2, 3, 4, 5, 6},
                                    {2, 3, 1, 5, 6, 4, 8, 9, 7},
                                    {5, 6, 4, 8, 9, 7, 2, 3, 1},
                                    {8, 9, 7, 2, 3, 1, 5, 6, 4},
                                    {3, 1, 2, 6, 4, 5, 9, 7, 8},
                                    {6, 4, 5, 9, 7, 8, 3, 1, 2},
                                    {9, 7, 8, 3, 1, 2, 6, 4, 5}};

    printf("\n*****apply_mask function test: test results are written to a log file (test/log/apply_mask_test_log.txt)*****\n");
    printf("\n");

    fp = fopen ("../log/apply_mask_test_log.txt", "w+");
    
    if (fp == NULL){
        printf("Could not open the file");
        _Exit(EXIT_FAILURE);
    }

    fprintf(fp, "%s", "POSTCONDITION: positive test cases and the expected outputs\n");
    fprintf(fp, "%s", "-----------------------------------------------------------\n");

    for(int i = 0; i < array_size; i++){
        cells_tobe_masked = 0;
        numbers_tobe_shown = 0;

        apply_mask(rearranged_sudoku1, diff_level [i], masked_sudoku);

        fprintf(fp, "%s %d", "\napply_mask function called for difficulty level:", diff_level [i]);
        fprintf(fp, "%s", "\n");
        fprintf(fp, "%s", "--------------------------------------------------\n");

        for(int k = 0; k < 9; k++){
            for(int m = 0; m < 9; m++){
                if(masked_sudoku[k][m] == 0){
                    cells_tobe_masked++;
                }
                else{
                    numbers_tobe_shown++;
                }

            fprintf(fp, "%d ", masked_sudoku[k][m]);
            }
            fprintf(fp, "%s", "\n");
        }
        fprintf(fp, "%s %d", "Number of cells masked:",  cells_tobe_masked);
        fprintf(fp, "%s %d", "\nNumbers shown on Sudoku game:", numbers_tobe_shown);
        fprintf(fp, "%s", "\n");
    }

    fprintf(fp, "%s", "\nPRECONDITION: negative test cases and the expected outputs\n");
    fprintf(fp, "%s", "----------------------------------------------------------\n");
    fprintf(fp, "%s", "The PRECONDITIONs were asserted at the function level and apply_mask function is designed to cover all cases. \n");
    fprintf(fp, "%s", "When an incorrect input values are passed the function, the function displays an Error Message to the screen and terminate.\n");

    fprintf(fp, "%s", "\n");
    fprintf(fp, "%s", "*****************The outcome of the test*****************\n");

    fprintf(fp, "%s", "The rearranged_sudoku array size not being 9x9,  testing with 4x9 array\n");
    /* The case where the rearranged_sudoku array size not being 9x9, in this case being 4x9 */
    int rearranged_sudoku2 [4][9] = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
                                     {4, 5, 6, 7, 8, 9, 1, 2, 3},
                                     {7, 8, 9, 1, 2, 3, 4, 5, 6},
                                     {2, 3, 1, 5, 6, 4, 8, 9, 7}};    /* apply_mask function being called with rearranged_sudoku array size 4x9 instead of 9x9 */

    apply_mask(rearranged_sudoku2, 1 , masked_sudoku);
    fprintf(fp, "%s", "The rearranged_sudoku array value(s) not being from 1 to 9\n");
    /* apply_mask function being called with rearranged_sudoku value not being 9x9, in this case row 9 and column 2 being 77 */
    int rearranged_sudoku3 [9][9] = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
                                     {4, 5, 6, 7, 8, 9, 1, 2, 3},
                                     {7, 8, 9, 1, 2, 3, 4, 5, 6},
                                     {2, 3, 1, 5, 6, 4, 8, 9, 7},
                                     {5, 6, 4, 8, 9, 7, 2, 3, 1},
                                     {8, 9, 7, 2, 3, 1, 5, 6, 4},
                                     {3, 1, 2, 6, 4, 5, 9, 7, 8},
                                     {6, 4, 5, 9, 7, 8, 3, 1, 2},
                                     {9, 77, 8, 3, 1, 2, 6, 4, 5}};    /* The case where the rearranged_sudoku array value(s) not being from 1 to 9 */

    fprintf(fp, "%s", "\n");
    fprintf(fp, "%s", "Error Message: The rearranged_sudoku array value(s), data type, or array size is incorrect.\n");
    apply_mask(rearranged_sudoku3, 2, masked_sudoku);

    fprintf(fp, "%s", "The diff_level value not being 0, 1, 2, or 3\n");
    apply_mask(rearranged_sudoku1, 7 , masked_sudoku);    /* The diff_level value not being 0, 1, 2, or 3 */
    apply_mask(rearranged_sudoku1, 'A' , masked_sudoku);  /* Incorrect diff_level data type */

    fclose(fp);
    return 0;
}

