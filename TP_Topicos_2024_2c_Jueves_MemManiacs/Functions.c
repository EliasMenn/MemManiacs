#include "Headers.h"

bool assfile()
{
    FILE* arch;
    int size;
    arch = fopen("files\\DATOS.txt","rb");
    if(arch == NULL)
    {
        printf("Error opening");
        return false;
    }
    fseek(arch,0,SEEK_END);
    size = ftell(arch);
    char *start, *end; //Utilizaremos 2 punteros de tipo char, el primero nos marcara el comienzo de la memoria asignada, el segundo el final
    start = malloc(size); //utilizamos el tama�o de archivo en bytes para asignar memoria
    if (start == NULL)
    {
        fclose(arch);
        printf("Error al momento de asignar memoria");
        //cambie por un return porque el exit sale del programa
        return false;
    }
    //si no se pone el menos 1 entonces se pasa de la memoria alocada
    end = start+size-1;
    printf("%p, %p", start, end);
    free(start);
    return true;
}