#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node
{
char imie[20];
char nazwisko[20];
int wiek;
struct node *next;
struct node *prev;
} lista;

int i, j, q, count;
char im[20], nazw[20];
struct node *dodaj(struct node *);
struct node *usun(struct node *);
int szukaj(struct node*);
int szukaj_nazw(struct node*);
int szukaj_imie(struct node*);

int menu()
{
    
        printf("\nWybierz co chcesz zrobic:\n");
        printf("\t1-Dodac element na koniec listy.\n");
        printf("\t2-Usunac element z konca listy.\n");
        printf("\t3-Wyswietlic liste.\n");
        printf("\t4-Przeszukac liste.\n");
        printf("\t5-Zakonczyc dzialanie programu.\n");
        scanf("%d", &q);
        return q;
}

int main(int argc, char *argv[])
{
char k;
struct node *ostatni;
struct node *dodawany_usuwany;
struct node *kolejny;

lista.next=NULL;
lista.prev=NULL;
strcpy(lista.imie,"Anna");
strcpy(lista.nazwisko, "Marchewka");
lista.wiek = 10;
printf("Pierwszy element listy(imie, nazwisko, wiek): %s %s, %d lat(a)\n",lista.imie, lista.nazwisko, lista.wiek);
dodawany_usuwany=&lista;
ostatni=&lista;

dodawany_usuwany = dodaj(ostatni);
ostatni = dodawany_usuwany;
strcpy(ostatni->imie, "Natalia");
strcpy(ostatni->nazwisko, "Koperek");
ostatni->wiek = 19;
printf("Drugi element listy(imie, nazwisko, wiek): %s %s, %d lat(a)\n", ostatni->imie, ostatni->nazwisko, ostatni->wiek);

dodawany_usuwany = dodaj(ostatni);
ostatni = dodawany_usuwany;
strcpy(ostatni->imie, "Marcin");
strcpy(ostatni->nazwisko, "Wrona");
ostatni->wiek = 36;
printf("Drugi element listy(imie, nazwisko, wiek): %s %s, %d lat(a)\n", ostatni->imie, ostatni->nazwisko, ostatni->wiek);

do{
    q = menu();
    switch (q) 
    {
        case 1:
            {
                dodawany_usuwany = dodaj(ostatni);
                ostatni = dodawany_usuwany;
                printf("Wartosc elementu(imie nazwisko wiek): ");
                scanf("%s %s %d", &(ostatni->imie), &(ostatni->nazwisko), &(ostatni->wiek));
            }
            break;

        case 2:
            {
                if (dodawany_usuwany == &lista)
                {
                    printf("Pozostal jeden element.\n");
                    break;
                }
                ostatni = usun(dodawany_usuwany);
                dodawany_usuwany = ostatni;
                
            }
            break;

        case 3:
            printf("\nElementy listy wypisane od poczatku do konca:\n");
            kolejny = &lista;
            do
            {
                printf("%s\t%s\t%d lat(a)\n", kolejny->imie, kolejny->nazwisko, kolejny->wiek);
                kolejny = kolejny->next;
            } while (kolejny != NULL);
            break;
        
        case 4:
            printf("Wyszukiwanie osoby po 1-imieniu/2-nazwisku/3-wieku:\n");
            scanf("%d", &i);

            switch (i)
            {
                    case 1:
                    {
                        printf("Znajdz osobe o imieniu:\n");
                        scanf("%s", &im);
                        count = szukaj_imie(&lista);
                        if (!count)
                            printf("Brak osob.\n");
                    }
                    break;

                    case 2:
                    {
                        printf("Znajdz osobe o nazwisku:\n");
                        scanf("%s", &nazw);
                        count = szukaj_nazw(&lista);
                        if (!count)
                            printf("Brak osob.\n");
                    }
                    break;

                    case 3:
                    {
                        printf("Wyszukaj osoby w podanym wieku i mlodsze:\n");
                        scanf("%d", &j);
                        count = szukaj(&lista);
                        if (!count)
                            printf("Brak osob.\n");
                    }
                    break;
                    }
        case 5:
            printf("Nacisnij jakis klawisz...");
            k = getchar();
            k = getchar();
            break;
        default:
            printf("Blad polecenia.");

    }
} while (q != 5);

return 0;
}


struct node *dodaj(struct node *ostatni)
{
  struct node *nowy;
  nowy=(struct node*)malloc(sizeof(struct node));
  ostatni->next=nowy;
  nowy->prev=ostatni;
  nowy->next=NULL;
  return(nowy);
}

struct node *usun(struct node *ostatni)
{
  struct node *p_ostatni;
  p_ostatni=ostatni->prev;
  p_ostatni->next=NULL;
  free(ostatni);
  return(p_ostatni);
}

int szukaj(struct node* kolejny)
{
    int count=0;
    printf("\nWyszukane elementy listy :\n");
    kolejny = &lista;
    do
    {
        if (kolejny->wiek <= j) {
            printf("%s\t%s\t%d lat(a)\n", kolejny->imie, kolejny->nazwisko, kolejny->wiek);
            count=1;
        }
        kolejny = kolejny->next;
    } while (kolejny != NULL);
    printf("\n");

    return count;
}

int szukaj_imie(struct node* wsk)
{
    int count = 0;
    printf("\nWyszukane elementy listy :\n");
    wsk = &lista;
    do
    {
        if (strcmp(wsk->imie, im) == 0)
        {
            printf("%s\t%s\t%d lat(a)\n", wsk->imie, wsk->nazwisko, wsk->wiek);
            count=1;
        }
        wsk = wsk->next;
    } while (wsk != NULL);
    printf("\n");

    return count;
}


int szukaj_nazw(struct node* wsk)
{
    int count = 0;
    printf("\nWyszukane elementy listy :\n");
    wsk = &lista;
    do
    {
        if (strcmp(wsk->nazwisko,nazw)==0) 
        {
            printf("%s\t%s\t%d lat(a)\n", wsk->imie, wsk->nazwisko, wsk->wiek);
            count=1;
        }
        wsk = wsk->next;
    } while (wsk != NULL);
    printf("\n");

    return count;
}

