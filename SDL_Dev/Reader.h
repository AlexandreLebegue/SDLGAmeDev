#include <iostream>
#include <fstream>
#include<string>
#include <vector>
#include "Biome.h"

#ifndef  DEF_READER
#define DEF_READER

using namespace std;

class Reader {
public:
	Reader();
	Reader(string filepath);
	void selectFile(string filepath) { m_filepath = filepath; }
	void read();
	vector<Biome> genBiomeList();
	string toString();

private:
	string m_filepath;
	

};

#endif