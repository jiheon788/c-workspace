#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 5
void get_sum_diff(int x, int y, int* psum, int* pdiff);
void print_array(int* arr, int size);
void copy_array(int* arr1, int* arr2, int size);
int search(int* arr, int size, int x);
void print_array2(char* name, int* arr, int size);
void merge(int* arr1, int* arr2, int* arr3, int size);

int main(void)
{
	printf("\n1)================================================\n");
	int sum = 0, diff = 0;
	int num1, num2;

	printf("첫번째 정수: ");
	scanf(" %d", &num1);
	printf("두번째 정수: ");
	scanf(" %d", &num2);

	get_sum_diff(num1, num2, &sum, &diff);

	printf("두 정수의 합: %d\n두 정수의 차: %d\n", sum, diff);

	printf("\n2)================================================\n");
	int a[SIZE] = { 1, 2, 3, 4, 5 };
	int b[SIZE] = { 0 };
	
	printf("배열 a: ");
	print_array(a, SIZE);
	
	printf("배열 b: ");
	print_array(b, SIZE);
	
	copy_array(a, b, SIZE);

	printf("복사 후 배열 a: ");
	print_array(a, SIZE);
	
	printf("복사 후 배열 b: ");
	print_array(b, SIZE);
	

	printf("\n3)================================================\n");
	int data[10] = { 8, 10, 3, 1, 7, 4, 6, 2, 9, 5 };
	int value, index;


	printf("검색하는 값: ");
	scanf(" %d", &value);

	index = search(data, 10, value);

	if (index == -1)
		printf("검색 내용이 없습니다.\n");
	else
		printf("검색하는 값 %d의 배열내 위치: %d\n", value, index);


	printf("\n4)================================================\n");
	int c[SIZE] = { 1, 3, 5, 6, 7 };
	int d[SIZE] = { 2, 4, 8, 9, 10 };
	int e[SIZE * 2];
	char name;

	
	name = 'c';
	print_array2(&name, c, SIZE);
	name = 'd';
	print_array2(&name, d, SIZE);

	merge(c, d, e, SIZE*2);

	name = 'e';
	print_array2(&name, e, SIZE*2);

	return 0;
}
void get_sum_diff(int x, int y, int *psum, int *pdiff)
{
	*psum = x + y;
	*pdiff = x - y;
}
void print_array(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void copy_array(int* arr1, int* arr2, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr1[i];
	}
}
int search(int* arr, int size, int x)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x)
			return i;
	}
	return -1;
}
void print_array2(char *name, int *arr, int size)
{
	printf("배열 %c: ",*name);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

}
void merge(int* arr1, int* arr2, int* arr3, int size)
{
	int i, j, k;
	i = 0; j = 0; k = 0;

	for (k = 0; k < size; k++)
	{
		if (i >= size / 2)
		{
			arr3[k] = arr2[j];
			j++;
		}
		else if (j >= size / 2)
		{
			arr3[k] = arr1[i];
			i++;
		}
		else if (arr1[i] < arr2[j])
		{
			arr3[k] = arr1[i];
			i++;
		}
		else if (arr1[i] > arr2[j])
		{
			arr3[k] = arr2[j];
			j++;
		}
	}
}