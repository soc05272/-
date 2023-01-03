#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char **dp;
	int i, j;
	dp = (char**)malloc(sizeof(char *) * 2);

	for(i=0; i<2; i++)
	{
		dp[i] = (char *)malloc(sizeof(char) * 4);
	}

	printf("&dp = %p, dp = %p\n", &dp, dp);

	for(i=0; i<2; i++)
	{
		printf("dp+%d(%p) : %p\n", i, dp+i, *(dp+i));
		for(j=0; j<4; j++)
		{
			printf("학생의 점수를 입력하시오 :");
			scanf("%s", &dp[i][j]);
			
			printf("(%p)*(*(dp+%d)+%d) = %c\n", *(dp+i)+j, i, j, *(*(dp+i)+j));
			printf("%c의 주소 : %p\n", *(*(dp+i)+j), &dp[i][j]);
		}
		printf("==========================\n");
	}	
	return 0;
}	



