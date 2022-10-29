#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"My_Stack.h"



bool check_brackets(char* str);//��������Ƿ�ƥ��
bool Sign_compare(char top, char cur_sign);
int find_elem(char c, char* arr);//�Ӹ��������в��Ҹ����ַ�                  
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

//��� ����������Ƚ�  
// ����ֵ true--top���ȸ� ���ȼ���ջ������
// ����ֵ false--top���ȼ��� ֱ����ջ
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
			StackPop(&st);	//û����ѹ'#' ��Ϊpop����assert(ps->top > 0);
		}	
		i++;
	}
	if (!StackEmpty(&st))
	{
		return false;
	}
	return true;
}


int find_elem(char c,char *arr) //�Ӹ��������в��Ҹ����ַ�                  
{   int i=0;
    while(arr[i]) 
    { if(c==arr[i]) return i;
      i++;
	}
    return -1;
}


//����ջ������
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
				StackPush(dd_st, operfuncp[i](left, right));//����д��
				//�������� ��ε�������
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
		while ((str[i]<='9'&&str[i]>='0'))//��������
		{
			num = num * 10 + (int)(str[i] - '0');//����������⣿����
			
			if (!(str[i + 1] <= '9' && str[i + 1] >= '0'))
				StackPush(&d_st, num);

			i++;
		}
		if(find_elem(str[i],Sign)!=-1)//���������
		{
			if (StackEmpty(&s_st))//��һ������
			{
				StackPush(&s_st, str[i]);
				i++;
			}
			else 
			{
				char top = StackTop(&s_st);//�ǿ�
				char cur_sign = str[i];
				if (!Sign_compare(top, cur_sign))
				{
					StackPush(&s_st, cur_sign);
					i++;
				}
				else
				{
					//��������ջ�е�����
					calculate_data_stack(&d_st, &s_st);
				}
			}
			
		}
		if(str[i]=='('||str[i]==')'||str[i]=='['||str[i]==']')//��������
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
						StackPush(&d_st, operfuncp[i](left, right));//����д��
						//�������� ��ε�������
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
		printf("����ƥ�����\n");
		return 0;
	}
	printf("%f\n",calc(str));

	return 0;
}