#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int parent[15];

void SimpleUnion(int i, int j) {
	parent[i] = j;
}

int SimpleFind(int i) {
	for (; parent[i] >= 0; i = parent[i]);
	return i;
}
int main() {
	SimpleUnion(1, 2);
	SimpleUnion(1, 3);
	SimpleUnion(1, 4);
	SimpleUnion(3, 5);
	SimpleUnion(5, 6);
	SimpleUnion(7, 8);
	SimpleUnion(9, 10);
	SimpleUnion(10, 11);
	SimpleUnion(12, 14);

	for(int i = 1; i <= 15; i++) {
		printf("노드 %d의 루트는 %d\n", i, SimpleFind(i));
	}
}
