#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char data = 'a';
	char key = 0xff;
	char encrpted_data;
	
	encrpted_data = data ^ key;
	printf("암호화된 문자=%c \n", encrpted_data);
	
	char orig_data;
	orig_data = encrpted_data ^ key;
	
	printf("원래의 데이터=%c\n", orig_data);
	
	return 0;
}