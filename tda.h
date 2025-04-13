#ifndef tda_cola

#define tda_cola
#include "struct.h"


void pushBack(Cola* cola, ticket * nuevo);
ticket* popFront(Cola * cola);
ticket* buscarId(Cola * cola, int id);
ticket* eliminarId(Cola * cola, int id);
#endif