//Zablokowanie ostrze�e� o funkcjach stanowi�cych zagro�enie dla bezpiecze�stwa
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char* dzialanie;        //deklaracja zmiennej znakowej 'dzialanie'
    int i;                  //deklaracja zmiennej 'i' typu int
    double* wekt1, * wekt2, * wynik;        //deklaracja zmiennych 'wekt1', 'wekt2', 'wynik' typu double 
    errno_t r;              //typ b��du dla wersji bezpiecznej funkcji

    //przydzielenie pami�ci 40 element�w typu char, je�li przydzielona pami�� r�wna si� zero na ekranie pojawia si� komunikat o b��dzie i program ko�czy dzia�anie
    if ((dzialanie = (char*)malloc(40 * sizeof(char))) == 0) {
        printf("Blad przydzialu pamieci.\n");
        exit(1);
    }

    //wersja bezpieczna funkcji 'strcpy()'
    r = strcpy_s(dzialanie, 40 * sizeof(char), "Iloczyn skalarny wektorow:\n");    //funkcja 'strcpy_s' kopiuje �a�cuch znak�w "Iloczyn...wektorow:" pod adres przechowywany przez zmienn� 'dzialanie'
    printf("\n%s\n", dzialanie);        //wydruk �a�cucha znak�w(%s - string)

    //zwolnienie pami�ci przydzielonej na zmienn� 'dzialanie'
    free(dzialanie);


    if ((       //przydzia� 4 warto�ci typu double dla zmiennej 'wekt1', je�li nie uda si� zarezerwowa� pami�ci zwr�ci znak zerowy, program wy�wietli komunikat o b��dzie i zako�czy dzia�anie
        wekt1 = (double*)malloc(4 * sizeof(double))) == NULL) {
        printf("Blad przydzialu pamieci.");
        exit(1);
    }

    if ((       //jw. dla zmiennej 'wekt2'
        wekt2 = (double*)malloc(4 * sizeof(double))) == NULL) {
        printf("Blad przydzialu pamieci.");
        exit(1);
    }

    printf("Podaj elementy wektora 1 (4 liczby):\n");       //pro�ba o podanie 4 warto�ci pierwszego wektora
    for (i = 0; i < 4; i++) {                               //wektor mo�e by� maksymalnie 4-elementowy(u�ywamy w p�tli zmiennej 'i')
    fscanf_s(stdin, "%lf", (wekt1 + i));                    //przypisanie warto�ci z klawiatury pod kolejne adresy w tablicy dynamicznej('wekt1' jest zadeklarowany jako wska�nik do pierwszego elementu)
}

    printf("Podaj elementy wektora 2 (4 liczby):\n");       //jw. dla drugiego wektora(reprezentowany przez zmienn� 'wekt2')
    for (i = 0; i < 4; i++) {
        fscanf_s(stdin, "%lf", (wekt2 + i));
    }

    //przydzielenie pami�ci zmiennej 'wynik'(typ double), w przypadku b�edu zwr�ci znak zerowy i zako�czy program
 if ((wynik = (double *) malloc(1*sizeof(double))) == NULL) {
   printf("Blad przydzialu pamieci.");
   exit(1);
 }
 
 *wynik=0;                                             //deklaracja warto�ci zmiennej 'wynik'

 for (i = 0; i < 4; i++) {                             //p�tla powt�rzy si� dla ka�dej pary 4 element�w wektor�w
     *wynik = *wynik + *(wekt1 + i) * *(wekt2 + i);    //pod zmienn� 'wynik' zostanie przypisana warto�� iloczynu tych samych element�w 2-�ch wektor�w, po ka�dym przebiegu p�tli zmienna 'wynik' b�dzie
 }                                                     //nadpisywana przez dodanie do poprzedniej warto�ci zmiennej 'wynik' iloczynu kolejnej pary element�w wektor�w

 printf("\nIloczyn skalarny wektorow = %lf\n\n", *wynik);    //wy�wietla warto�� 'wynik' po zako�czeniu dzia�ania p�tli 'for'
 
 free(wekt1);       //zwolnienie pami�ci przydzielonej na zmienn� 'wekt1'
 free(wekt2);       //zwolnienie pami�ci przydzielonej na zmienn� 'wekt2'
 free(wynik);       //zwolnienie pami�ci przydzielonej na zmienn� 'wynik'

 system("PAUSE");	//zatrzymanie konsoli
 return 0;
}
