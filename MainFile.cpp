#include <string>
#include <iostream>
#include <typeinfo>
#include "payment.h"
#include "date.h"
#include "driver.h"
#include "Passenger.h"
#include "Trips.h"
#include <fstream>
using namespace std;
const int SIZE=20;
//an array of trips to keep pointers of all the trips of uber application
//This array will keep data of all the trips ever created. 
user **Userarray = new user*[SIZE];
trip **uberTrips = new trip*[SIZE];
int usersize = 0;
int n = 0;


void addToUberTrips(trip* t)// function to add new trips to uberTrips
{
	if(n<SIZE-1 && t!=nullptr)
	{
		uberTrips[n++]= t;
	}
} 
void printUsers()
{
	cout << "\nThere are --<< " << usersize << " >>-- users present \n";
	for (int i = 0; i < usersize; i++)
	{
		cout << "\n---<< " << i + 1 << " >>---\n\n";
		cout << *Userarray[i];
	}
}
void printUberTrips() //function to print uberTrips
{
	cout << "\nThere are --<< " << n << " >>-- trips present \n";
	for(int i=0; i<n; i++)
	{
		cout << "\n---<< " << i + 1 << " >>---\n\n";
		cout<< *uberTrips[i]<<endl;
	}
}

void readfromfile(string file)
{
	ifstream read;
	read.open(file);
	if (read.is_open())
	{
			char type;
			char* name = new char[25];
			int d;
			int m;
			int y;
			char* mail = new char[25];
			char* pno = new char[25];
		while (!read.eof())
		{
			read >> type;
			read.ignore(1, ',');
			read.getline(name, 25, ',');
			read >> d;
			read >> m;
			m *= -1;
			read >> y;
			y *= -1;
			read.ignore(1, ',');
			read.getline(mail, 35, ',');
			read >> pno;
			if (type == 'p')
			{
				Userarray[usersize] = new passengers(name, date(d, m, y), mail, pno, "cash");
				usersize++;
			}
			else if (type == 'd')
			{
				Userarray[usersize] = new driver(name, date(d, m, y), mail, pno, "LinXXXXX", "VINXXXX");
				usersize++;
			}
			
		}
	}



}
void main()
{

	passengers * p1 = new passengers("P1", date(10, 10, 1990), "ali@yahoo.com", "0334564334", payment("111-222-333-333", "card"));
	driver *d1 = new driver("D1", date(16, 1, 1990), "ayesha@yahoo.com", "0357757585", "Lin1197717", "VIN9817917");
	//////Test Case 1, user books, driver picks, driver ends (rating can be given only in this case)
	cout << *p1 << endl;
	cout << *d1 << endl;

	addToUberTrips(p1->bookride("A", "B"));// will create a new trip and add it to uberTrips array
	cout << *uberTrips[n - 1];// will print this trip
	addToUberTrips(p1->bookride("C", "D"));//prints error as p1 has already booked a ride
	d1->Pickupride(uberTrips[n - 1]); //will assign  d1 to uberTrip[0], the status of this ride will also change to InProgress
	d1->Ratepassengers(uberTrips[n - 1], 5); //error as the trip is not complete
	p1->rateDriver(uberTrips[n - 1], 4); //error as the trip is not complete

	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->Endride(); //will change the status of uberTrip[0] to Complete

	d1->Ratepassengers(uberTrips[n - 1], 5); //error as the trip is not complete
	p1->rateDriver(uberTrips[n - 1], 4); //error as the trip is not complete
	cout << *uberTrips[n - 1] << endl;
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->Pickupride(uberTrips[n - 1]);//prints error as the ride is completed
	cout << "-------------------------------------" << endl;

	//////Test case 2: User books, driver picks, user cancels, ratings are not applicable to cancelled ride
	addToUberTrips(p1->bookride("C", "D"));
	d1->Pickupride(uberTrips[n - 1]);
	cout << *p1 << endl;
	cout << *d1 << endl;
	p1->cancelride();
	p1->cancelride();//error as there is no current ride
	cout << *p1 << endl;
	cout << *d1 << endl;
	d1->Ratepassengers(uberTrips[n - 1], 5); //error as the ride was not complete
	p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete
	cout << "-----------------------------------------\n----------------" << endl;

	//Test Case 3: User Books, user Cancels, driver cannot pick this ride now, ratings are not applicable to this ride
	addToUberTrips(p1->bookride("D", "E"));
	p1->cancelride();
	d1->Pickupride(uberTrips[n - 1]); //error as this ride is not looking for driver
	d1->Ratepassengers(uberTrips[n - 1], 5); //error as the ride was not complete
	p1->rateDriver(uberTrips[n - 1], 5); //error as the ride was not complete
	cout << "-------------------------------------" << endl;

	////Test Case 4: getting avg ratings and print trip funnction
	//Adding some more test data
	addToUberTrips(p1->bookride("X", "Y"));
	d1->Pickupride(uberTrips[n - 1]);
	d1->Endride();
	d1->Ratepassengers(uberTrips[n - 1], 3);
	p1->rateDriver(uberTrips[n - 1], 5);

	addToUberTrips(p1->bookride("X", "Y"));
	d1->Pickupride(uberTrips[n - 1]);
	d1->Endride();
	d1->Ratepassengers(uberTrips[n - 1], 6);//error as the rating is not between 1 and 5 
	d1->Ratepassengers(uberTrips[n - 1], 4);
	d1->Ratepassengers(uberTrips[n - 1], 3);// will upate the passanging rating from 4 to 3
	p1->rateDriver(uberTrips[n - 1], 1);
	cout << "-------------------------oh9ohhp\n";
	p1->printTrips();
	d1->printTrips();
	cout << "________________________________\n";
	cout << p1->getavgrating()<< endl ;
	cout << d1->getavgrating()<< endl ;

	printUberTrips();

	readfromfile("inputusers.txt");
	addToUberTrips(Userarray[0]->bookride("Androon lahore", "defence Phase II"));
	Userarray[1]->Pickupride(uberTrips[n - 1]);
	Userarray[1]->sendmessage("Jigar kahan jana hy?");
	Userarray[0]->readmessage();
	Userarray[0]->sendmessage("Jahan khushi se le chalo");
	Userarray[1]->Endride();
	Userarray[0]->rateDriver(uberTrips[n - 1], 5);
	Userarray[1]->Ratepassengers(uberTrips[n - 1], 4);
	addToUberTrips(Userarray[2]->bookride("Shaalmi", "Nagan churangi"));
	Userarray[0]->Pickupride(uberTrips[n - 1]);
	Userarray[0]->Endride();
	Userarray[0]->Ratepassengers(uberTrips[n - 1], 3);
	Userarray[2]->rateDriver(uberTrips[n - 1], 4);

	printUberTrips();


	
}