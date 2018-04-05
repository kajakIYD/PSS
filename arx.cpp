#include "arx.h"

ARX::ARX()
{
    //destrctor and make it aggregation(outside of that class, in mw)
    this->conf = new Config("E:\\Qt\\Projects\\PSS\\PSS_Config.xml");

    parA = conf->A;
    parB = conf->B;

    s_k = conf->delay;
    s_switchTime = conf->switchTime;

    // stopnie wielomianów
    s_dA = parA.size();
    s_dB = parB.size()-1;

    // wstępne zerowanie wektorów
    for(int i=0; i < s_dA;i++)
    y.push_back(0);

    for(int i=0;i < s_dB+s_k+1 ;i++)
    u.push_back(0);

}

void ARX::UpdateParameters()
{
    parA = conf->A_N;
    parB = conf->B_N;
}


int ARX::GetSwitchTime()
{
    return this->s_switchTime;
}

double ARX::Simulate_step(double input)
{
    //make it static (optimal)
    std::deque<double> subU, subY;

    // generate random e value
    std::normal_distribution<double> distribution(0, s_var);
    double e = distribution(generator);

    // delete oldest value and push newest
    u.pop_back();
    u.push_front(input);

    // copy u vector with k offset
    auto it = u.begin();
    advance(it, this->s_k);
    std::copy(it, u.end(), std::back_inserter(subU));

    // copy y vector with dA offset
    it = y.begin();
    advance(it, this->s_dA);
    std::copy(y.begin(), it, std::back_inserter(subY));
    //std::copy(it, y.end(), std::back_inserter(subY));

    double output1, output2, dist;

    // generate new output
    output1 = inner_product(parB.begin(), parB.end(), subU.begin(), 0.0);
    output2 = - inner_product(parA.begin(), parA.end(), subY.begin(), 0.0);
    dist = 0 - e;

    this->y.pop_back();
    this->y.push_front(output1 + output2 + dist);
    double output = output1 + output2 + dist;
    Notify(input, output);

    return output;
}
