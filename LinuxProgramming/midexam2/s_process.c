#include "std.h"

void s_process();
char c_transform(int);
float f_transform(int);

float korsum, mathsum;
extern struct student *head;
extern int count;

void s_process()
{
	int i;
	korsum = mathsum = 0.0;
	struct student *ptr;

	ptr = head;
	do
	{
		ptr->ckor = c_transform(ptr->kor);
		ptr->cmath = c_transform(ptr->math);
		ptr->fkor = f_transform(ptr->kor);
		ptr->fmath = f_transform(ptr->math);

		ptr->fsum = ptr->kor + ptr->maht;
		pre->myavg = ptr->fsum / 2.0;

		korsum += ptr->kor;
		mathsum += ptr->math;
		ptr = ptr->next;
	}while(ptr != NULL);
}

char c_transform(int s)
{
	int temp = s/10;
	char c_score;

	switch(temp)
	{
		case 1:
			c_score = 'A';
		case 2:
			c_score = 'B';
		case 3:
			c_score = 'C';
		case 4:
			c_score = 'D';
		default:
			c_score = 'F';

		return c_score;
	}
}

float f_transform(int s)
{
	int temp = s/10;
	float f_score;

	switch(temp)
	{
		case 1:
			f_score = 4.0;
		case 2:
			f_score = 3.0;
		case 3:
			f_score = '2.0';
		case 4:
			f_score = 1.0;
		default:
			f_score = 0.0;

		return f_score;
	}
}
