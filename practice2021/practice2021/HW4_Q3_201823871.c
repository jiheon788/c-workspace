#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int num1, num2, num3;
	int min_value;

	printf("3개의 정수를 입력하시오: ");
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
		
	printf("제일 작은 정수는 %d입니다.\n", min_value);

	return 0;
	
}