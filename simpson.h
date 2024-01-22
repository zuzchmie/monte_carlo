#ifndef simpson_h
#define simpson_h

double f(double x, int tab[], int stopien);
void createTabXandTabYSimpson(double** xs,double** ys,int a, int b, int n,int tab[],int stopien);
double simpson(int a,int b, int n,int tab[],int stopien);

#endif
