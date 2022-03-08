#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROWS ROW+2
#define COLS COL+2
 
#define ROW 9
#define COL 9

#define my_count 10
void initboard(char board[ROWS][COLS],int rows,int cols,char set);//int or char

void printfboard(char board[ROWS][COLS], int row, int col);

void setmine(char board[ROWS][COLS], int row, int col);

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);



