#ifndef MY_HEADER
#define MY_HEADER

#include <vector>
#include <array>

void printHello();

//
// A class for 3x3 matrices
//
class myMatrix
{
private:
	double _val[9];

public:
	// Constructor using a static array
	myMatrix(double values[9]);
	// Constructor using a vector of data
	myMatrix(std::vector<double> &values);
	myMatrix(const std::vector<double> &values);

	void print();
};

#endif