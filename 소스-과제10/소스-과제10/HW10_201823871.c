#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <math.h>
// 1.
typedef struct point
{
	int x;
	int y;
}POINT;
int equal(POINT* p1, POINT* p2);

// 2.
enum shape_type { TRIANGLE, RECTANGLE, CIRCLE };
struct shape
{
	int type;
	
	union
	{
		struct {
			int base, height;
		} tri;
		struct {
			int width, height;
		} rect;
		struct {
			int radius;
		} circ;
		
	}p;
};

// 3.
void set_proverb(char** q, int n);

// 4.
void set_max_ptr(int m[], int size, int** pmax);



int main(void)
{
	printf("\n1)================================================\n");
	POINT p1, p2;
	
	printf("첫번째 점의 좌표를 입력하시오(예: 1, 3): ");
	scanf("%d %d", &p1.x, &p1.y);

	printf("두번째 점의 좌표를 입력하시오(예: 1, 3): ");
	scanf("%d %d", &p2.x, &p2.y);

	if (equal(&p1, &p2) == 1)
	{
		printf("(%d, %d) == (%d, %d)", p1.x, p1.y, p2.x, p2.y);
	}
	else
	{
		printf("(%d, %d) != (%d, %d)", p1.x, p1.y, p2.x, p2.y);
	}

	printf("\n2)================================================\n");
	struct shape s;
	enum shape_type type;

	printf("도형의 타입을 입력하시오(0, 1, 2): ");
	scanf(" %d", &type);

	switch (type)
	{
	case TRIANGLE:
		printf("밑변과 높이를 입력하시오(예를 들어서 10 20): ");
		scanf("%d %d", &s.p.tri.base, &s.p.tri.height);

		printf("면적은 %d\n", (int)(s.p.rect.width * s.p.rect.height));
		break;
	case RECTANGLE:
		printf("가로와 세로의 길이를 입력하시오(예를 들어서 10 20):");
		scanf("%d %d", &s.p.rect.width, &s.p.rect.height);

		printf("면적은 %d\n", (int)(s.p.rect.width * s.p.rect.height));
		break;
	case CIRCLE:
		printf("반지름을 입력하시오(예를 들어서 10): ");
		scanf("%d", &s.p.circ.radius);

		printf("면적은 %d\n", (int)(3.14 * s.p.circ.radius * s.p.circ.radius));
		break;
	default:
		printf("도형의 타입이 잘못 선택되었습니다.\n");
		break;
	}

	printf("\n3)================================================\n");
	int n;
	char* ps;

	printf("몇번째 속담을 선택하시겠습니까? ");
	scanf(" %d", &n);

	set_proverb(&ps, n);

	printf("Selected proverb: %s\n", ps);

	printf("\n4)================================================\n");
	int m[6] = { 5, 6, 1, 3, 7, 9 };
	int* pmax;

	set_max_ptr(m, 6, &pmax);

	printf("가장 큰 값은 %d\n", pmax);

	return 0;
}
int equal(POINT* p1, POINT* p2)
{
	if ((p1->x == p2->x) && (p1->y == p2->y))
	{
		return 1;
	}
	return 0;
}
void set_proverb(char** q, int n)
{
	static char* array[10] = { "A bad shearer never had a good sickle.",
		"A bad workman (always) blames his tools. ",
		"A bad workman quarrels with his tools.",
		"A bad thing never dies.",
		"A bad workman finds fault with his tools.",
		"A bad workman always blames his tools.",
		"A bargain is a bargain.",
		"A barking dog never bites.",
		"A barking dog was never a good hunter." };

	*q = array[n];
}
void set_max_ptr(int m[], int size, int** pmax)
{
	*pmax = m[0];
	for (int i = 1; i < size; i++)
	{
		if (*pmax<m[i])
		{
			*pmax = m[i];
		}
	}
}