#ifndef ESTRUCTURAGENERICA_H_INCLUDED
#define ESTRUCTURAGENERICA_H_INCLUDED
typedef struct
{
    char usuario[20];
    char password[16];
    int idGenerica;
    int estado;
}eUsuario;

typedef struct{

    char szNombre[30];
    int idProducto;
    float fPrecio;
    int bEstado;
    int nStock;
    int nVendidos;
}eProductos;

typedef struct{

    int idUsuario;
    int idProducto;
}ePublicacion;
#endif // ESTRUCTURAGENERICA_H_INCLUDED

int eUser_init(eUsuario[],int limite);
int eUser_buscarPorId(eUsuario[] ,int limite, int id);
int eUser_siguienteId(eUsuario[] ,int limite);
int eUser_buscarLugarLibre(eUsuario listado[],int limite);

int eUser_mostrarUno(eUsuario parametro);
int eUser_mostrarListado(eUsuario[] ,int limite);
int eUser_mostrarListadoConBorrados(eUsuario[] ,int limite);

int eUser_alta(eUsuario[] ,int limite);
int eUser_baja(eUsuario[] ,int limite, int id);
int eUser_modificacion(eUsuario[] ,int limite);

int eUser_ordenar(eUsuario[] ,int limite, int orden);


char* eUser_cargarUsuario(char*);
int pedirEntero(char*);
