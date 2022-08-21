#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void TestList1()
{
	//LTNode* pList = NULL;
	//ListInit(&pList);
	LTNode* pList = ListInit();
	ListPushBack(pList, 1);
	ListPushBack(pList, 2);
	ListPushBack(pList, 3);
	ListPushBack(pList, 4);
	ListPushBack(pList, 5);
	ListPushBack(pList, 6);
	ListPrint(pList);

	ListPopBack(pList);
	ListPopBack(pList);
	ListPopBack(pList);
	ListPopBack(pList);
	ListPopBack(pList);
	ListPopBack(pList);
	//ListPopBack(pList);
	ListPrint(pList);
}

void TestList2()
{
	//LTNode* pList = NULL;
	//ListInit(&pList);
	LTNode* pList = ListInit();
	ListPushBack(pList, 1);
	ListPushBack(pList, 2);
	ListPushBack(pList, 3);
	ListPushBack(pList, 4);
	ListPushBack(pList, 5);
	ListPushBack(pList, 6);
	ListPrint(pList);

	LTNode* pos = ListFind(pList, 3);
	if (pos)
	{
		ListInsert(pos, 30);
	}
	ListPrint(pList);
}

void TestList3()
{
	LTNode* pList = ListInit();
	ListPushBack(pList, 1);
	ListPushBack(pList, 2);
	ListPushBack(pList, 3);
	ListPushBack(pList, 4);
	ListPushBack(pList, 5);
	ListPushBack(pList, 6);
	ListPrint(pList);

	LTNode* pos = ListFind(pList, 3);
	if (pos)
	{
		//ListErase(NULL);
		ListErase(pos);
		pos = NULL;
	}
	ListPrint(pList);

	//ListErase(pList);
	//ListPrint(pList);
}

void TestList4()
{
	LTNode* pList = ListInit();
	ListPushBack(pList, 1);
	ListPushBack(pList, 2);
	ListPushBack(pList, 3);
	ListPushBack(pList, 4);
	ListPushBack(pList, 5);
	ListPushBack(pList, 6);
	ListPrint(pList);

	ListPushFront(pList, 0);
	ListPushFront(pList, -1);
	ListPushFront(pList, -2);
	ListPrint(pList);

	ListPopBack(pList);
	ListPopBack(pList);
	ListPopBack(pList);
	ListPrint(pList);

	ListPopFront(pList);
	ListPopFront(pList);
	ListPopFront(pList);
	ListPrint(pList);

	ListDestory(pList);
	pList = NULL;
}

int main()
{
	TestList3();

	return 0;
}