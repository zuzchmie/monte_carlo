#include <stdio.h>
#include <stdlib.h>
#include "simpson.h"
#include "func.h"



void createTabXandTabYSimpson(double** xs,double** ys,int a, int b, int n, int tab[],int stopien){
    double przedzial = (double)(b - a)/n;
    (*xs) = (double*) malloc(n*sizeof(double*));
    (*ys) = (double*) malloc(n*sizeof(double*));

    if (*xs == NULL || *ys == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);}
    
    for(int i=0; i<=n; i++){
        double k = a + przedzial * i;
        (*xs)[i] = k;
        (*ys)[i] = f(k, tab, stopien);
    }
}

double simpson(int a,int b, int n,int tab[],int stopien){
    double przedzial = (double) (b - a) / n;
    double suma = 0.0;
     
   for (int i = 0; i <= n; i++) {
     double k = a + przedzial * i;
        if (i == 0 || i == n) suma += f(k, tab, stopien);
        else if (i % 2 == 0)  suma += 2 * f(k, tab, stopien);
        else                  suma += 4 * f(k, tab, stopien);
    }

    double calka = (przedzial / 3) * suma;
    return calka;
}
