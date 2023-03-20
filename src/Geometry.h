#ifndef _GEOMETRY_
#define _GEOMETRY_

#include <vector>
#include <array>

#include "Quadrature.h"

//
// A vertex in 3D with 3 coordinates and a tag (identifier)
// 
class Vertex
{
private:
	int _tag;
	double _pos[3];
public:
	Vertex(int tag, double x, double y, double z);
	Vertex(int tag, double pos[3]);
	Vertex(int tag, const std::vector<double> &pos);

	int tag() const { return _tag; };
	double x() const { return _pos[0]; };
	double y() const { return _pos[1]; };
	double z() const { return _pos[2]; };
};

//
// An abstract geometric element, essentially a list of vertices
//
class Element
{
protected:
	int _numVertices;
	std::vector<const Vertex*> _vertices;

public:
	Element(){};

	virtual void evaluateBasisFunctions(double xsi, double eta, double res[3]) = 0;
	virtual double computeJacobian(double xsi, double eta) = 0;
	virtual double computeArea() = 0;
	virtual double integrate(quadratureRule *rule, double(*fun)(double,double)) = 0;
};

class Triangle : public Element
{
private:

public:
	Triangle(const Vertex *v0, const Vertex *v1, const Vertex *v2);

	void evaluateBasisFunctions(double xsi, double eta, double res[3]);
	double computeJacobian(double xsi, double eta);
	double computeArea();
	double integrate(quadratureRule *rule, double(*fun)(double,double));

};

class Quadrangle : public Element
{
private:

public:
	Quadrangle(const Vertex *v0, const Vertex *v1, const Vertex *v2, const Vertex *v3);

	void evaluateBasisFunctions(double xsi, double eta, double res[3]);
	double computeJacobian(double xsi, double eta);
	double computeArea();
	double integrate(quadratureRule *rule, double(*fun)(double,double));

};

#endif