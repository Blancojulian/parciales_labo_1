/*
 * censista.c
 *
 *  Created on: 18 may. 2022
 *      Author: Blanco Julián Agustín
 */


#include "censista.h"
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
 * \brief Inicializa el array de censistas.
 * \param Censista* list, Es el puntero al array de censistas.
 * \param int len, es el limite de array.
 * \return (-1) Error / (0) Ok
 */
int initCensistas(Censista* list, int len)
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
 * \brief Realiza el alta de un censista solo si el indice corresponde a un espacio vacio (isEmpty == 1)
 * \param Censista* list, Es el puntero al array de censistas.
 * \param int len, es el limite de array.
 * \param int id, indica el id del censista.
 * \param char* nombre, indica el nombre del censista.
 * \param char* apellido, indica el apellido del censista.
 * \param Fecha nacimiento, indica la fecha de nacimiento del censista.
 * \param int edad, indica la edad del censista.
 * \param int estado, indica el estado de censista (1 - ACTIVO | 0 - INACTIVO).
 * \param char* direccion, indica la direccion del censista.
 * \return (-1) Error / (0) Ok
 */
int addCensista(Censista* list, int len, int id, char* nombre, char* apellido, Fecha nacimiento, int edad, Direccion direccion, int estado)
{
    int retorno = -1;
    int index;
    if(list != NULL && len > 0 && id > 0 && nombre != NULL && apellido != NULL && edad > 0 && direccion.calle != NULL && direccion.altura > 0 && (estado >= LIBERADO && estado <= INACTIVO))
    {
        if(searchFreeIndex(list, len, &index) == 0 && index < len)
        {
            list[index].id = id;
            strncpy(list[index].nombre, nombre, LEN_STRING);
            strncpy(list[index].apellido, apellido, LEN_STRING);
            list[index].nacimiento = nacimiento;
            list[index].edad = edad;
            list[index].direccion = direccion;
            //strncpy(list[index].direccion.calle, direccion, LEN_STRING);
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
 * \brief Busca un espacio libre en el array de censistas.
 * \param Censista* list, Es el puntero al array de censistas.
 * \param int len, es el limite de array.
 * \param int* index, Es el puntero al index del espacio libre.
 * \return (-1) Error / (0) Ok
 */
int searchFreeIndex(Censista* list, int len, int* pIndex)
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
 * \brief Busca el censista por id y retorna su indice.
 * \param Censista* list, Es el puntero al array de censistas.
 * \param int len, es el limite de array.
 * \param int id, id que será buscado.
 * \param int* pIndex, puntero al espacio de memoria.
 * \return Retorna el indice
 */
int findCensistaById(Censista* list, int len, int id, int* pIndex)
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
 * \brief Realiza baja logica de un censista si el indice no está vacio.
 * \param Censista* list, Es el puntero al array de censistas.
 * \param int len, es el limite de array.
 * \param int id, es el id del censista a remover.
 * \return (-1) Error / (0) Ok
 */
int removeCensista(Censista* list, int len, int id)
{
    int retorno = -1;
    int index;
    if(list != NULL && len > 0 && id > 0 && findCensistaById(list, len, id, &index) == 0)
    {
        if(list[index].isEmpty == 0 && index >= 0 && list[index].estado == LIBERADO)
        {
        	list[index].estado = INACTIVO;
            //list[index].isEmpty = 1;
            retorno = 0;
        }
    }
    return retorno;
}

/*
 * \ brief - Ordena array de censistas por apellido y estado de manera ascendente o descendente.
 * \ param - Censista* list, recibe el array a utilizar.
 * \ param - int len, indica la longitud del array.
 * \ param - int order, indica el orden de los elementos. 1 en caso de ascendente y 0 en caso de descendente.
 * \ return - (-1) en caso de error / (0) en caso de funcionar.
 */
int sortCensistas(Censista* list, int len, int order)
{
	Censista aux;
    int retorno = -1;
    int flagSwap = 0;
    int i = 0;
    int auxComparacion;

    if(list != NULL && len > 0 && (order == 0 || order == 1))
    {
        do
        {
            flagSwap = 0;
            len--;
            for(i = 0; i < len; i++)
            {
                // 0 - orden descendente
                // 1 - orden ascendente
            	auxComparacion = strncmp(list[i].apellido, list[i+1].apellido, LEN_STRING);
                if((order == 0 && auxComparacion < 0) ||
                    (order == 1 && auxComparacion > 0) ||
                    (auxComparacion == 0 &&
                    ((order == 0 && list[i].estado < list[i+1].estado) ||
                    (order == 1 && list[i].estado > list[i+1].estado))))
                {
                    aux = list[i+1];
                    list[i+1] = list[i];
                    list[i] = aux;
                    flagSwap = 1;
                }
            }
        }while(flagSwap);
        retorno = 0;
    }
    return retorno;
}

/**
 * \brief Modifica datos de un censista si el id es valido.
 * \param Censista* list, Es el puntero al array de censistas.
 * \param int len, es el limite de array.
 * \param int id, es el id del censista a modificar.
 * \param int field, indica el campo que será modificado.
 * \param int fieldDate, indica el campo de la estuctura Fecha que será modificado.
 * \param int fieldDirection, indica el campo de la estuctura Direccion que será modificado.
 * \return (-1) Error / (0) Ok
 */
int modifyCensista(Censista* list, int len, int id, int field, int fieldDate, int fieldDirection)
{
	int retorno = -1;
	Censista aux;
	int index;

	if(list != NULL && len > 0  && findCensistaById(list, len, id, &index) == 0 && list[index].isEmpty == 0)
	{
	    aux = list[index];
		if( (field == 1 && utn_getName(aux.nombre, "\nIngrese el nombre del censista: ", "\nNombre invalido.", CANT_REINTENTOS, LEN_STRING) == 0) ||
			(field == 2 && utn_getName(aux.apellido, "\nIngrese el apellido del censista: ", "\nApellido invalido.", CANT_REINTENTOS, LEN_STRING) == 0) ||
			(field == 3 && utn_getNumberInt(&aux.edad, "\nIngrese edad(hasta 60 años): ", "\nEdad invalido.", 1, 60, CANT_REINTENTOS) == 0) ||
			(field == 4 && utn_modifyDateByField(&aux.nacimiento, fieldDate, "\nIngrese fecha de nacimiento", "\nFecha invalida", CANT_REINTENTOS) == 0) ||
			//(field == 4 && utn_getNumberInt(&aux.estado, "\n1) Liberado\n2) Activo\n3) Inactivo\nIngrese estado del censista: ", "\nEstado de censista invalido.", LIBERADO, ACTIVO, CANT_REINTENTOS) == 0) ||
			(field == 5 && ((fieldDirection == 1 && utn_getStreet(aux.direccion.calle, "\nIngrese calle: ", "\nCalle invalido.", CANT_REINTENTOS, LEN_STRING) == 0) ||
			(fieldDirection == 2 && utn_getNumberInt(&aux.direccion.altura, "\nIngrese altura: ", "\nAltura invalida.", 1, MAX_ALTURA, CANT_REINTENTOS) == 0))))
		{
			aux.isEmpty = 0;
			list[index] = aux;
			retorno = 0;
		}
	}
	return retorno;
}

/**
 * \brief Solicita los datos del censista al usuario.
 * \param Censista* auxCensista, Es el puntero al espacio de memoria.
 * \return (-1) Error / (0) Ok
 */
int requestDataCensista(Censista* auxCensista)
{
	int retorno = -1;
	Censista aux;

	if(auxCensista != NULL)
	{
		if(utn_getName(aux.nombre, "\nIngrese el nombre del censista: ", "\nNombre invalido.", CANT_REINTENTOS, LEN_STRING) == 0 &&
		    utn_getName(aux.apellido, "\nIngrese el apellido del censista: ", "\nApellido invalido.", CANT_REINTENTOS, LEN_STRING) == 0 &&
			utn_getNumberInt(&aux.edad, "\nIngrese edad(hasta 60 años): ", "\nPrecio invalido.", 1, 60, CANT_REINTENTOS) == 0 &&
			//utn_getNumberInt(&aux.estado, "\n1) Liberado\n2) Activo\n3) Inactivo\nIngrese estado del censista: ", "\nEstado de censista invalido.", LIBERADO, INACTIVO, CANT_REINTENTOS) == 0 &&
			utn_getStreet(aux.direccion.calle, "\nIngrese calle: ", "\nCalle invalido.", CANT_REINTENTOS, LEN_STRING) == 0 &&
			utn_getNumberInt(&aux.direccion.altura, "\nIngrese altura: ", "\nAltura invalido.", 1, MAX_ALTURA, CANT_REINTENTOS) == 0 &&
			utn_getDate(&aux.nacimiento, "\nIngrese fecha de nacimiento", "\nFecha invalida", CANT_REINTENTOS) == 0)
		{
		    aux.id = generateNewId();
		    aux.estado = LIBERADO;
			*auxCensista = aux;
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
int isEmptyArrayCensistas(Censista* list, int len)
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
 * \brief Realiza el alta forzada de un censista solo si el indice corresponde a un espacio vacio (isEmpty == 1)
 * \param Censista* list, Es el puntero al array de censistas.
 * \param int len, es el limite de array.
 * \param int id, indica el id del censista.
 * \param char* nombre, indica el nombre del censista.
 * \param char* apellido, indica el apellido del censista.
 * \param Fecha nacimiento, indica la fecha de nacimiento del censista.
 * \param int edad, indica la edad del censista.
 * \param int estado, indica el estado de censista (1 - LIBERADO | 2 - ACTIVO | 3 - INACTIVO).
 * \param char* direccion, indica la direccion del censista.
 * \return (-1) Error / (0) Ok
 */
int altaForzadaCensista(Censista* list, int len, char* nombre, char* apellido, int dia, int mes, int anio, int edad, char* calle, int altura, int estado)
{
	int retorno = -1;
	Fecha auxFecha;
	Direccion auxDireccion;
	int id;
	if(list != NULL && len > 0 && nombre != NULL && apellido != NULL && edad > 0 && calle != NULL && altura > 0 &&
			(estado >= LIBERADO || estado <= INACTIVO) && isValidDate(dia, mes, anio))
	{
		id = generateNewId();
		strncpy(auxDireccion.calle, calle, LEN_STRING);
		auxDireccion.altura = altura;
		auxFecha.dia = dia;
		auxFecha.mes = mes;
		auxFecha.anio = anio;
		if(addCensista(list, len, id, nombre, apellido, auxFecha, edad, auxDireccion, estado) == 0)
		{
			retorno = 0;
		}
	}
	return retorno;
}
/**
 * \brief Imprime los datos de un censista.
 * \param Censista* pCensista, Es el puntero al censista.
 * \return (-1) Error / (0) Ok
 */
int printCensista(Censista* pCensista)
{
	int retorno = -1;

	if(pCensista != NULL && pCensista->isEmpty == 0)
	{
		printf( "Id: %d - Nombre: %s - Apellido: %s - Fecha de nacimiento: %d/%d/%d - Edad: %d - Direccion: %s %d - Estado: %d.\n"
						,pCensista->id , pCensista->apellido, pCensista->apellido, pCensista->nacimiento.dia, pCensista->nacimiento.mes,
						pCensista->nacimiento.anio, pCensista->edad, pCensista->direccion.calle, pCensista->direccion.altura, pCensista->estado);
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Imprime los censistas cargados.
 * \param Censista* list, Es el puntero al array de censistas.
 * \param int len, es el limite de array
 * \return (-1) Error / (0) Ok
 */
int printArrayCensistas(Censista* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			printCensista(&list[i]);
		}
		retorno = 0;
	}
	return retorno;
}
