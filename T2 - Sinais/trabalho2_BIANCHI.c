#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
int contador = 0;
char decide;
void trata_ctrl_c (int signum)
{
    if ((contador++) >= 10)
    {
        alarm(5);
        printf("\nDeseja sair?(Y/N):");
        scanf(" %c",&decide);
        printf("\n");
        if(decide == 'Y')
        {
            raise(SIGKILL);
        }
        else 
        {
            contador = 0 ;
            alarm(0);
        }
    }
    /*else
    {
        contador++;
    }*/
        
}
void trata_crtl_z(int signum2)
{   
    printf("QTD: %d\n",contador);
}
int main(void)
{
    signal(SIGINT,trata_ctrl_c);
    signal(SIGTSTP,trata_crtl_z);
    while(1);
}