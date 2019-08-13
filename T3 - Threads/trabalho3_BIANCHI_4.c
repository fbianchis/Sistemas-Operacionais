#include <stdio.h> 
#include <unistd.h>
#include <pthread.h>
#define TAM_MAX 1000000000
#define PASSO 250000000

double vet[4] = {0.0,0.0,0.0,0.0};

void* contador (void* identificador)
{
    int tid;
    double a;
    long int i;
    tid = (int)identificador;
    if(tid == 0) 
    {
        for(i=0;i<=PASSO;i++)
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
    else if (tid == 1)
    {
        for(i=PASSO+1;i<=2*PASSO;i++)
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
    else if (tid == 2)
    {
        for(i=(2*PASSO)+1;i<=(3*PASSO);i++)
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
        for(i=(3*PASSO)+1;i<=TAM_MAX;i++)
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
    pthread_t identificador_t[4]; 
    double resp;
    for(j=0;j<4;j++)
    {
        pthread_create(&identificador_t[j],NULL,contador,(void*)j); //criar as threads
    }
    for(j=0;j<4;j++)
    {
        pthread_join(identificador_t[j],NULL); //aguardar o termino das threads
    }

    resp = 4*(vet[0]+vet[1]+vet[2]+vet[3]);
    printf("O resultado foi:%lf \n",resp);

}