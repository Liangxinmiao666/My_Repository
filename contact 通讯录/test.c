#define _CRT_SECURE_NO_WARNINGS 1
//通讯录：
//1. 可以存放1000个人的信息
//2. 人的信息：名字，年龄，电话，住址，性别
//3. 增加联系人
//4. 删除联系人
//5. 查找联系人
//6. 修改联系人
//7. 排序（名字 / 年龄）
#include"contact.h"
enum option
{
	EXIT,
	ADD,
	DEL,
	SERCH,
	MODIFY,
	SORT,
	SHOW

};
void menu()
{
	printf("******1.add       2.del       *******\n");
	printf("******3.serch     4.modify    *******\n");
	printf("******5.sort      6.show      *******\n");
	printf("******0.exit                  *******\n");
}
int main()
{
	int intput = 0;
	contact con = { 0 };
	//初始化通讯录
	initcontact(&con);
	do {
		menu();
		printf("请输入");
		scanf("%d", &intput);
		switch (intput)
		{
		case ADD:
			contact_add(&con);
			break;
		case DEL:
			contact_del(&con);
			break;
		case SERCH:
			Find(&con);
			break;
		case MODIFY:
			break;
		case SORT:
			break;
		case SHOW:
			contact_show(&con);
			break;
		case EXIT:
			//存储到文件
			file_record(&con);
			destroy_contact(&con);
			printf("退出通讯录");
			break;
		default:
			printf("输入错误");
			break;

		}
	} while (intput);



	return 0;
}