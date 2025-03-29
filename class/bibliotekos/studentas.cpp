#include "studentas.h"

studentas::~studentas()
{
    paz.clear();
    var = "";
    pav = "";
    int egz = 0;
    double galutinisVid = 0;
    double galutinisMed = 0;
}

studentas::studentas(const string &vardas, const string &pavarde, const vector<int> &paz, int egzaminas) : var(vardas), pav(pavarde), paz(paz), egz(egzaminas) {}