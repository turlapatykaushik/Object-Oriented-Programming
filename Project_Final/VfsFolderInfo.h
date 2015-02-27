// VfsFolderInfo.h
// T KAUSHIK
//IMT2013054

#ifndef VFSFOLDERINFO_H
#define VFSFOLDERINFO_H
#include<vector>
#include<map>
#include<string>
#include"VfsNodeInfo.h"
using namespace std;
class VfsFileInfo;

class VfsFolderInfo : public VfsNodeInfo
{
public:
	string node_path;
	VfsFolderInfo *par_folder;
	vector<VfsFolderInfo*> child_folders;
	vector<VfsFileInfo*> folder_files;
	VfsFolderInfo(string , string);
	void childFolder(VfsFolderInfo *var);
	void parentFolder(VfsFolderInfo *par);
	void addIntoFolder(vector<string>& content);
	string folderPath();
	void  newHeader(HeaderRecord &);
	void addFile(VfsFileInfo *var1);
	
};

#endif
