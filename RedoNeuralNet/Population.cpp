#include <vector>
#include <algorithm>

#include "Population.h"
#include "NeuralNetwork.h"
#include "Tester.h"
#include "utilities.h"

using namespace std;
using namespace KD_PopulationClass;

class Population {
public:
	Population(void);
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

KD_NeuralNetworkClass::NeuralNetwork KD_PopulationClass::Population::getBest() {///////////////////////////////////////////GOOD
	KD_NeuralNetworkClass::NeuralNetwork result = KD_NeuralNetworkClass::NeuralNetwork::NeuralNetwork();
	return result;
}

bool KD_PopulationClass::Population::testAll(boardObjects aGameboard[SIZE_OF_BOARD][SIZE_OF_BOARD]) {////////////GOOD
	return true;

}

bool sortByFitnessHigh(KD_NeuralNetworkClass::NeuralNetwork &aNet, KD_NeuralNetworkClass::NeuralNetwork &bNet) {
	//return aNet.getFitness() < bNet.getFitness();
	return true;
}

bool sortByFitnessLow(KD_NeuralNetworkClass::NeuralNetwork &aNet, KD_NeuralNetworkClass::NeuralNetwork &bNet) {
	//return aNet.getFitness() > bNet.getFitness();
	return false;
}

void KD_PopulationClass::Population::sortPopulation(bool sortHighLast) {/////////////////////////These may be reversed
	
}

//get worst 2 Candidates from sorted population....NUMBER_OF_BREEDS_PER_TEST
void KD_PopulationClass::Population::getCandidatesToKill() {
	
}

//Get the top four networks from sorted population...NUMBER_OF_BREEDS_PER_TEST *2
void KD_PopulationClass::Population::getCandidatesToBreed() {
	
}

void KD_PopulationClass::Population::breedBestNeuralNet() {/////////////////////////////////////////////////////////////////////////GOOD
	
}

std::vector<KD_NeuronClass::Neuron> selectGenesFromLayer(int layerNum, KD_NeuralNetworkClass::NeuralNetwork &aParent, KD_NeuralNetworkClass::NeuralNetwork &bParent) {//////////////////////////GOOD
	std::vector<KD_NeuronClass::Neuron> result;
	//const std::vector<KD_NeuronClass::Neuron> aParentLayer = aParent.m_layers[layerNum];
	//const std::vector<KD_NeuronClass::Neuron> bParentLayer = bParent.m_layers[layerNum];

	//for (int n = 0; n < aParentLayer.size(); n++) {
	//	if ((rand() % 10) < 5) {//50 % chance
	//		result.push_back(aParentLayer[n]);
	//	}
	//	else {
	//		result.push_back(bParentLayer[n]);
	//	}
	//}
	return result;
}

void KD_PopulationClass::Population::breed(KD_NeuralNetworkClass::NeuralNetwork &aParent, KD_NeuralNetworkClass::NeuralNetwork &bParent, KD_NeuralNetworkClass::NeuralNetwork &child) {////////////////////////////GOOD
	
}

KD_NeuralNetworkClass::NeuralNetwork KD_PopulationClass::Population::takeOutRandomNetFromVector(std::vector< KD_NeuralNetworkClass::NeuralNetwork> &netToPullFrom) {////////////////////GOOD
	int place = rand() % netToPullFrom.size();
	KD_NeuralNetworkClass::NeuralNetwork result = netToPullFrom.at(place);
	//netToPullFrom.erase(netToPullFrom.begin + place - 1);//remove the element cop
	return result;
}


KD_PopulationClass::Population::Population(void) {///////////////////////////////////////////////////////////////GOOD
	vector< KD_NeuralNetworkClass::NeuralNetwork> testGroup;
	for (int i = 0; i < NUMBER_OF_NEURALNETS; i++) {
		KD_NeuralNetworkClass::NeuralNetwork temp = KD_NeuralNetworkClass::NeuralNetwork();
		testGroup.push_back(temp);
	}
}