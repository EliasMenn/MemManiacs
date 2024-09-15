#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
#include <stddef.h>
#include <stdbool.h>
#define NULLARG 1
#define SIN_MEM 2
#define TODO_OK 0
//esto ya es un vector pero me gusta que se llame cadena
//el campo de cursor no sirve para nada si lo pones como const y consideraba ponerlo en const mas importante
typedef struct
{
    char* inicio;
    char* cursor;
    size_t letras;
    size_t cap;
}
Cadena;
//caracteristicas
//inicio siempre apunta al inicio de la cadena NO DEBE MODIFICARSE
//cursor Es un cursor de la palabra nunca deberia ser mayor que inicio+cap
//letras es la cantidad de caracteres no nulos
//cap es la capacidad en memoria es letras mas una cantidad especificada
//no deberia haber una funcion para redimensionar la cadena
//esto es para diferenciarla de los vectores
//se usaria primero cadenaCrear y luego cadenaVaciar y asi en un ciclo
int cadenaCrear(Cadena* cad,const char* copiar,size_t tamExtra);
bool cadenaVaciar(Cadena* cadena);
bool cadenaMostrar(const Cadena* cad);
bool cadenaCursorMostrar(const Cadena* cad);

char* cadenaConcatenar(Cadena*destino,const Cadena* fuente);
char* cadenaConcatenarLimite(Cadena* destino,const Cadena* fuente,size_t BytesACopiar);
size_t cadenaTamanio(const Cadena* c1);
char * cadenaBuscarCaracter(const Cadena*cadena,char bus);
char * cadenaBuscarCaracterFin(const Cadena*cadena,char bus);

char* cadenaCopia(Cadena*destino,const Cadena* fuente);
bool cadenaAnadirCaracter(Cadena* cad,char car);
//>0 s1 mas grande
//=0 iguales
//<0 s2 mas grande
int cadenaComparar(const Cadena* c1,const Cadena* c2);
int cadenaCompararIgnorar(const Cadena* c1,const Cadena* c2);

bool cadenaCursorReiniciar(Cadena* cad);
int cadenaCursorCambiarCararacter(Cadena* cadena,char car);
bool cadenaCursorMoverPos(Cadena* cad,size_t mov);
bool cadenaCursorEsElem(Cadena* cad,char car);
bool cadenaCursorMoverAElem(Cadena* cad,char car);
bool cadenaCursorMoverAElemIni(Cadena* cad,char car);

int mem_cmp(const void* dir1,const void* dir2,size_t tElem);
#endif // CADENA_H_INCLUDED
