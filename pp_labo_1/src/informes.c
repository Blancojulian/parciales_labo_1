/*
 * informes.c
 *
 *  Created on: 19 may. 2022
 *      Author: Blanco Julián Agustín
 */

#include "informes.h"

//Informar cantidad de censistas en estado Activo con zona Pendiente

int informarCensistasActivosConZonasPendientes(Zona* listZonas, int lenZonas, Censista* listCensistas, int lenCensistas, int* countCensistas)
{
	int retorno = -1;
	int i = 0;
	int auxCountCensistas = 0;
	int index;
	if(listZonas != NULL && lenZonas > 0 && listCensistas != NULL && lenCensistas > 0 && countCensistas != NULL)
	{
		for(i = 0; i < lenZonas; i++)
		{
			if(listZonas[i].estado == PENDIENTE && findCensistaById(listCensistas, lenCensistas, listZonas[i].idCensista, &index) == 0 &&
					listCensistas[index].estado == ACTIVO)
			{
				auxCountCensistas++;
			}
		}
		*countCensistas = auxCountCensistas;
		retorno = 0;
	}
	return retorno;
}

//Informar nombre de localidad con más casas ausentes

int informarLocalidadConMasAusentes(Zona* listZonas, int lenZonas, int* codigoLocalidad)
{
	int retorno = -1;
	int i = 0;
	int auxCantAusentes;
	int indexMasAusentes;
	int flag = 0;
	if(listZonas != NULL && lenZonas > 0  && codigoLocalidad != NULL)
	{
		for(i = 0; i < lenZonas; i++)
		{
			if(listZonas[i].estado == FINALIZADO  && listZonas[i].cantAusentes >= 0 && (flag == 0 || listZonas[i].cantAusentes > auxCantAusentes))
			{
				flag = 1;
				auxCantAusentes = listZonas[i].cantAusentes;
				indexMasAusentes = i;
			}
		}
		*codigoLocalidad = listZonas[indexMasAusentes].localidad.codigo;
		retorno = 0;
	}
	return retorno;
}

//Informar el censista cuya zona fue la más censada (total censados presencial y virtual)

int informarCensistaZonaMasCensada(Zona* listZonas, int lenZonas, int* idCensista)
{
	int retorno = -1;
	int i = 0;
	int auxCantCensados;
	int indexMasCensados;
	int flag = 0;
	int auxSumaCensados;
	if(listZonas != NULL && lenZonas > 0  && idCensista != NULL)
	{
		for(i = 0; i < lenZonas; i++)
		{
			auxSumaCensados = listZonas[i].cantCensadosInSitu + listZonas[i].cantCensadosVirtual;
			if(listZonas[i].estado == FINALIZADO  && auxSumaCensados >= 0 && (flag == 0 || auxSumaCensados > auxCantCensados))
			{
				flag = 1;
				auxCantCensados = auxSumaCensados;
				indexMasCensados = i;
			}
		}
		*idCensista = listZonas[indexMasCensados].idCensista;
		retorno = 0;
	}
	return retorno;
}
