#include "ivedimas.h"

void stud_ivedimas(stud_struct &temp)
{
    cout << "Iveskite studento varda: ";
    cin >> temp.var;
    if (!cin)
        throw runtime_error("Netinkamai ivestas vardas. Bandykite vel");

    cout << "Iveskite studento pavarde: ";
    cin >> temp.pav;
    if (!cin)
        throw runtime_error("Netinkamai ivesta pavarde. Bandykite vel");
}

void paz_ivedimas(stud_struct &temp)
{
    while (true)
    {
        int pazymys{};
        cout << "Iveskite mokinio pazymi (0, jei daugiau pazymiu nera): ";
        cin >> pazymys;
        if (!cin || pazymys > 10)
            throw runtime_error("Netinkamas pazymys. Pasirinkite skaiciu nuo 1 iki 10");

        if (pazymys)
            temp.paz.push_back(pazymys);
        else
            break;
    }

    if (temp.paz.empty())
    {
        throw runtime_error("Nera ivestu pazymiu. Prasome ivesti bent viena pazymi.");
    }

    cout << "Iveskite egzamino rezultata: ";
    cin >> temp.egz;
    if (!cin || temp.egz > 10)
        throw runtime_error("Netinkamas egzamino balas. Pasirinkite skaiciu nuo 1 iki 10");
}

void gen_paz(stud_struct &temp)
{
    for (int i = 0; i < 32; i++)
    {
        temp.paz.push_back(rand() % 10);
    }
    temp.egz = rand() % 10;
}

void failo_ivedimas(istream &in)
{
    stud_struct temp;
    int pazymys;

    string line, word;

    // ND kiekio radimas pagal antraštę
    getline(in, line);
    istringstream antraste(line);

    int nd_count{};
    while (antraste >> word)
    {
        nd_count++;
    }

    // Galutinis ND numeris (atemus varda, pavarder ir egz. bala)
    nd_count -= 3;

    timer_prad();
    cout << endl << "Ivedami duomenys..." << endl;

    // Duomenų įvedimas iš failo
    while (getline(in, line))
    {
        istringstream iss(line);

        iss >> temp.var >> temp.pav;

        for (int i = 0; i < nd_count; i++)
        {
            iss >> pazymys;
            temp.paz.push_back(pazymys);
        }

        iss >> temp.egz;

        grupe.push_back(temp);
        temp.paz.clear();
    }
    
    timer_pab("Failo ivedimas");
}