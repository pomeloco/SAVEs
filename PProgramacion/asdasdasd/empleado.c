#include "empleado.h"
/*
typedef struct{

    int nDia;
    int nMes;
    int nYear;

}eFecha;

typedef struct{

    char szNombre[20];
    char szApellido[20];
    char cSexo;
    int nLegajo;
    float fSalario;
    eFecha FechaIngreso;
    int nIdSector;
    int nIsEmpty;

}eEmpleado;


typedef struct{

    int nIdMenu;
    char szDescripcion[40];
    float fImporte;

}eMenu;

typedef struct{

    int nIdEmpleado;
    int nIdMenu;

}eAlmuerzo;


typedef struct{

    int nIdSector;
    char szDescripcion[30];

}eSector;

*/
/******************* Prototipos *******************/


/*****************HARCODEAR/INICIALIZAR*************/
void HarcodearSector(eSector[], int);
void HarcodearMenu(eMenu[], int);
void InicializarEmpleados(eEmpleado[],int);
/**************************************************/
int buscarLibreEmpleado(eEmpleado[],int);
