#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int f(int x, int tab[], int stopien) {
    int wynik = tab[0]; // Początkowa wartość wyniku to współczynnik przy x^3 (najwyższa potęga)

    for (int i = 1; i <= stopien; i++)
        wynik = wynik * x + tab[i]; // Schemat Hornera

    return wynik;
}