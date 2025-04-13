#ifndef estructura
#define estructura
#include <time.h>

typedef enum{
    bajo = 0, medio = 1, alto = 2
}prioridad;

typedef struct ticket{
    int id;
    char desc[256];
    prioridad priori;
    time_t hora;
    struct ticket* sgte;
}ticket;

typedef struct Cola{
    ticket *head;
    ticket *tail;
}Cola;
#endif