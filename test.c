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
void deleteLastNode();
void insertLastNode(NODE *);
int searchNode(int); // 노드를 탐색하는 기능
int isEmpty();
void printList();
void printSearchNode(int,int);

int main(void)
{
//	NODE *newNode;
	int data;
	createList();
	printList();
	isEmpty();
	printf("값 : %d\n", isEmpty());
	insertLastNode(makeNode(10));
	isEmpty();
	printList();
	printf("값 : %d\n", isEmpty());
	insertLastNode(makeNode(20));
	insertLastNode(makeNode(30));
	insertLastNode(makeNode(40));
	insertLastNode(makeNode(50));
	printList();

	while(head != NULL)
	{
		deleteLastNode();
		printList();
	}


	//newNode = makeNode(1);
//	insertFirstNode(newNode);
//	printList();
//	deleteFirstNode();
	/*
	insertFirstNode(makeNode(1));
	printList();
	insertFirstNode(makeNode(2));
	printList();
	insertFirstNode(makeNode(3));
	printList();
	
	printSearchNode(1, searchNode(1));
	printSearchNode(100, searchNode(100));
	*/

	//("%d번째있는 노드입니다!\n", searchNode(1));
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

int isEmpty()
{
	if(head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
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

void insertLastNode(NODE *newNode)
{
	NODE *p;

	if(head == NULL)
	{
		head = newNode;
		return;
	}

	p = head;
	while(p->link != NULL)
	{
		p = p->link;	
	}
	p->link = newNode;
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

void deleteLastNode()
{
	NODE *p, *q;

	if(head == NULL)
	{
		printf("Empty List!!!\n");
		return;
	}
	p = q = head;

	while(p->link != NULL)
	{
		q = p;
		p = p->link;
	}
	free(p);

	if(p == head)
	{
		head = NULL;
		return;
	}	
	q->link = NULL;
}	

int searchNode(int data)
{
	NODE *p = head;
	int count = 0;
	while(1)
	{
		count++;
		if(p->data == data)
		{
			break;
		}
		else
		{
			if(p->link != NULL)
			{
				p=p->link;
			}	
			else
			{
				count = -1;
				break;
			}
		}	
		
	}
	return count;
}
void printSearchNode(int data, int pos)
{
	if(pos != -1)
	{
		printf("%d노드는 %d번째 있습니다!\n", data, pos);
	}
	else
	{
		printf("%d는 연결리스트에 존재하지 않습니다!\n", data);
	}
}	
