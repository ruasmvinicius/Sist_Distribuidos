#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int child_status;
    char *arg_list[] = {"ls", "-l", "/", NULL};

    /* Cria um processo filho para executar o comando "ls". */
    pid_t child_pid = fork();
    
    if (child_pid == 0) {
        /* Este é o processo filho. */
        execvp(arg_list[0], arg_list);
        /* Se execvp falhar, sair com erro. */
        exit(1);
    } else {
        /* Este é o processo pai. Espera o filho completar. */
        wait(&child_status);
        if (WIFEXITED(child_status)) {
            printf("O processo filho encerrou normalmente, com código de saída %d\n", WEXITSTATUS(child_status));
        } else {
            printf("O processo filho terminou com erro.\n");
        }
    }
    return 0;
}
