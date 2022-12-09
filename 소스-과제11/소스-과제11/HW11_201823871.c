#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define SIZE 20
struct student
{
	char name[100];
	double korean;
	double english;
	double math;
};

int main(void)
{
	printf("\n1)================================================\n");
	FILE* fp1, * fp2;

	char fname1[100], fname2[100];
	char buffer[100];
	int c;

	printf("첫번째 파일: ");
	scanf("%s", fname1);
	printf("두번째 파일: ");
	scanf("%s", fname2);

	if ((fp1 = fopen(fname1, "r")) == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", fname1);
		exit(1);
	}
	if ((fp2 = fopen(fname2, "w")) == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", fname2);
		exit(1);
	}

	while ((c = fgetc(fp1)) != EOF)
	{
		if (c >= 'a' && c <= 'z')
			c -= 32;
		fputc(c, fp2);
		putchar(c);
	}
	printf("\n");
	fclose(fp1);
	fclose(fp2);

	printf("\n2)================================================\n");
	char buffer1[1024], buffer2[1024];

	printf("첫번째 파일: ");
	scanf("%s", fname1);
	printf("두번째 파일: ");
	scanf("%s", fname2);

	if ((fp1 = fopen(fname1, "r")) == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", fname1);
		exit(1);
	}
	if ((fp2 = fopen(fname2, "r")) == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", fname2);
		exit(1);
	}
	while (1)
	{
		char* p1 = fgets(buffer1, 1000, fp1);
		char* p2 = fgets(buffer2, 1000, fp2);

		if (p1 == NULL || p2 == NULL)
			break;

		if (strcmp(buffer1, buffer2) != 0)
		{
			printf("<< %s", buffer1);
			printf(">> %s\n", buffer2);
		}
	}

	fclose(fp1);
	fclose(fp2);

	printf("\n3)================================================\n");
	FILE* fp = NULL;

	char fname[100];
	struct student s;
	double ksum = 0, esum = 0, msum = 0;

	printf("파일명을 입력하세요: ");
	scanf("%s", fname);

	if ((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", fname);
		exit(1);
	}

	for (int i = 0; i < SIZE; i++)
	{
		fread(&s, sizeof(struct student), 1, fp);
		printf("이름 = %s, 국어 = %.1f, 영어 = %.1f, 수학 = %.1f\n", s.name, s.korean, s.english, s.math);
		ksum += s.korean;
		esum += s.english;
		msum += s.math;
	}
	fclose(fp);

	printf("평균: 국어 = %.2f, 영어 = %.2f, 수학 = %.2f\n", ksum / SIZE, esum / SIZE, msum / SIZE);

	
	printf("\n4)================================================\n");
	FILE* fp3, * fp4;
	
	char fname3[100], fname4[100];
	int num[100];
	
	// 첫번째 파일명은 rand1.txt, 두번째 파일명은 rand2.dat를 사용자로부터 입력 받음
	printf("첫번째 파일: ");
	scanf("%s", fname3);
	printf("두번째 파일: ");
	scanf("%s", fname4);
	
	// 각 파일을 열때 에러가 있으면 파일을 열수 없다는 메시지 출력
	if ((fp3 = fopen(fname3, "w")) == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", fname3);
		exit(1);
	}
	if ((fp4 = fopen(fname4, "ab")) == NULL)
	{
		fprintf(stderr, "파일 %s을 열 수 없습니다.\n", fname4);
		exit(1);
	}

	// 함수 rand를 이용해 정수를 랜덤하게 생성하고 실행 예제와 같이 화면에 출력한 후 
	// rand1.txt에는 fprintf, rand2.dat에는 fwrite를 이용해 씀(100번 반복해서 실행해 100개 정수를 생성)
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		num[i] = rand();
		printf("%d", num[i]);
		fprintf(fp3, "%d", num[i]);
	}
	printf("\n");
	fwrite(num, sizeof(int), 100, fp4);

	// 각 파일의 사이즈를 실행 예제와 같이 출력
	fseek(fp3, 0, SEEK_END);
	printf("The size of rand1.txt: %d\n", ftell(fp3));
	fseek(fp4, 0, SEEK_END);
	printf("The size of rand2.dat: %d\n", ftell(fp4));
	
	fclose(fp3);
	fclose(fp4);

	return 0;
}