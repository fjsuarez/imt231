#include <iostream>
#include <collections/vector.h>

using namespace std;

void cuadrado(int x) {
    cout << "Calculando cuadrado de " << x << endl;
    cout << x*x << endl;
}

int main() {
    Vector<int> vec;

    vec.add(1);
    vec.add(2);
    vec.add(3);

    cout << "Tamaño de vec antes: " <<  vec.size() << endl;

    vec.add(4);
    vec.add(5);
    vec.add(6);

    cout << "Tamaño de vec despues: " << vec.size() << endl;

    cout << "Elemento en indice 5: " << vec[5] << endl;
    // cout << "Elemento en indice 6: " << vec[6] << endl;

    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }

    cout << endl;

    for (int elemento : vec) { // for each
        cout << elemento << " ";
    }

    cout << endl;

    cout << vec.get(1) << endl;

    vec.set(1, 100);

    vec.remove(2);

    for (int elemento : vec) { // for each
        cout << elemento << " ";
    }

    cout << endl;

    vec.mapAll(cuadrado);

    Vector<int> vec2 = {99, 88, 77, 66};

    for (int elemento : vec2) { // for each
        cout << elemento << " ";
    }

    cout << vec2.toString() << endl;
    cout << vec2 << endl;
    cout << (vec + vec2).size() << endl;

    return 0;
}

// Complejidad de tiempo
// Acceso   O(1)
// Busqueda O(n)
// add      O(1) / O(n)
// insert   O(n) / O(1)
// remove   O(n) / O(1)
// copy     O(n)
// mapAll   O(n)