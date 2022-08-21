//#define _CRT_SECURE_NO_WARNINGS 1
//#include "game.h"
//
//void InitBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			board[i][j] = ' ';
//		}
//	}
//}
//
////版本1
////void DisplayBoard(char board[ROW][COL], int row, int col)
////{
////	int i = 0;
////	int j = 0;
////	for (i = 0; i < row; i++)
////	{
////		//数据
////		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
////		//分割行
////		if(i<row-1)
////			printf("---|---|---\n");
////	}
////}
//
//
////版本2
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		//数据
//		for (j = 0; j < col; j++)
//		{
//			printf(" %c ", board[i][j]);
//			if (j < col - 1)
//				printf("|");
//		}
//		printf("\n");
//		//分割行
//		if (i < row - 1)
//		{
//			for (j = 0; j < col; j++)
//			{
//				printf("---");
//				if (j < col - 1)
//					printf("|");
//			}
//		}
//		printf("\n");
//	}
//}
//
//
////玩家下棋
//void player_move(char board[ROW][COL], int row, int col)
//{
//	printf("玩家下棋:>");
//	int x = 0;
//	int y = 0;
//
//	while (1)
//	{
//		scanf("%d %d", &x, &y);
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if (board[x - 1][y - 1] == ' ')
//			{
//				board[x - 1][y - 1] = '*';
//				break;
//			}
//			else
//			{
//				printf("该坐标被占用，请重新输入！\n");
//			}
//		}
//		else
//		{
//			printf("坐标非法，请重输入!\n");
//		}
//	}
//}
//
//
//
//void computer_move(char board[ROW][COL], int row, int col)
//{
//	int x = 0;
//	int y = 0;
//	printf("电脑下棋>\n");
//	while (1)
//	{
//		x = rand() % ROW;//0~2
//		y = rand() % COL;//0~2
//		if (board[x][y] == ' ')
//		{
//			board[x][y] = '#';
//			break;
//		}
//	}
//}
//
//int is_full(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		for (j = 0; j < col; j++)
//		{
//			if (board[i][j] == ' ')
//			{
//				return 0;
//			}
//		}
//	}
//	return 1;
//}
//
//char is_win(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	//三行
//	for (i = 0; i < row; i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
//		{
//			return board[i][1];
//		}
//	}
//	//三列
//	for (i = 0; i < col; i++)
//	{
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
//		{
//			return board[1][i];
//		}
//	}
//	//对角线的判断
//	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
//	{
//		return board[1][1];
//	}
//
//	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
//	{
//		return board[1][1];
//	}
//
//	//判断平局
//	if (1 == is_full(board, row, col))
//	{
//		return 'Q';
//	}
//	//继续
//	return 'C';
//}