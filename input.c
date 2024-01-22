#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <stdbool.h>
//wciecia
int degreeOfPolynomial(){
    int degree;
    while (true) {
        printf("Podaj stopien (liczbe do ktorej podnoszona jest najwieksza potega) wielomianu: ");
        if (scanf("%d", &degree) == 1) {
            printf("\n");
            break;
        }
        else {
            printf("Nieprawidlowe dane. Podaj poprawny stopien wielomianu (liczba).\n");
            while (getchar() != '\n');
        }
    }
    return degree;
}

int* arrayWithCoefficients(int degree){
    int* array_coefficients = (int*)malloc(degree*sizeof(int));
    printf("Podaj prosze wspolczynniki liczonego wielomianu zaczynajac od tego przy najwyzszej potedze.\n\n");
    while(1){
        for (int i = 0; i < degree+1; i++){
            printf("Podaj %d wspolczynnik:", i);
            if(scanf("%d", &array_coefficients[i])==1){
                continue;
        }
            else{
                printf("Nieprawidlowe dane. Podaj poprawny stopien wielomianu (liczba).\n");
                while (getchar() != '\n');
                i--;
            }
        }
        printf("\n");
        break;
    }
    int n = degree;
    printf("Liczony wielomian to:");
    for(int i=0; i<n; i++){
        printf(" %dx^%d +",array_coefficients[i],degree);
        degree--;
        }
    printf(" %d\n",array_coefficients[n]);
    
    printf("\n");   
    return array_coefficients;
}

int lowerLimit(){
    int a;
    printf("Calka liczona jest dla danego przedzialu <a,b>\n");
    while(1){
        printf("Podaj dolna granice (a) zasiegu liczenia calki:");
        if(scanf("%d",&a)==1){
            break;
        }
            else{
                printf("Nieprawidlowe dane. Podaj poprawny stopien wielomianu (liczba).\n");
                while (getchar() != '\n');
            }
    }
    return a; 
}


int upperLimit() {
    int b;
    while(1){
        printf("Podaj gorna granice (b) zasiegu liczenia calki:");
        if(scanf("%d",&b)==1){
            printf("\n");
            break;
        }
            else {
                printf("Nieprawidlowe dane. Podaj poprawna granice dolna(liczba).\n");
                while (getchar() != '\n');
            }
    }
    return b;
}

int numOfSamples(){
    int n;
    printf("Obie metody liczenia opieraja sie na wyliczeniu wartosci dla wielomianu dla danej ilosci probek.\nIm wyzsza liczba probek tym wyzsza dokladnosc calki.\n\n");
    while(1){
        printf("Podaj liczbe probek dla ktorej chcesz liczyc calke (dowlona dodatnia liczba):");
        if(scanf("%d", &n)==1){
            printf("\n");
             break;
        }
            else{
                printf("Nieprawidlowe dane. Podaj poprawna dolna granice (liczba).\n");
                while (getchar() != '\n');
            }
    }
    return n;
}