#include "..\Headers\String.h"
#include <stdlib.h>
#define NULLARG 1
#define SIN_MEM 2
#define TODO_OK 0
int cadenaCrear(Cadena* cad,const* copiar)
{
    if(!copiar)
        return NULLARG;
    const char* cursorC=copiar;
    while (*cursorC!='\0')
    {
        cursorC++;
    }
    cad->letras=cursorC-copiar+1;
    cad->inicio=malloc(cad->letras);//sizeof(char)=1
    if(!cad)
    {
        cad->letras=0;
        return SIN_MEM;
    }
    cad->cap=cad->letras+10;
    return TODO_OK;
}
int cadenaComparar(const Cadena* c1,const Cadena* c2)
{
    //para discutir
    if(!(c1&&c2))
        return -404;
    const char* cursor1=c1->inicio;
    const char* cursor2=c2->inicio;
    while(*cursor1!='\0'&&*cursor2!='\0'&&(*cursor1-*cursor2)==0)
    {
        cursor1++;
        cursor2++;
    }
    return *cursor1-*cursor2;
}
int cadenaCompararIgnorar(const Cadena* c1,const Cadena* c2)
{
    if(!(c1&&c2))
        return -404;
    const char* cursor1=c1->inicio;
    const char* cursor2=c2->inicio;
    //quizas se requiera una funcion que verifique que sean mayus o minus o tilde
    while(*cursor1!='\0'&&*cursor2!='\0'&&(EsLetra(*cursor1)-EsLetra(*cursor2)==0))
    {
        cursor1++;
        cursor2++;
    }
    return *cursor1-*cursor2;
}
size_t cadenaTamanio(const Cadena* c1)
{
    //porque no genera error?
    if(!c1)
        return -1;
    const char* cursor=c1->inicio;
    while (*cursor!='\0')
    {
        cursor++;
    }
    return cursor-c1;
}
char* cadenaBuscarCaracter(const Cadena* cadena,char bus)
{
    if(!cadena)
        return NULL;
    const char* cursor=cadena->inicio;
    while(*cursor!=bus)
    {
        cursor++;
    }
    if(*cursor!=bus)
        return NULL;
    return cursor;
}
char* cadenaBuscarCaracterFin(const Cadena* cadena,char bus)
{
    if(!cadena)
        return NULL;
    const char* cursor=cadena->inicio;
    char* ultimaLugar=NULL;
    while(*cursor!='\0')
    {
        if(*cursor==bus)
        {
            ultimaLugar=cursor;
        }
        cursor++;
    }
    if(*cursor==bus)
    {
        return cursor;
    }
    return ultimaLugar;
}
char* cadenaCopia(Cadena*destino,const Cadena* fuente)
{
    if(!(destino&&fuente))
        return NULL;
    if(destino->cap<fuente->cap)
        return NULL;
    char* cursorD=destino->inicio;
    char* cursorF=fuente->inicio;
    while (*cursorF!='\0')
    {
        *cursorD=*cursorF;
        cursorD++;
        cursorF++;
    }
    *cursorD='\0';
    destino->letras=fuente->letras;
    return destino;
}
char* cadenaConcatenar(Cadena*destino,const Cadena* fuente)
{
    if(!(destino&&fuente))
        return NULL;
    if(destino->cap<destino->letras+fuente->letras)
        return NULL;
    char* cursorD=destino->inicio;
    char* cursorF=fuente->inicio;
    while (*cursorD!='\0')
    {
        cursorD++;
    }
    while (*cursorF!='\0')
    {
        *cursorD=*cursorF;
        *cursorD++;
        cursorF++;
    }
    *cursorD='\0';
    return destino;
}
//para hacer memcpy
//memmove?