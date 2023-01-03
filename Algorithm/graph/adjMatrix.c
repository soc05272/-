#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

typedef struct graph
{
	int n; // 정점의 수
	int adjMatrix[MAX_VERTEX][MAX_VERTEX]; // 인접행렬
}graphType;

void createGraph(graphType* ); // 그래프를 초기화
void insertVertex(graphType*, int); // 정점을 추가
void insertEdge(graphType*, int, int); // 엣지를 추가
void print_adjMatrix(graphType* ); // 그래프 출력

int main(void)
{
	// G1 만들기
	graphType* G1 = (graphType*)malloc(sizeof(graphType));
	createGraph(G1);

	for(int i = 0; i < 4; i++)
	{
		insertVertex(G1, i);
	}
	
	insertEdge(G1, 0, 1);
	insertEdge(G1, 0, 3);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 2, 1);
	insertEdge(G1, 2, 3);
	insertEdge(G1, 3, 3);
	insertEdge(G1, 3, 3);
	insertEdge(G1, 3, 1);
	insertEdge(G1, 3, 2);

	printf("[G1]\n");
	print_adjMatrix(G1);

	
	// G6 만들기
	graphType* G6 = (graphType*)malloc(sizeof(graphType));
	createGraph(G6);
	for(int i = 0; i < 4; i++)
	{
		insertVertex(G6, i);
	}
	
	insertEdge(G6, 0, 1);
	insertEdge(G6, 0, 2);
	insertEdge(G6, 0, 3);
	insertEdge(G6, 1, 0);
	insertEdge(G6, 1, 2);
	insertEdge(G6, 1, 3);
	insertEdge(G6, 2, 0);
	insertEdge(G6, 2, 1);
	insertEdge(G6, 2, 3);
	insertEdge(G6, 3, 0);
	insertEdge(G6, 3, 1);
	insertEdge(G6, 3, 2);

	printf("[G6]\n");
	print_adjMatrix(G6);
	
	return 0;
}

void createGraph(graphType* g)
{
	g->n = 0;

	for(int i = 0; i < MAX_VERTEX; i++)
	{
		for(int j = 0; j < MAX_VERTEX; j++)
		{
			g->adjMatrix[i][j] = 0;
		}
	}
}


void insertVertex(graphType* g, int v) // 정점을 추가
{
	if((g->n)+1 > MAX_VERTEX)
	{
		printf("그래프 정점의 개수를 초과했습니다!!\n");
		return;
	}

	g->n++;
}

void insertEdge(graphType* g, int u, int v) // 엣지를 추가
{
	if((u >= g->n) || (v >= g->n))
	{
		
		printf("그래프에 존재하지 않는 정점입니다!!\n");
		return;
	}
	g->adjMatrix[u][v] = 1;
}

void print_adjMatrix(graphType* g) // 그래프 출력
{
	for(int i = 0; i < g->n; i++)
	{
		printf("\n");
		for(int j = 0; j < g->n; j++)
		{
		
			printf("%2d", g->adjMatrix[i][j]);
		}
	}printf("\n\n");

}
