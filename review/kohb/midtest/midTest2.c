#include <stdio.h>
#include <stdlib.h>

typedef struct book_info
{
	int num;
	char title[30];
	int price;
}BOOK;

int main(void)
{
	BOOK b[5];
	BOOK *books;

	books = (BOOK *)malloc(sizeof(BOOK) * 5);
	int i;
	int count = 0;

	for(i=0; i<5; i++)
	{
		printf("number, title, price : ");
		scanf("%d %s %d", &b[i].num, &b[i].title, &b[i].price);
	}

	for(i=0; i<5; i++)
	{
		printf("%d\n %s\n %d\n", b[i].num, b[i].title, b[i].price);
	}
	
	for(i=0; i<5; i++);
	{
		if((20000 <= b[i].price) && (b[i].price <= 30000))
		{
			count += 1;
		}
	}

	printf("20000원 이상 30000원 이하인 책 : %d권\n", count);

	return 0;
}	
