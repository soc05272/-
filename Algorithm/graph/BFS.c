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
}QNode;

typedef struct qtype
{
	QNode* front;
	QNode* rear;
}QType;

void createGraph(graphType*); // 그래프 초기화
void insertVertex(graphType*, int); // 정점을 추가
void insertEdge(graphType*, int, int); // 엣지를 추가
void print_adjList(graphType*); // 인접리스트를 출력

QType* createQueue(); // 큐 생성
int isEmpty(QType*); // 공백 큐 검사
void enQueue(QType*, int); // 큐에 자료 삽입
int deQueue(QType*); // 큐에서 자료 삭제
void BFS_adjList(graphType*, int); // BFS 수행

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

	printf("----- BFS result ----------\n");
	BFS_adjList(G9, 0);
	printf("\n");

	return 0;
}

QType* createQueue()
{
	QType* LQ;
	LQ = (QType*)malloc(sizeof(QType));
	LQ->front = NULL;
	LQ->rear = NULL;

	return LQ;
}

int isEmpty(QType* LQ)
{
	if(LQ->front == NULL)
	{
		//printf("Empty Queue!!!\n");
		return 1;
	}
	else return 0;
}

void enQueue(QType* LQ, int item)
{
	QNode* newNode;
	newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;

	if(isEmpty(LQ))
	{
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else
	{
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

int deQueue(QType* LQ)
{
	QNode* old = LQ->front;
	int item;

	if(isEmpty(LQ)) return 0;
	else
	{
		item = old->data;
		LQ->front = LQ->front->link;
	}
	
	if(LQ->front == NULL)
	{
		LQ->rear = NULL;
	}
	free(old);

	return item;
}

void BFS_adjList(graphType* g, int v)
{
	graphNode *w;
	QType* Q;

	Q = createQueue();
	g->visited[v] = TRUE;

	printf("%c ", v+65);
	enQueue(Q, v);

	while(!isEmpty(Q))
	{
		v = deQueue(Q);
		for(w = g->adjList_H[v]; w!=NULL; w = w->link)
		{
			if(!g->visited[w->vertex])
			{
				g->visited[w->vertex] = TRUE;
				printf("%c ", w->vertex+65);
				enQueue(Q, w->vertex);
			}
		}

	}
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
