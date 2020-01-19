#pragma once
#include <iostream>
#pragma warning(disable: 4996)
#include<cmath>
#include <ctime>
using namespace std;

class date
{
	int day;
	int month;
	int year;
public:
	date();
	date(int a, int b, int c);
	void setdate(int a, int b, int c);
	friend ostream& operator << (ostream& out, date obj);

};
