#include <iostream>
#include "date.h"
using namespace std;

#pragma once
class driver;
class passengers;
class trip
{
	friend class passenger;
	friend class driver;
	
	char* status;

	driver *captian;
	passengers *rider;
	
	date tareekh;
	char* pickupLocation;
	char* dropoffLocation;
	int driverRating;
	void ratepassenger(int a);
public:
	int passengerRating;
	void ratedriver(int a);
	trip(char*a);
	trip(char*a, char* b, char* c);
	char* getstatus();
	void changeStatus(char* state);
	void setpickupLocation(char* loc);
	void setdropoffLocation(char* loc);
	void setDriver(driver * dr);
	void setpassenger(passengers * dr);
	friend ostream& operator << (ostream& out, trip& other);



};