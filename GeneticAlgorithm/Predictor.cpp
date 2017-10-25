/*
 * Predictor.cpp
 *
 *  Created on: Apr 8, 2016
 *      Author: Gabriel
 */

#include "Predictor.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Constructor
Predictor::Predictor() {
	fitness = -1;
	a = 1;
	b = 1;
	c = 1;
	d = 1;
}
Predictor::Predictor(float a, float b, float c, float d){
	fitness = -1;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

//Destructor
Predictor::~Predictor() {

}

//Getters
float Predictor::getA(){
	return a;
}
float Predictor::getB(){
	return b;
}
float Predictor::getC(){
	return c;
}
float Predictor::getD(){
	return d;
}
float Predictor::getFitness(){
	return fitness;
}

//Setters
void Predictor::setA(float a){
	this->a = a;
}
void Predictor::setB(float b){
	this->b = b;
}
void Predictor::setC(float c){
	this->c = c;
}
void Predictor::setD(float d){
	this->d = d;
}
void Predictor::setFitness(float fitness){
	this->fitness = fitness;
}

//Printing Function with precision of 9 digits
void Predictor::print(){
	cout << std::fixed;
	cout << std::setprecision(9) << a << "x^3\t" << b << "x^2\t" << c << "x\t" << d << "\t" << fitness << endl;
}
