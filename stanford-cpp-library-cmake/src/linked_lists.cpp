#include <iostream>

using namespace std;

// Lista Enlazada
//                            actual
//                              v
// {1} -> {2} -> {3} -> {4} -> {5} -> {6} -> {7} -> {8} -> {9} -> {10} -> nullptr

class Nodo {
    public:
        int valor;
        Nodo* siguiente = nullptr;
        
        void insertar(int valor) {
            Nodo* nodo = new Nodo();
            nodo->valor = valor;
            this->siguiente = nodo;
        }
};

class ListaEnlazada {
    public:
        Nodo* cabeza = nullptr;
        
        void imprimir() { // recorrido de la lista (traversal) O(n)
            Nodo* actual = cabeza;
            while (actual != nullptr) {
                cout << actual->valor << " -> ";
                actual = actual->siguiente;
            }
            cout << "/" << endl;
        }

        void insertar(int valor) { // O(n)
        //     if (cabeza == nullptr) {
        //         Nodo* nodo = new Nodo();
        //         nodo->valor = valor;
        //         cabeza = nodo;
        //     } else {
        //         Nodo* actual = cabeza;
        //         while (actual->siguiente != nullptr) {
        //             actual = actual->siguiente;
        //         }
        //         actual->insertar(valor);
        //     }
        // }
            Nodo* nodo = new Nodo();
            nodo->valor = valor;
            Nodo* actual = cabeza;
            if (cabeza == nullptr) {
                cabeza = nodo;
            } else {
                while (actual->siguiente != nullptr) {
                    actual = actual->siguiente;
                }
                actual->siguiente = nodo;
            }
        }

        void buscar(int valor) { // O(n)
            Nodo* actual = cabeza;
            int indice = 0;
            while (actual != nullptr) {
                if (actual->valor == valor) {
                    cout << "Encontrado!" << " Indice: " << indice << endl;
                    return;
                }
                actual = actual->siguiente;
                indice++;
            }
            cout << "No encontrado!" << endl;
        }

        bool contains(int valor) { // O(n)
            Nodo* actual = cabeza;
            while (actual != nullptr) {
                if (actual->valor == valor) {
                    return true;
                }
                actual = actual->siguiente;
            }
            return false;
        }

        int index(int valor) { // O(n)
            Nodo* actual = cabeza;
            int indice = 0;
            while (actual != nullptr) {
                if (actual->valor == valor) {
                    return indice;
                }
                actual = actual->siguiente;
                indice++;
            }
            return -1;
        }

        void insertarAlInicio(int valor) { // O(1)
            Nodo* nodo = new Nodo();
            nodo->valor = valor;
            nodo->siguiente = cabeza;
            cabeza = nodo;
        }

        int removerCabeza() { // O(1)
            if (cabeza != nullptr) {
                Nodo* temp = cabeza;
                cabeza = cabeza->siguiente;
                int valor = temp->valor;
                delete temp;
                return valor;
            }
            return -1;
        }
        //     actual     temp 
        //      v          v
        // -> { x } -> { remover } -> { y }
        //      |______________________^
        int remover(int valor) { // O(n)
            if (cabeza != nullptr) {
                if (cabeza->valor == valor) {
                    return removerCabeza();
                } else {
                    Nodo* actual = cabeza;
                    while (actual->siguiente != nullptr) {
                        if (actual->siguiente->valor == valor) {
                            Nodo* temp = actual->siguiente;
                            actual->siguiente = actual->siguiente->siguiente;
                            int valor = temp->valor;
                            delete temp;
                            return valor;
                        }
                        actual = actual->siguiente;
                    }
                }
            }
            return -1;
        }
};

int main() {
    ListaEnlazada lista;
    Nodo* nodo = new Nodo();
    nodo->valor = 1;
    lista.cabeza = nodo;

    cout << lista.cabeza->valor << endl;

    // Nodo* nodo2 = new Nodo();
    // nodo2->valor = 5;
    // nodo->siguiente = nodo2;
    nodo->insertar(5);

    cout << lista.cabeza->siguiente->valor << endl;

    // Nodo* nodo3 = new Nodo();
    // nodo3->valor = 10;
    // nodo2->siguiente = nodo3;
    nodo->siguiente->insertar(10);
    cout << lista.cabeza->siguiente->siguiente->valor << endl;

    lista.imprimir();

    lista.insertar(2);
    lista.insertar(8);

    lista.imprimir();
    cout << "Buscando 2" << endl;
    lista.buscar(2);
    cout << "Buscando 11" << endl;
    lista.buscar(11);

    lista.insertarAlInicio(0);
    lista.imprimir();
    lista.removerCabeza();
    lista.imprimir();

    lista.remover(5);
    lista.imprimir();

    lista.remover(1);
    lista.imprimir();

    lista.remover(9);
    lista.imprimir();
    lista.remover(8);
    lista.imprimir();

    return 0;
}