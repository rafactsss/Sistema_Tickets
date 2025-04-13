#SISTEMA DE GESTION DE TICKETS 

Este es un sistema en c el cual permite gestionar, registrar y procesar tickets con prioridades(alta,media y baja).

#COMO COMPILAR Y EJECUTAR LA TAREA

-ARCHIVOS NECESARIOS : funciones.c, funciones.h, main.c, struct.h, tda.c, tda.h.

#COMPILACION

abre una terminal en la carpeta del proyecto y ejecuta el siguiente comando:

---------------------------------------------------
gcc main.c tda.c funciones.c -o sistema_tickets.exe
---------------------------------------------------

esto ejecutara el archivo sistema_tickets.exe y para ejecutar el programa utiliza : ./sistema_tickets.exe

#FUNCIONALIDADES IMPLEMENTADAS :

-Registrar nuevo ticket
-Cambiar prioridad
-Mostrar pendientes+
-Procesar ticket siguiente
-Buscar ticket por id
-Salir

#COSAS A MEJORAR

aun se encuentra en desarrollo la interfaz, para que esta tenga una apariencia mas amigable.

#PROBLEMAS QUE PODRIAN APARACER

-CUANDO NO SE EJECUTEN TODOS LOS ARCHIVOS.C JUNTOS DARA UN ERROR
-HAY QUE VERIFICAR QUE TODOS LOS ARCHIVOS ".H" ESTEN INCLUIDOS.

#EJEMPLO DE SU USO 

--------BIENVENIDO AL SISTEMA DE TICKET-------
1. REGISTRAR NUEVO TICKET
2. CAMBIAR PRIORIDAD
3. MOSTRAR PENDIENTES
4. PROCESAR TICKET SIGUIENTE
5. BUSCAR TICKET POR ID
6. SALIR DEL SISTEMA

PASO 1 : INGRESA EL NUMERO 1

--------SELECCIONE UNA OPCION--------1

PASO 2 : INGRESA EL ID DEL TICKET

===================================
INGRESE EL ID DEL TICKET :
===================================

1001


PASO 3 : DESCRIBA EL PROBLEMA

===================================
DESCRIBA EL PROBLEMA :
===================================

No funciona el mouse

Ticket registrado con éxito.

Presione cualquier tecla para continuar...

PASO 4: PRESIONA LA TECLA 4 (DEBERIA PROCESARLO).

--------------------------------------------------
Presione ENTER para continuar...


PASO 5: COMPROBAR LA FUNCION, SELECCIONE LA OPCION 5 Y INGRESE EL ID 

ERROR, EL ID 222 NO EXISTE.
Presione ENTER para continuar...


