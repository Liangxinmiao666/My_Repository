#define _CRT_SECURE_NO_WARNINGS 1

#include "my_game.h"





void menu()
{
	printf("*************************\n");
	printf("*******1.play************\n");
	printf("*******2.exit************\n");
	printf("*************************\n");
}


void game()
{
	//创建数组
	char mine[ROWS][COLS] = { 0 };//存放布置好的的雷的信息
	char show[ROWS][COLS] = { 0 };//存放排查出的雷的信息
	//初始化数组
	initboard(mine, ROWS, COLS,'0');//全是'0'
	initboard(show, ROWS, COLS,'*');//全是'*'
	//打印
	//printfboard(mine, ROW, COL);
	printfboard(show, ROW, COL);
	//布置雷
	setmine(mine, ROW, COL);
	printfboard(mine, ROW, COL);
	//printfboard(show, ROW, COL);
	//排雷
	findmine(mine,show,ROW,COL);





}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {                                                                                                     
		menu();
		printf("请输入");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}





