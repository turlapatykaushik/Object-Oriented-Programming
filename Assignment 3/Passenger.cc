//Passenger.cc
//T KAUSHIK
//IMT2013054

#include<iostream>
#include<string>
#include"Passenger.h"
#include"Reservation.h"
#include"Ticket.h"

using namespace std;

Passenger::Passenger(string p_name,int p_age,char p_gender):passenger_name(p_name),passenger_age(p_age),passenger_gender(p_gender){}
Reservation* Passenger::addReservation(string coach_num,int seat_num){
	Reservation *person_reservation=new Reservation(coach_num,seat_num);
	return person_reservation;
}
void Passenger::showPassenger2(){my_ticket->PNRnumber();}
void Passenger::showPassenger(){cout<<"\t\t\t\t"<<passenger_name<<"\t\t\t\t"<<passenger_age<<"\t\t\t\t"<<passenger_gender<<"\t\t\t\t" <<endl;}
void Passenger::connectTicket(Ticket *ticket){my_ticket=ticket;}

