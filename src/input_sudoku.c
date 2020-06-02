#include <stdio.h>
#include <stdlib.h>

void input_sudoku(int *diff_level,int *no_sudoku);


/*
* File name: input_sudoku.c
*
* Brief: This function takes input from the user.
*
* Description: The first input asks for the difficuly level.The second input asks for the number of sudokus that user wants to generate.
*
* Warning: Do not enter any charaters or symbols because the program will crash. This bug will be solved before release 2.
*
* Author: Rishith Rao - rishithrao@cmail.carleton.ca
*
**/
void input_sudoku(int *diff_level,int *no_sudoku) { 

int i,j;
printf("....................Welcome to Sudoku Generator......................\n");
 /*This input askes for the difficulty level*/
  while(1){
    printf("Enter difficulty level as(0,1,2 or 3):\nEasy:      0\nMedium:    1\nHard:      2\nVery Hard: 3\n");
    scanf("%d", &i);
    if(i != 0 && i !=1 && i !=2 && i !=3){
              
              printf("..............Invalid input.Please try again.......................\n\n");
              } 
    else{
              
         break;
         } }
/*This input askes for the number of sudokus that a user wants to generate*/
  while(2){
    printf("Enter the number of sudokus you would like to print between 1 to 40:\n");
    scanf("%d",&j);
    if(!(j <= 40) || !(j >= 1)){                       
	    printf("................Invalid no of sudokus.Please try again...............\n\n");           
	  }

     else{
            break;
          } }
*diff_level=i;
*no_sudoku=j;
}

