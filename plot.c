#include <stdio.h>
#include <stdlib.h>
#include "plot.h"


void drawPlotMonte(){ 
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

void drawPlotSimpson(){ 
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

void writeDataToFile(char* name, double x[], double y[], int n) {
    char filename [100];
    snprintf(filename, sizeof(filename),"plot_data_%s.txt",name);
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

void writeDataToFileMonte(double x[],double y[],int n) {
    writeDataToFile("monte", x, y, n);
}

void writeDataToFileSimpson(double x[],double y[],int n){
    writeDataToFile("simpson", x, y, n);
}
/*
char* name_png, char* plot_name
char filename[100];
    char filename1[100];
    snprintf(filename, sizeof(filename), "%s", name_png); 
    snprintf(filename1, sizeof(filename1), "%s", plot_name);
    */