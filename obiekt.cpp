#include "obiekt.h"

obiekt::obiekt(double A, double c):
    A(A),
    c(c)
{

}

double obiekt::simulate(double qwe, double dt)
{
    h += (1/A)*(qwe - c*h) * dt;
    //Notify({1 + qwe, 2 + qwe}, {1+h, 2+h});
    return h;
}
