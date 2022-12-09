#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5
#define INF 10000
#define FALSE 0
#define TRUE 1


int cost[][MAX_VERTICES] =
{//  0  1  2  3	 4    
	{0, 6, INF, 7, INF},
	{INF, 0, 5, 8, -4},
	{INF, -2, 0, INF, INF},
	{INF, INF, -3, 0, 9},
	{2, INF, 7, INF, 0}
};

int distance[MAX_VERTICES];
short int found[MAX_VERTICES];
int n = MAX_VERTICES;
int pi[MAX_VERTICES];

int choose(void);
void shortestPath(int v);
void printPath(int src, int dest);

int main(void) {

	int src, dst;

	src = 0;

	printf("도착 Vertex를 입력하세요: ");
	scanf(" %d", &dst);

	shortestPath(src);

	printf("Vertex %d에서 Vertex %d으로 가는 최단 경로의 길이는 %d입니다.\n", src, dst, distance[(dst)]);
	
	return 0;
}

int choose(void) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}



void shortestPath(int v) {

	int i, u, w;

	for (i = 0; i < n; i++) {
		found[i] = FALSE;
		distance[i] = cost[v][i];
		if (distance[i] < INF) {
			pi[i] = v;
		}
	}

	found[v] = TRUE;
	distance[v] = 0;

	for (i = 0; i < n - 2; i++) {
		u = choose();

		found[u] = TRUE;

		for (w = 0; w < n; w++) {
			if (!found[w]) {
				if (distance[u] + cost[u][w] < distance[w]) {
					distance[w] = distance[u] + cost[u][w];
					pi[w] = u;
				}
			}
		}

	}

}


void printPath(int src, int dest) {

	if (src == dest) {
		return;
	}
	else {
		printPath(src, pi[dest]);
		printf("%d ", pi[dest]);
	}

}