#include "bibliotekos/main_lib.h"
#include "bibliotekos/apdorojimas.h"
#include "bibliotekos/ivedimas.h"
#include "bibliotekos/isvedimas.h"

int main(int argc, char *argv[])
{
    srand(69420);
    ar_skaiciuoti_laika = true;
    int dydis;
    char strategija;
    string gen_file;

    /*
    Argumentai:
    1. Failo dydis
    2. Strategijos pasirinkimas (1-3)
    3. Failo generavimo pasirinkimas (1/0)
    */

    switch (argc)
    {
    case 2:
        dydis = atoi(argv[1]);
        cout << "Iveskite strategija: ";
        cin >> strategija;
        break;

    case 3:
        dydis = atoi(argv[1]);
        strategija = argv[2][0];
        break;

    case 4:

        dydis = atoi(argv[1]);
        strategija = argv[2][0];

        if (string(argv[3]) == "1")
        {
            gen_file = "teksto_failai/studentai" + to_string(dydis) + ".txt";
            failo_generavimas(gen_file, 10, dydis);
        }
        break;

    default:
        cout << "Iveskite failo dydi: ";
        cin >> dydis;
        cout << endl;
        cout << "Iveskite strategija: ";
        cin >> strategija;
        break;
    }

    gen_file = "teksto_failai/studentai" + to_string(dydis) + ".txt";
    cout << endl
         << "filesize: " << dydis;

    ifstream fd(gen_file);
    failo_ivedimas(fd);
    fd.close();

    char choice_mediana = 'y';

    for (auto &studentas : grupe)
    {
        studentas.galutinisVid = vidurkis_gal(studentas);
        if (choice_mediana == 'y')
            studentas.galutinisMed = mediana_gal(studentas);
    }

    cout << "Studentai skirstomi pagal pazymius..." << endl;

    switch (strategija)
    {
    case '1':
        stud_isskirstymas_1(grupe);
        break;
    case '2':
        stud_isskirstymas_2(grupe);
        break;
    case '3':
        stud_isskirstymas_3(grupe);
        break;
    default:
        cout << "Nepasirinkta strategija";
    }
}
