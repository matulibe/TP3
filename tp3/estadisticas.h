#ifndef __ESTADISTICAS_H__
#define  __ESTADISTICAS_H__


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_NOMBRE 50
#define MAX_RANGO 50
#define MAX_DESCRIPCION 200
#define CENSO "censo.csv"


typedef struct enano{
char nombre[MAX_NOMBRE];
int edad;
int cantidad_misiones ;
int id_rango;
} enano_t;

typedef struct rango{
int id;
char nombre[MAX_RANGO];
char descripcion[MAX_DESCRIPCION];
} rango_t;


/*void actualizar_censo();


void promover_enanos();


void elegir_enanos();


void enanos_de_rango();
*/

#endif /*__ESTADISTICAS_H__*/
