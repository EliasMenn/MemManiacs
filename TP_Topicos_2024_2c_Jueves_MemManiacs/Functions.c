#include "Headers.h"

int assfile()
{
    FILE* arch;
    int size;
    arch = fopen("files\\DATOS.txt","rb");
    if(arch == NULL)
    {
        printf("Error opening");
        exit(1);
    }
    fseek(arch,0,SEEK_END);
    size = ftell(arch);
    char *start, *end; //Utilizaremos 2 punteros de tipo char, el primero nos marcara el comienzo de la memoria asignada, el segundo el final
    start = malloc(size); //utilizamos el tamaño de archivo en bytes para asignar memoria
    if (start == NULL)
    {
        printf("Error al momento de asignar memoria");
        exit(2);
    }
    end = start+size;
    printf("%p, %p", start, end);
    free(start);
    return 0;
}
