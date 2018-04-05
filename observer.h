#ifndef OBSERVER_H
#define OBSERVER_H
#include <QVector>

class Observer {
public:
    virtual ~Observer () {}
    virtual void UpdateView(double x, double y) = 0;
};

#endif // OBSERVER_H
