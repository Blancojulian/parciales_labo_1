/*
 * menu.c
 *
 *  Created on: 11 jun. 2022
 *      Author: Blanco Julián Agustín
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"
#include "utn_biblioteca.h"
#include "menu.h"
#include "LinkedList.h"
/**
 * \brief	Muestra el menu principal.
 * \param	int* pOption, puntero a un espacio de memoria.
 * \return	Retorna 0 (exito)y -1 (error).
 */
int utn_showMenu(int* pOption, LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	int option;

	if(pOption != NULL)
	{
		if(utn_getNumberInt(&option, "***Menu de opciones***\n\n"
									 "1- Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
									 "2- Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
									 "3- Alta de pasajero.\n"
									 "4- Modificar datos de pasajero.\n"
									 "5- Baja de pasajero.\n"
									 "6- Listar pasajeros.\n"
									 "7- Ordenar pasajeros.\n"
									 "8- Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
									 "9- Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
									 "10- Salir.\n\n"
									 "Ingrese la opcion: ", "Opcion ingresada invalida.\n", 1, OPTIONS, 2) == 0 &&
		ll_isEmpty(pArrayListPassenger) && option > 2 && option < 10)
		{
			printf("Primero se debe cargar la lista.\n");
		}
		else
		{
			if(ll_isEmpty(pArrayListPassenger) == 0 && option < 3)
			{
				printf("La lista ya fue cargada.\n");
			}
			else
			{
				*pOption = option;
				retorno = 0;
			}
		}
	}
	return retorno;
}
