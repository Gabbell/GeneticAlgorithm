/*
 * main.h
 *
 *  Created on: Mar 31, 2016
 *      Author: Gabriel
 */

#include <iostream>
#include <time.h>
#include <string>

#include "Langermann.h"
#include "Polynomial.h"

using namespace std;

int main() {

	//Initialize random seed
	srand (time(NULL));

/*
*	 Langermann Template -> Langerman(INITIIALPOPSIZE, MAXGEN)
*	 Default is INITIALPOPSIZE=100, MAXGEN=10
*/
	cout << "------------------------------------------------------------------" << endl;
	cout << "LANGERMANN FUNCTION" << endl;
	Langermann();

/*
*	 Polynomial Template -> Polynomial(INITIIALPOPSIZE, MAXGEN)
*	 Default is INITIALPOPSIZE=10, MAXGEN=10
*/
	cout << "------------------------------------------------------------------" << endl;
	cout << "POLYNOMIAL FUNCTION" << endl;
	cout << "1x^3 + 2x^2 + 3x + 4" << endl;
	Polynomial(100,100);

	string input;
	cin >> input;
	return 0;
}
