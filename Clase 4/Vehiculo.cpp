#include <string>
#include <iostream>
#include "Vehiculo.hpp"
using namespace std;


string Vehiculo::obtenerMarca() { // getBrand
    return marca;
}

int Vehiculo::obtenerCilindrada() {
    return cilindrada;
}

string Vehiculo::obtenerNombre() {
    return nombre;
}

void Vehiculo::establecerNombre(string nombre) { // setName
    if (nombre == "Batimovil") {
        cout << "No puedes cambiar el nombre" << endl;
        return;
    }
    this->nombre = nombre; //     (*this).nombre == this->nombre
}

void Vehiculo::acelerar() {
    if (tanque > 0) {
        cout << "Acelerando..." << endl;
        tanque -= 0.5;
    } else {
        cout << "No hay gasolina" << endl;
    }
}

void Vehiculo::encenderRadio() {
    cout << "Encendiendo radio..." << endl;
}

float Vehiculo::obtenerGasolina() {
    return tanque;
}

void Vehiculo::cargarGasolina(float litros) {
    tanque += litros;
}
void Vehiculo::activarAirbags() {
    cout << "Airbags activados" << endl;
}
