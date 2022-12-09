#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char alphabet;

	printf("영문 소문자를 입력하시오: ");
	scanf(" %c", &alphabet);

	switch (alphabet)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		printf("모음입니다.\n");
		break;
	case 'b':
	case 'c':
	case 'd':
	case 'f':
	case 'g':
	case 'h':
	case 'j':
	case 'k':
	case 'l':
	case 'm':
	case 'n':
	case 'p':
	case 'q':
	case 'r':
	case 's':
	case 't':
	case 'v':
	case 'w':
	case 'x':
	case 'y':
	case 'z':
		printf("자음입니다.\n");
		break;
	default:
		printf("영문 소문자가 아닙니다.\n");
		break;
	}

	return 0;
}