#ifndef monte_carlo_h
#define monte_carlo_h

double f(double x, int tab[], int stopien);
void createTabXandTabYMonte(double** xs,double** ys,int a, int b, int n,int tab[],int stopien);
double monteCarlo(int a,int b, double ys[], int n);

#endif
