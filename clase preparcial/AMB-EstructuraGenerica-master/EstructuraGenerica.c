#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstructuraGenerica.h"
#define tamUsuarios 3
#define tamPublicaciones 5
#define OCUPADO 0
#define LIBRE 1



int eUser_init( eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idGenerica= 0;
        }
    }
    return retorno;
}

int eUser_buscarLugarLibre(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eUser_siguienteId(eUsuario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idGenerica>retorno)
                    {
                         retorno=listado[i].idGenerica;
                    }

            }
        }
    }

    return retorno+1;
}


int eUser_buscarPorId(eUsuario listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idGenerica == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int eUser_mostrarUno(eUsuario parametro)
{
     printf("\n %s - %d - %d - %s\n",parametro.usuario,parametro.idGenerica,parametro.estado,parametro.password);

}

int eUser_mostrarListado(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {

                eUser_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}


int eUser_mostrarListadoConBorrados(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==LIBRE)
            {
                printf("\n[LIBRE]");
            }
            eUser_mostrarUno(listado[i]);
        }
    }
    return retorno;
}




int eUser_alta(eUsuario  listado[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eUser_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = 0;
            id = eUser_siguienteId(listado,limite);

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
                //retorno = 0;
                strcpy(listado[indice].usuario,eUser_cargarUsuario("Ingrese nuevo usuario: "));
                strcpy(listado[indice].password,eUser_cargarUsuario("Ingrese nueva contraseña: "));
                listado[indice].idGenerica = id;
                listado[indice].estado = OCUPADO;
            //}
        }
    }
    return retorno;
}


 char* eUser_cargarUsuario(char* szMensaje){

    char szUsuario[20];

    printf("%s", szMensaje);
    fflush(stdin);
    gets(szUsuario);

    return szUsuario;

}

int pedirEntero (char* mensaje){

    int nNumero;

    printf("%s", mensaje);
    scanf("%d", &nNumero);

    return nNumero;
}

int eUser_modificacion(eUsuario Users[], int limite){

    int idBuscada;
    int indexEncontrado;

    idBuscada=pedirEntero("\nIngrese ID a buscar: ");

    if(indexEncontrado=eUser_buscarPorId(Users, limite, idBuscada) >= 0){

    strcpy(Users[indexEncontrado].password,eUser_cargarUsuario("ingrese nueva contraseña: "));

    }
}
