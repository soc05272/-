#include <stdio.h>

int main(void)
{
	char *ptr[3] ={ "korea" , "seoul", "data structure"};
	int i;

	for(i=0; i<3; i++)
	{
		printf("%s\n", ptr[i]);
	}
	
	printf("========== report =============\n");

	for(i=0; i<3; i++)
	{	
		printf("ptr[%d]의 주소 : %p\n%s \n", i, &ptr[i], ptr[i]);
	}			

	

	return 0;
}
