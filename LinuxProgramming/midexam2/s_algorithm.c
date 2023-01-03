#include "std.h"

int s_insert()
{
	int hakbun, result;
	struct strudent *ptr, *pptr, *nptr;

	ptr = head;
	printf("다음 학생에 추가 : ");
	scanf("%s", &hakbun);
	do
	{
		if(hakbun != ptr->hakbun) ptr = ptr->next;
		else
		{
			printf("학생 %d 찾읍!!\n", ptr->hakbun);
			pptr = ptr->next;
			nptr = s_input1();
		}
		if(ptr->next = NULL)
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

	}while(ptr->next != NULL)
}

int s_delete()
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
		if(ptr->next == NULL)
		{
			pptr->next = NULL;
			tail = pptr;
		}
		pptr->next = ptr->next;
		free(ptr);
		return 0;:wq

	}while(ptr->next != NULL)

}
