
#include "Quadrature.h"

#include <stdlib.h>
#include <iostream>

static const double _gaussQuad4Xsi[4]    = {-0.577350269189626,-0.577350269189626, 0.577350269189626, 0.577350269189626};
static const double _gaussQuad4Eta[4]    = { 0.577350269189626,-0.577350269189626,-0.577350269189626, 0.577350269189626};
static const double _gaussQuad4Weight[4] = { 1.000000000000000, 1.000000000000000, 1.000000000000000, 1.000000000000000};
static const double _gaussTri3Xsi[3]     = { 0.166666666666667, 0.666666666666667, 0.166666666666667};
static const double _gaussTri3Eta[3]     = { 0.166666666666667, 0.166666666666667, 0.666666666666667};
static const double _gaussTri3Weight[3]  = { 0.166666666666667, 0.166666666666667, 0.166666666666667};

quadratureRule *createQuadratureRule(int n, elementType type)
{
    quadratureRule *rule = (quadratureRule*) malloc(sizeof(quadratureRule));
    if (type == elementType::QUAD && n == 4) {
        rule->n      = 4;
        rule->xsi    = _gaussQuad4Xsi;
        rule->eta    = _gaussQuad4Eta;
        rule->weight = _gaussQuad4Weight; }
    else if (type == elementType::TRI && n == 3) {
        rule->n      = 3;
        rule->xsi    = _gaussTri3Xsi;
        rule->eta    = _gaussTri3Eta;
        rule->weight = _gaussTri3Weight; }
    else printf("Cannot create such an integration rule !");
    return rule; 
}