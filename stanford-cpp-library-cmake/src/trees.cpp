#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
class Nodo {
    public:
    T data;
    vector<unique_ptr<Nodo<T>>> hijos;
    Nodo(T valor) : data(valor) {}

    ~Nodo() {
        // cout << "Destruyendo el nodo con data: " << data << endl;
    }

    void agregarHijo(unique_ptr<Nodo<T>> hijo) {
        hijos.push_back(move(hijo));
    }
};

template<typename T>
class Arbol {
    public:
    unique_ptr<Nodo<T>> raiz;
    Arbol() : raiz(nullptr) {};
    Arbol(T dataRaiz) : raiz(make_unique<Nodo<T>>(dataRaiz)) {}; 
    ~Arbol() = default;

    Nodo<T>* BFS(const T& valor) {
        if (!raiz) {
            cout << "El árbol está vacío." << endl;
            return nullptr;
        }
        queue<Nodo<T>*> frontera;
        frontera.push(raiz.get());

        while (!frontera.empty()) {
            Nodo<T>* nodoActual = frontera.front();
            frontera.pop();
            cout << "Visitando nodo: " << nodoActual->data << endl;
            if (nodoActual->data == valor) {
                cout << "Encontrado: " << nodoActual->data << endl;
                return nodoActual;
            }

            for (const auto& hijo : nodoActual->hijos) {
                if (hijo) {
                    frontera.push(hijo.get());
                }
            }
        }
        return nullptr;
    }

    Nodo<T>* DFS(const T& valor) {
        if (!raiz) {
            cout << "El árbol está vacío." << endl;
            return nullptr;
        }
        stack<Nodo<T>*> frontera;
        frontera.push(raiz.get());

        while (!frontera.empty()) {
            Nodo<T>* nodoActual = frontera.top();
            frontera.pop();
            cout << "Visitando nodo: " << nodoActual->data << endl;
            if (nodoActual->data == valor) {
                cout << "Encontrado: " << nodoActual->data << endl;
                return nodoActual;
            }

            for (const auto& hijo : nodoActual->hijos) {
                if (hijo) {
                    frontera.push(hijo.get());
                }
            }
        }
        return nullptr;
    }

    bool agregarNodo(const T& valorPadre, const T& valorHijo) {
        Nodo<T>* nodoPadre = BFS(valorPadre);
        if (nodoPadre) {
            unique_ptr<Nodo<T>> nuevoHijo = make_unique<Nodo<T>>(valorHijo);
            nodoPadre->agregarHijo(move(nuevoHijo));
            return true;
        } else {
            cout << "No se encontró el nodo padre." << endl;
            return false;
        }
    }

};

int main() {
    Arbol<string> arbolEmpresa("Gerente General");

    // auto nodoGF = make_unique<Nodo<string>>("Gerente Financiero");
    // auto nodoGC = make_unique<Nodo<string>>("Gerente Comercial");
    // auto nodoGT = make_unique<Nodo<string>>("Gerente de Tecnologia");
    // arbolEmpresa.raiz->agregarHijo(move(nodoGF));
    // arbolEmpresa.raiz->agregarHijo(move(nodoGC));
    // arbolEmpresa.raiz->agregarHijo(move(nodoGT));

    arbolEmpresa.agregarNodo("Gerente General", "Gerente Financiero");
    arbolEmpresa.agregarNodo("Gerente General", "Gerente Comercial");
    arbolEmpresa.agregarNodo("Gerente General", "Gerente de Tecnologia");
    arbolEmpresa.agregarNodo("Gerente de Tecnologia", "Sysadmin");
    arbolEmpresa.agregarNodo("Gerente de Tecnologia", "Arquitecto de BD");
    arbolEmpresa.agregarNodo("Gerente de Tecnologia", "Subgerente de Desarrollo");
    arbolEmpresa.agregarNodo("Subgerente de Desarrollo", "Desarrollador 1");
    arbolEmpresa.agregarNodo("Subgerente de Desarrollo", "Desarrollador 2");


    cout << "Raiz: " << arbolEmpresa.raiz->data << endl;
    cout << "Hijos de la raiz:" << endl;
    for (const auto &hijo : arbolEmpresa.raiz->hijos) {
        cout << hijo->data << endl;
    }

    cout << "Buscando BFS 'Sysadmin'..." << endl;
    Nodo<string>* nodoEncontrado = arbolEmpresa.BFS("Sysadmin");
    if (nodoEncontrado) {
        cout << "Nodo encontrado: " << nodoEncontrado->data << endl;
    } else {
        cout << "Nodo no encontrado." << endl;
    }
    cout << "Buscando DFS 'Sysadmin'..." << endl;
    nodoEncontrado = arbolEmpresa.DFS("Sysadmin");
    if (nodoEncontrado) {
        cout << "Nodo encontrado: " << nodoEncontrado->data << endl;
    } else {
        cout << "Nodo no encontrado." << endl;
    }
    cout << "Buscando 'SCRUM Master'..." << endl;
    nodoEncontrado = arbolEmpresa.DFS("SCRUM Master");
    if (nodoEncontrado) {
        cout << "Nodo encontrado: " << nodoEncontrado->data << endl;
    } else {
        cout << "Nodo no encontrado." << endl;
    }

    return 0;
}