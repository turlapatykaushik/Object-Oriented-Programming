// VfsFile.h
//T KAUSHIK
//IMT2013054


#ifndef VFSFILE_H
#define VFSFILE_H

#include<string>
using namespace std;

class VfsFile
{
private:
	char data_bytes[1024];
	
public:
	const int SIZE = 1024;
	void exportFile(fstream& load_file,int ,int ,string);
	void saveInVFS(fstream& repository,int ,int ,string); 
	VfsFile();
	
};

#endif
