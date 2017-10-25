/*
 * Functions.h
 *
 *  Created on: Mar 31, 2016
 *      Author: Gabriel
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#define M_PI 3.14159265359

#include <vector>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include "Predictor.h"
#include "Point.h"

using namespace std;

class Functions {

public:
	Functions();
	virtual ~Functions();

	//Polymorphic Functions
	void fitnessLangermann(vector<Point>&);
	void fitnessLangermann(Point&);

	void fitnessPoly(vector<Predictor>&);
	void fitnessPoly(Predictor&);

	Point intermediateCrossover(Point&, Point&);
	Predictor intermediateCrossover(Predictor&, Predictor&);

	Point realValuedMutation(Point&);
	Predictor realValuedMutation (Predictor&);

	//Templated Function
	template <typename T>
	void sortFitness(vector<T>&, int, int);

	template <typename T>
	vector<T> mergeVectors(vector<T>&,vector<T>&);

private:
	//Crossover
	float const OFFSPRINGFACTOR = 0.25; //Constant d
	float scalingfactor = 0; //Variable a

	//Mutation
	float const MUTATIONRANGE = 0.1; //Variable r
	float const MUTATIONPRECISION = 16; //Variable k

	//Size of sample point
	int const SAMPLESIZE = 20;
	int const XRANGE = 100;

};

template <typename T>
//Merge two vectors (parentpool and offspringpool) to create jointpool
vector<T> Functions::mergeVectors(vector<T>& vector1, vector<T>& vector2){
	vector<T> jointpool;
	for(int i = 0; i < abs((int)vector1.size()); i++){
		jointpool.push_back(vector1[i]);
	}
	for(int i = 0; i < abs((int)vector2.size()); i++){
		jointpool.push_back(vector2[i]);
	}
	return jointpool;
}
template <typename T>
//QuickSort of Fitness from jointpool
void Functions::sortFitness(vector<T>& jointpool, int left, int right){
    int i = left, j = right;
    T tmp;
    float pivot = jointpool[(left + right) / 2].getFitness();

    /* partition */
    while (i <= j) {

          while (jointpool[i].getFitness() < pivot)
                i++;

          while (jointpool[j].getFitness() > pivot)
                j--;

          if (i <= j) {
                tmp = jointpool[i];
                jointpool[i] = jointpool[j];
                jointpool[j] = tmp;

                i++;
                j--;
          }
    };

    /* recursion */
    if (left < j)
          sortFitness(jointpool, left, j);

    if (i < right)
          sortFitness(jointpool, i, right);
}

#endif /* FUNCTIONS_H_ */
