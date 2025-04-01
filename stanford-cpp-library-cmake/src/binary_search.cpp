#include <iostream>
#include <collections/vector.h>

using namespace std;

bool contains_lineal(Vector<int>& v, int valor) { // O(n)
    for (int i = 0; i < v.size(); i++) {
        cout << (i + 1) << " iteraciones" << endl;
        if (v[i] == valor) {
            return true;
        }
    }
    return false;
}                                 
                        // inicio == fin == medio
                //    inicio      medio        fin
// inicio              medio                    fin
// [                                               ]
bool contains_logaritmico(Vector<int>& v, int valor) { // O(log n)
    int inicio = 0;
    int fin = v.size() - 1;
    int iteraciones = 1;
    while (inicio <= fin) {
        cout << iteraciones << " iteraciones" << endl;
        cout << "Inicio: " << inicio << " Fin: " << fin << endl;
        int medio = inicio + (fin - inicio) / 2;
        if (v[medio] == valor) {
            return true;
        } else if (v[medio] < valor) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
        iteraciones++;
    }
    return false;
}

int main() {
    Vector<int> v;
    v.add(1);
    v.add(2);
    v.add(8);
    v.add(12);
    v.add(14);
    v.add(19);
    v.add(24);
    v.add(33);
    v.add(41);
    v.add(56);
    cout << "v: " << v.toString() << endl;
    cout << "# de elementos: " << v.size() << endl;
    cout << "8 en v?: " << endl << contains_lineal(v, 8) << endl;
    cout << "35 en v?: " << endl << contains_lineal(v, 35) << endl;
    
    cout << "8 en v?: " << endl << contains_logaritmico(v, 8) << endl;
    cout << "35 en v?: " << endl << contains_logaritmico(v, 35) << endl;
    

    return 0;
}

// Tabla Hash

// x=  [1, 2, 8, 12, 14, 19, 24, 33, 41, 56]
// k
// 0[ h_1 ]                        [
// [ h_2 ]
// [ h_3 ]                   1
// []
// []                        19
// []
// []
// []                        33
// []
// []                        41
// []
// 11[]                      56 
// []                        
// []                        24
// []                        
// []                        2
// []
// []                        8
// []
// []                        14
// 19[ h_n ]
//                         []]

// k = h(v)

// h : x -> k

// pure hash function : uniformemente distribuida