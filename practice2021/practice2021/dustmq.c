#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int id, pass;
	printf("아이디와 패스워드를 4개의 숫자로 입력하세요:\n");
	printf("id: ____ \b\b\b\b");
	scanf("%d", &id);
	printf("pass: ____ \b\b\b\b");
	scanf("%d", &pass);
	printf("\a입력된 아이디는 %d이고 패스워드는 %d입니다.", id, pass);
		return 0;
}