#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED
typedef struct
{
    char szApellido[20];
    char szNombre[20];
    char szDireccion[20];
    char szTarjetaDeCredito[12];
    int idPropietario;
    int estado;

}ePropietario;


typedef struct{

    char szPatente[8];
    int nMarca;
    int idPropietario;
    int hHorarioEntrada;
    int estado;
}eAuto;

#endif // ESTRUCTURAGENERICA_H_INCLUDED

int eProp_init(ePropietario[],int limite);
int eProp_buscarPorId(ePropietario[] ,int limite, int id);
int eProp_siguienteId(ePropietario[] ,int limite);
int eProp_buscarLugarLibre(ePropietario listado[],int limite);

int eProp_mostrarUno(ePropietario parametro);
int eProp_mostrarListado(ePropietario[] ,int limite);
int eProp_mostrarListadoConBorrados(ePropietario[] ,int limite);

int eProp_alta(ePropietario[] ,int limite);
int eProp_baja(ePropietario[] ,int limite, int id);
int eProp_modificacion(ePropietario[] ,int limite);

int eProp_ordenar(ePropietario[] ,int limite, int orden);


char* eProp_cargarUsuario(char*);
int pedirEntero(char*);

void eProp_hardcodeo(ePropietario[]);



char pregunta(char*);


int eAuto_altaEstacionamiento(eAuto[], ePropietario[], int limiteAutos, int limitePropietarios);
int eAuto_buscarLugarLibreAuto(eAuto listadoAutos[],int limite);
int eAuto_initAuto(eAuto[],int limite);
int eAuto_buscarPorPatente(eAuto Autos[] ,int limite, char* patente);
int eAuto_egresoEstacionamiento(eAuto Autos[],ePropietario Popietarios ,int limiteAutos, int limitePropietarios, char* patente);
int eAuto_mostrarUnAuto(eAuto parametro);
int eAuto_mostrarListado(eAuto Auto[] ,int limite);


void eAuto_harcodeo(eAuto[]);
