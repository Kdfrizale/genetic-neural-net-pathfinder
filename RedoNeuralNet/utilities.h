#pragma once
#include <string>
#include <vector>
#include <fstream>
#include "Neuron.h"


enum boardObjects { enemy = -10, outOfBounds = -5, block = 0, ai = 1, openSpace = 5,  goal = 100 };//Change double value of these to increase nets performance differentiation between blocks
enum movementDirection { goUp, goDown, goLeft, goRight };

struct position {
	int x_cordinate;
	int y_cordinate;
};

const int UNINITIALZIED = -1;

const double FITNESS_CALIBRATOR_COL_REACHED = 10.0;//Value of reaching the right side
const double FITNESS_CALIBRATOR_MOVES_REMAINING = 10.0;//Value of reaching the goal quickly
const double FITNESS_CALIBRATOR_MOVES_TAKEN = 2.0;//Value of moving, and not standing still
const double FITNESS_CALIBRATOR_DISTANCE_FROM_START = 4.0;//Value of moving away from start
const double FITNESS_CALIBRATOR_DISTANCE_FROM_GOAL = 10.0;//Value of getting close to the Goal


const int NUMBER_OF_OUTPUTS = 4;
const int NUMBER_OF_INPUTS = 49;//how many pixels too look at, centered around ai
const int NUMBER_OF_HIDDEN_LAYERS = 1;
const int NUMBER_OF_NEURONS_IN_HIDDEN_LAYER = (int)((NUMBER_OF_INPUTS + NUMBER_OF_OUTPUTS) / 2); //Mean of input and output neurons
const int NUMBER_OF_NEURALNETS = 50;//15
const int NUMBER_OF_BREEDS_PER_TEST = 8;//2
const double MUTATE_FACTOR = 0.2;//.15
const double MUTATION_CHANCE = 50; //Percent chance a mutation will occur per neuron


const int SIZE_OF_BOARD = 10;
const int NUMBER_OF_BLOCKS_ABLE_TO_SEE = (sqrt(NUMBER_OF_INPUTS) - 1) / 2;
const int NUMBER_OF_ALLOWED_MOVES = 50; //Max number of moves the AI is allowed to get to the goal
const int SATISFIED_SCORE = 500;
const int NUMBER_OF_TRIALS_PER_NET = 50;

const std::string NAME_OF_BOARD = "Testdata.txt";
const std::string NAME_OF_BOARD2 = "Testdata2.txt";
const std::string NAME_OF_BOARD3 = "Testdata3.txt";
const std::string NAME_OF_BOARD4 = "Testdata4.txt";
const std::string NAME_OF_BOARD5 = "Testdata5.txt";
const std::string NAME_OF_BOARD6 = "Testdata6.txt";

const bool SAVE_POPULATION = true;
const bool LOAD_POPULATION = false;

std::vector<std::string> getBoardInfo(const std::string filename);