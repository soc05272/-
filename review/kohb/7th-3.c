#include <stdio.h>

typedef struct date
{
	int year, month, day;
}DATE;
//typedef struct date DATE;

void calcDate(DATE, DATE *);

int main(void)
{
	DATE today, tomorrow;

	printf("today : (year month day) : ");
	scanf("%d %d %d", &today.year, &today.month, &today. day);

	//calcDATE 호출
	calcDate(today, &tomorrow);
	printf("today(%d년 %d월 %d일 ) => tomorrow(%d년 %d월 %d일)\n", today.year, today.month, today.day, tomorrow.year, tomorrow.month, tomorrow.day);

	return 0;
}

void calcDate(DATE to, DATE  * tomo)
{
	int term[] = {31, 28, 30, 31, 30, 31, 30, 31,30, 31, 30, 31};

	if(to.month == 12 && to.day == 31)
	{
		tomo->year = to.year + 1;
		tomo->month = 1;
		tomo->day = 1;
	}
	else if(to.day == term[to.month	- 1])
	{
		tomo->year = to.year;
		tomo->month = to.month +1;
		tomo->day = 1;
	}
	else
	{
		tomo->year =  to.year;
		tomo->month = to.month;
		tomo->day = to.day + 1;
	}
}	
