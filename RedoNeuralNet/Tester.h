#pragma once

#include "Population.h"

namespace KD_TesterClass {
	class Tester {
	public:
		void testEachNeuralNet(KD_PopulationClass::Population &population);
		void displayBestNeuralNet(KD_PopulationClass::Population &population);
		boardObjects theGameBoard[SIZE_OF_BOARD][SIZE_OF_BOARD];

	private:
		void initializeTheGameBoard();
	};
}


