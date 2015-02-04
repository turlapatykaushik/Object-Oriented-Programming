// Phone.h
// T KAUSHIK
// IMT2013054

#include<iostream>
#include<string>

using namespace std;

class Phone
{
		private:
		string phoneNumber;
		enum phoneState{IDLE,IN_USE};
		public:
		Phone(string );
		void call();
};
