#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int check_alpha(char);
void is_leap(int);
int b_rand();
float f_rand();

int main(void)
{
	printf("\n(Q1)================================================\n");
	int i = 1;
	int sum = 0;

	while (i <= 100)
	{
		if (i % 3 == 0)
			sum += i;
		i++;
	}
	printf("1���� 100������ ��� 3�� ����� ���� %d�Դϴ�", sum);
	

	printf("\n(Q2)================================================\n");
	int j;

	for (i = 1; i <= 7; i++)
	{
		for (j = 1; j <= 7 - i; j++)
			printf(" ");
		for (j = 1; j <= i; j++)
			printf("*");
		printf("\n");
	}
	

	printf("\n(Q3)================================================\n");
	i = 0;
	sum = 0;

	while (1)
	{
		sum += i;
		if (sum >= 10000)
			break;
		i++;
	}
	printf("1���� %d������ ���� %d�Դϴ�.", i-1, sum-i);
	

	printf("\n(Q4)================================================\n");
	int x, obj;
	int n = 1;
	
	printf("������ �Է��Ͻÿ�: ");
	scanf(" %d", &x);

	do
	{
		obj = x / n;
		obj %= 10;
		printf("%d", obj);
		n *= 10;
	} while (x > n);
	

	printf("\n(Q5)================================================\n");
	char unknown;
	int result;
	
	printf("���ڸ� �Է��Ͻÿ�:");
	scanf(" %c", &unknown);

	result = check_alpha(unknown);
	
	switch (result)
	{
	case 0:
		printf("���ĺ��� �ƴմϴ�.");
		break;
	case 1:
		printf("%c�� ���ĺ� �����Դϴ�.",unknown);
		break;
	}
	
	printf("\n(Q6)================================================\n");
	int year;

	printf("������ �Է��Ͻÿ�:");
	scanf(" %d", &year);

	is_leap(year);

	printf("\n(Q7)================================================\n");
	srand((unsigned)time(NULL));

	for (i = 0; i < 10; i++)
		printf("%d ", b_rand());
	
	printf("\n(Q8)================================================\n");
	for (i = 0; i < 5; i++)
		printf("%lf ", f_rand());
	printf("\n");
	
	return 0;
}
int check_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	else if (c >= 'A' && c <= 'Z')
		return 1;
	else
		return 0;
}

void is_leap(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		printf("%d���� 366�� �Դϴ�.", y);
	else
		printf("%d���� 365�� �Դϴ�.", y);
}

int b_rand()
{
	int i = rand() % 2;

	if (i == 0)
		return 0;
	else
		return 1;
}

float f_rand()
{
	float i = (float)rand() / (float)RAND_MAX;
	return i;
}