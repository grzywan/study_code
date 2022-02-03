#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

//Prosta baza danych przechowywana w strukturze
//Program umo¿liwia wypisanie wszystkich elementów z bazy oraz wyszukaæ osoby po wieku

struct osoba {
    char imie[20];
    char nazwisko[20];
    int wiek;
    struct data
    {
        int dzien;
        char miesiac[20];
    } ur;
} gosc[MAX];

void szukaj(struct osoba *gosc, int n);


int main(int argc, char* argv[])
{
    int n, j, k=0;

    strcpy(gosc[0].imie, "Ania");
    strcpy(gosc[0].nazwisko, "Marchewka");
    gosc[0].wiek = 10;
    gosc[0].ur.dzien = 25;
    strcpy(gosc[0].ur.miesiac, "luty");

    strcpy((gosc + 1)->imie, "Wojtek");
    strcpy((gosc + 1)->nazwisko, "Wrona");
    (gosc + 1)->wiek = 21;
    gosc[1].ur.dzien = 14;
    strcpy((gosc+1)->ur.miesiac, "marzec");

    strcpy(gosc[2].imie, "Aga");
    strcpy(gosc[2].nazwisko, "Pietrucha");
    gosc[2].wiek = 19;
    gosc[2].ur.dzien = 16;
    strcpy(gosc[2].ur.miesiac, "wrzesien");

    strcpy(gosc[3].imie, "Marcin");
    strcpy(gosc[3].nazwisko, "Lis");
    gosc[3].wiek = 33;
    gosc[3].ur.dzien = 20;
    strcpy(gosc[3].ur.miesiac, "czerwiec");

    strcpy(gosc[4].imie, "Barbara");
    strcpy(gosc[4].nazwisko, "Kalarepa");
    gosc[4].wiek = 45;
    gosc[4].ur.dzien = 2;
    strcpy(gosc[4].ur.miesiac, "grudzien");


    while (k != 3)
    {
        printf("\nWybierz opcje:\n\t1-Wypisz elementy bazy\n\t2-Wyszukaj osoby wedlug wieku\n\t3-Zakoncz dzialanie programu\n");
        scanf("%d", &k);

        switch (k) {
        case 1:
            for (j = 0; j < MAX; ++j)
                printf("%s\t%s\t%d lat(a), urodziny %d %s\n", gosc[j].imie, gosc[j].nazwisko, gosc[j].wiek, gosc[j].ur.dzien, gosc[j].ur.miesiac);
            break;
        case 2:
            printf("\nWyszukaj osoby mlodsze niz:");
            scanf("%d", &n);
            szukaj(&gosc, n);
            break;
        case 3:
            printf("\nKoniec programu\n");
            if (k == 3) continue;
        default:
            printf("\nBlad polecenia\n");
        }
    }
    system("PAUSE");
    return 0;

}


void szukaj(struct osoba *gosc, int n)
{
    int i, znaleziono;

    znaleziono = 0;
    for (i = 0; i < MAX; i++)
    {
        if (gosc[i].wiek < n)
        {
            printf("%s\t%s\t%d lat(a), urodziny %d %s\n", gosc[i].imie, gosc[i].nazwisko, gosc[i].wiek, gosc[i].ur.dzien, gosc[i].ur.miesiac);
            ++znaleziono;
        }
    }
    if (znaleziono == 0) 
        printf("Nie znaleziono osob w podanym wieku.\n\n");

}
