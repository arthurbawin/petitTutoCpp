
#include "Geometry.h"
#include <iostream>

//
// Classe Vertex
//
Vertex::Vertex(int tag, double x, double y, double z)
{
	// ...
}

Vertex::Vertex(int tag, double pos[3])
{
	// ...
}

Vertex::Vertex(int tag, const std::vector<double> &pos)
{
	// ...
}

//
// Classe Triangle
//
Triangle::Triangle(const Vertex *v0, const Vertex *v1, const Vertex *v2)
{
	// ...
}

void Triangle::evaluateBasisFunctions(double xsi, double eta, double *res)
{
	res[0] = 0.;
	res[1] = 0.;
	res[2] = 0.;
}

void Triangle::evaluateBasisFunctionsDerivatives(double xsi, double eta, double *res)
{
	// dphidr
	res[0] = 0.;
	res[1] = 0.;
	res[2] = 0.;

	// dphids
	res[3] = 0.;
	res[4] = 0.;	
	res[5] = 0.;	
}

// 
// det J = (x1 - x0)(y2 - y0) - (x2 - x0)(y1 - y0) (constant!)
//
double Triangle::computeJacobian(double xsi, double eta)
{
	return 0.;
}

double Triangle::computeArea()
{
	return 0.;
}

double Triangle::integrate(quadratureRule *rule, double(*fun)(double,double))
{
	double res = 0.;
	return res;
}

//
// Classe Quandrangle
//
Quadrangle::Quadrangle(const Vertex *v0, const Vertex *v1, const Vertex *v2, const Vertex *v3)
{
	// ...
}

void Quadrangle::evaluateBasisFunctions(double xsi, double eta, double *res)
{
	res[0] = 0.;
	res[1] = 0.;
	res[2] = 0.;
	res[3] = 0.;
}

void Quadrangle::evaluateBasisFunctionsDerivatives(double xsi, double eta, double *res)
{
	// dphidr
	res[0] = 0.;
	res[1] = 0.;
	res[2] = 0.;
	res[3] = 0.;

	// dphids
	res[4] = 0.;
	res[5] = 0.;
	res[6] = 0.;
	res[7] = 0.;
}

double Quadrangle::computeJacobian(double xsi, double eta)
{
	return 0.;
}

double Quadrangle::computeArea()
{
	return 0.;
}

double Quadrangle::integrate(quadratureRule *rule, double(*fun)(double,double))
{
	double res = 0.;
	return res;
}