#pragma once
#include <vector>

#include "Neuron.h"
#include "utilities.h"

//typedef std::vector<Neuron> Layer;
namespace KD_NeuralNetworkClass {
	class NeuralNetwork {
	public:
		NeuralNetwork();
		void setFitness(double newFitness);
		double getFitness();
		void mutateGenesOfNeurons();
		void test();
		std::vector<double> getOutputs();
		void giveInputs(std::vector<double> inputs);
		void displayProcess(boardObjects board[SIZE_OF_BOARD][SIZE_OF_BOARD]);
		std::vector<std::vector<KD_NeuronClass::Neuron>> m_layers;

		boardObjects theGameBoard[SIZE_OF_BOARD][SIZE_OF_BOARD];

	private:
		double fitness;
		void initializeTheGameBoard();
		movmentDirection getMove();


	};
}
