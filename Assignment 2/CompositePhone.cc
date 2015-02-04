// CompositePhone.cc
// T KAUSHIK
// IMT2013054

#include<iostream>
#include<string>
#include "Camera.h"
#include "CompositePhone.h"

using namespace std;

CompositePhone::CompositePhone(string phone_number,string given_make)
	{
		phoneNumber=phone_number;
		camera_object = new Camera(given_make);
	}
void CompositePhone::call()
	{
		cout << "Calling " << phoneNumber << endl;
	}
void CompositePhone::click()
	{
		camera_object->click();
	}

