#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ***dp;
	int i,j,k;

	int score[2][3][5] = {{{50, 50, 50, 50, 50}, {60, 60, 60, 60, 60}, {70, 70, 70, 70, 70}},{{80, 80, 80, 80, 80}, {90, 90, 90, 90, 90}, {85, 85, 85, 85, 85}}};
	dp = (int ***)malloc(sizeof(int **) * 2);
	for(i=0; i<2; i++)
	{
		dp[i] = (int **)malloc(sizeof(int *) * 3);
		for(j=0; j<3; j++)
		{
			printf("%d학년 %d반", i+1, j+1);

			dp[i][j] = (int *)malloc(sizeof(int) * 5);
			for(k=0; k<5; k++)
			{
				printf("%3d점", score[i][j][k]);

				if(k == 4)
				{
					printf("\n");
				}
			}
			if(j == 2)
			{
				printf("--------------------------------\n");
			}	
		}
			
	}
	return 0;
}	
