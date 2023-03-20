#ifndef _QUADRATURE_
#define _QUADRATURE_

enum class elementType {TRI, QUAD};

typedef struct {
    int n;
    const double *xsi;
    const double *eta;
    const double *weight;
} quadratureRule;

quadratureRule *createQuadratureRule(int numQuadPoints, elementType type);

#endif