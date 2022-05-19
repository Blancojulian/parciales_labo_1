/*
 * zona.c
 *
 *  Created on: 18 may. 2022
 *      Author: Blanco Julián Agustín
 */
#include "zona.h"

#define CANT_REINTENTOS 3

static int generateNewId(void);

/**
 * \brief Incrementa el id y lo retorna.
 * \return Retorna el id
 */
static int generateNewId(void)
{
	static int id = 0;

	id++;
	return id;
}

/**
 * \brief Inicializa el array de zonas.
 * \param Zona* list, Es el puntero al array de zonas.
 * \param int len, es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int initZona(Zona* list, int len)
{
    int retorno = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

/**
 * \brief Realiza el alta de un zona solo si el indice corresponde a un espacio vacio (isEmpty == 1)
 * \param Zona* list, Es el puntero al array de zonas.
 * \param int len, es el limite de array.
 * \param int id, indica el id de la zona.
 * \param Calles calles, indica las calles de la zona.
 * \param Locadidad localidad, indica la localidad de la zona.
 * \param int idCensista, indica el id del censista.
 * \param int edad, indica la edad del censista.
 * \param int estado, indica el estado de zona (1 - FINALIZADO | 0 - PENDIENTE).
 * \return (-1) Error / (0) Ok
 */
int addZona(Zona* list, int len, int id, Calles calles, Locadidad localidad, int idCensista, int cantCensadosInSitu, int cantCensadosVirtual, int cantAusentes, int estado)
{
    int retorno = -1;
    int index;
    if(list != NULL && len > 0 && id > 0 && idCensista >= 0 && calles.calle1 != NULL && calles.calle2 != NULL && calles.calle3 != NULL && calles.calle4 != NULL && cantCensadosInSitu >= 0 && cantCensadosVirtual >= 0 && cantAusentes >= 0 && (estado >= PENDIENTE && estado <= FINALIZADO))
    {
        if(searchFreeIndexZona(list, len, &index) == 0 && index < len)
        {
            list[index].id = id;
            list[index].idCensista = idCensista;
            list[index].calles = calles;
            list[index].localidad = localidad;
            list[index].cantCensadosInSitu = cantCensadosInSitu;
            list[index].cantCensadosVirtual = cantCensadosVirtual;
            list[index].cantAusentes = cantAusentes;
            list[index].estado = estado;
            list[index].isEmpty = 0;

            retorno = 0;
        }
        else
		{
			printf("No hay espacios libres para dar de alta.");
		}
    }


    return retorno;
}

/**
 * \brief Busca un espacio libre en el array de zonas.
 * \param Zona* list, Es el puntero al array de zonas.
 * \param int len, es el limite de array.
 * \param int* index, Es el puntero al index del espacio libre.
 * \return (-1) Error / (0) Ok
 */
int searchFreeIndexZona(Zona* list, int len, int* pIndex)
{
    int retorno = -1;

    if(list != NULL && len > 0 && pIndex != NULL)
    {
        int i = 0;
        while(i < len)
        {
            if(list[i].isEmpty == 1)
            {
                *pIndex = i;
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

/**
 * \brief Busca la zona por id y retorna su indice.
 * \param Zona* list, Es el puntero al array de zonas.
 * \param int len, es el limite de array.
 * \param int id, id que será buscado.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return Retorna el indice
 */
int findZonaById(Zona* list, int len, int id, int* pIndex)
{
    int retorno = -1;

    if(list != NULL && len > 0 && id > 0)
    {
        int i = 0;
        while(i < len)
        {
            if(id == list[i].id)
            {
            	*pIndex = i;
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

/**
 * \brief Realiza baja logica de una zona si el indice no está vacio.
 * \param Zona* list, Es el puntero al array de zonas.
 * \param int len, es el limite de array.
 * \param int id, es el id de la zona a remover.
 * \return (-1) Error / (0) Ok
 */
int removeZona(Zona* list, int len, int id)
{
    int retorno = -1;
    int index;
    if(list != NULL && len > 0 && id > 0 && findZonaById(list, len, id, &index) == 0)
    {
        if(list[index].isEmpty == 0 && index >= 0 && list[index].estado == PENDIENTE)
        {
        	list[index].estado = FINALIZADO;
            //list[index].isEmpty = 1;
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Solicita los datos de la zona al usuario.
 * \param Zona* pZona, Es el puntero al espacio de memoria.
 * \param Locadidad* list, Es el puntero al array de localidades.
 * \param int len, es el limite de array. Uso esta como limite ya que es un array hardcodeado
 * \return (-1) Error / (0) Ok
 */
int requestDataZona(Zona* pZona, Locadidad* listLocalidades, int len)
{
	int retorno = -1;
	Zona aux;
	int codigo;
	int index;

	if(pZona != NULL)
	{
		if(utn_getStreet(aux.calles.calle1, "\nIngrese las cuatro calles de la zona\nIngrese primer calle: ", "\nCalle invalida.", CANT_REINTENTOS, LEN_STRING) == 0 &&
				utn_getStreet(aux.calles.calle2, "\nIngrese segunda calle: ", "\nCalle invalida.", CANT_REINTENTOS, LEN_STRING) == 0 &&
				utn_getStreet(aux.calles.calle3, "\nIngrese tercera calle: ", "\nCalle invalida.", CANT_REINTENTOS, LEN_STRING) == 0 &&
				utn_getStreet(aux.calles.calle4, "\nIngrese cuarta calle: ", "\nCalle invalida.", CANT_REINTENTOS, LEN_STRING) == 0 &&
				printArrayLocadidades(listLocalidades, len) == 0 &&
				utn_getNumberInt(&codigo, "\nIngrese codigo de la localidad: ", "\nCodigo invalido.", 1, len, CANT_REINTENTOS) == 0 &&
				findLocadidadByCodigo(listLocalidades, len, codigo, &index) == 0)
		{
		    aux.id = generateNewId();
		    aux.localidad = listLocalidades[index];
		    aux.idCensista = SIN_ASIGNAR;
		    aux.cantCensadosInSitu = 0;
		    aux.cantCensadosVirtual = 0;
		    aux.cantAusentes = 0;
		    aux.estado = PENDIENTE;
			*pZona = aux;
			retorno = 0;
		}
		else
		{
			printf("Error al ingresar los datos.");
		}
	}
	return retorno;
}

/**
 * \brief Controla si el array tiene censistas cargados.
 * \param Censista* list, Es el puntero al array de censistas.
 * \param int len, es el limite de array.
 * \return (1) true, esta vacio / (0) false, tiene pasajeros cargados
 */
int isEmptyArrayZonas(Zona* list, int len)
{
	int retorno = 1;
	int i = 0;

	if (list != NULL && len > 0)
	{
	    while(i < len)
	    {
	        if(list[i].isEmpty == 0)
			{
				retorno = 0;
				break;
			}
			i++;
	    }
	}
	return retorno;
}

/**
 * \brief Busca la zona por codigo y retorna su indice.
 * \param Locadidad* list, Es el puntero al array de localidades.
 * \param int len, es el limite de array.
 * \param int id, id que será buscado.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return Retorna el indice
 */
int findLocadidadByCodigo(Locadidad* list, int len, int codigo, int* pIndex)
{
    int retorno = -1;

    if(list != NULL && len > 0 && codigo > 0)
    {
        int i = 0;
        while(i < len)
        {
            if(codigo == list[i].codigo)
            {
            	*pIndex = i;
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}
/**
 * \brief Imprime las localidades hardcodeadas.
 * \param Censista* list, Es el puntero al array de localidades.
 * \param int len, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int printArrayLocadidades(Locadidad* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			printf("%d) %s", list[i].codigo, list[i].decripcion);
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Imprime las zonas cargados.
 * \param Zona* list, Es el puntero al array de zonas.
 * \param int len, es el limite de array
 * \return (-1) Error / (0) Ok
 */

int printArrayZonas(Zona* list, int len, Censista* listCensistas, int lenCensistas)
{
	int retorno = -1;
	int i;
	int index;

	if(list != NULL && len > 0 && listCensistas != NULL && lenCensistas > 0)
	{
		for (i = 0; i < len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				printf("\nID: %d - Calles: %s, %s, %s y %s - Localidad: %s", list[i].id, list[i].calles.calle1, list[i].calles.calle2, list[i].calles.calle3, list[i].calles.calle4, list[i].localidad.decripcion);
				if(list[i].idCensista == SIN_ASIGNAR)
				{
					printf("\nNo se asigno censista");
				}
				else if(findCensistaById(listCensistas, lenCensistas, list[i].idCensista, &index) == 0)
				{
					printf("\nNombre censista: %s - Apellido censista: %s", listCensistas[index].nombre, listCensistas[index].apellido);
				}

				if(list[i].estado == PENDIENTE)
				{
					printf("\nLa zona sigue pendiente a censar");
				}
				else
				{
					printf("\nCantidad censados in situ: %d\nCantidad de censados que completaron el formulario virtual: %d\nCantidad ausentes: %d\n\n", list[i].cantCensadosInSitu, list[i].cantCensadosVirtual, list[i].cantAusentes);
				}

			}
		}
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Asigna un censista, con estado LIBERADO, a una zona.
 * \param Zona* list, Es el puntero al array de zonas.
 * \param int len, es el limite de array de zonas.
 * \param int idZona, es el id de la zona a asignar.
 * \param Censista* listCensistas, Es el puntero al array de zonas.
 * \param int lenCensistas, es el limite de array de censistas.
 * \param int idCensista, es el id del censista.
 * \return (-1) Error / (0) Ok
 */
int asignarCensistaAZona(Zona* list, int len, int idZona, Censista* listCensistas, int lenCensistas, int idCensista)
{
	int retorno = -1;
	int indexZona;
	int indexCensista;

	if(list != NULL && len > 0 && listCensistas != NULL && lenCensistas > 0 &&
			findCensistaById(listCensistas, lenCensistas, idCensista, &indexCensista) == 0 &&
			findZonaById(list, len, idZona, &indexZona) == 0 &&
			listCensistas[indexCensista].estado == LIBERADO)
	{
		list[indexZona].idCensista = listCensistas[indexCensista].id;
		listCensistas[indexCensista].estado = ACTIVO;

		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Realiza la carga de los datos de una zona y cambia el estado a finalizado si el indice no está vacio, asignado un censista y estado pendiente.
 * \param Zona* list, Es el puntero al array de zonas.
 * \param int len, es el limite de array de zonas.
 * \param Censista* listCensistas, Es el puntero al array de zonas.
 * \param int lenCensistas, es el limite de array de censistas.
 * \param int id, es el id de la zona a cargar datos.
 * \return (-1) Error / (0) Ok
 */
int cargaDatosAZona(Zona* list, int len, int id, Censista* listCensistas, int lenCensistas)
{
    int retorno = -1;
    Zona aux;
    int indexZona;
    int indexCensista;
    if(list != NULL && len > 0 && id > 0 && listCensistas != NULL && lenCensistas > 0 &&
    		findZonaById(list, len, id, &indexZona) == 0 &&
			findCensistaById(listCensistas, lenCensistas, list[indexZona].idCensista, &indexCensista) == 0)
    {
        if(list[indexZona].isEmpty == 0 && indexZona >= 0 && list[indexZona].estado == PENDIENTE && list[indexZona].idCensista > SIN_ASIGNAR)
        {

        	aux = list[indexZona];
        	if(utn_getNumberInt(&aux.cantCensadosInSitu, "\nIngrese cantidad censados in situ: ", "\nNumero invalido.", 1, MAX_CASAS_ZONA, CANT_REINTENTOS) == 0 &&
				utn_getNumberInt(&aux.cantCensadosVirtual, "\nIngrese cantidad de censados que completaron el formulario virtual: ", "\nNumero invalido.", 1, MAX_CASAS_ZONA, CANT_REINTENTOS) == 0 &&
				utn_getNumberInt(&aux.cantAusentes, "\nIngrese cantidad ausentes: ", "\nNumero invalido.", 1, MAX_CASAS_ZONA, CANT_REINTENTOS) == 0)

        	aux.estado = FINALIZADO;
        	list[indexZona] = aux;
        	listCensistas[indexCensista].estado = LIBERADO;
            //list[indexZona].isEmpty = 1;
            retorno = 0;
        }
    }
    return retorno;
}

/**
 * \brief Realiza el alta forzada de un censista solo si el indice corresponde a un espacio vacio (isEmpty == 1)
 * \param Censista* list, Es el puntero al array de censistas.
 * \param int len, es el limite de array.
 * \param int id, indica el id del censista.
 * \param char* nombre, indica el nombre del censista.
 * \param char* apellido, indica el apellido del censista.
 * \param Fecha nacimiento, indica la fecha de nacimiento del censista.
 * \param int edad, indica la edad del censista.
 * \param int estado, indica el estado de censista (0 - PENDIENTE | 1 - FINALIZADO).
 * \param char* direccion, indica la direccion del censista.
 * \return (-1) Error / (0) Ok
 */
int altaForzadaZona(Zona* list, int len, Locadidad* listLocalidad, int lenLocalidad, char* calle1, char* calle2, char* calle3, char* calle4, int codigoLocalidad, int idCensista, int cantCensadosInSitu, int cantCensadosVirtual, int cantAusentes, int estado)
{
	int retorno = -1;
	Locadidad auxLocadidad;
	Calles auxCalles;
	int indexLocalidad;
	int id;
	if(list != NULL && len > 0 && listLocalidad != NULL && lenLocalidad > 0 && idCensista >= SIN_ASIGNAR &&
			cantCensadosInSitu >= 0 && cantCensadosVirtual >= 0 && cantAusentes >= 0 && (estado >= PENDIENTE || estado <= FINALIZADO) &&
			findLocadidadByCodigo(listLocalidad, lenLocalidad, codigoLocalidad, &indexLocalidad) == 0)
	{
		id = generateNewId();
		auxLocadidad = listLocalidad[indexLocalidad];
		strncpy(auxCalles.calle1, calle1, LEN_STRING);
		strncpy(auxCalles.calle2, calle2, LEN_STRING);
		strncpy(auxCalles.calle3, calle3, LEN_STRING);
		strncpy(auxCalles.calle4, calle4, LEN_STRING);

		if(addZona(list, len, id, auxCalles, auxLocadidad, idCensista, cantCensadosInSitu, cantCensadosVirtual, cantAusentes, estado) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}
