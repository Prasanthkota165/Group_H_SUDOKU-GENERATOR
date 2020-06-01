#include <stdio.h>
#include <stdlib.h>

void input_sudoku(int arr[2]);


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
void input_sudoku(int arr[2]) { 
{
  int diff_level,no_sudoku;
 /*This input askes for the difficulty level*/
  while(1){
    printf("Enter difficulty level as(0,1,2 or 3):\nEasy:      0\nMedium:    1\nHard:      2\nVery Hard: 3\n");
    scanf("%d", &diff_level);
    if (diff_level != 0 && diff_level !=1 && diff_level !=2 && diff_level !=3) 
            {
              
              printf("..............Invalid input.Please try again.......................\n\n");
            } 

    else    {
              
              break;
            }

  }
/*This input askes for the number of sudokus that a user wants to generate*/
  while(2)
  {
    printf("Enter the number of sudokus you would like to print between 1 to 40:\n");
    scanf("%d",&no_sudoku);
    if(!(no_sudoku <= 40) || !(no_sudoku >= 1)) 
          {                       
	    printf("................Invalid no of sudokus.Please try again...............\n\n");           
	  }

     else {
            break;
          }

  }
 arr[0]= diff_level;
 arr[1]= no_sudoku;
}}


