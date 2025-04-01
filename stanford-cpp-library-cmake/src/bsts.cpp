#include <iostream>

using namespace std;

// BSTs (min)
// Propiedad BST: el valor del nodo izquierdo de otro nodo es menor, y el valor 
// del nodo derecho es mayor
//      10  raiz (no tiene padre)
//      |
//  _________
//  |       |
// 4        18 nodo intermedio (tiene padre e hijos)
        //  |
    // _________
    // |       |
    // 12      20  hoja (nodo terminal, no tienen hijos)
    // |
//  X_____X (15)
class Nodo {
    public:
        int valor;
        Nodo* izquierdo = nullptr;
        Nodo* derecho = nullptr;
        
        Nodo(int valor) {
            this->valor = valor;
        }
};

class BST {
    public:
        Nodo* raiz = nullptr;
        void insertar(int valor) { // helper function
            raiz = insertar_recursivo(raiz, valor);
        }

        void recorrido() {
            recorrido_recursivo(raiz);
        }

        int minimo();
        int maximo();
        int buscar(int valor);

    private:
        void recorrido_recursivo(Nodo* nodo) {
            if (nodo == nullptr) {

            } else {
                cout << nodo->valor << endl; // pre order traversal 
                recorrido_recursivo(nodo->izquierdo); 
                // cout << nodo->valor << endl; // in order traversal 
                recorrido_recursivo(nodo->derecho);
                // cout << nodo->valor << endl; // post order traversal 
            }
        }

        Nodo* insertar_recursivo(Nodo* nodo, int valor) {
            if (nodo == nullptr) {
                return new Nodo(valor);
            } else {
                if (valor < nodo->valor) {
                    nodo->izquierdo = insertar_recursivo(nodo->izquierdo, valor);
                } else {
                    nodo->derecho = insertar_recursivo(nodo->derecho, valor);
                }
                return nodo;
            }
        }

        void insertar_iterativo(int valor) {
            Nodo* nuevo_nodo = new Nodo(valor);
            if (raiz==nullptr) {
                raiz = nuevo_nodo;
            } else {
                Nodo* nodo_actual = raiz;
                Nodo* nodo_padre = nullptr;
                while (nodo_actual != nullptr) {
                    // nodo_padre = nodo_actual;
                    if (valor < nodo_actual->valor) {
                        nodo_padre = nodo_actual;
                        nodo_actual = nodo_actual->izquierdo;
                    } else {
                        nodo_padre = nodo_actual;
                        nodo_actual = nodo_actual->derecho;
                    }
                }
                if (valor < nodo_padre->valor) {
                    nodo_padre->izquierdo = nuevo_nodo;
                } else {
                    nodo_padre->derecho = nuevo_nodo;
                }
            }
        }
};

int main() {
    BST miBST;
    miBST.insertar(10);
    miBST.insertar(4);
    miBST.insertar(18);
    miBST.insertar(12);
    miBST.insertar(7);
    miBST.insertar(11);
    miBST.insertar(17);
    miBST.insertar(14);
    miBST.insertar(1);
    miBST.insertar(3);
    miBST.insertar(19);
    miBST.insertar(9);
    miBST.insertar(15);
                            //                 10                              h = 0 // busqueda binaria
                            //     4                               18          h = 1
                            // 1           7            12             19      h = 2
                            //   3             9    11        17
                            //                            14
                            //                               15




    // cout << "Raiz: " << miBST.raiz->valor << endl; 
    // cout << "Raiz -> izquierdo: " << miBST.raiz->izquierdo->valor << endl;
    // cout << "Raiz -> derecho: " << miBST.raiz->derecho->valor << endl;
    // cout << "Raiz -> derecho -> izquierdo: " << miBST.raiz->derecho->izquierdo->valor << endl;
    // cout << "Raiz -> derecho -> derecho : " << miBST.raiz->derecho->derecho->valor << endl;
    miBST.recorrido();
}
