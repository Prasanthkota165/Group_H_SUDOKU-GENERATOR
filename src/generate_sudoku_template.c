#include <stdio.h>
#include<stdlib.h>
#include "../include/sudoku.h"
/*
*File name: generate_sudoku_template.c
*
*Description: This function generates a sudoku template. 
*
*
*Author: Rishith Rao
*
*
**/


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
 /*	while(i!=9){
		while(j!=9){
			sudoku_temp[i][j]=a[i][j];
			j++;
		}
		j=0;
		i++;
	}	*/ 
}
