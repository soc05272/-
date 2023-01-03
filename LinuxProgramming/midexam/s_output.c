#include "std.h"

void s_output();
void s_class_output();

extern float korsum, mathsum;
extern int count;
extern struct student *head;

void s_output()
{
	int i;
	struct student *ptr;

	ptr = head;

	printf("+-------------------------------------+\n");
	printf("|학번 	이름  성별  국어 	수학	평균	|\n");
	printf("+-------------------------------------+\n");

	do
	{
		if(ptr->hakbun == -1) return;
		printf("%d %10s %2s %3d %c %.2f %3d %c %.2f	%.2f\n", ptr->hakbun, ptr->name, ptr->sex, ptr->kor, ptr->ckor, ptr->fkor, ptr->math, ptr->cmath, ptr->fmath, ptr->myavg);
		ptr = ptr->next;
	}while(ptr != NULL);
}

void s_class_output()
{
	float koravg, mathavg, classavg;

	koravg = korsum / count;
	mathavg = mathsum / count;
	classavg = (koravg + mathavg) /2.0;

	printf("+-------------------------------------+\n");
	printf("|학급총점 :	%.2f	%.2f\n", korsum, mathsum);
	printf("|학급 평균 :	%.2f	%.2f\n", koravg, mathavg);
	printf("|학급 전체 평균 :	%.2f\n", classavg);
	printf("+-------------------------------------+\n");
}
