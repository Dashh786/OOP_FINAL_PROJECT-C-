#pragma once
#include <iostream>
using namespace std;

class payment
{
	char* method;
	char* cardnumber;
public:
	payment();

	payment(char* cash)
	{
		method = "cash";
		cardnumber = "";
	}
	payment(char* number, char* type);

	void setpayment(char* type, char* number);

	friend ostream& operator << (ostream& out, payment pay);

	char* getpayment();




};