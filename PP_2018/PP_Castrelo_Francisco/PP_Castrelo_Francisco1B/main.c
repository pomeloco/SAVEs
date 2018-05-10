#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#define TAM_prop 10
#define TAM_autos 20

int main()
{
    ePropietario Propietarios[TAM_prop];
    eAuto Autos[TAM_autos];
    int nOpcion;

    eAuto_initAuto(Autos,TAM_autos);
    eProp_init(Propietarios, TAM_prop);
    eProp_hardcodeo(Propietarios);
    eAuto_harcodeo(Autos);



    do{

                system("cls");
                nOpcion=pedirEntero("1.Alta\n2.Modificar\n3.Baja\n4.Mostrar Propietarios\n5.Estacionar Auto\n6.Listar Autos\n9.Salir\n");
                switch(nOpcion){


                case 1:     system("cls");
                            eProp_alta(Propietarios, TAM_prop);

                            break;


                case 2:     system("cls");
                            eProp_mostrarListado(Propietarios,TAM_prop);
                            printf("\n");
                            eProp_modificacion(Propietarios,TAM_prop);
                            break;


                case 3:     system("cls");
                            eProp_mostrarListado(Propietarios,TAM_prop);
                            printf("\n");
                            eProp_baja(Propietarios,TAM_prop,pedirEntero("\nIngrese ID a buscar: "));
                            break;

                case 4:     system("cls");
                            eProp_mostrarListado(Propietarios, TAM_prop);
                            getche();
                            break;

                case 5:
                            system("cls");
                            eAuto_altaEstacionamiento(Autos, Propietarios, TAM_autos, TAM_prop);
                            break;

                case 6:     system("cls");
                            eAuto_mostrarListado(Autos, TAM_autos);
                            break;


                case 9:     exit(1);
                            break;
                }

    }while(nOpcion!=9);
    return 0;
}




