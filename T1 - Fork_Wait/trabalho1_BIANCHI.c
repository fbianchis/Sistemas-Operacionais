#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void conta (void)
{
    int j;
    for(j=0;j<5;j++)
    {
        printf("\n");
    }
}


int main (void)
{
    pid_t pid_filho = 0;
    pid_t pid_neto = 0;
    int i;
    char identificador = 65;

    for (i=1;i<=3;i++)
    {
        pid_filho = fork();
        if(pid_filho>0) //condição para que somente o processo pai entre
        {
            printf("Olá eu sou o processo pai %c, meu PID eh: %ld \n",identificador,(long int)getpid());
            waitpid(pid_filho,NULL,WUNTRACED);
        }
        else //condição que somente os processos filhos consigam entrar
        {
            if(i >= 2)
            {
                identificador = identificador + i + 1;
            }
            else
            {
                identificador = identificador + i;

            }
            printf("Olá eu sou o processo filho %c, meu pai eh: %ld e eu sou: %ld \n",identificador,(long int)getppid(),(long int)getpid());
            if(identificador == 66)
            {
                if((pid_neto = fork())>0)
                {
                    printf("Olá eu sou o processo pai %c, meu PID eh: %ld \n",identificador,(long int)getpid());
                    waitpid(pid_neto,NULL,WUNTRACED);
                }
                else
                {
                    identificador++;
                    printf("Olá eu sou o processo filho %c, meu pai eh: %ld e eu sou: %ld \n",identificador,(long int)getppid(),(long int)getpid());
                    conta();
                    printf("Eu vou partir agora, não se esqueça eu sou o processo %c, meu PID:%ld e meu pai: %ld \n",identificador,(long int)getpid(),(long int)getppid());
                    exit(1);
                }
                
            }
            else if(identificador == 69)
            {
                if((pid_neto = fork())>0)
                {
                    printf("Olá eu sou o processo pai %c, meu PID eh: %ld \n",identificador,(long int)getpid());
                    waitpid(pid_neto,NULL,WUNTRACED);
                }
                else
                {
                    identificador++;
                    printf("Olá eu sou o processo filho %c, meu pai eh: %ld e eu sou: %ld \n",identificador,(long int)getppid(),(long int)getpid());
                    if((pid_neto = fork())>0)
                    {
                        printf("\tOlá eu sou o processo pai %c, meu PID eh: %ld \n",identificador,(long int)getpid());
                        waitpid(pid_neto,NULL,WUNTRACED);
                    }
                    else
                    {
                        identificador++;
                        printf("Olá eu sou o processo filho %c, meu pai eh: %ld e eu sou: %ld \n",identificador,(long int)getppid(),(long int)getpid());
                        conta();
                        printf("Eu vou partir agora, não se esqueça eu sou o processo %c, meu PID:%ld e meu pai: %ld \n",identificador,(long int)getpid(),(long int)getppid());
                        exit(1);
                    }
                    conta();
                    printf("Eu vou partir agora, não se esqueça eu sou o processo %c, meu PID:%ld e meu pai: %ld \n",identificador,(long int)getpid(),(long int)getppid());
                    exit(1);
                }
            }
            conta();
            printf("Eu vou partir agora, não se esqueça eu sou o processo %c, meu PID:%ld e meu pai: %ld \n",identificador,(long int)getpid(),(long int)getppid());
            exit(1);
        }
    }
    printf("Agora que ele se foi, vou também, sou o processo %c,meu pid: %ld\n",identificador,(long int)getpid());
}