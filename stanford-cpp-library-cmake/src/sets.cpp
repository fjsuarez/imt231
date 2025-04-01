#include <iostream>
#include <collections/set.h>

using namespace std;

int main() {
    Set<int> s;
    s.add(1); // O(1)
    s.add(2);
    s.add(3);
    s.add(1);
    cout << "s: " << s.toString() << endl;

    Set<int> s2;
    s2.add(2);
    s2.add(3);
    s2.add(5);
    s2.add(7);
    cout << "s2: " << s2.toString() << endl;

    cout << "Union de conjuntos (+): " << endl;
    cout << (s + s2).toString() << endl;
    cout << "s: " << s.toString() << endl;
    // cout << "Union de conjuntos (addAll): " << endl; // s += s2
    // cout << s.addAll(s2) << endl;
    // cout << "s: " << s.toString() << endl;

    cout << "Interseccion de conjunto: " << endl;
    cout << (s * s2).toString() << endl;

    cout << "Diferencia de conjuntos (A - B): " << endl;
    cout << (s - s2).toString() << endl;

    cout << "Diferencia de conjuntos (B - A): " << endl;
    cout << (s2 - s).toString() << endl;

    if (s.contains(2)) { // O(1)
        cout << "El conjunto contiene el 2" << endl;
    }
    if (s.contains(5)) {
        cout << "El conjunto contiene el 2" << endl;
    } else {
        cout << "El conjunto no contiene el 5" << endl;
    }

    // Los sets se utilizan en caso de no querer elementos repetidos
    // Los sets no tienen orden
    // Los sets no tienen indice
    // Los sets se utilizan para buscar elementos en O(1) (chequear existencia)
    return 0;
};