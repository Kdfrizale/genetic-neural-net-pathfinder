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

	double m_outputValue;
	double updateOutput();
};

double KD_NeuronClass::Neuron::getOutputValue() {
	return m_outputValue;
}
void KD_NeuronClass::Neuron::setOutputValue(double valueToSet) {
	m_outputValue = valueToSet;
}

void KD_NeuronClass::Neuron::setInputWeights(std::vector<Connection> inputWeights) {
	m_inputWeights.clear();
	m_inputWeights = inputWeights;
}

std::vector<Connection> KD_NeuronClass::Neuron::getInputWeights() {
	return m_inputWeights;
}

void KD_NeuronClass::Neuron::mutateInputWeights() {
	
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

//get the output of each neuron in the layer above it
//times each one by its weight in m_inputWeights
//then sum them up
double KD_NeuronClass::Neuron::updateOutput() {////////////////////////////////////////////////////GOOD
	/*if (m_layerAbove == NULL) {
		return m_outputValue;
	}
	else {
		double result = 0;
		for (Neuron neuronAbove : *m_layerAbove) {
			result += neuronAbove.updateOutput();
		}
		m_outputValue = result;
		return result;
	}*/
	return 0.0;
}



////////////////////////////////ONLY THIS LEFT//////////////////////////////////////////////////



