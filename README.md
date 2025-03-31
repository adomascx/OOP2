# OOP2

Šis projektas yra C++ programa, skirta studentų pažymių įvedimui ir galutinio rezultato skaičiavimui. Nuo paskutinio README atnaujinimo įdiegta papildoma funkcionalumo refinavimo versija – interaktyvus meniu, papildomi duomenų apdorojimo testai bei patobulintas laiko matavimas.

## Ankstesnės versijos
- **v0.1:** Sukurtas įvedimo meniu, duomenų įvedimas ranka, vektorių bei C masyvų implementacija.
- **v0.2:** Įdiegta duomenų įvedimo/išvedimo su failais funkcija, pagerintas medianos skaičiavimo algoritmas.
- **v0.2.1:** Ištaisyta kritinė įvedimo klaida, pašalintas nereikalingas kintamasis.
- **v0.3:** Atliktas pilnas refactoringas, įdiegtas išimčių valdymas, kodas suskaidytas į atskirus .cpp ir .h failus.
- **v0.4:** Pridėtas failų generavimo funkcionalumas, studentų rūšiavimas pagal galutinį balą, įdiegta laiko matavimo sistema.
- **v1.0:** Papildyta programa, lyginant trijų konteinerių (vector, deque, list) realizacijos spartą

## Įdiegimo instrukcijos
Naudokite įtrauktą Makefile. Terminale vykdykite:
 - `make build` – sukompiliuoja programas (4 realizacijomis)
 - `make test` – sukompiliuoja laiko matavimo programas (4 realizacijomis)
 - `make all` – sukompiliuoja visas esamas programos versijas
 - `make clean` – ištrina sugeneruotus vykdomuosius failus.

## Programos spartos analizė

#### Testai matuoja:
- Duomenų nuskaitymą iš failo,
- Konteinerio rūšiavimą (naudojant std::sort),
- Studentų grupavimą į dvi kategorijas.

#### Sistemos Parametrai:
- CPU: AMD Ryzen 5 5600X (6 Cores @ 4.6GHz)
- Memory: Corsair Vengeance 16GB (DDR4 3200MHz CL16)
- Storage: Western Digital SN550 (1TB M.2 NVMe)

### 1 Strategija
(Sugrupuojama bendro studentų konteinerio kopija į dvi naujas, kur tas pats studentas saugomas abiejuose konteineriuose.)

#### Vector:
| Testai                               | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų |
| ------------------------------------ | ----------- | ------------ | ------------- | -------------- |
| Duomenu nuskaitymas                  | 0.01        | 0.12         | 1.34          | 14.3           |
| Studentų rūšiavimas                  | <0.01       | 0.02         | 0.18          | 2.17           |
| Studentų išskirstymas                | <0.01       | 0.02         | 0.16          | 2.4            |
| **Bendras programos veikimo laikas** | 0.01        | 0.16         | 1.68          | 18.87          |

#### List:
| Testai                               | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų |
| ------------------------------------ | ----------- | ------------ | ------------- | -------------- |
| Duomenu nuskaitymas                  | 0.02        | 0.13         | 1.35          | 13.12          |
| Studentų rūšiavimas                  | <0.01       | 0.03         | 0.49          | 8.09           |
| Studentų išskirstymas                | <0.01       | 0.04         | 0.36          | 4.81           |
| **Bendras programos veikimo laikas** | 0.02        | 0.2          | 2.2           | 26.02          |

#### Deque:
| Testai                               | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų |
| ------------------------------------ | ----------- | ------------ | ------------- | -------------- |
| Duomenu nuskaitymas                  | 0.01        | 0.13         | 1.32          | 13.43          |
| Studentų rūšiavimas                  | <0.01       | 0.02         | 0.25          | 3.56           |
| Studentų išskirstymas                | <0.01       | 0.03         | 0.25          | 2.64           |
| **Bendras programos veikimo laikas** | 0.01        | 0.18         | 1.82          | 19.63          |

#### Pastebėjimai:
 - Dėl duomenų dubliavimo dviejuose naujuose konteineriuose, programa naudoja labai daug atminties (pradeda naudoti swap'us)
 - Implementacija su 'list' veikia greičiausiai, po jos eina 'vector' bei 'deque' implementacijos.
 - Ilgiausiai užtruka išrūšiuoti studentus; List implementacija rūšiuoja efektyviausiai, todėl ir užtrunka mažiausiai laiko

### 2 Strategija
(Sukuriamas tik vienas naujas konteineris "kartotojams": studentai perkelti į naują konteinerį ir ištrinti iš pagrindinio, todėl likę tik "išlaikytojai")

#### Vector:
| Testai                               | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų |
| ------------------------------------ | ----------- | ------------ | ------------- | -------------- |
| Duomenu nuskaitymas                  | 0.01        | 0.12         | 1.3           | 12.81          |
| Studentų rūšiavimas                  | <0.01       | 0.01         | 0.16          | 2.3            |
| Studentų išskirstymas                | <0.01       | <0.01        | 0.01          | 0.12           |
| **Bendras programos veikimo laikas** | 0.01        | 0.13         | 1.47          | 15.23          |

#### List:
| Testai                               | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų |
| ------------------------------------ | ----------- | ------------ | ------------- | -------------- |
| Duomenu nuskaitymas                  | 0.01        | 0.15         | 1.34          | 13.35          |
| Studentų rūšiavimas                  | <0.01       | 0.02         | 0.49          | 7.9            |
| Studentų išskirstymas                | <0.01       | <0.01        | 0.11          | 1.08           |
| **Bendras programos veikimo laikas** | 0.01        | 0.17         | 1.94          | 22.33          |

#### Deque:
| Testai                               | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų |
| ------------------------------------ | ----------- | ------------ | ------------- | -------------- |
| Duomenu nuskaitymas                  | 0.01        | 0.15         | 1.51          | 12.28          |
| Studentų rūšiavimas                  | <0.01       | 0.02         | 0.27          | 3.19           |
| Studentų išskirstymas                | <0.01       | <0.01        | 0.04          | 0.3            |
| **Bendras programos veikimo laikas** | 0.01        | 0.17         | 1.82          | 15.77          |

#### Pastebėjimai:
 - Atsikračius nereikalingo konteinerių laikymo atmintyje, atminties sąnaudos ženkliai krenta. *(16+ GB --> 10 GB)* 
 - Dėl optimizuoto studentų išskirstymo, programa bendrai veikia daug greičiau
 - Studentų išskirstymo sudėtingumas mažeja nuo *O(NlogN)* iki *O(N)*


### 3 Strategija
(Pagerinama 2-oji strategija, naudojant efektyvias STL funkcijas, taip pat naudojamos kompiliavimo optimizavimo vėliavėlės (flags))

#### Vector:

| Testai                               | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų |
| ------------------------------------ | ----------- | ------------ | ------------- | -------------- |
| Duomenu nuskaitymas                  | 0.01        | 0.11         | 1.32          | 12.98          |
| Studentų rūšiavimas                  | <0.01       | 0.01         | 0.16          | 1.93           |
| Studentų išskirstymas                | <0.01       | <0.01        | 0.02          | 0.15           |
| **Bendras programos veikimo laikas** | 0.01        | 0.12         | 1.5           | 15.06          |

#### List:
| Testai                               | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų |
| ------------------------------------ | ----------- | ------------ | ------------- | -------------- |
| Duomenu nuskaitymas                  | 0.01        | 0.12         | 1.29          | 13.33          |
| Studentų rūšiavimas                  | <0.01       | 0.02         | 0.46          | 7.76           |
| Studentų išskirstymas                | <0.01       | <0.01        | 0.1           | 1.07           |
| **Bendras programos veikimo laikas** | 0.01        | 0.14         | 1.85          | 22.16          |

#### Deque:
| Testai                               | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų |
| ------------------------------------ | ----------- | ------------ | ------------- | -------------- |
| Duomenu nuskaitymas                  | 0.01        | 0.16         | 1.26          | 13.33          |
| Studentų rūšiavimas                  | <0.01       | 0.02         | 0.3           | 3.23           |
| Studentų išskirstymas                | <0.01       | <0.01        | 0.04          | 0.4            |
| **Bendras programos veikimo laikas** | 0.01        | 0.18         | 1.6           | 16.96          |

#### Pastebėjimai:
 - Be to, pakeitimai programai naudojant daugiau STL funkcijų rodo *~10%* greitesnį veikimą
 - Su optimizacijomis, 'vector' implementacija tampa sparčiausia, o 'list' lėčiausia
 - Dauguma programos veikimo etapų veikia su *O(N)* sudėtingumu, išskyrus rūšiavimo operacijas

### Struct vs Class

#### Class:
| Testai                               | 100000 įrašų | 1000000 įrašų |
| ------------------------------------ | ------------ | ------------- |
| Duomenu nuskaitymas                  | 0.15         | 1.49          |
| Studentų rūšiavimas                  | 0.04         | 0.63          |
| Sudentų išskirstymas                 | <0.01        | 0.05          |
| Išvedimas į failą                    | 0.37         | 3.64          |
| **Bendras programos veikimo laikas** | 0.56         | 5.81          |

#### Struct (vector):
| Testai                               | 100000 įrašų | 1000000 įrašų |
| ------------------------------------ | ------------ | ------------- |
| Duomenu nuskaitymas                  | 0.11         | 1.09          |
| Studentų rūšiavimas                  | 0.01         | 0.14          |
| Sudentų išskirstymas                 | <0.01        | 0.01          |
| Išvedimas į failą                    | 0.38         | 3.73          |
| **Bendras programos veikimo laikas** | 0.5          | 4.97          |

#### Pastebėjimai:
 - Struktūrų (struct) implementacija bendrai veikia greičiau, nei klasių (class) atitikmuo, ypač duomenų nuskaitymo ir rūšiavimo operacijose.
 - Tačiau, klasių realizacijoje failo išvedimo procesas vykdomas šiek tiek greičiau.

### Vėliavėlės (flags):

#### Class:
| Testai                               | Be flag | -O1      | -O2      | -O3      | -Os    |
| ------------------------------------ | ------- | -------- | -------- | -------- | ------ |
| Duomenu nuskaitymas                  | 2.16    | 1.45     | 1.47     | 1.42     | 1.49   |
| Studentų rūšiavimas                  | 2.68    | 0.72     | 0.68     | 0.65     | 0.74   |
| Sudentų išskirstymas                 | 0.08    | 0.05     | 0.05     | 0.05     | 0.06   |
| Išvedimas į failą                    | 3.86    | 3.85     | 3.79     | 3.69     | 3.76   |
| **Bendras programos veikimo laikas** | 8.78    | 6.07     | 5.99     | 5.81     | 6.05   |
| '.exe' failo dydis                   | 858 KB  | 1,210 KB | 1,265 KB | 1,824 KB | 805 KB |

#### Struct (vector):
| Testai                               | Be flag | -O1      | -O2      | -O3      | -Os    |
| ------------------------------------ | ------- | -------- | -------- | -------- | ------ |
| Duomenu nuskaitymas                  | 1.32    | 1.11     | 1.1      | 1.1      | 1.13   |
| Studentų rūšiavimas                  | 1.45    | 0.17     | 0.18     | 0.15     | 0.26   |
| Sudentų išskirstymas                 | 0.03    | 0.01     | 0.01     | 0.01     | 0.01   |
| Išvedimas į failą                    | 3.83    | 3.86     | 3.78     | 3.78     | 3.77   |
| **Bendras programos veikimo laikas** | 6.63    | 5.15     | 5.07     | 5.04     | 5.17   |
| '.exe' failo dydis                   | 986 KB  | 1,570 KB | 1,505 KB | 1,925 KB | 919 KB |

#### Pastebėjimai:
 - Naudojant -O1, pastebimas reikšmingas programos veikimo laiko sumažėjimas, nors failo dydis taip pat ženkliai padidėja
 - -O2 optimizacijos naudojimas rodo mažus tiek spartos, tiek failo dydžio skirtumus
 - -O3 failo dydis žymiai išauga, tačiau veikimo greitis išlieka beveik nepakitęs
 - -Os efektyviausia iš visų nurodytų: sumažintas failo dydis (net geresnis už versiją be optimizacijos) ir panaši sparta kaip su -O1