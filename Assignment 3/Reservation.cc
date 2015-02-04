// Reservation.cc
// T KAUSHIK
// IMT2013054
#include<iostream>
#include<string>
#include"Reservation.h"
#include"Passenger.h"

using namespace std;

Reservation::Reservation(string coach,int seat):coach_num(coach),seat_num(seat){}
void Reservation::setTrainRun(TrainRun *t){mytrain=t;}
void Reservation::setPassenger(Passenger *p){mypassenger=p;}
void Reservation::showReservation(){mypassenger->showPassenger2();}
string Reservation::getCoachInfo(){return coach_num;}
int Reservation::getSeatInfo(){return seat_num;}

