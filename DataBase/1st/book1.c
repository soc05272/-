#include <stdio.h>
#include <stdlib.h>
#define NUM 4

typedef struct book
{
	int bnum;
	char title[20];
	char author[20];
	int price;
}Book;

Book b[NUM] = {{1, "database", "yu", 23000}, {2, "java", "kim", 34000}, {3, "unix", "choi", 45000}, {4, "python", "yu", 22000}};

void printMenu();
void searchBook(int);
void printBook();

int main(void)
{
	int num, menu;

	while(1)
	{
		printMenu();
		printf("select menu : ");
		scanf("%d", &menu);

		if(menu == 3) break;
		
		switch(menu)
		{
			case 1:
				printBook();
				break;
			case 2:
				printf("input bNum : ");
				scanf("%d", &num);
				searchBook(num);
				break;
			default:
				printf("wrong number!!!\n");

		}
	}
	
	return 0;
}

void printMenu()
{
	printf("------------------------\n");
	printf("1. book list\n");
	printf("2. search\n");
	printf("3. exit\n");
	printf("------------------------\n");
}

void searchBook(int bNum)
{
	bNum--;
	printf("%d %10s %5s %5d\n", b[bNum].bnum, b[bNum].title, b[bNum].author, b[bNum].price);
}

void printBook()
{
	int i;
	for(i = 0; i < NUM; i++)
	{
		printf("%d %10s %5s %5d\n", b[i].bnum, b[i].title, b[i].author, b[i].price);
	}
}
