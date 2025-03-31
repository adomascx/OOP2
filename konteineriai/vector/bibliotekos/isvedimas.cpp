#include "isvedimas.h"

void rez_isvedimas(ostream &out, char choice_mediana, const vector<stud_struct> &grupe)
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
        out << setw(15) << left << i.var
            << setw(15) << i.pav
            << fixed << setprecision(3) << setw(20)
            << i.galutinisVid << " ";
        if (choice_mediana == 'y')
            out << i.galutinisMed << " ";
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

void stud_isskirstymas_3(const vector<stud_struct> &grupe)
{
    vector<stud_struct> temp = grupe;

    timer_prad();
    sort(temp.begin(), temp.end(), [](const auto &a, const auto &b)
         { return a.galutinisVid > b.galutinisVid; });
    timer_pab("Studentu rusiavimas");

    timer_prad();
    // originalaus masyvo indeksas, per kuri perskiriama
    auto i = find_if(temp.begin(), temp.end(), [](const auto &grupe)
                     { return grupe.galutinisVid < 5; });

    // perkeliami duomenys is 'temp' i 'kartotojai'
    vector<stud_struct> kartotojai(make_move_iterator(i), make_move_iterator(temp.end()));
    temp.erase(i, temp.end());
    timer_pab("Isdeliojimas i 2 vektorius");

    // 'kartotoju' isvedimas i faila
    timer_prad();
    ofstream fr_k("teksto_failai/kartotojai.txt");
    if (!fr_k)
        throw runtime_error("Nepavyko atidaryti kartotoju failo");

    rez_isvedimas(fr_k, 'n', kartotojai);
    fr_k.close();

    // 'islaikytoju' isvedimas i faila
    ofstream fr_i("teksto_failai/islaikytojai.txt");
    if (!fr_i)
        throw runtime_error("Nepavyko atidaryti islaikytoju failo");

    rez_isvedimas(fr_i, 'n', temp);
    fr_i.close();
    timer_pab("Isvedimas i faila");
}

void stud_isskirstymas_2(const vector<stud_struct> &grupe)
{
    vector<stud_struct> temp = grupe;

    // visas masyvas rusiuojamas is karto, taip sumazinant velesniu palyginimu sk.
    timer_prad();

    sort(temp.begin(), temp.end(), [](const auto &a, const auto &b)
         { return a.galutinisVid > b.galutinisVid; });

    timer_pab("Studentu rusiavimas");

    timer_prad();

    // originalaus masyvo indeksas, per kuri perskiriama
    auto i = find_if(temp.begin(), temp.end(), [](const auto &grupe)
                     { return grupe.galutinisVid < 5; });

    vector<stud_struct> kartotojai;

    // perkeliami duomenys is 'temp' i 'kartotojai'
    kartotojai.insert(kartotojai.end(),
                      make_move_iterator(i),
                      make_move_iterator(temp.end()));
    
    timer_pab("Isdeliojimas i 2 vektorius");

    // timer_prad();

    // 'kartotoju' isvedimas i faila
    ofstream fr_k("teksto_failai/kartotojai.txt");
    if (!fr_k)
        throw runtime_error("Nepavyko atidaryti kartotoju failo");

    rez_isvedimas(fr_k, false, kartotojai);
    fr_k.close();

    // 'islaikytoju' isvedimas i faila
    ofstream fr_i("teksto_failai/islaikytojai.txt");
    if (!fr_i)
        throw runtime_error("Nepavyko atidaryti islaikytoju failo");

    rez_isvedimas(fr_i, false, temp);
    fr_i.close();

    // timer_pab("Isvedimas i faila");
}

void stud_isskirstymas_1(const vector<stud_struct> &grupe)
{
    vector<stud_struct> temp = grupe;
    vector<stud_struct> islaikytojai;
    vector<stud_struct> kartotojai;

    // visas masyvas rusiuojamas is karto, taip sumazinant velesniu palyginimu sk.
    timer_prad();

    sort(temp.begin(), temp.end(), [](const auto &a, const auto &b)
         { return a.galutinisVid > b.galutinisVid; });

    timer_pab("Studentu rusiavimas");

    timer_prad();

    // nauja (blogesne) implementacija
    for (auto i : temp)
    {
        if (i.galutinisVid < 5)
            kartotojai.push_back(i);
        else
            islaikytojai.push_back(i);
    }

    timer_pab("Isdeliojimas i 2 vektorius");

    // timer_prad();

    // 'kartotoju' isvedimas i faila
    ofstream fr_k("teksto_failai/kartotojai.txt");
    if (!fr_k)
        throw runtime_error("Nepavyko atidaryti kartotoju failo");

    rez_isvedimas(fr_k, false, kartotojai);
    fr_k.close();

    // 'islaikytoju' isvedimas i faila
    ofstream fr_i("teksto_failai/islaikytojai.txt");
    if (!fr_i)
        throw runtime_error("Nepavyko atidaryti islaikytoju failo");

    rez_isvedimas(fr_i, false, islaikytojai);
    fr_i.close();

    // timer_pab("Isvedimas i faila");
}