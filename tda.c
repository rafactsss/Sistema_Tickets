#include <stdlib.h>
#include "tda.h"

void pushBack(Cola *cola, ticket *nuevo) {
    if (!cola->head) {
        cola->head = cola->tail = nuevo;
    } else {
        cola->tail->sgte = nuevo;
        cola->tail = nuevo;
    }
}

ticket* popFront(Cola* cola) {
    if (!cola->head) return NULL;
    ticket* temp = cola->head;
    cola->head = temp->sgte;
    if (!cola->head) cola->tail = NULL;
    return temp;
}

ticket* buscarId(Cola *cola, int id) {
    ticket *actual = cola->head;
    while (actual) {
        if (actual->id == id) return actual;
        actual = actual->sgte;
    }
    return NULL;
}

ticket* eliminarId(Cola *cola, int id) {
    ticket *actual = cola->head, *anterior = NULL;
    while (actual) {
        if (actual->id == id) {
            if (anterior) {
                anterior->sgte = actual->sgte;
            } else {
                cola->head = actual->sgte;
            }
            if (actual == cola->tail) {
                cola->tail = anterior;
            }
            actual->sgte = NULL;
            return actual;
        }
        anterior = actual;
        actual = actual->sgte;
    }
    return NULL;
}


