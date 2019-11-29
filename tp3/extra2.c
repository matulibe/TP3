#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estadisticas.h"


enano_t leer_enano(FILE * lista_enanos, int* cant_enanos_leidos){
  enano_t enanos;
  *cant_enanos_leidos = fscanf(lista_enanos, "%[^;];%i;%i;%i\n", enanos.nombre, &enanos.edad, &enanos.cantidad_misiones, &enanos.id_rango);
  return enanos;
}


int elegir_enanos(int guerrero, int lideres, int generales, char nombre_mision[]){
  enano_t elegido;
  int cant_aprend = 0;
  int cant_gral = 0;
  int cant_lider = 0;
  int cant_guerrero = 0;
  int cant_enanos_leidos;
  FILE * lista_enanos;
  FILE * mision;

  lista_enanos = fopen(CENSO, "r");
  if(lista_enanos == NULL){
    printf("No se ha podido abrir el archivo\n");
    return -1;
  }

  mision = fopen(nombre_mision, "r");
  if(mision != NULL){
    printf("La mision ya a sido asiganda\n");
    fclose(mision);
    fclose(lista_enanos);
    return -1;
  }

  mision = fopen(nombre_mision, "w");
  if(mision == NULL){
    printf("No se ha podido abrir el archivo\n");
    fclose(lista_enanos);
    return -1;
  }

  elegido = leer_enano(lista_enanos, &cant_enanos_leidos);
  while(cant_enanos_leidos != EOF){
    if(elegido.id_rango == APRENDIZ && cant_aprend <= APRENDICES_MISIONES){
      fwrite(&elegido, sizeof(enano_t), 1, mision);
      cant_aprend++;
      elegido = leer_enano(lista_enanos, &cant_enanos_leidos);
    }else if(elegido.id_rango == GUERRERO && cant_guerrero <= guerrero){
      fwrite(&elegido, sizeof(enano_t), 1, mision);
      cant_guerrero++;
      elegido = leer_enano(lista_enanos, &cant_enanos_leidos);
    }else if(elegido.id_rango == LIDER && cant_lider <= lideres){
      fwrite(&elegido, sizeof(enano_t), 1, mision);
      cant_lider++;
      elegido = leer_enano(lista_enanos, &cant_enanos_leidos);
    } else if(elegido.id_rango == GENERAL && cant_gral <= generales){
      fwrite(&elegido, sizeof(enano_t), 1, mision);
      cant_gral++;
      elegido = leer_enano(lista_enanos, &cant_enanos_leidos);
    }else{
      elegido = leer_enano(lista_enanos, &cant_enanos_leidos);
    }
  }

  if(cant_guerrero < guerrero || cant_lider < lideres || cant_gral < generales){
    printf("No hay suficuentes soldados");
    fclose(mision);
    fclose(lista_enanos);
    remove(nombre_mision);
    return -1;
  }


  fclose(mision);
  fclose(lista_enanos);
  return 1;
}


void promocion(enano_t *enano){
  if(enano->cantidad_misiones >= MIN_MISIONES_GUERRERO && enano->id_rango == APRENDIZ){
    enano->id_rango++;
  }else if(enano->cantidad_misiones >= MIN_MISIONES_LIDER && (enano->edad >= EDAD_LIDER_MIN && enano->edad <= EDAD_LIDER_MAX) && enano->id_rango == GUERRERO){
    enano->id_rango++;
  }else if(enano->cantidad_misiones >= MIN_MISIONES_GENERAL && (enano->edad >= EDAD_GENERAL_MIN && enano->edad <= EDAD_GENERAL_MAX) && enano->id_rango == LIDER){
    enano->id_rango++;
  }

}

int promover_enanos(){
  enano_t leido;
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
    fclose(lista_enanos);
  }

  leido = leer_enano(lista_enanos, &cant_enanos_leidos);
  while (cant_enanos_leidos != EOF){
    promocion(&leido);
    fprintf(lista_actualizada, " %s;%i;%i;%i\n", leido.nombre, leido.edad, leido.cantidad_misiones, leido.id_rango);
    leido = leer_enano(lista_enanos, &cant_enanos_leidos);
  }

  fclose(lista_actualizada);
  fclose(lista_enanos);
  return 1;
}



void enanos_de_rango(int rango){
  enano_t leido;
  rango_t rango_leido;
  int id_de_rango;
  int cant_enanos_leidos;
  int tamanio = (int)(sizeof(rango_t));
  int moverse = ((rango - DESFASAJE)* tamanio);
  FILE * lista_enanos;
  FILE * lista_rangos;
  lista_enanos = fopen(CENSO, "r");
  if(lista_enanos == NULL){
    printf("No se ha podido abrir el archivo\n");
  }

  lista_rangos = fopen(RANGOS, "r");
  if(lista_rangos == NULL){
    printf("No se ha podido abrir el archivo\n");
    fclose(lista_enanos);
  }

  fseek(lista_rangos, moverse, SEEK_SET);
  fread(&rango_leido, sizeof(rango_t), 1, lista_rangos);
  printf("%i) %s\n%s\n", rango_leido.id, rango_leido.nombre, rango_leido.descripcion);

  leido = leer_enano(lista_enanos, &cant_enanos_leidos);

  while(cant_enanos_leidos != EOF){
    id_de_rango = leido.id_rango;
    if(id_de_rango == rango){
      if(rango == OBRERO){
        printf(ANSI_COLOR_YELLOW "  %s" ANSI_COLOR_RESET "\n", leido.nombre);
        leido = leer_enano(lista_enanos, &cant_enanos_leidos);
      }else if(rango == APRENDIZ){
        printf(ANSI_COLOR_CYAN "  %s" ANSI_COLOR_RESET "\n", leido.nombre);
        leido = leer_enano(lista_enanos, &cant_enanos_leidos);
      }else if(rango == GUERRERO){
        printf(ANSI_COLOR_MAGENTA "  %s" ANSI_COLOR_RESET "\n", leido.nombre);
        leido = leer_enano(lista_enanos, &cant_enanos_leidos);
      }else if(rango == LIDER){
        printf(ANSI_COLOR_RED "  %s" ANSI_COLOR_RESET "\n", leido.nombre);
        leido = leer_enano(lista_enanos, &cant_enanos_leidos);
      }else{
        printf(ANSI_COLOR_GREEN "  %s" ANSI_COLOR_RESET "\n", leido.nombre);
        leido = leer_enano(lista_enanos, &cant_enanos_leidos);
      }
    }else{
      leido = leer_enano(lista_enanos, &cant_enanos_leidos);
    }
  }

  fclose(lista_rangos);
  fclose(lista_enanos);
}

int main(int argc, char const *argv[]) {
  if((strcmp(argv[PRIMERO], ACTUALIZAR) == 0) && argc == 3){

  }else if((strcmp(argv[PRIMERO], PROMOVER) == 0) && argc == 2){
    promover_enanos();

  }else if((strcmp(argv[PRIMERO], SELECCIONAR) == 0) && argc == 6){
    char nombre_mision[MAX];
    int guerreros = atoi(argv[SEGUNDO]);
    int lideres = atoi(argv[TERCERO]);
    int generales = atoi(argv[CUARTO]);
    strcpy(nombre_mision, argv[QUINTO]);
    strcat(nombre_mision, ".dat");
    elegir_enanos(guerreros, lideres, generales, nombre_mision);

  }else if((strcmp(argv[PRIMERO], LISTAR) == 0) && argc == 3){
    int rango = atoi(argv[2]);
    enanos_de_rango(rango);
  }else{
    printf("Comando no valido\n");
  }


  return 0;
}

//gcc extra2.c -o a -std=c99 -Wall -Werror -Wconversion
