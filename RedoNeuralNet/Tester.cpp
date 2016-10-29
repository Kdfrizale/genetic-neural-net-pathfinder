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

void KD_TesterClass::Tester::testEachNeuralNet(KD_PopulationClass::Population &population) {
	bool satisfied = false;
	int count = 0;
	while (!satisfied && count < NUMBER_OF_TRIALS_PER_NET) {////////////reduce this to one
		satisfied = population.testAll();

		//displayBestNeuralNet(population);
		count++;
	}
	bool cool = true;
	//save the population
	if (SAVE_POPULATION) {

	}
}

void KD_TesterClass::Tester::displayBestNeuralNet(KD_PopulationClass::Population &population) {	
	population.getBest().displayProcess(getBoardInfo(NAME_OF_BOARD));//show end result
	population.getBest().displayProcess(getBoardInfo(NAME_OF_BOARD2));
	population.getBest().displayProcess(getBoardInfo(NAME_OF_BOARD3));
	population.getBest().displayProcess(getBoardInfo(NAME_OF_BOARD4));
	population.getBest().displayProcess(getBoardInfo(NAME_OF_BOARD5));
}