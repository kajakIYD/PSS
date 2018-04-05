#ifndef SISO_H
#define SISO_H


class SISO
{
public:
    SISO();
    /*!
     * \brief simulate_step
     * perform one simulation step
     */
    virtual double Simulate_step(double input) = 0;
    //vi. destr.
};

#endif // SISO_H
