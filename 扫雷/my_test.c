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
	//��������
	char mine[ROWS][COLS] = { 0 };//��Ų��úõĵ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };//����Ų�����׵���Ϣ
	//��ʼ������
	initboard(mine, ROWS, COLS,'0');//ȫ��'0'
	initboard(show, ROWS, COLS,'*');//ȫ��'*'
	//��ӡ
	//printfboard(mine, ROW, COL);
	printfboard(show, ROW, COL);
	//������
	setmine(mine, ROW, COL);
	printfboard(mine, ROW, COL);
	//printfboard(show, ROW, COL);
	//����
	findmine(mine,show,ROW,COL);





}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do {                                                                                                     
		menu();
		printf("������");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������\n");
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}





