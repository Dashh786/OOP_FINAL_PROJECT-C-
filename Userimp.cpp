#include "Users.h"


string user::message = "Inbox empty";

user::user(char* naam, date DOB, char* mail, char* no)
{
	int l = strlen(naam);
	name = new char[l + 1];
	strcpy(name, naam);
	DateOfBirth = DOB;
	l = strlen(mail);
	email = new char[l + 1];
	strcpy(email, mail);
	l = strlen(no);
	phonenumber = new char[l + 1];
	strcpy(phonenumber, no);
	nooftrips = 0;
	trips = new trip*[10];
	current_trip = nullptr;
}
ostream& user::print(ostream& out)
{
	out << name << endl;
	out << DateOfBirth << endl;
	out << email << endl;
	out << phonenumber << endl;
	out << "Total trips: " << nooftrips << endl;
	if (current_trip == nullptr)
		out << "Currently not driving\n";
	else if (current_trip->getstatus() == "in progress")
		out << "Driving\n";
	else if (current_trip->getstatus() == "complete")
		out << "Done with a ride\n";
	else if (current_trip->getstatus() == "cancel")
		out << "Current ride cancelled\n";
	return out;
}
ostream& operator << (ostream& out, user & other)
{
	other.print(out);
	return out;
}
user::user(const user& other)
{
	int l = strlen(other.name);
	name = new char[l + 1];
	strcpy(name, other.name);
	DateOfBirth = other.DateOfBirth;
	l = strlen(other.email);
	email = new char[l + 1];
	strcpy(email, other.email);
	l = strlen(other.phonenumber);
	phonenumber = new char[l + 1];
	strcpy(phonenumber, other.phonenumber);
	nooftrips = other.nooftrips;
	trips = new trip*[10];
	for (int i = 0; i < nooftrips; i++)
		trips[i] = other.trips[i];
	current_trip = other.current_trip;
}
void user::printTrips()
{
	cout << "\nTotal no. of trips: " << nooftrips << endl;
	for (int i = 0; i < nooftrips; i++)
		cout << *trips[i] << endl << endl;
	cout << "----Thats all :)\n\n\n";

}
void user::ChangeName(char* naam)
{
	name = naam;
}
char* user::getname()
{
	return name;
}
void user::changeDOB(date d)
{
	DateOfBirth = d;
}
void user::Changephnumber(char* no)
{
	phonenumber = no;
}
float user::getavgrating()
{
	float sum = 0.0;
	for (int i = 0; i < nooftrips; i++)
	{
		sum = sum + trips[i]->passengerRating;
	}

	return sum/nooftrips ;
}
user::~user()
{
	delete name;
	delete phonenumber;
	delete email;
	delete current_trip;
	for (int i = 0; i < nooftrips; i++)
		delete trips[i];
	delete trips;
}