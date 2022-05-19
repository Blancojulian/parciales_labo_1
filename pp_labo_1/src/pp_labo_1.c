/*
 ============================================================================
 Name        : pp_labo_1.c
 Author      : Blanco Julián Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "zona.h"
#define LEN_ARRAY_LOCALIDADES 4
#define LEN_ARRAY_CENSISTAS 500
#define LEN_ARRAY_ZONAS 500
#define CANT_REINTENTOS 3

int main(void) {
	setbuf(stdout, NULL);

	Locadidad listLocalidades[LEN_ARRAY_LOCALIDADES] = {
			{1, "BANFIELD"},
			{2, "LOMAS DE ZAMORA"},
			{3, "TEMPERLEY"},
			{4, "LANUS"}
	};
	Censista arrayCensistas[LEN_ARRAY_CENSISTAS];
	Zona arrayZonas[LEN_ARRAY_ZONAS];
	Censista auxCensista;
	Zona auxZona;
	int option;

	if(initCensistas(arrayCensistas, LEN_ARRAY_CENSISTAS) == 0 &&
			initZona(arrayZonas, LEN_ARRAY_ZONAS) == 0)
	{
		do{
			if(utn_getNumberInt(&option,"**********************Menu principal**********************\n"
					"\n1. Alta censista"
					"\n2. Modificación censista"
					"\n3. Baja censista"
					"\n4. Alta zona"
					"\n5. Asignar censista a zona"
					"\n6. Cargar de datos de zona censada"
					"\n7. Mostrar censistas"
					"\n8. Mostrar zonas"
					"\n9. Salir"
					"\nEliga la opcion correspondiente: ", "\nOpcion invalida.", 1, 9, CANT_REINTENTOS)==0)
			{
				printf("\nla opcion es: %d",option);
				if(option != 1 && isEmptyArrayCensistas(arrayCensistas, LEN_ARRAY_CENSISTAS))
				{
					printf("\nSe debe cargar un censista para usar estas funciones.\n");
				}
				else
				{
					switch(option)
					{

					}
				}

			}
			else
			{
				break;
			}

			if(!isEmptyArrayCensistas(arrayCensistas, LEN_ARRAY_CENSISTAS))
			{
				printf("\narray vacio");
			}
			else
			{
				printf("\narray con censistas");
			}

		}while(option != 9);
	}

	return EXIT_SUCCESS;
}
