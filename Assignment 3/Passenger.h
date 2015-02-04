//Passenger.h
//T KAUSHIK
//IMT2013054

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Reservation;
class Ticket;

class Passenger{
	//Data members
	string passenger_name;//Passenger name is declared
	int passenger_age;// passenger age is declared
	char passenger_gender;//passenger gender is declared
	Reservation *myreservation;
	Ticket *my_ticket;
	public:
	//Data methods
	Passenger(string,int,char);
	Reservation* addReservation(string,int);
	void connectTicket(Ticket *);
	void showPassenger2();
	void showPassenger();
};

