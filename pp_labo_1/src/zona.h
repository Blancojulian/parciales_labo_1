/*
 * zona.h
 *
 *  Created on: 18 may. 2022
 *      Author: Blanco Julián Agustín
 */

#ifndef ZONA_H_
#define ZONA_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#include "censista.h"
#define LEN_STRING 51
#define MAX_CASAS_ZONA 20


#define PENDIENTE 0
#define FINALIZADO 1

#define SIN_ASIGNAR 0

typedef struct{
	int codigo;
	char decripcion[LEN_STRING];
}Locadidad;

typedef struct{
	char calle1[LEN_STRING];
	char calle2[LEN_STRING];
	char calle3[LEN_STRING];
	char calle4[LEN_STRING];
}Calles;

typedef struct{
	int id;
	Calles calles;
	Locadidad localidad;
	int idCensista;
	int cantCensadosInSitu;
	int cantCensadosVirtual;
	int cantAusentes;
	int estado;
	int isEmpty;
}Zona;

int initZona(Zona* list, int len);
int addZona(Zona* list, int len, int id, Calles calles, Locadidad localidad, int idCensista, int cantCensadosInSitu, int cantCensadosVirtual, int cantAusentes, int estado);
int searchFreeIndexZona(Zona* list, int len, int* pIndex);
int findZonaById(Zona* list, int len, int id, int* pIndex);
int removeZona(Zona* list, int len, int id);
int requestDataZona(Zona* pZona, Locadidad* listLocalidades, int len);
int isEmptyArrayZonas(Zona* list, int len);
int findLocadidadByCodigo(Locadidad* list, int len, int id, int* pIndex);
int printArrayLocadidades(Locadidad* list, int len);
int printArrayZonas(Zona* list, int len, Censista* listCensistas, int lenCensistas);
int asignarCensistaAZona(Zona* list, int len, int idZona, Censista* listCensistas, int lenCensistas, int idCensista);
int altaForzadaZona(Zona* list, int len, Locadidad* listLocalidad, int lenLocalidad, char* calle1, char* calle2, char* calle3, char* calle4, int codigoLocalidad, int idCensista, int cantCensadosInSitu, int cantCensadosVirtual, int cantAusentes, int estado);
int cargaDatosAZona(Zona* list, int len, int id, Censista* listCensistas, int lenCensistas);

#endif /* ZONA_H_ */
