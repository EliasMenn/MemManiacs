#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#include <stdbool.h>
#define ERRORC '@'
#define EsMayusTilde(car)((car)=='Á'||(car)=='É'||(car)=='Í'||(car)=='Ó'||(car)=='Ú')
#define EsMayus(car) ((car)>='A'&&(car)<='Z')
#define EsMinusTilde(car)((car)=='á'||(car)=='é'||(car)=='í'||(car)=='ó'||(car)=='ú')
#define EsMinus(car) ((car)>='a'&&(car)<='z')
#define EsTilde(car) (EsMayusTilde((car))||EsMinusTilde((car)))
#define EsLetra(car) (EsMayus((car))||EsMinus((car))||EsTilde((car)))
//se asume que se valido antes
#define MinAMay (car) ((car)-'a'+'A')
#define MayAMin (car) ((car)-'A'+'a')
#define TildeMinAMay(car)(\
    switch(car)\
    {\
        case 'Á':\
            return 'á';\
        case 'É':\
            return 'é';\
        case 'Í':\
            return 'í';\
        case 'Ó':\
            return 'ó';\
        case 'Ú':\
            return 'ú';\
        default:\
            return ERRORC;\
    }\
)
#define TildeMayAMin(car)(\
    switch(car)\
    {\
        case 'á':\
            return 'A';\
        case 'é':\
            return 'É';\
        case 'í':\
            return 'Í';\
        case 'ó':\
            return 'Ó';\
        case 'ú':\
            return 'Ú';\
        default:\
            return ERRORC;\
    }\
)
//version con la validacion
/*
#define MinAMay (car) (EsMinus(car)?(car)-'a'+'A':car)
#define MayAMin (car) (EsMayus(car)?(car)-'A'+'a':car)
*/

/*
#include <time.h>
clock_t start, end;
float elapsed_time;
start = clock();
read_disk_sector();
end = clock();
elapsed_time = (float)(end - start) / (float)CLOCKS_PER_SEC;
printf("Elapsed time: %f seconds\n", elapsed_time);*/

#endif // HEADERS_H_INCLUDED
