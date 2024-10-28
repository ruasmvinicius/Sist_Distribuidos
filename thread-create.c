#include <pthread.h>
#include <stdio.h>
/* Imprime x's para stderr. O parâmetro não é usado. Não retorna. */
void* print_xs (void* unused)
{
 while (1)
 fputc ('x', stderr);
 return NULL;
}
/* O programa principal. */
int main ()
{
 pthread_t thread_id;
/* Cria uma nova thread. A nova thread executará a função print_xs. */
pthread_create (&thread_id, NULL, &print_xs, NULL);
/* Imprime o's continuamente para stderr. */
 while (1)
 fputc ('o', stderr);
 return 0;
}
