#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 30

// 한 리스트의 노드를 나타내는 구조체
typedef struct graphNode
{
	int vertex;
	struct graphNode* link;
}graphNode;

// 그래프의 구조를 나타내는 구조체
typedef struct graphType
{
	int n;
	graphNode* adjList_H[MAX_VERTEX];
}graphType;

void createGraph(graphType*); // 그래프 초기화
void insertVertex(graphType*, int); // 정점을 추가
void insertEdge(graphType*, int, int); // 엣지를 추가
void print_adjList(graphType*); // 인접리스트를 출력

int main(void)
{
	graphType* G1 = (graphType*)malloc(sizeof(graphType));
	createGraph(G1);
	insertVertex(G1, 4);

	insertEdge(G1, 0, 3);
	insertEdge(G1, 0, 1);
	insertEdge(G1, 1, 3);
	insertEdge(G1, 1, 2);
	insertEdge(G1, 1, 0);
	insertEdge(G1, 2, 3);
	insertEdge(G1, 2, 1);
	insertEdge(G1, 3, 2);
	insertEdge(G1, 3, 1);
	insertEdge(G1, 3, 0);

	print_adjList(G1);

	return 0;
}

void createGraph(graphType *g)
{
	g->n = 0;

	for(int i = 0; i < MAX_VERTEX; i++)
	{
		g->adjList_H[i] = NULL;
	}
}

void insertVertex(graphType* g, int v)
{
	if((g->n+1) > MAX_VERTEX)
	{
		printf("정점의 수가 초과되었습니다!!\n");
		return;
	}
	
	(g->n) += v;
}

void insertEdge(graphType* g, int u, int v)
{
	graphNode* node;

	if(u >= g->n || v >= g->n)
	{
		printf("정점의 번호가 잘못되었습니다!!\n");
		return;
	}

	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}

void print_adjList(graphType* g)
{
	int i;
	graphNode* p;

	for(i = 0; i < g->n; i++)
	{
		printf("%c adjList : ", i+65);
		p = g->adjList_H[i];
		while(p) // while(p != NULL)
		{
			if(p->link != NULL) printf("%c ->", p->vertex+65);
			else printf("%c", p->vertex+65);
			p = p->link;
		}
		printf("\n");
	}
}
