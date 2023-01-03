#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *llink;
	struct node *rlink;
}NODE;

NODE *head;

void createList();
NODE *makeNode(int);
void insertNode(NODE *); // 새 노드를 정렬된 위치에 삽입
void deleteNode(int); // 삭제하려는 노드 삭제
void printList();

int main(void)
{
	int data;
	createList();
	insertNode(makeNode(100));
	insertNode(makeNode(30));
	insertNode(makeNode(50));
	insertNode(makeNode(35));
	//insertNode(makeNode(30));
	printList();

	deleteNode(30);
	printList();
	deleteNode(100);
	printList();
	deleteNode(35);
	printList();
	deleteNode(50);
/*	printList();
	deleteNode(20);
	printList();
	deleteNode(10);
	printList();
	deleteNode(10);*/
	
	
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
	newNode->llink = newNode;
	newNode->rlink = newNode;

	return newNode;
}

void insertNode(NODE *newNode)
{
	NODE *p;

	//공백리스트??
	if(head == NULL)
	{
		head = newNode;
		return;
	}

	p = head;

	do
	{
		if(newNode->data < p->data)
		{
			break;
		}  
		p = p->rlink;
	}while(p != head);
	
	if(p == head && newNode->data < p->data) // 모든 노드가 중간노드
	{
		head = newNode;
	}
	
	newNode->rlink = p;
	newNode->llink = p->llink;
	p->llink->rlink = newNode;
	p->llink = newNode;
	
}	
void deleteNode(int data)
{
	NODE *p;

	if(head == NULL)
	{
		printf("Empty List!!!\n");
		return;
	}

	p = head;

	do
	{
		if(p->data == data)
		{
			break;
		}
		p = p->rlink;
	}while( p != head);

	if(p == head && p->data != data) // 삭제하려는 노드가 없는 경우
	{
		printf("No Item!!!\n");
		return;
	}
	//마지막 하나 남은 노드 삭제하는 경우
	if(p == p->llink && p == p->rlink)
	{
		head = NULL;
		free(p);
		return;
	}	
	if(p == head) // Delete First Node
	{
		head = p->rlink;
	}
	
	// 원형구조에서는 모든 노드는 중간노드
	//p: 삭제할 노드
       //p->link: 삭제할 노드의 앞노드
	//p->rlink: 삭제할 노드의 뒷노드
	p->llink->rlink = p->rlink;
	p->rlink->llink = p->llink;
	
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

	printf("[");
	do
	{
		printf("%d ", p->data);
		p = p->rlink;
	}while(p != head);

	printf("]\n");
}
