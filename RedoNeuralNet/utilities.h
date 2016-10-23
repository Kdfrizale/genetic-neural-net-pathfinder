#pragma once
#include "Neuron.h"


enum boardObjects { enemy, openSpace, ai, block, goal };///////Change double value of these to increase nets performance differentiation
enum movmentDirection { up, down, left, right };


struct position {
	int x_cordinate;
	int y_cordinate;
};


const int UNINITIALZIED = -1;

const double FITNESS_CALIBRATOR_COL_REACHED = 5.0;//Value of reaching the right side
const double FITNESS_CALIBRATOR_MOVES_REMAINING = 10.0;//Value of reaching the goal quickly


const int NUMBER_OF_OUTPUTS = 4;
const int NUMBER_OF_INPUTS = 49;//how many pixels too look at, centered around ai
const int NUMBER_OF_HIDDEN_LAYERS = 1;
const int NUMBER_OF_NEURONS_IN_HIDDEN_LAYER = (int)((NUMBER_OF_INPUTS + NUMBER_OF_OUTPUTS) / 2); //Mean of input and output neurons
const int NUMBER_OF_NEURALNETS = 15;
const int NUMBER_OF_BREEDS_PER_TEST = 2;
const double MUTATE_FACTOR = 0.15;


const int SIZE_OF_BOARD = 10;
const int NUMBER_OF_BLOCKS_ABLE_TO_SEE = (sqrt(NUMBER_OF_INPUTS) - 1) / 2;
const int NUMBER_OF_ALLOWED_MOVES = 50; // amount of moves it should take + C or times K
const int SATISFIED_SCORE = 50;




//Fill in board




