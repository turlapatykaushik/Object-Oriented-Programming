//Ticket.cc
//T KAUSHIK
//IMT2013054

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>
#include"Ticket.h"
#include"TrainRun.h"
#include"Passenger.h"

using namespace std;

Ticket::Ticket(TrainRun *random, string y, string z):trainrun(random),source_passenger(y),destination_passenger(z)
{
static int var = 1;
PNR_number = "HOA20I2123";
stringstream ss;			
ss << PNR_number << var;					
PNR_number = ss.str();
var++;
}

void Ticket::addPassenger(string name,int age,char gender,string coach,int seat_num)
{
	Passenger *passenger_object=new Passenger(name,age,gender);
	passenger.push_back(passenger_object);
	passenger_object->connectTicket(this);
	trainrun-> reservationValues(passenger_object,passenger_object->addReservation(coach,seat_num));
	
}
void Ticket::printTicket()
{
	cout<<endl;
	trainrun->printTrainDetails();
	cout<<"PNR: ";
	cout.width(25);cout<<left<<PNR_number;
	trainrun->printjourney_date();
	cout<<"Ticket Source: "<<source_passenger<<'\t'<<"Ticket Destination: "<<destination_passenger;
	cout<<endl;
	cout<<'\t';
	cout.width(25);cout<<left<<"Passenger List";
	cout.width(20);cout<<left<<"Name";
	cout<<"        ";
	cout.width(5);cout<<left<<"Age";
	cout<<"         ";
	cout.width(10);cout<<left<<"Gender";
	cout<<endl;
	cout<<endl;
	total_members=passenger.size();
	for(int i=0;i<total_members;i++)
	{
		cout<<'\t';
		cout.width(2);
		cout<<left<<i+1;
		passenger[i]->showPassenger();
		cout<<endl;		
	}
	
}
void Ticket::PNRnumber(){cout<<PNR_number<<endl;}

