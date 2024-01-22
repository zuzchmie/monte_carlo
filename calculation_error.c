#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calculation_error.h"

double error(double ys[], int n, double monte){
double y_squared = 0.0;
double monte_squared = 0.0;
double error;

double* ys_squared = (double*)malloc(n*sizeof(double));
for(int i = 0; i < n ; i++){
    ys_squared[i] = ys[i]*ys[i];
}

for(int j = 0; j < n; j++){
    y_squared += ys_squared[j]; 
}


y_squared = y_squared/n; 
monte_squared = monte*monte;
error = sqrt((monte_squared-y_squared)/(n));

return error;

}