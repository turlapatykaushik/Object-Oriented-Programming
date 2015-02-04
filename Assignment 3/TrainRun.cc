//TrainRun.cc
//T KAUSHIK
//IMT2013054

#include<iostream>
#include<string>
#include"TrainRun.h"
#include"Reservation.h"
#include"Passenger.h"
#include<iomanip>
#include<vector>
#include<sstream>

using namespace std;

TrainRun::TrainRun(string train_num,string train_sourc,string train_destinatio,string date):train_number(train_num),train_source(train_sourc),train_destination(train_destinatio),journey_date(date)
{
}
/* we wanted to print the ticket as per the given main function ( i.e the pattern ) and so use some methods to print the ticket in that particular design as given in the main function */

void TrainRun::printReservationChart()
{
	// use "width" keyword to form the design as given in main function
	cout<<"Train Number:";
	cout.width(19);cout<<left<<train_number;
	cout<<"Train Source: ";
	cout.width(20);cout<<left<<train_source;
	cout<<"Train Destination: ";
	cout.width(12);cout<<left<<train_destination<<endl;
	cout<<"Date of Journey: "<<journey_date<<endl;
int p_count=passengers.size();
int r_count=reservation.size();
cout<<"PNR: "<<"\t\t";cout<<"\t\t\t\t\t\t"<<"Name"<<"\t\t\t\t\t"<<"Age"<<"\t\t\t\t"<<"Gender"<<endl;
cout<<endl;
int i = 0;
while(i<r_count)
{
	cout<<"Coach: "<<reservation[i]->getCoachInfo()<<"    ";
	cout<<"Seat Number: "<<reservation[i]->getSeatInfo()<<"    ";
	passengers[i]->showPassenger();
	i++;
}


}

void TrainRun::printTrainDetails()
{
	cout<<"TrainNumber: ";
	cout.width(19);cout<<left<<train_number;
	cout<<"TrainSource: ";
	cout.width(20);
	cout<<left<<train_source;
	cout<<"Train Destination: ";
	cout.width(12);cout<<left<<train_destination<<endl;
	cout<<endl;
}
void TrainRun::printjourney_date()
{
	cout<<"Date of Journey: "<<journey_date;
	cout<<"        "<<endl;
}
void TrainRun::reservationValues(Passenger* obj, Reservation *r)
{
	reservation.push_back(r);
	passengers.push_back(obj);
}



