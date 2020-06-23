/**
* @file output_sudoku.c 
*
* Purpose   : Contains the functions to create the sudoku file for the Sudoku 
*             Generator program. 
*
* Language  : C
*
* Author    : Mathieu Falardeau 101173923, 
* GitHub ID : Mathieufalardeau3 
* Date      : 29 May 2020
*
*/
#if defined(_WIN32)||defined (WIN32) //<Define if Microsoft OS                           
#include <direct.h>
#include "..\\include\\sudoku.h"
#else //Define if Linux OS*/ 
#include "../include/sudoku.h"
#include <sys/stat.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *  Creates the two Sudoku CSV files for the Sudoku Puzzle and Solution in 
 *  an ../output folder. 
 * 
 *  @param[in] sudoku_solution The Sudoku Solution that will be created.
 *  @param[in] sudoku_puzzle The Sudoku Puzzle that will be created.
 *  @param[in] diff_lvl The difficulty level of the Sudoku Puzzle.
 */
void output_sudoku(int sudoku_solution[9][9], int sudoku_puzzle[9][9], 
                        int diff_lvl){
           
    int k = 0;
    static int output_count = 1;/*Output counter indicating the number of times 
                                    the function creates a Sudokus puzzle and 
                                    Solution during the entire run of the 
                                    program*/
    
    #if defined(_WIN32)||defined (WIN32) /*Create output folder if Microsoft OS*/                           
    mkdir("..\\output");                    
    #else 
    mkdir("../output",0777); /*Create output folder if Linux OS */
    #endif
    
    /*Creates the Sudoku Puzzle and Sudoku Solution files*/
    create_sudoku_file(sudoku_solution, "answer", diff_lvl, output_count);

    create_sudoku_file(sudoku_puzzle, "puzzle", diff_lvl, output_count);
    
    output_count++; /*Increments the output counter*/ 

    return;
}

/**
 *  Creates a Sudoku file for the output_sudoku() function.
 *  
 *  @param[in] sudoku The Sudoku with the data inside.
 *  @param[in] sudoku_type The Sudoku type chosen by the user.
 *  @param[in] diff_lvl The difficulty level of the Sudoku.
 *  @param[in] output_count The current number of times a Sudoku pair has been 
 *                          created. 
 */
void create_sudoku_file(int sudoku[][9], char* sudoku_type, int diff_lvl, 
                            int output_count){
    
    /*Pointers*/
    char file_name[50];
    char counter[4]; /*String of the Output counter */
    char sudoku_type_temp[7];
	FILE *p_sudoku_file; 
    
    /*Variables*/
    char value, seperator;
    int k = 0;

    /*Initial Naming of the ouput file*/
    #if defined(_WIN32)||defined(WIN32) /*Assign Microsoft OS file name path*/   
    strcpy(file_name, "..\\output\\sudoku_");
    #else
    strcpy(file_name, "../output/sudoku_");
    #endif
    
	strncpy(sudoku_type_temp, sudoku_type,6);/*Cuts the sudoku_type to a six 
                                                long string if too long*/
    strcat(file_name,sudoku_type_temp); /*Concatenates the sudoku type to the 
                                            file name*/

    /*Concatenates the difficulty level to the file name*/
    switch(diff_lvl){
        case(0):strcat(file_name, "_easy_");break; 
        case(1):strcat(file_name, "_normal_");break;
        case(2):strcat(file_name, "_hard_");break;
        case(3):strcat(file_name, "_very_hard_");break;
        default:strcat(file_name, "_error_");break;
    }
    if(output_count < -99 || output_count > 999){
        output_count = 0;
    }
    sprintf(counter,"%d",output_count); /*Converts the output counter from an 
                                            int to a string*/ 
    strcat(file_name, counter); /*Concatenates output counter to the 
                                        file name*/
    strcat(file_name, ".csv"); /*Concatenates the csv file type to the 
                                    file name*/
    //free(counter); /*Releases memory space of the counter*/

    p_sudoku_file = fopen(file_name, "w"); /*Creates or opens the file name 
                                                in the output directory*/
   
    /*Writes the Sudoku data in the Sudoku file*/
    for (int i = 0; i<9;i++){
        for (int j = 0; j<9;j++){
            k = sudoku[i][j]; 
            
            value = k ? '0' + k : ' '; 
            fputc(value,p_sudoku_file);/*If the digit is a number between 
                                            1 and 9, then the character of the 
                                            digit will be written in the file. 
                                            If the digit is 0, then an empty 
                                            space will be written instead.*/

            seperator = j==8 ? '\n' : ','; 
            fputc(seperator,p_sudoku_file);/*If the last column of the Sudoku 
                                                is reached, then a new line will 
                                                be written in the file. If not, 
                                                then a comma will be written 
                                                instead.*/
        }
    }

    /*Closes the Sudoku file stream*/
    if(fclose(p_sudoku_file)){
        printf("The file did not close properly!!\n");
    }
    
    return;

}
