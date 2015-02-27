// T KAUSHIK
// IMT2013054
// VfsNodeInfo.h

#ifndef VFSNODEINFO_H
#define VFSNODEINFO_H
#include"VfsRepository.h"
#include<string>
using namespace std;
class VfsRepository;

class VfsNodeInfo
{
public:
	string node_name;
	enum n_type{FILE,FOLDER};
	VfsNodeInfo::n_type node_type;
        string node_path;
	VfsNodeInfo(string);
	virtual void newHeader(HeaderRecord &)=0;
	string getNodeName();
	VfsNodeInfo(string,string);
	virtual void load(string external_path,string repo_path){};
};

#endif
