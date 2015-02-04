// Reservation.h
// T KAUSHIK
// IMT2013054
#include<iostream>
#include<string>

using namespace std;

class Passenger;
class TrainRun;

class Reservation{
	//Data members
	string coach_num;//coach number of your ticket is declared
	int seat_num;//seat number of your ticket is declared
	Passenger *mypassenger;
	TrainRun *mytrain;
	public:
	//Data methods
	Reservation(string,int);
	void showReservation();
	void setPassenger(Passenger *p);
	void setTrainRun(TrainRun *t);
	string getCoachInfo();
	int getSeatInfo();
};
