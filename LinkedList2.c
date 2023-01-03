#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}NODE;

NODE *head;

void createList();
NODE *makeNode(int);
void insertFirstNode(NODE *);
void deleteFirstNode();
int searchNode(int); // 노드를 탐색하는 기능
void printList();

int main(void)
{
//	NODE *newNode;

	createList();
//	newNode = makeNode(1);
//	insertFirstNode(newNode);
	printList();
//	deleteFirstNode();
	insertFirstNode(makeNode(1));
	printList();
	insertFirstNode(makeNode(2));
	printList();
	insertFirstNode(makeNode(3));
	printList();
	searchNode(3);
	printf("%d\n", data);
	/*
	deleteFirstNode();
	printList();
	deleteFirstNode();
	printList();
	deleteFirstNode();
	printList();
	*/

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
	newNode->link = NULL;

	return newNode;
}

void insertFirstNode(NODE *newNode)
{
	if(head == NULL)
	{
		head = newNode;
		return;
	}
	newNode->link = head;
	head = newNode;
}	

void printList()
{
	NODE *p = head;

	printf("[");
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("]\n");
}

void deleteFirstNode()
{
	NODE *p;

	if(head == NULL)
	{
		printf("Empty List!!!\n");
		return;
	}
	p = head;
	head = p->link; // or head = head->link;
	free(p);
}	

int searchNode(int data)
{
	NODE *p;
	while( p != NULL)
	{
		if(p->data = 3)
		{
			return data;
		}
		else
		{
			return -1;
		}
	}	
}	
