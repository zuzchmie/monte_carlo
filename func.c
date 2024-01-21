#include <stdio.h>
#include <stdlib.h>
#include "func.h"

double f(double x, int tab[], int stopien) {
    double wynik = tab[0]; // Współczynnik przy najwyższej potędze

    for (int i = 1; i <= stopien; i++)
        wynik = wynik * x + tab[i]; // Schemat Hornera

    return wynik;
}
