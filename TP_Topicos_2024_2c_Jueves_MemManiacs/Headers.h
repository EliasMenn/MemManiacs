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

#define TAMNOMPROD 50
#define TAMESPE 250
//tda Vector con Null todavia no se dio
typedef struct
{
    void* vec;
    size_t ce;
    size_t cap;
    size_t tElem;
}
Vector;
//struct especificaciones pertenece a la parte de especificaciones
typedef struct
{
    int CodProd;
    char NomProd[TAMNOMPROD];
    char Especificacion[TAMESPE];
}
Especificaciones;
//tipo de funcion comparacion se debe hacer una funcion que tenga la misma estructura(struct ja)
typedef int (COMPARE)(const void* e1,const void* e2);
//ordenamientoSeleccion
void ordenamientoSeleccion(Vector* vec,CMP cmpCampo1,CMP cmpCampo2);
void* BuscarElemMenor(void* inicio,void* fin,size_t tamElem,CMP cmpCampo1,CMP cmpCampo2);
void Intercambio(void*e1,void* menor,size_t tamElem);
int cmpCodProd(const void* e1,const void* e2);
int cmpCodEmp(const void* e1,const void* e2);
//ordenamientoInsersion
void ordenamientoInserccion(Vector* vec,CMP cmpCampo1);
int cmpCodProdEspe(const void* e1,const void* e2);
#endif // HEADERS_H_INCLUDED