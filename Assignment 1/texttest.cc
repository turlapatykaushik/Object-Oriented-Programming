#include<iostream>
#include<cstdlib>
#include<string>
#include "TextDocument.h"
int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		cout<<"Usage: "<<argv[0]<<"input-string"<<endl;
		exit(1);
	}
	string search_string=argv[1];
	TextDocument tdoc(cin);
	int scount=tdoc.getTermCount(search_string);
	cout<<"The term "<<search_string<<" occurs "<<scount<<" time!"<<endl;
}

