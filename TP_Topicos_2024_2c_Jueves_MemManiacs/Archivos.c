#include "Headers.h"
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

void carga_estructura(const char* registro,DatosStruct* dat)
{
    const char* auxc=registro;
    DatosStruct auxd=*dat;
    sscanf(registro,"%d|%d|%d|%d|%f|%d",&dat->Anio,&dat->Mes,&dat->CodEmp,&dat->CodProd,&dat->Precio,&dat->NumForm);
    auxd=*dat;
}
void imprimirStruct(DatosStruct* dat)
{
    DatosStruct auxd=*dat;
    printf("%d|%d|%d|%d|%f|%d",dat->Anio,dat->Mes,dat->CodEmp,dat->CodProd,dat->Precio,dat->NumForm);
}