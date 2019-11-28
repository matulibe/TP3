#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estadisticas.h"

#define CENSO "censo.csv"

#define RANGOS "rango.dat"
#define ACTUALIZAR "actualizar_censo"
#define PROMOVER "promover_enanos"
#define SELECCIONAR "elegir_enanos"
#define LISTAR "enanos_de_rango"


int main(int argc, char const *argv[]) {
  FILE * archivo = fopen(RANGOS, "r")
  fclose(archivo);
  return 0;
}
