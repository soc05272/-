#include <stdio.h>
#include <string.h>

//구조체 선언
struct employee
{
	char name[10];
	int year;
	int pay;
};	

int main(void)
{
	//구조체형 변수 선언
	struct employee lee;
	struct employee kim = {"kim", 2012, 4500};
	struct employee *sptr = &kim;
	
	strcpy(lee.name, "lee");
	lee.year = 2013;
	lee. pay = 3400;

	//printf("%10s  %4d  %4d\n", kim.name, kim.year, kim.pay);
	printf("%10s  %4d  %4d\n", sptr->name, sptr->year, sptr->pay);
	printf("%10s  %4d  %4d\n", lee.name, lee.year, lee.pay);
	
	return 0;
}	
