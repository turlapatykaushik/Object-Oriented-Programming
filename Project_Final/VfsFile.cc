#include<iostream>
#include<string>
#include<fstream>
#include"VfsFile.h"
using namespace std;

VfsFile::VfsFile(){}
void VfsFile::exportFile(fstream& load_file,int file_offset,int size,string external_path)
{
	int count = size/SIZE;
	fstream file_exportfile;
	file_exportfile.open(external_path,ios::in|ios::out | ios::binary);
	for(int i = 0 ; i<count;i++)
		{
			load_file.read((char *)&data_bytes,SIZE);
			file_exportfile.write((char *)&data_bytes,SIZE);		
		}
	file_exportfile.close();
}

void VfsFile::saveInVFS(fstream& repository,int file_offset,int size,string external_path)
{
	
	int count;
	fstream file_saveinvfs;
	file_saveinvfs.open(external_path,ios::in|ios::binary);
	file_offset = repository.tellp();
	while(!file_saveinvfs.eof())
		{
		file_saveinvfs.read((char *)&data_bytes,SIZE);
		repository.write((char *)&data_bytes,SIZE);
		count++;		
		}
	size = count*1024;
	file_saveinvfs.close();

}

