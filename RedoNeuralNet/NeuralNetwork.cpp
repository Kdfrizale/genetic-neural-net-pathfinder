#pragma once
#include <vector>
#include <algorithm>

#include "NeuralNetwork.h"
#include "Neuron.h"
#include "utilities.h"

using namespace std;
using namespace KD_NeuralNetworkClass;

class NeuralNetwork {
public:
	void setFitness(double newFitness);
	double getFitness();
	void mutateGenesOfNeurons();
	void test(boardObjects board[SIZE_OF_BOARD][SIZE_OF_BOARD]);
	std::vector<double> getOutputs();
	void giveInputs(std::vector<double> inputs);
	void displayProcess(boardObjects board[SIZE_OF_BOARD][SIZE_OF_BOARD]);
	std::vector<std::vector<KD_NeuronClass::Neuron>> m_layers;

private:
	double fitness;

	movmentDirection getMove();


};
void KD_NeuralNetworkClass::NeuralNetwork::setFitness(double newFitness) {
	NeuralNetwork::fitness = newFitness;
}
double KD_NeuralNetworkClass::NeuralNetwork::getFitness() {
	return NeuralNetwork::fitness;

}

//go through each layer, each neuron, using the mutate genes function in Neuron
void KD_NeuralNetworkClass::NeuralNetwork::mutateGenesOfNeurons() {//////////////////////////////////////////GOOD
	
}


//get last layer of neurons outputs
std::vector<double> KD_NeuralNetworkClass::NeuralNetwork::getOutputs() {////////////////////////////////////////GOOD
	std::vector<double> outputs;
	
	return outputs;
}


//set the first layer neurons outout to equal inputs
void KD_NeuralNetworkClass::NeuralNetwork::giveInputs(std::vector<double> inputs) {///////////////////////////////////GOOD---Is this reversed? shouldnt matter though

}


bool compareDoubles(double a, double b) {
	return a < b;
}
movmentDirection KD_NeuralNetworkClass::NeuralNetwork::getMove() {/////////////////////////////////////////////////GOOD
	movmentDirection move;
	/*int placeOfHighest = 0;
	std::vector<double> outputs = getOutputs();
	//get largest output
	double highestValue = std::max_element(outputs.begin, outputs.end, compareDoubles);
	for (int i = 0; i < outputs.size(); i++) {
		if (outputs.at(i) == highestValue) {
			placeOfHighest = i;
		}
	}
	switch (placeOfHighest) {
	case 0: move = up;
	case 1: move = down;
	case 2: move = left;
	case 3: move = right;
	}*/
	move = up;
	return move;
}

//Calculate fitness with Weighted preferences
double calculateFitness(int furthestColReached, int distanceFromGoal, int movesRemaining) {///////GOOD
	double result = (furthestColReached*FITNESS_CALIBRATOR_COL_REACHED - distanceFromGoal
		+ FITNESS_CALIBRATOR_MOVES_REMAINING*movesRemaining);
	return result;
}

void KD_NeuralNetworkClass::NeuralNetwork::test(boardObjects board[SIZE_OF_BOARD][SIZE_OF_BOARD]) {/////////////////////////GOOD/////Board must be a copy
	/*int movesLeft = NUMBER_OF_ALLOWED_MOVES;
	bool ableToContinue = true;
	position goalPos;
	position aiPos;
	position oldAiPos = aiPos;
	std::vector<double> boardInfoAvailableToAI;
	//find ai position in board
	for (int x = 0; x < SIZE_OF_BOARD; x++) {
		for (int y = 0; y < SIZE_OF_BOARD; y++) {
			if (board[x][y] == ai) {
				aiPos.x_cordinate = x;
				aiPos.y_cordinate = y;
				break;
			}
			if (board[x][y] == goal) {
				goalPos.x_cordinate = x;
				goalPos.y_cordinate = y;
			}
		}
	}
	while (ableToContinue) {//Start Test
		int xLowerRange = aiPos.x_cordinate - NUMBER_OF_BLOCKS_ABLE_TO_SEE;
		int xUpperRange = aiPos.x_cordinate + NUMBER_OF_BLOCKS_ABLE_TO_SEE;
		int yLowerRange = aiPos.y_cordinate - NUMBER_OF_BLOCKS_ABLE_TO_SEE;
		int yUpperRange = aiPos.y_cordinate + NUMBER_OF_BLOCKS_ABLE_TO_SEE;

		//get area aroud ai pos in every direction
		for (int x = xLowerRange; x <= xUpperRange; x++) {
			for (int y = yLowerRange; y <= yUpperRange; y++) {
				boardInfoAvailableToAI.push_back(board[x][y]);
			}
		}
		//feed info to input neurons
		giveInputs(boardInfoAvailableToAI);

		//get output of net;; and decide on direction to move
		movmentDirection aiMove = getMove();

		//update ai pos
		//////////////////////////////////////////////////////////////////////////////////////Check for out of bounds exception
		switch (aiMove) {
		case up:
			if (board[aiPos.x_cordinate][aiPos.y_cordinate + 1] == openSpace)
				aiPos.y_cordinate++;
			else if (board[aiPos.x_cordinate][aiPos.y_cordinate + 1] == enemy)
				ableToContinue = false;//Dead
		case down:
			if (board[aiPos.x_cordinate][aiPos.y_cordinate - 1] == openSpace)
				aiPos.y_cordinate--;
			else if (board[aiPos.x_cordinate][aiPos.y_cordinate - 1] == enemy)
				ableToContinue = false;//Dead
		case left:
			if (board[aiPos.x_cordinate - 1][aiPos.y_cordinate] == openSpace)
				aiPos.x_cordinate--;
			else if (board[aiPos.x_cordinate - 1][aiPos.y_cordinate] == enemy)
				ableToContinue = false;//Dead
		case right:
			if (board[aiPos.x_cordinate + 1][aiPos.y_cordinate] == openSpace)
				aiPos.x_cordinate++;
			else if (board[aiPos.x_cordinate + 1][aiPos.y_cordinate] == enemy)
				ableToContinue = false;//Dead
		}
		movesLeft--;
		//update ableCondition
		//false if newpos = oldpos (it's stuck) or if movesLeft == 0; if ai touches enemy
		if (ableToContinue) {
			ableToContinue = aiPos.x_cordinate == (movesLeft <= 0) ||
				(oldAiPos.x_cordinate && aiPos.y_cordinate == oldAiPos.y_cordinate);
		}
	}//End of Test

	int furthestColReached = SIZE_OF_BOARD - aiPos.x_cordinate;
	int distanceFromGoal = abs(aiPos.x_cordinate - goalPos.x_cordinate) + abs(aiPos.y_cordinate - goalPos.y_cordinate);
	//calculate fitness
	NeuralNetwork::fitness = calculateFitness(furthestColReached, distanceFromGoal, movesLeft);
	*/
}

std::vector<KD_NeuronClass::Neuron> createInputLayer(int numberOfNeurons) {////////////////////////////////////////////GOOD
	std::vector<KD_NeuronClass::Neuron> result;
	for (int i = 0; i < numberOfNeurons; i++) {
		KD_NeuronClass::Neuron temp = KD_NeuronClass::Neuron();//set Neurons above layer to null
		result.push_back(temp);
	}
	return result;
}

std::vector<KD_NeuronClass::Neuron> createRandomLayer(int numberOfNeurons, std::vector<KD_NeuronClass::Neuron> aLayerAbove) {////////////////////////////GOOD
	std::vector<KD_NeuronClass::Neuron> result;
	for (int i = 0; i < numberOfNeurons; i++) {
		KD_NeuronClass::Neuron temp = KD_NeuronClass::Neuron(aLayerAbove);
		result.push_back(temp);
	}
	return result;
}

KD_NeuralNetworkClass::NeuralNetwork::NeuralNetwork(void) {/////////////////////////////////////////////////////////GOOD
														   //add the input layer
	m_layers.push_back(createInputLayer(NUMBER_OF_INPUTS));

	//add all the hidden layers
	m_layers.push_back(createRandomLayer(NUMBER_OF_NEURONS_IN_HIDDEN_LAYER, m_layers.back()));

	//add the output layer
	m_layers.push_back(createRandomLayer(NUMBER_OF_OUTPUTS, m_layers.back()));

	//set Fitness to UNINITIALIZED
	fitness = UNINITIALZIED;
}












////////////////////////////////ONLY THIS LEFT//////////////////////////////////////////////////





void KD_NeuralNetworkClass::NeuralNetwork::displayProcess(boardObjects board[SIZE_OF_BOARD][SIZE_OF_BOARD]) {
	//just like test, but record each movement, and possible add to GUI
}