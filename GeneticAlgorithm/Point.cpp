#include "Point.h"

#include <iostream>
#include <iomanip>

using namespace std;

//Constructors and Destructors
Point::Point(){
	x = 0;
	y = 0;
	fitness = 0;
}
Point::Point(float x, float y){
	this -> x = x;
	this -> y = y;
	fitness = 0;
}
Point::~Point(){

}

//Getters
float Point::getX(){
	return x;
}
float Point::getY(){
	return y;
}
float Point::getFitness(){
	return fitness;
}

//Setters
void Point::setX(float x){
	this->x = x;
}
void Point::setY(float y){
	this->y = y;
}
void Point::setFitness(float fitness){
	this->fitness = fitness;
}

//Printing Function with precision of 9 digits
void Point::print(){
	cout << std::fixed;
	cout << std::setprecision(9) << x << "\t" << y << "\t" << fitness << endl;
}
