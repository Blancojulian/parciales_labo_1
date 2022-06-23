#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#define LEN_BUFFER_STR 4096

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* auxPassenger;
	int r;

	char id[LEN_BUFFER_STR];
	char nombre[LEN_BUFFER_STR];
	char apellido[LEN_BUFFER_STR];
	char precio[LEN_BUFFER_STR];
	char codigoVuelo[LEN_BUFFER_STR];
	char tipoPasajero[LEN_BUFFER_STR];
	char estadoVuelo[LEN_BUFFER_STR];

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);

			auxPassenger = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
			if(auxPassenger != NULL)
			{
				if(r == 7)
				{
					//printf("id: %d", auxPassenger->id);
					ll_add(pArrayListPassenger, auxPassenger);
					retorno = 0;
				}
				else
				{
					Passenger_delete(auxPassenger);
				}
			}
		}while(!feof(pFile));
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{

	int retorno = -1;
	Passenger* auxPassenger;
	int r;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		do
		{
			auxPassenger = Passenger_new();
			r = fread(auxPassenger, sizeof(Passenger), 1, pFile);
			if(auxPassenger != NULL)
			{
				if(r == 1)
				{
					ll_add(pArrayListPassenger, auxPassenger);
					retorno = 0;
				}
				else
				{
					Passenger_delete(auxPassenger);
				}
			}
		}while(!feof(pFile));
	}
	return retorno;
}
