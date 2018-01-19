#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \brief crea una estructura persona.
 * \param void
 * \return return aux (puntero estructura persona)
 *
 */
ePersona* persona_new(void)
{
    ePersona* returnAux;
    returnAux = (ePersona*)malloc(sizeof(ePersona));

    if(returnAux !=NULL){
       strcpy(returnAux->szNombre, "");
       strcpy(returnAux->szMail, "");
    }
    return returnAux;

}

/** \brief muestra elementos de tipo ePersona.
 * \param estructura tipo persona
 * \return void
 *
 */
void persona_print(ePersona* this)
{
    if(this != NULL){
        printf("%s - %s \n", this->szNombre, this->szMail);
    }
}
