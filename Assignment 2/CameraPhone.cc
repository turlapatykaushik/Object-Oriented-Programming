//CameraPhone.cc
// T KAUSHIK
// IMT2013054

#include<iostream>
#include<string>
#include"Phone.h"
#include"CameraPhone.h"

using namespace std;

CameraPhone::CameraPhone(string number,string given_make):Phone(number),cameraMake(given_make)
{
}

void CameraPhone::click()
{
	cout << "Click!! It is " << cameraMake << endl;
}

