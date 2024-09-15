#include "..\Headers\Cadena.h"
#include "..\Headers\Normalizar.h"
#include <stdlib.h>
#include <stdio.h>
int cadenaCrear(Cadena* cad,const char* copiar,size_t tamExtra)
{
    if(!copiar)
        return NULLARG;
    const char* cursorC=copiar;
    while (*cursorC!='\0')
    {
        cursorC++;
    }
    cad->letras=cursorC-copiar;
    cad->cap=cad->letras+1+tamExtra;
    cad->cursor=cad->inicio=malloc(cad->cap);//sizeof(char)=1
    if(!cad)
    {
        cad->letras=cad->cap=0;
        return SIN_MEM;
    }
    cursorC=copiar;
    while (*cursorC!='\0')
    {
        *cad->cursor=*cursorC;
        cursorC++;
        cad->cursor++;
    }
    *cad->cursor='\0';
    cad->cursor=cad->inicio;
    return TODO_OK;
}
int cadenaComparar(const Cadena* c1,const Cadena* c2)
{
    //para discutir
    if(!(c1&&c2))
        return NULLARG;
    //pense que seria bueno poner una verificacion para ver si eran del mismo tamaño, sin embargo eso no lo veo y importante y aun asi se deberia ordenar
    //ejemplo
    //civilization
    //civilization 27
    //civilization 800
    //civilization 7
    //civilization 41
    //deberia ordenarse a
    //civilization
    //civilization 7
    //civilization 27
    //civilization 41
    //civilization 800
    const char* cursor1=c1->inicio;
    const char* cursor2=c2->inicio;
    while(*cursor1!='\0'&&*cursor2!='\0'&&(*cursor1==*cursor2))
    {
        cursor1++;
        cursor2++;
    }
    return *cursor1-*cursor2;
}
int cadenaCompararIgnorar(const Cadena* c1,const Cadena* c2)
{
    if(!(c1&&c2))
        return NULLARG;
    const char* cursor1=c1->inicio;
    const char* cursor2=c2->inicio;
    char letra1,letra2;
    //quizas se requiera una funcion que verifique que sean mayus o minus o tilde
    while((letra1=*cursor1)!='\0'&&(letra2=*cursor2)!='\0'&&((EsLetra(letra1))==(EsLetra(letra2))))
    {
        cursor1++;
        cursor2++;
    }
    return *cursor1-*cursor2;
}
size_t cadenaTamanio(const Cadena* c1)
{
//No se si va a aceptar el -1 me parece que lo va a convertir
    if(!c1)
        return -1;
    return c1->letras;
}
char* cadenaBuscarCaracter(const Cadena* cadena,char bus)
{
    if(!cadena)
        return NULL;
    const char* cursor=cadena->inicio;
    while(*cursor!='\0'&&*cursor!=bus)
    {
        cursor++;
    }
    if(*cursor!=bus)
        return NULL;
    return (char*)cursor;
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
            ultimaLugar=(char*)cursor;
        }
        cursor++;
    }
    if(*cursor==bus)
    {
        return (char*)cursor;
    }
    return ultimaLugar;
}
char* cadenaCopia(Cadena*destino,const Cadena* fuente)
{
    if(!(destino&&fuente))
        return NULL;
    if(destino->cap<fuente->letras)
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
    return destino->inicio;
}
char* cadenaConcatenar(Cadena*destino,const Cadena* fuente)
{
    if(!(destino&&fuente))
        return NULL;
    if(destino->cap<destino->letras+fuente->letras)
        return NULL;
    char* cursorD=destino->inicio+destino->letras+1;
    char* cursorF=fuente->inicio;
    while (*cursorF!='\0')
    {
        *cursorD=*cursorF;
        cursorD++;
        cursorF++;
    }
    *cursorD='\0';
    return destino->inicio;
}
int mem_cmp(const void* dir1,const void* dir2,size_t tElem)
{
    const char *cur1=dir1;
    const char *cur2=dir2;
    while(*cur1==*cur2&&tElem>0)
    {
        cur1++;
        cur2++;
        tElem--;
    }
    return *cur1-*cur2;
}
bool cadenaVaciar(Cadena* cadena)
{
    //esto no es necesario hagan la una funcion void si les parece
    if(!cadena)
        return false;
    cadena->letras=cadena->cap=0;
    free(cadena->inicio);
    cadena->inicio=cadena->cursor=NULL;
    return true;
}
int cadenaCursorCambiarCararacter(Cadena* cadena,char car)
{
    //'\0' es el caracter NULO
    //!cadena da verdadero si es NULL
    if(!cadena||*cadena->cursor=='\0')
        return NULLARG;
    *cadena->cursor=car;
    return TODO_OK;
}
bool cadenaCursorReiniciar(Cadena* cad)
{
    if(!cad)
        return false;
    cad->cursor=cad->inicio;
    return true;
}
bool cadenaCursorMoverPos(Cadena* cad,size_t mov)
{
    if(!cad||cad->inicio+cad->letras+1<cad->cursor+mov)
        return false;
    cad->cursor+=mov;
    return true;
}
bool cadenaCursorEsElem(Cadena* cad,char car)
{
    if(!cad)
        return false;
    return *cad->cursor==car;
}
bool cadenaCursorMoverAElem(Cadena* cad,char car)
{
    if(!cad)
        return false;
    while (*cad->cursor!='\0'&&*cad->cursor!=car)
    {
        cad->cursor++;
    }
    return *cad->cursor==car;
}
bool cadenaCursorMoverAElemIni(Cadena* cad,char car)
{
    if(!cad)
        return false;
    cad->cursor=cad->inicio;
    while (*cad->cursor!='\0'&&*cad->cursor!=car)
    {
        cad->cursor++;
    }
    return *cad->cursor==car;
}
bool cadenaAnadirCaracter(Cadena* cad,char car)
{
    if(cad->letras+1==cad->cap||!cad)
        return false;
    cad->cursor=cad->inicio+cad->letras+1;
    *cad->cursor=car;
    cad->cursor++;
    cad->cursor='\0';
    return true;
}
char* cadenaConcatenarLimite(Cadena* destino,const Cadena* fuente,size_t BytesACopiar)
{
    if(!destino||destino->cap<BytesACopiar)
        return NULL;
    const char *curF=fuente->inicio;
    char *curD=destino->inicio+destino->letras+1;
    while(*curF!='\0'&&BytesACopiar>0)
    {
        *curD=*curF;
        curD++;
        curF++;
        BytesACopiar--;
    }
    *curD='\0';
    return destino->inicio;
}
bool cadenaMostrar(const Cadena* cad)
{
    if(!cad)
        return false;
    puts(cad->inicio);
    return true;
}
bool cadenaCursorMostrar(const Cadena* cad)
{
    if(!cad)
        return false;
    printf("La posicion del cursor es en %I64d\n",cad->cursor-cad->inicio+1);
    return true;
}
