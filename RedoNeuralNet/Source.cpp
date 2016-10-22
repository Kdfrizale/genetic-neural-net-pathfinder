#include <iostream>

#include "Population.h"
#include "utilities.h"
#include "Tester.h"

using namespace std;


int main() {
	KD_PopulationClass::Population testGroup = KD_PopulationClass::Population::Population();
	KD_TesterClass::Tester myTester;
	myTester.testEachNeuralNet(testGroup);


	cout << "Completed" << endl;
}
