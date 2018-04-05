#include "arx.h"

ARX::ARX()
{
    this->conf = new Config("E:\\Qt\\Projects\\PSS\\PSS_Config.xml");

    parA = conf->A;
    parB = conf->B;

    k = conf->delay;
    switchTime = conf->switchTime;

    // stopnie wielomianów
    dA = parA.size()-1;
    dB = parB.size()-1;

    // wstępne zerowanie wektorów
    for(int i=0; i < dA ;i++)
    y.push_back(0);

    for(int i=0;i < dB+k ;i++)
    u.push_back(0);

}

void ARX::UpdateParameters()
{
    parA = conf->A_N;
    parB = conf->B_N;
}


int ARX::GetSwitchTime()
{
    return this->switchTime;
}

double ARX::Simulate_step(double input)
{
    std::deque<double> subU, subY;

    // generate random e value
    std::normal_distribution<double> distribution(0,1.0);
    double e = distribution(generator);

    // delete oldest value and push newest
    u.pop_back();
    u.push_front(input);

    // copy u vector with k offset
    auto it = u.begin();
    advance(it, this->k);
    std::copy(it, u.end(), std::back_inserter(subU));

    // copy y vector with dA offset
    it = y.begin();
    advance(it, this->dA);
    std::copy(y.begin(), it, std::back_inserter(subY));
    //std::copy(it, y.end(), std::back_inserter(subY));

    double output;

    // generate new output
    output = inner_product(parB.begin(), parB.end(), subU.begin(), 0.0) - inner_product(parA.begin(), parA.end(), subY.begin(), 0.0) - e;

    this->y.pop_back();
    this->y.push_front(output);

    Notify(input, output);

    return output;
}
