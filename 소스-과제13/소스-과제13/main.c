#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int d, x, o;

	scanf("%d %x %o", &d, &x, &o);
	printf("%d %x %o", d, x, o);
	return 0;
}
//typedef struct addr
//{
//	char name[100];
//	char phone[100];
//}ADDR;
//
//typedef struct NODE
//{
//	int data;
//	struct NODE* link;
//}NODE;
//
//int get_integer();
//void print_list(NODE* plist);
//void free_list(NODE* plist);
//
//int main(void)
//{
//	printf("\n1)================================================\n");
//	int* list;
//	int numofInt;
//	int sum = 0;
//
//	printf("������ ����: ");
//	scanf(" %d", &numofInt);
//
//	list = (int*)malloc(numofInt * sizeof(int));
//	if (list == NULL)
//	{
//		printf("���� �޸� �Ҵ� ����\n");
//		exit(1);
//	}
//	// �Է�
//	for (int i = 0; i < numofInt; i++)
//	{
//		printf("���� ������ �Է��Ͻÿ�: ");
//		scanf(" %d", &list[i]);
//	}
//	// ���
//	printf("�Էµ� ����: ");
//	for (int i = 0; i < numofInt; i++)
//	{
//		printf("%d ", list[i]);
//		sum += list[i];
//	}
//	printf("\n�Էµ� �������� ���� %d�Դϴ�.\n", sum);
//	
//	free(list);
//	
//	printf("\n2)================================================\n");
//	char* list2[10];
//	int numofString;
//	char buffer[100];
//
//	printf("���ڿ��� ����: ");
//	scanf(" %d", &numofString);
//	getchar();
//	
//	
//	for (int i = 0; i < numofString; i++) 
//	{
//		list2[i] = (char*)malloc(100 * sizeof(char));
//		if (list2[i] == NULL) 
//		{
//			printf("malloc() ����!\n\n");
//			exit(1);
//		}
//		printf("���ڿ��� �Է��Ͻÿ�: ");
//		gets_s(list2[i],100);
//	
//	}
//
//	
//	printf("[");
//	for (int i = 0; i < numofString; i++) {
//		printf(" \"%s\" ",list2[i]);
//	}
//	printf("]");
//
//	for (int i = 0; i < numofString; i++)
//	{
//		free(list2[i]);
//	}
//	
//	
//	printf("\n3)================================================\n");
//	ADDR* addrs;
//	int numofAddr;
//
//	printf("�ּ��� ����: ");
//	scanf(" %d", &numofAddr);
//	getchar();
//	addrs = (ADDR*)malloc(sizeof(ADDR) * numofAddr);
//	if (addrs == NULL)
//	{
//		printf("malloc() ����!\n\n");
//		exit(1);
//	}
//
//	for (int i = 0; i < numofAddr; i++)
//	{
//		
//		printf("�̸��� �Է��Ͻÿ�: ");
//		fflush(stdin);
//		gets_s(addrs[i].name, 100);
//
//		printf("�޴��� ��ȣ�� �Է��Ͻÿ�: ");
//		fflush(stdin);
//		gets_s(addrs[i].phone, 100);
//	}
//	printf("===================================\n");
//	printf("�̸�		�޴��� ��ȣ\n");
//	printf("===================================\n");
//
//	for (int i = 0; i < numofAddr; i++)
//	{
//		printf("%s\t\t%s\n", addrs[i].name, addrs[i].phone);
//	}
//	printf("===================================\n");
//	free(addrs);
//
//
//	printf("\n4)================================================\n");
//	NODE* plist = NULL;
//	NODE* prev = NULL, * p, * next;
//	int pstvint;
//
//	while (1)
//	{
//		pstvint = get_integer();
//		if (pstvint < 0)
//			break;
//
//		p = (NODE*)malloc(sizeof(NODE));
//		if (p == NULL) break;
//		p->data = pstvint;
//
//		if (plist == NULL)
//			plist = p;
//		else
//			prev->link = p;
//		p->link = NULL;
//		prev = p;
//	}
//	print_list(plist);
//	free_list(plist);
//
//	return 0;
//}
//
//int get_integer()
//{
//	int pstvint;
//	printf("���� ������ �Է��Ͻÿ� (�����Ϸ��� -1�� �Է�): ");
//	scanf(" %d", &pstvint);
//	
//	return pstvint;
//}
//void print_list(NODE* plist)
//{
//	NODE* p=plist;
//	while (p != NULL)
//	{
//		printf("%d->", p->data);
//		p = p->link;
//	}
//	printf("NULL\n");
//}
//void free_list(NODE* plist)
//{
//	NODE* next, * p;
//	p = plist;
//	while (p != NULL)
//	{
//		next = p->link;
//		free(p);
//		p = next;
//	}
//	
//}
//	