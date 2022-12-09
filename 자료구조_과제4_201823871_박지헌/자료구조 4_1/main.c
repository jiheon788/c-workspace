#include <stdio.h>

//heapify, �� ���� ����� 
void heapify(int* arr, int size) {
	for (int i = 1; i < size; ++i) {
		int child = i;
		do {
			//�ڽ� ��尡 �θ� ��庸�� ũ�� ��ȯ
			int root = (child - 1) / 2;
			if (arr[root] < arr[child]) {
				int temp = arr[root];
				arr[root] = arr[child];
				arr[child] = temp;
			}
			child = root;
		} while (child != 0);	//�ֻ�� ������ ����
	}
}

//�ֻ�� ���� ���ϴ� ��� ��ü
void heap(int* arr, int* size) {
	int temp = arr[0];
	arr[0] = arr[*size - 1];
	arr[*size - 1] = temp;
	--(*size);
}
int main()
{
	
	int size = 15;
	//������ �迭
	int arr[15] = { 2, 4, 125, 105, 102, 91, 88, 60, 14, 31, 12, 25, 82, 51, 30 };

	printf("������ ������ : ");
	for (int i = 0; i < 15; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	//������
	for (int i = 0; i < 15; ++i) {
		heapify(arr, size);
		heap(arr, &size);
	}

	printf("Heap sort : ");
	//��� 
	for (int i = 0; i < 15; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
