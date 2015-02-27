//T KAUSHIK
// IMT2013054
//VfsFileInfo.cc

#include"VfsRepository.h"
#include"VfsFolderInfo.h"
#include"VfsFileInfo.h"
#include"VfsFile.h"
#include<iostream>
#include<cstring>
#include<fstream>

using namespace std;

VfsFileInfo::VfsFileInfo(string name, int offset,long bytes) : VfsNodeInfo(name),file_offset(offset),files_bytes(bytes){}
VfsFileInfo::VfsFileInfo(string name,string path):VfsNodeInfo(name,path){}
	
void VfsFileInfo::setParent(VfsFolderInfo *par)
{
	parent_folder=par;
}
void VfsFileInfo::newHeader(HeaderRecord & object_header)
{
	strcpy(object_header.node_name,getNodeName().c_str());
	object_header.node_type=0;
	object_header.size=files_bytes;
	object_header.offset=file_offset;
	strcpy(object_header.folder_path,(parent_folder->folderPath().c_str())); 

}	
void VfsFileInfo::save(string external_path,string repo_path)
{
	fstream file_save;
	file_save.open(repo_path,ios::ate|ios::out| ios::binary);
	VfsFile *object_vfsfile = new VfsFile();
	object_vfsfile->saveInVFS(file_save,file_offset,files_bytes,external_path);
	file_save.close();
}
void VfsFileInfo::load(string external_path,string repo_path)
{
	fstream file_load;
	file_load.open( repo_path,ios::ate|ios::out| ios::binary);
	VfsFile *object_vfsfile = new VfsFile();
	object_vfsfile->exportFile(file_load,file_offset,files_bytes,external_path);
	file_load.close();
}


