/*
* TITLE      : output_sudoku_test.c 
*
* Purpose   : Test the output_sudoku.c file functions. 
*
*             Becasue the function output_sudoku() mainly calls the 
*             create_sudoku_file() function, it would be redundant to test output_sudoku().
*             As such, the create_sudoku_file() was the only function that was tested.
*
* Language  : C
*
* Author    : Mathieu Falardeau 101173923, 
* GitHub ID : Mathieufalardeau3 
* Date      : 30 May 2020
*
**/

#include "..\\..\\include\\sudoku.h"
#include "..\\include\\output_sudoku_test.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(void){
    
    int pass = 21; 
    char* log_location = "../log/output_sudoku_result.log";
    FILE *log = fopen(log_location, "w");
    
    fprintf(log,"         OUTPUT SUDOKU TESTING RESULT\n"
            "       -------------------------------------\n");

    /*Tests to run*/
    if(!create_sudoku_file_test_sudoku_1()){
        fputs("-Sudoku output test create_sudoku_file_test_sudoku_1() has \n" 
        "  failed. The value was not properly written in the file\n",log);
        pass--;
    }
    
    if(!create_sudoku_file_test_sudoku_2()){
        fputs("-Sudoku output test create_sudoku_file_test_sudoku_2() has \n" 
        "    failed. The value was not properly written in the file\n",log);
        pass--;
    }
    if(!create_sudoku_file_test_sudoku_3()){
        fputs("-Sudoku output test create_sudoku_file_test_sudoku_3() has \n" 
        "    failed. The value -1 was not properly, written in the file\n",log);
        pass--;
    }
    if(!create_sudoku_file_test_sudoku_4()){
        fputs("-Sudoku output test create_sudoku_file_test_sudoku_4() has \n" 
        "    failed. The value 10 was not properly written in the file\n",log);
        pass--;
    }

    if(!create_sudoku_file_test_sudoku_5()){
        fputs("-Sudoku output test create_sudoku_file_test_sudoku_5() has \n" 
        "    failed. The array 9x8 was not properly written in the file\n",log);
        pass--;
    }

    if(!create_sudoku_file_test_sudoku_6()){
        fputs("-Sudoku output test create_sudoku_file_test_sudoku_6() has \n" 
        "    failed. The array 8x9 was not properly written in the file\n",log);
        pass--;
    }

    if(!create_sudoku_file_test_sudoku_type_1()){
        fputs("-Sudoku output test create_sudoku_file_test_sudoku_type_1() has \n" 
        "    failed. The five char sudoku_type string was not properly written.\n",log);
        pass--;
    }
    
    if(!create_sudoku_file_test_sudoku_type_2()){
        fputs("-Sudoku output test create_sudoku_file_test_sudoku_type_2() has \n" 
        "    failed. The six char sudoku_type string was not properly written.\n",log);
        pass--;
    }
    
    if(!create_sudoku_file_test_sudoku_type_3()){
        fputs("-Sudoku output test create_sudoku_file_test_sudoku_type_3() has \n" 
        "    failed. The seven char sudoku_type string was not properly written.\n",log);
        pass--;
    }

    if(!create_sudoku_file_test_diff_lvl_1()){
        fputs("-Sudoku output test create_sudoku_file_test_diff_lvl_1() has \n" 
        "    failed. The difficulty level \"_easy_\" was not properly written.\n",log);
        pass--;
    }
    
    if(!create_sudoku_file_test_diff_lvl_2()){
        fputs("-Sudoku output test create_sudoku_file_test_diff_lvl_2() has \n" 
        "    failed. The difficulty level \"_normal_\" was not properly written.\n",log);
        pass--;
    }

    if(!create_sudoku_file_test_diff_lvl_3()){
        fputs("-Sudoku output test create_sudoku_file_test_diff_lvl_3() has \n" 
        "    failed. The difficulty level \"_hard_\" was not properly written.\n",log);
        pass--;
    }

    if(!create_sudoku_file_test_diff_lvl_4()){
        fputs("-Sudoku output test create_sudoku_file_test_diff_lvl_4() has \n" 
        "    failed. The difficulty level \"_very_hard_\" was not properly written.\n",log);
        pass--;
    }

    if(!create_sudoku_file_test_diff_lvl_5()){
        fputs("-Sudoku output test create_sudoku_file_test_diff_lvl_5() has \n" 
        "    failed. The difficulty level \"_error_\" was not properly written.\n",log);
        pass--;
    }
    
    if(!create_sudoku_file_test_diff_lvl_6()){
        fputs("-Sudoku output test create_sudoku_file_test_diff_lvl_6() has \n" 
        "    failed. The difficulty level \"_error_\" was not properly written.\n",log);
        pass--;
    }

    if(!create_sudoku_file_test_output_count_1()){
        fputs("-Sudoku output test create_sudoku_file_test_output_count_1() has \n" 
        "    failed. The output count \"0\" was not properly written.\n",log);
        pass--;
    };

    if(!create_sudoku_file_test_output_count_2()){
        fputs("-Sudoku output test create_sudoku_file_test_output_count_2() has \n" 
        "    failed. The output count \"999\" was not properly written.\n",log);
        pass--;
    };

    if(!create_sudoku_file_test_output_count_3()){
        fputs("-Sudoku output test create_sudoku_file_test_output_count_3() has \n" 
        "    failed. The output count \"-99\" was not properly written.\n",log);
        pass--;
    };

    if(!create_sudoku_file_test_output_count_4()){
        fputs("-Sudoku output test create_sudoku_file_test_output_count_4() has \n" 
        "    failed. The output count \"1000\" was not properly written.\n",log);
        pass--;
    };

    if(!create_sudoku_file_test_output_count_5()){
        fputs("-Sudoku output test create_sudoku_file_test_output_count_5() has \n" 
        "    failed. The output count \"-999\" was not properly written.\n",log);
        pass--;
    };

    if(!output_sudoku_test_count()){
        fputs("-Sudoku output test output_sudoku_test_count_() has \n" 
        "    failed. The count was not properly tracked.\n",log);
        pass--;
    };
    
    /*Number of tests that have passed.*/
    fprintf(log,"Successful sudoku_output Tests: %d/21\n",pass);
    
    /*If all tests have passed.*/
    if(pass == 21){
        fprintf(log,"All tests have passed!!\n");
    }

    fclose(log);
    return 0;
}

/**
 * Sudoku Test #1
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_1(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test_normal_1.csv";
    
    /*Verifies the result of the test*/
    return verify_sudoku_file(sudoku,"test",1,1,location);
}

/**
 * Sudoku Test #2
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_2(void){
    /*Variables*/
    int sudoku[9][9] = {{1,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test_normal_1.csv";
    
    /*Verifies the result of the test*/
    return verify_sudoku_file(sudoku,"test",1,1,location);  
}

/**
 * Sudoku Test #3
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_3(void){
    /*Variables*/
    int sudoku[9][9] = {{-1,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,-1,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,-1.1,2,3,4},
                        {6,7,8,-1,1,0,3,0,5},
                        {7,8,-1,1,2,3,4,5,6},
                        {8,-1,1,2,0,4,5,6,7},
                        {9,-1,0,3,0,-1,0,7,8}};

    char* location = "../output/sudoku_test_normal_1.csv";
    
     /*Verifies the result of the test*/
    return verify_sudoku_file(sudoku,"test",1,1,location);    
}

/**
 * Sudoku Test #4
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_4(void){
    /*Variables*/
    int sudoku[9][9] = {{10,3,3,4,5,6,7,8,9},
                        {2,3,10,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,10,0,3},
                        {5,0,7,0,9,10,2,3,4},
                        {6,7,8,9,1,0,3,10,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,10,4,5,6,7},
                        {9,10,10,3,10,5,0,7,8}};

    char* location = "../output/sudoku_test_normal_1.csv";
    
     /*Verifies the result of the test*/
    return verify_sudoku_file(sudoku,"test",1,1,location);     
}

/**
 * Sudoku Test #5
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_5(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8},
                        {2,3,0,5,6,7,8,9},
                        {3,4,5,6,0,8,9,1},
                        {4,5,6,7,8,9,1,0},
                        {5,0,7,0,9,1,2,3},
                        {6,7,8,9,1,0,3,0},
                        {7,8,0,1,2,3,4,5},
                        {8,0,1,2,0,4,5,6},
                        {9,1,0,3,0,5,0,7}};

    char* location = "../output/sudoku_test_normal_1.csv";
    
     /*Verifies the result of the test*/
    return verify_sudoku_file(sudoku,"test",1,1,location);    
}

/**
 * Sudoku Test #6
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_6(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,7},
                        {3,4,5,6,0,8,9,1,7},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test_normal_1.csv";
        
    /*Verifies the result of the test*/
    return verify_sudoku_file(sudoku,"test",1,1,location);    
}

/**
 * Sudoku Type Test #1
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_type_1(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* place = "../output/sudoku_test0_normal_2.csv";
    /*Using function to be tested*/
    return verify_sudoku_file_name(sudoku, "test0", 1, 2, place);
}

/**
 * Sudoku Type Test #2
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_type_2(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test12_normal_1.csv";
    
    /*Using function to be tested*/
    return verify_sudoku_file_name(sudoku,"test12",1,1, location);
}

/**
 * Sudoku Type Test #3
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_sudoku_type_3(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test12_normal_2.csv";
    
    /*Using function to be tested*/
    return verify_sudoku_file_name(sudoku,"test123",1,2, location);
}

/**
 * Difficulty level Test #1
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_diff_lvl_1(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test00_easy_1.csv";
    
    /*Using function to be tested*/
    return verify_sudoku_file_name(sudoku,"test00",0,1, location);
}

/**
 * Difficulty level Test #2
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_diff_lvl_2(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test00_normal_1.csv";
    
    /*Using function to be tested*/
    return verify_sudoku_file_name(sudoku,"test00",1,1, location);
}

/**
 * Difficulty level Test #3
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_diff_lvl_3(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test00_hard_1.csv";
    
    /*Using function to be tested*/
    return verify_sudoku_file_name(sudoku,"test00",2,1, location);
}

/**
 * Difficulty level Test #4
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_diff_lvl_4(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test00_very_hard_1.csv";

    /*Using function to be tested*/
    return verify_sudoku_file_name(sudoku,"test00",3,1, location);
}

/**
 * Difficulty level Test #5
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_diff_lvl_5(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test00_error_1.csv";
        
    /*Using function to be tested*/
    return verify_sudoku_file_name(sudoku,"test00",-1,1, location);
}

/**
 * Difficulty level Test #6
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_diff_lvl_6(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test01_error_1.csv";
    
    /*Using function to be tested*/
    return verify_sudoku_file_name(sudoku,"test01",4,1, location);
}

/**
 * Output Count Test #1
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_output_count_1(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test02_easy_0.csv";
    
    /*Using function to be tested*/
    return verify_sudoku_file_name(sudoku,"test02",0,0, location);
}

/**
 * Output Count Test #2
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_output_count_2(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test02_easy_999.csv";
    
    /*Using function to be tested*/
    return verify_sudoku_file_name(sudoku,"test02",0,999, location);
}

/**
 * Output Count Test #3
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_output_count_3(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test02_easy_-99.csv";
        
    /*Using function to be tested*/
    return verify_sudoku_file_name(sudoku,"test02",0,-99, location);
}

/**
 * Output Count Test #4
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_output_count_4(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test03_easy_0.csv";

    return verify_sudoku_file_name(sudoku,"test03",0,1000, location);
}

/**
 * Output Count Test #5
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool create_sudoku_file_test_output_count_5(void){
    /*Variables*/
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location = "../output/sudoku_test04_easy_0.csv";
    
    return verify_sudoku_file_name(sudoku, "test04", 0, -999, location);
    
}

/**
 * General function to compare the contents between the array and the file.
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool verify_sudoku_file(int sudoku[][9], char *type, int diff_lvl, int count, 
                            char* location){
    /*Variable*/
    int value;
    _Bool result;
    FILE *sudoku_file;
    
    create_sudoku_file(sudoku, type, diff_lvl, count);

    /*Opening the file to read*/
    sudoku_file = fopen(location, "r");
    if(sudoku_file==NULL){
        printf("The file did not open\n");
    }

    /*Compare each element of the array with the value in the file*/
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            /*If the values read are not the same, then the function returns 
            FALSE*/
            
            value = fgetc(sudoku_file);
            if((value != ('0' + sudoku[i][j]) ) && (value != ' ')){
                
                fclose(sudoku_file);
                return 0;
            }
            value = fgetc(sudoku_file);
            if(value != ',' && value != '\n'){
                fclose(sudoku_file);
                return 0;
            }
        }
    }
    /*If the file passes, the the function eturns true*/
    fclose(sudoku_file);
    
    return 1;
}
/**
 * General function to verify the validity of the file location.
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool verify_sudoku_file_name(int sudoku[9][9], char* type, int diff_lvl, 
                                int count, char* location){
    FILE *file;

    /*Using function to be tested*/
    create_sudoku_file(sudoku, type, diff_lvl, count);
    file = fopen(location,"r");
    
    /*Verifies the result of the test*/
    if(file==NULL){
        printf(location);
        return 0;
    } 
    else{
        fclose(file);
        return 1;
        }
}

/**
 * Internal Static Count 
 * 
 * @return FALSE if the test has failed. True if the test passed.
 *  
 */
_Bool output_sudoku_test_count(void){
    
    FILE *file1;
    FILE *file2;
    int result;
    int sudoku[9][9] = {{0,3,3,4,5,6,7,8,9},
                        {2,3,0,5,6,7,8,9,1},
                        {3,4,5,6,0,8,9,1,2},
                        {4,5,6,7,8,9,1,0,3},
                        {5,0,7,0,9,1,2,3,4},
                        {6,7,8,9,1,0,3,0,5},
                        {7,8,0,1,2,3,4,5,6},
                        {8,0,1,2,0,4,5,6,7},
                        {9,1,0,3,0,5,0,7,8}};

    char* location1 = "../output/sudoku_puzzle_easy_1.csv";
    char* location2= "../output/sudoku_puzzle_easy_2.csv";

    /*Using function to be tested*/
    output_sudoku(sudoku, sudoku, 0);
    output_sudoku(sudoku, sudoku, 0);

    file1 = fopen(location1,"r");
    file2 = fopen(location2,"r");

    /*Verifies the result of the test*/
    if(file1 == NULL || file2 == NULL){
        result = 0;
    }else{
        result = 1;
    }
        
    fclose(file1);
    fclose(file2);
    return result;
}


