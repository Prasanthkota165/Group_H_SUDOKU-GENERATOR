/**
 * @file test_sudoku.c
 *
 * Purpose  : This function tests whether the regenerated sudoku meets all the sudoku rules or not .
 *
 * Language : C
 *
 * Author   : Rishith Rao - rishithrao@cmail.carleton.ca
 *            Prasanth Kota - prasanthkota@cmail.carleton.ca
 *
 * Date     : 13 June, 2020.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/sudoku.h"

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

/**
 * Deletes the first element of the array.
 */
struct node* deleteFirst() {
    struct node *tempLink = head;/*save reference to first link*/
    head = head->next;/*mark next to first link as first*/
    return tempLink;/*return the deleted link*/
}

/**
 * Checks whether the list is empty or not.
 */
bool isEmpty() {
    return head == NULL;
}

/**
 * Insert link at the first location.
 */
void insertFirst(int data){
    struct node *link = (struct node*) malloc(sizeof(struct node));/*create a link*/
    link->data = data;
    link->next = head;/*point it to old first node*/
    head = link;/*point first to new first node*/
}

/**
 * Delete a link with given data
 */
struct node* delete(int data) {
    struct node* current = head;/*start from the first link*/
    struct node* previous = NULL;
    if(head == NULL){/*if list is empty*/
        return NULL;
    }
    while(current->data != data){/*navigate through list*/
        if(current->next == NULL) {/*if it is last node*/
            return NULL;
        }else {
             previous = current;/*store reference to current link*/
             current = current->next;/*move to next link*/
         }
    }
    if(current == head){/*found a match, update the link*/
        head = head->next;/*change first to point to next link*/
    }else {
        previous->next = current->next;/*bypass the current link*/
     }    
    return current;
}

/*
 *This checks the 3X3 blocks for repeated values.
 */
_Bool test_3X3(int rearranged_sudoku[][9]) {
    int z[9][9];  
    int x=0,y=2,sum=0,k=0,l=2,a,sumplus=0;
    int flag=0;
    while(x<=8) {
        while(k<=8) {
            for (int i=x;i<=y;i++) {
                for(int j=k;j<=l;j++) {
   		    a=rearranged_sudoku[i][j];
   		    sum=sum+a;
                    delete(a);
                }
            }
            k=k+3;
            l=l+3;
            sumplus=sum;
            while(!isEmpty() || sumplus!=45) {/*checks whether the array is empty or not. If not it empties the array for furthur operation.*/
                flag=true;  
                sumplus=45;        
                struct node *temp = deleteFirst();
            }  
            sum=0;
    	    insertFirst(1);
            insertFirst(2);
            insertFirst(3);
            insertFirst(4);
            insertFirst(5);
            insertFirst(6);
            insertFirst(7);
            insertFirst(8);
            insertFirst(9);
        }
        k=0;
        l=2;
        x=x+3;
        y=y+3;
    }
    return flag;
}

/**
 * This function checks the rows, columns and 3X3 matrix for sudoku rules.
 */
_Bool test_sudoku_rules(int rearranged_sudoku[][9]) {  
    test_3X3(rearranged_sudoku);
    if(test_3X3(rearranged_sudoku)){
        return true;
    }else {
         return false;
     } 
}


