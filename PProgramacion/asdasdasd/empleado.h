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

/************************ FUNCIONES ***********************************/


/***********************INICIALIZAR/HARCODEAR************************/
void HarcodearSector(eSector Sector[], int nCantidadSectores){

    int i;

    for(i=0;i<nCantidadSectores;i++){

        Sector[i].nIdSector=i+1;
    }

    strcpy(Sector[0].szDescripcion,"programador");
    strcpy(Sector[1].szDescripcion,"limpeza");
    strcpy(Sector[2].szDescripcion,"mantenimiento");
}

void HarcodearMenu(eMenu Menu[],int nCantidadMenu){

    int i;

    for(i=0;i<nCantidadMenu;i++){

        Menu[i].nIdMenu =i+1;
        Menu[i].fImporte=i+1,5;

        }

        strcpy(Menu[0].szDescripcion,"Sopita");
        strcpy(Menu[1].szDescripcion, "Ensaladita");
        strcpy(Menu[2].szDescripcion, "Sanguchito");

}

void InicializarEmpleados(eEmpleado Empleados[],int nCantidadEmpleados){

    int i;

    for(i=0;i<nCantidadEmpleados;i++){

            Empleados[i].nIsEmpty=1;
    }
}
/******************************************************/
int buscarLibreEmpleado(eEmpleado Empleados[], int nCantidadEmpleados){
    int i,retornoIndex;

    for(i=0;i<nCantidadEmpleados;i++){

        if(Empleados[i].nIsEmpty==1){
            retornoIndex=i;
            break;
        }
    }

    return retornoIndex;

}
