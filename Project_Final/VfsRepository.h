//T KAUSHIK
// IMT2013054
// VfsRepository.h


#ifndef VFSREPOSITORY_H
#define VFSREPOSITORY_H


#include<vector>
#include<string>
#include<map>

using namespace std;
class VfsNodeInfo;

const int MAX_NAME_LEN=200;
const int MAX_PATH_LEN=200;
const int MAX_NODES=200;

struct HeaderRecord{
	char node_name[MAX_NAME_LEN];
	int node_type;
	int offset;
	int size;
	char folder_path[MAX_PATH_LEN];
	};

class VfsRepository{
private:
	std::string repo_name;
	enum repository_status{OPEN,CLOSED};
	VfsRepository::repository_status repo_status;
	int node_num;
	string repo_file_path;
	vector<VfsNodeInfo*>nodeinfo;
	map<string,VfsNodeInfo*> nodes;
public:
	VfsRepository();
	void create(string ,string);
	void open(string,string );
	void close();
	void makeDir(string ,string );
	void loadHeader();
	void saveHeader();
	void list(string param1,vector<string>& contents);
	void copyIn(string , string );
	void copyOut(string , string );
	};


#endif
