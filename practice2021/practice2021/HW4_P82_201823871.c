#include <stdio.h>

int main(void)
{
	char c;
	int i;
	float f;
	
	c = 10000; // ���� ��ȯ
	i = 1.23456 + 10; // ���� ��ȯ
	f = 10 + 20; // �ø� ��ȯ
	
	printf("c = %d, i = %d, f = %f \n", c, i, f);
	
	return 0;
}