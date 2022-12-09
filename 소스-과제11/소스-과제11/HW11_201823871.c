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

	printf("ù��° ����: ");
	scanf("%s", fname1);
	printf("�ι�° ����: ");
	scanf("%s", fname2);

	if ((fp1 = fopen(fname1, "r")) == NULL)
	{
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", fname1);
		exit(1);
	}
	if ((fp2 = fopen(fname2, "w")) == NULL)
	{
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", fname2);
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

	printf("ù��° ����: ");
	scanf("%s", fname1);
	printf("�ι�° ����: ");
	scanf("%s", fname2);

	if ((fp1 = fopen(fname1, "r")) == NULL)
	{
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", fname1);
		exit(1);
	}
	if ((fp2 = fopen(fname2, "r")) == NULL)
	{
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", fname2);
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

	printf("���ϸ��� �Է��ϼ���: ");
	scanf("%s", fname);

	if ((fp = fopen(fname, "rb")) == NULL)
	{
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", fname);
		exit(1);
	}

	for (int i = 0; i < SIZE; i++)
	{
		fread(&s, sizeof(struct student), 1, fp);
		printf("�̸� = %s, ���� = %.1f, ���� = %.1f, ���� = %.1f\n", s.name, s.korean, s.english, s.math);
		ksum += s.korean;
		esum += s.english;
		msum += s.math;
	}
	fclose(fp);

	printf("���: ���� = %.2f, ���� = %.2f, ���� = %.2f\n", ksum / SIZE, esum / SIZE, msum / SIZE);

	
	printf("\n4)================================================\n");
	FILE* fp3, * fp4;
	
	char fname3[100], fname4[100];
	int num[100];
	
	// ù��° ���ϸ��� rand1.txt, �ι�° ���ϸ��� rand2.dat�� ����ڷκ��� �Է� ����
	printf("ù��° ����: ");
	scanf("%s", fname3);
	printf("�ι�° ����: ");
	scanf("%s", fname4);
	
	// �� ������ ���� ������ ������ ������ ���� ���ٴ� �޽��� ���
	if ((fp3 = fopen(fname3, "w")) == NULL)
	{
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", fname3);
		exit(1);
	}
	if ((fp4 = fopen(fname4, "ab")) == NULL)
	{
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", fname4);
		exit(1);
	}

	// �Լ� rand�� �̿��� ������ �����ϰ� �����ϰ� ���� ������ ���� ȭ�鿡 ����� �� 
	// rand1.txt���� fprintf, rand2.dat���� fwrite�� �̿��� ��(100�� �ݺ��ؼ� ������ 100�� ������ ����)
	srand((unsigned)time(NULL));
	for (int i = 0; i < 100; i++)
	{
		num[i] = rand();
		printf("%d", num[i]);
		fprintf(fp3, "%d", num[i]);
	}
	printf("\n");
	fwrite(num, sizeof(int), 100, fp4);

	// �� ������ ����� ���� ������ ���� ���
	fseek(fp3, 0, SEEK_END);
	printf("The size of rand1.txt: %d\n", ftell(fp3));
	fseek(fp4, 0, SEEK_END);
	printf("The size of rand2.dat: %d\n", ftell(fp4));
	
	fclose(fp3);
	fclose(fp4);

	return 0;
}