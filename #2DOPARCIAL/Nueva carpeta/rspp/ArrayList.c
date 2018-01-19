#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "funciones.c"

// funciones privadas
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)    //CREA ARRAY LIST
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList=(ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList,void* pElement) //AGREGA UN ELEMENTO AL ARRAYLIST
{
    int returnAux = -1;
    int flag=0;
    void** pListAux;

    if(pList!=NULL && pElement!=NULL)
    {
        if(pList->size==pList->reservedSize)
        {
            flag=resizeUp(pList);
        }
        pListAux=pList->pElements+(pList->size);

        if(!flag)
        {
           *pListAux=pElement;
           pList->size++;
           returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList)    //BORRA TODO EL ARRAYLIST
{
    int returnAux = -1;

    if(pList != NULL)
    {
        free(pList->pElements);
        free(pList);
        returnAux=0;
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList)    //CUENTA LOS ESPACIOS OCUPADOS
{
    int returnAux = -1;

    if(pList != NULL)
    {
        returnAux = pList->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList , int index)  //TOMA UN ELEMENTO DEL ARRAYLIST
{
    void* returnAux = NULL;

    if(pList != NULL && index >= 0  && index  <= pList->size)
    {
        returnAux = pList->pElements[index];
    }
    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement)   //COMPRUEBA ELEMENTO
{
    int returnAux=-1;
    int i;
    int flag=0;
    if(pList != NULL && pElement != NULL )
    {
        returnAux = 0;
        for( i=0 ; i<pList->size ; i++ )
        {
            if( *(pList->pElements+i) == pElement)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            returnAux=1;
        }else
        {
            returnAux=0;
        }
    }
    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement)  //COLOCA ELEMENTO EN LUGAR ESPECIFICO
{
    int returnAux = -1;

    if(pList != NULL && pElement!=NULL && index >= 0  && index  <= pList->size)
    {
        pList->pElements[index]=pElement;

        returnAux = 0;
    }
    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index)       //ELIMINA UN ELEMENTO EN INDICIE
{
    int returnAux = -1;
    int i;
    int flag=0;

    if(pList != NULL && index >= 0  && index  <= pList->size)
    {
        if(contract(pList,index)==0)
        {
            returnAux=0;
        }
        /*for( i=index ; i < pList->size ; i++)
        {
            pList->pElements[i] = pList->pElements[i+1];
        }
        pList->size--;
        returnAux=0;*/
    }
    return returnAux;
}

/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList)      //BORRA TODOS LOS ELEMENTOS DEL ARRAYLIST
{
    int returnAux = -1;
    int i;
    if(pList != NULL)
    {
        for(i=0;i<pList->size;i++)
        {
            pList->pElements[i]=NULL;
        }
        pList->size=0;
        returnAux=0;
    }
    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList)   //CLONA TODA LA LISTA DEL ARRAY
{
    ArrayList* returnAux = NULL;
    int i;
    if(pList != NULL)
    {
        returnAux=al_newArrayList();
        if(returnAux!=NULL)
        {
            for( i=0 ; i<pList->size ; i++)
            {
                al_add(returnAux,al_get(pList,i));
            }
        }
    }
    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement)    //MUEVE LOS ELEMENTOS Y PONE UN ELEMENTO EN EL INDEX
{
    int returnAux = -1;
    void** pListAux;

    if(pList!=NULL && pElement!=NULL && index>=0 && index<=pList->size)
    {
        if(expand(pList,index)==0)
        {
            pListAux=pList->pElements+index;
            *pListAux=pElement;
            pList->size++;
            returnAux=0;
        }
    }
    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement)    //RETORNA EL INDICIE DE LA PRIMERA APARICION DE UN ELEMENTO
{
    int returnAux = -1;
    int i;
    if(pList != NULL && pElement!=NULL)
    {
        for( i=0 ; i<pList->size ; i++ )
        {
            if(*(pList->pElements+i) == pElement)
            {
                returnAux=i;
                break;
            }
        }
    }
    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList)    //VERIFICA SI ESTA VACIO
{
    int returnAux = -1;
    int i;
    if(pList != NULL)
    {
        if(pList->size==0)
        {
            returnAux=1;
        }else
        {
            returnAux=0;
        }
    }
    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index)    //RETORNA PUNTERO DEL INDICIE Y LO ELIMINA
{
    void* returnAux = NULL;
    if(pList!=NULL && index>=0 && index <= pList->size)
    {
        returnAux = al_get(pList,index);
        if( al_remove(pList,index) == -1 )
        {
            returnAux = NULL;
        }
    }
    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to) //RETORNA NUEVO ARRAYLIST CON SUBCONJUNTO DE ELEMENTOS
{
    void* returnAux = NULL;
    int i;
    if(pList!=NULL && from >= 0 && from < to && to <= pList->size)
    {
        returnAux=al_newArrayList();

        if(returnAux != NULL)
        {
            for(i=from; i<to; i++)
            {
                al_add(returnAux,al_get(pList,i));
            }
        }
    }
    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2)  //COMPRUEBA SI LOS ELEMENTOS ESTAN EN EL ARRAYLIST
{
    int returnAux = -1;
    int i;

    if(pList!=NULL && pList2!=NULL)
    {
        for(i=0; i<pList2->size; i++)
        {
            if( al_contains( pList , *(pList2->pElements+i)) == 0 )
            {
                returnAux=0;
                break;
            }
            else
            {
                returnAux=1;
            }
        }
    }
    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order)    //ORDENA ELEMENTOS
{
    int returnAux = -1;
    int i,j;
    void* pAuxiliar;

    if(pList!=NULL && pFunc!=NULL && al_len(pList) > 0 && (order==1 || order==0))
    {
        for(i=0; i<(al_len(pList))-1; i++)
        {
            for(j=i+1; j<(al_len(pList)); j++)
            {
                if( pFunc(al_get(pList,i),al_get(pList,j)) == -1 && order == 0 )
                {
                    pAuxiliar=pList->get(pList,j);
                    pList->set(pList,j,pList->get(pList,i));
                    pList->set(pList,i,pAuxiliar);

                }
                if( pFunc(al_get(pList,i),al_get(pList,j)) == 1 && order == 1 )
                {
                    pAuxiliar=pList->get(pList,j);
                    pList->set(pList,j,pList->get(pList,i));
                    pList->set(pList,i,pAuxiliar);
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList)  //AUMENTA EL ESPACIO DEL ARRAYLIST
{
    int returnAux = -1;
    void** auxpElements;

    if(pList!=NULL)
    {
        if(pList->reservedSize == pList->size)
        {
            auxpElements=(void**)realloc(pList->pElements,sizeof(void*)*(pList->reservedSize+AL_INCREMENT));

                if(auxpElements != NULL)
                {
                    pList->pElements = auxpElements;
                    pList->reservedSize = pList->reservedSize+AL_INCREMENT;
                    //pList->reservedSize +=AL_INCREMENT;
                    returnAux=0;
                }
        }
    }
    return returnAux;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)  //EXPANDE
{
    int returnAux = -1;
    int i;

    if(pList != NULL && index <= pList->size && index>=0)
    {
        if(pList->size+1 == pList->reservedSize)
        {
            resizeUp(pList);
        }
        for( i=pList->size ; i>index ; i-- )
        {
            pList->pElements[i]=pList->pElements[i-1];
        }
        pList->size++;
        returnAux=0;
    }
    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index) //CONTRAE
{
    int returnAux = -1;
    int i;
    if(pList != NULL && index <= pList->size && index >= 0)
    {
        for( i=index ; i<pList->size-1 ; i++)
        {
            pList->pElements[i]=pList->pElements[i+1];
        }
        pList->size--;
        returnAux=0;
    }
    return returnAux;
}





/*******************************/

ArrayList* al_filter(ArrayList* listIn, int (*pFuncionFiltrar)(void*)){

    ArrayList* pAuxArrayList = al_newArrayList();
    int i;


    if(listIn != NULL && pFuncionFiltrar !=NULL && listIn->len(listIn) > 0){

        for(i=0; i<listIn->len(listIn); i++)
        {


                if( pFuncionFiltrar(al_get(listIn,i)) == 1  ) // MANTENER
                {
                    pAuxArrayList->add(pAuxArrayList, al_get(listIn, i));

                }else{

                break;
                }

    }


    }
    return pAuxArrayList;
}
