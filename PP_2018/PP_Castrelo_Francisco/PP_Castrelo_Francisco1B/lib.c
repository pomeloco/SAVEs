#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define tamszNombres 10
#define tamPublicaciones 5
#define OCUPADO 0
#define LIBRE 1
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTRO 4



int eProp_init( ePropietario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idPropietario= 0;
        }
    }
    return retorno;
}

int eProp_buscarLugarLibre(ePropietario listado[],int limite)
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

int eProp_siguienteId(ePropietario listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].idPropietario>retorno)
                    {
                         retorno=listado[i].idPropietario;
                    }

            }
        }
    }

    return retorno+1;
}


int eProp_buscarPorId(ePropietario listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idPropietario == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int eProp_mostrarUno(ePropietario parametro)
{
     printf("ID: %d %s, %s\nDireccion: %s\nTarjeta de credito: %s\n",parametro.idPropietario, parametro.szApellido,parametro.szNombre, parametro.szDireccion, parametro.szTarjetaDeCredito);

}

int eProp_mostrarListado(ePropietario listado[],int limite)
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

                eProp_mostrarUno(listado[i]);
            }
        }
    }
    return retorno;
}


int eProp_mostrarListadoConBorrados(ePropietario listado[],int limite)
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
            eProp_mostrarUno(listado[i]);
        }
    }
    return retorno;
}




int eProp_alta(ePropietario  listado[],int limite)
{
    int retorno = -1;
    char nombre[50];
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eProp_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = 0;
            id = eProp_siguienteId(listado,limite);

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
                //retorno = 0;
                strcpy(listado[indice].szNombre,eProp_cargarUsuario("Ingrese nombre: "));
                strcpy(listado[indice].szApellido,eProp_cargarUsuario("Ingrese Apellido: "));
                strcpy(listado[indice].szDireccion,eProp_cargarUsuario("Ingrese Direccion: "));
                strcpy(listado[indice].szTarjetaDeCredito,eProp_cargarUsuario("Ingrese Tarjeta de credito: "));

                listado[indice].idPropietario = id;
                listado[indice].estado = OCUPADO;
            //}
        }
    }
    return retorno;
}


 char* eProp_cargarUsuario(char* szMensaje){

    char szNombre[20];

    printf("%s", szMensaje);
    fflush(stdin);
    gets(szNombre);

    return szNombre;

}

int pedirEntero (char* mensaje){

    int nNumero;

    printf("%s", mensaje);
    scanf("%d", &nNumero);

    return nNumero;
}

int eProp_modificacion(ePropietario Propietarios[], int limite){

    int idBuscada;
    int indexEncontrado;
    char aux[10];

    idBuscada=pedirEntero("\nIngrese ID a buscar: ");
    indexEncontrado=eProp_buscarPorId(Propietarios, limite, idBuscada);

    if(indexEncontrado >= 0){

    strcpy(aux,eProp_cargarUsuario("Ingrese nueva tarjeta: "));

    if(pregunta("Confirma la modificacion?")=='s'){

        strcpy(Propietarios[indexEncontrado].szTarjetaDeCredito,aux);
        printf("Modificacion realizada con exito!");
    }

    }else{

        printf("no se encontro la ID!\n");
        }
}



int eProp_baja(ePropietario Propietarios[], int limite, int id){

    int indexEncontrado;
    int retorno;

    indexEncontrado=eProp_buscarPorId(Propietarios, limite, id);

    if(indexEncontrado >= 0){
        retorno=-2;
        if(pregunta("ID encontrada, desea dar de baja?")=='s'){
            Propietarios[indexEncontrado].estado = LIBRE;
            printf("baja realizada con exito!\n");
            retorno=0;
        }
    }else{

        printf("no se encontro la ID!\n");
        retorno =-2;
        }

    return retorno;
}





void eProp_hardcodeo(ePropietario Propietarios[]){


    Propietarios[0].idPropietario=1;
    strcpy(Propietarios[0].szNombre ,"Juan");
    strcpy(Propietarios[0].szApellido,"Gimenez");
    strcpy(Propietarios[0].szTarjetaDeCredito,"111-111");
    strcpy(Propietarios[0].szDireccion,"mitre");
    Propietarios[0].estado=OCUPADO;


    Propietarios[1].idPropietario=2;
    strcpy(Propietarios[1].szNombre ,"Luis");
    strcpy(Propietarios[1].szApellido,"Gonzalez");
    strcpy(Propietarios[1].szTarjetaDeCredito,"222-222");
    strcpy(Propietarios[1].szDireccion,"urquiza");
    Propietarios[1].estado=OCUPADO;

    Propietarios[2].idPropietario=3;
    strcpy(Propietarios[2].szNombre ,"Maria");
    strcpy(Propietarios[2].szApellido,"Lopez");
    strcpy(Propietarios[2].szTarjetaDeCredito,"333-333");
    strcpy(Propietarios[2].szDireccion,"belgrano");
    Propietarios[2].estado=OCUPADO;

    Propietarios[3].idPropietario=4;
    strcpy(Propietarios[3].szNombre ,"Jose");
    strcpy(Propietarios[3].szApellido,"Alvarez");
    strcpy(Propietarios[3].szTarjetaDeCredito,"444-444");
    strcpy(Propietarios[3].szDireccion,"alsina");
    Propietarios[3].estado=OCUPADO;

}



char pregunta(char* mensaje){

    char respuesta;

    printf(mensaje);
    fflush(stdin);
    respuesta=getchar();

    return respuesta;
}




int eAuto_altaEstacionamiento(eAuto Autos[], ePropietario Propietarios[], int limiteAutos, int limitePropietarios){


    int idPropietarioAux;
    int indexPropietario;
    int indexLibre;
    int retorno = -1;

    idPropietarioAux = pedirEntero("ingrese ID de propietario: ");
    indexPropietario = eProp_buscarPorId(Propietarios, limitePropietarios, idPropietarioAux);

    if(indexPropietario >= 0){

    if(limiteAutos > 0 && Autos != NULL)
    {
        retorno = -2;
        indexLibre = eAuto_buscarLugarLibreAuto(Autos,limiteAutos);
        if(indexLibre >= 0)
        {
            retorno = 0;

                strcpy(Autos[indexLibre].szPatente,eProp_cargarUsuario("Ingrese Patente: "));
                Autos[indexLibre].nMarca=pedirEntero("\n1.Alpha rompeo\n2.Ferrari\n3.Audi\n4.Otro\n");
                Autos[indexLibre].hHorarioEntrada=pedirEntero("Ingrese horario de entrada: ");

                Autos[indexLibre].idPropietario = indexPropietario;
                Autos[indexLibre].estado = OCUPADO;

        }
    }


    }else{

        printf("no se encontro el propietario!\n");
        getche();

    }


        return retorno;
}



int eAuto_buscarLugarLibreAuto(eAuto listadoAutos[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoAutos != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listadoAutos[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eAuto_initAuto( eAuto listadoAutos[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoAutos != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listadoAutos[i].estado= LIBRE;
            listadoAutos[i].idPropietario= 0;
        }
    }
    return retorno;
}


int eAuto_buscarPorPatente(eAuto Autos[], int limite, char* patente){

    int retorno = -1;
    int i;
    if(limite > 0 && Autos != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(Autos[i].estado == OCUPADO && strcmp(Autos[i].szPatente,patente)==0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;

}




int eAuto_egresoEstacionamiento(eAuto Autos[],ePropietario Popietarios ,int limiteAutos, int limitePropietarios, char* patente){

    int indexEncontrado;
    int retorno;
    int ticket;

    indexEncontrado=eAuto_buscarPorPatente(Autos, limiteAutos, patente);

    if(indexEncontrado >= 0){
        retorno=-2;
        if(pregunta("patente encontrada encontrada, desea sacar el auto?")=='s'){

            switch(Autos[indexEncontrado].nMarca){

                case ALPHA_ROMEO:   ticket=Autos[indexEncontrado].hHorarioEntrada*150;
                                    break;

                case FERRARI: ticket=Autos[indexEncontrado].hHorarioEntrada*175;
                                break;

                case AUDI: ticket=Autos[indexEncontrado].hHorarioEntrada*200;
                            break;

                case OTRO: ticket=Autos[indexEncontrado].hHorarioEntrada*250;
                            break;
            }
            Autos[indexEncontrado].estado = LIBRE;

            printf("egreso realizado con exito!\n");
            retorno=0;
        }
    }else{

        printf("no se encontro la ID!\n");
        retorno =-2;
        }

    return retorno;

}





int eAuto_mostrarUnAuto(eAuto parametro){

     printf("patente: %s \nHorario entrada: %d\nId Propietario: %d,",parametro.szPatente,parametro.hHorarioEntrada,parametro.idPropietario );
     printf("marca: ");
     switch(parametro.nMarca){

        case ALPHA_ROMEO:       printf("Alpha Rompeo");
                                break;

        case FERRARI:   printf("FERRARI");
                        break;

        case AUDI:  printf("AUDI");
                    break;

        case OTRO: printf("OTRO");
                    break;
     }

     getche();
}


int eAuto_mostrarListado(eAuto Auto[] ,int limite){

    int retorno = -1;
    int i;
    if(limite > 0 && Auto != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(Auto[i].estado==OCUPADO)
            {

                eAuto_mostrarUnAuto(Auto[i]);
            }
        }
    }
    return retorno;


}

void eAuto_harcodeo(eAuto Autos[]){


    strcpy(Autos[0].szPatente,"aaa123");
    Autos[0].nMarca=1;
    Autos[0].idPropietario=1;
    Autos[0].hHorarioEntrada=18;
    Autos[0].estado=0;


    strcpy(Autos[1].szPatente,"asdih");
    Autos[1].nMarca=3;
    Autos[1].idPropietario=2;
    Autos[1].hHorarioEntrada=20;
Autos[1].estado=0;

    strcpy(Autos[2].szPatente,"123asd");
    Autos[2].nMarca=1;
    Autos[2].idPropietario=3;
    Autos[2].hHorarioEntrada=23;
    Autos[2].estado=0;

    strcpy(Autos[3].szPatente,"asd123");
    Autos[3].nMarca=1;
    Autos[3].idPropietario=2;
    Autos[3].hHorarioEntrada=00;
    Autos[3].estado=0;


}
