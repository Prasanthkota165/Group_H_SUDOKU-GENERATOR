#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(void){
    int sudoku_sol[9][9] = {{1,2,3,4,5,6,7,8,9},
                                {1,2,3,4,5,6,7,8,9},
                                {6,1,0,2,0,3,4,0,5},
                                {1,2,3,4,5,6,7,8,9},
                                {1,2,3,4,5,6,7,8,9},
                                {6,1,0,2,0,3,4,0,5},
                                {1,2,3,4,5,6,7,8,9},
                                {1,2,3,4,5,6,7,8,9},
                                {6,1,0,2,0,3,4,0,5},};

    int sudoku_puz[9][9] = {{1,2,3,4,5,6,7,8,9},
                                {0,0,0,0,0,0,0,0,0},
                                {6,1,0,2,0,3,4,0,5},
                                {1,2,3,4,5,6,7,8,9},
                                {0,0,0,0,0,0,0,0,0},
                                {6,1,0,2,0,3,4,0,5},
                                {1,2,3,4,5,6,7,8,9},
                                {0,0,0,0,0,0,0,0,0},
                                {6,1,0,2,0,3,4,0,5},};

    
    output_sudoku(sudoku_sol, sudoku_sol, 1 , 3);

    printf("A sudoku file was created.");

    return 0;
}



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