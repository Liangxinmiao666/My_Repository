#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>

#define NAME_MAX 20
#define SEX_MAX 5
#define TEL_MAX 11
#define ADDR_MAX 15

#define CAPACITY 3

typedef struct peoinfo {
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}peoinfo;

//通讯录的结构体
typedef struct contact {
	peoinfo * data;
	int sz;
	int capacity;
}contact;
//初始化通讯表
void initcontact(contact* p);
//增加联系人
int contact_add(contact* p);
//删减联系人
void contact_del(contact* p);
//展示通讯表
void contact_show(const contact* p);
//根据人名查找
int find_byname(const contact* p,char* name);
//根据电话查找
int find_bytel(const contact* p, char* tel);
//
int Find(const contact* p);
//增容
void check_capacity(contact *p);
//销毁
void destroy_contact(contact*p);
//存储
void file_record(contact* p);
//加载数据
void Load_contact(contact*p);

