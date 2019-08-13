#include <stdio.h> 
#include <unistd.h>
#include <pthread.h>
#define TAM_MAX 1000000000
#define PASSO 62500000

double vet[16] = {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

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
    else if(tid == 3)
    {
        for(i=(3*PASSO)+1;i<=4*PASSO;i++)
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
    else if (tid == 4)
    {
        for(i=4*PASSO+1;i<=5*PASSO;i++)
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
    else if (tid == 5)
    {
        for(i=(5*PASSO)+1;i<=(6*PASSO);i++)
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
    else if(tid == 6)
    {
        for(i=(6*PASSO)+1;i<=7*PASSO;i++)
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
    else if (tid == 8)
    {
        for(i=(7*PASSO)+1;i<=8*PASSO;i++)
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
    else if (tid == 9)
    {
        for(i=8*PASSO+1;i<=9*PASSO;i++)
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
    else if (tid == 10)
    {
        for(i=(9*PASSO)+1;i<=(10*PASSO);i++)
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
    else if(tid == 11)
    {
        for(i=(10*PASSO)+1;i<=11*PASSO;i++)
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
    else if (tid == 12)
    {
        for(i=11*PASSO+1;i<=12*PASSO;i++)
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
    else if (tid == 13)
    {
        for(i=(12*PASSO)+1;i<=(13*PASSO);i++)
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
    else if(tid == 14)
    {
        for(i=(13*PASSO)+1;i<=14*PASSO;i++)
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
        for(i=(14*PASSO)+1;i<=TAM_MAX;i++)
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
    pthread_t identificador_t[16]; 
    double resp = 0.0;
    for(j=0;j<16;j++)
    {
        pthread_create(&identificador_t[j],NULL,contador,(void*)j); //criar as threads
    }
    for(j=0;j<16;j++)
    {
        pthread_join(identificador_t[j],NULL); //aguardar o termino das threads
    }
    for(j=0;j<16;j++)
    {
        resp = resp + vet[j];
    }
    printf("O resultado foi:%lf \n",4*resp);

}