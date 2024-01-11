#ifndef plot_h
#define plot_h

void writeDataToFile_monte(double x[],double y[],int n);

/*
** writing the data from the arrays with the points of a monte carlo integration
*/
void writeDataToFile_simpson(double x[],double y[],int n);

/*
** writing the data from the arrays with the points of a simpson integration
*/

void drawPlot_monte();
/*
** drawing the plot using the data from the txt data file (monte carlo)
*/

void drawPlot_simpson();

/*
** drawing the plot using the data from the txt data file (monte carlo)
*/

#endif