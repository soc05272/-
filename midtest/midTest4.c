#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	float avg; //= {'72.5', '80.4', '70.9', '65.9', '95.2'};
	//float p;
	float *p = (float *)malloc(sizeof(float) * 5);


	int i;
	for(i=0; i<5; i++)
	{
		printf("학생 %d의 평균점수를 입력하시오 : ", i+1);
		scanf("%f", &avg);
	}

	
	for(i=0; i<5; i++)
	{
		
		printf("%f\n", *(p+i));
		printf("%p\n", p+i);
	}
	return 0;
}	
