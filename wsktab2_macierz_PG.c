#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//Program tworzy dwie tablice dwuwymiarowe i zwraca jako wynik:
//najwiêksz¹ liczbê pierwszej macierzy
//najwiêksz¹ liczbê drugiej macierzy
//iloczyn macierzy tab1 * tab2
//iloczyn macierzy tab2 * tab1

void dz_el(int(*tab1)[3], int(*tab2)[2], int(*mnoz1)[2], int(*mnoz2)[3], float* wynik);

int main()
{

    int i, j;
    int tab1[2][3] =
    {
      {1, 8, 3},
      {4, 5, 6}
    };

    int tab2[3][2] =
    {
      {1, 2},
      {3, 5},
      {4, 6}
    };

    int mnoz1[2][2] = { {0} };
    int mnoz2[3][3] = { {0} };


    float wynik[2];

    dz_el(tab1, tab2, mnoz1, mnoz2, wynik);

    printf("\nnajwieksza liczba tab1=%f   najwieksza liczba tab2=%f   \n\n", wynik[0], wynik[1]);
    printf("\nIloczyn macierzy tab1*tab2\n");
    for (i = 0; i < 2; i++)
    {
        printf("\n");
        for (j = 0; j < 2; j++)
            printf("%d\t", mnoz1[i][j]);
    }

    printf("\n\n\nIloczyn macierzy tab2*tab1\n");
    for (i = 0; i < 3; i++)
    {
        printf("\n");
        for (j = 0; j < 3; j++)
            printf("%d\t", mnoz2[i][j]);
    }

    system("pause");
    return 0;
}


void dz_el(int(*tab1)[3], int(*tab2)[2], int(*mnoz1)[2], int(*mnoz2)[3], float* wynik)
{
    int i, j, p, u;
    int max1, max2;


    max1 = 0;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            if (max1 < tab1[i][j])
                max1 = tab1[i][j];
        }
    }

    max2 = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if (max2 < tab2[i][j])
                max2 = tab2[i][j];
        }
    }

    *wynik = max1;
    *(wynik + 1) = max2;

    for (i = 0; i < 2; i++)
        for (p = 0; p < 2; p++)
            for (u = 0; u < 3; u++)
                mnoz1[i][p] = mnoz1[i][p] + tab1[i][u] * tab2[u][p];

    for (i = 0; i < 3; i++)
        for (p = 0; p < 3; p++)
            for (u = 0; u < 2; u++)
                mnoz2[i][p] = mnoz2[i][p] + tab2[i][u] * tab1[u][p];

};
