#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Stworzenie dwóch wektorów n-elementowych i obliczenie iloczynu skalarnego ich wszystkich elementów przy u¿yciu funkcji */

double skalar(double* a, double* b, int n);


int main(int argc, char* argv[])
{
    char* dzialanie;
    int i, n;
    double wekt1[5], wekt2[5], wynik;
    errno_t r;

    if ((dzialanie = (char*)malloc(40 * sizeof(char))) == 0) {
        printf("Blad przydzialu pamieci.\n");
        exit(1);
    }

    r = strcpy_s(dzialanie, 40 * sizeof(char), "Iloczyn skalarny wektorow = \n");


    free(dzialanie);

    printf("Podaj liczbe elementow wektorow (max 5 liczb):\n");
    zle: scanf("%d", &n);

    while (n > 5) {
        printf("Sprobuj jeszcze raz.\n");
        goto zle;
    }

    printf("\nPodaj elementy wektora 1 (%d liczby):\n", n);

    for (i = 0; i < n; i++) {
        fscanf_s(stdin, "%lf", (wekt1 + i));
    }

    printf("\nPodaj elementy wektora 2 (%d liczby):\n", n);
    for (i = 0; i < n; i++) {
        fscanf_s(stdin, "%lf", (wekt2 + i));
    }

    wynik = skalar(wekt1, wekt2, n);
    printf("\nIloczyn skalarny wektorow = %lf\n", wynik);

    system("PAUSE");
    return 0;
}

double skalar(double* wekt1, double* wekt2, int n) {

    int i;
    double temp = 0;

    for (i = 0; i < n; i++) {
        temp = temp + *(wekt1 + i) * *(wekt2 + i);
    }

    return temp;
}