#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct book
{
	int bnum;
	char title[20];
	char author[20];
	int price;
	char isbn[20];
}BOOK;

BOOK* b;
int num;

void printMenu();
void printList();
void search(int);

int main(void)
{
	int i;
	char temp[1024], *tok;
	int menu, bNum;
	FILE* fp;

	// 파일로부터 데이터를 읽어들이는 과정
	if((fp = fopen("bookList.txt", "r")) == NULL)
	{
		printf("File OPen Error!!!\n");
		exit(1);
	}

	fscanf(fp, "%d\n", &num);
	b = (BOOK *)malloc(sizeof(BOOK) * num);

	for(i = 0; i < num; i++)
	{
		fgets(temp, sizeof(temp), fp);
		tok = strtok(temp, "\t\n");
		b[i].bnum = atoi(tok);

		tok = strtok(NULL, "\t\n");
		strcpy(b[i].title, tok);

		tok = strtok(NULL, "\t\n");
		strcpy(b[i].author, tok);

		tok = strtok(NULL, "\t\n");
		b[i].price = atoi(tok);

		tok = strtok(NULL, "\t\n");
		strcpy(b[i].isbn, tok);
	}

	while(1)
	{
		printMenu();

		printf("menu : ");
		scanf("%d", &menu);

		if(menu == 3) break;

		switch(menu)
		{
			case 1:
				printList();
				break;
			case 2:
				printf("bnum : ");
				scanf("%d", &bNum);
				search(bNum);
				break;
			default:
				printf("Wrong number!!\n");
		}
	}
	return 0;
}


void printMenu()
{
	printf("============================================\n");
	printf("1. Book List\n");
	printf("2. Search\n");
	printf("3. exit\n");
	printf("============================================\n");
}

void printList()
{
	int i;
	for(i = 0; i < num; i++)
	{
		printf("%d %10s %10s %5d %10s\n", b[i].bnum, b[i].title, b[i].author, b[i].price, b[i].isbn);
	}
}

void search(int bNum)
{
	int i = bNum -1;
	printf("%d %10s %10s %5d\n, %10s\n", b[i].bnum, b[i].title, b[i].author, b[i].price, b[i].isbn);
}
