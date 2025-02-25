#include <string>
#include <iostream>
#include "Vehiculo.hpp"
using namespace std;

Vehiculo::Vehiculo() { // constructor por defecto
    nombre = "";
    marca = "Toyota";
    cilindrada = 2000;
    ruedas = 4;
    esElectrico = false;
    tieneAireAcondicionado = true;
    tieneCajaAutomatica = true;
    tanque = 40.0;
    modelo = nullptr;
}

Vehiculo::Vehiculo(string nombre) : Vehiculo() { // constructor delegador
    this->nombre = nombre;
}

Vehiculo::Vehiculo(string nombre, string marca) : nombre(nombre), marca(marca) // lista inicializadora (C++ 11)
{
}

Vehiculo::Vehiculo(string nombre, int cilindrada) : Vehiculo(nombre)
{
    this->cilindrada = cilindrada;
}

Vehiculo::Vehiculo(const string &modelo, float tanque): Vehiculo()
{
    this->modelo = new string(modelo);
    this->tanque = tanque;
}

Vehiculo::Vehiculo(const Vehiculo &otroVehiculo)
{
    this->nombre = otroVehiculo.nombre;
    this->marca = otroVehiculo.marca;
    this->cilindrada = otroVehiculo.cilindrada;
    this->ruedas = otroVehiculo.ruedas;
    this->esElectrico = otroVehiculo.esElectrico;
    this->tieneAireAcondicionado = otroVehiculo.tieneAireAcondicionado;
    this->tieneCajaAutomatica = otroVehiculo.tieneCajaAutomatica;
    this->tanque = otroVehiculo.tanque;
    if (otroVehiculo.modelo != nullptr) {
        this->modelo = new string(*otroVehiculo.modelo); // deep copy
    } else {
        this->modelo = nullptr;
    }
}

string Vehiculo::obtenerMarca()
{ // getBrand
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

void Vehiculo::establecerModelo(const string& modelo)
{
    *this->modelo = modelo;
}

string Vehiculo::obtenerModelo()
{
    if (modelo == nullptr) {
        return "No se ha establecido el modelo";
    } else {
        return *modelo;
    }
}

void Vehiculo::activarAirbags()
{
    cout << "Airbags activados" << endl;
}
