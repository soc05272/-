#include <stdio.h>

typedef struct node
{
	int data;
	struct node *link;
}NODE;	

int main(void)
{
	NODE n1, n2, n3, n4;
	NODE *head = &n1;
	NODE *p = head;

	n1.data = 1;
	n1.link = &n2;
	n2.data = 2;
	n2.link = &n3;
	n3.data = 3;
	n3.link = &n4;
	n4.data = 4;
	n4.link = NULL;
	

	/*
	printf("%p(%d, %p)\n", &n1, n1.data, n1.link);
	printf("%p(%d, %p)\n", &n2, n2.data, n2.link);
	printf("%p(%d, %p)\n", &n3, n3.data, n3.link);
	*/
	while(p != NULL)
	{
		
		printf("%p(%d, %p)\n", p, p->data, p->link);
		p = p->link;

	}	
	return 0;
}	
