#include "studentas.h"
#include "isvedimas.h"

// ----- Klases metodai -----

// destruktorius
studentas::~studentas()
{
    paz.clear();
    var = "";
    pav = "";
    egz = 0;
    galutinisVid = 0;
    galutinisMed = 0;
}

// konstruktoriai
studentas::studentas(const string &vardas, const string &pavarde, const vector<int> &paz, const int &egzaminas) : var(vardas), pav(pavarde), paz(paz), egz(egzaminas)
{
    calc_gal_vidurkis();
    calc_gal_mediana();
}

// konstruktorius naudojant stream
studentas::studentas(istream &is, int nd_count)
{
    paz_ivedimas(is, nd_count);
    calc_gal_vidurkis();
    calc_gal_mediana();
};

// copy konstruktorius
studentas::studentas(const studentas &other)
    : var(other.var),
      pav(other.pav),
      paz(other.paz),
      egz(other.egz),
      galutinisVid(other.galutinisVid),
      galutinisMed(other.galutinisMed) {}

// move konstruktorius
studentas::studentas(studentas &&other) noexcept
    : var(move(other.var)),
      pav(move(other.pav)),
      paz(move(other.paz)),
      egz(other.egz),
      galutinisVid(other.galutinisVid),
      galutinisMed(other.galutinisMed) { other.~studentas(); }

// copy operatorius
studentas &studentas::operator=(const studentas &other)
{
    if (this == &other)
        return *this;

    var = other.var;
    pav = other.pav;
    paz = other.paz;
    egz = other.egz;
    galutinisVid = other.galutinisVid;
    galutinisMed = other.galutinisMed;

    return *this;
}

// move operatorius
studentas &studentas::operator=(studentas &&other) noexcept
{
    if (this == &other)
        return *this;

    var = move(other.var);
    pav = move(other.pav);
    paz = move(other.paz);
    egz = move(other.egz);
    galutinisVid = move(other.galutinisVid);
    galutinisMed = move(other.galutinisMed);
    other.~studentas();
    return *this;
}

// setteriai

// pazymiu ivedimas
istream &studentas::paz_ivedimas(istream &is, int nd_count)
{
    int pazymys;
    for (int i = 0; i < nd_count; i++)
    {
        is >> pazymys;
        paz.push_back(pazymys);
    }
    return is;
};

// vardu, pavardziu ir egz rezultatu ivedimas su '>>' operatorium
istream &operator>>(istream &is, studentas &s)
{
    is >> s.var >> s.pav >> s.egz;
    return is;
}

ostream &operator<<(ostream &os, const studentas &s)
{
    os << setw(15) << left << s.vardas()
       << setw(15) << s.pavarde()
       << fixed << setprecision(3) << setw(20)
       << s.galutinis_vidurkis() << " ";
    if (s.galutinis_mediana() >= 1 && s.galutinis_mediana() <= 10)
        os << s.galutinis_mediana() << " ";
    os << endl;
    return os;
}

void studentas::rank_vardo_ivedimas()
{
    cout << "Iveskite studento varda: ";
    cin >> var;
    if (!cin)
        throw runtime_error("Netinkamai ivestas vardas. Bandykite vel");

    cout << "Iveskite studento pavarde: ";
    cin >> pav;
    if (!cin)
        throw runtime_error("Netinkamai ivesta pavarde. Bandykite vel");
}

void studentas::rank_paz_ivedimas()
{
    while (true)
    {
        int pazymys{};
        cout << "Iveskite mokinio pazymi (0, jei daugiau pazymiu nera): ";
        cin >> pazymys;
        if (!cin || pazymys > 10)
            throw runtime_error("Netinkamas pazymys. Pasirinkite skaiciu nuo 1 iki 10");

        if (pazymys)
            paz.push_back(pazymys);
        else
            break;
    }

    if (paz.empty())
    {
        throw runtime_error("Nera ivestu pazymiu. Prasome ivesti bent viena pazymi.");
    }

    cout << "Iveskite egzamino rezultata: ";
    cin >> egz;
    if (!cin || egz > 10)
        throw runtime_error("Netinkamas egzamino balas. Pasirinkite skaiciu nuo 1 iki 10");
}

void studentas::gen_paz()
{
    for (int i = 0; i < 32; i++)
    {
        paz.push_back(rand() % 10);
    }
    egz = rand() % 10;
}

// galutinio balo apskaiciavimas
void studentas::calc_gal_vidurkis()
{
    double vid = 0;
    for (auto score : paz)
    {
        vid += score;
    }
    double vidurkis = vid / paz.size();

    galutinisVid = (0.4 * vidurkis) + (0.6 * egz);
}

void studentas::calc_gal_mediana()
{
    vector<int> temp = paz;

    int j = temp.size() / 2;
    double mediana = 0;

    if (temp.size() % 2 == 0)
    {
        nth_element(temp.begin(), temp.begin() + j, temp.end());
        int mid1 = temp[j];

        nth_element(temp.begin(), temp.begin() + j - 1, temp.end());
        int mid2 = temp[j - 1];

        mediana = (mid1 + mid2) / 2;
    }
    else
    {
        nth_element(temp.begin(), temp.begin() + j, temp.end());
        mediana = temp[j];
    }

    galutinisMed = (0.4 * mediana) + (0.6 * egz);
}

// ----- Ne metodai, bet darbas su klase -----
void failo_ivedimas(vector<studentas> &grupe, istream &is)
{
    string line, word;

    getline(is, line);
    istringstream antraste(line);
    int nd_count{};
    while (antraste >> word)
    {
        nd_count++;
    }
    nd_count -= 3;

    timer_prad();
    cout << endl
         << "Ivedami duomenys..." << endl;

    while (getline(is, line))
    {
        istringstream iss(line);
        studentas temp(iss, nd_count);
        grupe.push_back(temp);
    }

    timer_pab("Failo ivedimas");
}

void stud_isskirstymas_1(const vector<studentas> &grupe)
{
    vector<studentas> temp = grupe;
    vector<studentas> islaikytojai;
    vector<studentas> kartotojai;

    timer_prad();
    sort(temp.begin(), temp.end(), [](const auto &a, const auto &b)
         { return a.galutinis_vidurkis() > b.galutinis_vidurkis(); });
    timer_pab("Studentu rusiavimas");

    timer_prad();
    for (auto i : temp)
    {
        if (i.galutinis_vidurkis() < 5)
            kartotojai.push_back(i);
        else
            islaikytojai.push_back(i);
    }
    timer_pab("Isdeliojimas i 2 vektorius");

    ofstream fr_k("teksto_failai/kartotojai.txt");
    if (!fr_k)
        throw runtime_error("Nepavyko atidaryti kartotoju failo");
    rez_isvedimas(fr_k, 'n', kartotojai);
    fr_k.close();

    ofstream fr_i("teksto_failai/islaikytojai.txt");
    if (!fr_i)
        throw runtime_error("Nepavyko atidaryti islaikytoju failo");
    rez_isvedimas(fr_i, 'n', islaikytojai);
    fr_i.close();
}

void stud_isskirstymas_2(const vector<studentas> &grupe)
{
    vector<studentas> temp = grupe;

    timer_prad();
    sort(temp.begin(), temp.end(), [](const auto &a, const auto &b)
         { return a.galutinis_vidurkis() > b.galutinis_vidurkis(); });
    timer_pab("Studentu rusiavimas");

    timer_prad();
    auto i = find_if(temp.begin(), temp.end(), [](const auto &s)
                     { return s.galutinis_vidurkis() < 5; });
    vector<studentas> kartotojai;
    kartotojai.insert(kartotojai.end(),
                      make_move_iterator(i),
                      make_move_iterator(temp.end()));
    timer_pab("Isdeliojimas i 2 vektorius");

    ofstream fr_k("teksto_failai/kartotojai.txt");
    if (!fr_k)
        throw runtime_error("Nepavyko atidaryti kartotoju failo");
    rez_isvedimas(fr_k, false, kartotojai);
    fr_k.close();

    ofstream fr_i("teksto_failai/islaikytojai.txt");
    if (!fr_i)
        throw runtime_error("Nepavyko atidaryti islaikytoju failo");
    rez_isvedimas(fr_i, false, temp);
    fr_i.close();
}

void stud_isskirstymas_3(const vector<studentas> &grupe)
{
    vector<studentas> temp = grupe;

    timer_prad();
    sort(temp.begin(), temp.end(), [](const auto &a, const auto &b)
         { return a.galutinis_vidurkis() > b.galutinis_vidurkis(); });
    timer_pab("Studentu rusiavimas");

    timer_prad();
    auto i = find_if(temp.begin(), temp.end(), [](const auto &s)
                     { return s.galutinis_vidurkis() < 5; });
    vector<studentas> kartotojai(make_move_iterator(i), make_move_iterator(temp.end()));
    temp.erase(i, temp.end());
    timer_pab("Studentu isskirstymas");

    timer_prad();
    ofstream fr_k("teksto_failai/kartotojai.txt");
    if (!fr_k)
        throw runtime_error("Nepavyko atidaryti kartotoju failo");
    rez_isvedimas(fr_k, 'n', kartotojai);
    fr_k.close();

    ofstream fr_i("teksto_failai/islaikytojai.txt");
    if (!fr_i)
        throw runtime_error("Nepavyko atidaryti islaikytoju failo");
    rez_isvedimas(fr_i, 'n', temp);
    fr_i.close();
    timer_pab("Isvedimas i faila");
}