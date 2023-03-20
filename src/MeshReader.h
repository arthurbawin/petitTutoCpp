#ifndef _MESH_READER_
#define _MESH_READER_

#include <string>
#include <vector>

bool readMesh(const std::string &meshFile,
	std::vector<double> &coord,
	std::vector<int> &connectivity,
	int *numVertices,
	int *numElements,
	int *numLocalVertices);

#endif