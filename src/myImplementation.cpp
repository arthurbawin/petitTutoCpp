
#include "myHeader.h"
#include <iostream>

void printHello()
{
	std::cout << "Hello World!" << std::endl;
}

myMatrix::myMatrix(double values[9])
{
	for(int i = 0; i < 9; ++i) {
		_val[i] = values[i];
		values[i] = 1.;
	}
}

myMatrix::myMatrix(std::vector<double> &values)
{
	for(int i = 0; i < values.size(); ++i) {
		_val[i] = values[i];
		values[i] = 1.;
	}
}

myMatrix::myMatrix(const std::vector<double> &values)
{
	for(int i = 0; i < values.size(); ++i) {
		_val[i] = values[i];
	}
}

void myMatrix::print()
{
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			std::cout << _val[3 * i + j] << " ";
		}
		std::cout << std::endl;
	}
}
