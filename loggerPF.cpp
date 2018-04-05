#include "loggerPF.h"

LoggerPF::LoggerPF(const char* filePath)
{
    outfile.open(filePath, std::ios_base::app);
}

void LoggerPF::UpdateView(double u, double y)
{
    outfile << u << ";" << y << "\n";
}
