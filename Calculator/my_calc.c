#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"My_Stack.h"



bool check_brackets(char* str);//检查括号是否匹配
bool Sign_compare(char top, char cur_sign);
int find_elem(char c, char* arr);//从给定数组中查找给定字符                  
void calculate_data_stack(ST* d_st, ST* s_st);


float calc(char* str);

float add(float, float);                                                      
float sub(float, float);                                                     
float mul(float, float);                                                     
float dive(float, float);                                                     



char Brackets[20] = { "()[]"};
char Sign[20] = { "+-*/" };
//float (*operfuncp[10])(float,float)={add,sub,mul,dive,squ,l};
typedef float (*FP)(float, float);
FP operfuncp[4] = { add,sub,mul,dive};

//打表 用于运算符比较  
// 返回值 true--top优先高 得先计算栈里数据
// 返回值 false--top优先级低 直接入栈
bool Sign_compare(char top,char cur_sign)
{
	if (top == '*' || top == '/')
	{
		switch (cur_sign)
		{
		case '+':
			return true;
		case '-':
			return true;
		default:
			return false;
		}
	}
	if (top == '+' || top == '-')
	{
		return false;
	}
	if (top == '(' )
	{
		return false;
	}
}


bool check_brackets(char* str)
{
	int i=0,index;
	ST st;
	StackInit(&st);
	while (str[i])
	{
		if (str[i] == '(' || str[i] =='{')
		{
			StackPush(&st,str[i]);
		}
		else if((str[i] == ')' && StackTop(&st) =='(') || (str[i] == '}' && StackTop(&st) == '{'))
		{
			StackPop(&st);	//没有先压'#' 因为pop里有assert(ps->top > 0);
		}	
		i++;
	}
	if (!StackEmpty(&st))
	{
		return false;
	}
	return true;
}


int find_elem(char c,char *arr) //从给定数组中查找给定字符                  
{   int i=0;
    while(arr[i]) 
    { if(c==arr[i]) return i;
      i++;
	}
    return -1;
}


//计算栈中数据
void calculate_data_stack(ST* dd_st,ST* ss_st)
{
	if (!StackEmpty(ss_st))
	{
		float right = StackTop(dd_st);
		StackPop(dd_st);
		float left = StackTop(dd_st);
		StackPop(dd_st);

		char cur_sign = StackTop(ss_st);
		StackPop(ss_st);

		float newnum=0;

		for (int i = 0; i < 4; i++)
		{
			if (cur_sign == Sign[i])
			{
				StackPush(dd_st, operfuncp[i](left, right));//容易写反
				//问题来了 如何迭代起来
				if(!StackEmpty(ss_st)&&(StackTop(ss_st)!='('&&StackTop(ss_st)!='{'))
				calculate_data_stack(dd_st, ss_st);
			}
		}

	}
	else
		return;

}



float calc(char* str)
{
	ST d_st;
	ST s_st;
	int n = strlen(str);
	int num = 0;
	int i = 0;
	StackInit(&d_st);
	StackInit(&s_st);
	//StackPush(&s_st, '#');
	while(i<n)
	{
		num = 0;
		while ((str[i]<='9'&&str[i]>='0'))//处理数字
		{
			num = num * 10 + (int)(str[i] - '0');//整形溢出问题？？？
			
			if (!(str[i + 1] <= '9' && str[i + 1] >= '0'))
				StackPush(&d_st, num);

			i++;
		}
		if(find_elem(str[i],Sign)!=-1)//处理运算符
		{
			if (StackEmpty(&s_st))//第一个符号
			{
				StackPush(&s_st, str[i]);
				i++;
			}
			else 
			{
				char top = StackTop(&s_st);//非空
				char cur_sign = str[i];
				if (!Sign_compare(top, cur_sign))
				{
					StackPush(&s_st, cur_sign);
					i++;
				}
				else
				{
					//处理数字栈中的数据
					calculate_data_stack(&d_st, &s_st);
				}
			}
			
		}
		if(str[i]=='('||str[i]==')'||str[i]=='['||str[i]==']')//处理括号
		{
			if (str[i] == '(' || str[i] == '[')
			{
				StackPush(&s_st, str[i]);
				i++;
			}

			if (str[i] == ')' || str[i] == '}')
			{
				float right = StackTop(&d_st);
				StackPop(&d_st);
				float left = StackTop(&d_st);
				StackPop(&d_st);

				char cur_sign = StackTop(&s_st);
				StackPop(&s_st);

				float newnum = 0;

				for (int i = 0; i < 4; i++)
				{
					if (cur_sign == Sign[i])
					{
						StackPush(&d_st, operfuncp[i](left, right));//容易写反
						//问题来了 如何迭代起来
						//if(!StackEmpty(ss_st))
						//calculate_data_stack(&d_st, &s_st);
						break;
					}
				}
				if(StackTop(&s_st)=='('||StackTop(&s_st)=='{')
				StackPop(&s_st);
				i++;
			}
			
		}

		
	}
	calculate_data_stack(&d_st, &s_st);
	return StackTop(&d_st);
}


float add(float f1, float f2)                                                  
{
	return f1 + f2;
}
float sub(float f1, float f2)                                                  
{
	return f1 - f2;
}
float mul(float f1, float f2)                                                  
{
	return f1 * f2;
}
float dive(float f1, float f2)                                                
{
	return f1 / f2;
}


int main()
{
	char str[20];
	gets(str);
	if (!check_brackets(str))
	{
		printf("括号匹配错误\n");
		return 0;
	}
	printf("%f\n",calc(str));

	return 0;
}