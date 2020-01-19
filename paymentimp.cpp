#include "Payment.h"


payment::payment()
{
	method = "";
	cardnumber = "";
}

payment::payment(char* number, char* type)
{
	if (type == "card")
	{
		method = type;
		cardnumber = number;
	}
	else if (type == "cash")
	{
		method = type;
		cardnumber = "";
	}
}

void payment::setpayment(char* type, char* number)
{
	if (type == "card")
	{
		method = type;
		cardnumber = number;
	}
	else if (type == "cash")
	{
		method = type;
		cardnumber = "";
	}
}

ostream& operator << (ostream& out, payment pay)
{
	if (pay.method == "card")
	{
		out << pay.cardnumber << "," << pay.method;
	}
	else if (pay.method == "cash")
		out << pay.method;
	return out;
}

char* payment::getpayment()
{
	return method;
}

