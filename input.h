#ifndef input_h
#define input_h

int degreeOfPolynomial();

/*
** takes the input of the degree of a polynomial from the user
*/

int* arrayWithCoefficients(int degree);

/*
** takes the input of the rates of change of a polynomial from the user
*/

int lowerLimit();

/*
** takes the input of the down limit of the interval on which the integration is being calculated from the user
*/


int upperLimit();

/*
** takes the input of the top limit of the interval on which the integration is being calculated from the user
*/

int numOfSamples();


/*
** takes the input of the number of values for which the integration is being calculated from the user
*/


#endif