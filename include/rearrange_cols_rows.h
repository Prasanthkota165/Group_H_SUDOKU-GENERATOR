/**
 * @file rearrange_cols_rows.h
 *
 * @brief This file is used to create functions to generate different combinations of sudoku. 
 *
 * @author Prasanth Kota - prasanthkota@cmail.carleton.ca
 */

#ifndef REARRANGE_COLS_ROWS_H
#define REARRANGE_COLS_ROWS_H
/**
 * @brief This function is used to generate random numbers between [1,9] 
 *  
 * @param[in] rangeLow --- This parameter is used to determine the lowest number in the range.
 *
 * @param[in] rangeHigh --- This parameter is used to determine the highest number in the range.
 *
 * @details  This is a predefined function which is used for the generation of different combinations of sudoku.
 *
 * @return This function returns a number between [1,9]
 *
 */ 

int choose_number(int , int );

/**
 * @brief This function is used to select different numbers in the sudoku template and swap them accordingly.
 *
 * @param[in] table[][9] --- This parameter updates the sudoku template after successful swapping of the values.
 * 
 * @details This is a predefined function which is used for the generation of different combinations of sudoku.
 * 
 * @return There is no return value for this function.
 *
 */ 

void swap(int table[][9]);

/**
 * @brief This function is used to change the randomly rearrange columns:
		1, 2 and 3 within themselves;
		4, 5 and 6 within themselves; and
		7, 8 and 9 within themselves. 
 * 
 * @param[in] col_matrix[][9] --- This parameter updates the sudoku template after the rearrangement of the columns combination consecutively.
 *
 * @param[in] p --- This parameter is used to take the values of the column number.
 *
 * @param[in] q --- This paramter is used to take the values of the consecutive column number after the xth column.
 *
 * @param[in] r --- This parameter is used to take the values of the consecutive column number after the yth column.
 *
 * @details This is a predefined function which is used for the generation of different combinations of sudoku.
 * 
 * @return There is no return value for this function.
 *
 */ 

void change_columns(int col_matrix[][9], int p, int q, int r);

/**
 * @brief This function is used to change the randomly rearrange rows:
		1, 2 and 3 within themselves;
		4, 5 and 6 within themselves; and
		7, 8 and 9 within themselves. 
 * 
 * @param[in] row_matrix[][9] --- This parameter updates the sudoku template after the rearrangement of the rows combination consecutively.
 *
 * @param[in] x --- This parameter is used to take the values of the row number.
 *
 * @param[in] y --- This paramter is used to take the values of the consecutive row number after the xth row.
 *
 * @param[in] z --- This parameter is used to take the values of the consecutive row number after the yth row.
 *
 * @details This is a predefined function which is used for the generation of different combinations of sudoku.
 * 
 * @return There is no return value for this function.
 *
 */ 

void change_rows(int row_matrix[][9], int x, int y, int z);

/**
 * @brief This function is used to randomly rearrange in 3 row groups of size 3x9 
 * 
 * @param[in] column_group[][9] --- This parameter updates the sudoku template after the rearrangement of 3 column groups (9x3 size).
 *
 * @param[in] b_1[9][3] --- This parameter is used to copy the first 9x3 size of sudoku template and overwrite it's values.
 *
 * @param[in] b_2[9][3] --- This parameter is used to copy the second 9x3 size of sudoku template and overwrite it's values.
 *
 * @param[in] b_3[9][3] --- This parameter is used to copy the third 9x3 size of sudoku template and overwrite it's values.
 * 
 * @details This is a predefined function which is used for the generation of different combinations of sudoku.
 * 
 * @return There is no return value for this function.
 *
 */ 
void col_groups(int column_group[][9], int b_1[9][3], int b_2[9][3], int b_3[9][3]);

/**
 * @brief This function is used to randomly rearrange in 3 row groups of size 3x9 
 * 
 * @param[in] r_group[][9] --- This parameter updates the sudoku template after the rearrangement of 3 row groups (3x9 size).
 *
 * @param[in] c_1[3][9] --- This parameter is used to copy the first 3x9 size of sudoku template and overwrite it's values.
 *
 * @param[in] c_1[3][9] --- This parameter is used to copy the second 3x9 size of sudoku template and overwrite it's values.
 *
 * @param[in] c_1[3][9] --- This parameter is used to copy the third 3x9 size of sudoku template and overwrite it's values.
 *
 * @details This is a predefined function which is used for the generation of different combinations of sudoku.
 * 
 * @return There is no return value for this function.
 *
 */ 

void row_groups(int r_group[][9], int c_1[3][9], int c_2[3][9], int c_3[3][9]);

#endif
