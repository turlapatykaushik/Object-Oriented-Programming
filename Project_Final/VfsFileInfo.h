// VfsFileInfo.h
//T KAUSHIK
//IMT2013054

#ifndef VFSFILEINFO_H
#define VFSFILEINFO_H
#include"VfsNodeInfo.h"
struct HeaderRecord;

#include<string>
using namespace std;
class VfsFolderInfo;

class VfsFileInfo : public VfsNodeInfo
{
private:
	int file_offset;
	long files_bytes;
	VfsFolderInfo *parent_folder;
public:
	VfsFileInfo(string name, int offset,long bytes);
	void newHeader(HeaderRecord &);
	void save(string external_path,string repo_path);
	VfsFileInfo(string name,string path);
	virtual void load(string external_path,string repo_path);
	void addFile(VfsFileInfo *var1);
	void setParent(VfsFolderInfo *par);
};

#endif
