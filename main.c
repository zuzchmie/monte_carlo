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
#include "calculation_error.h"


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
    
    double integrationMonte = monteCarlo(a, b, TabY, n);
    double integrationSimpson = simpson(a, b, n, arrayCoefficients, degree);
    double errorMonte = error(TabY, n, integrationMonte);
    
    writePolynomialToFile(degree, arrayCoefficients, a, b, n, integrationMonte, integrationSimpson, errorMonte);
    
    writeDataToFileMonte(TabX, TabY, n);
    drawPlotMonte();
   
    writeDataToFileSimpson(tabX, tabY, n);
    drawPlotSimpson();
    
    printf("Bląd obliczeniowy wynosi:%f\n\n", error(TabY, n, integrationMonte));
    
    free(TabX);
    free(TabY); 
    free(tabX);
    free(tabY);

    return 0;
}