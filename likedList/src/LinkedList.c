#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


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
	 LinkedList* this = (LinkedList*)malloc(sizeof(LinkedList));
	    if (this != NULL)
	    {
	        this->size=0;
	        this->pFirstNode = NULL;
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
	    if (this != NULL && this->size >= 0)
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
	Node* pNode = NULL;
	    if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) //Entra si el puntero es distinto a NULL y la posicion esta dentro de los parametros del LinkedList
	    {
	        pNode = this->pFirstNode;   //Asigno la direccion de memoria del primer nodo a pNode
	        for (int i=0; i<nodeIndex; i++)
	        {
	            pNode = pNode->pNextNode; //Asigno la direccion de memoria del siguiente nodo a pNode
	        }
	    }
	    return pNode;
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
	    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
	    {
	        Node* newNode = (Node*)malloc(sizeof(Node));
	        if(!nodeIndex) //Si el indice es 0, es el primer elemento del array
	        {
	            newNode->pNextNode = this->pFirstNode; //Le asigno al pNextNode del nuevo nodo la direccion del primer nodo
	            this->pFirstNode = newNode; //Se la asigno a pFirstNode
	        }
	        else //Indice entre 1 y el largo
	        {
	            Node* lastNode = getNode(this, nodeIndex-1); //Asigno al nodo anterior el nodo del indice anterior al indice ingresado por parametro.
	            Node* nextNode = lastNode->pNextNode;        //Asigno al siguiente el valor del nodo a agregar.

	            newNode->pNextNode = nextNode;               //asigno al nuevo nodo el valor del siguiente.
	            lastNode->pNextNode = newNode;               //Asigno al anterior el nuevo nodo.
	        }
	        this->size++;
	        newNode->pElement = pElement; //Le asigno el tamanio de elemento al nuevo nodo
	        returnAux = 0;
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
	int returnAux = -1;     //Variable a retornar por la funcion
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
	void* pElement = NULL;
	Node* pNode = NULL; 	//Puntero a nodo inicializado en NULL
	if (this != NULL && index>=0 && index<ll_len(this))
	{
		pNode = getNode(this, index);
		if(pNode!=NULL)
		{
			pElement=pNode->pElement;
		}

	}

	return pElement;
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
int ll_set(LinkedList* this, int index,void* pElement)
{
	int returnAux = -1;	//ARREGLAR EL GETNODE
	Node* pNode = NULL;

	    if (this != NULL && index>=0 && index<ll_len(this)) //Entra si this y la direccion de memoria que retorne getNode son distintas a NULL
	    {
	    	pNode = getNode(this, index);//Asigno al nodo el valor del elemento ingresado como parametro

	    	if(pNode != NULL)
	    	{
	    		pNode->pElement=pElement;
	    		returnAux=0;
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
	//ARREGLAR EL LL_REVOME NO DESENGANCHAR
	int returnAux = -1;
	Node* pNode = NULL;
	Node* lastNode = NULL;
	Node* nextNode = NULL;

	    if (this != NULL && index >= 0 && index < ll_len(this))
	    {
	    	pNode = getNode(this,index);
	    	nextNode = getNode(this,index+1);

	    	if (index==0)//Entro si el indice es igual a 0
	        {
	            this->pFirstNode = nextNode;
	        }
	        else
	        {
	        	lastNode = getNode(this,index-1);
	        	lastNode->pNextNode=nextNode;
	        }

	    	if(pNode!=NULL) // arreglar free despues del if else
	    	{
	    		free(pNode);
	    	}

	        this->size--;
	        returnAux = 0;
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
	int len;
	int i;

	if (this != NULL)
	    {
		  len=ll_len(this);
		  if(len>0)
		  {
			for(i=len-1; i>=0; i--)
			{
				ll_remove(this, i);  //Recorre todos los datos y los elimina en cada iteracion
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
	    if (this != NULL)
	    {
	    	if(ll_clear(this) == 0)//elimino todos los empleados
	    	{
	    		free(this);    //libera la direccion de memoria
	    	}

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
	int index = -1;
	int len;
	len = ll_len(this);

	    if (this != NULL)
	    {
	        for(int i=0; i<len; i++)
	        {
	            if (ll_get(this, i) == pElement)
	            {
	                index = i;  //asigno a index el valor de la posicion del elemento
	                break;
	            }
	        }
	    }
	    return index;
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
	    if (this != NULL)
	    {
	    	returnAux = 1;

	        if (ll_len(this)!=0)
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

	    if(this!=NULL && index>=0 && index<=ll_len(this))
	    {
	        returnAux=addNode(this,index,pElement);
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
	if(this!=NULL && index>=0 && index<ll_len(this))
	{
	   returnAux=ll_get(this,index);
	   ll_remove(this,index);
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
	int returnAux= -1;
	int index;
    if(this != NULL)
	{
    	index=ll_indexOf(this, pElement);
    	returnAux = 0;
	    if(index != -1)
	    {
		   returnAux = 1;
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
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
	int returnAux = -1;
	int i;
	int len;
	void* pElement=NULL;

	if(this!=NULL && this2!=NULL)
	  {
		len=ll_len(this2);
	    returnAux=1;

	     for(i=0; i<len; i++)
	      {
	    	pElement=ll_get(this2,i);

	          if(ll_contains(this,pElement)!=1)
	            {
	                returnAux=0;
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
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
	LinkedList* cloneArray = NULL;
	    void* pElement=NULL;
	    int i;
	    if(this!=NULL)
	    {
	        if(from>=0 && from<ll_len(this) && to>from && to<=ll_len(this))
	        {
	            cloneArray=ll_newLinkedList();
	            if(cloneArray!=NULL)
	            {
	                for(i=from; i<to; i++)
	                {
	                    pElement=ll_get(this,i);
	                    ll_add(cloneArray,pElement);
	                }
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
	int len;
	if(this!=NULL)
	{
	   len=ll_len(this);
	   cloneArray=ll_subList(this,0,len);
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
	void* pAux;
	void* pAux2;
	int criterio;
	int i;
	int j;
	int len;

	if(this!=NULL && pFunc!=NULL && order>=0 && order<=1)
	    {
	        len=ll_len(this);
	        for(i=0; i<len-1; i++)
	        {
	            pAux=ll_get(this,i);
	            for(j=i+1; j<len; j++)
	            {
	                pAux2=ll_get(this,j);
	                criterio=pFunc(pAux,pAux2);
	                if((order==0 && criterio==-1) || (order==1 && criterio==1))
	                {
	                    addNode(this,i,pAux2);//arreglar los nodos
	                    ll_remove(this,j+1);
	                }
	            }
	        }
	        returnAux=0;
	    }
	    return returnAux;

}

