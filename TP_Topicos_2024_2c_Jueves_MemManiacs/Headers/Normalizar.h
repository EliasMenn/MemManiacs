#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED
#include <stdbool.h>
#define EsMayus(car) ((car)>='A'&&(car)<='Z'?true:false)
#define EsMinus(car) ((car)>='a'&&(car)<='z'?true:false)
#define EsLetra(car) (EsMayus(car)||EsMinus(car)?true:false)
//se asume que se valido antes
#define MinAMay (car) ((car)-'a'+'A')
#define MayAMin (car) ((car)-'A'+'a')

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
