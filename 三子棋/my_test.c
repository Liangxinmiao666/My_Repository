#define _CRT_SECURE_NO_WARNINGS 1
#include "my_game.h"
void menu()
{
	printf("********************\n");
	printf("*******1.play*******\n");
	printf("*******0.exit*******\n");
	printf("********************\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);//初始化棋盘
	PrintBoard(board, ROW, COL);//打印棋盘
	char ret = 0;
	while (1)
	{
		player_move(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = Is_Win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		computer_move(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		ret = Is_Win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("you are winner.\n");
	}
	if (ret == '#')
	{
		printf("compute is winner.\n");
	}
	if (ret == 'Q')
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	
	do 
	{	menu();
		printf("请玩家输入：");
		scanf("%d", &input);//定义在外面 --->死循环
		switch (input)
	{
	case 1://有可能有一边输入不对 多输入几遍
		game();
		break;
	case 0:
		printf("退出游戏\n");
		break;
	default:
		printf("输入错误，请重新输入0或者1\n");
		break;//无break 死循环?
	}
	}while (input);
}
int main()
{
	test();
	return 0;
}