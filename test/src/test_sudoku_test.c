#include <stdio.h>
#include "../../src/test_sudoku.c"
#include "../../include/sudoku.h"
#include "../../src/rearrange_cols_rows.c"

/**
 * @file test_sudoku_test.c
 *
 * Purpose  : This function tests whether the regenerated sudoku meets all the sudoku rules or not .
 *
 * Language : C
 *
 * Author   : Rishith Rao - rishithrao@cmail.carleton.ca
 *            Prasanth Kota - prasanthkota@cmail.carleton.ca
 *
 * Date     : 13 June, 2020.
 */


int main(void) {
    _Bool a;
    int sudoku_temp[9][9] = {{1,2,3,4,5,6,7,8,9},
		     {4,5,6,7,8,9,1,2,3},
		     {7,8,9,1,2,3,4,5,6},
		     {2,3,1,5,6,4,8,9,7},
		     {5,6,4,8,9,7,2,3,1},
		     {8,9,7,2,3,1,5,6,4},
		     {3,1,2,6,4,5,9,7,8},
		     {6,4,5,9,7,8,3,1,2},
		     {9,7,8,3,1,2,6,4,5}};
    int rearranged_sudoku[9][9];
    rearrange_cols_rows(sudoku_temp, rearranged_sudoku);
    a=test_sudoku_rules(rearranged_sudoku);
    printf("Bool : %d\n",a);
    if (a==0) {
        printf("..........No Errors..........\n");
    }else {
        printf("...........There is an error.............\n");
     }
}


