#include <stdio.h>
#include <stdlib.h>

#include "Headers.h"

int main()
{
    //printf("Hello MemManiacs!\n");
    //int estado=assfile();
    FILE* arch=fopen("files\\DATOS.txt","rb");
    if(arch==NULL);
    DatosStruct dat;
    char buffer[256];
    fgets(buffer,256,arch);
    fclose(arch);
    carga_estructura(buffer,dat);
    imprimirStruct(dat);
    return 0;
}
