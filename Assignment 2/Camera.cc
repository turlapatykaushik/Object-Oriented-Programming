//Camera.cc
// T KAUSHIK
// IMT2013054

#include<iostream>
#include<string>
#include"Camera.h"

using namespace std;

Camera::Camera(string given_make)
	{
			cameraMake = given_make;
			zoomLevel = 0;
	}
void Camera::click()
	{
		cout << "Click! It is " << cameraMake << endl;
	}
