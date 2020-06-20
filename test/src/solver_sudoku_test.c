/**
* @file solver_sudoku_test.c
*
* Purpose   : Contains the functions that tests the Sudoku solver
*
* Language  : C
*
* Author    : Mathieu Falardeau 101173923
	      Gabriel Seyoum 100333091
* GitHub ID : Mathieufalardeau3, gabriels2018
* Date      : 06 June 2020
*
*/

#include <stdio.h>
#include <stdlib.h>

#ifndef __MY_HEADER__
#define __MY_HEADER__
   #include "../../include/sudoku.h"
#endif

//#include "../../src/solver_sudoku.c"
 
#define ROWS 9
#define COLS 9

/**
* This function sorts the 3x3 values and test them if they pass the Sudoku rules
* @param[in] tester[ROWS] contains either the row, columns or the 3x3 solver output values.
* @param[out] _Bool is used to check if there are duplicate values in either row, column or
*             the 3x3 solver output, if there are duplicates it returns false otherwise true.
*/
 _Bool sort_array_and_test(int tester[ROWS]){
     
     int temp = 0;
     for(int k = 0; k < ROWS; k++){
           for(int l = 0; l < COLS - (k+1); l++){
               if (tester[l] > tester[l + 1]){
                   temp = tester[l];
                   tester[l] = tester[l + 1];
                   tester[l + 1] = temp;
               }
           }
     }

    /* The Sudoku rule states the 3x3 need to contain numbers from 1 to 9 without duplicate*/
    for(int m = 0; m < ROWS; m++){
        if(tester [m] != (m+1)){
                return 0;
        }

    }
    
    return 1;
 }


/**
* This function extracts the 3x3 values from the solver output
* @param[in] solver[ROWS][COLS] contains the solver 2D array output values.
* @param[in] FILE *fp is the file pointer to write the test results to a log file located at /test/log.
* @param[out] tester[ROWS] contains the 3x3 solver output values.
*/
 void extract_3x3(int solver[ROWS][COLS], FILE *fp, int tester[ROWS]){

    int three_by_three, section = 0;

    /* Testing the 3x3 sections of the result array to see if they comply with the Sodoku rule */
    for(int i = 0; i < ROWS; i = i + 3){

        for(int j = 0; j < COLS; j = j + 3){
            three_by_three = 0;
            for(int k = i; k < 3 + i; k++){

                for(int l = j; l < 3 + j; l++){

                  tester[three_by_three++] = solver[k][l];

                }
            }
             section++;

            /* The following message is written to log file and will show which section of the 3x3 Sudoku game violated the Sudoku rule */


            if(sort_array_and_test(tester)){
                 fprintf(fp, "The [3 x 3] section %d %s", section, "of the solver output has ***passed*** the Sudoku rule test\n");
            }
            else{
                 fprintf(fp, "The [3 x 3] section %d %s", section, "of the solver output has ***failed*** the Sudoku rule test\n");
            }
        }
    }
 }


/**
* Testing the rows of the 9x9 solver output to see if it comply with the Sodoku rules
* @param[in] solver[ROWS][COLS] contains the solver output values.
* @param[in] FILE *fp is the file pointer to write the test results to a log file located at /test/log.
* @param[out] tester[ROWS] contains the rows data of solver output.
*/
 void extract_rows(int solver [ROWS][COLS], FILE *fp, int tester[ROWS]){

     for(int i = 0; i < ROWS; i++){
         for(int j = 0; j < COLS; j++){
             tester[j] = solver[i][j];
         }

         if(sort_array_and_test(tester)){
                fprintf(fp, "Row %d %s", i+1, "solver output has ***passed*** the Sudoku rule test\n");
         }
         else{
                fprintf(fp,  "Row %d %s", i+1, "solver output has ***failed*** the Sudoku rule test\n");
         }
     }
 }


 /**
* Testing the columns of the 9x9 solver output to see if it comply with the Sodoku rules
* @param[in] solver[ROWS][COLS] contains the solver output values.
* @param[in] FILE *fp is the file pointer to write the test results to a log file located at /test/log.
* @param[out] tester[ROWS] contains the columns data of solver output.
*/
 void extract_columns(int solver [ROWS][COLS], FILE *fp, int tester [ROWS]){
     int count = 0;
     for(;;){
         for(int i = 0; i < ROWS; i++){
             for(int j = 0; j < 1 ; j++ ){
                 tester[i] = solver[i][count];
             }
         }
         count++;
         if(sort_array_and_test(tester)){
             fprintf(fp, "Column %d %s", count, "solver output has ***passed*** the Sudoku rule test\n");
         }
         else{
             fprintf(fp, "Column %d %s", count, "solver output has ***failed*** the Sudoku rule test\n");
         }
         if(count == 9){
             break;
         }
     }
 }

 int main()
 {
    FILE *fp;
    int tester [ROWS];
    int solver [ROWS][COLS];

    int musked_sudoku [ROWS][COLS] = {{3, 0, 6, 5, 0, 8, 4, 0, 0 },
                                      {5, 2, 0, 0, 0, 0, 0, 0, 0 },
                                      {0, 8, 7, 0, 0, 0, 0, 3, 1 },
                                      {0, 0, 3, 0, 1, 0, 0, 8, 0 },
                                      {9, 0, 0, 8, 6, 3, 0, 0, 5 },
                                      {0, 5, 0, 0, 9, 0, 6, 0, 0 },
                                      {1, 3, 0, 0, 0, 0, 2, 5, 0 },
                                      {0, 0, 0, 0, 0, 0, 0, 7, 4 },
                                      {0, 0, 5, 2, 0, 6, 3, 0, 0 }};

    if (solver_sudoku(musked_sudoku,solver)){
        printf("The solver solved the puzzle\n");
    }
    else{
        printf("The solver did not solve the puzzle\n");
    }

    for(int i = 0 ; i < 9; i++){
            for (int j = 0 ; j < 9; j++){
               printf("%d ", solver[i][j]);

            }
           printf("\n");
    }


    fp = fopen ("../log/sudoku_solver_test_log_file.txt", "w+");
    if (fp == NULL)
    {
        printf("Could not open the file");
        return 0;
    }

    fprintf(fp, "%s", "Testing all nine 3x3 sections of the Sudoku solver output to see if it complies with the Sodoku rules\n");
    fprintf(fp, "%s", "-----------------------------------------------------------------------------------------------------\n");
    extract_3x3(solver, fp, tester);
    fprintf(fp, "%s", "\n");

    fprintf(fp, "%s", "Testing all the rows of the Sudoku solver output \n");
    fprintf(fp, "------------------------------------------------\n");
    extract_rows(solver, fp, tester);
    fprintf(fp, "%s", "\n");

    fprintf(fp, "%s", "Testing all the columns of the Sudoku solver output \n");
    fprintf(fp, "%s", "---------------------------------------------------\n");
    extract_columns(solver, fp, tester);

    printf("\n");
    printf("~~~~~~~ The output of this program is written to a log file, located at /test/log ~~~~~~~\n");

    fclose(fp);
    return 0;
 }
