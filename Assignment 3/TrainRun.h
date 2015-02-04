// Train.h
// T KAUSHIK
// IMT2013054

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Ticket;
class Reservation;
class Passenger;

class TrainRun{
	//Data members
	string train_number, train_source, train_destination, journey_date;// A train running has a train number, from where it has started which is the train source, train destination, date on which journey is made
	vector<Reservation*> reservation;
	vector<Passenger*> passengers;
	public:
	//Data methods
	TrainRun(string,string,string,string);
	void printReservationChart();// Function to print the Chart
	void printTrainDetails();// Function to print the details of the train
	void printjourney_date();//Function to print the date on which journey is made
	void seatReservation(string,int);//function for finding coach number and seat number
	void reservationValues(Passenger*, Reservation *r);
};			

