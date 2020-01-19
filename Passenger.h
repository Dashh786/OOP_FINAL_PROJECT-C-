#pragma once
#include "Users.h"
#include "payment.h"
#include <string>

class trip;
class passengers : public user
{
	friend class trip;
	payment PaymentMethods;

public:
	void Ratepassengers(trip* tr, int a) { cout << "Passenger can't rate himself\n"; };
	void Pickupride(trip* trr) { cout << "Passenger  cannot picks up a ride\n"; };
	void Endride() { cout << "Passenger cannot end any ride\n"; };
	virtual void sendmessage(string);
	passengers(char* naam, date DOB, char* mail, char* pno, payment pay);
	passengers(const passengers&);
	trip* bookride(char*a, char* b);
	ostream& print(ostream& out); 
	void rateDriver(trip* tr, int a);
	void Addpaymentmethod(char* a);
	void cancelride();
	void readmessage();
};
