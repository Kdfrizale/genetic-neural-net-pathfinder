#include <string>
#include <vector>
#include <fstream>

#include "utilities.h"

using namespace std;

std::vector<std::string> getBoardInfo(const std::string filename) {
	ifstream  file(filename);
	vector<string> boardInfo;
	string line;
	while (!file.eof()) {
		getline(file, line, ',');
		boardInfo.push_back(line);

	}
	//break up by comma
	return boardInfo;
}


