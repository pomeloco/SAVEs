#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "funciones.h"

int main()
{

ArrayList* empleados = al_newArrayList();
int i;


    CargarArchivo(empleados);

    for(i=0;i<empleados->len(empleados);i++){
    al_filter(empleados,funcionQueFiltra(empleados->get(empleados,i)));
    }

return 0;
}
