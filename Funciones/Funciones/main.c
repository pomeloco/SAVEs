#include <stdio.h>
#include <stdlib.h>

int pedirEntero (char*); // pido un entero
void mostrarEntero (char* , int, int); //muestra entero true. \n false. espacio
int validarNumeroEntero(int, int, int, char*); // valida numero entero entre un rango


int main()
{
    int nNumeroIngresado, nNumeroDos;

    nNumeroIngresado=pedirEntero("Ingrese un numero: ");
    nNumeroDos= pedirEntero("Ingrese un numero: ");
    nNumeroDos = validarNumeroEntero(nNumeroDos, 1, 10, "error reingrese numero");

    mostrarEntero("El primer numero es: ", nNumeroIngresado,1);
    mostrarEntero("El segundo numero es: ", nNumeroDos,0);


    return 0;
}

/** \brief  Funcion para pedir un numero
 *
 * \param char* mensaje a mostrar
 * \return retorna el numero que se ingresa
 *
 */

int pedirEntero(char* szCadena){

    int nNumero;
    printf("%s",szCadena);
    scanf("%d", &nNumero);
    free(szCadena);

    return nNumero;
}

/** \brief muestra un numero entero con un mensaje generico
 *
 * \param mensaje a mostrar
 * \param numero entero que se desea mostrar
 * \param flag para indicar como mostrar el mensaje true: con /n false: con espacio
 * \return
 *
 */

void mostrarEntero(char* szCadena, int nNumero, int bFlag){

    if(bFlag){

    printf("%s %d", szCadena, nNumero);
    printf("\n");

    }else{

    printf("%s %d ", szCadena, nNumero);
    }

    free(szCadena);
}

/** \brief Valida un numero entre dos rangos
 *
 * \param dato a validar
 * \param numero minimo del rango
 * \param numero maximo del rango
 * \param mensaje de error
 * \return dato validado
 *
 */

int validarNumeroEntero(int nDato, int nMinimo, int nMaximo, char* szMensajeError){

    while(nDato < nMinimo || nDato > nMaximo){

        nDato=pedirEntero(szMensajeError);
    }

    return nDato;
}
