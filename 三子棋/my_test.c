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
	InitBoard(board, ROW, COL);//��ʼ������
	PrintBoard(board, ROW, COL);//��ӡ����
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
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	
	do 
	{	menu();
		printf("��������룺");
		scanf("%d", &input);//���������� --->��ѭ��
		switch (input)
	{
	case 1://�п�����һ�����벻�� �����뼸��
		game();
		break;
	case 0:
		printf("�˳���Ϸ\n");
		break;
	default:
		printf("�����������������0����1\n");
		break;//��break ��ѭ��?
	}
	}while (input);
}
int main()
{
	test();
	return 0;
}