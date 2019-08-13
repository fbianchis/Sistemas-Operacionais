#include <stdio.h> 
#include <unistd.h>
#include <pthread.h>
#define TAM_MAX 1000000000

double vet[2] = {0.,0.};

void* contador (void* identificador)
{
    int tid;
    double a;
    long int i;
    tid = (int)identificador;
    if(tid)
    {
        for(i=0;i<TAM_MAX/2;i++)
        {
            a = (1.0/(2*i+1));
            if(i % 2 == 0)
            {
                vet[tid] = vet[tid] + a ;
            }
            else
            {
                vet[tid] = vet[tid] - a ;
            }
        }
    }
    else
    {
        for(i=(TAM_MAX/2+1);i<=TAM_MAX;i++)
        {
            a = (1.0/(2*i+1));
            if(i % 2 == 0)
            {
                vet[tid] = vet[tid] + a ;
            }
            else
            {
                vet[tid] = vet[tid] - a ;
            }
        }
    }
    
    return NULL;
}

int main (void)
{
    int j;
    pthread_t identificador_t[2]; 
    double resp;
    for(j=0;j<2;j++)
    {
        pthread_create(&identificador_t[j],NULL,contador,(void*)j); //criar as threads
    }
    pthread_join(identificador_t[0],NULL); //aguardar o termino da primeira thread
    pthread_join(identificador_t[1],NULL); //aguardar o termino da segunda thread

    resp = 4*(vet[0]+vet[1]);
    printf("O resultado foi:%lf \n",resp);

}