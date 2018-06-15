#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList *this;
    ArrayList *returnAux = NULL;
    void **pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void*)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
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
int al_add(ArrayList* this, void **pElement)
{
    int returnAux = -1;
    int flag = 0;
    void **auxpElement = NULL;

    if(this!=NULL && pElement!=NULL){
        if(this->size >= this->reservedSize){
            auxpElement = (void**)realloc(this->pElements,sizeof(void*)*(this->reservedSize + AL_INITIAL_VALUE));
            if(auxpElement != NULL){
                this->pElements = auxpElement;
                this->reservedSize = this->reservedSize + AL_INITIAL_VALUE;
            }
            else{
                flag = -1;
            }
        }
        if(flag == 0){
            this->pElements[this->size] = pElement;
            this->size++;
            returnAux = 0;
        }

    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
 /************************************************
 Elimina el ArrayList . Verificando que el puntero pList sea distinto de NULL.
 Si la verificación falla la función retorna (-1),
 si esta vacío (1)
 y si contiene elementos (0).
 *************************************************/
int al_deleteArrayList(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL){
        if(!(this->clear)){
            free(this);
            returnAux = 1;
        }
        else{
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
 /************************************************
 Retorna el tamaño del ArrayList. Verificando que
 el puntero pList sea distinto de NULL.
 Si la verificación falla la función retorna (-1)
 y si tiene éxito retorna la longitud del array.
 *************************************************/
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL){
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
 /*************************************************
 Retorna un puntero al elemento que se encuentra en el índice especificado.
 Verificando que el puntero pList sea distinto de NULL y que index sea positivo
 e inferior al tamaño del array. Si la verificación falla la función retorna (NULL)
 y si tiene éxito retorna el elemento.
 **************************************************/
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;

    if(this!=NULL && index>=0 && index<this->size){
        returnAux = this->pElements[index];
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
 /************************************************
 Comprueba si existe el elemento que se le pasa como parámetro.
 Verificando que tanto el puntero pList como pElement sean distintos de NULL.
 Si la verificación falla la función retorna (-1) ,
 si encuentra el elemento (1) y si no lo encuentra (0).
 *************************************************/
int al_contains(ArrayList* this, void *pElement)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && pElement!=NULL){
        for(i=0;i<this->size;i++){
            if(this->pElements[i] == pElement){
                returnAux = 1;
                break;
            }
            else{
                returnAux = 0;
            }
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
 /*****************************************************
 Inserta un elemento en el ArrayList, en el índice especificado.
 Verificando que tanto el puntero pList como pElement sean distintos de NULL
 y que index sea positivo e inferior al tamaño del array.
 Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 ******************************************************/
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && pElement!=NULL && index>=0 && index<this->size){
        this->pElements[index] = pElement;
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
 /************************************************
 Elimina un elemento del ArrayList, en el índice especificado.
 Verificando que el puntero pList sea distinto de NULL
 y que index sea positivo e inferior al tamaño del array.
 Si la verificación falla la función retorna (-1)
 y si tiene éxito (0).
 ************************************************/
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;

    if(this!=NULL){
        if(index >= 0 && index < this->size){
            for(i=index;i<this->size;i++){
                this->pElements[i] = this->pElements[i+1];
                returnAux = 0;

                if(i==this->size-1){
                    this->size = this->size-1;
                }
            }
        }
    }

    return returnAux;
}

/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
 /***********************************************************
 Borra todos los elementos de ArrayList. Verificando que el puntero pList sea distinto de NULL.
 Si la verificación falla la función retorna (-1) y si tiene éxito (0).
 ************************************************************/
int al_clear(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL){
        free(this->pElements);
        this->size = 0;
        returnAux = 0;
    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
 /******************************************************************************
 Retorna un nuevo ArrayList copia del ArrayList original.
 Verificando que el puntero pList sea distinto de NULL.
 Si la verificación falla la función retorna (NULL)
 y si tiene éxito retorna el nuevo array.
 ******************************************************************************/
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    int i;

    if(this!=NULL){
        returnAux = al_newArrayList();
        for(i=0;i<this->size;i++){
            this->add(returnAux, this->pElements[i]);
            this->set(returnAux,i,this->pElements[i]);
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
 /*************************************************************
 Desplaza los elementos e inserta en la posición index.
 Verificando que tanto el puntero pList como pElement sean distintos de NULL
 y que index sea positivo e inferior al tamaño del array.
 Si la verificación falla la función retorna (-1)
 y si tiene éxito (0).
 *************************************************************/
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this!=NULL && pElement!=NULL){
        if(this->size>=this->reservedSize){
            resizeUp(this);
        }
        if(index>=0 && index<=this->len(this))
        {
            expand(this, index);
            this->set(this, index, pElement);
            this->size++;
            returnAux = 0;
        }

    }
    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
 /***************************************************************************
 Retorna el índice de la primera aparición de un elemento (element) en el ArrayList.
 Verificando que tanto el puntero pList como pElement sean distintos de NULL.
 Si la verificación falla o no encuentra el elemento la función retorna (-1)
 y si encuentra el elemento retorna su índice.
 **********************************************************************+***/
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && pElement!=NULL){
        for(i=0;i<this->size;i++){
            if(this->pElements[i] == pElement){
                returnAux = i;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
 /***********************************************************
 Retorna cero si contiene elementos y uno si no los tiene.
 Verificando que el puntero pList sea distinto de NULL.
 Si la verificación falla la función retorna (-1),
 si esta vacío (1) y si contiene elementos (0).
 ************************************************************/
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL){
        if(this->size==0){
            returnAux = 1;
        }
        else{
            returnAux = 0;
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
 /*********************************************************
 Retorna un puntero al elemento que se encuentra en el índice especificado
 y luego lo elimina de la lista.
 Verificando que el puntero pList sea distinto de NULL y que index sea positivo
 e inferior al tamaño del array.
 Si la verificación falla la función retorna (NULL)
 y si tiene éxito retorna el elemento.
 *********************************************************/
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;

    if(this!=NULL){
        if(index>=0 && index<=this->len(this)){
            returnAux = this->get(this, index);
            this->remove(this, index);
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
 /******************************************************************
 Retorna un nuevo ArrayList con el subconjunto de elementos.
 Verificando que el puntero pList sea distinto de NULL
 y que tanto el indice 'from' como 'to' sean positivos e inferiores al tamaño del array.
 Si la verificación falla la función retorna (NULL)
 y si tiene éxito retorna el nuevo
 ******************************************************************/
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    void* returnAux = NULL;
    int i;

    if(this!=NULL){
        if(from>=0 && from<al_len(this)){
            if(to>0 && to<=al_len(this) && from<to){
                returnAux = al_newArrayList();
                for(i=from;i<to;i++){
                   al_add(returnAux, this->pElements[i]);
                }
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
 /****************************************************************
 Comprueba si los elementos pasados son contenidos por el ArrayList.
 Verificando que tanto el puntero pList como pList2 sean distintos de NULL.
 Si la verificación falla o no encuentra el elemento la función retorna (-1),
 si las listas difieren (0)
 y si ambas listas son iguales retorna (1).
 *****************************************************************/
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1, i;
    if(this!=NULL && this2!=NULL)
    {
        for(i=0;i<this2->size;i++)
        {
            if(!(this->contains(this,this2->pElements[i])))
            {
                returnAux = 0;
                break;
            }
            else
            {
                returnAux = 1;
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
 /*****************************************************
 Ordena los elementos del array recibiendo como parámetro la función que
 sera la encargada de determinar que elemento es mas grande que otro
 y si se debe ordenar de manera ascendente o descendente.
 Verificando que tanto el puntero pList como el puntero a la funcion pFunc
 sean distintos de NULL. Si la verificación falla (-1) caso contrario retorna (1).
 *****************************************************/
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void* pSwap;
    int i, j;

    if(this!=NULL){
        if(pFunc!=NULL &&(order==1 || order==0)){
            for(i=0; i<this->size-1; i++){
                for (j=i+1; j<this->size; j++){
                    switch(order){
                        case 0:
                            if((pFunc(this->pElements[i],this->pElements[j])==-1) && pSwap!=NULL)
                            {
                                pSwap=this->pElements[i];
                                this->pElements[i]=this->pElements[j];
                                this->pElements[j]=pSwap;
                            }
                            break;
                        case 1:
                            if((pFunc(this->pElements[i],this->pElements[j])==1) && pSwap!=NULL)
                            {
                                pSwap=this->pElements[i];
                                this->pElements[i]=this->pElements[j];
                                this->pElements[j]=pSwap;
                            }
                            break;
                    }
                }
            }
        returnAux=0;
        }
    }
    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** aux;

    if(this!=NULL){
        aux = (void**)realloc(this->pElements, sizeof(void*)*(this->reservedSize+AL_INCREMENT));
        if(aux!=NULL){
            this->reservedSize += AL_INCREMENT;
            this->pElements=aux;
        }
        returnAux = 0;
    }
    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;
    if(this!=NULL){
        if(index>=0 && index<=this->size){
            for(i=this->size-1; i>=this->size; i--){
                this->pElements[i] = this->pElements[i+1];
            }
        this->size++;
        returnAux=0;
        }
    }
    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;

    if(this!=NULL && index>=0 && index<=this->size){
        for(i=index ; i<(this->size-1); i++){
            this->pElements[i] = this->pElements[i+1];
        }
        this->size--;
        returnAux=0;
    }

    return returnAux;
}
