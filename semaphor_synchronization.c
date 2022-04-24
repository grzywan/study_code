#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>


sem_t semaphore;
/* Parameters to print_function.  */


struct char_print_parms
{
  /* The character to print.  */
  char character;
  /* The number of times to print it.  */
  int count;
};

/* Prints a number of characters to stderr, as given by PARAMETERS,
   which is a pointer to a struct char_print_parms.  */

void* char_print_1 (void* parameters)
{
 /* Cast the cookie pointer to the right type.  */
  struct char_print_parms* p = (struct char_print_parms*) parameters;
  int i=0;

while (i < p->count){
    sem_wait(&semaphore);
    fputc (p->character, stderr);
    ++i;
    }
  return NULL;
}

void* char_print_2 (void* parameters)
{
 /* Cast the cookie pointer to the right type.  */
  struct char_print_parms* p = (struct char_print_parms*) parameters;
  int i=0;

while (i < p->count){
    fputc (p->character, stderr);
    ++i;
    sem_post(&semaphore);
    sleep(0.500);
    }
  return NULL;
}

/* The main program.  */

int main ()
{
  sem_init(&semaphore, 0, 0);
  pthread_t thread1_id;
  pthread_t thread2_id;
  struct char_print_parms thread1_args;
  struct char_print_parms thread2_args;

  /* Create a new thread to print 2000 x's.  */
  thread1_args.character = 'x';
  thread1_args.count = 200;
  pthread_create (&thread1_id, NULL, &char_print_1, &thread1_args);
  /* Create a new thread to print 2000 o's.  */
  thread2_args.character = 'o';
  thread2_args.count = 200;
  pthread_create (&thread2_id, NULL, &char_print_2, &thread2_args);
  printf("Zaczynam czekanie\n");
  /* Make sure the first thread has finished.  */
  pthread_join (thread1_id, NULL);
  /* Make sure the second thread has finished.  */
  pthread_join (thread2_id, NULL);
  printf("\nKoncze czekanie\n");

  /* Now we can safely return.  */
  return 0;
}
