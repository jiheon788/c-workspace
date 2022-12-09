#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeStruct
{
    char name[10];
    int date;
    char location[20];
    struct NodeStruct* leftChild;
    struct NodeStruct* rightChild;
}Node;

Node* root = NULL;

Node* BST_insert(Node* root, int name, int date, char location)
{
    if (root == NULL)
    {
        root = (Node*)malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        strcpy(root->name, name);
        root->date = date;
        strcpy(root->location, location);
    
        return root;
    }
    else
    {
        if (root->name > name)
            root->leftChild = BST_insert(root->leftChild, name, date, location);
        else
            root->rightChild = BST_insert(root->rightChild, name, date, location);
    }
    return root;
}
Node* findMinNode(Node* root)
{
    Node* tmp = root;
    while (tmp->leftChild != NULL)
        tmp = tmp->leftChild;
    return tmp;
}
Node* BST_delete(Node* root, int name)
{
    Node* tNode = NULL;
    if (root == NULL)
        return NULL;

    if (root->name > name)
        root->leftChild = BST_delete(root->leftChild, name);
    else if (root->name < name)
        root->rightChild = BST_delete(root->rightChild, name);
    else
    {
        // 자식 노드가 둘 다 있을 경우
        if (root->rightChild != NULL && root->leftChild != NULL)
        {
            tNode = findMinNode(root->rightChild);
            strcpy(root->name, tNode->name);

            root->rightChild = BST_delete(root->rightChild, tNode->name);
        }
        else
        {
            tNode = (root->leftChild == NULL) ? root->rightChild : root->leftChild;
            free(root);
            return tNode;
        }
    }

    return root;
}
Node* BST_search(Node* root, int name)
{
    if (root == NULL)
        return NULL;

    if (root->name == name)
        return root;
    else if (root->name > name)
        return BST_search(root->leftChild, name);
    else
        return BST_search(root->rightChild, name);
}
void BST_print(Node* root)
{
    if (root == NULL)
        return;

    printf("%s ", root->name);
    printf("%d ", root->date);
    printf("%s ", root->location);

    BST_print(root->leftChild);
    BST_print(root->rightChild);
}
/*
int main()
{
    root = BST_insert(root, 5);
    root = BST_insert(root, 3);
    root = BST_insert(root, 7);
    root = BST_insert(root, 1);
    root = BST_insert(root, 9);
    root = BST_insert(root, 6);

    root = BST_delete(root, 7);

    BST_print(root);
}*/

int printMenu() {

    int selectNum;
    printf("------------------------------------------------\n");
    printf("1:입력 2:검색 3:수정 4:취소 5:종료\n");
    printf("메뉴를 입력하세요 -> ");
    scanf(" %d", &selectNum);

    return selectNum;
}

int main(void)
{
	int sNum;
	char name[10];
	int date;
	char location[20];

	while (1)
	{
	startPoint:
		sNum = printMenu();
		//종료
		if (sNum == 5) {
			break;
		}
		else if (sNum == 1) {
			printf("이름: ");
			scanf(" %s", name);
			printf("날짜: ");
			scanf(" %d", &date);
			printf("지역: ");
			scanf(" %s", location);
            root = BST_insert(root, name, date, location);
		}
		else if (sNum == 2) {
			printf("검색할 이름: ");
			scanf(" %s", name);
            root = BST_search(root, name);
		}
		else if (sNum == 3) {

		}
		else if (sNum == 4) {
			printf("삭제할 이름: ");
			scanf(" %s", name);
            root = BST_delete(root, name);
			
		}
		
	}
	
    BST_print(root);

	return 0;
}