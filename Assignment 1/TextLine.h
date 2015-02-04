#include<string>
using namespace std;
class TextLine
{
	private:
		string text_line;
	public:
		TextLine(string inputline);
		int getTermCount(string search_string);
		void showline();
};
