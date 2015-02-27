//VfsFolderInfo.cc
// T KAUSHIK
//IMT2013054

#include<iostream>
#include<string>
#include"VfsRepository.h"
#include"VfsNodeInfo.h"
#include"VfsFolderInfo.h"
#include"VfsFileInfo.h"
#include<cstring>
using namespace std;

VfsFolderInfo::VfsFolderInfo(string name, string path): VfsNodeInfo(name,path),node_path(path){}
void VfsFolderInfo::childFolder(VfsFolderInfo *var)
{
	
	child_folders.push_back(var);
}
void VfsFolderInfo::addFile(VfsFileInfo *var1)
{
	folder_files.push_back(var1);
}
void VfsFolderInfo::parentFolder(VfsFolderInfo *par)
{
	par_folder=par;
}
void VfsFolderInfo::addIntoFolder(vector<string>& content)
{
	int len=child_folders.size();
	for(int i=0;i<len;i++)
	{
		string path1 = child_folders[i]->folderPath();
		string name1 = child_folders[i]->getNodeName();
		string path = path1+"/"+name1+"/";
		content.push_back(path);
	}
	int len2=folder_files.size();
	for(int j=0;j<len2;j++)
	{		
		string path2 = folder_files[j]->node_path + "/" + folder_files[j]->node_name;
		content.push_back(path2);
		
	}
}
string VfsFolderInfo::folderPath()
{
	return node_path;
}
void VfsFolderInfo::newHeader(HeaderRecord &object_header)
{

	strcpy(object_header.node_name,getNodeName().c_str());
	object_header.node_type=0;
	strcpy(object_header.folder_path,node_path.c_str());
	
}	
