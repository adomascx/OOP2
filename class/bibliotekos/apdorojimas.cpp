#include "apdorojimas.h"

double vidurkis(const stud_struct &student)
{
    double vid = 0;
    for (auto score : student.paz)
    {
        vid += score;
    }
    return vid / student.paz.size();
}

int mediana(const stud_struct &student)
{
    vector<int> temp = student.paz;

    int j = temp.size() / 2;

    if (temp.size() % 2 == 0)
    {
        nth_element(temp.begin(), temp.begin() + j, temp.end());
        int mid1 = temp[j];

        nth_element(temp.begin(), temp.begin() + j - 1, temp.end());
        int mid2 = temp[j - 1];

        return (mid1 + mid2) / 2;
    }
    else
    {
        nth_element(temp.begin(), temp.begin() + j, temp.end());
        return temp[j];
    }
}

double vidurkis_gal(const stud_struct &student)
{
    return (0.4 * vidurkis(student)) + (0.6 * student.egz);
}

double mediana_gal(const stud_struct &student)
{
    return (0.4 * mediana(student)) + (0.6 * student.egz);
}