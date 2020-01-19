#pragma once
#include <string>
#include "Users.h"


class trip;
class driver :public user
{
	friend class trip;
	char* drivingLicenseNo;
	char* VehicleIdentNo;
public:
	virtual void sendmessage(string);
	void rateDriver(trip* tr, int a) { cout << "Driver can't rate himself\n"; };
	trip* bookride(char*a, char* b) { cout << "Driver can't book a ride\n"; 
	return nullptr;
	};
	driver(char* naam, date DOB, char* mail, char* pno, char* licence, char* vehicle);
	ostream& print(ostream& out);
	void Pickupride(trip* trr);
	void Endride();
	void Ratepassengers(trip* tr, int a);
	driver(const driver& other);
	void readmessage();
};
