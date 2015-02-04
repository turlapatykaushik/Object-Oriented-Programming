//CameraPhone.h
// T KAUSHIK
// IMT2013054

#include<iostream>
#include<string>

using namespace std;

class CameraPhone:public Phone
{
	private:
	string cameraMake;
	double zoomLevel;
	enum photoMode{AUTO,NIGHT,SUNNY};
	public:
	CameraPhone(string ,string );
	void click();
};


