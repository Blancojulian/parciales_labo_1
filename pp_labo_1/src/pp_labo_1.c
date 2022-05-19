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
#include "informes.h"
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
	int auxIdCensista;
	int auxIdZona;
	int auxField;
	int auxFieldDate;
	int auxFieldDirection;

	int optionInformes;
	int auxCountCensistas;
	int auxCodigoLocalidad;
	int auxIndex;


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
					"\n9. Informes"
					"\n10. Salir"
					"\nEliga la opcion correspondiente: ", "\nOpcion invalida.", 1, 9, CANT_REINTENTOS)==0)
			{
				printf("\nla opcion es: %d",option);
				if(((option >= 2 && option <= 3) || option == 7 || option == 5) && isEmptyArrayCensistas(arrayCensistas, LEN_ARRAY_CENSISTAS))
				{
					printf("\nSe debe cargar un censista para usar estas funciones.\n");
				}
				else if(((option >= 5 && option <= 6) || option == 8) && isEmptyArrayZonas(arrayZonas, LEN_ARRAY_ZONAS))
				{
					printf("\nSe debe cargar una zona para usar estas funciones.\n");
				}
				else
				{
					switch(option)
					{
						case 1:
							if(requestDataCensista(&auxCensista) == 0 &&
								addCensista(arrayCensistas, LEN_ARRAY_CENSISTAS, auxCensista.id, auxCensista.nombre, auxCensista.apellido, auxCensista.nacimiento, auxCensista.edad, auxCensista.direccion, auxCensista.estado) == 0)
							{
								printf("\nEl censista fue cargado correctamente.");
							}
							break;
						case 2:
							if(utn_getNumberInt(&auxIdCensista, "\nIngrese el id del censista que quiere modificar: ", "\nId invalido.", 1, LEN_ARRAY_CENSISTAS, CANT_REINTENTOS) == 0 &&
									utn_getNumberInt(&auxField, "\n1. Modificar el nombre del censista"
											"\n2. Modificar el apellido del censista"
											"\n3. Modificar edad"
											"\n4. Modificar fecha de nacimiento\n\t1. Modificar Día\n\t2. Modificar Mes\n\t3. Modificar Año"
											"\n5. Modificar dirección\n\t1. Modificar Calle\n\t1. Modificar Altura"
											"\n6. Cancelar"
											"\nEliga la opcion correspondiente: ", "\nOpción invalida.", 1, 6, CANT_REINTENTOS) == 0)
							{
								if(auxField >= 1 && auxField <= 3)
								{
									if(modifyCensista(arrayCensistas, LEN_ARRAY_CENSISTAS, auxIdCensista, auxField, 0, 0) == 0)
									{
										printf("\nEl censista fue modificado correctamente.");
									}
								}
								else if(auxField == 4 && utn_getNumberInt(&auxFieldDate,"\nFecha:\n1. Modificar Día\n2. Modificar Mes\n3. Modificar Año"
										"\nEliga la opcion correspondiente: ", "\nOpción invalida", 1, 3, CANT_REINTENTOS) == 0)
								{
									if(modifyCensista(arrayCensistas, LEN_ARRAY_CENSISTAS, auxIdCensista, auxField, auxFieldDate, 0) == 0)
									{
										printf("\nEl censista fue modificado correctamente.");
									}
								}
								else if(auxField == 5 && utn_getNumberInt(&auxFieldDirection,"\nDirección:\n1. Modificar Calle\n2. Modificar Altura"
										"\nEliga la opcion correspondiente: ", "\nOpción invalida", 1, 2, CANT_REINTENTOS) == 0)
								{
									if(modifyCensista(arrayCensistas, LEN_ARRAY_CENSISTAS, auxIdCensista, auxField, 0, auxFieldDirection) == 0)
									{
										printf("\nEl censista fue modificado correctamente.");
									}
								}
							}
							break;
						case 3:
							if(utn_getNumberInt(&auxIdCensista, "\nIngrese el id del censista(LIBERADO) que quiere dar de baja: ", "\nId invalido.", 1, LEN_ARRAY_CENSISTAS, CANT_REINTENTOS) == 0)
							{
								if(removeCensista(arrayCensistas, LEN_ARRAY_CENSISTAS, auxIdCensista) == 0)
								{
									printf("\nEl censista fue dado de baja correctamente.");
								}
							}
							break;
						case 4:
							if(requestDataZona(&auxZona, listLocalidades, LEN_ARRAY_LOCALIDADES) == 0 &&
									addZona(arrayZonas, LEN_ARRAY_ZONAS, auxZona.id, auxZona.calles, auxZona.localidad, auxZona.idCensista, auxZona.cantCensadosInSitu, auxZona.cantCensadosVirtual, auxZona.cantAusentes, auxZona.estado) == 0)
							{
								printf("\nLa Zona fue cargada correctamente.");
							}
							break;
						case 5:
							if(utn_getNumberInt(&auxIdZona, "\nIngrese el id de la zona(PENDIENTE) a asignar censista: ", "\nId invalido.", 1, LEN_ARRAY_ZONAS, CANT_REINTENTOS) == 0 &&
									utn_getNumberInt(&auxIdCensista, "\nIngrese el id del censista(LIBERADO): ", "\nId invalido.", 1, LEN_ARRAY_CENSISTAS, CANT_REINTENTOS) == 0 &&
									asignarCensistaAZona(arrayZonas, LEN_ARRAY_ZONAS, auxIdZona, arrayCensistas, LEN_ARRAY_CENSISTAS, auxIdCensista) == 0)
							{
								printf("\nEl censista fue asignado correctamente a zona.");
							}
							break;
						case 6:
							if(utn_getNumberInt(&auxIdZona, "\nIngrese el id de la zona(PENDIENTE) a asignar censista: ", "\nId invalido.", 1, LEN_ARRAY_ZONAS, CANT_REINTENTOS) == 0 &&
									cargaDatosAZona(arrayZonas, LEN_ARRAY_ZONAS, auxIdZona, arrayCensistas, LEN_ARRAY_CENSISTAS) == 0)
							{
								printf("\nSe cargaron datos del censo a la zona correctamente.");
							}
							break;
						case 7:
							if(printArrayCensistas(arrayCensistas, LEN_ARRAY_CENSISTAS) == 0)
							{
								printf("Se imprimio datos de censistas");
							}
							break;
						case 8:
							if(printArrayZonas(arrayZonas, LEN_ARRAY_ZONAS, arrayCensistas, LEN_ARRAY_CENSISTAS) == 0)
							{
								printf("Se imprimio datos de las zonas");
							}
							break;
						case 9:
							if(utn_getNumberInt(&optionInformes, "\n1. Informar cantidad de censistas en estado Activo con zona Pendiente."
									"\n2. Mostrar el listado de censistas de Avellaneda, Lanús, Lomas de Zamora o Banfield ordenados alfabéticamente por apellido y nombre."
									"\n3. Informar nombre de localidad con más casas ausentes."
									"\n4. Informar el censista cuya zona fue la más censada (total censados presencial y virtual)"
									"\n5. Informar el promedio de censos por censista/zona."
											"\n6. Cancelar"
											"\nEliga la opcion correspondiente: ", "\nOpción invalida.", 1, 6, CANT_REINTENTOS) == 0)
							{
								switch(optionInformes)
								{
								case 1://auxIdCensista
									if(informarCensistasActivosConZonasPendientes(arrayZonas, LEN_ARRAY_ZONAS, arrayCensistas, LEN_ARRAY_CENSISTAS, &auxCountCensistas) == 0)
									{
										printf("\nLa cantidad de censistas en estado Activo con zona Pendiente es %d", auxCountCensistas);
									}
									break;
								case 3:
									if(informarLocalidadConMasAusentes(arrayZonas, LEN_ARRAY_ZONAS, &auxCodigoLocalidad) == 0 &&
											findLocadidadByCodigo(listLocalidades, LEN_ARRAY_LOCALIDADES,auxCodigoLocalidad, &auxIndex) == 0)
									{
										printf("\nLa localidad con más casas ausentes es %s", listLocalidades[auxIndex].decripcion);
									}
									break;

								case 4:
									if(informarCensistaZonaMasCensada(arrayZonas, LEN_ARRAY_ZONAS, &auxIdCensista) == 0 &&
											findCensistaById(arrayCensistas, LEN_ARRAY_CENSISTAS, auxIdCensista, &auxIndex) == 0)
									{
										printf("\nEl censista cuya zona fue la más censada es %s %s ID: %d", arrayCensistas[auxIndex].apellido, arrayCensistas[auxIndex].nombre, arrayCensistas[auxIndex].id);
									}
									break;
								}
							}
							break;
					}
				}

			}
		}while(option != 10);
	}

	return EXIT_SUCCESS;
}
