#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <stdbool.h>
//wciecia
int stopien_wielomianu(){
    int st;
    while (true) {
        printf("Podaj stopien (liczbe do ktorej podnoszona jest najwieksza potega) wielomianu: ");
        if (scanf("%d", &st) == 1) break;
        else {
            printf("Nieprawidlowe dane. Podaj poprawny stopien wielomianu (liczba).\n");
            while (getchar() != '\n');
        }
    }
    return st;
}

int* tablica_z_podanymi_wspolczynnikami(int st){
    int* tablica_wspolczynnikow = (int*)malloc(st*sizeof(int));
    printf("Podaj prosze wspolczynniki liczonego wielomianu zaczynajac od tego przy najwyzszej potedze.\n");
    while(1){
        for (int i = 0; i < st+1; i++){
            printf("Podaj %d wspolczynnik:", i);
            if(scanf("%d", &tablica_wspolczynnikow[i])==1){
                continue;
        }
            else{
                printf("Nieprawidlowe dane. Podaj poprawny stopien wielomianu (liczba).\n");
                while (getchar() != '\n');
                i--;
            }
        }
        break;
    }
    int n = st;
    printf("Liczony wielomian to:");
    for(int i=0; i<n; i++){
        printf("%dx^%d+",tablica_wspolczynnikow[i],st);
        st--;
        }
    printf("%d\n",tablica_wspolczynnikow[n]);
    //ładniej??

    return tablica_wspolczynnikow;
}

int dolna_gr(){
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


int gorna_gr() {
    int b;
    while(1){
        printf("Podaj gorna granice (b) zasiegu liczenia calki:");
        if(scanf("%d",&b)==1){
            break;
        }
            else {
                printf("Nieprawidlowe dane. Podaj poprawny stopien wielomianu (liczba).\n");
                while (getchar() != '\n');
            }
    }
    return b;
}

int il_prob(){
    int n;
    printf("Obie metody liczenia opieraja sie na wyliczeniu wartosci dla wielomianu dla danej ilosci probek.\n Im wyzsza liczba probek tym wyzsza dokladnosc calki.\n");
    while(1){
        printf("Podaj liczbe probek dla ktorej chcesz liczyc calke (dowlona dodatnia liczba):");
        if(scanf("%d", &n)==1){
             break;
        }
            else{
                printf("Nieprawidlowe dane. Podaj poprawny stopien wielomianu (liczba).\n");
                while (getchar() != '\n');
            }
    }
    return n;
}