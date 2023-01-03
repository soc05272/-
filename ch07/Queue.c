#include <stdio.h>
#include <stdlib.h>

typedef char element;
typedef struct node
{
	element data;
	struct node *link;
}QNode;

typedef struct type
{
	QNode * front, *rear;
}QType;

QType *createQueue(); // 공백큐 생성
void enQueue(QType *, element); //  큐에 자료를 삽입하는 연산
void printQueue(QType *); // 큐를 출력
element deQueue(QType *);

int main(void)
{
	QType *LQ;
	LQ = createQueue();

	enQueue(LQ, 'A');
	enQueue(LQ, 'B');
	enQueue(LQ, 'C');
	enQueue(LQ, 'D');
	enQueue(LQ, 'E');
	printQueue(LQ);

	while(LQ->front)
	{	
		deQueue(LQ);
		printQueue(LQ);
	}	

	
	deQueue(LQ);
	return 0;
}

void enQueue(QType *LQ, element data)
{
	QNode *newNode;

	newNode = (QNode *)malloc(sizeof(QNode));
	newNode->data = data;
	newNode->link = NULL;

	//공백 큐인가?
	if(LQ->front == NULL && LQ->rear == NULL)
	{
		LQ->front = LQ->rear = newNode;
	}
	else
	{
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}

element deQueue(QType *LQ)
{
	element item;
	QNode *temp;

	temp = LQ->front;

	// Empty Queue??
	if(LQ->front == NULL && LQ->rear == NULL)
	{
		printf("No Deletion...Empty Queue!!!\n");
		return 0;
	}
	temp = LQ->front;
	item = temp->data;

	LQ->front = LQ->front->link;
	if(LQ->front == NULL)
	{
		LQ->rear = NULL;
	}
	free(temp);

	return item;
}	

void printQueue(QType *LQ)
{
	QNode *p = LQ->front;
	printf("Queue[ ");
	while(p) // while(p != NULL)
	{
		printf("%c ", p->data);
		p = p->link;
	}
	printf("]\n");
}	

QType *createQueue()
{
	QType *LQ;
	LQ = (QType *)malloc(sizeof(QType));

	LQ->front = NULL;
	LQ->rear = NULL;

	return LQ;
}
