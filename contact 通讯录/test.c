#define _CRT_SECURE_NO_WARNINGS 1
//ͨѶ¼��
//1. ���Դ��1000���˵���Ϣ
//2. �˵���Ϣ�����֣����䣬�绰��סַ���Ա�
//3. ������ϵ��
//4. ɾ����ϵ��
//5. ������ϵ��
//6. �޸���ϵ��
//7. �������� / ���䣩
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
	//��ʼ��ͨѶ¼
	initcontact(&con);
	do {
		menu();
		printf("������");
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
			//�洢���ļ�
			file_record(&con);
			destroy_contact(&con);
			printf("�˳�ͨѶ¼");
			break;
		default:
			printf("�������");
			break;

		}
	} while (intput);



	return 0;
}