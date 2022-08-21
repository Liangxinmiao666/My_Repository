#pragma once
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

#define ROW 3
#define COL 3

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void PrintBoard(char board[ROW][COL], int row, int col);
//����ƶ�
void player_move(char board[ROW][COL], int row, int col);
//�����ƶ�
void computer_move(char board[ROW][COL], int row, int col);
//�ж�ȫ��
int Is_Full(char board[ROW][COL], int row, int col);
//�ж���Ӯ
char Is_Win(char board[ROW][COL], int row, int col);