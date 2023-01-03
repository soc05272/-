#include<stdio.h>

void selection(int*, int);
void bubble(int*, int);
void insertion(int*, int);
void printList(int*, int);

int main(void)
{
	int list[] = {69, 10, 30, 2, 16, 8, 31, 22};
	int size = 8;
	int menu;

	while(1)
	{
		printf("1. selection, 2. bubble, 3. insertion, 0. exit\n");
		printf("menu : ");
		scanf("%d", &menu);

		if(menu == 0)
		{
			printf("Bye~~\n");
			break;
		}
		switch(menu)
		{
			case 1:
				selection(list, size);
				break;
			case 2:
				bubble(list, size);
				break;
			case 3:
				insertion(list, size);
				break;
			default:
				printf("메뉴를 잘못 입력했습니다!!\n");
		}
	}

	return 0;
}


void selection(int* list, int size)
{
	int min, temp;
	
	printf("------------ selction sort -----------\n");
	printf("[step 0] ");
	printList(list, size);

	for(int i = 0; i < size-1; i++)
	{
		min = i;
		for(int j = i+1; j < size; j++)
		{
			if(list[j] < list[min])
			{
				min = j;
			}
		}

		temp = list[i];
		list[i] = list[min];
		list[min] = temp;

		printf("[step %d] ", i+1);
		printList(list, size);
	}
	printf("-------------------------------------\n");
}
void bubble(int* list, int size)
{
	int temp, cnt = 0;

	printf("---------- bubble sort--------------\n");
	printf("[step %d] ", cnt);
	printList(list, size);

	for(int i = size-1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(list[j] > list[j+1])
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
		}
		printf("[step %d] ", ++cnt);
		printList(list, size);
	}
	printf("------------------------------------\n");
}

void insertion(int* list, int size)
{
	
	int temp;

	printf("---------- insertion sort--------------\n");
	printf("[step 0] ");
	printList(list, size);

	for(int i = 1; i < size; i++)
	{
		temp = list[i];
		int j = i;
		while((j > 0) && (list[j-1] > temp))
		{
			list[j] = list[j-1];
			j--;
		}
		list[j] = temp;
		printf("[step %d]", i+1);
		printList(list, size);
	}
}

void printList(int* list, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%2d ", list[i]);
	}printf("\n");
}

