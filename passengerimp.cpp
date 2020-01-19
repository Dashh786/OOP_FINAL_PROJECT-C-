#include "Passenger.h"

passengers::passengers(char* naam, date DOB, char* mail, char* pno, payment pay):user(naam,DOB,mail,pno)
{
	PaymentMethods = pay;
}

passengers::passengers(const passengers& other):user(other)
{
	PaymentMethods = other.PaymentMethods;

}
void passengers::readmessage()
{
	if (current_trip != nullptr)
	{
		cout << "Message from driver: ";
			cout << message<< endl;
	}
}
void passengers::sendmessage(string msg)
{
	if (current_trip != nullptr)
	{

		message = msg;
		cout << "Passenger send a message to driver" << endl;
	}
	else
		cout << "No current ride\n";
}

trip* passengers::bookride(char*a, char* b)
{
	if (this->current_trip == nullptr || current_trip->getstatus() == "complete" || current_trip->getstatus() == "end" || current_trip->getstatus() == "cancel")
	{
		trip* as = new trip("looking for driver", a, b);
		current_trip = as;
		current_trip->setpassenger(this);
		trips[nooftrips] = current_trip;
		nooftrips++;
		return this->current_trip;
	}
	else
	{
		cout << "Cannot book two rides at the same time\n";
		return nullptr;
	}

}
ostream& passengers::print(ostream& out)
{
	user::print(out);
	out << "Payment method = " <<  PaymentMethods << endl;
	return out;
}
void passengers::cancelride()
{
	cout << current_trip->getstatus()<< endl;
	if (current_trip->getstatus() == "complete")
	{
		cout << "No current trip present\n";
	}
	else if (current_trip->getstatus() == "cancel")
	{
		cout << "Trip is already cancelled\n";
	}
	else 
		current_trip->changeStatus("cancel");
}
void passengers::rateDriver(trip* tr, int a)
{
	if (a >= 0 && a <= 5)
	{
		for (int i = 0; i < nooftrips; i++)
		{
			if (tr == trips[i])
			{
				if (trips[i]->getstatus() == "complete" || trips[i]->getstatus() == "Complete")
				{
					trips[i]->ratedriver(a);
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


void passengers::Addpaymentmethod(char* a)
{
		if (a == "card")
		{
			payment p("XXXXXXXXXXXX", "card");
			PaymentMethods = p;
		}
		else if (a == "cash")
		{
			payment p("cash");
			PaymentMethods = p;
		}
}