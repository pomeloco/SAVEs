#include "funciones.h"
#include "arraylist.h"
#include <stdio.h>


int funcionQueFiltra (void* item){

    int auxReturn=0;
    eEmpleado auxEmpleado;
    printf("%s\n", item);


    if(al_get() >30 && strcmp(item->profecion,"Programador")==0){       //MANTENER

        auxReturn = 1;
    }else{          //FILTRAR


        auxReturn =0;
    }



    return auxReturn;
}



void CargarArchivo(ArrayList* empleados){

eEmpleado* auxEmpleado;
char szAuxProfecion[30];
int nAuxEdad;
int nAuxId;
char szAuxNombre [50];
//ArrayList* empleados = al_newArrayList();

FILE* pFileArchivo;



pFileArchivo = fopen("empleados.csv", "r");     //ABRO ARCHIVO

        if(pFileArchivo == NULL){

            printf("no se pudo abrir el archivo");
            exit(1);
        }

                        /******************LEVANTO ARCHIVO *******************/
        while(!feof(pFileArchivo)){

            fscanf(pFileArchivo ,"%[^,],%[^,],%[^,],%d\n",&nAuxId,&szAuxNombre,&szAuxProfecion,&nAuxEdad);

            auxEmpleado = empleado_new();

                if(auxEmpleado!=NULL){
                    strcpy(auxEmpleado->nombre, szAuxNombre);
                    strcpy(auxEmpleado->profecion, szAuxProfecion);
                    auxEmpleado->edad = nAuxEdad;
                    auxEmpleado->id = nAuxId;

                    empleados->add(empleados, auxEmpleado);

                }

            }// WHILE FEOF
            fclose(pFileArchivo);   //CIERRO ARCHIVO
            printf("empleados cargados\n");

}



eEmpleado* empleado_new(void)
{
    eEmpleado* returnAux;
    returnAux = (eEmpleado*)malloc(sizeof(eEmpleado));

    if(returnAux !=NULL){
       strcpy(returnAux->nombre, "");
       strcpy(returnAux->profecion, "");
       returnAux->edad=0;
       returnAux->id=0;
    }
    return returnAux;

}
