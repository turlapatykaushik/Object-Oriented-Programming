//T KAUSHIK
// IMT2013054
//VfsNodeInfo.cc

#include<iostream>
#include<string>
#include"VfsNodeInfo.h"
using namespace std;

VfsNodeInfo::VfsNodeInfo(string name):node_name(name){}
string VfsNodeInfo::getNodeName()
{
	return node_name;
}
VfsNodeInfo::VfsNodeInfo(string name,string path):node_name(name),node_path(path){}


