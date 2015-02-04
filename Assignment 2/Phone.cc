//Phone.cc
// T KAUSHIK
// IMT2013054

#include<iostream>
#include<string>
#include"Phone.h"

using namespace std;

Phone::Phone(string phone_number)
	{
			phoneNumber = phone_number;
	}

void Phone::call()
	{
			cout << "Calling " << phoneNumber << endl;
	}

