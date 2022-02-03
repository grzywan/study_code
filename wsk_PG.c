#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])    // definicja funkcji "main";
{

    char* mes;                  // deklaracja wkaŸnika do ³añcucha znakowego(u¿ycie wskaŸnika do char);
    int a[10], b;               // zadeklarowanie tablicy 10-cio elementowej a[] i zmiennej b, oba elementy typu ca³kowitego;
    int y;                      // deklaracja zmiennej ca³kowitej y;
    int ll[10];                 // deklaracja tablicy 10-cio elementowej ll[] z elementami typu ca³kowitego;

   
    int* px, * lx;              // deklaracja wskaŸników *px i *lx, typu ca³kowitego;
    void zamiana(int*, int*);   // deklaracja funkcji "zamiana", funckja pobiera dwa argumenty typu ca³kowitego, funkcja mo¿e odczytaæ wartoœci zapisane pod adresami które jej podamy,\n
                                // standard ANSI C pozwala pomin¹æ nazwy zmiennych;

    mes = "napis";              // mes przechowuje ci¹g znaków "napis";
    printf("%c\n", mes[2]);     // wydruk na ekranie 3-go znaku z ³añcucha znakowego mes(litera "p");
    y = '\n';                   // zmienna y przechowuje znak nowej linni;
    lx = &ll[0];                // przypisanie wskaŸnikowi lx wartoœci(adresu) pierwszego elementu tablicy ll[];
    px = &y;                    // przypisanie wskaŸnikowi px wartoœci(adresu) zmiennej y;
    *px = 2;                    // pod adres na któy wskazuje wskaŸnik px zostaje nadana wartoœæ 2;
    y = 1;                      // przypisanie zmiennej y wartoœci 1(tak¿e wskaŸnikowi px, któy wskazuje na wartoœæ pod adresem y);
    (*px)++;                    // zwiêkszenie wartoœci na któr¹ wskazuje wskaŸnik px o 1(postinkrementacja);
    y = ++(*px);                // wartoœæ zmiennej y równa siê wartoœci na któr¹ wskazuje wskaŸnik px zwiêkszon¹ uprzednio o 1(preinkrementacja);
    lx[1] = 3;                  // wskaŸnik lx przypisuje wartoœæ 3 do drugiego elementu tablicy ll[] (notacja tablicowa);
    *(ll + 3) = 4;              // przypisuje wartoœæ 4 dla czwartego elementu tablicy ll[] (notacja wskaŸnikowa);

    a[5] = 1;                   // przypisuje wartoœæ 1 szóstemu elementowi tablicy a[];
    b = 2;                      // zmienna b przechowuje wartoœæ 2;


    zamiana(a, &b);             // wywo³anie funkcji "zamiana", argumenty formalne to tablica a[] i adres zmiennej b;
    

    printf("a=%d  b=%d\n", a[5], b);    // wydruk wartoœæi znajduj¹cych siê pod 6-ym elementem tablicy a[] i pod zmienn¹ b;

    system("PAUSE");            // zatrzymanie konsoli;
    return 0;                   // wartoœæ zwracana z funkcji main;
}


void zamiana(int a[], int* b)   // definicja funkcji "zamiana", argumenty funkcji(int a[] = "wskaŸnik do int"), funkcja dziêki dziêki operatorowi "*" mo¿e odczytaæ wartoœci zapisane pod tymi adresami i dokonaæ ich zmiany;
{

    int temp;       // zadeklarowanie zmiennej typu int o nazwie temp;
    temp = a[5];    // temp otrzymuje wartoœæ na któr¹ wskazuje 6 element tablicy a[];
    a[5] = *b;      // nadanie 6 elementowi tablicy a[] wartoœci na któr¹ wskazuje wskaŸnik *b;
    *b = temp;      // b otrzymuje wartoœæ pod zmienn¹ temp;

}
