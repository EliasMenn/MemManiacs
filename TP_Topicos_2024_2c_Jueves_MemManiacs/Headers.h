#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int Anio;
    int Mes;
    int CodEmp;
    int CodProd;
    float Precio;
    int NumForm;
}DatosStruct;

int assfile();

#endif // HEADERS_H_INCLUDED
