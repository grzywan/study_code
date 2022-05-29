#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;

struct char_print_parms
{
  /* The character to print.  */
  char character;
  /* The number of times to print it.  */
  int count;
};

/* Prints a number of characters to stderr, as given by PARAMETERS,
   which is a pointer to a struct char_print_parms.  */

void* char_print (void* parameters)
{
 /* Cast the cookie pointer to the right type.  */
  struct char_print_parms* p = (struct char_print_parms*) parameters;
  int i;
  for (i = 0; i < p->count; ++i){
    sleep(0.5);
    pthread_mutex_lock(&mutex);
    sleep(0.5);
    fputc (p->character, stderr);
    pthread_mutex_unlock(&mutex);
    sleep(0.5);
    }
  return NULL;
}

/* The main program.  */

int main ()
{
  pthread_mutex_init(&mutex,NULL);
  pthread_t thread1_id;
  pthread_t thread2_id;
  struct char_print_parms thread1_args;
  struct char_print_parms thread2_args;

  /* Create a new thread to print 2000 x's.  */
  thread1_args.character = 'x';
  thread1_args.count = 1000;
  pthread_create (&thread1_id, NULL, &char_print, &thread1_args);

  /* Create a new thread to print 2000 o's.  */
  thread2_args.character = 'o';
  thread2_args.count = 1000;
  pthread_create (&thread2_id, NULL, &char_print, &thread2_args);

  printf("Zaczynam czekanie\n");
  /* Make sure the first thread has finished.  */
  pthread_join (thread1_id, NULL);
  /* Make sure the second thread has finished.  */
  pthread_join (thread2_id, NULL);
  printf("\nKoncze czekanie\n");
  pthread_mutex_destroy(&mutex);
  /* Now we can safely return.  */
  return 0;
}

