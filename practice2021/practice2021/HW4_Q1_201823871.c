#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char a, b, c, d;
	unsigned int result;

	printf("ù��° ���ڸ� �Է��Ͻÿ�: ");
	scanf(" %c", &a);
	
	printf("�ι�° ���ڸ� �Է��Ͻÿ�: ");
	scanf(" %c", &b);

	printf("����° ���ڸ� �Է��Ͻÿ�: ");
	scanf(" %c", &c);
	
	printf("�׹�° ���ڸ� �Է��Ͻÿ�: ");
	scanf(" %c", &d);
	
	result = (d << 24) | (c << 16) | (b << 8) | a;
	printf("�����: %x", result);
	
	return 0;



}