#include <stdio.h>

#include <string.h>

int main(void)
{
	char *ptr1 = "korea";
	char *ptr2 = "seoul";
	char *ptr3 = "data structure";
	char *ptr[3] = {"korea", "seoul", "data structure"};
	int i,j;

	printf("%s\n", ptr1);
	printf("%s\n", ptr2);
	printf("%s\n", ptr3);

	printf("ptr1: %p,  *ptr1: %c,  &ptr1: %p\n", ptr1, *ptr1, &ptr1);
	printf("ptr2: %p,  *ptr2: %c,  &ptr2: %p\n", ptr2, *ptr2, &ptr2);
	printf("ptr3: %p,  *ptr3: %c,  &ptr3: %p\n", ptr3, *ptr3, &ptr3);

	printf("======================= report ====================\n");

	for(i=0; i<3; i++)
	{
		printf("%d\n", strlen(ptr[i]));

		for(j=0; j<strlen(ptr[i]); j++)
		{
			printf("%p(%c)\n", (ptr[i])+j, *(ptr[i]+j));
		}	
		
						
		printf("-------------------------\n");
	}
	printf("===================================================\n");
	
	return 0;
}
