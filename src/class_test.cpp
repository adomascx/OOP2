#define CATCH_CONFIG_MAIN
#include "lib/catch_amalgamated.hpp"
#include "lib/studentas.h"
#include "lib/isvedimas.h"

TEST_CASE("Test konstruktoriu", "[studentas]") {
    // Testuojame numatytąjį konstruktorių
    studentas stud_default;
    // Tikimės, kad vardas ir pavardė yra tušti, o skaičiavimai nenustatyti (galutinės reikšmės 0 arba normalios)
    REQUIRE(stud_default.vardas() == "");
    REQUIRE(stud_default.pavarde() == "");

    // Testuojame parametrizuotą konstruktorių
    vector<int> pazymiai = {8, 9, 10};
    studentas stud_param("Jonas", "Jonaitis", pazymiai, 8);
    REQUIRE(stud_param.vardas() == "Jonas");
    REQUIRE(stud_param.pavarde() == "Jonaitis");
    // Tikriname, ar skaičiavimo metodai grąžina reikiamą intervalą
    REQUIRE(stud_param.galutinis_vidurkis() >= 1);
    REQUIRE(stud_param.galutinis_vidurkis() <= 10);
}

TEST_CASE("Test copy konstruktoriaus", "[studentas]") {
    // Sukuriame originalų objektą
    vector<int> pazymiai = {7, 8, 9};
    studentas originalas("Petras", "Petraitis", pazymiai, 7);
    // Naudojame copy konstruktorių
    studentas kopija(originalas);
    // Patikriname, ar kopija turi tas pačias reikšmes kaip ir originalas
    REQUIRE(kopija.vardas() == originalas.vardas());
    REQUIRE(kopija.pavarde() == originalas.pavarde());
    REQUIRE(kopija.galutinis_vidurkis() == originalas.galutinis_vidurkis());
    REQUIRE(kopija.galutinis_mediana() == originalas.galutinis_mediana());
}

TEST_CASE("Test copy priskyrimo operatoriaus", "[studentas]") {
    vector<int> pazymiai = {6, 7, 8};
    studentas originalas("Ona", "Onaitė", pazymiai, 6);
    studentas kopija;
    kopija = originalas;
    // Patikriname, ar priskyrimas perkopijavo reikšmes
    REQUIRE(kopija.vardas() == originalas.vardas());
    REQUIRE(kopija.pavarde() == originalas.pavarde());
    REQUIRE(kopija.galutinis_vidurkis() == originalas.galutinis_vidurkis());
    REQUIRE(kopija.galutinis_mediana() == originalas.galutinis_mediana());
}

TEST_CASE("Test move konstruktoriaus", "[studentas]") {
    vector<int> pazymiai = {5, 5, 5};
    studentas originalas("Ieva", "Ievaitė", pazymiai, 5);
    double vidurkis_original = originalas.galutinis_vidurkis();
    double mediana_original = originalas.galutinis_mediana();

    // Naudojame move konstruktorių; originalas perdedamas į naują objektą
    studentas perkelta(move(originalas));
    REQUIRE(perkelta.vardas() == "Ieva");
    REQUIRE(perkelta.pavarde() == "Ievaitė");
    REQUIRE(perkelta.galutinis_vidurkis() == vidurkis_original);
    REQUIRE(perkelta.galutinis_mediana() == mediana_original);
    // Originalo turinys po move gali būti tuščias ar nulinis pagal implementaciją
    REQUIRE(originalas.vardas() == "");
    REQUIRE(originalas.pavarde() == "");
    REQUIRE(originalas.galutinis_vidurkis() == 0);
    REQUIRE(originalas.galutinis_mediana() == 0);
}

TEST_CASE("Test move priskyrimo operatoriaus", "[studentas]") {
    vector<int> pazymiai = {4, 4, 4};
    studentas originalas("Andrius", "Andraitis", pazymiai, 4);
    double vidurkis_original = originalas.galutinis_vidurkis();
    double mediana_original = originalas.galutinis_mediana();
    studentas perkelta;
    perkelta = move(originalas);
    REQUIRE(perkelta.vardas() == "Andrius");
    REQUIRE(perkelta.pavarde() == "Andraitis");
    REQUIRE(perkelta.galutinis_vidurkis() == vidurkis_original);
    REQUIRE(perkelta.galutinis_mediana() == mediana_original);

    // Patikrinkite originalaus objekto būklę po perkėlimo
    REQUIRE(originalas.vardas() == "");
    REQUIRE(originalas.pavarde() == "");
    REQUIRE(originalas.galutinis_vidurkis() == 0);
    REQUIRE(originalas.galutinis_mediana() == 0);
    REQUIRE(perkelta.vardas() == "Andrius");
    REQUIRE(perkelta.pavarde() == "Andraitis");
    REQUIRE(perkelta.galutinis_vidurkis() == vidurkis_original);
    REQUIRE(perkelta.galutinis_mediana() == mediana_original);
}

TEST_CASE("Test destruktoriaus", "[studentas]") {
    // Testuojama, kad destruktorius veikia be klaidų sunaikinant objektus
    {
        studentas stud("Simonas", "Simonaitis", vector<int>{10, 9, 8}, 10);
        REQUIRE(stud.vardas() == "Simonas");
        // Objektas bus automatiškai sunaikintas pasibaigus blokui, destruktorius turi tvarkingai išvalyti objektą
    }
    // Jei destruktorius sukelia problemų, testas bus nesėkmingas
}