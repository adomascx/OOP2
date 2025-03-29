#pragma once

#include "main_lib.h"

class studentas
{
public:
    string var, pav;
    vector<int> paz;
    int egz;
    double galutinisVid;
    double galutinisMed;

    studentas() : egz(0) {} // default konstruktorius
    studentas(const string& vardas, const string& pavarde, const vector<int>& paz, int egzaminas);
    //inline string vardas() const { return var; }        // get'eriai, inline
    //inline string pavarde() const { return pav; }      // get'eriai, inline
    //istream &readStudent(istream &);                   // set'eriai
    
    ~studentas();
};