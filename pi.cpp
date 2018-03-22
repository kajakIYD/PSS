#include "pi.h"
#include <iostream>
#include <math.h>

using namespace std;

PI::PI(double dt, double max_u, double Kr, double Ti) :
    dt(dt),
    max_u(max_u),
    min_u(0),
    Kr(Kr),
    Ti(Ti),
    e0(0),
    integral(0),
    u(0)
{

}

double PI::simulate(double pv, double dt)
{
    // calculate error
    double e = setpoint - pv;

    // proportional term
    double u_p = Kr * e;

    // integral term
    // anti windup
    double u_i = (u >= max_u || u <= min_u) ? 0.0 : Kr*e * dt / Ti;    // ?????
    integral = integral + u_i;

        u = u_p + integral;      // total output

    u = (u >= max_u) ? max_u : u;
    u = (u <= min_u) ? 0.0 : u;

    return u;

}
