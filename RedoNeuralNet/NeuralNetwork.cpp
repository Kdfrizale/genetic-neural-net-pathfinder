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
	std::vector<movementDirection> test(std::vector<std::string> boardInfo);
	std::vector<double> getOutputs();
	void giveInputs(std::vector<double> inputs);
	std::vector<std::vector<KD_NeuronClass::Neuron>> m_layers;

	boardObjects theGameBoard[SIZE_OF_BOARD][SIZE_OF_BOARD];

private:
	double fitness;
	void initializeTheGameBoard(std::vector<std::string> boardInfo);
	bool moveAi(movementDirection move, position &aiPos);

	movementDirection getMove();


};
void KD_NeuralNetworkClass::NeuralNetwork::setFitness(double newFitness) {
	NeuralNetwork::fitness = newFitness;
}
double KD_NeuralNetworkClass::NeuralNetwork::getFitness() {
	return NeuralNetwork::fitness;

}
boardObjects getBoardObjectFromStringVector(std::vector<std::string> &boardInfo) {//could use hash table
	std::string temp;
	boardObjects result;
	while (true) {
		temp = boardInfo.front();
		if (temp == "emeny") {
			result = enemy;
			break;
		}
		else if (temp == "outOfBounds") {
			result = outOfBounds;
			break;
		}
		else if (temp == "block") {
			result = block;
			break;
		}
		else if (temp == "ai") {
			result = ai;
			break;
		}
		else if (temp == "openSpace") {
			result = openSpace;
			break;
		}
		else if (temp == "goal") {
			result = goal;
			break;
		}
		else {
			//Invalid data entered
			boardInfo.erase(boardInfo.begin());
		}

	}
	
	boardInfo.erase(boardInfo.begin());
	return result;
}
//Create the board and what it contains
void KD_NeuralNetworkClass::NeuralNetwork::initializeTheGameBoard(std::vector<std::string> boardInfo) {
	for (int i = 0; i < SIZE_OF_BOARD; i++) {
		for (int j = 0; j < SIZE_OF_BOARD; j++) {
			boardObjects temp = getBoardObjectFromStringVector(boardInfo);
			KD_NeuralNetworkClass::NeuralNetwork::theGameBoard[i][j] = temp;
		}
	}
}

//Calculate fitness with Weighted preferences
double calculateFitness(int distanceFromGoal, int movesRemaining, int movesTaken, int distanceFromStart, int furthestColReached) {
	double result = (FITNESS_CALIBRATOR_MOVES_REMAINING*movesRemaining + FITNESS_CALIBRATOR_COL_REACHED*furthestColReached
		+ FITNESS_CALIBRATOR_MOVES_TAKEN*movesTaken + FITNESS_CALIBRATOR_DISTANCE_FROM_START*distanceFromStart
		- FITNESS_CALIBRATOR_DISTANCE_FROM_GOAL*distanceFromGoal);
	return result;
}



//get last layer of neurons outputs
std::vector<double> KD_NeuralNetworkClass::NeuralNetwork::getOutputs() {
	int l = -1;//layer above number
	for (std::vector<KD_NeuronClass::Neuron> &layer : m_layers) {
		for (KD_NeuronClass::Neuron &neuron : layer) {
			if (l != -1) {
				neuron.updateOutput(m_layers[l]);
			}
			else {
				neuron.updateOutput(m_layers[0]);//This is to accomadate input layer not having a layer above, m_layers[0] is not used
			}
		}
		l++;
	}

	std::vector<double> outputs;
	std::vector<KD_NeuronClass::Neuron> &lastLayer = m_layers.back();
	for (KD_NeuronClass::Neuron &neuron : lastLayer) {
		outputs.push_back(neuron.getOutputValue());
	}
	return outputs;
}


//set the first layer neurons outout to equal inputs
void KD_NeuralNetworkClass::NeuralNetwork::giveInputs(std::vector<double> inputs) {
	for (KD_NeuronClass::Neuron &neuron : m_layers.front()) {
		neuron.setOutputValue(inputs.back());//set the value
		inputs.pop_back();//remove the value
	}
}

movementDirection KD_NeuralNetworkClass::NeuralNetwork::getMove() {
	movementDirection move;
	int placeOfHighest = 0;
	std::vector<double> outputs = getOutputs();

	//get largest output
	double highestValue = *std::max_element(outputs.begin(), outputs.end());
	for (int i = 0; i < outputs.size(); i++) {
		if (outputs.at(i) == highestValue) {
			placeOfHighest = i;
		}
	}

	switch (placeOfHighest) {
	case 0: move = goUp; break;
	case 1: move = goDown; break;
	case 2: move = goLeft; break;
	case 3: move = goRight; break;
	}
	return move;
}

std::vector<KD_NeuronClass::Neuron> createInputLayer(int numberOfNeurons) {
	std::vector<KD_NeuronClass::Neuron> result;
	for (int i = 0; i < numberOfNeurons; i++) {
		KD_NeuronClass::Neuron temp = KD_NeuronClass::Neuron();//set Neurons above layer to null
		result.push_back(temp);
	}
	return result;
}

std::vector<KD_NeuronClass::Neuron> createRandomLayer(int numberOfNeurons, std::vector<KD_NeuronClass::Neuron> aLayerAbove) {
	std::vector<KD_NeuronClass::Neuron> result;
	for (int i = 0; i < numberOfNeurons; i++) {
		KD_NeuronClass::Neuron temp = KD_NeuronClass::Neuron(aLayerAbove);
		result.push_back(temp);
	}
	return result;
}

KD_NeuralNetworkClass::NeuralNetwork::NeuralNetwork(void) {
	//add the input layer
	m_layers.push_back(createInputLayer(NUMBER_OF_INPUTS));

	//add all the hidden layers
	m_layers.push_back(createRandomLayer(NUMBER_OF_NEURONS_IN_HIDDEN_LAYER, m_layers.back()));

	//add the output layer
	m_layers.push_back(createRandomLayer(NUMBER_OF_OUTPUTS, m_layers.back()));

	//set Fitness to UNINITIALIZED
	fitness = UNINITIALZIED;
}


//go through each layer, each neuron, using the mutate genes function in Neuron
void KD_NeuralNetworkClass::NeuralNetwork::mutateGenesOfNeurons() {
	for (std::vector<KD_NeuronClass::Neuron> &layer : m_layers) {
		for (KD_NeuronClass::Neuron &neuron : layer) {
			if ((rand() % 100) < MUTATION_CHANCE) {//Only mutate some of the neurons 
				neuron.mutateInputWeights();
			}
		}
	}
}


std::vector<movementDirection> KD_NeuralNetworkClass::NeuralNetwork::test(std::vector<std::string> boardInfo) {
	initializeTheGameBoard(boardInfo);

	int movesLeft = NUMBER_OF_ALLOWED_MOVES;
	bool ableToContinue = true;
	position goalPos;
	position currentAiPos;
	position startOfRunAiPos;
	position beginningOfTestAiPos;
	std::vector<double> boardInfoAvailableToAI;
	std::vector<movementDirection> allMovesTaken;

	//find ai and goal position in board
	for (int x = 0; x < SIZE_OF_BOARD; x++) {
		for (int y = 0; y < SIZE_OF_BOARD; y++) {
			if (KD_NeuralNetworkClass::NeuralNetwork::theGameBoard[x][y] == ai) {
				currentAiPos.x_cordinate = x;
				currentAiPos.y_cordinate = y;
			}
			if (KD_NeuralNetworkClass::NeuralNetwork::theGameBoard[x][y] == goal) {
				goalPos.x_cordinate = x;
				goalPos.y_cordinate = y;
			}
		}
	}
	beginningOfTestAiPos = currentAiPos;

	while (ableToContinue) {//Start Test
		boardInfoAvailableToAI.clear();
		startOfRunAiPos = currentAiPos;
		int xLowerRange = currentAiPos.x_cordinate - NUMBER_OF_BLOCKS_ABLE_TO_SEE;
		int xUpperRange = currentAiPos.x_cordinate + NUMBER_OF_BLOCKS_ABLE_TO_SEE;
		int yLowerRange = currentAiPos.y_cordinate - NUMBER_OF_BLOCKS_ABLE_TO_SEE;
		int yUpperRange = currentAiPos.y_cordinate + NUMBER_OF_BLOCKS_ABLE_TO_SEE;

		//get area aroud ai pos in every direction
		for (int x = xLowerRange; x <= xUpperRange; x++) {
			for (int y = yLowerRange; y <= yUpperRange; y++) {
				boardInfoAvailableToAI.push_back(KD_NeuralNetworkClass::NeuralNetwork::theGameBoard[x][y]);
			}
		}
		//feed info to input neurons
		giveInputs(boardInfoAvailableToAI);

		//get output of net;; and decide on direction to move
		movementDirection aiMove = getMove();
		allMovesTaken.push_back(aiMove);

		//update ai pos
		ableToContinue = moveAi(aiMove, currentAiPos);

		movesLeft--;
		//update ableCondition
		//false if newpos = oldpos (it's stuck) or if movesLeft == 0; if ai touches enemy
		if (ableToContinue) {
			ableToContinue = (movesLeft > 0) &&
				!(currentAiPos.x_cordinate == startOfRunAiPos.x_cordinate && currentAiPos.y_cordinate == startOfRunAiPos.y_cordinate) &&
				!(currentAiPos.x_cordinate == goalPos.x_cordinate && currentAiPos.y_cordinate == goalPos.y_cordinate);
		}
	}//End of Test

	int distanceFromGoal = abs(currentAiPos.x_cordinate - goalPos.x_cordinate) + abs(currentAiPos.y_cordinate - goalPos.y_cordinate);
	int distanceFromStart = abs(currentAiPos.x_cordinate - beginningOfTestAiPos.x_cordinate) + abs(currentAiPos.y_cordinate - beginningOfTestAiPos.y_cordinate);;
	int movesTaken = NUMBER_OF_ALLOWED_MOVES - movesLeft;
	int furthestColReached = abs(currentAiPos.x_cordinate - goalPos.x_cordinate);//////////////////////////////////////////////////////////////////////////////////////////////////////////Should I also add row?

	//calculate fitness
	bool atGoal = (currentAiPos.x_cordinate == goalPos.x_cordinate) && (currentAiPos.y_cordinate == goalPos.y_cordinate);

	NeuralNetwork::fitness += (atGoal) ? calculateFitness(distanceFromGoal, movesLeft, movesTaken, distanceFromStart, furthestColReached)
		: calculateFitness(distanceFromGoal, 0, movesTaken, distanceFromStart, furthestColReached);

	return allMovesTaken;
}

bool KD_NeuralNetworkClass::NeuralNetwork::moveAi(movementDirection move, position &aiPos) {
	boardObjects spaceToTheRight = KD_NeuralNetworkClass::NeuralNetwork::theGameBoard[aiPos.x_cordinate][aiPos.y_cordinate + 1];
	boardObjects spaceToTheLeft = KD_NeuralNetworkClass::NeuralNetwork::theGameBoard[aiPos.x_cordinate][aiPos.y_cordinate - 1];
	boardObjects spaceAbove = KD_NeuralNetworkClass::NeuralNetwork::theGameBoard[aiPos.x_cordinate - 1][aiPos.y_cordinate];
	boardObjects spaceBelow = KD_NeuralNetworkClass::NeuralNetwork::theGameBoard[aiPos.x_cordinate + 1][aiPos.y_cordinate];
	KD_NeuralNetworkClass::NeuralNetwork::theGameBoard[aiPos.x_cordinate][aiPos.y_cordinate] = openSpace;//Ai leaves the space it was in

	switch (move) {
	case goRight:
		if (spaceToTheRight == openSpace || spaceToTheRight == goal) {
			aiPos.y_cordinate++;
			break;
		}	
		else if (spaceToTheRight == enemy)
			return false;//Dead
		break;
	case goLeft:
		if (spaceToTheLeft == openSpace || spaceToTheLeft == goal) {
			aiPos.y_cordinate--;
			break;
		}
		else if (spaceToTheLeft == enemy)
			return false;//Dead
		break;
	case goUp:
		if (spaceAbove == openSpace || spaceAbove == goal) {
			aiPos.x_cordinate--;
			break;
		}
		else if (spaceAbove == enemy)
			return false;//Dead
		break;
	case goDown:
		if (spaceBelow == openSpace || spaceBelow == goal) {
			aiPos.x_cordinate++;
			break;
		}
		else if (spaceBelow == enemy)
			return false;//Dead
		break;
	}

	KD_NeuralNetworkClass::NeuralNetwork::theGameBoard[aiPos.x_cordinate][aiPos.y_cordinate] = ai;//update postion of ai
	return true;
}


///////////////////////////////////////WHats left///////////////////////////////////////////////////////////



