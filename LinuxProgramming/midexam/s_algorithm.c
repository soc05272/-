#include "std.h"
#include <stdlib.h>

int s_insert(), s_search(int), s_delete(int);
extern void s_output();
extern struct student *s_input1();
extern struct student *head, *tail;
extern int count;

int s_insert()
{
	int hakbun, result;
	struct student *ptr, *pptr, *nptr;

	ptr = head;
	printf("다음 학생 뒤에 추가 : ");
	scanf("%d", &hakbun);
	do
	{
		if(hakbun != ptr->hakbun)
		{
			ptr = ptr->next;
		}
		else
		{
			printf("학번 %d 찾음\n", ptr->hakbun);
			pptr = ptr->next;
			nptr = s_input1();

			if(ptr->next == NULL) // Last Student
			{
				nptr->next = NULL;
				ptr->next = nptr;
				tail = nptr;
			}
			else
			{
				ptr->next = nptr;
				nptr->next = pptr;
			}
			return 0;
		}
	}while(ptr != NULL);
	printf("해당학번이 존재하지 않음!!!\n");
	return -1;
}

int s_search(int hakbun)
{
	struct student *ptr;

	ptr = head;
	do
	{
		if(hakbun != ptr->hakbun)
		{
			ptr = ptr->next;
		}
		else
		{
			printf("\n");
			printf("+-----------------------------------------+");
			printf("|학번 	이름 성별 국어 		수학 	평균|\n");
			printf("+-----------------------------------------+");
			printf("%d %10s %2s %3d %c %.2f %3d %c %.2f  %.2f\n", ptr->hakbun, ptr->name, ptr->sex, ptr->kor, ptr->ckor, ptr->fkor, ptr->math, ptr->cmath, ptr->fmath, ptr->myavg);

		}
		return 0;
	}while(ptr != NULL);	
}

int s_delete(int hakbun)
{
	struct student *ptr, *pptr;

	ptr = head;
	do
	{
		if(hakbun != ptr->hakbun)
		{
			pptr = ptr;
			ptr = ptr->next;
			continue;
		}
		else
		{
			if(ptr->next == NULL) // Last Student
			{
				pptr->next = NULL;
				tail = pptr;
			}
			pptr->next = ptr->next;
			free(ptr);
			return 0;
		}
	}while(ptr != NULL);
	printf("해당 학번의 학생이 존재하지 않음!!!\n");
	return -1;
}
