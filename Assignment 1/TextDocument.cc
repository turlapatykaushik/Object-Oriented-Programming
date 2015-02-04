#include<iostream>
#include<string>
#include "TextDocument.h"

using namespace std;
TextDocument::TextDocument(istream& is)
{
	string temp;
	while(getline(is,temp))
	{
		TextLine *tptr=new TextLine(temp);
		doc_lines.push_back(tptr);

	}
	line_count=doc_lines.size();
}
TextDocument::~TextDocument()
{
	for(int i=0;i<line_count;i++)
	{
		delete doc_lines[i];
	}
}
int TextDocument::getTermCount(string search_string)
{
	int tcount=0;
	for(int i=0;i<line_count;i++)
	{
		tcount+=doc_lines[i]->getTermCount(search_string);
	}
	return tcount;
}

