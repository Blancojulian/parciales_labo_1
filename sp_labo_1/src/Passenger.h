/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "LinkedList.h"

#define LEN_STRING 51
#define LEN_FLY_CODE 8
//TIPO DE PASAJERO
#define FIRST_CLASS 1
#define EXECUTIVE_CLASS 2
#define ECONOMYCLASS 3
//ESTADO DE VUELO
#define ATERRIZADO 1
#define EN_HORARIO 2
#define EN_VUELO 3
#define DEMORADO 4


typedef struct
{
	int id;
	char nombre[LEN_STRING];
	char apellido[LEN_STRING];
	float precio;
	char codigoVuelo[LEN_FLY_CODE];
	int tipoPasajero;
	int estadoVuelo;
	int millas;

}Passenger;

/*
typedef struct
{
	int id;
	char nombre[LEN_STRING];
	char apellido[LEN_STRING];
	float precio;
	char codigoVuelo[LEN_FLY_CODE];
	int tipoPasajero;
	int estadoVuelo;
	int millas;

}PassengerMillas;*/

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);
Passenger* Passenger_newParametros_types(int id, char* nombreStr, char* apellidoStr, float precio, char* codigoVueloStr, int tipoPasajero, int estadoVuelo);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo);

int Passenger_getIntTipoPasajero(char* tipoPasajeroStr, int* tipoPasajero);
int Passenger_getTextTipoPasajero(int tipoPasajero, char* tipoPasajeroStr);
int Passenger_getIntEstadoVueldo(char* estadoVueloStr, int* estadoVuelo);
int Passenger_getTextEstadoVueldo(int estadoVuelo, char* estadoVueloStr);

int Passenger_printPassenger(Passenger* this);
int Passenger_findById(LinkedList* pArrayListPassenger, int id, int* pIndex);
Passenger* Passenger_modifyPassenger(Passenger* this);
int requestDataPassenger(Passenger* auxPassenger);
int Passenger_findMaxId(LinkedList* pArrayListPassenger, int* pMaxId);

int Passenger_funcionCriterioId(void* this1, void* this2);
int Passenger_funcionCriterioNombre(void* this1, void* this2);
int Passenger_funcionCriterioApellido(void* this1, void* this2);
int Passenger_funcionCriterioPrecio(void* this1, void* this2);
int Passenger_funcionCriterioCodigoVuelo(void* this1, void* this2);
int Passenger_funcionCriterioTipoPasajero(void* this1, void* this2);
int Passenger_funcionCriterioEstadoVuelo(void* this1, void* this2);


int Passenger_fnTipoFirstClass(void* this);
int Passenger_fnTipoExecutiveClass(void* this);
int Passenger_fnTipoEconomyClass(void* this);

int Passenger_imprimiCantidadPasajerosPorClase(LinkedList* pArrayListPassenger);
LinkedList* Passenger_filtrarPasajerosPorClase(LinkedList* pArrayListPassenger);

void Passenger_criterioMap(void* this);
int Passenger_printPassengerMiles(Passenger* this);

int Passenger_setMillas(Passenger* this,int millas);
int Passenger_getMillas(Passenger* this,int* millas);


#endif /* PASSENGER_H_ */
