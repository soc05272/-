#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct node
{
	element data;
	struct node *link;
}stackNode;

stackNode *top;

void push(element); // 스택에 자료를 삽입하는 연산
element pop(); // 스택에서 top위치에 있는 자료를 삭제
void printStack(); // 스택을 출력

int main(void)
{
	top = NULL; // 공백 스택을 생성하기

	push(10);
	push(20);
	push(30);
	printStack();

	pop();
	printStack();
	pop();
	printStack();
	pop();
	printStack();

	return 0;
}

element pop()
{
	stackNode *temp = top;
	element item;

	if(top == NULL)
	{
		printf("Empty Stack!!!\n");
		return -1;
	}

	item = temp->data;
	top = top->link; // top = temp->link;
	free(temp);
}	
	
void push(element item)
{
	stackNode *temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = NULL;

	temp->link = top;
	top = temp;
}	

void printStack()
{
	stackNode *p = top;

	printf("stack[  ");
	
	while(p) // while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->link;
	}
	printf("]\n");
}	
