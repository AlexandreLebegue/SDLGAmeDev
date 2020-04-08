#include "Reader.h"

Reader::Reader() {
	cout << "Reader initialization ... " << endl;
	m_filepath = "";
}

Reader::Reader(string filepath) {
	cout << "Reader initialization ... " << endl;
	m_filepath = filepath;
}

vector<Biome> Reader::genBiomeList() {
	vector<Biome> biomeList;
	cout << m_filepath << endl;
	if (m_filepath == "") {
		cout << "No path, unable to gen ... " << endl;
		return biomeList;
	}
	ifstream m_file (m_filepath);
	string line;	
	if (!m_file.is_open()) {
		cout << "Unable to open file ... " << endl;
		return biomeList;
	}else{
		while (getline(m_file, line))
		{
			cout << line << endl;
			Biome biome = Biome(line.substr(0, 4));
			biomeList.push_back(biome);
		}
		m_file.close();
		return biomeList;
	}
}