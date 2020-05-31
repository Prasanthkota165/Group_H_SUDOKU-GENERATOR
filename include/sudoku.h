#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#define ROWS 9
#define COLS 9


int * inputSudoku();
void generateSudokuTemplate(int sudoku_temp[ROWS][COLS]);
void rearrangeColsRows(int sudoku_temp[ROWS][COLS], int rearranged_sudoku_temp[ROWS][COLS]);
_Bool testSudokuRules(int test_sudoku[ROWS][COLS]);
void applyMask(int test_sudoku[ROWS][COLS], int diff_level, int masked_sudoku[ROWS][COLS]);
_Bool applySolver(int sudoku_puzzle [ROWS][COLS]);
void output_sudoku(int sudoku_solution [ROWS][COLS], int sudoku_puzzle [ROWS][COLS], int diff_lvl);
void create_sudoku_file(int sudoku[ROWS][COLS], char* sudoku_type, int diff_lvl, int output_count);

#endif  