#include <stdio.h>
#include <stdlib.h>
#include "plot.h"


void drawPlot_monte(){ 
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
    FILE *gnuplotPipeSimpson = popen("gnuplot -persistent", "w");
    if (gnuplotPipeSimpson != NULL) {
        fprintf(gnuplotPipeSimpson, "set terminal pngcairo enhanced color\n");
        fprintf(gnuplotPipeSimpson, "set output 'calka_wykres_simpson.png'\n");
        fprintf(gnuplotPipeSimpson, "set xlabel 'X'\n");
        fprintf(gnuplotPipeSimpson, "set ylabel 'Y'\n");
        fprintf(gnuplotPipeSimpson, "set title 'Calka Simpson'\n");
        fprintf(gnuplotPipeSimpson, "plot 'plot_data_simpson.txt' smooth unique title 'Data'\n");
    } else {
        printf("Error: Gnuplot not found or unable to open a pipe.\n");
        exit(EXIT_FAILURE);
    }
}

void writeDataToFile_monte(double x[],double y[],int n){
    FILE *dataFile = fopen("plot_data_monte.txt", "w");
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

void writeDataToFile_simpson(double x[],double y[],int n){
    FILE *dataFile = fopen("plot_data_simpson.txt", "w");
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