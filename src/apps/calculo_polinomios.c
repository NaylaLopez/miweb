#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include "../include/lista.h"

#define MAX 100

void hacerPolinomio(Lista list){
    TipoElemento te;
    float valor;
    float *clave;
    bool agregar = true;
    int tamano;
    char auxiliar[MAX];  
    printf("Ingrese el grado del polinomio: ");
    fgets(auxiliar, MAX, stdin);
    auxiliar[strcspn(auxiliar, "\n")] = '\0';
    tamano = validar_entero(auxiliar);
    while (tamano < 1)
    {
        printf("El grado del polinomio no puede ser 0 o menor. Ingrese uno correcto.\n");
        printf("Ingrese el grado del polinomio: ");
        fgets(auxiliar, MAX, stdin);
        auxiliar[strcspn(auxiliar, "\n")] = '\0';
        tamano = validar_entero(auxiliar);
    }
    
    printf("Ingrese los coeficientes iniciando con el termino independiente hasta el primero. \n");
    for (int i = 0; i <= tamano; i++)
    {   
        valor = (float)validarReales();
        clave = (float*) malloc(sizeof(float));
        *clave = valor;
        te = te_crear_con_valor(i, clave);
        agregar = l_agregar(list, te);
        if (!agregar)
        {
            printf("ERROR AL CARGAR LISTA.");
            return;
        }
    }
    return;
}

float evaluarPolinomio(Lista list, float x) {
    float resultado = 0;
    Iterador ite = iterador(list);
    TipoElemento te;
    int grado = l_longitud(list) - 1;
    
    while (hay_siguiente(ite)) {
        te = siguiente(ite);
        float coef = *((float*)te->valor);
        resultado += coef * pow(x, grado - te->clave);
    }
    return resultado;
}

Lista calcularRango(Lista list, double x, double y, double sumando){
    Lista l1;
    l1 = l_crear();
    TipoElemento te;
    float *resultado;
    int cont = 0;
    bool agregar = true;
    while (x <= y && agregar)
    {   
        resultado = (float*) malloc(sizeof(float));
        *resultado = evaluarPolinomio(list, x);
        te = te_crear_con_valor(cont++, resultado);
        agregar = l_agregar(l1, te);
        x += sumando;
    }
    return l1;    
}
