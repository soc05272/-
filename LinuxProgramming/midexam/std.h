#include <stdio.h>
#define MAX_STUDENT 100
struct student
{
	int hakbun;
	char name[20];
	char sex[2];
	int kor, math, mysum;
	char ckor, cmath;
	float fkor, fmath, fsum;
	float myavg;
	struct student * next;
};
