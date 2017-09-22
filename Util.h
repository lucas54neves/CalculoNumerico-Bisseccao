#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <iostream>
#include <math.h>
#include <functional>
#include <cstdlib>
#include <cstdio>


using namespace std;

const double VALOR_EULER = 2.71828182845904523536;

double calculaEuler(double& x){
    double res = (1 / pow(VALOR_EULER,x));
    return res;
}

#endif // UTIL_H_INCLUDED
