#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#define ROWS 9
#define COLS 9
 

void input_sudoku(int*, int*);
void generate_sudoku_template(int sudoku_temp[ROWS][COLS]);
void rearrange_cols_rows(int sudoku_temp[ROWS][COLS], 
                            int rearranged_sudoku_temp[ROWS][COLS]);
_Bool test_sudoku_rules(int test_sudoku[ROWS][COLS]);
void apply_mask(int rearrange_cols_rows[ROWS][COLS], int numbers_tobe_shown, 
                    int masked_sudoku[ROWS][COLS]);
_Bool apply_solver(int sudoku_puzzle [ROWS][COLS]);

/** \brief Primary function to create the Sudoku Puzzle and Solution. 
 *  
 *  This function takes-in two sudoku grid (Sudoku Puzzle and Sudoku Solution) 
 *  and calls on the function create_sudoku_file() to create a.CSV file for 
 *  each Sudoku. It also creates the destination directory /output, in the event 
 *  that the directory doesn't exist. 
 *  
 *  The function also contains a static variable that allows it to count the 
 *  number of times outpu_sudoku has been used. This value is used in the naming 
 *  of the files in the function create_sudoku_file() 
 *  
 *  @param[in] sudoku_solution The Sudoku Solution that will be created.
 *  @param[in] sudoku_puzzle The Sudoku Puzzle that will be created.
 *  @param[in] diff_lvl The difficulty level of the Sudoku Puzzle. 
 */
void output_sudoku(int sudoku_solution [ROWS][COLS], 
                    int sudoku_puzzle [ROWS][COLS], int diff_lvl);


/** \brief Sub function to create a Sudoku file. 
 *  
 *  This function takes-in an 9x9 array which representes a Sudoku grid (This 
 *  can be either a Sudoku Puzzle or a Sudoku Solution). It will create a 
 *  single CSV file in the ../output directory. The function will use three 
 *  parameters to name the file:  
 * 
 *      -The Sudoku type (Puzzle or Solution);
 *      -The difficulty level (easy, normal, hard, very hard);
 *      -The current iteration of the Sudoku. 
 *  
 *  Once the file name is made, the file itself is created and each element 
 *  of the array is written on the file as a character. If the element is:
 * 
 *      -an int between 1 and 9, then the corresponding character between 
 *          1 and 9 will be written; and
 *      -int 0, then ' ' will be written.
 * 
 * Once it has gone through the entire array, the function will then close file 
 * stream and end the function.   
 *  
 *  @param[in] sudoku The Sudoku with the data inside.
 *  @param[in] sudoku_type The Sudoku type chosen by the user.
 *  @param[in] diff_lvl The difficulty level of the Sudoku.
 *  @param[in] output_count The current number of times a Sudoku pair has been 
 *              created. 
 */
void create_sudoku_file(int sudoku[ROWS][COLS], char* sudoku_type, int diff_lvl, 
                        int output_count);

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
