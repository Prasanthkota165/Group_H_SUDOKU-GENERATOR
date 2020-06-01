#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#define ROWS 9
#define COLS 9
 

void input_sudoku(int arr[2]);
void generate_sudoku_template(int sudoku_temp[ROWS][COLS]);
void rearrange_cols_rows(int sudoku_temp[ROWS][COLS], int rearranged_sudoku_temp[ROWS][COLS]);
_Bool test_sudoku_rules(int test_sudoku[ROWS][COLS]);
void apply_mask(int rearrange_cols_rows[ROWS][COLS], int numbers_tobe_shown, int masked_sudoku[ROWS][COLS]);
_Bool apply_solver(int sudoku_puzzle [ROWS][COLS]);
void output_sudoku(int sudoku_solution [ROWS][COLS], int sudoku_puzzle [ROWS][COLS], int diff_lvl);
void create_sudoku_file(int sudoku[ROWS][COLS], char* sudoku_type, int diff_lvl, int output_count);

#endif 
