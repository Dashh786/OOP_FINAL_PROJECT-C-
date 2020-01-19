#pragma once
#include <iostream>
using namespace std;
#include "Trips.h"
#include "date.h"


class user
{
	
protected:
	char *name;
	date DateOfBirth;
	char *email;
	char* phonenumber;
	int nooftrips;
	trip **trips;
	trip *current_trip;
public:
	static string message;
	user(char* naam, date DOB, char* mail, char* no);
	virtual ostream& print(ostream& out);
	friend ostream& operator << (ostream&, user &);
	char* getname();
	void ChangeName(char* naam);
	void changeDOB(date d);
	void Changephnumber(char* no);
	float getavgrating();
	void printTrips();
	user(const user&);
	virtual void sendmessage(string ) = 0;
	virtual void readmessage() = 0 ;
	virtual void rateDriver(trip* tr, int a) = 0;
	virtual void Ratepassengers(trip* tr, int a) = 0;
	virtual void Endride() = 0;
	virtual void Pickupride(trip* trr) = 0;
	virtual trip* bookride(char*a, char* b) = 0;
	~user();
};