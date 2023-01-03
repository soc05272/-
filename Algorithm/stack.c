#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}NODE;

NODE* top;

void createStack(); // 공백스텍 생성
NODE* makeNode(int); // 노드 생성
void push(int); // 삽입
int pop(); // 삭제하는 기능
void printStack(); // 출력

int main(void)
{
	createStack();

	push(10);
	push(20);
	push(30);
	push(40);
	push(50);

	printStack(); // 50 40 30 20 10

	printf("%d\n", pop());
	printStack();
	printf("%d\n", pop());
	printStack();
	printf("%d\n", pop());
	printStack();
	printf("%d\n", pop());
	printStack();
	printf("%d\n", pop());
	printStack();
	
	printf("%d\n", pop());
	
	return 0;
}

void createStack()
{
	top = NULL;
}

NODE* makeNode(int data)
{
	NODE* newNode;
	newNode = (NODE *) malloc(sizeof(NODE));
	newNode->data = data;
	newNode->link = NULL;

	return newNode;
}

void push(int data)
{
	NODE* newNode = makeNode(data);
	//공백스텍인가?
	if(top == NULL)
	{
		top = newNode;
		return;
	}

	newNode->link = top;
	top = newNode;
}

int pop()
{
	NODE* p = top;
	int data;
	// 공백스텍인가?
	if(p == NULL)
	{
		printf("NO deletion!! Empty Stack!!\n");
		return -1;
	}
	
	data = p->data;
	top = p->link;
	free(p);

	return data;
}

void printStack()
{
	NODE* p = top;

	printf("[ ");
	while(p != NULL) // while(p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");

}
