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
    Vehiculo vehiculo2("Batimovil");
    Vehiculo vehiculo3("El auto fantastico", "Foton");
    Vehiculo vehiculo4("Supra", 2800);
    Vehiculo vehiculo5("Corolla", 20.5f);
    Vehiculo vehiculo6 = vehiculo5;

    cout << "Modelo de vehiculo5: " << vehiculo5.obtenerModelo() << endl;
    cout << "Modelo de vehiculo6: " << vehiculo6.obtenerModelo() << endl;
    vehiculo5.establecerModelo("Corolla 2022");
    cout << "Modelo de vehiculo5: " << vehiculo5.obtenerModelo() << endl;
    cout << "Modelo de vehiculo6: " << vehiculo6.obtenerModelo() << endl;
    

    cout << "Marca de vehiculo1: " << vehiculo1.obtenerMarca() << endl;
    cout << "Marca de vehiculo2: " << vehiculo2.obtenerMarca() << endl;
    // vehiculo2.marca = "Ford";
    // cout << "Marca de vehiculo2: " << vehiculo2.marca << endl;
    subirAlVehiculo(vehiculo1);
    vehiculo1.establecerNombre("Troncomovil");
    subirAlVehiculo(vehiculo1);
    subirAlVehiculo(vehiculo2);

    subirAlVehiculo(vehiculo3);
    cout << "Marca de vehiculo3: " << vehiculo3.obtenerMarca() << endl;
    cout << "Cilindra de vehiculo3: " << vehiculo3.obtenerCilindrada() << endl;

    return 0;
}