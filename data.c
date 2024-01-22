#include <stdio.h>
#include <stdlib.h>
#include "data.h"

void writePolynomialToFile(int st, int tab[],int a, int b, int n, double cal1, double cal2){
    FILE *dataFile = fopen("data.txt", "a");
    if (dataFile != NULL) {
        fprintf(dataFile, "Dla wielomianu:\n ");
        int m = st;
        for(int i=0; i<m; i++){
            fprintf(dataFile, "%dx^%d + ",tab[i],st);
            st--;
        }
        fprintf(dataFile, "%d ",tab[m]);
        fprintf(dataFile, " w przedziale(%d,%d) ", a, b); 
        fprintf(dataFile, "dla %d ilosci probek:\n\n", n);
        fprintf(dataFile, "Monte Carlo:%f\n", cal1);
        fprintf(dataFile, "Simpson:%f\n\n", cal2);
        fprintf(dataFile, "-------------------------------------------------------------------\n");
        fclose(dataFile);
    } else {
        printf("Error: Unable to open data file.\n");
        exit(EXIT_FAILURE);
    }
}