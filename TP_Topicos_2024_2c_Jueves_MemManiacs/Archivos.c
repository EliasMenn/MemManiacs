#include "Headers.h"
#define DATOS_CAMPOS 6
#include "string.h"
//voy a probar con dato
/*
int muestra_binario()
{
    DatosStruct socio;
    FILE *pbin = fopen(ARCH_BIN,"rb");
    if(!pbin){
        printf("Error de apertura de archico binario");
        return ERROR;
    }

    while(fread(&socio,sizeof(DatosStruct),1,pbin)){
        printf("%ld|%s|%d/%d/%d|%c\n",socio.dni,socio.apyn,socio.fechaNac.dia,socio.fechaNac.mes,socio.fechaNac.anio,socio.sexo);
    }

    fclose(pbin);
    return TODO_OK;
}*/

bool carga_estructura(char* registro,DatosStruct* dat)
{
    char * coma=strrchr(registro,',');
    if(coma)
        *coma='.';
    int estado=sscanf(registro,"%d|%d|\"%d\"|\"%d\"|%f|%d",&dat->Anio,&dat->Mes,&dat->CodEmp,&dat->CodProd,&dat->Precio,&dat->NumForm);
    return estado==DATOS_CAMPOS;
}
void imprimirStruct(DatosStruct* dat)
{
    printf("%d|%d|%d|%d|%f|%d",dat->Anio,dat->Mes,dat->CodEmp,dat->CodProd,dat->Precio,dat->NumForm);
}
