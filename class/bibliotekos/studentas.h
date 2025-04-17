#pragma once

#include "main_lib.h"

class studentas
{
private:
    string var, pav;
    vector<int> paz;
    int egz;
    double galutinisVid;
    double galutinisMed;

public:
    // konstruktoriai
    studentas() : egz(0) {};                                                                              // default konstruktorius
    studentas(const string &vardas, const string &pavarde, const vector<int> &paz, const int &egzaminas); // pilnas konstruktorius
    studentas(istream &is, int nd_count);

    // copy konstruktorius
    studentas(const studentas &other);

    // move konstruktorius
    studentas(studentas &&other) noexcept;

    // copy operatorius
    studentas &operator=(const studentas &other);

    // move operatorius
    studentas &operator=(studentas &&other) noexcept;

    // destruktorius
    ~studentas();

    // getteriai
    inline string vardas() const { return var; }
    inline string pavarde() const { return pav; }
    inline double galutinis_vidurkis() const { return galutinisVid; }
    inline double galutinis_mediana() const { return galutinisMed; }

    void calc_gal_vidurkis();
    void calc_gal_mediana();

    istream &paz_ivedimas(istream &is, int nd_count);
    void rank_vardo_ivedimas();
    void rank_paz_ivedimas();
    void gen_paz();
};

void failo_ivedimas(vector<studentas> &grupe, istream &is);
void stud_isskirstymas_1(const vector<studentas> &grupe);
void stud_isskirstymas_2(const vector<studentas> &grupe);
void stud_isskirstymas_3(const vector<studentas> &grupe);