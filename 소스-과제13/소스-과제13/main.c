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
//	printf("정수의 개수: ");
//	scanf(" %d", &numofInt);
//
//	list = (int*)malloc(numofInt * sizeof(int));
//	if (list == NULL)
//	{
//		printf("동적 메모리 할당 오류\n");
//		exit(1);
//	}
//	// 입력
//	for (int i = 0; i < numofInt; i++)
//	{
//		printf("양의 정수를 입력하시오: ");
//		scanf(" %d", &list[i]);
//	}
//	// 출력
//	printf("입력된 정수: ");
//	for (int i = 0; i < numofInt; i++)
//	{
//		printf("%d ", list[i]);
//		sum += list[i];
//	}
//	printf("\n입력된 정수들의 합은 %d입니다.\n", sum);
//	
//	free(list);
//	
//	printf("\n2)================================================\n");
//	char* list2[10];
//	int numofString;
//	char buffer[100];
//
//	printf("문자열의 개수: ");
//	scanf(" %d", &numofString);
//	getchar();
//	
//	
//	for (int i = 0; i < numofString; i++) 
//	{
//		list2[i] = (char*)malloc(100 * sizeof(char));
//		if (list2[i] == NULL) 
//		{
//			printf("malloc() 실패!\n\n");
//			exit(1);
//		}
//		printf("문자열을 입력하시오: ");
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
//	printf("주소의 개수: ");
//	scanf(" %d", &numofAddr);
//	getchar();
//	addrs = (ADDR*)malloc(sizeof(ADDR) * numofAddr);
//	if (addrs == NULL)
//	{
//		printf("malloc() 실패!\n\n");
//		exit(1);
//	}
//
//	for (int i = 0; i < numofAddr; i++)
//	{
//		
//		printf("이름을 입력하시오: ");
//		fflush(stdin);
//		gets_s(addrs[i].name, 100);
//
//		printf("휴대폰 번호를 입력하시오: ");
//		fflush(stdin);
//		gets_s(addrs[i].phone, 100);
//	}
//	printf("===================================\n");
//	printf("이름		휴대폰 번호\n");
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
//	printf("양의 정수를 입력하시오 (종료하려면 -1을 입력): ");
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