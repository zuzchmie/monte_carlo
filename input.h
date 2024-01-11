#ifndef input_h
#define input_h

int stopien_wielomianu();

/*
** takes the input of the degree of a polynomial from the user
*/

int *tablica_z_podanymi_wspolczynnikami(int st);

/*
** takes the input of the rates of change of a polynomial from the user
*/

int dolna_gr();

/*
** takes the input of the down limit of the interval on which the integration is being calculated from the user
*/


int gorna_gr();

/*
** takes the input of the top limit of the interval on which the integration is being calculated from the user
*/

int il_prob();


/*
** takes the input of the number of values for which the integration is being calculated from the user
*/


#endif