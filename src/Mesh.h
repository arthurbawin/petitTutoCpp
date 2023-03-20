#ifndef _MESH_
#define _MESH_

#include "Geometry.h"

class Mesh
{
private:
	std::vector<Vertex*> _vertices;
	std::vector<Element*> _elements;

public:
	Mesh(const std::vector<double> &coord, const std::vector<int> &connectivity);

	double computeArea();
};

#endif