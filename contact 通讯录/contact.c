#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void initcontact(contact * p)
{
	assert(p);
	p->sz = 0;
	//memset(p->data, 0, sizeof(p->data));
	peoinfo *tmp=(peoinfo*)malloc(CAPACITY * sizeof(peoinfo));
	if (tmp != NULL)
	{
		p->data = tmp;
	}
	else
	{
		printf("initcontact()::%s\n", strerror(errno));
		return;
	}
	p->capacity = CAPACITY;
	//加载信息
	Load_contact(p);

}
void check_capacity(contact *p)
{
	peoinfo* tmp=(peoinfo*)realloc(p->data, (p->capacity + 2) * sizeof(peoinfo));
	if (tmp != NULL)
	{
		p->data= tmp;
		p->capacity += 2;
		printf("增容完毕\n");
	}
	else
	{
		printf("check_capacity()::%s\n", strerror(errno));
		return;
	}
}
void destroy_contact(contact *p)
{
	assert(p);
	free(p->data);
	p->data = NULL;
	p->sz = 0;
	p->capacity = 0;
}
int contact_add(contact* p)
{
	assert(p);
	/*if (p->sz == 1000)
	{
		printf("人数满了\n");
			return 0;
	}*/
	if (p->sz == p->capacity)
	{
		check_capacity(p);
	}
	printf("姓名：");
	scanf("%s", p->data[p->sz].name);
	printf("年龄：");
	scanf("%d", &(p->data[p->sz].age));
	printf("电话：");
	scanf("%s", p->data[p->sz].tel);
	printf("地址：");
	scanf("%s", p->data[p->sz].addr);
	printf("性别：");
	scanf("%s", p->data[p->sz].sex);
	p->sz++;
	printf("增加联系人成功\n");
	return 1;
}

void contact_show(const contact* p)
{
	printf("%-10s\t%-5s\t%-13s\t%-15s\t%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
	for (int i = 0;i< p->sz; i++)
	{
		printf("%-10s\t%-5s\t%-13d\t%-15s\t%-15s\n",
			p->data[i].name , p->data[i].sex, p->data[i].age, p->data[i].tel, p->data[i].addr);
	}
}
int find_byname(const contact* p, char* name)
{
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(p->data[i].name, name) == 0)
			return i;
	}
	return -1;

}
int find_bytel(const contact* p, char* tel)
{
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		if (strcmp(p->data[i].tel, tel) == 0)
			return i;
	}
	return -1;

}
int Find(const contact* p)
{
	int a = 0;
	int i;
	int (*arr[2])(const contact*, char*) = { &find_byname,&find_bytel };
	printf("通过姓名还是电话 姓名扣0 电话扣1\n");
	scanf("%d", &a);
	if (a == 0)
	{
		char name[10];
		printf("输入姓名");
		scanf("%s", name);
		 i = (*arr[a])(p, name);//有疑问
	}
	if (a == 1)
	{
		char tel[13];
		printf("输入电话");
		scanf("%s", tel);
		i = (*arr[a])(p, tel);//有疑问
	}
	printf("%-10s\t%-5s\t%-13s\t%-15s\t%-15s\n", "姓名", "性别", "年龄", "电话", "地址");
	printf("%-10s\t%-5s\t%-13d\t%-15s\t%-15s\n",
		p->data[i].name, p->data[i].sex, p->data[i].age, p->data[i].tel, p->data[i].addr);
	return i;
}
void contact_del(contact* p)
{
	assert(p);
	char name[15];
	if (p->sz == 0)
	{
		printf("通讯录为空，删除失败");
		return ;
	}
	printf("请输入你要删除的名字");
	scanf("%s", name);
	int ret = find_byname(p, name);
	if ( ret== -1)
		printf("不存在此人\n");
	else
	{
		for (int i = ret; i < p->sz-1; i++)
		{
			p->data[i] = p->data[i + 1];
		}
		p->sz--;
	}
	
}
void file_record(contact* p)
{
	FILE* pl= fopen("contact.txt", "wb");
	if (pl == NULL)
	{
		printf("flie_record::%s\n",strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < p->sz; i++)
		fwrite(p->data + i, sizeof(peoinfo), 1, pl);
	
	fclose(pl);
	pl = NULL;
}
void Load_contact(contact* p)
{
	FILE* pr = fopen("contact.txt", "rb");
	if (pr == NULL)
	{
		printf("initcontact::%s\n", strerror(errno));
		return;
	}
	peoinfo buf = { 0 };
	while (fread(&buf, sizeof(peoinfo), 1, pr))
	{
		check_capacity(p);
		p->data[p->sz] = buf;
		p->sz++;
	}
}