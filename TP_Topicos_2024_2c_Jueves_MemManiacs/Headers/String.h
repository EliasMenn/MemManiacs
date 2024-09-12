#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
//esto ya es un vector pero me gusta que se llame cadena
//el campo de cursor no sirve para nada si lo pones como const y consideraba ponerlo en const mas importante
typedef struct
{
    char* inicio;
    size_t letras;
    size_t cap;
}
Cadena;
char* cadenaConcatenar(Cadena*destino,const Cadena* fuente);
int cadenaCrear(Cadena* cad,Cadena* copiar);

char* cadenaCopia(Cadena*destino,const Cadena* fuente);

size_t cadenaTamanio(const Cadena* c1);
char * cadenaBuscarCaracter(const Cadena*cadena,char bus);
char * cadenaBuscarCaracterFin(const Cadena*cadena,char bus);

//>0 s1 mas grande
//=0 iguales
//<0 s2 mas grande
int cadenaComparar(const Cadena* c1,const Cadena* c2);
int cadenaCompararIgnorar(const Cadena* c1,const Cadena* c2);
#endif // STRING_H_INCLUDED
