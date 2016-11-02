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
	double updateOutput(std::vector<KD_NeuronClass::Neuron> &layerAbove);
	
private:
	std::vector<Connection> m_inputWeights;
	bool isInputNeuron;
	double m_outputValue;
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

KD_NeuronClass::Neuron::Neuron(std::vector<KD_NeuronClass::Neuron> &aLayerAbove) {
	m_layerAbove = &aLayerAbove;
	for (int i = 0; i < aLayerAbove.size(); i++) {
		Connection temp = (double)rand() / RAND_MAX;//0...1
		m_inputWeights.push_back(temp);
	}
	m_outputValue = 0;
}

KD_NeuronClass::Neuron::Neuron() {
	m_layerAbove = NULL;
	isInputNeuron = true;
	m_outputValue = 0;
}

//get the output of each neuron in the layer above it
//times each one by its weight in m_inputWeights
//then sum them up
double KD_NeuronClass::Neuron::updateOutput(std::vector<KD_NeuronClass::Neuron> &layerAbove) {
	if (isInputNeuron) {
		return m_outputValue;
	}
	else {
		double result = 0;
		int n = 0;
		for (Neuron neuronAbove : layerAbove) {
			result += neuronAbove.getOutputValue() * m_inputWeights[n];
			n++;
		}
		m_outputValue = result;
		return result;
	}
	return 0.0;
}

void KD_NeuronClass::Neuron::mutateInputWeights() {
	//for each connection modify it by a random value
	for (Connection &c : m_inputWeights) {
		double mutationEffect = (((double)rand() / RAND_MAX) * MUTATE_FACTOR); //How much the neurons input should change
		if ((rand() % 10) < 5) {//50 % chance
			c = c + mutationEffect;
		}
		else {
			c = c - mutationEffect;
		}
	}
}


