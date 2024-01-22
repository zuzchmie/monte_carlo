// MONTE CARLO PROJECT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "plot.h"
#include "input.h"
#include "monte_carlo.h"
#include "simpson.h"
#include "func.h"
#include "data.h"



int main()
{
    printf("\nMonte Carlo and Simpson Integration, based on Riemann Sum and Thomas Simpson\n\n");
    printf("Ten program wylicza wartosc calek numerycznych wielomianow za pomoca metody Monte Carlo oraz metody Simpsona.\nProsze wpisac nastepujace dane.\n\n");
   

    double* TabX;
    double* TabY;
    double* tabX;
    double* tabY;

    int degree = degreeOfPolynomial();
    int *arrayCoefficients = arrayWithCoefficients(degree);

    int a = lowerLimit();
    int b = upperLimit();
    int n = numOfSamples();
   

    createTabXandTabYMonte(&TabX, &TabY, a, b, n, arrayCoefficients, degree);
    createTabXandTabYSimpson(&tabX, &tabY, a, b, n, arrayCoefficients, degree);

   
    printf("Przyblizona wartosc calki numerycznej metoda Monte Carlo z wielomianu to: %f\n\n",monteCarlo(a, b, TabY, n));
    printf("Przyblizona wartosc calki numerycznej metoda Simpsona z wielomianu to: %f\n\n",simpson(a, b, n, arrayCoefficients, degree));
    
    double calka_monte = monteCarlo(a, b, TabY, n);
    double calka_simpson = simpson(a, b, n, arrayCoefficients, degree);
    
    writePolynomialToFile(degree, arrayCoefficients, a, b, n, calka_monte, calka_simpson);
    
    writeDataToFileMonte(TabX, TabY, n);
    drawPlotMonte();
    writeDataToFileSimpson(tabX, tabY, n);
    drawPlotSimpson();
    
    free(TabX);
    free(TabY); 
    free(tabX);
    free(tabY);

    return 0;
}