/*******************************************************************
* PID                                                              *
* O tipo pid_t é definido em <sys/types.h> para referenciar PIDs   *
* Um programa pode obter seu PID executando a chamada de           *
* sistema getpid()                                                 *
* Um programa pode obter o PID de seu pai executando a chamada     *
* de sistema getppid()                                             *
*******************************************************************/

#include <stdio.h>
#include <unistd.h>

int main ()
{
printf ("O id do processo é %d\n", (int) getpid ());
printf ("O id do pai do processo é %d\n", (int) getppid ());
return 0;
}
