
#include <iostream>
using namespace std;

// Estructura del nodo
struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
};

// Crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo();

    nuevo->dato = valor;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;

    return nuevo;
}

// Insertar elementos en el arbol
Nodo* insertar(Nodo* raiz, int valor) {

    if (raiz == NULL) {
        return crearNodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    }
    else if (valor > raiz->dato) {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    return raiz;
}

// RECORRIDO PREORDEN
void preorden(Nodo* raiz) {

    if (raiz != NULL) {
        cout << raiz->dato << " ";
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

// RECORRIDO INORDEN
void inorden(Nodo* raiz) {

    if (raiz != NULL) {
        inorden(raiz->izquierda);
        cout << raiz->dato << " ";
        inorden(raiz->derecha);
    }
}

// RECORRIDO POSTORDEN
void postorden(Nodo* raiz) {

    if (raiz != NULL) {
        postorden(raiz->izquierda);
        postorden(raiz->derecha);
        cout << raiz->dato << " ";
    }
}

// PROGRAMA PRINCIPAL
int main() {

    Nodo* raiz = NULL;

    // Insertar numeros
    raiz = insertar(raiz, 20);
    raiz = insertar(raiz, 10);
    raiz = insertar(raiz, 30);
    raiz = insertar(raiz, 5);
    raiz = insertar(raiz, 15);
    raiz = insertar(raiz, 25);
    raiz = insertar(raiz, 35);

    // Mostrar recorridos
    cout << "Recorrido Preorden: ";
    preorden(raiz);

    cout << "\n\nRecorrido Inorden: ";
    inorden(raiz);

    cout << "\n\nRecorrido Postorden: ";
    postorden(raiz);

    cout << endl;

    return 0;
}
