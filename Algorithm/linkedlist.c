#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *link;
}NODE;

NODE* head;

void createList(); // 공백리스트를 생성
NODE* makeNode(int); // 노드 생성
void insertFirstNode(NODE *); // 연결리스트에 첫노드 삽입
void deleteFirstNode(); // 연결리스트에서 첫 노드를 삭제하는 기능
void printList(); // 모든노드의 데이터를 출력

int main(void)
{
	createList();

	//NODE* p = makeNode(1);
	//insertFirstNode(p);
	insertFirstNode(makeNode(1));
	insertFirstNode(makeNode(2));
	insertFirstNode(makeNode(3));
	insertFirstNode(makeNode(4));
	insertFirstNode(makeNode(5));

	printList(); // 5 4 3 2 1

	deleteFirstNode();
	printList();
	deleteFirstNode();
	printList();
	deleteFirstNode();
	printList();
	deleteFirstNode();
	printList();
	deleteFirstNode();
	printList();

	deleteFirstNode();
	
	return 0;
}

void createList()
{
	head = NULL;
}

NODE* makeNode(int data)
{
	NODE* newNode;
	newNode = (NODE *) malloc(sizeof(NODE));
	newNode->data = data;
	newNode->link = NULL;

	return newNode;
}

void insertFirstNode(NODE* newNode)
{
	// 공백리스트인가?
	if(head == NULL)
	{
		head = newNode;
		return;
	}

	newNode->link = head;
	head = newNode;
}

void deleteFirstNode()
{
	NODE* p = head;
	// 공백리스트인가
	if(p == NULL)
	{
		printf("NO deletion!! Empty List!!\n");
		return;
	}
	
	head = p->link;
	free(p);
}

void printList()
{
	NODE* p = head;

	printf("[ ");
	while(p != NULL) // while(p)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf(" ]\n");

}
