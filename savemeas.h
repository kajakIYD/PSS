#ifndef PLOTDELEGATE_H
#define PLOTDELEGATE_H
#include "observer.h"
#include "ui_mainwindow.h"
#include <fstream>

class SaveMeas : public Observer
{
public:
    SaveMeas(const char* filePath);
    virtual void UpdateView(double u, double y);
private:
    std::ofstream outfile;
};

#endif // PLOTDELEGATE_H
