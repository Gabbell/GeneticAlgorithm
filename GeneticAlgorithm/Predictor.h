/*
 * Predictor.h
 *
 *  Created on: Apr 8, 2016
 *      Author: Gabriel
 */

#ifndef PREDICTOR_H_
#define PREDICTOR_H_

#include <vector>

using namespace std;

class Predictor {

public:

	Predictor();
	Predictor(float,float,float,float);
	float getFitness();
	void setFitness(float);
	float getA();
	float getB();
	float getC();
	float getD();
	void setA(float);
	void setB(float);
	void setC(float);
	void setD(float);
	void print();
	virtual ~Predictor();

private:
	float a,b,c,d;
	float fitness;

};

#endif /* PREDICTOR_H_ */
