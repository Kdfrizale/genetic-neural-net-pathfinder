#pragma once
#include <vector>

#include "NeuralNetwork.h"

namespace KD_PopulationClass {
	class Population {
	public:
		Population();
		KD_NeuralNetworkClass::NeuralNetwork getBest();
		void breedBestNeuralNet();
		bool testAll(boardObjects board[SIZE_OF_BOARD][SIZE_OF_BOARD]);

	private:
		std::vector< KD_NeuralNetworkClass::NeuralNetwork> population;
		std::vector< KD_NeuralNetworkClass::NeuralNetwork> candidatesToBreed;
		std::vector< KD_NeuralNetworkClass::NeuralNetwork> candidatesToKill;
		void getCandidatesToBreed();
		void getCandidatesToKill();
		void breed(KD_NeuralNetworkClass::NeuralNetwork &aParent, KD_NeuralNetworkClass::NeuralNetwork &bParent, KD_NeuralNetworkClass::NeuralNetwork &child);
		void sortPopulation(bool sortHighLast);
		KD_NeuralNetworkClass::NeuralNetwork takeOutRandomNetFromVector(std::vector< KD_NeuralNetworkClass::NeuralNetwork> &netToPullFrom);


	};
}
