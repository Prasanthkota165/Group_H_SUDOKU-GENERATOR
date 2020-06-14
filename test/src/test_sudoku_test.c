#include <stdio.h>
#include "../../src/test_sudoku.c"
#include "../../include/sudoku.h"

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


void main() {
    _Bool a;
    a=test_sudoku_rules(rearranged_sudoku);
    printf("Bool : %d\n",a);
    if (a==0) {
        printf("..........No Errors..........");
    }else {
        printf("...........There is an error..............");
     }
}
