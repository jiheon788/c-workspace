#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	unsigned int num;
	
	printf("������: ");
	scanf("%u", &num);
	
	unsigned int mask = 1 << 7; // mask = 10000000
	printf("������: ");
	
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;// ���������� 1��Ʈ �̵��Ѵ�.
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;// ���������� 1��Ʈ �̵��Ѵ�.
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;// ���������� 1��Ʈ �̵��Ѵ�.
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;
	((num & mask) == 0) ? printf("0") : printf("1");
	printf("\n");
	return 0;
}