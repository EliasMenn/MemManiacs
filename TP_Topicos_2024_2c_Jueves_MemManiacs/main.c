#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Headers\Normalizar.h"
void ejemplotilde(char car);
long long potencia(int base,int exp);
int main()
{
    //importantisimo sirve para las tildes
    system("chcp 1252 >nul");
    //esto es lo del tiempo
    clock_t start, end;
    float elapsed_time;
    start = clock();
    for(long long i=0;i<10000/*potencia(2,63)-1*/;i=i+1)
    {
        if(i%1==0)
            printf("Div 1\n");
        if(i%2==0)
            printf("Div 2\n");
        if(i%5==0)
            printf("Div 5\n");
        printf("i= %I64d\n",i);
    }
    end = clock();
    elapsed_time = (float)(end - start) / CLOCKS_PER_SEC;
    printf("%ld, %ld\n",end,start);
    printf("Elapsed time: %f seconds\n", elapsed_time);
    return 0;
}
void ejemplotilde(char car)
{
    printf("%c, %d\n",car,car);
}
//nota esta hecha lenta a proposito
long long potencia(int base,int exp)
{
    long long res;
    for(int i=2;i<exp;i++)
    {
        if(i==2)
        {
            res=1;
        }
        res*=base;
    }
    return res;
}
