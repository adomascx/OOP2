#pragma once

#include "main_lib.h"

class zmogus
{
protected:
    string var, pav;

public:
    // konstruktoriai
    zmogus() = default;
    zmogus(const string &vardas, const string &pavarde) : var(vardas), pav(pavarde) {}

    // getteriai
    virtual string vardas() const = 0;
    virtual string pavarde() const = 0;

    virtual void rank_vardo_ivedimas() = 0;
    virtual void rank_paz_ivedimas() = 0;

    // destruktorius
    virtual ~zmogus() = 0;
};

class studentas : public zmogus
{
private:
    vector<int> paz;
    int egz;
    double galutinisVid;
    double galutinisMed;

public:
    // Konstruktoriai
    studentas();
    studentas(const string &vardas, const string &pavarde, const vector<int> &paz, const int &egzaminas);
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
    string vardas() const { return var; }
    string pavarde() const { return pav; }
    double galutinis_vidurkis() const { return galutinisVid; }
    double galutinis_mediana() const { return galutinisMed; }

    // setteriai
    istream &paz_ivedimas(istream &is, int nd_count);

    friend ostream &operator<<(ostream &os, const studentas &s);
    friend istream &operator>>(istream &is, studentas &s);

    void rank_vardo_ivedimas();
    void rank_paz_ivedimas();
    void gen_paz();

    // gaultinio balo apskaiciavimas
    void calc_gal_vidurkis();
    void calc_gal_mediana();
};

void failo_ivedimas(vector<studentas> &grupe, istream &is);
void stud_isskirstymas(const vector<studentas> &grupe);