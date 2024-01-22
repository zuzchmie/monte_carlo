#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "monte_carlo.h"
#include "func.h"


void createTabXandTabYMonte(double** xs,double** ys, int a, int b, int n, int tab[], int stopien) {
    
    srand(time(NULL)); 
    double szerokosc_przedzialu =(double) b - a;
   
 
    *xs = (double*) malloc(n*sizeof(double));
    *ys = (double*) malloc(n*sizeof(double));

    if (*xs == NULL || *ys == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);}
 
    for (int i = 0; i < n; i++) {
        double xi = a + ((double)rand() / RAND_MAX) * szerokosc_przedzialu; // Losowa wartość z zakresu [a, b]
        (*xs)[i] = xi;
        (*ys)[i] = f(xi, tab, stopien);
    }
    
}


double monteCarlo(int a,int b, double ys[], int n){
    double suma = 0.0;
    double szerokosc_przedzialu = (double) b - a;

     for (int i = 0; i < n; i++) {
       
        suma += ys[i];
    
    }
  

    // Obliczenie przybliżonej wartości całki
   double calka = (suma * szerokosc_przedzialu) / n; // Obliczenie przybliżonej wartości całki
    return calka;
}