#include <iostream>
#include <collections/vector.h>
#include <collections/set.h>
#include <collections/map.h>
#include <collections/queue.h>
#include <collections/stack.h>
using namespace std;

class Nodo {
    public:
        int valor;
};

class Grafo {
    public:
        // Vector<Vector<Nodo>> matriz_adyacencia;
        // Vector<Set<Nodo>> matriz_adyacencia; // para grafos no dirigidos
        Map<int, Set<int>> lista_adyacencia;

        void agregarVertice(int vertice) {
            if (!lista_adyacencia.containsKey(vertice)) {
                lista_adyacencia[vertice] = Set<int>();
            }
        }

        void agregarAristas(int vertice1, int vertice2) {
            agregarVertice(vertice1);
            agregarVertice(vertice2);

            lista_adyacencia[vertice1].add(vertice2);
            lista_adyacencia[vertice2].add(vertice1);

            // matriz_adyacencia[vertice1][vertice2] = 1;
            // matriz_adyacencia[vertice2][vertice1] = 1;
        }

        Set<int> obtenerVecinos(int vertice) {
            if (!lista_adyacencia.containsKey(vertice)) {
                throw runtime_error("El vertice no existe");
            }
            return lista_adyacencia[vertice];
        }

        void recorrerGrafo(int inicial) {
            Set<int> visitado; // conjunto cerrado
            // Queue<int> frontera;
            Stack<int> frontera;
            // frontera.enqueue(inicial);
            frontera.push(inicial);
            visitado.add(inicial);

            while (!frontera.isEmpty()) {
                cout << "Frontera: " << frontera.toString() << endl;
                // int actual = frontera.dequeue();
                int actual = frontera.pop();
                for (int vertice : this->obtenerVecinos(actual)) {
                    if (!visitado.contains(vertice)) {
                        // frontera.enqueue(vertice);
                        frontera.push(vertice);
                        visitado.add(vertice);
                    }
                }
                cout << "Nodo " << actual << " visitado" << endl;
            }
        }
};      

// [ _ _ _ _ _ _ _ _ ]
//     |----> [ _ _ _ _ _ _ _ _ ]
//              |----> Nodo


using namespace std;

int main() {
    Grafo g;
    g.agregarVertice(0);
    g.agregarVertice(1);
    g.agregarVertice(2);
    g.agregarVertice(3);
    g.agregarVertice(4);
    g.agregarVertice(5);

    g.agregarAristas(0, 1);
    g.agregarAristas(0, 2);
    g.agregarAristas(0, 3);
    g.agregarAristas(0, 5);
    g.agregarAristas(1, 3);
    g.agregarAristas(1, 4);
    g.agregarAristas(2, 5);

    cout << g.lista_adyacencia.toString() << endl;

    g.recorrerGrafo(0);
    return 0;
}