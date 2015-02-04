#include<iostream>

using namespace std;

#include "Camera.h"
#include "Phone.h"
#include "CameraPhone.h"
#include "CompositePhone.h"

main()
{
	Camera c1("Nikon-standalone-camera");
	c1.click();

	Phone p1("+91-80-41407777");
	p1.call();

	CameraPhone cp1("+91-80-41407777", "Nikon-Integrated-Camera");
	cp1.call();
	cp1.click();

	CompositePhone cp2("+91-80-41407777", "Nikon-Embedded-Camera");
	cp2.call();
	cp2.click();
}

