#include "Trips.h"

trip::trip(char*a)
{
	status = a;
}
trip::trip(char*a, char* b, char* c)
{
	status = a;
	pickupLocation = b;
	dropoffLocation = c;
	captian = nullptr;
	rider = nullptr;
}
void trip::changeStatus(char* state)
{
	status = state;
}
char* trip::getstatus()
{
	return status;
}
void trip::ratedriver(int a)
{
	if (a >= 0 && a <= 5)
		driverRating = a;
}
void trip::ratepassenger(int a)
{
	if (a >= 0 && a <= 5)
		passengerRating = a;
}
void trip::setpickupLocation(char* loc)
{
	pickupLocation = loc;
}
void trip::setdropoffLocation(char* loc)
{
	dropoffLocation = loc;
}
void trip::setDriver(driver * dr)
{
	captian = dr;
}
void trip::setpassenger(passengers * dr)
{
	rider = dr;
}


ostream& operator << (ostream& out, trip& other)
{
	cout << "Status: " << other.status << endl;
	cout << "date: " << other.tareekh << endl;
	cout << "PickupLoc = " << other.pickupLocation << endl;
	cout << "DropOffLoc = " << other.dropoffLocation << endl;
	if (other.captian != nullptr)
	{
		cout << other.captian << " is its driver\n";
	}
	if (other.rider != nullptr)
	{
		cout << other.rider << " is its passenger\n";
	}
	if (other.driverRating > 0)
	cout << "Driver's rating " << other.driverRating << endl;
	if (other.passengerRating > 0)
	cout << "Passenger's rating " << other.passengerRating << endl;
	return out;
}
