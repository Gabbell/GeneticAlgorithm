/*
 * Langermann.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: Gabriel
 */

#include "Langermann.h"

Langermann::Langermann(){
	INITIALPOPSIZE = 100;
	MAXGEN = 10;
	runAlgorithm(INITIALPOPSIZE, MAXGEN);
}
Langermann::Langermann(int INITIALPOPSIZE, int MAXGEN){
	this->INITIALPOPSIZE = INITIALPOPSIZE;
	this->MAXGEN = MAXGEN;
	runAlgorithm(INITIALPOPSIZE, MAXGEN);
}
Langermann::~Langermann(){

}

void Langermann::runAlgorithm(int INITIALPOPSIZE, int MAXGEN){
	//Initializing random population
	for(int i = 0; i < INITIALPOPSIZE; i++){
		float x = (float)rand()/RAND_MAX * XRANGE;
		float y = (float)rand()/RAND_MAX * YRANGE;

		parentpool.push_back(Point(x,y));
	}

	cout << "Initialized population of " << INITIALPOPSIZE << " individuals" << endl;
	cout << endl;

	functions.fitnessLangermann(parentpool); //Evaluates the fitness of all population for Langermann

	//Iterative Selection
	while(!termination_criteria){

		while(abs((int)offspringpool.size()) < INITIALPOPSIZE*10){

			//Selecting two random parents
			Point parent1 = parentpool[rand()%INITIALPOPSIZE];
			Point parent2 = parentpool[rand()%INITIALPOPSIZE];

			//Intermediate Recombination Crossover
			Point offspring1 = functions.intermediateCrossover(parent1, parent2);
			Point offspring2 = functions.intermediateCrossover(parent1, parent2);

			//Real Valued Mutation
			offspring1 = functions.realValuedMutation(offspring1);
			offspring2 = functions.realValuedMutation(offspring2);

			//Calculating fitness for two offpsrings
			functions.fitnessLangermann(offspring1);
			functions.fitnessLangermann(offspring2);

			//Pushing offsprings into offspringpool
			offspringpool.push_back(offspring1);
			offspringpool.push_back(offspring2);
		}
		//Merging both offspring and parentpool
		jointpool = functions.mergeVectors<Point>(offspringpool,parentpool);

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
	cout << "X\t\tY\t\tFITNESS" << endl;
	for(int i = 0; i < abs((int)parentpool.size()); i++){
		parentpool[i].print();
	}
	cout << endl;
}
