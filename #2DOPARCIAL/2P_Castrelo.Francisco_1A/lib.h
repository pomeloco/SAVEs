typedef struct{

       char szMail[100], szNombre[100];
}ePersona;

/** \brief crea una estructura persona.
 * \param void
 * \return return aux (puntero estructura persona)
 *
 */
ePersona* persona_new(void);    //CONSTRUCTOR PERSONA


/** \brief muestra elementos de tipo ePersona.
 * \param estructura tipo persona
 * \return void
 *
 */
void persona_print(ePersona* this); //MOSTRAR PERSONA
