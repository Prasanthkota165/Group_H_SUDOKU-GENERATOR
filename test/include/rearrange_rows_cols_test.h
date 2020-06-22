#ifndef _REARRANGE_ROWS_COLS_TEST_H
#define _REARRANGE_ROWS_COLS_TEST_H
/**
 * Testing function to check the 4 numbers are swapped in the input parameter.
 * 
 * @param[in] sudoku[][9] input parameter to the function rearrange_rows_cols 
 *                          function.
 *  
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool swap_values(int [][9]);
/**
 * Testing function to check the 9x9 boundaries of the input parameter.
 * 
 * @param[in] sudoku[][9] input parameter to the function rearrange_rows_cols 
 *                          function.
 * 
 * @return FALSE if the test says within the boundaries. True if the test failed.
 *  
 */
_Bool beyond_boundary_1(int [][9]);
/**
 * Testing function to check the 9x9 boundaries of the output parameter.
 * 
 * @param[in] rearranged_sudoku [][9] output parameter to the function 
 *                                     rearrange_rows_cols function.
 * 
 * @return FALSE if the test says within the boundaries. True if the test failed.
 *  
 */
_Bool beyond_boundary_2(int [][9]);
/**
 * Testing function to check input parameter values are within [1,9].
 * 
 * @param[in] sudoku[][9] input parameter to the function rearrange_rows_cols 
 *                          function.
 * 
 * @return FALSE if the test says values are within the range [1,9]. True if 
 *          the test failed.
 *  
 */
_Bool beyond_range_1(int [][9]);
/**
 * Testing function to check output parameter values are within [1,9].
 * 
 * @param[in] rearranged_sudoku [][9] output parameter to the function 
 *                                      rearrange_rows_cols function.
 * 
 * @return FALSE if the test says values are within the range [1,9]. True if 
 *          the test failed.
 *  
 */
_Bool beyond_range_2(int [][9]);
/**
 * Testing function to check the identical behaviour of the 
 * rearrange_rows_cols_function.
 * 
 * @param[in] sudoku[][9] input parameter to the function rearrange_rows_cols 
 *                          function.
 * 
 * @param[in] rearranged_sudoku [][9] output parameter to the function 
 *                                      rearrange_rows_cols function.
 *
 * @return FALSE if the test says not indentical. True if the test failed.
 *  
 */
_Bool identical_sudokus(int sudoku[][9], int rearranged_sudoku[][9]);
#endif
