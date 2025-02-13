// Clases
// Objetos

#include <string>
#include <iostream>
#include "Vehiculo.hpp"
using namespace std;

void subirAlVehiculo(Vehiculo vehiculo) {
    cout << "Subiendo al vehiculo..." << vehiculo.obtenerNombre() << endl;
}

int main() {
    Vehiculo vehiculo1;
    Vehiculo vehiculo2;

    cout << "Marca de vehiculo1: " << vehiculo1.obtenerMarca() << endl;
    cout << "Marca de vehiculo2: " << vehiculo2.obtenerMarca() << endl;
    // vehiculo2.marca = "Ford";
    // cout << "Marca de vehiculo2: " << vehiculo2.marca << endl;
    subirAlVehiculo(vehiculo1);
    vehiculo1.establecerNombre("Troncomovil");
    subirAlVehiculo(vehiculo1);


    return 0;
}