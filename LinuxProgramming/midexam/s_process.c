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

		ptr->fsum = ptr->fkor + ptr->fmath;
		ptr->myavg = ptr->fsum / 2.0;

		korsum += ptr->fkor;
		mathsum += ptr->fmath;
		ptr = ptr->next;
	}while(ptr != NULL);
}

char c_transform(int s)
{
	int temp;
	char c_score;

	temp = s/10;
	switch(temp)
	{
		case 10:
		case 9:
			c_score = 'A';
		case 8:
			c_score = 'B';
		case 7:
			c_score = 'C';
		case 6:
			c_score = 'D';
		default:
			c_score = 'F';

	}
	return c_score;
}

float f_transform(int s)
{

	int temp;
	char f_score;

	temp = s/10;
	switch(temp)
	{
		case 10:
		case 9:
			f_score = 4.0;
		case 8:
			f_score = 3.0;
		case 7:
			f_score = 2.0;
		case 6:
			f_score = 1.0;
		default:
			f_score = 0.0;

	}
	return f_score;
}
