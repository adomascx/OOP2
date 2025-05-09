#include "bibliotekos/main_lib.h"
#include "bibliotekos/apdorojimas.h"
#include "bibliotekos/ivedimas.h"
#include "bibliotekos/isvedimas.h"

int main()
{

    srand(69420);
    char choice; // vartotojo pasirinkimas

    // Failo generavimo pasirinkimas
    cout << "Ar norite sugeneruoti studentu faila? (y/n): " << endl;
    try
    {
        cin >> choice;
        if (choice == 'y')
        {

            string gen_file; // generuojamo failo pavadinimas
            int dydis;       // studentu norimas skaicius
            int paz_sk;      // ND norimas skaicius

            cout << "Iveskite studentu kieki: " << endl;
            cin >> dydis;
            if (!cin)
                throw runtime_error("Netinkamas studentu kiekis. Pasirinkite skaiciu nuo 1 iki 2147483647");

            cout << "Iveskite pazymiu kieki: " << endl;
            cin >> paz_sk;
            if (!cin)
                throw runtime_error("Netinkamas pazymiu kiekis. Pasirinkite skaiciu nuo 1 iki 2147483647");

            // failo pavadinimas formatu "studentai[N].txt"
            gen_file = "txt/studentai" + to_string(dydis) + ".txt";

            failo_generavimas(gen_file, paz_sk, dydis);
        }
        else if (choice != 'n')
            throw runtime_error("Netinkamas pasirinkimas. Galimi pasirinkimai: 'y' arba 'n'");
    }
    catch (runtime_error &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }

    // Pagrindinis meniu
    cout << endl
         << "Kaip norite ivesti pazymius/studentu vardus?:" << endl
         << "1 - ranka" << endl
         << "2 - generuoti TIK pazymius" << endl
         << "3 - generuoti studentu vardus IR pazymius" << endl
         << "4 - ivesti duomenis is failo" << endl
         << "5 - baigti darba" << endl;
    cin >> choice;

    stud_struct temp; // laikinas įvedimo masyvas

    try
    {
        switch (choice)
        {
        // ranka
        case '1':
        {
            while (true)
            {
                stud_ivedimas(temp);
                paz_ivedimas(temp);

                grupe.push_back(temp);

                // ar kartoti ivedimo/generavimo cikla?
                cout << "Ar norite toliau ivesti studentus? (y/n): " << endl;
                cin >> choice;
                if (choice == 'n')
                    break;
                else if (choice == 'y')
                    continue;
                else
                    throw runtime_error("Netinkamas pasirinkimas. Galimi pasirinkimai: 'y' arba 'n'");
            }
            break;
        }

        // generuoti TIK pazymius
        case '2':
        {
            while (true)
            {
                // vardu/pavardziu rankinis ivedimas
                stud_ivedimas(temp);

                // pazymiu generavimas
                gen_paz(temp);

                grupe.push_back(temp);
                temp.paz.clear();

                // ar kartoti ivedimo/generavimo cikla?
                cout << "Ar norite toliau ivesti studentus? (y/n): " << endl;
                cin >> choice;
                if (choice == 'n')
                    break;
                else if (choice == 'y')
                    continue;
                else
                    throw runtime_error("Netinkamas pasirinkimas. Galimi pasirinkimai: 'y' arba 'n'");
            }
            break;
        }

        // generuoti studentu vardus IR pazymius
        case '3':
        {
            cout << "Kiek studentu norite sugeneruoti?: ";
            int i;
            cin >> i;
            if (!cin || i == 0)
                throw runtime_error("Netinkamas pasirinkimas. Pasirinkite skaiciu nuo 1 iki 2147483647");
            for (; i > 0; i--)
            {
                // vardu/pavardziu generavimas
                temp.var = vardas[rand() % 16];
                temp.pav = pavarde[rand() % 16];

                // pazymiu generavimas
                gen_paz(temp);

                grupe.push_back(temp);
                temp.paz.clear();
            }
            break;
        }

        // ivesti duomenis is failo
        case '4':
        {
            // Įvedimo failo atidarymas
            string input_file;
            cout << endl
                 << "Iveskite failo pavadinima: " << endl;
            cin >> input_file;

            // atidaryti faila tinkamoje direktorijoje
            input_file = "txt/" + input_file;
            ifstream fd(input_file);

            if (!fd)
            {
                throw runtime_error("Nepavyko atidaryti ivedimo failo");
            }

            // viso failo ivedimas i atminti
            failo_ivedimas(fd);

            fd.close();

            if (grupe.empty())
            {
                throw runtime_error("Failas tuscias arba netinkamo formato.");
            }
            else
                cout << "Failas ivestas sekmingai.";
            break;
        }

        // baigti darba
        case '5':
            return 0;

        default:
            throw runtime_error("Netinkamas pasirinkimas. Pasirinkite skaiciu nuo 1 iki 5");
        }
    }
    catch (runtime_error &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }

    // medianos skaiciavimo pasirinkimas
    char choice_mediana;
    try
    {
        cout << "\nAr norite taip pat skaiciuoti mediana?  (y/n): " << endl;
        cin >> choice_mediana;
        if (choice_mediana != 'y' && choice_mediana != 'n')
        {
            throw runtime_error("Netinkamas pasirinkimas. Galimi pasirinkimai: 'y' arba 'n'");
        }
    }
    catch (runtime_error &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }

    for (auto &student : grupe)
    {
        student.galutinisVid = vidurkis_gal(student);
        if (choice_mediana == 'y')
            student.galutinisMed = mediana_gal(student);
    }

    // diskriminavimas (vektoriaus padalinimas i 2 dalis)
    try
    {
        cout << endl
             << "Studentai skirstomi pagal pazymius..." << endl;
        stud_isskirstymas_3(grupe);
    }
    catch (runtime_error &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }

    cout << endl
         << "Kaip norite rusiuoti studentu rezultatus?: " << endl
         << "1 - Pagal varda" << endl
         << "2 - Pagal pavarde" << endl
         << "3 - Pagal galutini rezultata (vidurkis)" << endl
         << "4 - Pagal galutini rezultata (mediana)" << endl
         << "5 - Nerusiuoti rezultatu" << endl;

    // Duomenų rūšiavimo algoritmai
    try
    {
        cin >> choice;
        switch (choice)
        {
        case '1':
            sort(grupe.begin(), grupe.end(), [](const auto &a, const auto &b)
                 { return a.var < b.var; });
            break;

        case '2':
            sort(grupe.begin(), grupe.end(), [](const auto &a, const auto &b)
                 { return a.pav < b.pav; });
            break;

        case '3':
            sort(grupe.begin(), grupe.end(), [](const auto &a, const auto &b)
                 { return a.galutinisVid > b.galutinisVid; });
            break;

        case '4':
            if (choice_mediana == 'y')
            {
                sort(grupe.begin(), grupe.end(), [](const auto &a, const auto &b)
                     { return a.galutinisMed > b.galutinisMed; });
                break;
            }
            else
            {
                throw runtime_error("Netinkamas pasirinkimas. Mediana nebuvo skaiciuota");
            }

        case '5':
            break;

        default:
            throw runtime_error("Netinkamas pasirinkimas. Pasirinkite skaiciu nuo 1 iki 5");
        }
    }
    catch (runtime_error &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }

    cout << endl
         << "Ar norite duomenis isvesti i faila, ar i ekrana?: " << endl
         << "1 - I faila" << endl
         << "2 - I ekrana" << endl;

    try
    {
        cin >> choice;
        switch (choice)
        {
            // I faila
        case '1':
        {
            ofstream fr(output_file);
            if (!fr)
                throw runtime_error("Nepavyko atidaryti isvedimo failo");

            rez_isvedimas(fr, choice_mediana, grupe);
            fr.close();
            break;
        }

        // I ekrana
        case '2':
        {
            rez_isvedimas(cout, choice_mediana, grupe);
            break;
        }
        default:
            throw runtime_error("Netinkamas pasirinkimas. Pasirinkite 1 arba 2");
        }
    }
    catch (runtime_error &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }

    return 0;
}