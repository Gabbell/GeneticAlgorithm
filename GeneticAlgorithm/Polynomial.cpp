/*
 * Polynomial.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: Gabriel
 */

#include "Polynomial.h"

//Constructors
Polynomial::Polynomial(){
	INITIALPOPSIZE = 10;
	MAXGEN = 10;
	runAlgorithm(INITIALPOPSIZE, MAXGEN);
}
Polynomial::Polynomial(int INITIALPOPSIZE, int MAXGEN){
	this->INITIALPOPSIZE = INITIALPOPSIZE;
	this->MAXGEN = MAXGEN;
	runAlgorithm(INITIALPOPSIZE, MAXGEN);
}

//Destructor
Polynomial::~Polynomial(){

}

void Polynomial::runAlgorithm(int INITIALPOPSIZE, int MAXGEN){

	//Initializing random population
	for(int i = 0; i < INITIALPOPSIZE; i++){
		float a = (float)rand()/RAND_MAX * RANGE;
		float b = (float)rand()/RAND_MAX * RANGE;
		float c = (float)rand()/RAND_MAX * RANGE;
		float d = (float)rand()/RAND_MAX * RANGE;

		parentpool.push_back(Predictor(a,b,c,d));
	}

	cout << "Initialized population of " << INITIALPOPSIZE << " individuals" << endl;
	cout << endl;

	functions.fitnessPoly(parentpool); //Evaluates the fitness of all population for Polynomial

	//Iterative Selection
	while(!termination_criteria){

		while(abs((int)offspringpool.size()) < INITIALPOPSIZE*10){

			//Selecting two random parents
			Predictor parent1 = parentpool[rand()%INITIALPOPSIZE];
			Predictor parent2 = parentpool[rand()%INITIALPOPSIZE];

			//Intermediate Recombination Crossover
			Predictor offspring1 = functions.intermediateCrossover(parent1, parent2);
			Predictor offspring2 = functions.intermediateCrossover(parent1, parent2);

			//Real Valued Mutation
			offspring1 = functions.realValuedMutation(offspring1);
			offspring2 = functions.realValuedMutation(offspring2);

			//Calculating fitness for two offpsrings
			functions.fitnessPoly(offspring1);
			functions.fitnessPoly(offspring2);

			//Pushing offsprings into offspringpool
			offspringpool.push_back(offspring1);
			offspringpool.push_back(offspring2);
		}
		//Merging both offspring and parentpool
		jointpool = functions.mergeVectors<Predictor>(offspringpool,parentpool);

		//Sorting fitness of jointpool members
		functions.sortFitness(jointpool, 0, jointpool.size()-1);

		//Setting next population
		parentpool.clear();
		for(int i = 0; i < INITIALPOPSIZE; i++){
			parentpool.push_back(jointpool[i]);
		}

		//Clearing pools to make room for next round
		jointpool.clear();
		offspringpool.clear();

		//Incrementing current number of rounds and checking if it surpassed the maximum
		currentgen++;

		if(currentgen >= MAXGEN){
			termination_criteria = true;
		}
	}

	cout << "Parent pool after " << currentgen << " generations." << endl;
	cout << "A\t\tB\t\tC\t\tD\t\tFITNESS" << endl;
	for(int i = 0; i < abs((int)parentpool.size()); i++){
		parentpool[i].print();
	}
	cout << endl;
}

