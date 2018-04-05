#ifndef SUBJECT_H
#define SUBJECT_H
#include "observer.h"

class Observer;

class Subject
{
public:
    virtual ~Subject ();
    bool RegisterObserver (Observer * observer);
    bool UnregisterObserver (Observer * observer);
    void Notify (double u,  double y) const;
private:
    std::list<Observer * > s_Observers;
};

#endif // SUBJECT_H
