#include <iostream>
#include <string>
#include <collections/map.h>
#include <collections/vector.h>

using namespace std;

int main() {
    // Map<llave, valor>
    // miMapa["llave"] = valor;
    // llaves tienen que ser hasheables

    // miMapa["Marco"] = 19
    // miMapa["David"] = 20
    // miMapa["Camila"] = 19
    // miMapa["Camila"] = 21 // las llaves no pueden ser duplicadas
    Map<string, int> miMapa;
    miMapa.add("Marco", 19);
    miMapa["David"] = 20;
    miMapa["Camila"] = 19;

    cout << miMapa.toString() << endl;

    Map<string, Vector<string>> mapaAmigos;

    mapaAmigos["Pepe"] = {"Lucho", "Carlos", "Jorge"};
    mapaAmigos["Pedro"] = {"Ana", "Paul"};

    // Los mapas tambien se llaman diccionarios
    // Los mapas se utilizan cuando queremos representar relaciones
    // entre entidades
    // Permiten acceder a un elemento en O(1)
    // Permiten chequear existencia en O(1)

    cout << mapaAmigos.toString() << endl;
    return 0;
}