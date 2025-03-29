#include "isvedimas.h"

void rez_isvedimas(ostream &out, char choice_mediana, const vector<studentas> &grupe)
{
    out << setw(15) << left << "Vardas"
        << setw(15) << "Pavarde"
        << setw(18) << "Galutinis (Vid.)";
    if (choice_mediana == 'y')
        out << "/ " << setw(20) << "Galutinis (Med.)";
    out << endl
        << string(75, '-') << endl;

    for (const auto &i : grupe)
    {
        out << setw(15) << left << i.vardas()
            << setw(15) << i.pavarde()
            << fixed << setprecision(3) << setw(20)
            << i.galutinis_vidurkis() << " ";
        if (choice_mediana == 'y')
            out << i.galutinis_mediana() << " ";
        out << endl;
    }
}

void failo_generavimas(string gen_file, int paz_sk, int dydis)
{
    timer_prad();
    ofstream fr(gen_file);
    if (!fr)
        throw runtime_error("Nepavyko sukurti " + gen_file + " failo");

    // antraste
    fr << setw(15) << left << "Vardas" << setw(15) << "Pavarde";
    for (int i = 0; i < paz_sk; i++)
    {
        fr << left << setw(5) << "ND" + to_string(i + 1);
    }
    fr << setw(5) << left << "EGZ" << endl;

    // studentu generavimas
    for (int i = 0; i < dydis; i++)
    {
        fr << setw(15) << left << "Vardas" + to_string(i + 1)
           << setw(15) << "Pavarde" + to_string(i + 1);
        for (int j = 0; j < paz_sk + 1; j++)
        {
            fr << left << setw(5) << (rand() % 10) + 1;
        }
        fr << endl;
    }
    fr.close();

    timer_pab("failo generavimas");
}
