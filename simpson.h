#ifndef simpson_h
#define simpson_h

double f(double x, int tab[], int stopien);
void createTabXandTabY_simpson(double** xs,double** ys,int a, int b, int n,int tab[],int stopien);
double simpsons(int a,int b, int n,int tab[],int stopien);

#endif
