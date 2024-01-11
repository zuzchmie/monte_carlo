#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "monte_carlo.h"
#include "func.h"


void createTabXandTabY_monte(double** xs,double** ys, int a, int b, int n, int tab[], int stopien) {
    srand(time(NULL)); 
    double szerokosc_przedzialu =(double) b - a;
    (*xs) = (double*) malloc(n*sizeof(double*));
    (*ys) = (double*) malloc(n*sizeof(double*));
 
    for (int i = 0; i < n; i++) {
        double xi = a + ((double)rand() / RAND_MAX) * szerokosc_przedzialu; // Losowa wartość z zakresu [a, b]
        (*xs)[i] = xi;
        (*ys)[i] = f(xi, tab, stopien);
    }
    /*for(int i = 0; i < n; i++){
        printf("x:%f\n",xs[i]);
        }

    for(int i = 0; i < n; i++){
        printf("y:%f\n",ys[i]);
        }//drukowanie tablic z wart x i y*/
}

double monte_carlo(int a,int b, double ys[], int n){
    double suma = 0.0;
    double szerokosc_przedzialu = (double) b - a;

     for (int i = 0; i < n; i++) {
       
        suma += ys[i];
    
    }
    /*for(int i = 0; i < n; i++){
        printf("y:%f\n",ys[i]);
        }
    for (int i = 0; i < n; i++) suma += ys[i];*/

    // Obliczenie przybliżonej wartości całki
   double calka = (suma * szerokosc_przedzialu) / n; // Obliczenie przybliżonej wartości całki
    return calka;
}