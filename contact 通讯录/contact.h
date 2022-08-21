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

//ͨѶ¼�Ľṹ��
typedef struct contact {
	peoinfo * data;
	int sz;
	int capacity;
}contact;
//��ʼ��ͨѶ��
void initcontact(contact* p);
//������ϵ��
int contact_add(contact* p);
//ɾ����ϵ��
void contact_del(contact* p);
//չʾͨѶ��
void contact_show(const contact* p);
//������������
int find_byname(const contact* p,char* name);
//���ݵ绰����
int find_bytel(const contact* p, char* tel);
//
int Find(const contact* p);
//����
void check_capacity(contact *p);
//����
void destroy_contact(contact*p);
//�洢
void file_record(contact* p);
//��������
void Load_contact(contact*p);

