#include <cstdio>
#include <cstdlib>
#include <vector>
#include "spline.h"


int main(int argc, char** argv)
{
    if(argc<1) {
        printf("usage: %s <>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    std::vector<double> X(5), Y(5);
    X[0]=0.1;
    X[1]=0.4;
    X[2]=1.2;
    X[3]=1.8;
    X[4]=2.0;
    Y[0]=0.1;
    Y[1]=0.7;
    Y[2]=0.6;
    Y[3]=1.1;
    Y[4]=0.9;

    tk::spline s;
    // set_boundary() is optional and if omitted, natural boundary condition,
    // f''(a)=f''(b)=0, will be used
    // note, if natural boundary conditions are not used then extrapolation
    // will be a quadratic function, unless the last argument is set to true,
    // which forces linear extrapolation, but this will violate second order
    // differentiability at the endpoint
    s.set_boundary(tk::spline::second_deriv, 0.0,
                   tk::spline::first_deriv, -2.0, false);
    s.set_points(X,Y);

    for(size_t i=0; i<X.size(); i++) {
        printf("%f %f\n", X[i], Y[i]);
    }
    printf("\n");
    for(int i=-50; i<250; i++) {
        double x=0.01*i;
        printf("%f %f\n", x, s(x));
    }
    printf("\n");

    return EXIT_SUCCESS;
}


