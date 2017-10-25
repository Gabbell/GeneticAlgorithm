#include "Functions.h"

#include <iostream>

using namespace std;
Functions::Functions(){

}
Functions::~Functions(){

}
//Langermann Function Fitness
void Functions::fitnessLangermann(vector<Point> &pointvector){

	//Langermann's Function
	float fitness;
	int m = 5;
	float a[5] = {3, 5, 2, 1, 7};
	float b[5] = {5, 2, 1, 4, 9};
	float c[5] = {1, 2, 5, 2, 3};

	for(int i = 0; i < abs((int)pointvector.size()); i++){
		fitness = 0; //Resetting fitness for every point
		float x = pointvector[i].getX();
		float y = pointvector[i].getY();

		for(int j = 1; j < m; j++){
			//LANGERMANN FUNCTION IMPLEMENTATION
			fitness += c[j] * exp(-pow((x-a[j]),2)/M_PI - pow((y-b[j]),2)/M_PI)*cosf(M_PI*pow((x-a[j]),2)+M_PI*pow((y-b[j]),2));
		}

		pointvector[i].setFitness(fitness);
	}
}
void Functions::fitnessLangermann(Point &point){

	//Langermann's Function
	float fitness = 0;
	int m = 5;
	float a[5] = {3, 5, 2, 1, 7};
	float b[5] = {5, 2, 1, 4, 9};
	float c[5] = {1, 2, 5, 2, 3};

	float x = point.getX();
	float y = point.getY();

	for(int j = 1; j < m; j++){
		//LANGERMANN FUNCTION IMPLEMENTATION
		fitness += c[j] * exp(-pow((x-a[j]),2)/M_PI - pow((y-b[j]),2)/M_PI)*cosf(M_PI*pow((x-a[j]),2)+M_PI*pow((y-b[j]),2));
	}

	point.setFitness(fitness);
}
//Polynomial Function Fitness
void Functions::fitnessPoly(vector<Predictor> &predvector){
	float a = 1;
	float b = 2;
	float c = 3;
	float d = 4;
	float fitness = 0;

	for(int j = 0; j < abs((int)predvector.size()); j++){

		fitness = 0; //Resetting fitness

		for(int i = 0; i < SAMPLESIZE; i++){
			float x = rand()%XRANGE - (XRANGE/2); //Choosing random x's as a sample
			float y1 = a*pow(x,3) + b*pow(x,2) + c*x + d;
			float y2 = predvector[j].getA()*pow(x,3) + predvector[j].getB()*pow(x,2) + predvector[j].getC()*x + predvector[j].getD();

			fitness += pow(y2-y1,2);
		}
		fitness /= SAMPLESIZE;

		predvector[j].setFitness(fitness);
	}
}
//Polynomial Function Fitness
void Functions::fitnessPoly(Predictor &predictor){
	float a = 1;
	float b = 2;
	float c = 3;
	float d = 4;
	float fitness = 0;

	for(int i = 0; i < SAMPLESIZE; i++){
		float x = rand()%XRANGE - (XRANGE/2); //Choosing random x's as a sample
		float y1 = a*pow(x,3) + b*pow(x,2) + c*x + d;
		float y2 = predictor.getA()*pow(x,3) + predictor.getB()*pow(x,2) + predictor.getC()*x + predictor.getD();

		fitness += pow(y2-y1,2);
	}
	fitness /= SAMPLESIZE;

	predictor.setFitness(fitness);
}

//Intermediate Crossover, Point
Point Functions::intermediateCrossover(Point &point1, Point &point2){

	scalingfactor = (float)rand()/RAND_MAX * (OFFSPRINGFACTOR*2 + 1) - OFFSPRINGFACTOR;
	float x = point1.getX() + scalingfactor*(point2.getX() - point1.getX());

	scalingfactor = (float)rand()/RAND_MAX * (OFFSPRINGFACTOR*2 + 1) - OFFSPRINGFACTOR;
	float y = point1.getY() + scalingfactor*(point2.getY() - point1.getX());
	return Point(x,y);
}
//Intermediate Crossover, Predictor
Predictor Functions::intermediateCrossover(Predictor &pred1, Predictor &pred2){

	scalingfactor = (float)rand()/RAND_MAX * (OFFSPRINGFACTOR*2 + 1) - OFFSPRINGFACTOR;
	float a = pred1.getA() + scalingfactor*(pred2.getA() - pred1.getA());

	scalingfactor = (float)rand()/RAND_MAX * (OFFSPRINGFACTOR*2 + 1) - OFFSPRINGFACTOR;
	float b = pred1.getB() + scalingfactor*(pred2.getB() - pred1.getB());

	scalingfactor = (float)rand()/RAND_MAX * (OFFSPRINGFACTOR*2 + 1) - OFFSPRINGFACTOR;
	float c = pred1.getC() + scalingfactor*(pred2.getC() - pred1.getC());

	scalingfactor = (float)rand()/RAND_MAX * (OFFSPRINGFACTOR*2 + 1) - OFFSPRINGFACTOR;
	float d = pred1.getD() + scalingfactor*(pred2.getD() - pred1.getD());

	return Predictor(a,b,c,d);
}

//Real Valued Mutation, Point
Point Functions::realValuedMutation(Point &point){

	float s[2] = {-1, 1};
	float u[2] = {0, 1};

	float si = s[(int)rand()%2];
	float ri = MUTATIONRANGE*10;
	float ai = pow(2,-u[(int)rand()%2]*MUTATIONPRECISION );

	float x = point.getX() + (si * ri * ai);
	float y = point.getY() + (si * ri * ai);

	return Point(x,y);
}
//Real Valued Mutation, Predictor
Predictor Functions::realValuedMutation(Predictor &predictor){

	float s[2] = {-1, 1};
	float u[2] = {0, 1};

	float si = s[(int)rand()%2];
	float ri = MUTATIONRANGE*10;
	float ai = pow(2,-u[(int)rand()%2]*MUTATIONPRECISION );

	float a = predictor.getA() + (si * ri * ai);
	float b = predictor.getB() + (si * ri * ai);
	float c = predictor.getC() + (si * ri * ai);
	float d = predictor.getD() + (si * ri * ai);

	return Predictor(a,b,c,d);
}
