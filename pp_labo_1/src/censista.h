/*
 * censista.h
 *
 *  Created on: 18 may. 2022
 *      Author: Blanco Julián Agustín
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

#include <stdio.h>
#include <stdlib.h>
#include "utn_biblioteca.h"
#define LEN_STRING 51
#define LIBERADO 1
#define ACTIVO 2
#define INACTIVO 3
#define MAX_ALTURA 150000

typedef struct{
	char calle[LEN_STRING];
	int altura;
}Direccion;

typedef struct{
	int id;
	char nombre[LEN_STRING];
	char apellido[LEN_STRING];
	Fecha nacimiento;
	int edad;
	Direccion direccion;
	int estado;
	int isEmpty;
}Censista;

int initCensistas(Censista* list, int len);
int addCensista(Censista* list, int len, int id, char* nombre, char* apellido, Fecha nacimiento, int edad, Direccion direccion, int estado);
int searchFreeIndex(Censista* list, int len, int* pIndex);
int findCensistaById(Censista* list, int len, int id, int* pIndex);
int removeCensista(Censista* list, int len, int id);
int sortCensistas(Censista* list, int len, int order);
int modifyPassenger(Censista* list, int len, int id, int field, int fieldDate, int fieldDirection);
int requestDataCensista(Censista* auxCensista);
int isEmptyArrayCensistas(Censista* list, int len);
int altaForzadaCensista(Censista* list, int len, char* nombre, char* apellido, int dia, int mes, int anio, int edad, char* calle, int altura, int estado);
int printCensista(Censista* pCensista);
int printArrayCensistas(Censista* list, int len);

#endif /* CENSISTA_H_ */
