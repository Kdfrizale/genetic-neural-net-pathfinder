#include <fstream>
#include <iostream>
#include <string>

#include "Tester.h"
#include "utilities.h"
#include "Population.h"

using namespace std;
using namespace KD_TesterClass;

class Tester {
public:
	void testEachNeuralNet(KD_PopulationClass::Population &population);
	void displayBestNeuralNet(KD_PopulationClass::Population &population);
	

private:
};

vector<string> getBoardInfo(const string filename) {
	ifstream  file (filename);
	vector<string> boardInfo;
	string line;
	while (!file.eof()) {
		getline(file, line, ',');
		boardInfo.push_back(line);
		
	}
	//break up by comma
	return boardInfo;
}



void KD_TesterClass::Tester::testEachNeuralNet(KD_PopulationClass::Population &population) {
	bool satisfied1 = false;
	bool satisfied2 = false;
	bool satisfied3 = false;
	bool satisfied = false;
	int count = 0;
	while (!satisfied && count < NUMBER_OF_TRIALS_PER_NET) {
		satisfied1 = population.testAll(getBoardInfo(NAME_OF_BOARD));
		satisfied2 = population.testAll(getBoardInfo(NAME_OF_BOARD2));
		satisfied3 = population.testAll(getBoardInfo(NAME_OF_BOARD3));
		//displayBestNeuralNet(population);
		count++;
		satisfied = satisfied1 && satisfied2 && satisfied3;
	}
	bool cool = true;
}

void KD_TesterClass::Tester::displayBestNeuralNet(KD_PopulationClass::Population &population) {	
	population.getBest().displayProcess(getBoardInfo(NAME_OF_BOARD));//show end result
	population.getBest().displayProcess(getBoardInfo(NAME_OF_BOARD2));
	population.getBest().displayProcess(getBoardInfo(NAME_OF_BOARD3));
}