#include "Headers.h"
#define CAP_INI 10
#define FACTINC 1.5
bool redimensionarVector(Vector* vec,size_t nTam);
//quizas convenga mas hacer un header especifico para el vector
bool vectorCrear(Vector* vec,size_t tElem)
{
    //reserva una direccion de memoria de 10 elementos del tamaño de los elementos
    vec->vec=malloc(CAP_INI*tElem);
    vec->ce=0;
    //si no se reservo se va a casa
    if(!vec->vec)
        return false;
    vec->cap=CAP_INI;
    vec->tElem=tElem;
    return true;
}
bool vectorDestruir(Vector* vec)
{
    //quita la memoria reservada
    free(vec->vec);
    vec->vec=NULL;
    vec->cap=vec->ce=vec->tElem=0;
    return true;
}
bool vectorVaciar(Vector* vec)
{
    //tecnicamente lo que no se considera basura depende de vec->ce asi que simplemente se pone en 0
    vec->ce=0;
    //esto para devolver memoria creo que al redimensionar a algo mas pequeño no deberia fallar
    vec->cap=CAP_INI;
    bool estado=redimensionarVector(vec,CAP_INI);
    return estado;    
}
//lo vimos en clase
bool redimensionarVector(Vector* vec,size_t nTam)
{
    void * nvec=realloc(vec->vec,nTam*vec->tElem);
    if(!nvec)
        return false;
    vec->vec=nvec;
    vec->cap=nTam;
    return true;
}
//esto puede ser util
bool vectorOrdenadoBuscar(const Vector* vec,void* elemABus,COMPARE cmp)
{
    void*fin=vec->vec+(vec->ce-1)*vec->tElem;
    void* i=vec->vec;
    while(i<=fin&&cmp(elemABus,i)>0)
        i+=vec->tElem;
    //poner !=0 da lo mismo igual
    if(i>fin||cmp(elemABus,i)<0)
        return false;
    memcpy(elemABus,i,vec->tElem);
    return true;
}
//esto tambien
void vectorRecorrer(const Vector* vec,Accion accion,void* datos)
{
    void*fin=vec->vec+(vec->ce-1)*vec->tElem;
    void* i;
    for(i=vec->vec;i<fin;i+=vec->tElem)
        accion(i,datos);
}
//creo que conviene mas insertalo al final y luego ordenarlo que hacer un ordenado insertado porque va a ser mas rapido
bool vectorInsertarFin(Vector* vec,void* dato)
{
    if(vec->ce==vec->cap)
    {
        if(!redimensionarVector(vec,vec->cap*FACTINC))
            return false;
    }
    void*fin=vec->vec+(vec->ce)*vec->tElem;
    void*i=vec->vec;
    //nota quizas convenga hacer una version que no acepte duplicados, depende del criterio de la persona preguntar al profe
    while (i<fin)
        i+=vec->tElem;
    memcpy(i,dato,vec->tElem);
    return true;
}