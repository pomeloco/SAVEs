#include <stdio.h>
#include <stdlib.h>
#include <c://Users/alumno/Desktop/AMB-EstructuraGenerica-master/EstructuraGenerica.h>

#define tamMaximoUsuarios 3
#define tamMaximoPublicaciones 5

int main()
{
    eUsuario Usuarios [tamMaximoUsuarios];


    eUser_init(Usuarios, tamMaximoUsuarios);
    eUser_alta(Usuarios, tamMaximoUsuarios);
    eUser_mostrarUno(Usuarios[0]);

    eUser_modificacion(Usuarios,tamMaximoUsuarios);
    eUser_mostrarUno(Usuarios[0]);

    return 0;
}
