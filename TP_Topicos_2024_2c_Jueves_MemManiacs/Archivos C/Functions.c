#include "../Headers/Headers.h"
#define ERR_ARCH -1
#define ERR_MEM -2
#define TODO_OK 0
int assfile()
{
    FILE* arch= fopen("files\\DATOS.txt","rb");
    if(arch == NULL)
    {
        puts("Error opening");
        return ERR_ARCH;
    }
    fseek(arch,0,SEEK_END);
    int size = ftell(arch);
    char *start; //Utilizaremos 2 punteros de tipo char, el primero nos marcara el comienzo de la memoria asignada, el segundo el final
    start = malloc(size); //utilizamos el tama�o de archivo en bytes para asignar memoria
    if (start == NULL)
    {
        fclose(arch);
        puts("Error al momento de asignar memoria");
        //cambie por un return porque el exit sale del programa
        return ERR_MEM;
    }
    //si no se pone el menos 1 entonces se pasa de la memoria alocada
    char* end = start+size-1;
    printf("%p, %p\n", start, end);
    puts("Todo OK\n");
    fclose(arch);
    free(start);
    return TODO_OK;
}