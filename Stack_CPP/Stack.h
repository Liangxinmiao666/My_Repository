#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include<iostream>

//struct Stack
//{
//	int a[N];
//	int top; // 栈顶的位置
//};

typedef int STDataType;

typedef struct Stack
{
	STDataType* a;
	int top;		// 栈顶的位置
	int capacity;	// 容量
}ST;

#ifdef __cplusplus 
	#define EXTERN_C extern "C"
#else
	#define EXTERN_C
#endif
	 

EXTERN_C void StackInit(ST* ps);
EXTERN_C void StackDestory(ST* ps);
EXTERN_C void StackPush(ST* ps, STDataType x);
EXTERN_C void StackPop(ST* ps);
EXTERN_C bool StackEmpty(ST* ps);
EXTERN_C int StackSize(ST* ps);
EXTERN_C STDataType StackTop(ST* ps);


//#ifdef __cplusplus
//extern "C"
//{
//#endif
//void StackInit(ST* ps);
//void StackDestory(ST* ps);
//void StackPush(ST* ps, STDataType x);
//void StackPop(ST* ps);
//bool StackEmpty(ST* ps);
//int StackSize(ST* ps);
//STDataType StackTop(ST* ps);
//#ifdef __cplusplus
//}
//#endif