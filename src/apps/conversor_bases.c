#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/pila.h"
#define MAX 10

char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){
    Pila pila = p_crear();
    TipoElemento te;
    int resto, valor;
    char *resultado = (char*)malloc(sizeof(char)*MAX);
    char *auxc = resultado;
    if (nrobasedecimal < 0)
    {
        printf("Es negativo se lo tratara como positivo.\n");
        nrobasedecimal = nrobasedecimal + (nrobasedecimal* -2);
    }
    
    while (nrobasedecimal >= nrootrabase)
    {
        resto = nrobasedecimal % nrootrabase;
        te = te_crear(resto);
        p_apilar(pila, te);
        nrobasedecimal /= nrootrabase;
    }
    te = te_crear(nrobasedecimal);
    p_apilar(pila, te);
    while (!p_es_vacia(pila))
    {
        te = p_desapilar(pila);
        valor = te->clave;
    // Convertimos el número a carácter
        if (valor < 10){
        *auxc = '0' + valor; 
        }     // para 0-9
         else *auxc = 'A' + (valor - 10); // para 10-15 → A-F

    auxc++;
    }
    *auxc = '\0';
    return resultado;
}