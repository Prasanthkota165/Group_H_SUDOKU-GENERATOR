#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>


void output_sudoku(int sudoku_solution[][9], int sudoku_puzzle[][9], int diff_lvl, int num_sudoku){
    mkdir("output");
    create_sudoku_file(sudoku_puzzle, "puzzle", diff_lvl, num_sudoku);
    create_sudoku_file(sudoku_solution, "solution", diff_lvl, num_sudoku);
}

void create_sudoku_file(int sudoku[][9], char* sudoku_type, int diff_lvl, int num_sudoku){
    
    char *file_name;
    char *str = (char*)malloc(sizeof(int));
	FILE *sudoku_file;
    char value, seperator;
    int k = 0;

    file_name = strcat(".\\output\\sudoku_", sudoku_type);
    
    switch(diff_lvl){
        case(0):strcat(file_name, "_easy_");break;
        case(1):strcat(file_name, "_normal_");break;
        case(2):strcat(file_name, "_hard_");break;
        case(3):strcat(file_name, "_very_hard_");break;
    }

    spintf(str,"%d",num_sudoku);
    strcat(file_name, str);
    strcat(file_name, ".csv");
    free(str);

    sudoku_file = fopen(file_name, "w");

    for (int i = 0; i<9;i++){
        for (int j = 0; j<9;j++){
            k = sudoku[i][j];
            value = k ? '0' + k : ' ';
            seperator = j==8 ? '\n' : ',';

            fputc(value,sudoku_file);
            fputc(seperator,sudoku_file);
            }
        }
    }

    fclose(sudoku_file);

}