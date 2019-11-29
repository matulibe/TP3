#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estadisticas.h"

#define OBRERO 1
#define APRENDIZ 2
#define GUERRERO 3
#define LIDER 4
#define GENERAL 5
#define EDAD_LIDER_MIN 40
#define EDAD_LIDER_MAX 50
#define EDAD_GENERAL_MIN 50
#define EDAD_GENERAL_MAX 60
#define MIN_MISIONES_GUERRERO 10
#define MIN_MISIONES_LIDER 100
#define MIN_MISIONES_GENERAL 250
#define APRENDICES_MISIONES 10


enano_t leer_enano(FILE * lista_enanos, int* cant_enanos_leidos){
  enano_t enanos;
  *cant_enanos_leidos = fscanf(lista_enanos, "%[^;];%i;%i;%i\n", enanos.nombre, &enanos.edad, &enanos.cantidad_misiones, &enanos.id_rango);
  return enanos;
}


int elegir_enanos(int cant_guerro, int cant_lider, int cant_gral, ){
  FILE * censo;
  FILE * mision;
  enano_t elegido;
  size_t enanos_elegidos;

  censo = fopen(CENSO, "r");
  if(censo == NULL){
    printf("No se ha podido abrir el archivo\n");
    return -1;
  }

  mision = fopen(argv[])
  if(mision)
}


void promocion(enano_t *enano){
  if(enano->cantidad_misiones >= MIN_MISIONES_GUERRERO && enano->id_rango == APRENDIZ){
    enano->id_rango++;
  }else if(enano->cantidad_misiones >= MIN_MISIONES_LIDER && (enano->edad >= EDAD_LIDER_MIN && enano->edad >= EDAD_LIDER_MAX) && enano->id_rango == GUERRERO){
    enano->id_rango++;
  }else if(enano->cantidad_misiones >= MIN_MISIONES_GENERAL && (enano->edad >= EDAD_GENERAL_MIN && enano->edad >= EDAD_GENERAL_MAX) && enano->id_rango == LIDER){
    enano->id_rango++;
  }

}


int promover_enanos(){
  enano_t leido;
  size_t promover;
  int cant_enanos_leidos;
  FILE * lista_enanos;
  FILE * lista_actualizada;

  lista_enanos = fopen(CENSO, "r");
  if(lista_enanos == NULL){
    printf("No se ha podido abrir el archivo censo.csv\n");
  }

  lista_actualizada = fopen("lista.csv", "w");
  if(lista_actualizada == NULL){
    printf("No se ha podido abrir el archivo\n");
  }

  leido = leer_enano(lista_enanos, &cant_enanos_leidos);
  while (cant_enanos_leidos != EOF){
    promocion(&leido);
    promover = fprintf(lista_actualizada, " %s;%i;%i;%i\n", leido.nombre, leido.edad, leido.cantidad_misiones, leido.id_rango);
    leido = leer_enano(lista_enanos, &cant_enanos_leidos);
    if(!promover){
      printf("No se puede escribir el archivo\n");
      return -1;
    }
  }

  fclose(lista_actualizada);
  fclose(lista_enanos);
  return 1;
}


void imprimir_nombre_rango(int id_de_rango){
  if(id_de_rango == OBRERO){
    printf("Obreros:\n");
  }else if(id_de_rango == APRENDIZ){
    printf("\nAprendices:\n");
  }else if(id_de_rango == GUERRERO){
    printf("\nGuerreros:\n");
  }else if(id_de_rango == LIDER){
    printf("\nLideres:\n");
  }else{
    printf("\nGenerales:\n");
  }
}


void enanos_de_rango(){
  enano_t leido;
  int id_de_rango;
  int cant_enanos_leidos;
  FILE * lista_enanos;
  lista_enanos = fopen(CENSO, "r");
  if(lista_enanos == NULL){
    printf("No se ha podido abrir el archivo censo.csv\n");
  }

  leido = leer_enano(lista_enanos, &cant_enanos_leidos);

  while(cant_enanos_leidos != EOF){
    id_de_rango = leido.id_rango;
    imprimir_nombre_rango(id_de_rango);
    while(id_de_rango == leido.id_rango && cant_enanos_leidos != EOF){
      if(id_de_rango == OBRERO)´

      printf("   %s\n", leido.nombre);
      leido = leer_enano(lista_enanos, &cant_enanos_leidos);
    }
  }
fclose(lista_enanos);
}
