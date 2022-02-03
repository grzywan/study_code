//sortowanie wg pierwszej i drugiej litery alfabetu przy u¿yciu sortowania b¹belkowego
//porz¹dkowanie tylko tablicy wskaŸników
//sortowanie w funkcji msort1 i msort2

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int msort1(char **name, int size);
int msort2(char **name, int size);


int main(int argc, char *argv[])
{
  int i, size;
  char *name[10]={  "zajazd",
					"zlot",
					"auto",
					"kowal",
					"omen",
					"ala",
					"zenit"     };
  
  //liczba elementow w tablicy
  size=7;
  
  printf("Przed posortowaniem:\n");
  for (i=0; i<size; i++)
  printf("%s ",*(name+i));
  printf("\n");
  
  msort1(name, size);
  
  printf("\nPo posortowaniu:\n");
  for (i=0; i<size; i++)
  printf("%s ",name[i]);
  printf("\n\n");

  system("PAUSE");	
  return 0;
}





int msort1 (char **name, int size)
{
 int i,j;
 char *temp;

 //sortowanie babelkowe
 for(j=0; j<size; j++) {
  for (i=0; i<size-j-1; i++) {

   if (*name[i] > *name[i+1]) {
     temp=name[i];
     name[i]=name[i+1];
     name[i+1]=temp;
   }

   if (*name[i] == *name[i+1]) {
       if (*(name[i]+1) > *(name[i+1]+1)) {
           temp = name[i];
           name[i] = name[i+1];
           name[i+1] = temp;
       }

   }

  }
 }
 return 0;
}



int msort2 (char **name, int size)
{
 int i,j;
 char *temp;
 
 //sortowanie babelkowe
 for(j=0; j<size; j++) {
  for (i=0; i<size-j-1; i++) {

   if (**(name+i) > **(name+i+1)) {
     temp=*(name+i);
     *(name+i)=*(name+i+1);
     *(name+i+1)=temp;
   }
  
   if (**(name+i) == **(name+i+1)) {
       if (*(*(name+i)+1) > *(*(name+i+1)+1)) {
           temp = *(name+i);
           *(name+i) = *(name+i+1);
           *(name+i+1) = temp;
       }

   }
   
  }
 }
 return 0;
}
