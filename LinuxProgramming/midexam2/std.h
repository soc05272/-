#include <stdio.h>

struct student
{
	int hakbun;
	char name[20];
	char sex[2];
	int kor, math, mysum;
	char ckor, cmath;
	float fkor, kmath, fsum;
	float myavg;
	struct student *next;
};
