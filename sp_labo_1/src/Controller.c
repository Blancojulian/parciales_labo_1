#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn_biblioteca.h"
#include "Controller.h"
#define CANT_REINTENTOS 2


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo que va a ser leído.
 * \param pArrayListPassenger LinkedList* recibe el array
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL)
	{

		pFile = fopen(path,"r");

		if(pFile != NULL && !(parser_PassengerFromText(pFile, pArrayListPassenger)))
		{
			retorno = 0;
			fclose(pFile);
		}
		else
		{
			printf("No se pudo abrir el archivo.\n");
		}
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char* archivo que va a ser leído.
 * \param pArrayListPassenger LinkedList* recibe el array
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	FILE* pFile;
	if(path != NULL && pArrayListPassenger != NULL)// && ll_clear(pArrayListPassenger) == 0)
	{
		pFile = fopen(path,"rb");
		if(pFile != NULL && !(parser_PassengerFromBinary(pFile, pArrayListPassenger)))
		{
			retorno = 0;
			fclose(pFile);
		}
		else
		{
			printf("No se pudo abrir el archivo.\n");
		}
	}
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;

	Passenger* auxPassenger;
	Passenger auxParams;
	int auxId;

	if(pArrayListPassenger != NULL)
	{
		if(requestDataPassenger(&auxParams) == 0 &&Passenger_findMaxId(pArrayListPassenger, &auxId) == 0)
		{
			auxPassenger = Passenger_newParametros_types(auxId, auxParams.nombre, auxParams.apellido, auxParams.precio, auxParams.codigoVuelo, auxParams.tipoPasajero, auxParams.estadoVuelo);
			ll_add(pArrayListPassenger, auxPassenger);
			retorno = 0;
		}
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* pPassenger;
	Passenger* auxPassenger;

	int id;
	int maxId;
	int index;

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		if( Passenger_findMaxId(pArrayListPassenger, &maxId) == 0 &&
			utn_getNumberInt(&id ,"Ingrese el ID del pasajero a modificar: ", "ID invalido.\n", 0, (maxId - 1), CANT_REINTENTOS) == 0 &&
			Passenger_findById(pArrayListPassenger, id, &index) == 0)
		{
			pPassenger = (Passenger*)ll_get(pArrayListPassenger, index);
			auxPassenger = (Passenger*)Passenger_modifyPassenger(pPassenger);

			if(auxPassenger != NULL)// && Passenger_modifyPassenger(auxPassenger) == 0)
			{
				Passenger_delete(pPassenger);
				retorno = ll_set(pArrayListPassenger, index, auxPassenger);
			}
			else
			{
				printf("El ID seleccionado no corresponde a un pasajero de la lista.\n");
			}
		}

	}
	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param pArrayListPassenger LinkedList* recibe el array.
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int id;
	int index;
	int maxId;
	Passenger* auxPassenger;

	if(pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		if(Passenger_findMaxId(pArrayListPassenger, &maxId) == 0 &&
			utn_getNumberInt(&id ,"Ingrese el ID del pasajero a eliminar: ", "ID invalido.\n", 1, (maxId - 1), CANT_REINTENTOS) == 0 &&
			Passenger_findById(pArrayListPassenger, id, &index))
		{
			auxPassenger = (Passenger*)ll_get(pArrayListPassenger, index);
			if(auxPassenger != NULL)
			{
				ll_remove(pArrayListPassenger, index);
				Passenger_delete(auxPassenger);
				retorno = 0;
			}
		}
		else
		{
			printf("El ID seleccionado no corresponde a un empleado de la lista.\n");
		}
	}
	return retorno;
}

/** \brief Listar pasajeros
 *
 * \param pArrayListPassenger LinkedList* recibe el array
 * \return (-1) Error / (0) Ok
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int len;
	int i;
	Passenger* auxPassenger;

	len = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL && len > 0)
	{
		printf("\nID\t|\tNombre\t|\tApellido\t|\tPrecio\t|\tTipo de pasajero\t|\tCodigo de vuelo\t|\tEstado de vuelo\n");
		for (i = 0; i < len; i++)
		{
			auxPassenger = (Passenger*)ll_get(pArrayListPassenger, i);
			if(auxPassenger != NULL)
			{
				Passenger_printPassenger(auxPassenger);
			}
		}
	}
	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param pArrayListPassenger LinkedList*, recibe el array.
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int orden;
	int option;

	if(pArrayListPassenger != NULL &&
			utn_getNumberInt(&option, "\n1) Ordenar por Id\n2) Ordenar por Nombre"
					"\n3) Ordenar por Apellido\n4) Ordenar por precio"
					"\n5) Ordenar por codigo de vuelo\n6) Ordenar por tipo de pasajero"
					"\n7) Ordenar por estado de vuelo\nIngrese el orden: ", "Orden incorrecto.\n", 1, 7, CANT_REINTENTOS) == 0 &&
			utn_getNumberInt(&orden, "1) Descendente\n2) Ascendente\nIngrese el orden: ", "Orden incorrecto.\n", 1, 2, CANT_REINTENTOS) == 0)
	{
		orden--;
		switch(option)
		{
			case 1:
				if(ll_sort(pArrayListPassenger, Passenger_funcionCriterioId, orden) == 0){
					retorno = 0;
				}
				break;
			case 2:
				if(ll_sort(pArrayListPassenger, Passenger_funcionCriterioNombre, orden) == 0){
					retorno = 0;
				}
				break;
			case 3:
				if(ll_sort(pArrayListPassenger, Passenger_funcionCriterioApellido, orden) == 0){
					retorno = 0;
				}
				break;
			case 4:
				if(ll_sort(pArrayListPassenger, Passenger_funcionCriterioPrecio, orden) == 0){
					retorno = 0;
				}
				break;
			case 5:
				if(ll_sort(pArrayListPassenger, Passenger_funcionCriterioCodigoVuelo, orden) == 0){
					retorno = 0;
				}
				break;
			case 6:
				if(ll_sort(pArrayListPassenger, Passenger_funcionCriterioTipoPasajero, orden) == 0){
					retorno = 0;
				}
				break;
			case 7:
				if(ll_sort(pArrayListPassenger, Passenger_funcionCriterioEstadoVuelo, orden) == 0){
					retorno = 0;
				}
				break;
		}

	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*, archivo que va a ser escrito.
 * \param pArrayListPassenger LinkedList*, recibe el array.
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int len = ll_len(pArrayListPassenger);
	int i;
	Passenger* auxPassenger;
	Passenger auxParams;
	char auxTipoPasajero[LEN_STRING];
	char auxEstadoVuelo[LEN_STRING];
	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL && len > 0)
	{
		pFile = fopen(path,"w");
		if(pFile != NULL)
		{
			fprintf(pFile, "id,name,lastname,price,flycode,typePassenger,statusFlight\n");
			for (i = 0; i < len; i++)
			{
				auxPassenger = ll_get(pArrayListPassenger, i);
				if(Passenger_getId(auxPassenger, &auxParams.id)==0 &&
					Passenger_getNombre(auxPassenger, auxParams.nombre)==0 &&
					Passenger_getApellido(auxPassenger, auxParams.apellido)==0 &&
					Passenger_getPrecio(auxPassenger, &auxParams.precio)==0 &&
					Passenger_getCodigoVuelo(auxPassenger, auxParams.codigoVuelo)==0 &&
					Passenger_getTipoPasajero(auxPassenger, &auxParams.tipoPasajero)==0 &&
					Passenger_getEstadoVuelo(auxPassenger, &auxParams.estadoVuelo)==0 &&
					Passenger_getTextTipoPasajero(auxParams.tipoPasajero, auxTipoPasajero) == 0 &&
					Passenger_getTextEstadoVueldo(auxParams.estadoVuelo, auxEstadoVuelo) == 0)
				{
					fprintf(pFile, "%d,%s,%s,%.2f,%s,%s,%s\n",auxParams.id, auxParams.nombre, auxParams.apellido, auxParams.precio, auxParams.codigoVuelo, auxTipoPasajero, auxEstadoVuelo);
					retorno = 0;
				}
			}
		}
		else
		{
			printf("No se pudo abrir el archivo.\n");
		}

		fclose(pFile);
	}

	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*, archivo que va a ser escrito.
 * \param pArrayListPassenger LinkedList*, recibe el array.
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	Passenger* auxPassenger;
	int len = ll_len(pArrayListPassenger);
	FILE* pFile;

	if(path != NULL && pArrayListPassenger != NULL && len > 0)
	{
		pFile = fopen(path,"wb");
		if (pFile != NULL)
		{
			for(int i = 0; i < len; i++)
			{
				auxPassenger = ll_get(pArrayListPassenger, i);
				fwrite(auxPassenger, sizeof(Passenger), 1, pFile);
			}
			retorno = 0;
		}
		else
		{
			printf("No se pudo abrir el archivo.\n");
		}

		fclose(pFile);
	}

	return retorno;
}

/** \brief Informes de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_informesPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int option = 0;
	LinkedList* auxListPassenger = NULL;

	if(pArrayListPassenger != NULL)
	{
		if(utn_getNumberInt(&option, "\n1) Informar cantidad de pasajeros por clase"
				"\n2) Generar archivo de vuelos por clase de pasajero"
				"\n3) Calcular millas acumuladas"
				"\n4) Volver al menu anterior"
				"\nIngrese el orden: ", "Orden incorrecto.\n", 1, 4, CANT_REINTENTOS) == 0)
		{
			switch(option)
			{
				case 1:
					Passenger_imprimiCantidadPasajerosPorClase(pArrayListPassenger);
				break;
				case 2:
					auxListPassenger = Passenger_filtrarPasajerosPorClase(pArrayListPassenger);
					if(auxListPassenger != NULL && controller_saveAsText("dataFilter.csv" , auxListPassenger) == 0)
					{
						ll_deleteLinkedList(pArrayListPassenger);
						pArrayListPassenger = NULL;
						printf("Los datos se guardaron correctamente en el archivo de texto.\n");
					}
				break;
				case 3:
					printf("\nopcion 3");
				break;
			}
		}
	}

	return retorno;
}
