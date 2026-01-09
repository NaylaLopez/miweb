//Definiciones comunes (ej. tipos de datos, booleanos)
#ifndef COMMON_H
#define COMMON_H

typedef enum {FALSE = 0, TRUE = 1 };

typedef int TipoElemento;

typedef struct Nodo{
    TipoElemento Dato;
    struct Nodo* siguiente;    
} Nodo;


#endif // COMMON_H
