#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char a, b, c, d;
	unsigned int result;

	printf("첫번째 문자를 입력하시오: ");
	scanf(" %c", &a);
	
	printf("두번째 문자를 입력하시오: ");
	scanf(" %c", &b);

	printf("세번째 문자를 입력하시오: ");
	scanf(" %c", &c);
	
	printf("네번째 문자를 입력하시오: ");
	scanf(" %c", &d);
	
	result = (d << 24) | (c << 16) | (b << 8) | a;
	printf("결과값: %x", result);
	
	return 0;



}