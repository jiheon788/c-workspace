#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100

void delete_space(char s[]);
void flip_str(char* s);

int main(void)
{
	printf("\n1)================================================\n");
	char str[SIZE];

	printf("문자열을 입력하시오: ");
	gets_s(str, SIZE);

	delete_space(str);

	printf("\n2)================================================\n");

	printf("문자열을 입력: ");
	gets_s(str, SIZE);

	flip_str(str);


	printf("\n3)================================================\n");
	char s[200], target[200];
	char find[30], replace[30];
	char seps[] = " ";
	char* token;

	printf("문자열을 입력: ");
	gets_s(s, SIZE);

	printf("찾을 단어: ");
	scanf(" %s", find);

	printf("바꿀 단어: ");
	scanf(" %s", replace);

	token = strtok(s, seps);
	strcpy(target, token);
	token = strtok(NULL, seps);

	while (token != NULL)
	{
		if (strcmp(token, find) == 0)
		{
			strcat(target, replace);
		}
		else
		{
			strcat(target, token);
		}
		strcat(target, " ");
		token = strtok(NULL, seps);
	}

	strcat(target, "\0");
	printf("%s\n", target);



	printf("\n4)================================================\n");
	char s4[200];
	char op[10];
	int x, y;
	char* token2;

	printf("수학 연산을 입력: ");
	gets_s(s4, SIZE);

	token2 = strtok(s4, " ");
	strcpy(op, token2);

	token2 = strtok(NULL, " ");
	sscanf(token2, "%d", &x);

	token2 = strtok(NULL, " ");
	sscanf(token2, "%d", &y);

	if (strcmp(op, "add") == 0)
		printf("연산의 결과: %d\n", x + y);
	else if (strcmp(op, "sub") == 0)
		printf("연산의 결과: %d\n", x - y);
	else if (strcmp(op, "mult") == 0)
		printf("연산의 결과: %d\n", x * y);
	else if (strcmp(op, "div") == 0)
		printf("연산의 결과: %d\n", x / y);
	else
		printf("error\n");
}
void delete_space(char s[])
{
	char tmp[SIZE];
	int i, index = 0;


	for(i=0;s[i]!=NULL;i++)
		if (s[i] != ' ')
		{
			tmp[index] = s[i];
			index++;
		}
	tmp[index] = '\0';
	strcpy(s, tmp);

	puts(s);

}
void flip_str(char* s)
{
	for (int i = 0; s[i] != NULL; i++)
		if (islower(s[i]))
			s[i] = toupper(s[i]);
		else if (isupper(s[i]))
			s[i] = tolower(s[i]);

	puts(s);
}
