#pragma once
#include <vector>
#include "utilities.h"

typedef double Connection;

namespace KD_NeuronClass {
	class Neuron {
	public:
		void mutateInputWeights();
		double getOutputValue();
		void setOutputValue(double valueToSet);
		void Neuron::setInputWeights(std::vector<Connection> inputWeights);
		std::vector<Connection> Neuron::getInputWeights();
		Neuron::Neuron(std::vector<Neuron> &aLayerAbove);
		Neuron::Neuron();
		std::vector<Neuron> *m_layerAbove;

		
	private:
		std::vector<Connection> m_inputWeights;
		int m_myIndex;
		double m_outputValue;
		double updateOutput();
	};
}
