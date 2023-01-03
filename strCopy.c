#include <stdio.h>
#include <stdlib.h>

char strCopy(char *, char *);

int main(void)
{
	char str1[100] = "Data Structre";
	char str2[100];

	printf("before : %s\n", str1);

	strcpy(str2, str1);

	printf("after : %s\n", str2);

	return 0;
}

char strCopy(char *str2, char *str1)
{
	int temp;
	for(str1[100] = temp; temp = str2[100];	str2++, str1++);
}	
