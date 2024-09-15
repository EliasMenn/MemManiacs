#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Headers\Normalizar.h"
#include "Headers\Cadena.h"
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
    //empieza el contador
    Cadena cad1;
    if(cadenaCrear(&cad1,"Holi",10)!=TODO_OK)
        return -1;
    Cadena cad2;
    if(cadenaCrear(&cad2,"Chauchis",10)!=TODO_OK)
        return -2;
    cadenaMostrar(&cad1);
    cadenaCursorMostrar(&cad1);
    cadenaCopia(&cad1,&cad2);
    cadenaCursorMoverPos(&cad1,4);
    cadenaMostrar(&cad1);
    cadenaCursorMostrar(&cad1);
    cadenaVaciar(&cad1);
    cadenaVaciar(&cad2);
    //termina el contador
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

