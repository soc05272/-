#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *ip;
	float *fp;
	char *cp;
	int i;

	ip = (int *)malloc(sizeof(int)*10);
	fp = (float *)malloc(sizeof(float)*10);
	cp = (char *)malloc(sizeof(char)*10);

	for(i=0; i<10; i++)
	{
		*(ip+i) = i+1;
		*(fp+i) = i+1.1f;
		*(cp+i) = 'A'+i;

		printf("*(ip+%d) = %d,  *(fp+%d) = %.1f,  *(cp+%d) = %c\n", i, *(ip+i), i, *(fp+i), i, *(cp+i));
	}

	for(i=0; i<10; i++)
	{
		printf("ip+%d(%p), fp+%d(%p), cp+%d(%p)\n", i, ip+i, i, fp+i, i, cp+i);
	}

	printf("&ip : %p, &fp : %p, *cp : %p\n", &ip, &fp, &cp);
	printf("*ip : %d, *fp : %.1f, &cp : %c\n", *ip, *fp, *cp);
	printf("ip: %p, fp: %p, cp: %p\n", ip, fp, cp);
	printf("sizeof(ip)=%d, sizeof(fp) =%d, sizeof(cp)=%d\n", sizeof(ip), sizeof(fp), sizeof(cp));

	return 0;
}
