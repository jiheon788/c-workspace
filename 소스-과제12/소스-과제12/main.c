#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MIN(x, y) ((x) < (y)) ? (x) : (y)
#ifdef MIN
#define GET_MIN(x, y, z) (MIN(x, y)) < (z) ? (MIN(x, y)) : (z)
#endif // MIN

#define ARRAY_INT(a, size, value){\
	for(int i = 0; i < 10; i++)\
		a[i] = (value);}

#define GET_BIT(n, pos) (((n) >> (pos)) & 0x01)
#define SET_BIT(n, pos) ((n) |= (0x01 << (pos)))
#define SET_BIT_OFF(n, pos) ((n) &= ~(0x01 << (pos)))

void display_bit(int value);

int main(void)
{
	printf("\n1)================================================\n");
	int x, y, z;

	printf("3개의 정수를 입력하시오: ");
	scanf("%d %d %d", &x, &y, &z);

	printf("최소값은 %d입니다.\n", GET_MIN(x, y, z));

	printf("\n2)================================================\n");
	int a[10];

	ARRAY_INT(a, sizeof(a), 1);

	printf("[ ");
	for (int i = 0; i < 9; i++)
	{
		printf("%d, ", a[i]);
	}
	printf("%d ]\n ", a[9]);
	
	printf("\n3)================================================\n");
	int n = 0x808081;

	printf("n = 0x%X\n", n);
	printf("GET_BIT(n, 0): %d\n", GET_BIT(n, 0));
	SET_BIT(n, 2);
	printf("SET_BIT(n, 2)\n");
	printf("n = 0x%X\n", n);
	
	printf("\n4)================================================\n");
	int value, move, dist, mvalue;

	printf("정수값을 입력하시오: ");
	scanf(" %d", &value);
	printf("왼쪽 이동은 0, 오른쪽 이동은 1을 입력하시오: ");
	scanf(" %d", &move);
	printf("몇 비트 이동시킬 것인지 입력하시오:  ");
	scanf(" %d", &dist);

	printf("이동 전:");
	display_bit(value);

	if (move == 0)// shift left
	{
		mvalue = (value << dist);
		printf("이동 후: ");
		display_bit(mvalue);
	}
	else if (move == 1)// shift right
	{
		mvalue = (value >> dist);
		printf("이동 후: ");
		display_bit(mvalue);
	}


	return 0;
}
void display_bit(int value)
{
	int i, count;
	count = 0;
	for (i = 31; i >= 0; i--)
	{
		if (count == 4)
		{
			count = 0;
		}
		if (GET_BIT(value, i))
			printf("1");
		else
			printf("0");
		count++;
	}
	printf("\n");

}