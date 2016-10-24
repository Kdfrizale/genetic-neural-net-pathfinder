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
	Population();
	KD_NeuralNetworkClass::NeuralNetwork& getBest();
	void breedBestNeuralNet();
	bool testAll(std::vector<std::string> boardInfo);

private:
	std::vector< KD_NeuralNetworkClass::NeuralNetwork> population;
	std::vector< KD_NeuralNetworkClass::NeuralNetwork> candidatesToBreed;
	std::vector< KD_NeuralNetworkClass::NeuralNetwork> candidatesToKill;
	void getCandidatesToBreed();
	void getCandidatesToKill();
	void breed(KD_NeuralNetworkClass::NeuralNetwork &aParent, KD_NeuralNetworkClass::NeuralNetwork &bParent, KD_NeuralNetworkClass::NeuralNetwork &child);
	void sortPopulation(bool sortHighLast);
	KD_NeuralNetworkClass::NeuralNetwork takeOutRandomNetFromVector(std::vector< KD_NeuralNetworkClass::NeuralNetwork> &netToPullFrom);
	KD_NeuralNetworkClass::NeuralNetwork pickRandomNetFromVector(std::vector< KD_NeuralNetworkClass::NeuralNetwork> &netToPullFrom);


};

KD_PopulationClass::Population::Population() {///////////////////////////////////////////////////////////////GOOD
	for (int i = 0; i < NUMBER_OF_NEURALNETS; i++) {
		KD_NeuralNetworkClass::NeuralNetwork temp = KD_NeuralNetworkClass::NeuralNetwork();
		population.push_back(temp);
	}
}

KD_NeuralNetworkClass::NeuralNetwork& KD_PopulationClass::Population::getBest() {///////////////////////////////////////////GOOD
	sortPopulation(false);
	return population.front();
}

bool sortByFitnessHigh(KD_NeuralNetworkClass::NeuralNetwork &aNet, KD_NeuralNetworkClass::NeuralNetwork &bNet) {
	return aNet.getFitness() < bNet.getFitness();
	return true;
}

bool sortByFitnessLow(KD_NeuralNetworkClass::NeuralNetwork &aNet, KD_NeuralNetworkClass::NeuralNetwork &bNet) {
	return aNet.getFitness() > bNet.getFitness();
	return false;
}

void KD_PopulationClass::Population::sortPopulation(bool sortHighLast) {/////////////////////////These may be reversed
	if (sortHighLast) {
		std::sort(population.begin(), population.end(), sortByFitnessHigh);
		return;
	}
	std::sort(population.begin(), population.end(), sortByFitnessLow);
}

bool KD_PopulationClass::Population::testAll(std::vector<std::string> boardInfo) {

	//test each neural net if it has an unititialized fitness AKA was never tested
	for (int i = 0; i < Population::population.size(); i++) {
		if (population[i].getFitness() >= SATISFIED_SCORE) {
			return true;//return true
		}
		if (population[i].getFitness() == -1) {
			population[i].test(boardInfo);
		}
	}
	breedBestNeuralNet();
	sortPopulation(false);
	sortPopulation(true);
	return false;
}


//Selects one at random, Does not remove from list
KD_NeuralNetworkClass::NeuralNetwork KD_PopulationClass::Population::pickRandomNetFromVector(std::vector< KD_NeuralNetworkClass::NeuralNetwork> &netToPullFrom) {
	int place = rand() % netToPullFrom.size();
	KD_NeuralNetworkClass::NeuralNetwork result = netToPullFrom.at(place);
	return result;
}

//get worst 2 Candidates from sorted population....NUMBER_OF_BREEDS_PER_TEST
void KD_PopulationClass::Population::getCandidatesToKill() {
	sortPopulation(false);//sort Low last
	for (int i = 0; i < NUMBER_OF_BREEDS_PER_TEST; i++) {
		candidatesToKill.push_back(population.back());
		population.pop_back();
	}
}

//Get the top four networks from sorted population...NUMBER_OF_BREEDS_PER_TEST *2
void KD_PopulationClass::Population::getCandidatesToBreed() {
	sortPopulation(true); // sort High last
	for (int i = 0; i < NUMBER_OF_BREEDS_PER_TEST * 2; i++) {
		candidatesToBreed.push_back(population.back());
		population.pop_back();
	}
}

void KD_PopulationClass::Population::breedBestNeuralNet() {/////////////////////////////////////////////////////////////////////////GOOD
	getCandidatesToBreed();
	getCandidatesToKill();
	for (int i = 0; i < NUMBER_OF_BREEDS_PER_TEST; i++) {
		KD_NeuralNetworkClass::NeuralNetwork aParent = pickRandomNetFromVector(candidatesToBreed);//randomly pick from(and remove from) candidatesToBreed
		KD_NeuralNetworkClass::NeuralNetwork bParent = pickRandomNetFromVector(candidatesToBreed);
		KD_NeuralNetworkClass::NeuralNetwork child = takeOutRandomNetFromVector(candidatesToKill);//randomly pick from (and remove from) candidatesToKill
		breed(aParent, bParent, child);
	}
	for (KD_NeuralNetworkClass::NeuralNetwork net : candidatesToBreed) {
		population.push_back(net);
	}
	candidatesToBreed.clear();//Reset
	candidatesToKill.clear();
}



std::vector<KD_NeuronClass::Neuron> selectGenesFromLayer(int layerNum, KD_NeuralNetworkClass::NeuralNetwork &aParent, KD_NeuralNetworkClass::NeuralNetwork &bParent) {//////////////////////////Confirm its 50%
	std::vector<KD_NeuronClass::Neuron> result;
	const std::vector<KD_NeuronClass::Neuron> aParentLayer = aParent.m_layers[layerNum];
	const std::vector<KD_NeuronClass::Neuron> bParentLayer = bParent.m_layers[layerNum];

	for (int n = 0; n < aParentLayer.size(); n++) {
		if ((rand() % 10) < 5) {//50 % chance
			result.push_back(aParentLayer[n]);
		}
		else {
			result.push_back(bParentLayer[n]);
		}
	}
	return result;
}


void KD_PopulationClass::Population::breed(KD_NeuralNetworkClass::NeuralNetwork &aParent, KD_NeuralNetworkClass::NeuralNetwork &bParent, KD_NeuralNetworkClass::NeuralNetwork &child) {////////////////////////////GOOD
																																													   //add newly created child to populaltion
	child.m_layers.clear();
	for (int i = 0; i < aParent.m_layers.size(); i++) {
		child.m_layers.push_back(selectGenesFromLayer(i, aParent, bParent));//Copy the layers of both parents
	}
	child.setFitness(-1);//Indicate it's new and needs testing
	child.mutateGenesOfNeurons();
	population.push_back(child);
}
///////////////////////////Whats left/////////////////////////////////////////////











//Selects one at ranom, Does remove from list
KD_NeuralNetworkClass::NeuralNetwork KD_PopulationClass::Population::takeOutRandomNetFromVector(std::vector< KD_NeuralNetworkClass::NeuralNetwork> &netToPullFrom) {////////////////////Does not remove from list
	int place = rand() % netToPullFrom.size();
	KD_NeuralNetworkClass::NeuralNetwork result = netToPullFrom.at(place);
	//netToPullFrom.erase(netToPullFrom.begin + place - 1);//remove the element cop
	return result;
}









