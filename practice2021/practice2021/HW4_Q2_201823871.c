#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char alphabet;

	printf("���� �ҹ��ڸ� �Է��Ͻÿ�: ");
	scanf(" %c", &alphabet);

	switch (alphabet)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		printf("�����Դϴ�.\n");
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
		printf("�����Դϴ�.\n");
		break;
	default:
		printf("���� �ҹ��ڰ� �ƴմϴ�.\n");
		break;
	}

	return 0;
}