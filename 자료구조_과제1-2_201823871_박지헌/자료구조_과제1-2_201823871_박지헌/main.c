#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node* next;
}Node;

typedef struct _linkedList {
	Node* head;
	Node* cur;
	Node* before;
	int numofData;
	int (*comp)(LData d1, LData d2);
}LinkedList;

typedef LinkedList List;

void ListInit(List* plist);
void SInsert(List* plist, LData data);
int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);
LData LRemove(List* plist);
int LCount(List* plist);
void SetSortRule(List* plist, int (*comp)(LData d1, LData d2));
int printMenu();

//�������� - default
int descendingRule(int d1, int d2) {
	if (d1 > d2)
		return 0;
	else
		return 1;
}
//��������
int ascendingRule(int d1, int d2) {
	if (d1 < d2)
		return 0;
	else
		return 1;
}

int main(void) {
	int sNum;
	List list;
	int data;
	int n;
	ListInit(&list);
	SetSortRule(&list, descendingRule);


	while (1)
	{
	startPoint:
		sNum = printMenu();
		//����
		if (sNum == 5)
			break;
		//�Է�
		else if (sNum == 1) {
			printf("�Է�: ");
			scanf(" %d", &n);

			if (LFirst(&list, &data)) {
				if (data == n) {
					printf("�ߺ��� �������Դϴ�.\n");
					goto startPoint;
				}
				while (LNext(&list, &data)) {
					if (data == n) {
						printf("�ߺ��� �������Դϴ�.\n");
						goto startPoint;
					}
				}
			}
			SInsert(&list, n);
			printf("�����߽��ϴ�.\n");
		}
		//����
		else if (sNum == 2) {
			if (LCount(&list) == 0) {
				printf("list�� ����ֽ��ϴ�.\n");
			}
			else {
				printf("����: ");
				scanf(" %d", &n);

				if (LFirst(&list, &data)) {
					if (data == n) {
						LRemove(&list);
						printf("�����߽��ϴ�.\n");
						goto startPoint;
					}
					while (LNext(&list, &data)) {
						if (data == n) {
							LRemove(&list);
							printf("�����߽��ϴ�.\n");
							goto startPoint;
						}
					}
				}
				printf("ã�� ���� �����ϴ�.\n");
			}
		}
		//���
		else if (sNum == 3) {
			if (LCount(&list) == 0) {
				printf("list�� ����ֽ��ϴ�.\n");
				goto startPoint;
			}

			if (LFirst(&list, &data)) {
				printf("%d ", data);

				while (LNext(&list, &data))
					printf("%d ", data);
			}
			printf("\n");
		}
		//�������
		else if (sNum == 4) {
			if (LCount(&list) == 0) {
				printf("list�� ����ֽ��ϴ�.\n");
				goto startPoint;
			}

			List listCopy;
			int dataCopy;

			ListInit(&listCopy);
			SetSortRule(&listCopy, ascendingRule);

			if (LFirst(&list, &dataCopy)) {
				SInsert(&listCopy, dataCopy);

				while (LNext(&list, &dataCopy))
					SInsert(&listCopy, dataCopy);
			}

			if (LFirst(&listCopy, &dataCopy)) {
				printf("%d ", dataCopy);

				while (LNext(&listCopy, &dataCopy))
					printf("%d ", dataCopy);
			}
			printf("\n");
		}
	}
	
	return 0;
}

int printMenu() {

	int selectNum;
	printf("------------------------------------------------\n");
	printf("1:�߰� 2:���� 3:��� 4: ������� 5: ����\n");
	printf("�޴��� �Է��ϼ��� -> ");
	scanf(" %d", &selectNum);

	return selectNum;
}
void ListInit(List* plist) {
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numofData = 0;
}

void SInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* pred = plist->head;
	newNode->data = data;

	while (pred->next != NULL && plist->comp(data, pred->next->data) != 0) {
		pred = pred->next;
	}

	newNode->next = pred->next;
	pred->next = newNode;

	(plist->numofData)++;
}

int LFirst(List* plist, LData* pdata) {
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL)
		return FALSE;
	
	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist) {
	Node* rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numofData)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numofData;
}

void SetSortRule(List* plist, int (*comp)(LData d1, LData d2)) {
	plist->comp = comp;
}

