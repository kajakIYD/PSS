#include "savemeas.h"

SaveMeas::SaveMeas(const char* filePath)
{
    outfile.open(filePath, std::ios_base::app);
}

void SaveMeas::UpdateView(double u, double y)
{
    outfile << u << ";" << y << "\n";
}
