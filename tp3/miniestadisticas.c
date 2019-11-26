#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estadisticas.h"

#define PRIMERO 1
#define SEGUNDO 2
#define TERCERO 3
#define CUARTO 4
#define ACTUALIZAR "actualizar_censo"
#define PROMOVER "promover_enanos"
#define SELECCIONAR "elegir_enanos"
#define LISTAR "enanos_de_rango"


int main(int argc, char const *argv[]) {

  if(strcmp(argv[PRIMERO], ACTUALIZAR) == 0){

  }else if(strcmp(argv[PRIMERO], PROMOVER) == 0){

  }else if(strcmp(argv[PRIMERO], SELECCIONAR) == 0){
    int cant_guerro = atoi(argv[SEGUNDO]);
    int cant_lider = atoi(argv[TERCERO]);
    int cant_guerro = atoi(argv[CUARTO]);

  }else if(strcmp(argv[PRIMERO], LISTAR) == 0){

  }else{
    printf("Comando no valido\n", );
  }


  return 0;
}





//gcc *.c -o miniestadísticas -std=c99 -Wall -Werror -Wconversion
