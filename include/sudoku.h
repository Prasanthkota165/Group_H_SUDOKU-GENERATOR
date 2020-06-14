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
void input_sudoku(int* diff_level, int* no_sudoku);

/**
 * This function generates a pre-defined sudoku template using a two dimentional 
 * array which is of size 9X9 that is rearranged in a different function called 
 * rearrange_cols_rows.c 
 *  
 * @param[in] sudoku_temp[ROWS][COLS], Two dimentional array of size 9X9 containing
 *                                     the sudoku template. 
 */
void generate_sudoku_template(int sudoku_temp[ROWS][COLS]);

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
void rearrange_cols_rows(int sudoku_temp[ROWS][COLS], 
                            int rearranged_sudoku_temp[ROWS][COLS]);

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
void apply_mask(int rearrange_cols_rows[ROWS][COLS], int diff_level, 
                                            int masked_sudoku[ROWS][COLS]);

/** @brief Primary function to solve the Sudoku Puzzle.
 * 
 * This function takes in a Sudoku puzzle and verifies if the Sudoku puzzle 
 * is solvable. It begins by copying the Sudoku Puzzle into a temporary 2D 
 * int array which can be called a temporary sudoku. The temporary sudoku 
 * is then used as a parameter to the function apply_solver(). The return of 
 * the function apply_solver() will either return TRUE if it is solvable. If 
 * the temporary sudoku puzzle is not solvable, then the function will return 
 * FALSE and print a message saying "No solution exists for this puzzle."
 * 
 * The reason for copying the Sudoku Puzzle is that the function apply_solver() 
 * modifies the parameter as the sudoku gets solved. It is important that the 
 * sudoku_puzzle does not get modified as it will be used further on in the 
 * program to write its data in a file, including the empty spaces. As such, 
 * a copy is needed to solve te Sudoku Puzzle. 
 * 
 * @param[in] sudoku_puzzle[9][9] The Sudoku Puzzle to be verified.
 * @param[out] temp_sudoku[9][9] The Sudoku Solution when solved.
 * @return TRUE if it is solvable, FASLE if it is not.
 */
_Bool solver_sudoku(int sudoku_puzzle [ROWS][COLS], int temp_sudoku[ROWS][COLS]);

/** @brief Recursive function to solve the Sudoku Puzzle.
 * 
 * This function takes a partially filled Sudoku Puzzle and attempts to assign 
 * values to all EMPTY locations in such a way to meet the requirements for a 
 * Sudoku Solution (no conflict across rows, columns, and boxes).
 * 
 * First, it searches for an EMPTY slot in the Sudoku Puzzle by using the 
 * function find_next_empty(). If it can't find one, then the Sudoku Puzzle has 
 * been resolved, and the function will return TRUE. If it finds an EMPTY slot, 
 * then the function find_next_empty() will return FASLE and also return the row 
 * and column of that empty EMPTY slot.
 * 
 * Afterwards, it will verify each whole number between 1 and 9 inclusively and 
 * detremine if there is a conflict with either the row, column or boxe related 
 * to that empty slot:
 *      - If there is no conflict, then the function will call itself to continue 
 *          searching for the next EMPTY slot. This recursivity will end once all 
 *          slots are no longer EMPTY and no slots conflicting with one another. 
 *
 *      - If there is a conflict with one of the numbers, then it will move on to 
 *          the next one until all numbers have been used. Once all numbers are 
 *          confirmed to be in conflict, then the function will return FALSE and 
 *          return back to the previous call of apply_solver(). 
 * 
 * @param[in/out] sudoku_puzzle[9][9] partial sudoku puzzle to be solved.
 * 
 * @return TRUE if the sudoku puzzle has been solved, FALSE if it can't be 
 *          solved.    
 */
_Bool apply_solver(int sudoku_puzzle [ROWS][COLS]);

/** \brief Function that finds the next empty slot in a Sudoku Puzzle.
 * 
 * This function searches the sudoku_puzzle parameter in order to find a slot 
 * that is EMPTY. If found, the reference parameters row, col will be set with 
 * the location of the EMPTY slot and true is returned. If no EMPTY slots 
 * remain in the Sudoku Puzzle, then FALSE will be returned. 
 * 
 * @param[in] sudoku_puzzle[9][9] The Sudoku Puzzle to check for EMPTY slots.
 * @param[out] slot[2] An array to store the location of the EMPTY slot.
 * 
 * @return TRUE if an EMPTY slot is found, FALSE if not.
 */
_Bool find_next_empty(int sudoku_puzzle[ROWS][COLS], int location[2]);

/** @brief Verifies if there is a possible conflict if a number is assigned 
 *          at that location. 
 * 
 * This function checks if the number is already placed in either the row, the 
 * column, or the 3x3 box of the location. 
 * 
 * The function uses three seperate functions where each function verifies a 
 * specific area of the SUdoku Puzzle (row, column or box). Each will return 
 * a __Bool value which indicates if the area is free of the requested number. 
 * 
 * If at least one of the areas have an instance of the number already in 
 * place, then the function no_conflict() will return FALSE. If none of the 
 * areas have the requested number, then the function will return TRUE.
 *  
*  @param[in] sudoku_puzzle[9][9] The Sudoku Puzzle to check for a conflict.
 * @param[in] row The row of the location to check for conflict.
 * @param[in] col The column of the location to check for conflict.
 * @param[in] num The number that needs to be verified for conflict.
 * 
 * @return Returns TRUE if the location is free to place the number, FALSE if 
 *          it will create a conflict.
 */
_Bool no_conflict(int sudoku_puzzle[ROWS][COLS], int row, int col, int num);

/** @brief Verifies if the number is already in the row.
 * 
 * This functions checks if the requested number is already in the row by 
 * simply verifying each individual column of the row.
 * 
 * @param[in] sudoku_puzzle[9][9] The Sudoku Puzzle to check in.
 * @param[in] row The row to verify if the number is already there.
 * @param[in] num The number that needs to be verified.
 * 
 * @return Returns TRUE if the row has the number already there, FALSE if 
 *          not.
 */ 
_Bool used_in_row( int sudoku_puzzle[ROWS][COLS], int row, int num);

/** @brief Verifies if the number is already in the column.
 * 
 * This functions checks if the requested number is already in the column by 
 * simply verifying each individual row of the column.
 * 
 * @param[in] sudoku_puzzle[9][9] The Sudoku Puzzle to check in.
 * @param[in] col The column to verify if the number is already there.
 * @param[in] num The number that needs to be verified.
 * 
 * @return Returns TRUE if the colum has the number already there, FALSE if 
 *          not.
 */ 
_Bool used_in_col(int sudoku_puzzle[ROWS][COLS], int col, int num);

/** @brief Verifies if the number is already in the box.
 * 
 * This functions checks if the requested number is already in the 3x3 by 
 * simply verifying each individual slot in the box.
 * 
 * To determine which box the function needs to verify, the current row and 
 * column are needed to determine the starting point in the box. By dividing 
 * and multiplying the row and column by 3, the function can determine the 
 * starting point of the box verification.
 * 
 * @param[in] sudoku_puzzle[9][9] The Sudoku Puzzle to check in.
 * @param[in] row The row of the current location.
 * @param[in] col The column of the current location.
 * @param[in] num The number that needs to be verified.
 * 
 * @return Returns TRUE if the box has the number already there, FALSE if 
 *          not.
 */
_Bool used_in_box(int sudoku_puzzle[ROWS][COLS], int row, int col, int num);  

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



/* The below functions are defined only to support the "rearrange_cols_rows" function */

#ifndef REARRANGE_COLS_ROWS_H
#define REARRANGE_COLS_ROWS_H

/**
 * @brief This function is used to generate random numbers between [1,9] 
 *
 * @param[in] rangeLow --- This parameter determines the lowest number in the range.
 * @param[in] rangeHigh --- This parameter determines the highest number in the range.
 * @return This function returns a number between [1,9]
 */ 
int choose_number(int rangeLow, int rangeHigh);

/**
 * @brief This function is used to select different numbers in the 
 *        sudoku template and swap them accordingly.
 *
 * @param[in] table[][9] --- This parameter updates the sudoku template 
 *			     after successful swapping of the values.
 */ 
void swap(int table[][9]);

/**
 * @brief This function is to change the randomly rearrange columns:
 *		1, 2 and 3 within themselves;
 *		4, 5 and 6 within themselves; and
 *		7, 8 and 9 within themselves. 
 *
 * @param[in] col_matrix[][9] --- This parameter updates the sudoku template after the 
 *				  rearrangement of the columns combinations consecutively.
 * @param[in] p --- This parameter is used to take the values of the column number.
 * @param[in] q --- This paramter is used to take the values of the 
 *		    consecutive column number after the pth column.
 * @param[in] r --- This parameter is used to take the values of the 
 *		    consecutive column number after the qth column.
 */
void change_columns(int col_matrix[][9], int p, int q, int r);

/**
 * @brief This function is to change the randomly rearrange rows:
 *		1, 2 and 3 within themselves;
 *		4, 5 and 6 within themselves; and
 *		7, 8 and 9 within themselves.
 *
 * @param[in] row_matrix[][9] --- This parameter updates the sudoku template 
 *				  after the rearrangement of the rows combination consecutively.
 * @param[in] x --- This parameter is used to take the values of the row number.
 * @param[in] y --- This paramter is used to take the values of the 
 *		    consecutive row number after the xth row.
 * @param[in] z --- This parameter is used to take the values of the
 *		    consecutive row number after the yth row. 
 */
void change_rows(int row_matrix[][9], int x, int y, int z);

/**
 * @brief This function is used to randomly rearrange the sudoku template
 *         in 3 column groups of size 9x3.
 *
 * @param[in] column_group[][9] --- This parameter updates the sudoku template
 *				    after the rearrangement of 3 column groups (9x3 size).
 * @param[in] b_1[9][3] --- This parameter is used to copy the first 9x3 size 
 *			    of sudoku template and overwrite it's values.
 * @param[in] b_2[9][3] --- This parameter is used to copy the second 9x3 size 
 *		            of sudoku template and overwrite it's values.
 * @param[in] b_3[9][3] --- This parameter is used to copy the third 9x3 size
 *			    of sudoku template and overwrite it's values.
 */
void col_groups(int column_group[][9], int b_1[9][3], int b_2[9][3], int b_3[9][3]);

/** 
 * @brief This function is used to randomly rearrange the sudoku template 
 *        in 3 row groups of size 3x9.
 *
 * @param[in] r_group[][9] --- This parameter updates the sudoku template 
 *			       after the rearrangement of 3 row groups (3x9 size).
 * @param[in] c_1[3][9] --- This parameter is used to copy the first 3x9 size 
 *			    of sudoku template and overwrite it's values.
 * @param[in] c_1[3][9] --- This parameter is used to copy the second 3x9 size
 *		            of sudoku template and overwrite it's values.
 * @param[in] c_1[3][9] --- This parameter is used to copy the third 3x9 size
 *			    of sudoku template and overwrite it's values.
 */
void row_groups(int r_group[][9], int c_1[3][9], int c_2[3][9], int c_3[3][9]);

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
static inline void ClearInputBuffer();

/** 
 * @brief This function initially clears the input buffer and checks for restricted input values and returns only if the entered value 
 *        is integer. 
 *
 * @param[in] *inputInteger --- This parameter takes the user input.
 * 
 */
void getIntegerFromStdin(int *inputInteger);

/** 
 * @brief This functions asks the difficulty level and number of sudokus checks whether the meet the pre-defined conditions.
 *
 * @param[in] diff_level --- This parameter stores the difficulty level entered by the user.
 *
 * @param[in] no_sudoku --- This parameter store the number of sudokus that the user wants to generate. 
 */
void input_sudoku(int *diff_level,int *no_sudoku);

#endif


