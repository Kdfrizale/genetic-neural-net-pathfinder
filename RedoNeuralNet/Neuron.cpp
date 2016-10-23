#pragma once
#include <vector>
#include "utilities.h"
#include "Neuron.h"

typedef double Connection;
using namespace std;
using namespace KD_NeuronClass;

class Neuron {
public:
	void mutateInputWeights();
	double getOutputValue();
	void setOutputValue(double valueToSet);
	void Neuron::setInputWeights(std::vector<Connection> inputWeights);
	std::vector<Connection> Neuron::getInputWeights();
	Neuron::Neuron(std::vector<KD_NeuronClass::Neuron> &aLayerAbove);
	Neuron::Neuron();
	std::vector<KD_NeuronClass::Neuron> *m_layerAbove;
	
private:
	std::vector<Connection> m_inputWeights;
	int m_myIndex;
	double updateOutput();
	double m_outputValue;
	
};

double KD_NeuronClass::Neuron::getOutputValue() {
	updateOutput();
	return m_outputValue;
}
void KD_NeuronClass::Neuron::setOutputValue(double valueToSet) {
	m_outputValue = valueToSet;
}

void KD_NeuronClass::Neuron::setInputWeights(std::vector<Connection> inputWeights) {
	m_inputWeights.clear();
	m_inputWeights = inputWeights;
	updateOutput();
}

std::vector<Connection> KD_NeuronClass::Neuron::getInputWeights() {
	return m_inputWeights;
}



KD_NeuronClass::Neuron::Neuron(std::vector<KD_NeuronClass::Neuron> &aLayerAbove) {//////////////////////////////////GOOD
	m_layerAbove = &aLayerAbove;
	for (int i = 0; i < aLayerAbove.size(); i++) {
		Connection temp = (double)rand() / RAND_MAX;//0...1
		m_inputWeights.push_back(temp);
	}
}

KD_NeuronClass::Neuron::Neuron() {//////////////////////////////////GOOD
	m_layerAbove = NULL;
}



////////////////////////////////ONLY THIS LEFT//////////////////////////////////////////////////

void KD_NeuronClass::Neuron::mutateInputWeights() {

}

//get the output of each neuron in the layer above it
//times each one by its weight in m_inputWeights
//then sum them up
double KD_NeuronClass::Neuron::updateOutput() {/////////////////m_layer not right
	if (m_layerAbove == NULL) {
		return m_outputValue;
	}
	else {
		double result = 0;
		for (Neuron neuronAbove : *m_layerAbove) {
			result += neuronAbove.updateOutput();
		}
		m_outputValue = result;
		return result;
	}
	return 0.0;
}

