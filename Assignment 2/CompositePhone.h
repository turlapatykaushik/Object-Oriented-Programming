// CompositePhone.h
// T KAUSHIK
// IMT2013054

#include<iostream>
#include<string>

using namespace std;

class CompositePhone
{
	private:
	string phoneNumber;
	enum phoneState{IDLE,IN_USE} ;
	Camera *camera_object;
	public:
	CompositePhone(string ,string );
	void call();
	void click();
};


