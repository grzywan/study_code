#include <stdio.h>
#include <stdlib.h>

/* Stworzenie dwóch wektorów n-elementowych i zamiana ich wszystkich elementów przy u¿yciu funkcji */

float swap(float* c, float* d);

int main()
{
    int i;
    float a[5] = { 0, 1, 2, 3, 4 },
        b[5] = { 5, 6, 7, 8, 9 };

    printf("Wartosci tablic przed zamiana:\n\n");
    for (i = 0; i < 5; i++) {
        printf("a[%d] = %f     b[%d] = %f\n", i, a[i], i, b[i]);
    }

    swap(a, b);

    printf("\nWartosci tablic po zamianie:\n\n");
    for (i = 0; i < 5; i++) {
        printf("a[%d] = %f     b[%d] = %f\n", i, a[i], i, b[i]);
    }
    "\n";
    system("PAUSE");
    return 0;
}


float swap(float* c, float* d)
{
    int i;
    for (i = 0; i < 5; i++)
    {
        float temp;
        temp = c[i];
        c[i] = d[i];
        d[i] = temp;
    }
    return 0;
}
