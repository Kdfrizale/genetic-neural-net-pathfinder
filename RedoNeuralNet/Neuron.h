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
		double updateOutput(std::vector<KD_NeuronClass::Neuron> &layerAbove);

		
	private:
		std::vector<Connection> m_inputWeights;
		bool isInputNeuron;
		double m_outputValue;
	};
}
