#define _CRT_SECURE_NO_WARNINGS 1
#include"my_game.h"



void initboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j]=set;
		}
	}
}

void printfboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= col; i++)//�к�
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)//�к�
	{
		printf("%d ", i);
		for (j = 1; j <= row; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void setmine(char mine[ROWS][COLS], int row, int col)//Ϊʲô������Դ�����Ϣ����������������
{
	//����10����
	int count = my_count;
	
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

 static int get_data(char mine[ROWS][COLS], int x, int y)//static�������ڴ��ļ���ʹ��  or ����Ҫͷ�ļ����� ��Ϊ��ͬһ���ļ�
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-my_count)
	{
	printf("������Ҫ�Ų������");
	scanf("%d %d", &x, &y);
	if (x > 0 && x <= row && y > 0 && y <= col)
	{
		if (mine[x][y] == '1')
		{
			printf("��ϲ�� ��ը����\n");
			printfboard(mine, ROW, COL);
			break;
		}
		else
		{
			show[x][y] = get_data(mine, x, y)+'0';//ת�����ַ�
			printfboard(show, ROW, COL);
			win++;
		}
	}

	if (win == row * col - my_count)
	{			
		printf("���׳ɹ�");
		printfboard(mine, ROW, COL);
	}

	}


}


