/*
 * informes.h
 *
 *  Created on: 19 may. 2022
 *      Author: Blanco Julián Agustín
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "zona.h"

int informarCensistasActivosConZonasPendientes(Zona* listZonas, int lenZonas, Censista* listCensistas, int lenCensistas, int* countCensistas);
int informarLocalidadConMasAusentes(Zona* listZonas, int lenZonas, int* codigoLocalidad);
int informarCensistaZonaMasCensada(Zona* listZonas, int lenZonas, int* idCensista);

#endif /* INFORMES_H_ */
