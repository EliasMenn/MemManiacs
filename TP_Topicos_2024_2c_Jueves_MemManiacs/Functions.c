#include "Headers.h"

int assfile()
{
    FILE* arch;
    int size;
    arch = fopen("files\\DATOS.txt","rb");
    if(arch == NULL)
    {
        printf("Error opening");
        exit(1);
    }
    fseek(arch,0,SEEK_END);
    size = ftell(arch);
    char *start, *end; //Utilizaremos 2 punteros de tipo char, el primero nos marcara el comienzo de la memoria asignada, el segundo el final
    start = malloc(size); //utilizamos el tama�o de archivo en bytes para asignar memoria
    if (start == NULL)
    {
        printf("Error al momento de asignar memoria");
        exit(2);
    }
    end = start+size;
    printf("%p, %p", start, end);
    free(start);
    return 0;
}
//funcion de ordenamiento
void ordenamientoSeleccion(Vector* vec,COMPARE cmpCampo1,COMPARE cmpCampo2)
{
    void * fin=vec->vec+(vec->ce-1)*vec->tElem;
    void * i;
    void * menor;
    //quizas se podria hacer mas rapido si se hace i<fin sea mas rapido
    //si se hace eso se deberia hacer vec->ce*vec->tElem
    for(i=vec->vec;i<=fin;i+=vec->tElem)
    {
        //busca el elemento a selecionar//se envia fin para que no haga el calculo de donde esta fin cada vez
        menor=BuscarElemMenor(i,fin,vec->tElem,cmpCampo1,cmpCampo2);
        //se hace un intercambio
        Intercambio(i,menor,vec->tElem);
    }
}
void* BuscarElemMenor(void* inicio,void* fin,size_t tamElem,COMPARE cmpCampo1,COMPARE cmpCampo2)
{
    void* i;
    //elige el primero
    void* menor=inicio;
    //se inicia el iterador i en el siguiente de inicio porque ya se paso por inicio
    for(i=inicio+=tamElem;i<=fin;i+=tamElem)
    {
        if(cmpCampo1(inicio,i)<0||(cmpCampo1(inicio,i)==0&&cmpCampo2<0))
            menor=i;
    }
    return menor;
}
void Intercambio(void*e1,void* e2,size_t tamElem)
{
    //esto podria fallar no me acuerdo si habia un metodo para el intercambio de datos sin malloc
    //ver en clases posteriores
    void*aux=malloc(tamElem);
    memcpy(aux,e1,tamElem);
    memcpy(e1,e2,tamElem);
    memcpy(e2,aux,tamElem);

    free(aux);
}
//funciones de comparacion
//>0 si e1 es mas grande
//==0 son iguales
//<0 e2 es mas grande
int cmpCodProd(const void* e1,const void* e2)
{
    const DatosStruct *p1=e1;
    const DatosStruct *p2=e2;
    return p1->CodProd-p2->CodProd;
}
int cmpCodEmp(const void* e1,const void* e2)
{
    const DatosStruct *p1=e1;
    const DatosStruct *p2=e2;
    return p1->CodEmp-p2->CodEmp;
}
bool ordenamientoInserccion(Vector* vec,COMPARE cmpCampo1)
{
    void * fin=vec->vec+(vec->ce-1)*vec->tElem;
    void * i,*j;
    void * ins=malloc(vec->tElem);
    if(ins==NULL)
        return false;
    for(i=vec->vec+vec->tElem;i<=fin;i+=vec->tElem)
    {
        memcpy(ins,i,vec->tElem);
        j=i-vec->tElem;
        while(j<fin&&cmpCampo1(ins,j)<0)
        {
            memcpy(j+=vec->tElem,j,vec->tElem);
            j-=vec->tElem;
        }
        memcpy(j+=vec->tElem,ins,vec->tElem);
    }
    free(ins);
    return false;
}
//funcion de comparacion
//>0 si e1 es mas grande
//==0 son iguales
//<0 e2 es mas grande
int cmpCodProdEspe(const void* e1,const void* e2)
{
    const Especificaciones *p1=e1;
    const Especificaciones *p2=e2;
    return p1->CodProd-p2->CodProd;
}