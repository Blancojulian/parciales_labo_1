/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Blanco Julián Agustín
 */

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>
#include <string.h>
#include "utn_biblioteca.h"
#include "Passenger.h"
#define CANT_REINTENTOS 2

/**
 * \brief Escribe un id.
 * \param Employee* this, Es el puntero al espacio de memoria.
 * \param int id, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Lee un id.
 * \param Employee* this, Es el puntero al array.
 * \param int* id, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Escribe un nombre.
 * \param Employee* this, Es el puntero al espacio de memoria.
 * \param char* nombre, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL && isName(nombre, LEN_STRING))
	{
		strncpy(this->nombre, nombre, LEN_STRING);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Lee un nombre.
 * \param Employee* this, Es el puntero al array.
 * \param char* nombre, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre, LEN_STRING);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Escribe un apellido.
 * \param Employee* this, Es el puntero al espacio de memoria.
 * \param char* apellido, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL && isName(apellido, LEN_STRING))
	{
		strncpy(this->apellido, apellido, LEN_STRING);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Lee un apellido.
 * \param Employee* this, Es el puntero al array.
 * \param char* nombre, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		strncpy(apellido, this->apellido, LEN_STRING);
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Escribe un tipo de pasajero.
 * \param Employee* this, Es el puntero al array.
 * \param int* id, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero > 0)
	{
		this->tipoPasajero = tipoPasajero;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Lee un tipo de pasajero.
 * \param Employee* this, Es el puntero al array.
 * \param int* id, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		*tipoPasajero = this->tipoPasajero;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Escribe un precio.
 * \param Employee* this, Es el puntero al array.
 * \param int* id, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_setPrecio(Passenger* this, float precio)
{
	int retorno = -1;
	if(this != NULL && precio > 0)
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Lee un precio.
 * \param Employee* this, Es el puntero al array.
 * \param int* id, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_getPrecio(Passenger* this, float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Escribe un codigo de vuelo.
 * \param Employee* this, Es el puntero al espacio de memoria.
 * \param char* nombre, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL && isFlyCode(codigoVuelo, LEN_FLY_CODE))
	{
		strncpy(this->codigoVuelo, codigoVuelo, LEN_FLY_CODE);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Lee un codigo de vuelo.
 * \param Employee* this, Es el puntero al array.
 * \param char* nombre, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strncpy(codigoVuelo, this->codigoVuelo, LEN_FLY_CODE);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Escribe un estado de vuelo.
 * \param Employee* this, Es el puntero al array.
 * \param int* id, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_setEstadoVuelo(Passenger* this, int estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo >= ATERRIZADO && estadoVuelo <= DEMORADO)
	{
		this->estadoVuelo = estadoVuelo;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Lee un id.
 * \param Employee* this, Es el puntero al array.
 * \param int* id, Puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int Passenger_getEstadoVuelo(Passenger* this, int* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		*estadoVuelo = this->estadoVuelo;
		retorno = 0;
	}
	return retorno;
}

int Passenger_getIntTipoPasajero(char* tipoPasajeroStr, int* tipoPasajero)
{
	int retorno = -1;
	if(tipoPasajeroStr != NULL && tipoPasajero != NULL)
	{
		if(strncmp(tipoPasajeroStr, "FirstClass", LEN_STRING) == 0)
		{
			*tipoPasajero = FIRST_CLASS;
			retorno = 0;
		}
		else if(strncmp(tipoPasajeroStr, "ExecutiveClass", LEN_STRING) == 0)
		{
			*tipoPasajero = EXECUTIVE_CLASS;
			retorno = 0;
		}
		else if(strncmp(tipoPasajeroStr, "EconomyClass", LEN_STRING) == 0)
		{
			*tipoPasajero = ECONOMYCLASS;
			retorno = 0;
		}

	}
	return retorno;
}

int Passenger_getTextTipoPasajero(int estadoVuelo, char* estadoVueloStr)
{
	int retorno = -1;

	if((estadoVuelo >= FIRST_CLASS && estadoVuelo <= ECONOMYCLASS) && estadoVueloStr != NULL)
	{
		switch(estadoVuelo)
		{
			case FIRST_CLASS:
				strncpy(estadoVueloStr, "FirstClass", LEN_STRING);
				retorno = 0;
				break;
			case EXECUTIVE_CLASS:
				strncpy(estadoVueloStr, "ExecutiveClass", LEN_STRING);
				retorno = 0;
				break;
			case ECONOMYCLASS:
				strncpy(estadoVueloStr, "EconomyClass", LEN_STRING);
				retorno = 0;
				break;

		}
	}
	return retorno;
}

int Passenger_getIntEstadoVueldo(char* estadoVueloStr, int* estadoVuelo)
{
	int retorno = -1;
	if(estadoVueloStr != NULL && estadoVuelo != NULL)
	{
		if(strncmp(estadoVueloStr, "Aterrizado", LEN_STRING) == 0)
		{
			*estadoVuelo = ATERRIZADO;
			retorno = 0;
		}
		else if(strncmp(estadoVueloStr, "En Horario", LEN_STRING) == 0)
		{
			*estadoVuelo = EN_HORARIO;
			retorno = 0;
		}
		else if(strncmp(estadoVueloStr, "En Vuelo", LEN_STRING) == 0)
		{
			*estadoVuelo = EN_VUELO;
			retorno = 0;
		}
		else if(strncmp(estadoVueloStr, "Demorado", LEN_STRING) == 0)
		{
			*estadoVuelo = DEMORADO;
			retorno = 0;
		}

	}
	return retorno;
}

int Passenger_getTextEstadoVueldo(int estadoVuelo, char* estadoVueloStr)
{
	int retorno = -1;

	if((estadoVuelo >= ATERRIZADO && estadoVuelo <= DEMORADO) && estadoVueloStr != NULL)
	{
		switch(estadoVuelo)
		{
			case ATERRIZADO:
				strncpy(estadoVueloStr, "Aterrizado", LEN_STRING);
				retorno = 0;
				break;
			case EN_HORARIO:
				strncpy(estadoVueloStr, "En Horario", LEN_STRING);
				retorno = 0;
				break;
			case EN_VUELO:
				strncpy(estadoVueloStr, "En Vuelo", LEN_STRING);
				retorno = 0;
				break;
			case DEMORADO:
				strncpy(estadoVueloStr, "Demorado", LEN_STRING);
				retorno = 0;
				break;

		}
	}
	return retorno;
}
/**
 * \brief Solicita los datos del pasajero al usuario.
 * \param Passenger* auxPassenger, Es el puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int requestDataPassenger(Passenger* auxPassenger)
{
	int retorno = -1;
	Passenger aux;

	if(auxPassenger != NULL)
	{
		if(utn_getName(aux.nombre, "\nIngrese el nombre del pasajero: ", "Nombre invalido.\n", CANT_REINTENTOS, LEN_STRING) == 0 &&
		    utn_getName(aux.apellido, "\nIngrese el apellido del pasajero: ", "Apellido invalido.\n", CANT_REINTENTOS, LEN_STRING) == 0 &&
			utn_getNumberFloat(&aux.precio, "\nIngrese el precio del viaje: ", "Precio invalido.\n", 1, 500000, CANT_REINTENTOS) == 0 &&
			utn_getNumberInt(&aux.tipoPasajero, "\n1) FirstClass\n2) ExecutiveClass\n3) EconomyClass\nIngrese tipo de pasajero: ", "Tipo de pasajero invalido.\n", FIRST_CLASS, ECONOMYCLASS, CANT_REINTENTOS) == 0 &&
			utn_getFlyCode(aux.codigoVuelo, "\nIngrese el codigo de vuelo (AA0000A): ", "Codigo de vuelo invalido.\n", CANT_REINTENTOS, LEN_FLY_CODE) == 0 &&
			utn_getNumberInt(&aux.estadoVuelo, "\n1) Aterrizado\n2) En Horario\n3) En Vuelo\n4) Demorado\nIngrese estado de vuelo: ", "Estado de vuelo invalido.\n", ATERRIZADO, DEMORADO, CANT_REINTENTOS) == 0)
		{
		    //aux.id = generateNewId();
			*auxPassenger = aux;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief Crea un nuevo pasajero.
 * \return devuelve un puntero al espacio de memoria del pasajero.
 */
Passenger* Passenger_new()
{
	return (Passenger*)malloc(sizeof(Passenger));
}

/**
 * \brief Crea un nuevo pasajero y recibe los parametros.
 * \param char* id, Puntero al espacio de memoria.
 * \param char* nombreStr, Puntero al espacio de memoria.
 * \param char* apellidoStr, Puntero al espacio de memoria.
 * \param char* precioStr, Puntero al espacio de memoria.
 * \param char* codigoVueloStr, Puntero al espacio de memoria.
 * \param char* tipoPasajeroStr, Puntero al espacio de memoria.
 * \param char* estadoVueloStr, Puntero al espacio de memoria.
 * \return devuelve un puntero al espacio de memoria del pasajero.
 */
Passenger* Passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	Passenger* this = Passenger_new();
	int auxTipoPasajero;
	int auxEstadoVuelo;
	//printf("%s,%s,%s,%s",idStr, codigoVueloStr, tipoPasajeroStr,estadoVueloStr);

	if(this != NULL && isInt(idStr, LONG_BUFFER) && isFloat(precioStr, LONG_BUFFER)&&
			Passenger_getIntTipoPasajero(tipoPasajeroStr, &auxTipoPasajero) == 0 &&
			Passenger_getIntEstadoVueldo(estadoVueloStr, &auxEstadoVuelo) == 0 &&
			Passenger_setId(this, atoi(idStr)) == 0 &&
			Passenger_setNombre(this, nombreStr) == 0 &&
			Passenger_setApellido(this, apellidoStr) == 0 &&
			Passenger_setPrecio(this, atof(precioStr)) == 0 &&
			Passenger_setCodigoVuelo(this, codigoVueloStr) == 0 &&//hay un error en setCodigo
			Passenger_setTipoPasajero(this, auxTipoPasajero) == 0 &&
			Passenger_setEstadoVuelo(this, auxEstadoVuelo) == 0)
	{
		//printf("aux tipo pasajero: %d, %s\n",auxTipoPasajero, tipoPasajeroStr);
	}
	else
	{
		Passenger_delete(this);
		this = NULL;
	}

	return this;
}
/**
 * \brief Crea un nuevo pasajero y recibe los parametros.
 * \param int id, id del pasajero.
 * \param char* nombreStr, nombre del pasajero.
 * \param char* apellidoStr, apellido del pasajero.
 * \param float precio, precio del viaje.
 * \param int codigoVueloStr, Puntero al espacio de memoria.
 * \param char* tipoPasajeroStr, Puntero al espacio de memoria.
 * \param int estadoVueloStr, Puntero al espacio de memoria.
 * \return devuelve un puntero al espacio de memoria del pasajero.
 */
Passenger* Passenger_newParametros_types(int id, char* nombreStr, char* apellidoStr, float precio, char* codigoVueloStr, int tipoPasajero, int estadoVuelo)
{
	Passenger* this = Passenger_new();

	if(this != NULL && Passenger_setId(this, id) == 0 &&
			Passenger_setNombre(this, nombreStr) == 0 &&
			Passenger_setApellido(this, apellidoStr) == 0 &&
			Passenger_setPrecio(this, precio) == 0 &&
			Passenger_setCodigoVuelo(this, codigoVueloStr) == 0 &&
			Passenger_setTipoPasajero(this, tipoPasajero) == 0 &&
			Passenger_setEstadoVuelo(this, estadoVuelo) == 0)
	{

	}
	else
	{
		Passenger_delete(this);
		this = NULL;
	}

	return this;
}
/*
 * \brief Borra un pasajero (libera el espacio de memoria).
 * \param Passenger* this, Es el puntero al espacio de memoria del pasajero.
 */
void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

/**
 * \brief Imprime los datos de un pasajero.
 * \param Passenger* this, Es el puntero al pasajero.
 * \return (-1) Error / (0) Ok
 */
int Passenger_printPassenger(Passenger* this)
{
	int retorno = -1;
	char auxTipoPasajero[LEN_STRING];
	char auxEstadoVuelo[LEN_STRING];
	Passenger auxPassenger;

	if( this != NULL && Passenger_getId(this, &auxPassenger.id) == 0 &&
		Passenger_getNombre(this, auxPassenger.nombre) == 0 &&
		Passenger_getApellido(this, auxPassenger.apellido) == 0 &&
		Passenger_getPrecio(this, &auxPassenger.precio) == 0 &&
		Passenger_getCodigoVuelo(this, auxPassenger.codigoVuelo) == 0 &&
		Passenger_getEstadoVuelo(this, &auxPassenger.estadoVuelo) == 0 &&
		Passenger_getTipoPasajero(this, &auxPassenger.tipoPasajero) == 0 &&
		Passenger_getTextTipoPasajero(auxPassenger.tipoPasajero, auxTipoPasajero) == 0 &&
		Passenger_getTextEstadoVueldo(auxPassenger.estadoVuelo, auxEstadoVuelo) == 0)
	{
		printf("%04d\t|\t%-14s\t|\t%-14s\t|\t%.2f\t|\t%-14s\t|\t%-14s\t|\t%-14s\n",auxPassenger.id ,auxPassenger.nombre,
				auxPassenger.apellido, auxPassenger.precio, auxTipoPasajero, auxPassenger.codigoVuelo, auxEstadoVuelo);
	}

	return retorno;
}

/**
 * \brief Busca el elemento por id y se guarda su indice en un puntero.
 * \param LinkedList pArrayListPassenger, Es el puntero al array.
 * \param int id, es el limite de array.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return Retorna el indice
 */
int Passenger_findById(LinkedList* pArrayListPassenger, int id, int* pIndex)
{
	int retorno = -1;
	int i;
	int auxId;
	int len;
	Passenger* auxPassenger;

	len = ll_len(pArrayListPassenger);
	if (pArrayListPassenger != NULL && pIndex != NULL && id > 0)
	{
		for (i = 0; i < len; i++)
		{
			auxPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
			if(auxPassenger != NULL && Passenger_getId(auxPassenger, &auxId) ==  0 && auxId == id)
			{
				*pIndex = i;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
/*
 * \brief Modifica los datos de un auxiliar pasajero por campos y devuelve puntero al espacio de memoria del pasajero.
 * \param Passenger* this, Es el puntero al espacio de memoria del pasajero.
 */
Passenger* Passenger_modifyPassenger(Passenger* this)
{
	int option;
	Passenger auxParams;
	Passenger* auxPassenger = Passenger_new();

	if(this != NULL && auxPassenger != NULL && Passenger_getId(this, &auxParams.id) == 0 &&//getters
			Passenger_getNombre(this, auxParams.nombre) == 0 &&
			Passenger_getApellido(this, auxParams.apellido) == 0 &&
			Passenger_getPrecio(this, &auxParams.precio) == 0 &&
			Passenger_getCodigoVuelo(this, auxParams.codigoVuelo) == 0 &&
			Passenger_getEstadoVuelo(this, &auxParams.estadoVuelo) == 0 &&
			Passenger_getTipoPasajero(this, &auxParams.tipoPasajero) == 0 &&
			Passenger_setId(auxPassenger, auxParams.id) == 0 && //setters
			Passenger_setNombre(auxPassenger, auxParams.nombre) == 0 &&
			Passenger_setApellido(auxPassenger, auxParams.apellido) == 0 &&
			Passenger_setPrecio(auxPassenger, auxParams.precio) == 0 &&
			Passenger_setCodigoVuelo(auxPassenger, auxParams.codigoVuelo) == 0 &&
			Passenger_setEstadoVuelo(auxPassenger, auxParams.estadoVuelo) == 0 &&
			Passenger_setTipoPasajero(auxPassenger, auxParams.tipoPasajero) == 0 )
	{
		do{
			if(utn_getNumberInt(&option,"\n1) Modificar Nombre"
					"\n2) Modificar Apellido"
					"\n3) Modificar Precio"
					"\n4) Modificar tipo de pasajero"
					"\n5) Modificar codigo de vuelo"
					"\n6) Modificar estado de vuelo"
					"\n7) Volver al menu anterior"
					"\nIngrese opcion: ", "\nOpncion invalida", 1, 7, CANT_REINTENTOS) == 0)
			{
				switch(option)
				{
					case 1:
						if(utn_getName(auxParams.nombre, "\nIngrese el nombre del pasajero: ", "Nombre invalido.\n", CANT_REINTENTOS, LEN_STRING) == 0)
						{
							Passenger_setNombre(auxPassenger, auxParams.nombre);
						}
						break;
					case 2:
						if(utn_getName(auxParams.apellido, "\nIngrese el apellido del pasajero: ", "Apellido invalido.\n", CANT_REINTENTOS, LEN_STRING) == 0)
						{
							Passenger_setApellido(auxPassenger, auxParams.apellido);
						}
						break;
					case 3:
						if(utn_getNumberFloat(&auxParams.precio, "\nIngrese el precio del viaje: ", "Precio invalido.\n", 1, 500000, CANT_REINTENTOS) == 0)
						{
							Passenger_setPrecio(auxPassenger, auxParams.precio);
						}
						break;
					case 4:
						if(utn_getNumberInt(&auxParams.tipoPasajero, "\n1) FirstClass\n2) ExecutiveClass\n3) EconomyClass\nIngrese tipo de pasajero: ", "Tipo de pasajero invalido.\n", FIRST_CLASS, ECONOMYCLASS, CANT_REINTENTOS) == 0)
						{
							Passenger_setCodigoVuelo(auxPassenger, auxParams.codigoVuelo);
						}
						break;
					case 5:
						if(utn_getFlyCode(auxParams.codigoVuelo, "\nIngrese el codigo de vuelo (AA0000A): ", "Codigo de vuelo invalido.\n", CANT_REINTENTOS, LEN_FLY_CODE) == 0)
						{
							Passenger_setCodigoVuelo(auxPassenger, auxParams.codigoVuelo);
						}
						break;
					case 6:
						if(utn_getNumberInt(&auxParams.estadoVuelo, "\n1) \n1) Aterrizado\n2) En Horario\n3) En Vuelo\n4) Demorado\nIngrese estado de vuelo: ", "Estado de vuelo invalido.\n", ATERRIZADO, DEMORADO, CANT_REINTENTOS) == 0)
						{
							Passenger_setEstadoVuelo(auxPassenger, auxParams.estadoVuelo);
						}
						break;
				}
			}
			else
			{
				//printf("\n");
				break;
			}
		}while(option != 7);
	}
	else
	{
		auxPassenger = NULL;
	}

	return auxPassenger;
}

/**
 * \brief Encuentra el id maximo de la linkedlist.
 * \param LinkedList* pArrayListEmployee, Es el puntero al array.
 * \param int* pMaxId, puntero al espacio de memmoria donde se encuentra el id maximo.
 * \return (-1) Error / (0) Ok
 */
int Passenger_findMaxId(LinkedList* pArrayListPassenger, int* pMaxId)
{
	int retorno = -1;
	Passenger* auxPassenger;
	int len = ll_len(pArrayListPassenger);
	int bufferId;
	int MaxId;
	int i;

	if(pArrayListPassenger != NULL && pMaxId != NULL)
	{
		for (i = 0; i < len; i++)
		{
			auxPassenger = ll_get(pArrayListPassenger, i);
			Passenger_getId(auxPassenger, &bufferId);
			if(i == 0 || bufferId >= MaxId)
			{
				MaxId = bufferId;
			}

		}
		*pMaxId = MaxId + 1;
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Criterio para ordenar la lista, ordena por tipo de Pasajero
 * \param void* this1, puntero al espacio de memoria.
 * \param void* this2, puntero al espacio de memoria.
 * \return Retorna el criterio con el que se ordenara la lista.
 */
int Passenger_funcionCriterioId(void* this1, void* this2)
{

	int retorno = 0;
	Passenger* auxPas1 = (Passenger*)this1;
	Passenger* auxPas2 = (Passenger*)this2;
	int auxId1;
	int auxId2;

	if(this1 != NULL && this2 != NULL &&
		Passenger_getId(auxPas1, &auxId1) == 0 &&
		Passenger_getId(auxPas2, &auxId2) == 0)
	{
		if(auxId1 > auxId2)
		{
			retorno = 1;
		}
		else if(auxId1 < auxId2)
		{
			retorno = -1;
		}
	}
	return retorno;
}
/**
 * \brief Criterio para ordenar la lista, ordena por nombre
 * \param void* this1, puntero al espacio de memoria.
 * \param void* this2, puntero al espacio de memoria.
 * \return Retorna el criterio con el que se ordenara la lista.
 */
int Passenger_funcionCriterioNombre(void* this1, void* this2)
{
	int retorno = 0;
	Passenger* auxPas1 = (Passenger*)this1;
	Passenger* auxPas2 = (Passenger*)this2;
	char bufferNombre1[LEN_STRING];
	char bufferNombre2[LEN_STRING];

	//printf("\ndentro de comparar nombre\n");
	if(this1 != NULL && this2 != NULL &&
		Passenger_getNombre(auxPas1, bufferNombre1) == 0 &&
		Passenger_getNombre(auxPas2, bufferNombre2) == 0)
	{
		//printf("\ndentro de strcmp\n");
		//printf("\nnombre1: %s\n",bufferNombre1);
		//printf("\nid1: %d\n",auxEmp1->id);
		 retorno = strcmp(bufferNombre1,bufferNombre2);
	}
	//printf("\ndespues del if\n");
	return retorno;
}
/**
 * \brief Criterio para ordenar la lista, ordena por nombre
 * \param void* this1, puntero al espacio de memoria.
 * \param void* this2, puntero al espacio de memoria.
 * \return Retorna el criterio con el que se ordenara la lista.
 */
int Passenger_funcionCriterioApellido(void* this1, void* this2)
{
	int retorno = 0;
	Passenger* auxPas1 = (Passenger*)this1;
	Passenger* auxPas2 = (Passenger*)this2;
	char auxApellido1[LEN_STRING];
	char auxApellido2[LEN_STRING];


	if(this1 != NULL && this2 != NULL &&
		Passenger_getApellido(auxPas1, auxApellido1) == 0 &&
		Passenger_getApellido(auxPas2, auxApellido2) == 0)
	{
		 retorno = strcmp(auxApellido1,auxApellido2);
	}
	return retorno;
}
/**
 * \brief Criterio para ordenar la lista, ordena por precio
 * \param void* this1, puntero al espacio de memoria.
 * \param void* this2, puntero al espacio de memoria.
 * \return Retorna el criterio con el que se ordenara la lista.
 */
int Passenger_funcionCriterioPrecio(void* this1, void* this2)
{

	int retorno = 0;
	Passenger* auxPas1 = (Passenger*)this1;
	Passenger* auxPas2 = (Passenger*)this2;
	float auxPrecio1;
	float auxPrecio2;

	if(this1 != NULL && this2 != NULL &&
		Passenger_getPrecio(auxPas1, &auxPrecio1) == 0 &&
		Passenger_getPrecio(auxPas2, &auxPrecio2) == 0)
	{
		if(auxPrecio1 > auxPrecio2)
		{
			retorno = 1;
		}
		else if(auxPrecio1 < auxPrecio2)
		{
			retorno = -1;
		}
	}
	return retorno;
}
/**
 * \brief Criterio para ordenar la lista, ordena por nombre
 * \param void* this1, puntero al espacio de memoria.
 * \param void* this2, puntero al espacio de memoria.
 * \return Retorna el criterio con el que se ordenara la lista.
 */
int Passenger_funcionCriterioCodigoVuelo(void* this1, void* this2)
{
	int retorno = 0;
	Passenger* auxPas1 = (Passenger*)this1;
	Passenger* auxPas2 = (Passenger*)this2;
	char auxCodigoVuelo1[LEN_FLY_CODE];
	char auxCodigoVuelo2[LEN_FLY_CODE];


	if(this1 != NULL && this2 != NULL &&
		Passenger_getCodigoVuelo(auxPas1, auxCodigoVuelo1) == 0 &&
		Passenger_getCodigoVuelo(auxPas2, auxCodigoVuelo2) == 0)
	{
		 retorno = strcmp(auxCodigoVuelo1, auxCodigoVuelo2);
	}
	return retorno;
}
/**
 * \brief Criterio para ordenar la lista, ordena por tipo de Pasajero
 * \param void* this1, puntero al espacio de memoria.
 * \param void* this2, puntero al espacio de memoria.
 * \return Retorna el criterio con el que se ordenara la lista.
 */
int Passenger_funcionCriterioTipoPasajero(void* this1, void* this2)
{

	int retorno = 0;
	Passenger* auxPas1 = (Passenger*)this1;
	Passenger* auxPas2 = (Passenger*)this2;
	int auxTipoPasajero1;
	int auxTipoPasajero2;

	if(this1 != NULL && this2 != NULL &&
		Passenger_getTipoPasajero(auxPas1, &auxTipoPasajero1) == 0 &&
		Passenger_getTipoPasajero(auxPas2, &auxTipoPasajero2) == 0)
	{
		if(auxTipoPasajero1 > auxTipoPasajero2)
		{
			retorno = 1;
		}
		else if(auxTipoPasajero1 < auxTipoPasajero2)
		{
			retorno = -1;
		}
	}
	return retorno;
}
/**
 * \brief Criterio para ordenar la lista, ordena por tipo de Pasajero
 * \param void* this1, puntero al espacio de memoria.
 * \param void* this2, puntero al espacio de memoria.
 * \return Retorna el criterio con el que se ordenara la lista.
 */
int Passenger_funcionCriterioEstadoVuelo(void* this1, void* this2)
{

	int retorno = 0;
	Passenger* auxPas1 = (Passenger*)this1;
	Passenger* auxPas2 = (Passenger*)this2;
	int auxEstadoVuelo1;
	int auxEstadoVuelo2;

	if(this1 != NULL && this2 != NULL &&
		Passenger_getEstadoVuelo(auxPas1, &auxEstadoVuelo1) == 0 &&
		Passenger_getEstadoVuelo(auxPas2, &auxEstadoVuelo2) == 0)
	{
		if(auxEstadoVuelo1 > auxEstadoVuelo2)
		{
			retorno = 1;
		}
		else if(auxEstadoVuelo1 < auxEstadoVuelo2)
		{
			retorno = -1;
		}
	}
	return retorno;
}
/**
 * \brief Encuentra el estado de vuelo del codigo de vuelo.
 * \param LinkedList* pArrayListPassenger, Es el puntero al array.
 * \param int* pEstadoVuelo, puntero al espacio de memmoria donde se encuentra el estado de vuelo.
 * \return (-1) Error / (0) Ok
 */
int Passenger_findEstadoVuelo(LinkedList* pArrayListPassenger,char* codigoVuelo, int* pEstadoVuelo)
{
	int retorno = -1;
	Passenger* auxPassenger;
	int len = ll_len(pArrayListPassenger);
	int auxEstadoVuelo;
	char auxCodigoVuelo[LEN_FLY_CODE];
	int i;

	if(pArrayListPassenger != NULL && pEstadoVuelo != NULL)
	{
		for (i = 0; i < len; i++)
		{
			auxPassenger = ll_get(pArrayListPassenger, i);
			if(auxPassenger != NULL && Passenger_getCodigoVuelo(auxPassenger, auxCodigoVuelo) == 0 &&
				strncmp(codigoVuelo, auxCodigoVuelo, LEN_FLY_CODE) == 0 && Passenger_getEstadoVuelo(auxPassenger, &auxEstadoVuelo) == 0)
			{
				*pEstadoVuelo = auxEstadoVuelo;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

//Filter y count
/**
 * \brief Criterio para filtrar la lista por el tipo de pasajero FIRST_CLASS
 * \param void* this1, puntero al espacio de memoria.
 * \param void* this2, puntero al espacio de memoria.
 * \return Retorna el criterio con el que se ordenara la lista.
 */
int Passenger_fnTipoFirstClass(void* this)
{
	int retorno = 0;
	Passenger* auxPassenger = (Passenger*)this;
	int auxTipoPasajero = 0;

	if(this != NULL && Passenger_getTipoPasajero(auxPassenger, &auxTipoPasajero) == 0 && auxTipoPasajero == FIRST_CLASS )
	{
		retorno = 1;
	}

	return retorno;
}
/**
 * \brief Criterio para filtrar la lista por el tipo de pasajero EXECUTIVE_CLASS
 * \param void* this1, puntero al espacio de memoria.
 * \param void* this2, puntero al espacio de memoria.
 * \return Retorna el criterio con el que se ordenara la lista.
 */
int Passenger_fnTipoExecutiveClass(void* this)
{
	int retorno = 0;
	Passenger* auxPassenger = (Passenger*)this;
	int auxTipoPasajero = 0;

	if(this != NULL && Passenger_getTipoPasajero(auxPassenger, &auxTipoPasajero) == 0 && auxTipoPasajero == EXECUTIVE_CLASS )
	{
		retorno = 1;
	}

	return retorno;
}
/**
 * \brief Criterio para filtrar la lista por el tipo de pasajero ECONOMYCLASS
 * \param void* this1, puntero al espacio de memoria.
 * \param void* this2, puntero al espacio de memoria.
 * \return Retorna el criterio con el que se ordenara la lista.
 */
int Passenger_fnTipoEconomyClass(void* this)
{
	int retorno = 0;
	Passenger* auxPassenger = (Passenger*)this;
	int auxTipoPasajero = 0;

	if(this != NULL && Passenger_getTipoPasajero(auxPassenger, &auxTipoPasajero) == 0 && auxTipoPasajero == ECONOMYCLASS )
	{
		retorno = 1;
	}

	return retorno;
}


int Passenger_imprimiCantidadPasajerosPorClase(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	int firstClass = ll_count(pArrayListPassenger, Passenger_fnTipoFirstClass);
	int executiveClass = ll_count(pArrayListPassenger, Passenger_fnTipoExecutiveClass);
	int economyClass = ll_count(pArrayListPassenger, Passenger_fnTipoEconomyClass);

	if(firstClass >= 0 && executiveClass >= 0 && economyClass >= 0)
	{
		//FirstClass
		if(firstClass == 0)
		{
			printf("\nNo hay pasajeros en FirstClass");
		}
		else
		{
			printf("\nHay %d pasajeros en FirstClass", firstClass);
		}

		//ExecutiveClass
		if(executiveClass == 0)
		{
			printf("\nNo hay pasajeros en ExecutiveClass");
		}
		else
		{
			printf("\nHay %d pasajeros en ExecutiveClass", executiveClass);
		}

		//EconomyClass
		if(economyClass == 0)
		{
			printf("\nNo hay pasajeros en EconomyClass");
		}
		else
		{
			printf("\nHay %d pasajeros en EconomyClass", economyClass);
		}
		retorno = 0;
	}
	return retorno;
}


LinkedList* Passenger_filtrarPasajerosPorClase(LinkedList* pArrayListPassenger)
{
	int option;
	LinkedList* auxListPassenger = NULL;

	if(utn_getNumberInt(&option, "\n1) Filtrar por FirstClass"
										"\n2) Filtrar por ExecutiveClass"
										"\n3) Filtrar por EconomyClass"
										"\n4) Volver al menu anterior"
										"\nIngrese el orden: ", "Orden incorrecto.\n", 1, 4, CANT_REINTENTOS) == 0)
	{
		switch(option)
		{
			case 1:
				auxListPassenger = ll_filter(pArrayListPassenger, Passenger_fnTipoFirstClass);
			break;
			case 2:
				auxListPassenger = ll_filter(pArrayListPassenger, Passenger_fnTipoExecutiveClass);
			break;
			case 3:
				auxListPassenger = ll_filter(pArrayListPassenger, Passenger_fnTipoEconomyClass);
			break;
		}

	}
	return auxListPassenger;
}

//Map
/*
void* Passenger_criterioMap(void* this)
{
	LinkedList* auxPassenger = NULL;
	LinkedList* PassengerMillas = NULL;

	if(this != NULL)
	{

	}
	return PassengerMillas;
}
*/
