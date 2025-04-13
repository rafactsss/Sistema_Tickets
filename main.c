#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "funciones.h"
#include "tda.h"

extern Cola cola_alta, cola_media, cola_baja;

int main(){
    int opcion;
    do{
        printf("--------BIENVENIDO AL SISTEMA DE TICKET-------\n");
        printf("1. REGISTRAR NUEVO TICKET\n");
        printf("2. CAMBIAR PRIORIDAD\n");
        printf("3. MOSTRAR PENDIENTES\n");
        printf("4. PROCESAR TICKET SIGUIENTE\n");
        printf("5. BUSCAR TICKET POR ID\n");
        printf("6. SALIR DEL SISTEMA\n");
        printf("--------SELECCIONE UNA OPCION--------");
        scanf("%d", &opcion);
        getchar();
        limpiar_pantalla();
        int id;
        int priori;
        char desc[256]; 
        char idStr[256];

        switch(opcion){
            case 1: 
                printf("===================================\n");
                printf("INGRESE EL ID DEL TICKET :\n");
                printf("===================================\n\n");

                fgets(idStr, sizeof(idStr), stdin);
                idStr[strcspn(idStr, "\n")] = 0;

                if (!esNum(idStr)) {
                    printf("ERROR EL ID TIENE QUE CONTENER SOLO NUMEROS..........\n");
                    presione_tecla();
                    break;
                }

                id = atoi(idStr);

                if (idExistente(&cola_alta, &cola_media, &cola_baja, id)) {
                    printf("ERROR, EL ID %d YA FUE REGISTRADO.\n", id);
                    presione_tecla();
                    break;
                }

                printf("===================================\n");
                printf("DESCRIBA EL PROBLEMA :\n");
                printf("===================================\n\n");
                fgets(desc, sizeof(desc), stdin);
                desc[strcspn(desc,"\n")] = 0;
                registrar(id, desc);
                break;

            case 2:
                printf("===================================\n");
                printf("INGRESE EL ID DEL TICKET :\n");
                printf("===================================\n\n");   
                fgets(idStr, sizeof(idStr), stdin);
                idStr[strcspn(idStr, "\n")] = 0;
                if (!esNum(idStr)) {
                    printf("ERROR EL ID TIENE QUE CONTENER SOLO NUMEROS..........\n");
                    presione_tecla();
                    break;
                }

                id = atoi(idStr);

                if (!idExistente(&cola_alta, &cola_media, &cola_baja, id)) {
                    printf("ERROR, EL ID %d NO EXISTE.\n", id);
                    presione_tecla();
                    break;

                }
                printf("PRIORIDADES : ALTO = 2 | MEDIO = 1 | BAJA = 0\n");
                printf("LA NUEVA PRIORIDAD ES :\n");
                scanf("%d", &priori);
                getchar();
                if (priori < 0 || priori > 2) {
                    printf("ERROR: Prioridad inválida.\n");
                } else {
                    cambiar(id, (prioridad)priori);
                }
                presione_tecla();
                break;
                

            case 3 :
                mostrar_pendiente();
                presione_tecla();
                break;
        
            case 4 : 
                procesar_sgte();
                presione_tecla();
                break;

            case 5 :
                printf("===================================\n");
                printf("INGRESE EL ID DEL TICKET :\n");
                printf("===================================\n\n");   
                fgets(idStr, sizeof(idStr), stdin);
                idStr[strcspn(idStr, "\n")] = 0;
                if (!esNum(idStr)) {
                    printf("ERROR EL ID TIENE QUE CONTENER SOLO NUMEROS..........\n");
                    presione_tecla();
                    break;
                }

                id = atoi(idStr);

                if (!idExistente(&cola_alta, &cola_media, &cola_baja, id)) {
                    printf("ERROR, EL ID %d NO EXISTE.\n", id);
                    presione_tecla();
                    break;
                }
                buscar_ticket(id);
                presione_tecla();
                break;

            case 6 : 
                printf("A SALIDO DEL SISTEMA..............");
                return 0;
    
        }
    }while(opcion != 0);

    return 0;
}





