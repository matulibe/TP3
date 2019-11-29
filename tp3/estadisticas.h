#ifndef __ESTADISTICAS_H__
#define  __ESTADISTICAS_H__


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CENSO "censo.csv"
#define RANGOS "rango.dat"
#define ACTUALIZAR "actualizar_censo"
#define PROMOVER "promover_enanos"
#define SELECCIONAR "integrantes_mision"
#define LISTAR "enanos_de_rango"

#define MAX_ARG_INGRESADO 100
#define MAX_NOMBRE 50
#define MAX_RANGO 50
#define MAX_DESCRIPCION 200

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

const int OBRERO = 1;
const int APRENDIZ = 2;
const int GUERRERO = 3;
const int LIDER = 4;
const int GENERAL = 5;
const int EDAD_LIDER_MIN = 40;
const int EDAD_LIDER_MAX = 50;
const int EDAD_GENERAL_MIN = 50;
const int EDAD_GENERAL_MAX = 60;
const int MIN_MISIONES_GUERRERO = 10;
const int MIN_MISIONES_LIDER = 100;
const int MIN_MISIONES_GENERAL = 250;
const int APRENDICES_MISIONES = 10;
const int PRIMERO = 1;
const int SEGUNDO = 2;
const int TERCERO = 3;
const int CUARTO = 4;
const int QUINTO = 5;
const int DESFASAJE = 1;


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


int elegir_enanos();


void enanos_de_rango();
*/

#endif /*__ESTADISTICAS_H__*/
