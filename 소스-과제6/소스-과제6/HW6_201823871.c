#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void get_dice_face(void);
int get_random(void);
int sum(int);
int power(int base, int powerRaised);


int main(void)
{
	
	printf("\n1)================================================\n");
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++)
		get_dice_face();
	
	printf("\n2)================================================\n");
	printf("%d\n", get_random());
	printf("%d\n", get_random());
	printf("%d\n", get_random());
	
	printf("\n3)================================================\n");
	int n;

	printf("정수를 입력하시오: ");
	scanf(" %d", &n);
	
	printf("1부터 %d까지의 합 = %d\n", n, sum(n));

	printf("\n4)================================================\n");
	int base;
	int powerRaised;
	
	printf("밑수: ");
	scanf(" %d", &base);

	printf("지수: ");
	scanf(" %d", &powerRaised);

	printf("%d^%d = %d\n", base, powerRaised, power(base, powerRaised));

	return 0;
}

void get_dice_face(void)
{
	static int one, two, three, four, five, six;
	static int call_count = 0;
	
	int dice = (rand() % 6) + 1;
	
	call_count++;

	switch (dice)
	{
	case 1:
		one++;
		break;
	case 2:
		two++;
		break;
	case 3:
		three++;
		break;
	case 4:
		four++;
		break;
	case 5:
		five++;
		break;
	case 6:
		six++;
		break;
	}
	 
	if(call_count==100)
	{
		printf("1->%d\n2->%d\n3->%d\n4->%d\n5->%d\n6->%d\n", one, two, three, four, five, six);
	}

}

int get_random(void)
{
	static int initial = 0;

	if (initial == 0)
	{
		printf("초기화 실행\n");
		srand((unsigned)time(NULL));
		initial++;
	}
	
	return rand();
}

int sum(int n)
{
	if (n <= 1)
		return 1;
	else
		return n + sum(n - 1);
}

int power(int base, int powerRaised)
{
	if (powerRaised == 0)
		return 1;
	else
		return base * power(base, powerRaised - 1);
}