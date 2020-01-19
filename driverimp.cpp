#include "Driver.h"

driver::driver(char* naam, date DOB, char* mail, char* pno, char* licence, char* vehicle): user(naam,DOB,mail,pno)
{
	
	drivingLicenseNo = licence;
	VehicleIdentNo = vehicle;
	
}
ostream& driver::print (ostream& out)
{
	user::print(out);
	out << "Driving Licence no. " <<  drivingLicenseNo << endl;
	out << "Vehicle no. " <<  VehicleIdentNo << endl;
	return out;
}
driver::driver(const driver& other): user(other)
{
	int l = strlen(other.drivingLicenseNo);
	drivingLicenseNo = new char[l + 1];
	strcpy(drivingLicenseNo, other.drivingLicenseNo);
	l = strlen(other.VehicleIdentNo);
	VehicleIdentNo = new char[l + 1];
	strcpy(VehicleIdentNo, other.VehicleIdentNo);
}
void driver::readmessage()
{
	if (current_trip != nullptr)
	cout << "Message from rider: " << message << "\n";
}
void driver::sendmessage(string msg)
{
	if (current_trip != nullptr)
	{

		message = msg;
		cout << "Driver send a message to passenger " << endl;
	}
	else
		cout << "No current ride\n";
}
void driver::Pickupride(trip* trr)
{
	if (trr != nullptr && trr->getstatus() == "looking for driver")
	{
		current_trip = trr;
		current_trip->setDriver(this);
		trr->changeStatus("in progress");
		trips[nooftrips] = current_trip;
		nooftrips++;
	}
	else if (trr->getstatus() == "complete")
	{
		cout << "Trip is already done\n";
	}
	else if (trr->getstatus() == "cancel")
	{
		cout << "Trip is not looking for driver\n";
	}
	else
	{
		cout << "Trip is already in progress\n";
	}
}
void driver::Ratepassengers(trip* tr, int a)
{
	if (a >= 0 && a <= 5)
	{
		for (int i = 0; i < nooftrips; i++)
		{
			if (tr == trips[i])
			{
				if (trips[i]->getstatus() == "complete" || trips[i]->getstatus() == "Complete")
				{
					trips[i]->ratepassenger(a);
				}
				else
				{
					cout << "Trip isn't complete \n";
				}
				break;
			}
		}
	}
	else
		cout << "Rating isn't possible ";
}

void driver::Endride()
{
	if (current_trip->getstatus() == "cancel")
	{
		cout << "Trip is already cancel\n";
	}
	else 
		this->current_trip->changeStatus("complete");
}

