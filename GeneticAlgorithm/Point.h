/*
 * Point.h
 *
 *  Created on: Mar 31, 2016
 *      Author: Gabriel
 */

#ifndef POINT_H_
#define POINT_H_

using namespace std;

class Point {

private:
	float x;
	float y;
	float fitness;

public:
	Point();
	Point(float,float);
	float getX();
	float getY();
	float getFitness();
	void setX(float);
	void setY(float);
	void setFitness(float);
	void print();
	virtual ~Point();
};

#endif /* POINT_H_ */
