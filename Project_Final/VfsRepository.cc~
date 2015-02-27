//T KAUSHIK
// IMT2013054
//VfsRepository.cc

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<map>
#include<cstdlib>
#include"VfsRepository.h"
#include"VfsNodeInfo.h"
#include"VfsFolderInfo.h"
#include"VfsFileInfo.h"
#include"PathString.h"
#include"vfs_errors_def.h"
#include<sys/stat.h>

using namespace std;

bool fileExists(const string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
		return true;
    return false;
}


VfsRepository::VfsRepository():repo_status(CLOSED){}

void VfsRepository::create(string filename,string e_path){
	repo_file_path=e_path;
	repo_name=filename;
	fstream file;
	file.open((e_path),ios::out|ios::binary);
	if(!file.good())
	{
		throw VFS_CREATE_01;
	}
	node_num=0;
	file.write((char*) &node_num,sizeof(int));
	int i = 0;
    	while(i<MAX_NODES)
    	{
    		HeaderRecord *object= new HeaderRecord;
		file.write((char*) &object,sizeof(HeaderRecord));
		i++;	
    	}
    	file.close();
}

void VfsRepository::open(string name,string e_path)
	{	
		repo_name=name;
		repo_file_path=e_path;
		fstream file_name;
		if( !fileExists(repo_file_path) )
			throw VFS_OPEN_01;
		file_name.seekg(0,ios::beg);
		file_name.read((char*) &node_num,sizeof(int));
		int i = 0;
		while(i<node_num)
		{
			HeaderRecord temp_object;
			file_name.read((char*) &temp_object,sizeof(HeaderRecord));
		
	 		if(temp_object.node_type==1)
			{
				string store_node1_name(temp_object.node_name);
				string store_folder1_path(temp_object.folder_path);
				PathString pp (store_folder1_path,"/");
				string path = pp.excludeLast();
				string name = pp.getLast();
				makeDir(path,name);
			}

			else if(temp_object.node_type==0)
			{
				string store_node_name(temp_object.node_name);
				string store_folder_path(temp_object.folder_path);
				nodes[store_node_name+'/'+store_folder_path]= (VfsNodeInfo*)new VfsFileInfo(temp_object.node_name,temp_object.offset,temp_object.size);
			}
			i++;
			}
			node_num++;
			repo_status = OPEN;
		}

	
void VfsRepository::close()
{
	if(repo_status!=OPEN)	
		throw VFS_GEN_01;
	fstream file_close;
	file_close.open(repo_file_path, ios::in | ios::out | ios::binary);
	file_close.seekp(0,ios::beg);
	node_num = nodes.size();
	file_close.write((char*) &node_num,sizeof(int));
	
	for(map<string,VfsNodeInfo*>::iterator it=nodes.begin();it!=nodes.end();it++)
	{
		HeaderRecord initial_object;
		it->second->newHeader(initial_object);
		file_close.write((char*) &initial_object,sizeof(HeaderRecord));
	}
	
	for(int i =0;i< (MAX_NODES - node_num);i++)
	{
		HeaderRecord obj;
		file_close.write((char*) &obj,sizeof(HeaderRecord));
	}
	repo_status = CLOSED;
		
}
void VfsRepository::makeDir(string dir_path,string foldername)
{
	if(dir_path=="")
	{
		if(foldername=="")
		{	
			if(nodes.find(dir_path + '/' + foldername) != nodes.end())
			throw VFS_MAKEDIR_02;	
			VfsFolderInfo *object_folder_info = new VfsFolderInfo("","");
			nodes[""]=object_folder_info;
		}
		else if(foldername != "")
		{
			if(nodes.find(dir_path + '/' + foldername) != nodes.end())
				throw VFS_MAKEDIR_02;
			VfsFolderInfo *parent=(VfsFolderInfo*)nodes[dir_path];
			VfsFolderInfo *object_folder=new VfsFolderInfo(foldername,dir_path);
			nodes[dir_path+'/'+foldername]=(VfsNodeInfo*)object_folder;
			parent->childFolder(object_folder);
			object_folder->parentFolder(parent);
		}
			
	}
	
	if(nodes.find(dir_path) == nodes.end())
	throw VFS_MAKEDIR_01;
	
	else if(dir_path != "")
	{
		VfsFolderInfo *parent=(VfsFolderInfo*)nodes[dir_path];
		VfsFolderInfo *object_folder=new VfsFolderInfo(foldername,dir_path);
		nodes[dir_path+'/'+foldername]=(VfsNodeInfo*)object_folder;
	
		parent->childFolder(object_folder);
		object_folder->parentFolder(parent);
	}
		
	
	node_num++;
}


void VfsRepository::list(string param1,vector<string>& contents)
{
	for(map<string,VfsNodeInfo*>::iterator it=nodes.begin();it!=nodes.end();it++){}
		

		if (param1 == "/")
		param1 = "";
		if(nodes.find(param1) == nodes.end())
		throw VFS_LISTDIR_01;
		VfsFolderInfo *object_folderinfo=(VfsFolderInfo*)nodes[param1];
		object_folderinfo->addIntoFolder(contents);
}
void VfsRepository::copyIn(string e_path, string internal_path)
{
	if( !fileExists(e_path) )
	throw VFS_COPYIN_01;
	if(nodes.find(internal_path) != nodes.end())
	throw VFS_COPYIN_03;
	PathString object(internal_path,"/");
	string final_path = object.excludeLast();
	string name = object.getLast();
	VfsFileInfo *object_fileinfo = new VfsFileInfo(name,final_path);
	VfsFolderInfo *folder = (VfsFolderInfo *) nodes[final_path];
	nodes[internal_path] = (VfsNodeInfo *) object_fileinfo;
	node_num++;
	object_fileinfo->setParent(folder);
	folder->addFile(object_fileinfo);
	object_fileinfo->save(e_path,repo_file_path);
}	
void VfsRepository::copyOut(string internal_path, string e_path)
{
	fstream temp;
	if(nodes.find(internal_path) == nodes.end())
	throw VFS_COPYOUT_01;
	VfsFileInfo *file_info = (VfsFileInfo *) nodes[internal_path];
	fstream repo_file;
	repo_file.open(repo_file_path, ios::in | ios::out | ios::binary);
	if(!repo_file.good())
	throw VFS_COPYOUT_02;
	nodes[internal_path]->load(e_path, repo_file_path); 
	streamoff pos;	
	long size;
	VfsNodeInfo *n ;
	nodes[internal_path]->load(e_path,repo_file_path);
}


