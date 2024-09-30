#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    volatile long long i;
    //for (i = 0; i < 1000000000LL; i++);
    while(1);
    printf("Processo de ID %d terminou a execução.\n", getpid());
    return 0;
}
