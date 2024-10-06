#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
     char *arg_list[] = {"ls", "-l", "/", NULL};

    pid_t child_pid = fork();

    if (child_pid == 0) {
        /* Este é o processo filho. */
        printf("Processo filho/n");
        execvp(arg_list[0], arg_list);
        exit(1);
    } else {
        /* Este é o processo pai. Dorme por um minuto. */
        //sleep(60);
        printf("Processo pai/n");
        exit(0);
    }
    printf("Finalizando.../n");
    return 0;
}
