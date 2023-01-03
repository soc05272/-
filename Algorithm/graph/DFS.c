#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 10
#define TRUE 1
#define FALSE 0

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
	int visited[MAX_VERTEX];
}graphType;

typedef struct node
{
	int data;
	struct node* link;
}stackNode;

stackNode* top;
void createGraph(graphType*); // 그래프 초기화
void insertVertex(graphType*, int); // 정점을 추가
void insertEdge(graphType*, int, int); // 엣지를 추가
void print_adjList(graphType*); // 인접리스트를 출력
void push(int);
int pop();
void DFS_adjList(graphType*, int);

int main(void)
{
	graphType* G9 = (graphType*)malloc(sizeof(graphType));
	createGraph(G9);
	insertVertex(G9, 7);

	insertEdge(G9, 0, 2);
	insertEdge(G9, 0, 1);
	insertEdge(G9, 1, 4);
	insertEdge(G9, 1, 3);
	insertEdge(G9, 1, 0);
	insertEdge(G9, 2, 4);
	insertEdge(G9, 2, 0);
	insertEdge(G9, 3, 6);
	insertEdge(G9, 3, 1);
	insertEdge(G9, 4, 6);
	insertEdge(G9, 4, 2);
	insertEdge(G9, 4, 1);
	insertEdge(G9, 5, 6);
	insertEdge(G9, 6, 5);
	insertEdge(G9, 6, 4);
	insertEdge(G9, 6, 3);

	print_adjList(G9);

	printf("----- DFS result ----------\n");
	DFS_adjList(G9, 0);
	printf("\n");

	return 0;
}

void DFS_adjList(graphType* g, int v)
{
	graphNode* w;
	top = NULL;
	push(v);
	g->visited[v] = TRUE;
	printf("%c ", v+65);

	while(top)
	{
		w = g->adjList_H[v];
		while(w)
		{
			if(!g->visited[w->vertex])
			{
				push(w->vertex);
				g->visited[w->vertex] = TRUE;
				printf("%c ", w->vertex+65);
				v = w->vertex;
				w = g->adjList_H[v];
			}
			else w = w->link;
		}
		v = pop();
	}
}

void push(int item)
{
	stackNode* temp;
	temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

int pop()
{
	stackNode* temp = top;
	int item;

	if(top == NULL)
	{
		printf("Stack is Empty!!\n");
		return -1;
	}
	item = temp->data;
	top = temp->link;
	free(temp);

	return item;
}

void createGraph(graphType *g)
{
	g->n = 0;

	for(int i = 0; i < MAX_VERTEX; i++)
	{
		g->adjList_H[i] = NULL;
		g->visited[i] = FALSE;
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
			if(p->link != NULL) printf("%c -> ", p->vertex+65);
			else printf("%c", p->vertex+65);
			p = p->link;
		}
		printf("\n");
	}
}
