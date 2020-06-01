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


/*The below functions are defined only to support the "rearrange_cols_rows" function */

#ifndef REARRANGE_COLS_ROWS_H
#define REARRANGE_COLS_ROWS_H

int choose_number(int , int );
void swap(int table[][9]);
void change_columns(int col_matrix[][9], int p, int q, int r);
void change_rows(int row_matrix[][9], int x, int y, int z);
void col_groups(int column_group[][9], int b_1[9][3], int b_2[9][3], int b_3[9][3]);
void row_groups(int r_group[][9], int c_1[3][9], int c_2[3][9], int c_3[3][9]);

#endif
