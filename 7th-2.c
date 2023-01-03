#include <stdio.h>
#include <string.h>

struct student
{
	int number;
	char name[10];
	int score;
};

int main (void)
{
	struct student s1 = {1,"kim", 99};
	struct student s2 = {2, "lee", 89};
	struct student *sptr = &s1;

	s2.number;
	strcpy(s2.name, "lee");
	s2.score;

	printf("%d  %s  %d\n", sptr->number, sptr->name, sptr->score);
	printf("%d  %s  %d\n", s2.number, s2.name, s2.score);

	return 0;
}	
