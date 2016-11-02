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

//Test each neural net in the population, mutating/breeding after every test cycle
void KD_TesterClass::Tester::testEachNeuralNet(KD_PopulationClass::Population &population) {
	bool satisfied = false;
	int count = 0;
	while (!satisfied && count < NUMBER_OF_TRIALS_PER_NET) {
		satisfied = population.testAll();
		count++;
	}
	//save the population
	if (SAVE_POPULATION) {

	}
}

void KD_TesterClass::Tester::displayBestNeuralNet(KD_PopulationClass::Population &population) {	
	//population.getBest().test(getBoardInfo(NAME_OF_BOARD));//show end result
	//population.getBest().test(getBoardInfo(NAME_OF_BOARD2));
	//population.getBest().test(getBoardInfo(NAME_OF_BOARD3));
	//population.getBest().test(getBoardInfo(NAME_OF_BOARD4));
	//population.getBest().test(getBoardInfo(NAME_OF_BOARD5));
	population.getBest().test(getBoardInfo(NAME_OF_BOARD6));
}