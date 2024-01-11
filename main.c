// MONTE CARLO PROJECT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "plot.h"
#include "input.h"
#include "monte_carlo.h"
#include "simpson.h"
#include "func.h"



int main()
{
    printf("Monte Carlo and Simpson Integration, based on Riemann Sum and Thomas Simpson\n");
    printf("Ten program wynicza wartosc calek numerycznych wielomianow za pomoca metody Monte Carlo oraz metody Simpsona.\n Prosze wpisac nastepujace dane.\n ");

    double* TabX;
    double* TabY;
    double* tabX;
    double* tabY;

    int st = stopien_wielomianu();
    int *tablica = tablica_z_podanymi_wspolczynnikami(st);

    int a = dolna_gr();
    int b = gorna_gr();
    int n = il_prob();

    createTabXandTabY_monte(&TabX,&TabY,a,b,n,tablica,st);
    createTabXandTabY_simpson(&tabX,&tabY,a,b,n,tablica,st);


    printf("Przyblizona wartosc calki numerycznej metoda monte carlo z wielomianu to:%f\n",monte_carlo(a,b, TabY, n));
    printf("Przyblizona wartosc calki numerycznej metoda Simpsona z wielomianu to:%f\n",simpsons(a,b, tabY, n,tablica,st));
   
    writeDataToFile_monte(TabX,TabY,n);
    drawPlot_monte();
    writeDataToFile_simpson(tabX,tabY,n);
    drawPlot_simpson();
    
    free(TabX);
    free(TabY); 
    free(tabX);
    free(tabY);

    return 0;
}