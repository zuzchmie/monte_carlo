#ifndef plot_h
#define plot_h

void writeDataToFileMonte(double x[],double y[],int n);

/*
** writing the data from the arrays with the points of a monte carlo integration
*/
void writeDataToFileSimpson(double x[],double y[],int n);

/*
** writing the data from the arrays with the points of a simpson integration
*/

void drawPlotMonte();
/*
** drawing the plot using the data from the txt data file (monte carlo)
*/

void drawPlotSimpson();

/*
** drawing the plot using the data from the txt data file (monte carlo)
*/


#endif