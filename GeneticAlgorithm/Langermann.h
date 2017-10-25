/*
 * Langermann.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Gabriel
 */

#ifndef LANGERMANN_H_
#define LANGERMANN_H_

#include <vector>
#include <iostream>
#include "Point.h"
#include "Functions.h"

using namespace std;

class Langermann {

public:
	Langermann();
	Langermann(int, int);
	void runAlgorithm(int, int);
	virtual ~Langermann();

private:
	//Constants
	int INITIALPOPSIZE ; //LANGERMANN : 100, POLY : 20
	int MAXGEN; //LANGERMANN : 10, POLY : 10
	int const XRANGE = 10; //From 0 to 10
	int const YRANGE = 10; //From 0 to 10

	//Data Structures
	vector<Point> parentpool;
	vector<Point> offspringpool;
	vector<Point> jointpool;

	//Objects & Variables
	Functions functions; //Contains all functions to manipulate data
	bool termination_criteria = false;
	int currentgen = 0;

};

#endif /* LANGERMANN_H_ */
