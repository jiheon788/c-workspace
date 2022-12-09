#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define ROWS 10
#define COLS 3

void print_array(int arr[], int size);
int compare_array(int arr1[], int arr2[], int size);
void find_test_stat(int score[][3]);
void show_binary(int n);

int main(void)
{
	printf("\n1)================================================\n");
	int list[10];
	int i, max, min;

	srand((unsigned)time(NULL));
	for (i = 0; i < 10; i++)
		list[i] = rand();
		
	max = list[0];
	min = list[0];

	for (i = 1; i < 10; i++)
	{
		if (list[i] > max)
			max = list[i];

		if (list[i] < min)
			min = list[i];
	}
	printf("최대값은 %d\n", max);
	printf("최소값은 %d\n", min);

	printf("\n2)================================================\n");
	int a[SIZE] = { 1,2,3,4,5 };
	int b[SIZE] = { 1,2,3 };
	int result;
	
	printf("배열 a:");
	print_array(a, SIZE);
	printf("배열 b:");
	print_array(b, SIZE);

	result = compare_array(a, b, SIZE);
	
	if (result == 1)
		printf("2개의 배열은 같음\n");
	else
		printf("2개의 배열은 다름\n");

	printf("\n3)================================================\n");
	int score[ROWS][COLS];
	int r, c;

	srand((unsigned)time(NULL));
	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			score[r][c] = rand() % 100 + 1;

	find_test_stat(score);

	printf("\n4)================================================\n");
	int n;
	printf("10진수를 입력하시오:");
	scanf("%d", &n);

	show_binary(n);
	printf("\n");

	return 0;
}

void print_array(int arr[], int size)
{
	int i;

	for (i = 0; i < size; i++)
		printf(" %d", arr[i]);
	printf("\n");
}
int compare_array(int arr1[], int arr2[], int size) 
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (arr1[i] != arr2[i])
			return 0;
	}
	return 1;
}
void find_test_stat(int score[][3])
{
	int max, min,r,c;
	
	for (c = 0; c < COLS; c++)
	{
		max = score[0][c];
		min = score[0][c];

		for (r = 0; r < ROWS; r++)
		{
			if (score[r][c] > max)
				max = score[r][c];
			if (score[r][c] < min)
				min = score[r][c];
		}

		printf("시험 %d의 최고 점수 = %d\n", c + 1, max);
		printf("시험 %d의 최저 점수 = %d\n\n", c + 1, min);
	}
}
void show_binary(int n)
{
	int binary[32] = { 0 };
	int i = 0;

	while (1)
	{
		binary[i] = n % 2;
		n = n / 2;
		i++;

		if (n == 0)
			break;
	}

	for (int j = i - 1; j >= 0; j--)
		printf("%d", binary[j]);
}