#include <pthread.h>
#include <stdio.h>
/* Parametros para a função de imprimir. */
struct char_print_parms
{
 /* O caracter a ser impresso. */
 char character;
/* A quantidade de vezes para imprimí-lo. */
 int count;
};
/* Imprime uma quantidade de caracteres para stderr, conforme dado por PARAMETERS,
que é um ponteiro para uma estrutura char_print_parms. */
void* char_print (void* parameters)
{
/* Cast do ponteiro para o tipo correto. */
struct char_print_parms* p = (struct char_print_parms*) parameters;
 int i;
for (i = 0; i < p->count; ++i)
 fputc (p->character, stderr);
 return NULL;
}
/* O programa principal. */
int main ()
{
 pthread_t thread1_id;
 pthread_t thread2_id;
 struct char_print_parms thread1_args;
 struct char_print_parms thread2_args;
/* Cria um novo thread para imprimir 30000 x's. */
 thread1_args.character = 'x';
 thread1_args.count = 30000;
pthread_create (&thread1_id, NULL, &char_print, &thread1_args);
/* Cria um novo thread para imprimir 20000 o's. */
 thread2_args.character = 'o';
 thread2_args.count = 20000;
pthread_create (&thread2_id, NULL, &char_print, &thread2_args);

/* Certifique-se de que a primeira thread terminou. */
 pthread_join (thread1_id, NULL);
/* Certifique-se de que a segunda thread terminou. */
 pthread_join (thread2_id, NULL);
/* Agora podemos retornar de forma segura. */
 return 0;
}
