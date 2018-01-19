#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include <string.h>
#include "lib.h"


/*typedef struct{

       char szMail[100], szNombre[100];
}ePersona;

ePersona* persona_new(void);    //CONSTRUCTOR PERSONA
void persona_print(ePersona* this); //MOSTRAR PERSONA*/

int main()
{
    ArrayList* pArrayDestinatarios = al_newArrayList(); //CREA ARRAY LIST DESTINATARIO
    ArrayList* pArrayListaNegra = al_newArrayList(); //CREA ARRAY LIST BLACK
    ArrayList* pArrayDepurada = al_newArrayList(); //CREA ARRAYLIST DEPURADA

    FILE *pFileArchivo;     // ARCHIVOS
    ePersona* Persona;      //PERSONA
    char szAuxMail[100], szAuxNombre[100];  //AUXILIARES
    int nOpcion;
    char StringAux[100];


    if(pArrayDestinatarios == NULL){
        printf("no se pudo guardar memoria!");
        exit(1);
    }

    if(pArrayDepurada == NULL){
        printf("no se pudo guardar memoria!");
        exit(1);
    }

    if(pArrayListaNegra == NULL){
        printf("no se pudo guardar memoria!");
        exit(1);
    }


    do{
        printf("1-Destinatario\n2-Black\n3-Depurar\n4-Listar\n5-Salir");
        scanf("%d", &nOpcion);
    switch(nOpcion){

     case 1:    //DESTINATARIOS

        printf("ingrese nombre de archivo _destinatarios_ con su extencion: ");
        fflush(stdin);
        scanf("%s", &StringAux);
        pFileArchivo = fopen(StringAux, "r");     //ABRO ARCHIVO

        if(pFileArchivo == NULL){

            printf("no se pudo abrir el archivo");
            exit(1);
        }

                        /******************LEVANTO ARCHIVO *******************/
        while(!feof(pFileArchivo)){

            fscanf(pFileArchivo ,"%[^,],%s\n",szAuxNombre,szAuxMail);

            Persona = persona_new();

                if(Persona!=NULL){
                    strcpy(Persona->szMail, szAuxMail);
                    strcpy(Persona->szNombre, szAuxNombre);

                   /* pArrayDestinatarios->add(pArrayDestinatarios, Persona->szMail);
                    pArrayDestinatarios->add(pArrayDestinatarios, Persona->szNombre);*/

                    pArrayDestinatarios->add(pArrayDestinatarios, Persona);

                }

            }// WHILE FEOF
            fclose(pFileArchivo);   //CIERRO ARCHIVO
            printf("Destinatarios cargados\n");

         break; //case 1

     case 2: //BLACKLIST

        printf("ingrese nombre de archivo _blacklist_ con su extencion: ");
        fflush(stdin);
        scanf("%s", &StringAux);
        pFileArchivo = fopen(StringAux, "r");     //ABRO ARCHIVO

        if(pFileArchivo == NULL){

            printf("no se pudo abrir el archivo");
            exit(1);
        }

                        /******************LEVANTO ARCHIVO *******************/
        while(!feof(pFileArchivo)){

            fscanf(pFileArchivo ,"%[^,],%s\n",szAuxNombre,szAuxMail);

            Persona = persona_new();

                if(Persona!=NULL){
                    strcpy(Persona->szMail, szAuxMail);
                    strcpy(Persona->szNombre, szAuxNombre);
                    pArrayListaNegra->add(pArrayListaNegra, Persona);

                   /* for(int i=0; i<pArrayDestinatarios->size;i++){

                       if( pArrayDestinatarios->contains(pArrayDestinatarios, Persona) == 0){

                        pArrayListaNegra->add(pArrayListaNegra, pArrayDestinatarios->get(pArrayDestinatarios, i));
                        break;
                       }
                    }*/

                }

            }// WHILE FEOF
            fclose(pFileArchivo);   //CIERRO ARCHIVO
            printf("blacklist cargada\n");

        break; //case 2


     case 3:

      for(int i=0; i<pArrayDestinatarios->size;i++){

        for(int j=0 ; j<pArrayListaNegra->size; j++){

            if(pArrayDestinatarios->contains(pArrayDestinatarios,pArrayListaNegra->pElements[j])==0){

                pArrayDepurada->add(pArrayDepurada,pArrayDestinatarios->pElements[i]);
                break;
            }


        } //FOR J

      }//FOR I


        /***********************************************/

      for(int i=0; i<pArrayDepurada->size-1;i++){

        for(int j=i+1 ; j<pArrayDepurada->size; j++){

            if(pArrayDestinatarios->get(pArrayDestinatarios,i) == pArrayDestinatarios->get(pArrayDestinatarios,j)){
                //if(pArrayDepurada->contains(pArrayDepurada, pArrayDepurada->pElements[i])==0){
                pArrayDepurada->remove(pArrayDepurada,pArrayDepurada->pElements[j]);

            }


        } //FOR J
      }//FOR I

        printf("depuracion completada");


        break; //case 3




     case 4:
                for(int i=0; i<pArrayDepurada->size ; i++){
                persona_print(pArrayDepurada->pElements[i]);
                }

               /* for(int i=0; i<pArrayListaNegra->size ; i++){
                persona_print(pArrayListaNegra->pElements[i]);
                }*/

               /* for(int i=0; i<pArrayDestinatarios->size ; i++){
                persona_print(pArrayDestinatarios->pElements[i]);
                }*/
            break;

    }//SWITCH

    }while(nOpcion != 5);





    return 0;
    } // MAIN



/*ePersona* persona_new(void)
{
    ePersona* returnAux;
    returnAux = (ePersona*)malloc(sizeof(ePersona));

    if(returnAux !=NULL){
       strcpy(returnAux->szNombre, "");
       strcpy(returnAux->szMail, "");
    }
    return returnAux;

}


void persona_print(ePersona* this)
{
    if(this != NULL){
        printf("%s - %s \n", this->szNombre, this->szMail);
    }
}*/

