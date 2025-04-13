#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "struct.h"
#include "tda.h"

Cola cola_alta = {NULL, NULL};
Cola cola_media = {NULL, NULL};
Cola cola_baja = {NULL, NULL};

int esNum(char *cadena) {
    if (*cadena == '\0') return 0;
    if (*cadena == '-' || *cadena == '+') cadena++;
    while (*cadena) {
        if (!isdigit(*cadena)) return 0;
        cadena++;
    }
    return 1;
}

int idExistente(Cola *cola_alta, Cola *cola_media, Cola *cola_baja, int id) {
    Cola *colas[] = {cola_alta, cola_media, cola_baja};
    for (int i = 0; i < 3; i++) {
        ticket *aux = colas[i]->head;
        while (aux) {
            if (aux->id == id) return 1;
            aux = aux->sgte;
        }
    }
    return 0;
}
const char* obtener_priori(prioridad p) {
    switch (p) {
        case alto: return "ALTO";
        case medio: return "MEDIO";
        case bajo: return "BAJO";
        default: return "DESCONOCIDA";
    }
}

void registrar(int id, const char* desc) {
    if (idExistente(&cola_alta,&cola_media,&cola_baja, id)) {
        printf("EL ID %d YA AH SIDO REGISTRADO.\n", id);
        return;
    }

    ticket *nuevo = malloc(sizeof(ticket));
    nuevo->id = id;
    strncpy(nuevo->desc, desc, sizeof(nuevo->desc) - 1);
    nuevo->desc[sizeof(nuevo->desc) - 1] = '\0';
    nuevo->priori = bajo;
    nuevo->hora = time(NULL);
    nuevo->sgte = NULL;

    pushBack(&cola_baja, nuevo);
    printf("TICKET %d FUE REGISTRADO CON PRIORIDAD BAJO.\n", id);
}

void cambiar(int id, prioridad nueva) {
    ticket *t = eliminarId(&cola_alta, id);
    if (!t) t = eliminarId(&cola_media, id);
    if (!t) t = eliminarId(&cola_baja, id);

    if (!t) {
        printf("TICKET CON ID %d NO FUE ENCONTRADO.\n", id);
        return;
    }

    t->priori = nueva;
    t->sgte = NULL;

    switch (nueva) {
        case alto: pushBack(&cola_alta, t); break;
        case medio: pushBack(&cola_media, t); break;
        case bajo: pushBack(&cola_baja, t); break;
        default: printf("ERROR : PRIORIDAD INVALIDA ...... \n"); break;
    }

    printf("PRIORIDAD DEL TICKET %d CAMBIADA A %s.\n", id, obtener_priori(nueva));
}

void mostrar_ticket(const ticket *t) {
    if (!t) return;
    char tiempo[26];
    strftime(tiempo, sizeof(tiempo), "%Y-%m-%d %H:%M:%S", localtime(&t->hora));

    printf("--------------------------------------------------\n");
    printf("ID: %d | PRIORIDAD: %s | HORA: %s\nDESCRIPCION: %s\n",
           t->id, obtener_priori(t->priori), tiempo, t->desc);
    printf("--------------------------------------------------\n");
}

void buscar_ticket(int id) {
    ticket *t = buscarId(&cola_alta, id);
    if (!t) t = buscarId(&cola_media, id);
    if (!t) t = buscarId(&cola_baja, id);

    if (t) {
        printf("\nTICKET ES :\n");
        mostrar_ticket(t);
    } else {
        printf("TICKET CON EL ID %d NO FUE ENCONTRADO.\n", id);
    }
}

void mostrarCola(Cola *cola) {
    ticket *actual = cola->head;
    if (!actual) {
        printf(" (VACIA)\n");
        return;
    }
    while (actual) {
        printf("- ID: %d | DESCRIPCION: %s | HORA: %s",
               actual->id, actual->desc, ctime(&actual->hora));
        actual = actual->sgte;
    }
}

void mostrar_pendiente() {
    if (!cola_alta.head && !cola_media.head && !cola_baja.head) {
        printf("NO EXISTEN TICKETS PENDIENTES.\n");
        return;
    }

    printf("\n------------ LISTA DE TICKETS PENDIENTES ------------\n");
    printf("\nPRIORIDAD ALTA:\n");
    mostrarCola(&cola_alta);

    printf("\nPRIORIDAD MEDIA:\n");
    mostrarCola(&cola_media);

    printf("\nPRIORIDAD BAJA:\n");
    mostrarCola(&cola_baja);
}

void procesar_sgte() {
    Cola *cola = NULL;

    if (cola_alta.head) cola = &cola_alta;
    else if (cola_media.head) cola = &cola_media;
    else if (cola_baja.head) cola = &cola_baja;

    if (!cola) {
        printf("NO HAY TICKETS PENDIENTES.\n");
        return;
    }

    ticket *t = cola->head;
    cola->head = t->sgte;
    if (!cola->head) cola->tail = NULL;

    printf("\nPROCESANDO TICKET:\n");
    mostrar_ticket(t);
    free(t);
}

void limpiar_pantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void presione_tecla() {
    puts("Presione ENTER para continuar...");
    getchar();                 
}
