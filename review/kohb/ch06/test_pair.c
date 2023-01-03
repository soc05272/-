#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int testPair(char *); // 수식의 괄호를 검사

int main(void)
{
	top = NULL; // 공백 스택을 생성하기
	char exp[] = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";

	if(testPair(exp)) // if(testPair(exp) == 1)
	{
		printf("수식의 괄호가 맞습니다!!\n");
	}
	else
	{
		printf("수식의 괄호가 맞지 않습니다!!\n");
	}
	

	return 0;
}

int testPair(char *exp)
{
	int i, length = strlen(exp);
	char open_pair, symbol;

	for(i=0; i<length; i++)
	{
		symbol = exp[i];
		switch(symbol)
		{
			case '(':
			case '{':
			case '[':
			{
				push(symbol);
				break;
			}
			case ')':
			case '}':
			case ']':
			{
				if(top == NULL)
				{
					return 0;
				}
				open_pair = pop();
				if((open_pair == '(' && symbol != ')') || (open_pair == '{' && symbol != '}') || (open_pair == '[' && symbol != ']'))
				{
					return 0;
				}
				break;
			}
		}
	}	
	if(top == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
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
