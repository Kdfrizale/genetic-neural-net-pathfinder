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
	
	while (!satisfied) {
		satisfied =population.testAll();
	}
}

void KD_TesterClass::Tester::displayBestNeuralNet(KD_PopulationClass::Population &population) {																						   
	boardObjects aGameBoard[SIZE_OF_BOARD][SIZE_OF_BOARD];
	memcpy(aGameBoard, theGameBoard, sizeof(theGameBoard));
	population.getBest().displayProcess(aGameBoard);//show end result
}