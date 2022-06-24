#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= (LinkedList*) malloc(sizeof(LinkedList));

    if(this != NULL)
	{
		this->pFirstNode = NULL;
		this->size = 0;
	}

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxNode = NULL;
	int i = 0;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		auxNode = this->pFirstNode;
		for(i = 0; i < nodeIndex; i++)
		{
			auxNode = auxNode->pNextNode;
		}
	}
    return auxNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;
    Node* auxPrevNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	{
    	auxNode = (Node*) malloc(sizeof(Node));
    	if(auxNode != NULL)
    	{
    		if(nodeIndex == 0)
			{
				auxNode->pNextNode = this->pFirstNode;
				this->pFirstNode = auxNode;
			}
			else
			{
				auxPrevNode = getNode(this, (nodeIndex - 1));
				if(auxPrevNode!= NULL)
				{
					auxNode->pNextNode = auxPrevNode->pNextNode;
					auxPrevNode->pNextNode = auxNode;
				}

			}

			auxNode->pElement = pElement;
			this->size++;
			returnAux = 0;
    	}

	}
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = addNode(this, ll_len(this), pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	auxNode = getNode(this, index);
    	if(auxNode != NULL)
    	{
    		returnAux = auxNode->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node* auxNode = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		auxNode = getNode(this, index);

		if(auxNode != NULL)
		{
			auxNode->pElement = pElement;
			returnAux = 0;
		}
	}

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* auxNode = NULL;
	Node* auxPrevNode = NULL;

	if(this != NULL && index >= 0 && index < ll_len(this))
	{
		auxNode = getNode(this, index);
		if(auxNode != NULL)
		{
			if(index == 0)
			{
				this->pFirstNode = auxNode->pNextNode;
			}
			else
			{
				auxPrevNode = getNode(this, (index - 1));
				if(auxPrevNode!= NULL)
				{
					auxPrevNode->pNextNode = auxNode->pNextNode;
				}

			}

			free(auxNode);
			this->size--;
			returnAux = 0;
		}
	}

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    //Node* auxNode = NULL;
    int i = 0;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);
    	if(len > 0)
    	{
    		for(i = 0; i < len; i++)
			{
				ll_remove(this, i);
			}
    		returnAux = 0;
    	}

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL && ll_clear(this) == 0)
    {
    	free(this);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int len;

    if(this != NULL)
    {
    	len = ll_len(this);
    	for(i = 0; i < len; i++)
    	{
    		if(ll_get(this, i) == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 1;

    	if(ll_len(this) > 0)
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
    	returnAux = addNode(this, index, pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int returnAux = -1;
    int i;
    int len;

    if(this != NULL && this2 != NULL)
    {
    	len = ll_len(this2);
    	returnAux = 1;
    	for(i = 0; i < len; i++)
    	{
    		if(ll_contains(this, ll_get(this2, i)) == 0)
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    int len = ll_len(this);

    if(this != NULL && from >= 0 && from < len && from <= to && to <= len)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
			for(i = from; i < to; i++)
			{
				ll_add(cloneArray, ll_get(this, i));
			}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this != NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));

    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int flagSwap = 0;
    void* element1 = NULL;
	void* element2 = NULL;
	int len;
	int i;
	int r;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	len = ll_len(this);
    	do
    	{
    		flagSwap = 0;
    		len--;
			for(i = 0; i < len; i++)
			{
				// 0 - orden descendente
				// 1 - orden ascendente
				element1 = ll_get(this, i);
				element2 = ll_get(this, i+1);
				// < 0	//el primero es menor que el segundo
				// > 0	//el primero es mayor que el segundo
				// = 0	//son iguales
				r = pFunc(element1, element2);
				if((order == 0 && r < 0) ||//<
					(order == 1 && r > 0))//>
				{
					ll_set(this, i, element2);
					ll_set(this, i+1, element1);
					flagSwap = 1;
				}
			}

    	}while(flagSwap == 1);
    	returnAux = 0;
    }

    return returnAux;

}

/** \brief Recorre el arrayList y llama una funcion para filtrar elementos.
 * \param this LinkedList* Puntero a la lista
 * \param int (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* Retorna una Linkedlist.
 */
LinkedList* ll_filter(LinkedList* this, int (*fn)(void*))
{
	LinkedList* newList = ll_clone(this);
	int len = ll_len(newList);
	void* pElement;

	if(this != NULL && fn != NULL)
	{
		for (int i = 0; i < len; i++)
		{
			pElement = ll_get(newList, i);
			if(fn(pElement) == 1)
			{
				ll_remove(newList, i);
				i--;
			}
		}
	}
	return newList;
}

/** \brief Recorre la lista y actua de acuerdo a lo que haya en la funcion criterio.
 * \param this LinkedList* Puntero a la lista
 * \param void (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int len = ll_len(this);
	int acumulador = -1;
	void* pElement;

	if(this != NULL && fn != NULL)
	{
		acumulador = 0;
		for (int i = 0; i < len; i++)
		{
			pElement = ll_get(this, i);
			if(fn(pElement) == 1)
			{
				acumulador++;
			}
		}
	}
	return acumulador;
}

/** \brief Recorre la lista y actua de acuerdo a lo que haya en la funcion criterio.
 * \param this LinkedList* Puntero a la lista
 * \param void (*pFunc) Puntero a la funcion criterio
 * \return LinkedList* Retorna una Linkedlist.
 */
/*
LinkedList ll_map(LinkedList* this, void (*fn)(void*))
{
    LinkedList* newList = ll_clone(this);
    int len = ll_len(this);
    void* pElement;

    if(this != NULL && fn != NULL)
    {
    	for (int i= 0; i < len; i++)
    	{
    		pElement = ll_get(newList, i);
    		fn(pElement);
		}
    }
    return newList;
}
*/
