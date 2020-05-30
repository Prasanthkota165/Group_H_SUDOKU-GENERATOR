/*
* TITLE      :output_sudoku.c 
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


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void output_sudoku(int sudoku_solution[][9], int sudoku_puzzle[][9], 
                        int diff_lvl){
           
    static int output_count = 1;/*Output p_counter indicating the number of times the 
                                    function creates a Sudokus puzzle and Solution
                                    during the entire run of the program*/
    
    #ifdef linux                           //Create output folder if Linux OS 
    mkdir("../output");                     
    #elif defined(_WIN32)||defined (WIN32) //Create output folder if Microsoft OS
    mkdir("..\\output");
    #endif
    
    /*Creates the Sudoku Puzzle and Sudoku Solution files*/
    create_sudoku_file(sudoku_puzzle, "puzzle", diff_lvl, output_count);
    create_sudoku_file(sudoku_solution, "solution", diff_lvl, output_count);
    
    output_count++; //Increments the output p_counter 
}

void create_sudoku_file(int sudoku[][9], char* sudoku_type, int diff_lvl, 
                            int output_count){
    
    //Pointers
    char *p_file_name; //File name of the sudoku
    char *p_counter = (char*)malloc(sizeof(int)); //String of the Output counter 
	FILE *p_sudoku_file; 
    
    //Variables
    char value, seperator;
    int k = 0;

    #ifdef linux //Assign Linux OS file name path   
    p_file_name = strcat("../output/sudoku_", sudoku_type);
    #elif defined(_WIN32)||defined (WIN32) //Assign Microsoft OS file name path   
    p_file_name = strcat("..\\output\\sudoku_", sudoku_type);
    #endif
    
    /*Concatenates the difficulty level to the file name*/
    switch(diff_lvl){
        case(0):strcat(p_file_name, "_easy_");break;
        case(1):strcat(p_file_name, "_normal_");break;
        case(2):strcat(p_file_name, "_hard_");break;
        case(3):strcat(p_file_name, "_very_hard_");break;
    }

    spintf(p_counter,"%d",output_count); /*Converts the output counter from an 
                                            int to a string*/ 
    strcat(p_file_name, p_counter); /*Concatenates output counter to the 
                                        file name*/
    strcat(p_file_name, ".csv"); /*Concatenates the csv file type to the 
                                    file name*/
    free(p_counter); //Free memory space of the counter


    p_sudoku_file = fopen(p_file_name, "w"); /*Creates or opens the file name 
                                            in the output directory*/
   
    //Writes the Sudoku data in the Sudoku file
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

    fclose(p_sudoku_file); //End writing the sudoku file

    free(p_file_name); //Free memory space of the file name
    free(p_sudoku_file); //Free memory space of the file pointer
}