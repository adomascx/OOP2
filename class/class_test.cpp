#include "lib/studentas.h"
#include "lib/isvedimas.h"

int main(int argc, char *argv[])
{
     // 1. Default konstruktoriaus testavimas
     studentas studDefault;
     cout << "Numatytojo konstruktoriaus testas sekmingas:" << studDefault;

     // 2. Parametrinio konstruktoriaus testavimas
     vector<int> sampleGrades{2, 9, 10};
     studentas studParam("Jone", "Jonaityte", sampleGrades, 10);
     cout << "Parametrinio konstruktoriaus testas sekmingas: " << studParam;

     // 3. Kopijavimo (copy) konstruktoriaus testavimas
     studentas studCopyConstructed(studParam);
     cout << "Kopijavimo konstruktoriaus testas sekmingas: " << studCopyConstructed;

     // 4. Perkelimo (move) konstruktoriaus testavimas
     studentas studMoveConstructed(move(studParam));
     cout << "Perkelimo konstruktoriaus testas sekmingas: " << studMoveConstructed
          << "Like duomenys: " << studParam;

     // 5. Kopijavimo priskyrimo (operator=) testavimas
     studentas studCopyAssigned;
     studCopyAssigned = studCopyConstructed;
     cout << "Kopijavimo priskyrimo testas sekmingas: " << studCopyAssigned;

     // 6. Perkelimo priskyrimo (move operator=) testavimas
     studentas studMoveAssigned;
     studMoveAssigned = move(studMoveConstructed);
     cout << "Perkelimo priskyrimo testas sekmingas: " << studMoveAssigned
          << "Like duomenys: " << studMoveConstructed;

     // 7. Ivedimo metodu testavimas (naudojant stringstream)

     std::stringstream inputMock("Jonas Jonaitis 2 9 10 7");
     studentas studInput;
     studInput.paz_ivedimas(inputMock, 3);
     cout << "Ivedimo metodu testas sekmingas: " << studInput.vardas() << " " << studInput.pavarde() << endl;

     // 8. Isvedimo metodu testavimas (galutinis pazymys)
     studCopyAssigned.calc_gal_mediana();
     studCopyAssigned.calc_gal_vidurkis();

     cout << "Galutinis vidurkis: " << studCopyAssigned.galutinis_vidurkis() << endl;
     cout << "Galutine mediana: " << studCopyAssigned.galutinis_mediana() << endl;
     cout << "Isvedimo metodu testas sekmingas" << endl;

     // 9. Operator>> overload test

     stringstream inputOp("Petras Petraitis 7");
     studentas studOp;
     inputOp >> studOp;
     cout << "Operator>> testas sekmingas: " << studOp.vardas() << " " << studOp.pavarde() << endl;

     // 10. Operator<< overload test

     vector<int> sampleGradesTest{5, 7, 9};
     studentas studOut("Antanas", "Antanaitis", sampleGradesTest, 8);
     studOut.calc_gal_vidurkis();
     studOut.calc_gal_mediana();
     stringstream outputMock;
     outputMock << studOut;
     cout << "Operator<< testas sekmingas. Isvedimo rezultatas:" << outputMock.str();

     // 11. Destruktoriaus testas
     cout << "Destruktoriaus testas (bus iskviestas automatiskai pabaigoje)" << endl;
}