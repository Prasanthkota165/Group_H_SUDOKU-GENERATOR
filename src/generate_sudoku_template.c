/**
 * @file generate_sudoku_templete.c
 *
 * Purpose  : This function generates a pre-defined sudoku template.
 *
 * Language : C
 *
 * Author   : Rishith Rao - rishithrao@cmail.carleton.ca
 *
 * Date     : 4 June, 2020.
 */

#include <stdio.h>
#include<stdlib.h>
#include "../include/sudoku.h"

/**
 * This fnction generates the sudoku templete of size 9X9.      
 */
void generate_sudoku_template(int sudoku_temp [9][9]){
    int i,j;
    int a[9][9]= {{1,2,3,4,5,6,7,8,9}, 
	   		{4,5,6,7,8,9,1,2,3},
	   		{7,8,9,1,2,3,4,5,6},
	   		{2,3,1,5,6,4,8,9,7},
	   		{5,6,4,8,9,7,2,3,1},
	   		{8,9,7,2,3,1,5,6,4},
	   		{3,1,2,6,4,5,9,7,8},
    		        {6,4,5,9,7,8,3,1,2},
	   		{9,7,8,3,1,2,6,4,5}};
    for(i =0;i<9;i++){
        for(j =0;j<9;j++){
            sudoku_temp[i][j]=a[i][j];
	}
    }
 
}
