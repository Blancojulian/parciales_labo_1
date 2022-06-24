/*
 ============================================================================
 Name        : sp_labo_1.c
 Author      : Blanco Julián Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn_biblioteca.h"
#include "parser.h"
#include "menu.h"

int main(void) {
	setbuf(stdout, NULL);


	int option = 0;
	LinkedList* listPassenger = ll_newLinkedList();

	do
	{
		option = 0;
		utn_showMenu(&option, listPassenger);
		switch(option)
		{
			case 1:
				if(controller_loadFromText("data.csv", listPassenger) == 0)
				{
					printf("Los datos se cargaron correctamente.\n");
				}
				break;
			case 2:
				if(controller_loadFromBinary("data.bin",listPassenger) == 0)
				{
					printf("Los datos se cargaron correctamente.\n");
				}
				break;
			case 3:
				if(controller_addPassenger(listPassenger) == 0)
				{
					printf("El pasajero se cargo correctamente.\n");
				}
				break;
			case 4:
				if(controller_editPassenger(listPassenger) == 0)
				{
					printf("El pasajero se modifico correctamente.\n");
				}
				break;
			case 5:
				if(controller_removePassenger(listPassenger) == 0)
				{
					printf("El pasajero se elimino correctamente.\n");
				}
				break;
			case 6:
				if(controller_ListPassenger(listPassenger) == 0)
				{
					printf("La lista se mostro correctamente.\n");
				}
				break;
			case 7:
				if(controller_sortPassenger(listPassenger) == 0)
				{
					printf("La lista se ordeno correctamente.\n");
				}
				break;
			case 8:
				if(controller_saveAsText("data.csv", listPassenger) == 0)
				{
					printf("Los datos se guardaron correctamente en el archivo de texto.\n");
				}
				break;
			case 9:
				if(controller_saveAsBinary("data.bin", listPassenger) == 0)
				{
					printf("Los datos se guardaron correctamente en el archivo binario.\n");
				}
				break;
			case 10:
				if(controller_informesPassenger(listPassenger) == 0)
				{
					printf("Salio de informes.\n");
				}
				break;
			case 11:
				printf("Adios.\n");
				break;
		}
	}while(option != OPTIONS);
	return EXIT_SUCCESS;
}
