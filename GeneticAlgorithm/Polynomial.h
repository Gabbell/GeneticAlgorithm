/*
 * Polynomial.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Gabriel
 */

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <vector>
#include <iostream>
#include "Functions.h"
#include "Predictor.h"

using namespace std;

class Polynomial {

public:
	Polynomial();
	Polynomial(int, int);
	void runAlgorithm(int, int);
	virtual ~Polynomial();

private:
	//Constants
	int INITIALPOPSIZE;
	int PREDICTORSIZE;
	int MAXGEN;
	int const RANGE = 10; //From 0 to 10

	//Data Structures
	vector<Predictor> parentpool;
	vector<Predictor> offspringpool;
	vector<Predictor> jointpool;

	//Objects & Variables
	Functions functions; //Contains all functions to manipulate data
	bool termination_criteria = false;
	int currentgen = 0;
};

#endif /* POLYNOMIAL_H_ */
