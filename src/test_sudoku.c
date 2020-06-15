/**
 * @file test_sudoku.c
 *
 * Purpose  : This function tests whether the regenerated sudoku meets all the sudoku rules or not .
 *
 * Language : C
 *
 * Author   : Rishith Rao - rishithrao@cmail.carleton.ca
 *            Prasanth Kota - prasanthkota@cmail.carleton.ca
 *
 * Date     : 14 June, 2020.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/sudoku.h"

/**
 * This function checks the rows, columns and 3X3 matrix for sudoku rules.
 */

_Bool test_sudoku_rules(int rearranged_sudoku[][9]){  
  _Bool x,y,z; 
  int a[9]; /* Initialize array to copy the values 1 to 9 */
  int i;
  for(i=1;i<=9;i++){
	a[i-1] = i; /* Copying the values from 1 to 9 */
  }
  x= test_rows(rearranged_sudoku,a); /*Checks for any repeated values in the rows*/
  y= test_cols(rearranged_sudoku,a); /*Checks for any repeated values in the columns*/
  z= test_3X3(rearranged_sudoku,a); /*Checks for any repeated values in the 3X3 matrices*/
  if(x&&y||y&&z||z&&x){
  	return true;
  }
  else {
	return false;
  }
}

/* for rows */
_Bool test_rows(int rearranged_sudoku[][9], int a[9]){
   int i,j,sum=0,check_1;
   int flag=0;      
   int p;
   for (i=0;i<9;i++) {
	for (j=0;j<9;j++) { 
		check_1=rearranged_sudoku[i][j];/*Copy each element of row to check*/
		sum=sum+check_1; /* summing all the elements in the row to get 45 */
		delete_1(check_1,a); 
	}
    	for(p=0;p<9;p++){
	 	if(a[p]!=0 || sum!=45){ /* If the array is not empty or
					   sum is not 45 then test failed*/
			flag++;/*Increment flag with no. of times the sudoku rules failed*/
		}
  	 }
   	sum=0;
   	for(p=1;p<=9;p++){
		a[p-1] = p;
  	 }   
   } 
 return flag; /*positive values are treated as '1' in _Bool*/
}

/*for columns*/
_Bool test_cols(int rearranged_sudoku[][9], int a[9]){
   int i,j,sum=0,check_2;
   int flag=0;      
   int p;
   for (i=0;i<9;i++) {
	for (j=0;j<9;j++) {
		check_2=rearranged_sudoku[j][i];/*Copy each element of column to check*/
		sum=sum+check_2; /* summing all the elements in the column to get 45 */
		delete_1(check_2,a);
	}
    	for(p=0;p<9;p++){
	 	if(a[p]!=0 || sum!=45){ /* If the array is not empty or
					   sum is not 45 then test failed*/
			flag++;/*Increment flag with no. of times the sudoku rules failed*/
		}
  	 }
   	sum=0;
   	for(p=1;p<=9;p++){
		a[p-1] = p; /* Load the array again with the values from 1 to 9 */
  	 }   
   } 
 return flag; /*positive values are treated as '1' in _Bool*/
}

/*for 3X3 blocks*/
_Bool test_3X3(int rearranged_sudoku[][9], int a[9]) {  
    int x=0,y=2,k=0,l=2,i,j,sum=0,check_3;
    int flag=0;
    int p;
    while(x<=8) {
        while(k<=8) {
            for (int i=x;i<=y;i++) {
                for(int j=k;j<=l;j++) {
   		    check_3=rearranged_sudoku[i][j];/*Copy each element of 3X3 matrix to check*/
   		    sum=sum+check_3; /* summing all the elements in the 3X3 matrix to get 45 */
                    delete_1(check_3,a);
                }
            }
            k=k+3;
            l=l+3;
            for(p=0;p<9;p++){
	 	if(a[p]!=0 || sum!=45){ /* If the array is not empty or
					   sum is not 45 then test failed*/
			flag++;/*Increment flag with no. of times the sudoku rules failed*/
		}
            }  
            sum=0;
    	    for(p=1;p<=9;p++){
		a[p-1] = p; /* Load the array again with the values from 1 to 9 */
            }
        }
        k=0;
        l=2;
        x=x+3;
        y=y+3;
    }
    return flag;/*positive values are treated as '1' in _Bool*/
}


/* Mask the unrepeated elements in row/column/3x3 block and leave the array with elements
 * that has to be appeared in the place of repeated values.
 */
void delete_1(int check, int a[9]){
  int k;
  for(k=0;k<9;k++){ 
   	if(check==a[k]){  /*check the element is in the array*/
    		 a[k] = 0; 
  	} 
  }
}



