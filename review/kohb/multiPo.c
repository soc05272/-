#include <stdio.h>

int main(void)
{
	char ch = 'A';
	char *p = &ch;
	char **dp = &p;
	char ***tp = &dp;

	printf("ch : %c,  *p : %c,  **dp : %c, ***tp : %c\n", ch, *p, **dp, ***tp);
	printf("&ch : %p\n", &ch);
	printf("p : %p, &p : %p\n", p, &p);
	printf("dp : %p, &dp : %p\n", dp, &dp);
	printf("tp : %p, &tp : %p\n", tp, &tp);

	return 0;
}	
