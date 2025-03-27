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
Programą galite įdiegti ir paleisti dviem būdais:
- **Per VSCode užduočių paleidimą:**  
  Naudokite pateiktą `.vscode/tasks.json` konfiguraciją. Atidarykite komandų paletę (`Ctrl+Shift+P`) ir paleiskite "Tasks: Run Build Task".
- **Per Makefile:**  
  Naudokite įtrauktą Makefile. Terminale vykdykite:   
  • `make build_v` – sukompiliuoja programą su vector realizacija (OOP1_V.exe)  
  • `make build_l` – sukompiliuoja programą su list realizacija (OOP1_L.exe)  
  • `make build_d` – sukompiliuoja programą su deque realizacija (OOP1_D.exe)  
  • `make test_v` – sukompiliuoja laiko matavimo programą su vector realizacija (testavimas_V.exe)  
  • `make test_l` – sukompiliuoja laiko matavimo programą su list realizacija (testavimas_L.exe)  
  • `make test_d` – sukompiliuoja laiko matavimo programą su deque realizacija (testavimas_D.exe)  
  • `make clean` – ištrina sugeneruotus vykdomuosius failus.

### VSCode projektinio failo `tasks.json` konfigūracija

```jsonc
// filepath: .vscode/tasks.json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: Surinkti visus šaltinio failus",
            "command": "C:\\path\\to\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${workspaceFolder}\\OOP1.cpp",
                "${workspaceFolder}\\bibliotekos\\apdorojimas.cpp",
                "${workspaceFolder}\\bibliotekos\\ivedimas.cpp",
                "${workspaceFolder}\\bibliotekos\\isvedimas.cpp",
                "${workspaceFolder}\\bibliotekos\\main_lib.cpp",
                "-o",
                "${workspaceFolder}\\build\\OOP1.exe"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}
```

## Programos spartos analizė

### Testai matuoja:
- Duomenų nuskaitymą iš failo,
- Konteinerio rūšiavimą (naudojant std::sort),
- Studentų grupavimą į dvi kategorijas.

### Sistemų Parametrai
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

## Programos veikimo pavyzdžiai

Programos eiga apima duomenų įvedimą, rezultato apskaičiavimą bei spartos analizės etapų išvedimą:

- **Pagrindinis meniu:**  
  ![image](https://github.com/user-attachments/assets/59b5b9f6-e997-47e4-8fdf-32f85498f852)

- **Sugeneruotas studentų failas:**  
  ![image](https://github.com/user-attachments/assets/62391314-923f-4ff8-94c8-9cb42682917f)

- **Programos spartos analizė:**

  ![image](https://github.com/user-attachments/assets/f359d320-045c-41b3-83af-74726a414b2d)
