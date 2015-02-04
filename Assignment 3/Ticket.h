//Ticket.h
//T KAUSHIK
//IMT2013054

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class TrainRun;
class Passenger;

class Ticket{
	//Data members
	string PNR_number, source_passenger, destination_passenger; //A ticket has a PNR number and so it is declared as a string
	//A ticket has a source or place at which the passenger boards the train and so it is declared as a string
//A ticket has a destination or place at which the passenger gets off the train and so it is declared as a string
	TrainRun *trainrun; 
	vector<Passenger*> passenger;
	int total_members;
	public:
	//Data methods
	Ticket(TrainRun *,string,string);
	void addPassenger(string,int,char,string,int);
	void printTicket();
	void PNRnumber();
};

