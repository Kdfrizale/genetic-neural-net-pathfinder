#include "Tester.h"
#include "utilities.h"
#include "Population.h"

using namespace std;
using namespace KD_TesterClass;

class Tester {
public:
	void testEachNeuralNet(KD_PopulationClass::Population &population);
	void displayBestNeuralNet(KD_PopulationClass::Population &population);
	boardObjects theGameBoard[SIZE_OF_BOARD][SIZE_OF_BOARD];

private:
	void initializeTheGameBoard();
};

//Create the board and what it contains
void KD_TesterClass::Tester::initializeTheGameBoard() {
	for (int i = 0; i < SIZE_OF_BOARD; i++) {
		for (int j = 0; j < SIZE_OF_BOARD; j++) {
			theGameBoard[i][j] = openSpace;
		}
	}
	theGameBoard[SIZE_OF_BOARD / 2][SIZE_OF_BOARD / 2] = ai;

}

void KD_TesterClass::Tester::testEachNeuralNet(KD_PopulationClass::Population &population) {
	bool satisfied = false;																						
	boardObjects aGameBoard[SIZE_OF_BOARD][SIZE_OF_BOARD];
	initializeTheGameBoard();
	memcpy(aGameBoard, theGameBoard, sizeof(theGameBoard));
	//loop till a Net completes  the challenge 
	while (!satisfied) {
		satisfied =population.testAll(aGameBoard);
	}
}

void KD_TesterClass::Tester::displayBestNeuralNet(KD_PopulationClass::Population &population) {																						   
	boardObjects aGameBoard[SIZE_OF_BOARD][SIZE_OF_BOARD];
	memcpy(aGameBoard, theGameBoard, sizeof(theGameBoard));
	population.getBest().displayProcess(aGameBoard);//show end result
}