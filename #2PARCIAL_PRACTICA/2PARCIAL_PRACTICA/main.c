#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h" //LA MUERTE
#include <string.h>


typedef struct{

       char szMail[100], szNombre[100];
}ePersona;

ePersona* persona_new(void);    //CONSTRUCTOR PERSONA
void persona_print(ePersona* this); //MOSTRAR PERSONA

int main()
{
    ArrayList* pArrayDestinatarios = al_newArrayList(); //CREA ARRAY LIST DESTINATARIO
    ArrayList* pArrayListaNegra = al_newArrayList(); //CREA ARRAY LIST BLACK
    ArrayList* pArrayDepurada = al_newArrayList(); //CREA ARRAYLIST DEPURADA

    FILE *pFileArchivo;     // ARCHIVOS
    ePersona* Persona;      //PERSONA
    char szAuxMail[100], szAuxNombre[100];  //AUXILIARES
    int nOpcion;


    if(pArrayDestinatarios == NULL){
        printf("no se pudo guardar memoria! compra ram media pila");
        exit(1);
    }


    do{
        printf("1-Destinatario\n2-Black\n3-Depurar\n4-Listar\n5-Salir");
        scanf("%d", &nOpcion);
    switch(nOpcion){

     case 1:    //DESTINATARIOS

        pFileArchivo = fopen("destinatarios.csv", "r");     //ABRO ARCHIVO

        if(pFileArchivo == NULL){

            printf("no se pudo abrir el archivo, cagaste");
            exit(1);
        }

                        /******************LEVANTO ARCHIVO *******************/
        while(!feof(pFileArchivo)){

            fscanf(pFileArchivo ,"%[^,],%s\n",szAuxNombre,szAuxMail);

            Persona = persona_new();

                if(Persona!=NULL){
                    strcpy(Persona->szMail, szAuxMail);
                    strcpy(Persona->szNombre, szAuxNombre);

                    pArrayDestinatarios->add(pArrayDestinatarios, Persona);

                }

            }// WHILE FEOF
            fclose(pFileArchivo);   //CIERRO ARCHIVO
            printf("Destinatarios cargados\n");

         break; //case 1

     case 2: //BLACKLIST


        pFileArchivo = fopen("black_list.csv", "r");     //ABRO ARCHIVO

        if(pFileArchivo == NULL){

            printf("no se pudo abrir el archivo, cagaste");
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

                }

            }// WHILE FEOF
            fclose(pFileArchivo);   //CIERRO ARCHIVO
            printf("blacklist cargada\n");

        break; //case 2


     case 3:

        /*for(int i= 0 ; i<pArrayDestinatarios->size; i++){

            if(pArrayDestinatarios->contains(pArrayDestinatarios,pArrayListaNegra->pElements[i])==0){
                    pArrayDepurada->add(pArrayDestinatarios->pElements[i]);
            }
        }*/

      for(int i=0; i<pArrayDestinatarios->size;i++){

        for(int j=0 ; j<pArrayListaNegra->size; j++){

            if(pArrayDestinatarios->contains(pArrayDestinatarios,pArrayListaNegra->pElements[j])==0 || pArrayListaNegra->contains(pArrayListaNegra,pArrayDestinatarios->pElements[i])==0){

                pArrayDepurada->add(pArrayDepurada,pArrayDestinatarios->pElements[i]);
                printf("depuracion completa2\n");
            }

        } //FOR J
      }//FOR I



        break;




     case 4:
                for(int i=0; i<pArrayDepurada->size ; i++){
                persona_print(pArrayDepurada->pElements[i]);
                }

            break;

    }//SWITCH

    }while(nOpcion != 5);





    return 0;
    } // MAIN



ePersona* persona_new(void)
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
}
