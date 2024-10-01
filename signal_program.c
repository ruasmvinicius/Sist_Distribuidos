#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

// Variável global para contar o número de sinais recebidos
sig_atomic_t sigusr1_count = 0;

// Manipulador de sinal para SIGUSR1
void handler(int signal_number) {
    if (signal_number == SIGUSR1) {
        sigusr1_count++;
    }
}

int main() {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handler;
    
    // Configura o manipulador para SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Laço de 30.000 iterações com pausas de 10 milissegundos
    for (int i = 0; i < 30000; i++) {
        usleep(10000); // Pausa por 10 milissegundos
    }

    // Imprime o valor da variável global
    printf("SIGUSR1 foi chamado %d vezes\n", sigusr1_count);

    return 0;
}
