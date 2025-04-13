#ifndef funciones

#define funciones
#include "struct.h"
#define funciones

int esNum(char *cadena);
int idExistente(Cola *cola_alta, Cola *cola_media, Cola *cola_baja, int id);
void registrar(int id, const char *desc);
void cambiar(int id, prioridad nuevo);
void mostrar_pendiente();
void procesar_sgte();
void buscar_ticket(int id);
void mostrar_ticket(ticket *t);


void registrar_ticket();
void cambiar_prioridad(int id, prioridad nuevaPrioridad);
void limpiar_pantalla();
void presione_tecla();
void mostrarCola(Cola* cola);
const char* obtener_priori(prioridad p);
#endif