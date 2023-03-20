
#include "MeshReader.h"
#include <string.h>

bool readMesh(const std::string &meshFile, std::vector<double> &coord,
	std::vector<int> &connectivity, int *numVertices,
	int *numElements, int *numLocalVertices)
{    
    FILE* file = fopen(meshFile.data(),"r");
    if (file == nullptr){ 
    	printf("No mesh file ! Aborting");
    	return false;
    }

    int nVertices = -1, placeholder;

    fscanf(file, "Number of nodes %d \n", &nVertices);
    coord.resize(2 * nVertices, 0.);

    printf("Read %d vertices", nVertices);

    // Read vertices
    for(int i = 0; i < nVertices; ++i) {
        fscanf(file,"%d : %le %le \n", 
        	&placeholder,
        	&coord[2 * i],
        	&coord[2 * i + 1]);
    }
    
    char str[256]; 
    if (fgets(str, sizeof(str), file) == NULL) {
    	printf("Corrupted mesh file !");
    	return false;
    }

    int nElements, nLocalVertices;
    if (!strncmp(str,"Number of triangles",19)) {
    	nLocalVertices = 3;
        sscanf(str,"Number of triangles %d \n", &nElements);
        connectivity.resize(3 * nElements);
        int v0, v1, v2;
        for (int i = 0; i < nElements; ++i) {
            fscanf(file,"%d : %d %d %d\n", &placeholder, &v0, &v1, &v2);
            connectivity[3 * i + 0] = v0;
            connectivity[3 * i + 1] = v1;
            connectivity[3 * i + 2] = v2;
		}
	}
    else if (!strncmp(str,"Number of quds",15)) {
    	nLocalVertices = 4;
        sscanf(str,"Number of quads %d \n", &nElements);
        connectivity.resize(4 * nElements);
        int v0, v1, v2, v3; 
        for (int i = 0; i < nElements; ++i) {
            fscanf(file,"%d : %d %d %d %d\n", &placeholder, &v0, &v1, &v2, &v3);
            connectivity[4 * i + 0] = v0;
            connectivity[4 * i + 1] = v1;
            connectivity[4 * i + 2] = v2;
            connectivity[4 * i + 3] = v3;
		}
	}
	else {
		printf("Unrecognized element type!\n");
		return false;
	}
    fclose(file);
            
    *numVertices = nVertices;
    *numElements = nElements;
    *numLocalVertices = nLocalVertices;

    return true;
}
