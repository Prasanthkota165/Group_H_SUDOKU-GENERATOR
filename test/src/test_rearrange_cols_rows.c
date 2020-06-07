/**
 * @file test_rearrange_cols_rows.c
 *
 * Purpose   : This function is used to test the rearrange_cols_rows.c function
 *
 * Language  : C
 * 
 * Author    : Prasanth Kota - prasanthkota@cmail.carleton.ca 
 *
 * Date      : 3 June, 2020.
 */

#include<stdio.h>
#include<stdlib.h>

#include "../../src/rearrange_cols_rows.c"
#include "../../include/sudoku.h"

int main(void){
  int sudoku_temp[9][9] = {{1,2,3,4,5,6,7,8,9},
		     {4,5,6,7,8,9,1,2,3},
		     {7,8,9,1,2,3,4,5,6},
		     {2,3,1,5,6,4,8,9,7},
		     {5,6,4,8,9,7,2,3,1},
		     {8,9,7,2,3,1,5,6,4},
		     {3,1,2,6,4,5,9,7,8},
		     {6,4,5,9,7,8,3,1,2},
		     {9,7,8,3,1,2,6,4,5}};
  int rearranged_sudoku_temp[9][9];
  rearrange_cols_rows(sudoku_temp, rearranged_sudoku_temp);
  int i,j;
  for (i=0;i<9;i++){
 	for (j=0;j<9;j++){
		printf("%d ",sudoku_temp[i][j]);
	}
	printf("\n");
  }
  printf("\nRearranged Sudoku template: \n");
  for (i=0;i<9;i++){
 	for (j=0;j<9;j++){
		printf("%d ",rearranged_sudoku_temp[i][j]);
	}
	printf("\n");
  }
 
 return 0;
}
