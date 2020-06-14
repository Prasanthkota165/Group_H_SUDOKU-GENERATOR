#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#define ROWS 9
#define COLS 9
 
/**
 * This function askes for the difficulty level of the sudokus and the number of
 * sudokus that the user wants to generate. The difficulty levels can be entered 
 * as 0,1,2,3 for easy, medium, hard and very hard respectively. It checks the 
 * user input for these values and if user enters any other values, say characters,
 * strings, symbols etc., it simply voids them and continues to ask the user until 
 * it gets the valid difficulty level. Later the function asks the user to input to 
 * enter the number of sudokus that the user wants to generate and the limit that 
 * this program can generate is set to 40. So it continues to ask the user for the 
 * number of sudokus until the user enters valid number which is between 1 to 40 
 * inclusive. Then this function returns these to values for furthur use in the software.  
 *      
 * @param[in] diff_level, This parameter takes the difficulty level from user.
 *
 * @param[in] no_sudoku, This parameter takes the number of sudokus that user want 
 *                       to generate.
 */
void input_sudoku(int* , int* );

/**
 * This function generates a pre-defined sudoku template using a two dimentional 
 * array which is of size 9X9 that is rearranged in a different function called 
 * rearrange_cols_rows.c 
 *  
 * @param[in] sudoku_temp[ROWS][COLS], Two dimentional array of size 9X9 containing
 *                                     the sudoku template. 
 */
void generate_sudoku_template(int [ROWS][COLS]);

/**
 * The function rearrange_cols_rows takes in the sudoku template created in the
 * generate_sudoku_template function and goes on step-by-step random procedure
 * to generate different types of sudoku template. Firstly, it interchanges the 
 * 3 different numbers selecting randomly in each row. Then, it rearranges the 
 * columns,rows between them in the combination of three (Ex: 1,2,3 columns/rows 
 * rearrange themselves, followed by 4,5,6 rearranging and then 7,8,9 columns/rows).
 * After successful rearrangement, it also swaps the 3 column groups of 9x3 size
 * between them and followed by the swapping of the 3 row groups of size 3x9.
 * Finally, outputs the rearranged_sudoku of size 9x9.
 *
 * @param[in] sudoku_template[][9], This parameter takes the template generating 
 * 				    in the function generate_sudoku_template.c
 * @param[in] rearranged_sudoku[][9], This parameter is the updated randomized 
 * 				      sudoku template.
*/
void rearrange_cols_rows(int [ROWS][COLS], int [ROWS][COLS]);

_Bool test_sudoku_rules(int test_sudoku[ROWS][COLS]);


/**
* Function apply_mask creates unique masks in turn creates a unique Sudoku game. 
* Numbers are masked from rearrange_cols_rows [][] array locations based on the
* diffculty level. The difficulty levels are catagorized as easy, medium, hard, 
* and very hard, where 40, 34, 28, 24 numbers are only shown on the Sudoku game
* respectively. A Sudoku game have a total of 81 cells, and function apply_mask 
* generates random numbers between 1 to 81, where each radomly generated numbers
* are representing a location at the 2D array and this location information is 
* then used to map the rearrange_cols_rows [][] array locations to mask numbers 
* based on the difficulty level.
* 
* @param rearranged_sudoku [in], Array containing the rearranged Sudoku game.
* @param diff_level [in], Difficulty level dectates how many numbers should be shown on Sudoku game.
* @param masked_sudoku [out], Array containing the masked Sudoku game.
*/
void apply_mask(int [ROWS][COLS], int, int [ROWS][COLS]);


_Bool apply_solver(int [ROWS][COLS]);


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
void output_sudoku(int [ROWS][COLS], int [ROWS][COLS], int);


/** \brief Sub function to create a Sudoku file. 
 *  
 *  This function takes-in an 9x9 array which representes a Sudoku grid (This 
 *  can be either a Sudoku Puzzle or a Sudoku Solution). It will create a 
 *  single CSV file in the ../output directory. The function will use three 
 *  parameters to name the file:  
 * 
 *      - The Sudoku type (Puzzle or Solution);
 *      - The difficulty level (easy, normal, hard, very hard);
 *      - The current iteration of the Sudoku. 
 *  
 *  Once the file name is made, the file itself is created and each element 
 *  of the array is written on the file as a character. If the element is:
 * 
 *      - an int between 1 and 9, then the corresponding character between 
 *          1 and 9 will be written; and
 *      - int 0, then ' ' will be written.
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
void create_sudoku_file(int [ROWS][COLS], char* , int, int);

#endif 



/* The below functions are defined only to support the "rearrange_cols_rows" function */

#ifndef REARRANGE_COLS_ROWS_H
#define REARRANGE_COLS_ROWS_H

/**
 * @brief This function is used to generate random numbers between [1,9] 
 *
 * @param[in] rangeLow -- This parameter determines the lowest number in the range.
 * @param[in] rangeHigh -- This parameter determines the highest number in the range.
 * @return This function returns a number between [1,9]
 */ 
int choose_number(int, int);

/**
 * @brief This function is used to select different numbers in the 
 *        sudoku template and swap them accordingly.
 *
 * @param[in] table[][9] -- This parameter updates the sudoku template 
 *			     after successful swapping of the values.
 */ 
void swap(int [][9]);

/**
 * @brief This function is to change the randomly rearrange columns:
 *		1, 2 and 3 within themselves;
 *		4, 5 and 6 within themselves; and
 *		7, 8 and 9 within themselves. 
 *
 * @param[in] col_matrix[][9] -- This parameter updates the sudoku template after the 
 *				  rearrangement of the columns combinations consecutively.
 * @param[in] p -- This parameter is used to take the values of the column number.
 * @param[in] q -- This paramter is used to take the values of the 
 *		    consecutive column number after the pth column.
 * @param[in] r -- This parameter is used to take the values of the 
 *		    consecutive column number after the qth column.
 */
void change_columns(int [][9], int , int , int );

/**
 * @brief This function is to change the randomly rearrange rows:
 *		1, 2 and 3 within themselves;
 *		4, 5 and 6 within themselves; and
 *		7, 8 and 9 within themselves.
 *
 * @param[in] row_matrix[][9] -- This parameter updates the sudoku template 
 *				  after the rearrangement of the rows combination consecutively.
 * @param[in] x -- This parameter is used to take the values of the row number.
 * @param[in] y -- This paramter is used to take the values of the 
 *		    consecutive row number after the xth row.
 * @param[in] z -- This parameter is used to take the values of the
 *		    consecutive row number after the yth row. 
 */
void change_rows(int [][9], int, int, int);

/**
 * @brief This function is used to randomly rearrange the sudoku template
 *         in 3 column groups of size 9x3.
 *
 * @param[in] column_group[][9] -- This parameter updates the sudoku template
 *				    after the rearrangement of 3 column groups (9x3 size).
 * @param[in] b_1[9][3] -- This parameter is used to copy the first 9x3 size 
 *			    of sudoku template and overwrite it's values.
 * @param[in] b_2[9][3] -- This parameter is used to copy the second 9x3 size 
 *		            of sudoku template and overwrite it's values.
 * @param[in] b_3[9][3] -- This parameter is used to copy the third 9x3 size
 *			    of sudoku template and overwrite it's values.
 */
void col_groups(int [][9], int[9][3], int[9][3], int[9][3]);

/** 
 * @brief This function is used to randomly rearrange the sudoku template 
 *        in 3 row groups of size 3x9.
 *
 * @param[in] r_group[][9] -- This parameter updates the sudoku template 
 *			       after the rearrangement of 3 row groups (3x9 size).
 * @param[in] c_1[3][9] -- This parameter is used to copy the first 3x9 size 
 *			    of sudoku template and overwrite it's values.
 * @param[in] c_1[3][9] -- This parameter is used to copy the second 3x9 size
 *		            of sudoku template and overwrite it's values.
 * @param[in] c_1[3][9] -- This parameter is used to copy the third 3x9 size
 *			    of sudoku template and overwrite it's values.
 */
void row_groups(int [][9], int [3][9], int [3][9], int [3][9]);

#endif

#ifndef INPUT_SUDOKU_H
#define INPUT_SUDOKU_H
/** 
 * @brief This function removes surplus characters or symbols from the input buffer.
 *        Otherwise, if restricted symbols or characters have been entered during the
 *        call to fgets(), the surplus characters (after MAX_DIGITS chars) remain in the input buffer
 *        and will be wrongly accepted as input on the next iteration of the loop.
 *
 */
static inline void clear_input_buffer();

/** 
 * @brief This function initially clears the input buffer and checks for restricted input values and returns only if the entered value 
 *        is integer. 
 *
 * @param[in] *input_integer -- This parameter takes the user input.
 * 
 */
void get_integer_from_stdin(int *);



#endif


