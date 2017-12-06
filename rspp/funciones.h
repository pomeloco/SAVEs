#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

    char profecion[30];
    int edad;
    int id;
    char nombre [50];

}eEmpleado;

int funcionQueFiltra (void* item);

void CargarArchivo(ArrayList* empleados);


eEmpleado* empleado_new(void);

#endif // FUNCIONES_H_INCLUDED
