#pragma once
#include "main_lib.h"

void rez_isvedimas(ostream &out, char choice_mediana, const vector<stud_struct> &grupe);
void failo_generavimas(string gen_file, int paz_sk, int dydis);
void stud_isskirstymas_3(const vector<stud_struct> &grupe);
void stud_isskirstymas_2(const vector<stud_struct> &grupe);
void stud_isskirstymas_1(const vector<stud_struct> &grupe);