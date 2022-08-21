#define _CRT_SECURE_NO_WARNINGS 1
#include "my_game.h"


void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);//数据
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");//分割行
				if (j < col - 1)//疑问 上面的都写了为啥再写一遍
					printf("|");
			}	
		}
		printf("\n");
	}
}

void player_move(char board[ROW][COL], int row, int col)
{
	printf("玩家下棋>");
	while (1)
	{
		int x = 0;
		int y = 0;
		scanf("%d %d",&x,&y);//返回值忽略
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该坐标已被占用\n");
		}
		else
			printf("坐标非法，请重新输入\n");
	}
}

void computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑下棋>\n");
	srand((unsigned int) time(NULL));//NULL  (unsigned int )
	while (1)
	{
		x = rand() % row;//0~2
		y = rand() % col;//0~2
		if (board[x][y] == ' ')//why 可以等于字符
		{
			board[x][y] = '#'; 
				break;
		}
	}
}

int Is_Full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char Is_Win(char board[ROW][COL], int row, int col)
{
//{
	int i = 0;
	int j = 0;
//	//三行
//	for (i = 0; i < row; i++)         //改进不成功..............
//	{
//		for (j = 0; j < col - 1; j++);
//		{
//			if (board[i][j] == board[i][j + 1])
//			{
//				if (j == col - 2)
//					return board[i][j];
//				continue;
//			}
//		}
//	}
//	//三列
//	for (j = 0; j < col; j++)
//	{
//		for (i = 0; i < row - 1; i++)
//		{
//			if (board[i][j] == board[i + 1][j])
//			{
//				if (i == row - 2)
//					return board[i][j];
//				continue;
//			}
//		}
//
//		//对角线 左上---右下
//		while (board[i][j] == board[i + 1][j + 1])
//		{
//			if (board[row - 2][col - 2] == board[row - 1][col - 1])
//			{
//				return board[i][j];
//			}
//			i++;
//			j++;
//
//		}
//		//对角线 右上----左下
//		int k = col - 1;
//		while (board[i][k] == board[i + 1][k - 1])
//		{
//			return board[i][k];
//		}
//		i++;
//		k--;
//
//	}
//	//平局
//	if (1 == Is_Full(board, row, col))
//	{
//		{
//			return 'Q';
//
//		}
//		return 'C';
//	}
	for (i = 0; i < row; i++)
	{
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			{
				return board[i][1];
			}
		}
		//三列
		for (i = 0; i < col; i++)
		{
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			{
				return board[1][i];
			}
		}
		//对角线的判断
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		{
			return board[1][1];
		}

		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		{
			return board[1][1];
		}

		//判断平局
		if (1 == Is_Full(board, row, col))
		{
			return 'Q';
		}
		//继续
		return 'C';
	}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

























