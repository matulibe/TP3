#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estadisticas.h"

#define ARCH_LEER "rangos.csv"


int escribir_archivo(){
  rango_t rango;
  size_t cant_leidos;
  size_t chequear;
  FILE* archivo;
  FILE* leido;

  archivo = fopen("rango.dat", "w");
  if(archivo == NULL){
    printf("No se pudo abrir el archivo\n");
    return -1;
  }

  leido = fopen(ARCH_LEER, "r");
  if(leido == NULL){
    printf("No se pudo abrir el archivo a leer\n");
    return -1;
  }

  cant_leidos = fscanf(leido, "%i;%[^;];%[^;]\n", &rango.id, rango.nombre, rango.descripcion);

  while(cant_leidos != EOF){
    chequear = fwrite(&rango, sizeof(rango_t), 1, archivo);
    cant_leidos = fscanf(leido, "%i;%[^;];%[^;]\n", &rango.id, rango.nombre, rango.descripcion);
    if(!chequear){
      printf("No se puede escribir el archivo\n");
      return -1;
    }
  }



  fclose(leido);
  fclose(archivo);
  return 1;
}


int main(){

  escribir_archivo();
  return 0;
}
