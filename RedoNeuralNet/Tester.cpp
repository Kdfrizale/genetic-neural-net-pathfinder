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

vector<string> getBoardInfo() {
	ifstream  file (NAME_OF_BOARD);
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
	bool satisfied = false;																						
	int count = 0;
	while (!satisfied && count < 40) {
		satisfied =population.testAll(getBoardInfo());
		//displayBestNeuralNet(population);
		count++;
	}
	bool cool = true;
}

void KD_TesterClass::Tester::displayBestNeuralNet(KD_PopulationClass::Population &population) {	
	population.getBest().displayProcess(getBoardInfo());//show end result
}