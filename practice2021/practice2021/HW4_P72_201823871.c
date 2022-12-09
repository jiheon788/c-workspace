#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	unsigned int num;
	
	printf("십진수: ");
	scanf("%u", &num);
	
	unsigned int mask = 1 << 7; // mask = 10000000
	printf("이진수: ");
	
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;// 오른쪽으로 1비트 이동한다.
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;// 오른쪽으로 1비트 이동한다.
	((num & mask) == 0) ? printf("0") : printf("1");
	mask = mask >> 1;// 오른쪽으로 1비트 이동한다.
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