#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estadisticas.h"


int main(){
    FILE * stream;
    rango_t rango;

    stream = fopen("rango.dat", "r");
    fread(&rango, sizeof(rango_t), 1, stream);
    while(!feof(stream)){
      printf("%i) %s: %s\n", rango.id, rango.nombre, rango.descripcion);
      fread(&rango, sizeof(rango_t), 1, stream);
    }
    printf("\n");
    fclose(stream);
    return 0;
}
