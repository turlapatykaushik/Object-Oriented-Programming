#include<iostream>
#include<string>
#include "TextLine.h"
#include <vector>
using namespace std;
class TextDocument
{
	private:
		vector<TextLine*> doc_lines;
		int line_count;
	public:
		TextDocument(istream& is);
		~TextDocument();
		int getTermCount(string search_string);
		void showdocument();
};
