#if defined(_WIN32)||defined (WIN32) //<Define if Microsoft OS                           
#include "..\\include\\sudoku.h"
#else //Define if Linux OS*/ 
#include "../include/sudoku.h"
#endif

#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define TRUE 1
#define FALSE 0
#define N 9 

void printGrid(int grid[N][N]);
 
  
/* Driver Program to test above functions */
int main() 
{ 
    // 0 means unassigned cells 
    
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    if (solver_sudoku(grid)){ 
        printGrid(grid); 
    }
    else{
        printf("No solution exists"); 
    }
	
    return 0; 
} 

/* A utility function to print grid  */
void printGrid(int grid[N][N]) 
{ 
    for (int row = 0; row < N; row++) { 
        for (int col = 0; col < N; col++) 
            printf("%2d", grid[row][col]); 
        printf("\n"); 
    } 
}
