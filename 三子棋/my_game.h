#pragma once
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

#define ROW 3
#define COL 3

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
void PrintBoard(char board[ROW][COL], int row, int col);
//玩家移动
void player_move(char board[ROW][COL], int row, int col);
//电脑移动
void computer_move(char board[ROW][COL], int row, int col);
//判断全满
int Is_Full(char board[ROW][COL], int row, int col);
//判断输赢
char Is_Win(char board[ROW][COL], int row, int col);