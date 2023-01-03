#include <stdio.h>
#include <stdlib.h>

//노드의 구조 정의
typedef struct node
{
	int data;
	struct node *link;
}NODE;	

NODE *head;

void createList();
NODE *makeNode(int);
void insertNode(NODE *);
void deleteNode(int);
void printList();
NODE * searchTail();

int main(void)
{
	createList();

	insertNode(makeNode(10));
	insertNode(makeNode(5));
	insertNode(makeNode(20));
	insertNode(makeNode(15));
	insertNode(makeNode(30));
	printList();

	deleteNode(100);
	deleteNode(30);
	printList();
	deleteNode(5);		
	printList();
	deleteNode(15);		
	printList();
	deleteNode(20);		
	printList();
	deleteNode(10);	
	printList();
	deleteNode(10);		

	return 0;
}

void createList()
{
	head = NULL;
}

NODE * makeNode(int data)
{
	NODE *newNode;
	newNode = (NODE *)malloc(sizeof(NODE));
	newNode->data = data;
	newNode->link = newNode;

	return newNode;
}

void insertNode(NODE *newNode)
{
	NODE *p, *q;

	if(head == NULL) // 공백리스트인가?
	{
		head = newNode;
		return;
	}
	p = q = head;
	do
	{
		if(newNode->data < p->data)
		{
			break;
		}
		q = p;
		p = p->link;
	}while(p != head);

	if(p == head && newNode->data < p->data) // 첫 노드로 삽입
	{
		q = searchTail();
		q->link = newNode;
		newNode->link = p;
		head = newNode;
	}
	else if(p == head && newNode->data > p->data) // 마지막 노드로 삽입
	{
		q->link = newNode;
		newNode->link = head;
	}
	else // 중간노드로 삽입
	{
		newNode->link = p;
		q->link = newNode;
	}
}	

NODE * searchTail()
{
	NODE * q = head;

	while(q->link != head)
	{
		q = q->link;
	}
	return q;
}

void deleteNode(int data)
{
	NODE *p, *q;

	if(head == NULL) // 공백리스트인가?
	{
		printf("Empty List!!!\n");
		return;
	}	

	q = p = head;
	do
	{
		if(p->data == data)
		{
			break;
		}
		q = p;
		p = p->link;
	}while(p != head);

	if(p == head && p->data != data) // 삭제하려는 노드가 없는 경우
	{
		printf("No Item!!!\n");
		return;
	}

	if(p == head && p->link == head) // 하나 남은 노드 삭제하는 경우
	{
		head = NULL; // 공백리스트를 만듬
	}	
	else if(p == head) // Delete Firt Node
	{
		q = searchTail();
		q->link = p->link;
		head = p->link;
	}
	else if(p->link == head) // Delete Last Node
	{
		q->link = head;
	}
	else
	{
		q->link = p->link;
	}	
	
	free(p);
}

void printList()
{
	NODE *p = head;

	if(p == NULL)
	{
		printf("[  ]\n");
		return;
	}

	printf("[ ");
	do
	{
		printf("%d ", p->data);
		p = p->link;
	}while(p != head);
	printf(" ]\n");
}	
