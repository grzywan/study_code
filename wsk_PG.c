#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])    // definicja funkcji "main";
{

    char* mes;                  // deklaracja wka�nika do �a�cucha znakowego(u�ycie wska�nika do char);
    int a[10], b;               // zadeklarowanie tablicy 10-cio elementowej a[] i zmiennej b, oba elementy typu ca�kowitego;
    int y;                      // deklaracja zmiennej ca�kowitej y;
    int ll[10];                 // deklaracja tablicy 10-cio elementowej ll[] z elementami typu ca�kowitego;

   
    int* px, * lx;              // deklaracja wska�nik�w *px i *lx, typu ca�kowitego;
    void zamiana(int*, int*);   // deklaracja funkcji "zamiana", funckja pobiera dwa argumenty typu ca�kowitego, funkcja mo�e odczyta� warto�ci zapisane pod adresami kt�re jej podamy,\n
                                // standard ANSI C pozwala pomin�� nazwy zmiennych;

    mes = "napis";              // mes przechowuje ci�g znak�w "napis";
    printf("%c\n", mes[2]);     // wydruk na ekranie 3-go znaku z �a�cucha znakowego mes(litera "p");
    y = '\n';                   // zmienna y przechowuje znak nowej linni;
    lx = &ll[0];                // przypisanie wska�nikowi lx warto�ci(adresu) pierwszego elementu tablicy ll[];
    px = &y;                    // przypisanie wska�nikowi px warto�ci(adresu) zmiennej y;
    *px = 2;                    // pod adres na kt�y wskazuje wska�nik px zostaje nadana warto�� 2;
    y = 1;                      // przypisanie zmiennej y warto�ci 1(tak�e wska�nikowi px, kt�y wskazuje na warto�� pod adresem y);
    (*px)++;                    // zwi�kszenie warto�ci na kt�r� wskazuje wska�nik px o 1(postinkrementacja);
    y = ++(*px);                // warto�� zmiennej y r�wna si� warto�ci na kt�r� wskazuje wska�nik px zwi�kszon� uprzednio o 1(preinkrementacja);
    lx[1] = 3;                  // wska�nik lx przypisuje warto�� 3 do drugiego elementu tablicy ll[] (notacja tablicowa);
    *(ll + 3) = 4;              // przypisuje warto�� 4 dla czwartego elementu tablicy ll[] (notacja wska�nikowa);

    a[5] = 1;                   // przypisuje warto�� 1 sz�stemu elementowi tablicy a[];
    b = 2;                      // zmienna b przechowuje warto�� 2;


    zamiana(a, &b);             // wywo�anie funkcji "zamiana", argumenty formalne to tablica a[] i adres zmiennej b;
    

    printf("a=%d  b=%d\n", a[5], b);    // wydruk warto��i znajduj�cych si� pod 6-ym elementem tablicy a[] i pod zmienn� b;

    system("PAUSE");            // zatrzymanie konsoli;
    return 0;                   // warto�� zwracana z funkcji main;
}


void zamiana(int a[], int* b)   // definicja funkcji "zamiana", argumenty funkcji(int a[] = "wska�nik do int"), funkcja dzi�ki dzi�ki operatorowi "*" mo�e odczyta� warto�ci zapisane pod tymi adresami i dokona� ich zmiany;
{

    int temp;       // zadeklarowanie zmiennej typu int o nazwie temp;
    temp = a[5];    // temp otrzymuje warto�� na kt�r� wskazuje 6 element tablicy a[];
    a[5] = *b;      // nadanie 6 elementowi tablicy a[] warto�ci na kt�r� wskazuje wska�nik *b;
    *b = temp;      // b otrzymuje warto�� pod zmienn� temp;

}
