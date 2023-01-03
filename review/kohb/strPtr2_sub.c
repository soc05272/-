#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printStr(char *);
char *reverse(char *);

int main(void)
{
	char string[] = "Dreams come true!";
	char *ptr = string; // char *ptr = &string[0];

	printStr(ptr); // ptrStr(string);
	printf("%s\n", reverse(ptr));
	
	return 0;
}

void printStr(char *str)
{
	printf("%s\n", str);
}

char *reverse(char *src)
{
	int leng = strlen(src);
	int i, cnt=0;
	//char des[leng];
	char *des;
	des = (char *)malloc(sizeof(char) * leng);

	for(i=leng-1; i>=0; i--)
	{
		des[i] = src[cnt++];
	}
	return des;
}	
