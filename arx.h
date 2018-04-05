#ifndef ARX_H
#define ARX_H

#include <deque>
#include <vector>
#include <random>

#include "siso.h"
#include "subject.h"
#include "config.h"

class ARX : public SISO, public Subject
{
public:
    ARX();

    double Simulate_step(double input);
    int GetSwitchTime();
    void UpdateParameters();

    double public_U=0;

private:
    Config *conf;
    std::default_random_engine generator;
    std::vector<double> parA;
    std::vector<double> parB;
    std::deque<double> u;
    std::deque<double> y;

    int dA;
    int dB;
    int k;
    int time = 0;
    int switchTime=0;

};

#endif // ARX_H
