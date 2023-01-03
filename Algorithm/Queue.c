#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}NODE;

typedef struct qtype
{
	NODE* front;
	NODE* rear;
}QType;

QType* createQueue(); 
NODE* makeNode(int); 
void enQueue(QType*, int);
int deQueue(QType*);
void printQueue(QType*);

int main(void)
{
	QType* LQ = createQueue();

	enQueue(LQ, 10);
	enQueue(LQ, 20);
	enQueue(LQ, 30);
	enQueue(LQ, 40);
	enQueue(LQ, 50);

	printQueue(LQ);

	printf("deQueue => %d\n", deQueue(LQ));
	printQueue(LQ);
	printf("deQueue => %d\n", deQueue(LQ));
	printQueue(LQ);
	printf("deQueue => %d\n", deQueue(LQ));
	printQueue(LQ);
	printf("deQueue => %d\n", deQueue(LQ));
	printQueue(LQ);
	printf("deQueue => %d\n", deQueue(LQ));
	printQueue(LQ);
	printf("deQueue => %d\n", deQueue(LQ));
	
	return 0;
}

QType* createQueue()
{
	QType* LQ = (QType* )malloc(sizeof(QType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}

NODE* makeNode(int data)
{
	NODE* newNode;
	newNode = (NODE *) malloc(sizeof(NODE));
	newNode->data = data;
	newNode->link = NULL;

	return newNode;
}

void enQueue(QType* LQ, int data)
{
	NODE* newNode = makeNode(data);
	if(LQ->front == NULL)
	{
		LQ->front = newNode;
		LQ->rear = newNode;
		return;
	}
	
	LQ->rear->link = newNode;
	LQ->rear = newNode;
}

int deQueue(QType* LQ)
{
	NODE* old;
	int item;
	if(LQ->front == NULL)
	{
		printf("Empty Queue!!\n");
		return -1;
	}

	old = LQ->front;
	item = old->data;
	LQ->front = LQ->front->link;

	free(old);
	return item;
}

void printQueue(QType* LQ)
{
	NODE* p = LQ->front;

	printf("[ ");
	while(p != NULL) // while(p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");

}
