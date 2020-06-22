
/**
 * @file test_sudoku_test.c
 *
 * Purpose  : This function tests whether the regenerated sudoku meets all the 
 *              sudoku rules or not .
 *
 * Language : C
 *
 * Author   : Rishith Rao - rishithrao@cmail.carleton.ca
 *            Prasanth Kota - prasanthkota@cmail.carleton.ca
 *
 * Date     : 20 June, 2020.
 */
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<errno.h>
#include "../../include/sudoku.h"
#include "../include/test_sudoku_test.h"
#include "../../src/rearrange_cols_rows.c"
#include "../../src/generate_sudoku_template.c"


int main(){
    int sudoku_temp[9][9],i,j;
    int rearranged_sudoku[9][9]; 
    generate_sudoku_template(sudoku_temp);
    char* log_location = "../log/test_sudoku_test.log"; /*Define the path*/
    FILE *log = fopen(log_location, "w"); /*Write access to the log file */
    rearrange_cols_rows(sudoku_temp,rearranged_sudoku);
    fprintf(log,"       TEST SUDOKU TESTING RESULT\n"
		"--------------------------------------------\n");
    srand(time(0));
    fprintf(log,"         REARRANGED SUDOKU:\n");
    for(i=0;i<9;i++){ /* checking for same numbers */
       	for(j=0;j<9;j++){
	        fprintf(log,"  %d ", rearranged_sudoku[i][j]);	
	    }
	    fprintf(log,"\n");
    }
    if(main_test(sudoku_temp,rearranged_sudoku)){ /* Testing for any errors in 
                                                    rows, columns and 3X3*/
    	fputs("Test 1:All rows,columns and 3X3 contains 1 to 9 numbers and\n"
               "sum equals 45. Sudoku met all the rules.\n",log);
    } else {
      	fputs("Test 1: Rows, columns or 3X3 doesn't have all 9 numbers and\n"
              "sum doesn't equal 45. Sudoku didn't meet all the rules.\n",log);
    }
    if(testing_rows(sudoku_temp,rearranged_sudoku)){ /* Testing for errors in rows*/
       	fputs("Test 2:All the rows contains 1 to 9 numbers and sum equals 45.\n"
               "Sudoku met all the rules for rows\n",log);
    } else {
    	fputs("Test 2:Some of the rows doesn't have all 9 numbers or\n"
               "sum doesn't equal 45. Sudoku didn't meet all the rules for rows.\n",log);
    }
    if(testing_cols(sudoku_temp,rearranged_sudoku)){ /* Testing for errors in columns*/
        fputs("Test 3:All the columns contains 1 to 9 numbers and sum equals 45.\n"
              "Sudoku met all the rules for columns.\n",log);
    } else {
    	fputs("Test 3:Some of the columns doesn't have all 9 numbers or\n"
               "sum doesn't equal 45. Sudoku didn't meet all the rules for columns\n",log);
    }
    if(testing_3X3(sudoku_temp,rearranged_sudoku)){ /* Testing for errors in 3X3 matrix*/
    	fputs("Test 4:All the 3X3 matrices contains 1 to 9 numbers and sum equals 45.\n"
               "Sudoku Met all the rules for 3X3 matrix.\n",log);
    } else {
    	fputs("Test 4:Some of the 3X3 matrix doesn't have all 9 numbers or\n"
               "sum doesn't equal 45. Sudoku didn't meet all the rules for 3X3 matrix\n",log);
    }
    fputs("-----------------------------------------------\n",log);
    fclose(log);
    return 0;
}

/**
 * This function tests for any errors in 3X3 and returns a bool value.
 */
_Bool testing_3X3(int sudoku_temp[9][9],int rearranged_sudoku[9][9]) {
    char* log_location = "../log/test_sudoku_test.log"; /*Define the path*/
    FILE *log = fopen(log_location, "a"); /*Appends access to the log file*/
    _Bool b;
    int a[9];
    int i,j;
    for(i=1;i<=9;i++){
       	a[i-1] = i; /* Copying the values from 1 to 9 */
    }
    b=test_3X3(rearranged_sudoku,a);
    if (b==0) {
        fprintf(log,"             Test 4 'PASSED'            \n"
                     "..........No Errors in 3X3 matrix..........\n\n");
        return true;
    } else {
        fprintf(log,"             Test 4 'FAILED'                          \n"
                    ".......There is an error in 3X3...........\n\n");
        return false;
    }
}

/**
 * This function tests for any errors in columns and returns a bool value.
 */
_Bool testing_cols(int sudoku_temp[9][9],int rearranged_sudoku[9][9]) {
    char* log_location = "../log/test_sudoku_test.log"; /*Define the path*/
    FILE *log = fopen(log_location, "a"); /*Appends access to the log file*/
    _Bool b;
    int a[9];
    int i,j;
    for(i=1;i<=9;i++){
       	a[i-1] = i; /* Copying the values from 1 to 9 */
    }
    b=test_cols(rearranged_sudoku,a);
    if (b==0) {
        fprintf(log,"             Test 3 'PASSED'            \n"
                     "..........No Errors in columns..........\n\n");
        return true;
    } else {
        fprintf(log,"               Test 3 'FAILED'                          \n"
                    ".......There is an error in columns.........\n\n");
        return false;
    }
}

/**
 * This function tests for any errors in columns and returns a bool value.
 */ 
_Bool testing_rows(int sudoku_temp[9][9],int rearranged_sudoku[9][9]) {
    char* log_location = "../log/test_sudoku_test.log"; /*Define the path*/
    FILE *log = fopen(log_location, "a"); /*Appends access to the log file*/
    _Bool b;
    int a[9];
    int i,j;
    for(i=1;i<=9;i++){
       	a[i-1] = i; /* Copying the values from 1 to 9 */
    }
    b = test_rows(rearranged_sudoku,a);
    if (b==0) {
        fprintf(log,"             Test 2 'PASSED'            \n"
                     "..........No Errors over all..........\n\n");
        return true;
    } else {
        fprintf(log,"             Test 2 'FAILED'                          \n"
                    ".......There is an error in rows3X3.........\n\n");
        return false;
    }
}

/**
 * This function tests for any errors in rows,columns and 3X3 matrix and returns a bool value.
 */
_Bool main_test(int sudoku_temp[9][9],int rearranged_sudoku[9][9]) {
    _Bool a;
    char* log_location = "../log/test_sudoku_test.log"; /*Define the path*/
    FILE *log = fopen(log_location, "a"); /*Appends access to the log file*/
    rearrange_cols_rows(sudoku_temp, rearranged_sudoku);
    a=test_sudoku_rules(rearranged_sudoku);
    if (a==0) {
        fprintf(log,"             Test 1 'PASSED'            \n"
                     "..........No Errors over all..........\n\n");
        return true;
    } else {
        fprintf(log,"                  Test 1 'FAILED'                          \n"
                    ".......There is an error in rows, columns or 3X3 matrix.........\n\n");
        return false;
    }
}
