#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1, num2, num3;
	int min_value;

	printf("3���� ������ �Է��Ͻÿ�: ");
	scanf("%d %d %d", &num1, &num2, &num3);

	if (num1 < num2 && num1 < num3)
		min_value = num1;
	else if (num2 < num1 && num2 < num3)
		min_value = num2;
	else if (num3 < num1 && num3 < num2)
		min_value = num3;
	else
	{
		min_value = 0;
		printf("ERROR\n");
	}
		
	printf("���� ���� ������ %d�Դϴ�.\n", min_value);

	return 0;
	
}