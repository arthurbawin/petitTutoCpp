
#include "myHeader.h"
#include "Geometry.h"
#include "Mesh.h"
#include "MeshReader.h"

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

double one(double x, double y)
{
	return 1.0;
}

double myFun(double x, double y)
{
	return x*y;
}


int main()
{
	// Let's say hello
	printHello();

	quadratureRule *rule = createQuadratureRule(3, elementType::TRI);

	// Exercice: Créer un objet Triangle représentant le triangle de référence (0,0), (1,0), (0,1)

	// Exercice: Calculer le jacobien et l'aire du triangle de référence

	// Exercice: Calculer l'intégrale de xy sur le triangle de référence

	// Now read a simple mesh file and create a Mesh structure
	std::string meshFile = "../data/tiny.txt";

	std::vector<double> coord;
	std::vector<int> connectivity;

	int numVertices, numElements, numLocalVertices;
	bool flag = readMesh(meshFile, coord, connectivity, &numVertices,
		&numElements, &numLocalVertices);

	if(!flag) {
		printf("Something went wrong while reading the mesh :/\n");
		return 1;
	}

	// Exercice: Créer une structure Mesh représentant un maillage de triangles/quadrangles
	Mesh myMesh(coord, connectivity);

	// Exercice: Calculer l'aire de la surface couverte par le maillage

	free(rule);

	return 0;
}