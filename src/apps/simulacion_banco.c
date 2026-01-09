#include "../include/cola.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define MAX 11

Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion){
    Cola c1aux = c_ej2_copiar(c1);
    Cola c2aux = c_ej2_copiar(c2);
    Cola c3aux = c_ej2_copiar(c3);
    Cola colaresultado = c_crear();
    TipoElemento tec1, tec2, tec3, teclaveresul;
    int poscola1 = 1;
    int poscola2 = 1;
    int poscola3 = 1;
    while (!c_es_vacia(c1aux) || !c_es_vacia(c2aux) || !c_es_vacia(c3aux))
    {   
        if (!c_es_vacia(c1aux)){   
            tec1 = c_recuperar(c1aux);
            tec1->clave -= tiempoatencion;
            if (tec1->clave <= 0)
            {
                char *resultado1 = malloc(sizeof(char) * 20);
                sprintf(resultado1, "Cliente %d Cola %d", poscola1, 1);
                teclaveresul =te_crear_con_valor(tec1->clave, resultado1);
                c_encolar(colaresultado, teclaveresul);
                c_desencolar(c1aux);
                poscola1++;
            }
        }
        if (!c_es_vacia(c2aux)){
            tec2 = c_recuperar(c2aux);
            tec2->clave -= tiempoatencion;
            if (tec2->clave <= 0)
            {
                char *resultado2 = malloc(sizeof(char) * 20);
                sprintf(resultado2, "Cliente %d Cola %d", poscola2, 2);
                teclaveresul =te_crear_con_valor(tec2->clave, resultado2);
                c_encolar(colaresultado, teclaveresul);
                c_desencolar(c2aux);
                poscola2++;
            }
        }
        if (!c_es_vacia(c3aux)){
            tec3 = c_recuperar(c3aux);
            tec3->clave -= tiempoatencion;
            if (tec3->clave <= 0)
            {
                char *resultado3 = malloc(sizeof(char) * 20);
                sprintf(resultado3, "Cliente %d Cola %d", poscola3, 3);
                teclaveresul =te_crear_con_valor(tec3->clave, resultado3);
                c_encolar(colaresultado, teclaveresul);
                c_desencolar(c3aux);
                poscola3++;
            }
        }
    }
    return colaresultado;
}