//Zablokowanie ostrze¿eñ o funkcjach stanowi¹cych zagro¿enie dla bezpieczeñstwa
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    char* dzialanie;        //deklaracja zmiennej znakowej 'dzialanie'
    int i;                  //deklaracja zmiennej 'i' typu int
    double* wekt1, * wekt2, * wynik;        //deklaracja zmiennych 'wekt1', 'wekt2', 'wynik' typu double 
    errno_t r;              //typ b³êdu dla wersji bezpiecznej funkcji

    //przydzielenie pamiêci 40 elementów typu char, jeœli przydzielona pamiêæ równa siê zero na ekranie pojawia siê komunikat o b³êdzie i program koñczy dzia³anie
    if ((dzialanie = (char*)malloc(40 * sizeof(char))) == 0) {
        printf("Blad przydzialu pamieci.\n");
        exit(1);
    }

    //wersja bezpieczna funkcji 'strcpy()'
    r = strcpy_s(dzialanie, 40 * sizeof(char), "Iloczyn skalarny wektorow:\n");    //funkcja 'strcpy_s' kopiuje ³añcuch znaków "Iloczyn...wektorow:" pod adres przechowywany przez zmienn¹ 'dzialanie'
    printf("\n%s\n", dzialanie);        //wydruk ³añcucha znaków(%s - string)

    //zwolnienie pamiêci przydzielonej na zmienn¹ 'dzialanie'
    free(dzialanie);


    if ((       //przydzia³ 4 wartoœci typu double dla zmiennej 'wekt1', jeœli nie uda siê zarezerwowaæ pamiêci zwróci znak zerowy, program wyœwietli komunikat o b³êdzie i zakoñczy dzia³anie
        wekt1 = (double*)malloc(4 * sizeof(double))) == NULL) {
        printf("Blad przydzialu pamieci.");
        exit(1);
    }

    if ((       //jw. dla zmiennej 'wekt2'
        wekt2 = (double*)malloc(4 * sizeof(double))) == NULL) {
        printf("Blad przydzialu pamieci.");
        exit(1);
    }

    printf("Podaj elementy wektora 1 (4 liczby):\n");       //proœba o podanie 4 wartoœci pierwszego wektora
    for (i = 0; i < 4; i++) {                               //wektor mo¿e byæ maksymalnie 4-elementowy(u¿ywamy w pêtli zmiennej 'i')
    fscanf_s(stdin, "%lf", (wekt1 + i));                    //przypisanie wartoœci z klawiatury pod kolejne adresy w tablicy dynamicznej('wekt1' jest zadeklarowany jako wskaŸnik do pierwszego elementu)
}

    printf("Podaj elementy wektora 2 (4 liczby):\n");       //jw. dla drugiego wektora(reprezentowany przez zmienn¹ 'wekt2')
    for (i = 0; i < 4; i++) {
        fscanf_s(stdin, "%lf", (wekt2 + i));
    }

    //przydzielenie pamiêci zmiennej 'wynik'(typ double), w przypadku b³edu zwróci znak zerowy i zakoñczy program
 if ((wynik = (double *) malloc(1*sizeof(double))) == NULL) {
   printf("Blad przydzialu pamieci.");
   exit(1);
 }
 
 *wynik=0;                                             //deklaracja wartoœci zmiennej 'wynik'

 for (i = 0; i < 4; i++) {                             //pêtla powtórzy siê dla ka¿dej pary 4 elementów wektorów
     *wynik = *wynik + *(wekt1 + i) * *(wekt2 + i);    //pod zmienn¹ 'wynik' zostanie przypisana wartoœæ iloczynu tych samych elementów 2-óch wektorów, po ka¿dym przebiegu pêtli zmienna 'wynik' bêdzie
 }                                                     //nadpisywana przez dodanie do poprzedniej wartoœci zmiennej 'wynik' iloczynu kolejnej pary elementów wektorów

 printf("\nIloczyn skalarny wektorow = %lf\n\n", *wynik);    //wyœwietla wartoœæ 'wynik' po zakoñczeniu dzia³ania pêtli 'for'
 
 free(wekt1);       //zwolnienie pamiêci przydzielonej na zmienn¹ 'wekt1'
 free(wekt2);       //zwolnienie pamiêci przydzielonej na zmienn¹ 'wekt2'
 free(wynik);       //zwolnienie pamiêci przydzielonej na zmienn¹ 'wynik'

 system("PAUSE");	//zatrzymanie konsoli
 return 0;
}
