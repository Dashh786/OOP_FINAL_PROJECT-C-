#include "date.h"
date::date()
{
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

	day = timePtr->tm_mday;
	month = timePtr->tm_mon + 1;
	year = timePtr->tm_year + 1900;
}
date::date(int a, int b, int c) :day(a), month(b), year(c) 
{	}
void date::setdate(int a, int b, int c)
{
	day = a;
	month = b;
	year = c;
}
ostream& operator << (ostream& out, date obj)
{
	out << obj.day << "/" << obj.month << "/" << obj.year;
	return out;
}