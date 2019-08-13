#include <stdio.h> 
#include <unistd.h>
#include <pthread.h>
#define TAM_MAX 1000000000

double vet = 0.0;

void* contador (void* identificador)
{
    int tid;
    double a;
    long int i;
    tid = (int)identificador;
    for(i=0;i<=TAM_MAX;i++)
    {
        a = (1.0/(2*i+1));
        if(i % 2 == 0)
        {
            vet = vet + a ;
        }
        else
        {
            vet = vet - a ;
        }
    }
    
    return NULL;
}

int main (void)
{
    int j;
    pthread_t identificador_t;
    double resp;

    pthread_create(&identificador_t,NULL,contador,(void*)j); //criar a thread

    pthread_join(identificador_t,NULL); //aguardar o termino da thread

    resp = 4*vet;
    printf("O resultado foi:%lf \n",resp);

}