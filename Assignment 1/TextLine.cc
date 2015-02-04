#include<iostream>
#include "TextLine.h"
#include<string>
#include<vector>
using namespace std;
TextLine::TextLine(string inputline)
{
	text_line=inputline;
}
int TextLine::getTermCount(string search_string)
{
	int string_count=0;
	size_t str_position;
	str_position = text_line.find(search_string,0);
		while(str_position <text_line.size() && str_position>=0)
		{
			string_count++;
			str_position = text_line.find(search_string,str_position+1);
		}
	return string_count;
	
}

void TextLine::showline()
{
	cout<<"Line is: " << text_line<<endl;
}
