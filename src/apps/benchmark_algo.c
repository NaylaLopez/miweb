#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/arbol.h"
#include "../include/hash.h"
#define STR_MAX 100
#define NUMERO_PRIMO_5 997
int NUMERO_PRIMO;

//funcion hash
int hash_function(int clave){
    int pos = clave % NUMERO_PRIMO;
    return pos;
}

int funcion_hash(int a){
    int poss= (a % NUMERO_PRIMO_5);
    return poss;
}


void cargar_arbolavl_tablahash_aleatorios(ArbolAVL AVL, TablaHash TH, int cant_numeros, int min, int max){
    int i= 0;
    bool busqueda = false;
    TipoElemento X;
    while (i<cant_numeros){
        X= te_crear(min+ rand() % (max+1 - min));
        buscar_elemento(avl_raiz(AVL), X->clave, &busqueda);
        if ((busqueda == false)){
            th_insertar(TH, X);
            avl_insertar(AVL, X);
            i++;
        }
        busqueda = false;
    }
}

void buscar_elemento(NodoArbol nodo, int clave, bool *busqueda){
    if (nodo == NULL) {
        return;
    }
    if (nodo->datos->clave == clave) {
        *busqueda = true;
        return;
    }
    buscar_elemento(n_hijoizquierdo(nodo), clave, busqueda);
    buscar_elemento(n_hijoderecho(nodo), clave, busqueda);
}


void th_ej5_comparacion(int q_claves, int q_repeticiones, int rango_desde, int rango_hasta){
    ArbolAVL avl = avl_crear();
    TablaHash tab = th_crear(q_claves, funcion_hash);
    clock_t tiempo_avl, tiempo_th;
    double tiempo_total_avl= 0;
    double tiempo_total_tabla= 0;
    TipoElemento X, X2;
    cargar_arbolavl_tablahash_aleatorios(avl, tab,q_claves, rango_desde, rango_hasta);

    tiempo_avl = clock();
    for (int i = 0; i < q_repeticiones; i++){
        X= te_crear(rango_desde+ rand() % (rango_hasta+1 - rango_desde));
        X2= avl_buscar(avl, X->clave);
    }
    tiempo_avl= clock()- tiempo_avl;
    tiempo_total_avl += ((double)tiempo_avl)/CLOCKS_PER_SEC;

    tiempo_th= clock();
    for (int i = 0; i < q_repeticiones; i++){
        X= te_crear(rango_desde+ rand() % (rango_hasta+1 - rango_desde));
        X2= th_recuperar(tab, X->clave);
    }
    tiempo_th= clock()- tiempo_th;
    tiempo_total_tabla+= ((double)tiempo_th)/CLOCKS_PER_SEC;

    printf("Tiempo total de la busqueda de las claves en el Arbol AVL: %.10f segundos.\n", tiempo_total_avl);
    printf("Tiempo total de la busqueda de las claves en la Tabla Hash: %.10f segundos.\n", tiempo_total_tabla);

}