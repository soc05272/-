#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int **dp, i, j;
	dp = (int **) malloc(sizeof(int *) * 3);

	for(i=0; i<3; i++)
	{
		dp[i] = (int *)malloc(sizeof(int) * 5);
	}

	printf("dp : %p &dp : %p\n", dp, &dp);

	for(i=0; i<3; i++)
	{
		printf("dp+%d(%p) = %p\n", i, dp+i, *(dp+i));
		for(j=0; j<5; j++)
		{
			dp[i][j] = (i+1)*(j+1);
			printf("(%p)dp[%d][%d] = %d\n", *(dp+i)+j, i, j, *(*(dp+i)+j),); // dp[i][j]);
			
		}
		printf("==============================\n");
	}

	return 0;
}	
