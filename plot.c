#include <stdio.h>
#include <stdlib.h>
#include "plot.h"


void drawPlot(char* name_txt, char* plot_name){
    char filename[100];
    snprintf(filename, sizeof(filename), "calka_wykres_%s.txt Calka %s", name_txt, plot_name); 
    FILE *gnuplotPipeMonte = popen("gnuplot -persistent", "w");
    if (gnuplotPipeMonte != NULL) {
        fprintf(gnuplotPipeMonte, "set terminal pngcairo enhanced color\n");
        fprintf(gnuplotPipeMonte, "set output 'calka_wykres_monte.png'\n");
        fprintf(gnuplotPipeMonte, "set xlabel 'X'\n");
        fprintf(gnuplotPipeMonte, "set ylabel 'Y'\n");
        fprintf(gnuplotPipeMonte, "set title 'Calka Monte Carlo'\n");
        fprintf(gnuplotPipeMonte, "plot 'plot_data_monte.txt' smooth unique title 'Data'\n");

    } else {
        printf("Error: Gnuplot not found or unable to open a pipe.\n");
        exit(EXIT_FAILURE);
    }
}

void drawPlot_simpson(){ 
    drawPlot("simpson","Simpson");    
}


void drawPlot_monte(){ 
    drawPlot("monte","Monte Carlo");    
}

void writeDataToFile(char* name, double x[], double y[], int n) {
    char filename [100];
    snprintf(filename, sizeof(filename),"monte_carlo_%s.txt",name);
    FILE *dataFile = fopen(filename, "w");
    if (dataFile != NULL) {
        for (int i = 0; i < n; i++) {
            fprintf(dataFile, "%f %f\n", x[i], y[i]);
        }
        fclose(dataFile);
    } else {
        printf("Error: Unable to open data file.\n");
        exit(EXIT_FAILURE);
    }
}

void writeDataToFile_monte(double x[],double y[],int n) {
    writeDataToFile("monte", x, y, n);
}

void writeDataToFile_simpson(double x[],double y[],int n){
    writeDataToFile("simplson", x, y, n);
}