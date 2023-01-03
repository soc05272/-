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
NODE *searchTail();

int main(void)
{
	int data;
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
	newNode->llink = NULL;
	newNode->rlink = NULL;

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
	while(p != NULL)
	{
		if(newNode->data < p->data)
		{
			break;
		}  
		p = p->rlink;
	}	
	
	if(p == head) // Insert First Node
	{
		newNode->rlink =  p;
		p->llink = newNode;
		head = newNode;
	}
	else if(p == NULL) // Insert Last Node
	{
		p = searchTail(); // Search Last Node
		p->rlink = newNode;
		newNode->llink = p;
	}	
	else
	{
		newNode->rlink = p;
		newNode->llink = p->llink;
		p->llink->rlink = newNode;
		p->llink = newNode;
	}
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

	while(p != NULL) // 삭제하려는 노드 탐색
	{
		if(p->data == data)
		{
			break;
		}
		p = p->rlink;
	}
	if(p == NULL) // 삭제하려는 노드가 없는 경우
	{
		printf("No Item!!!\n");
		return;
	}
	//마지막 하나 남은 노드 삭제하는 경우
	if(p->llink == NULL && p->rlink == NULL)
	{
		head = NULL;
	}	
	else if(p == head) // Delete First Node
	{
		p->rlink->llink = NULL;
		head = p->rlink; // 두번쨰 노드로 헤드 갱신
	}
	else if(p->rlink == NULL) // Delete Last Node
	{
		p->llink->rlink = NULL;
	}
	else
	{
		p->llink->rlink = p->rlink;
		p->rlink->llink = p->llink;
	}
	free(p);
}	
void printList()
{
	NODE *p = head;

	printf("[");
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->rlink;
	}
	printf("]\n");
}

NODE * searchTail()
{
	NODE *p = head;
	while(p->rlink != NULL)
	{
		p = p->rlink;
	}
	return p;
}	
