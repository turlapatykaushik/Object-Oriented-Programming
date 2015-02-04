//Camera.h
// T KAUSHIK
// IMT2013054

#include<iostream>
#include<string>

using namespace std;

class Camera
{
		private:
		string cameraMake;
		double zoomLevel;
		enum photoMode{AUTO,NIGHT,SUNNY};
		public:
		Camera(string );
		void click();
};

